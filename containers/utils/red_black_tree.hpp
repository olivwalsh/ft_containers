/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:52 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/18 16:34:25 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "rbt_iterator.hpp"
# include "type_traits.hpp"
# include <iostream>
# include <string>
# define RED "\033[1;31m"
# define BLACK "\033[1;30m"
# define RESET "\033[m"
#define GREEN(s) "\033[1;32m" s "\033[m"
# include <queue>
# include <iomanip>
# include <cmath>
# include "stack.hpp"

/*
	The rules:
		- root is black
		- null nodes are black
		- every path from root to null must have the same amount of black nodes
		- there are no two consecutives red nodes
		- every insertion is red

	when new insertion:
		if red aunt: color flip
		if black aunt: rotate
	
*/

namespace ft
{

	/* ------------- NODE (RED BLACK TREE) CLASS ------------- */

	

	/* ------------- RED BLACK TREE CLASS ------------- */


	template <typename Key,
				typename Value,
				typename Compare = std::less<Key>,
				typename Allocator = std::allocator<Value>
				>
	class red_black_tree
	{
		public:
			typedef				Key												key_type;
			typedef 			Value											value_type;
			typedef 			Compare											value_compare;
			typedef				Allocator 										allocator_type;
			
			typedef typename	Allocator::size_type							size_type;
			typedef typename	Allocator::difference_type						difference_type;
			
			typedef typename	Allocator::reference							reference;
			typedef typename	Allocator::const_reference						const_reference;
			typedef typename	Allocator::pointer								pointer;
			typedef typename	Allocator::const_pointer						const_pointer;

			typedef 			node<Value>										node_type;
			typedef				node<Value>										*node_pointer;
			
			typedef				ft::rbt_iterator<value_type>					iterator;
			typedef				ft::rbt_const_iterator<value_type>				const_iterator;

			typedef				ft::reverse_iterator< iterator >				reverse_iterator;
			typedef				ft::reverse_iterator< const_iterator >			const_reverse_iterator;

			typedef typename 	Allocator::template rebind< node_type >::other	node_allocator;

			/* ------------- constructors ------------- */
			red_black_tree(const Compare &comp, const allocator_type &alloc = allocator_type())
				: _root(NULL), _size(0), _compare(comp), _node_allocator(alloc)
			{
				_root = init_nil_node();
			}

			red_black_tree(const red_black_tree &rhs)
				: _nil_node(NULL), _root(NULL), _size(0), _compare(rhs._compare), _node_allocator(rhs._node_allocator)
			{
				*this = rhs;
			}

			~red_black_tree()
			{
				clear(_root);
				_node_allocator.destroy(_nil_node);
				_node_allocator.deallocate(_nil_node, 1);
				_nil_node = NULL;
			}

			red_black_tree & operator=(const red_black_tree &rhs)
			{
				clear();
				_compare = rhs._compare;
				_node_allocator = rhs._node_allocator;
				if (!_nil_node)
					_root = init_nil_node();
				if (!rhs.empty())
					insert(rhs.begin(), rhs.end());
				return *this;
			}

			void clear()
			{
				clear(_root);
				_nil_node->parent = _root;
				_nil_node->right = NULL;
				_nil_node->left = NULL;
				_nil_node->is_left_child = false;
				_nil_node->color = black;
				_root = _nil_node;
				_size = 0;
			}

			/* ------------- iterators ------------- */

			iterator begin()
			{
				return iterator(get_minimum_value());
			}

			const_iterator begin() const
			{
				return const_iterator(get_minimum_value());
			}
			
			iterator end()
			{
				return iterator(_nil_node);
			}

			const_iterator end() const
			{
				return const_iterator(_nil_node);
			}


			/* ------------- capacity ------------- */

			bool empty( void ) const
			{ 
				return this->_size == 0; 
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _node_allocator.max_size();
			}
			
			void swap(red_black_tree &other)
			{
				node_pointer	tmp_nil_node = _nil_node;
				node_pointer	tmp_root = _root;
				size_type		tmp_size = _size;
				value_compare	tmp_compare = _compare;
				node_allocator	tmp_node_allocator = _node_allocator;

				_nil_node = other._nil_node;
				_root = other._root;
				_size = other._size;
				_compare = other._compare;
				_node_allocator = other._node_allocator;
				
				other._nil_node = tmp_nil_node;
				other._root = tmp_root;
				other._size = tmp_size;
				other._compare = tmp_compare;
				other._node_allocator = tmp_node_allocator;
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				node_pointer duplicate = find(value);
				if (duplicate != _nil_node)
					return ft::make_pair(iterator(duplicate), false);
			
				node_pointer new_node = create_node(value);
				if (_root == _nil_node)
				{
					_root = new_node;
					_root->color = black;
					_size++;
					attach_nil_node();
				}
				else
				{
					detach_nil_node();
					add(_root, new_node);
					attach_nil_node();
					_size++;
				}
				return ft::make_pair(iterator(new_node), true);
			}

			template <class InputIt>
			void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0)
			{
				for (; first != last; ++first)
					insert(*first);
			}

			size_type get_height()
			{
				if (_root == NULL)
					return 0;
				return get_height(_root) - 1;
			}
			
			size_type get_height(node_pointer node)
			{
				if (!node)
					return 0;
				int left_height = get_height(node->left) + 1;
				int right_height = get_height(node->right) + 1;
				if (left_height > right_height)
					return left_height;
				return right_height;
			}

			node_pointer find(value_type value) const
			{
				node_pointer	tmp = lower_bound(value);

				if (tmp == _nil_node || _compare(value, tmp->value))
					return _nil_node;

				return tmp;
			}

			/**
			 *  @return  node pointer pointing to first element equal to or greater
			 *           than value, or end().
			 **/
			node_pointer lower_bound( value_type value) const
			{
				node_pointer tmp = _root;
				node_pointer lower = _nil_node;

				while (tmp && tmp != _nil_node)
				{
					if (!_compare(tmp->value, value))
					{
						lower = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return lower;
			}

			/**
			 *  @return  node pointer pointing to first element greater
			 *           than value, or end().
			 **/
			node_pointer upper_bound( value_type value) const
			{
				node_pointer tmp = _root;
				node_pointer upper = _nil_node;
				
				while (tmp && tmp != _nil_node)
				{
					if (_compare(value, tmp->value))
					{
						upper = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return upper;
			}

			size_type erase(const value_type &value)
			{
				node_pointer tmp = find(value);

				if (tmp == _nil_node)
					return 0;
				
				if (_size == 1) // delete root
					clear();
				else
				{
					detach_nil_node();
					_erase(tmp);
					attach_nil_node();
					_size--;
				}
				return 1;
			}

			bool check_black_nodes(node_pointer node, int black_count, int& path_black_count)
			{
				if (!node)
				{
					if (path_black_count == -1)
						path_black_count = black_count;
					else if (path_black_count != black_count)
					{
						std::cout << "There isn't the same amount of black nodes in each path from root to null!" << std::endl;
						return false;
					}
					return true;
				}
				if (node != _nil_node && node->color == black)
					black_count++;
				return check_black_nodes(node->left, black_count, path_black_count) && check_black_nodes(node->right, black_count, path_black_count);
			}

			bool check_consecutive_red(node_pointer node)
			{
				if (!node)
					return true;
				if (node->color == red && node->parent && node->parent->color == red)
				{
					std::cout << "There are two consecutive red nodes in the tree!" << std::endl;
					return false;
				}
				return check_consecutive_red(node->left) && check_consecutive_red(node->right);
			}
			
			void check_rules_violation()
			{
				bool violation = false;
				
				// null nodes are black + insertions are red. 
				if (_root->color == red)
				{
					violation = true;
					std::cout << "Root is not black as supposed to!" << std::endl;
				}
				int path_black_count = -1;
				if (!check_black_nodes(_root, 0, path_black_count))
					violation = true;
				if (!check_consecutive_red(_root))
					violation = true;
				if (violation)
					std::cout << RED << "One of the red-black tree rules has been violated" << RESET << std::endl;
				else
					std::cout << GREEN("Tree is balanced!") << std::endl;
			}
			
			void printTree()
			{
				if (_root) 
				{
					printHelper("", _root, true);
					std::cout << std::endl;
				}
				check_rules_violation();
			}

			void printHelper(std::string prefix, node_pointer node, bool is_left)
			{
				if (node)
				{
					printHelper( prefix + "    " , node->right, false);
					std::cout << prefix;
					std::cout << (is_left ? "└──" : "┌──" );
					if (node != _nil_node)
					{
						if (node->color == red)
							std::cout << RED;
						else
							std::cout << BLACK;
						std::cout << " " << node->value.first << RESET << std::endl;
					}
					else
						std::cout << " #" << std::endl;
					printHelper( prefix + (is_left ? "    " : "│   "), node->left, true);
				}
			}

			
		private:
			node_pointer	_nil_node;
			node_pointer	_root;
			size_type		_size;
			value_compare	_compare;
			node_allocator	_node_allocator;


			node_pointer get_successor(node_pointer to_delete)
			{
				node_pointer successor = to_delete->right;

				while (successor && successor->left)
					successor = successor->left;
				return successor;
			}

			node_pointer get_sibling(node_pointer node)
			{
				if (!node->parent)
					return NULL;
				if (node->is_left_child)
					return node->parent->right;
				return node->parent->left;
			}

			void delete_fix(node_pointer node)
			{
				while (node != _root && node && node->color == black)
				{
					if (node->is_left_child)
					{
						node_pointer sibling = node->parent->right;
						if (sibling && sibling->color == red)
						{
							sibling->color = black;
							node->parent->color = red;
							left_rotate(node->parent);
							sibling = node->parent->right;
						}
						if (sibling && sibling->left && sibling->left->color == black 
							&& sibling->right && sibling->right->color == black)
						{
							sibling->color = red;
							node = node->parent;
						}
						else
						{
							if (sibling && sibling->right && sibling->right->color == black)
							{
								sibling->left->color = black;
								sibling->color = red;
								right_rotate(sibling);
								sibling = node->parent->right;
							}
							sibling->color = node->parent->color;
							node->parent->color = black;
							sibling->right->color = black;
							left_rotate(node->parent);
							node = _root;
						}
					}
					else
					{
						node_pointer sibling = node->parent->left;
						if (sibling && sibling->color == red)
						{
							sibling->color = black;
							node->parent->color = red;
							right_rotate(node->parent);
							sibling = node->parent->left;
						}
						if (sibling && sibling->left && sibling->left->color == black
							&& sibling->right && sibling->right->color == black)
						{
							sibling->color = red;
							node = node->parent;
						}
						else
						{
							if (sibling && sibling->left && sibling->left->color == black)
							{
								sibling->right->color = black;
								sibling->color = red;
								left_rotate(sibling);
								sibling = node->parent->left;
							}
							sibling->color = node->parent->color;
							node->parent->color = black;
							sibling->left->color = black;
							right_rotate(node->parent);
							node = _root;
						}
					}
				}
				if (node)
					node->color = black;
			}

			void transplant(node_pointer node, node_pointer new_node)
			{
				
				if (!node->parent)
					_root = new_node;
				else
				{
					if (node->is_left_child)
						node->parent->left = new_node;
					else
						node->parent->right = new_node;
				}
				
				if (!new_node)
					return ;
				new_node->parent = node->parent;
				new_node->is_left_child = node->is_left_child;
				if (node->left != new_node)
					new_node->left = node->left;
				if (node->right != new_node)
					new_node->right = node->right;
				if (node->left && node->left != new_node)
					node->left->parent = new_node;
				if (node->right && node->right != new_node)
					node->right->parent = new_node;
			}

			void _erase(node_pointer to_delete)
			{
				bool original_color = to_delete->color;
				node_pointer successor;

				if (!to_delete->left && !to_delete->right)
					successor = NULL;
				else if (!to_delete->left)
					successor = to_delete->right;
				else if (!to_delete->right)
					successor = to_delete->left;
				else
				{
					successor = get_successor(to_delete);
					node_pointer successor_of_successor = successor->right;
					original_color = successor->color;
					if (successor_of_successor && (successor == to_delete->right || successor == to_delete->left))
						successor_of_successor->parent = successor;
					else
						transplant(successor, successor->right);
					transplant(to_delete, successor);
					successor->color = original_color;
					if (original_color == black)
						delete_fix(successor_of_successor);
					destroy_node(to_delete);
					return ;
				}
				transplant(to_delete, successor);
				if (original_color == black)
					delete_fix(successor);
				destroy_node(to_delete);
				
			}
		
			node_pointer init_nil_node()
			{
				_nil_node = create_node(value_type());
				_nil_node->parent = _root;
				_nil_node->right = NULL;
				_nil_node->left = NULL;
				_nil_node->is_left_child = false;
				_nil_node->color = black;
				return _nil_node;
			}

			node_pointer create_node(const value_type &value)
			{
				node_pointer tmp = _node_allocator.allocate(1);
		
				_node_allocator.construct(tmp, value);
				return tmp;
			}

			void destroy_node(node_pointer node)
			{
				_node_allocator.destroy(node);
				_node_allocator.deallocate(node, 1);
				node = NULL;
			}
				
			node_pointer tree_contains_value(const value_type& value)
			{
				node_pointer tmp = _root;
				
				while (tmp)
				{
					if (_compare(value, tmp->value))
						tmp = tmp->left;
					else if (_compare(tmp->value, value))
						tmp = tmp->right;
					else
						return tmp;
				}
				return NULL;
			}
			
			void add(node_pointer parent, node_pointer new_node)
			{
				if (_compare(parent->value, new_node->value))
				{
					// add right
					if (!parent->right)
					{	
						parent->right = new_node;
						new_node->parent = parent;
					}
					else
						add(parent->right, new_node);
				}
				else
				{
					if (!parent->left)
					{	
						parent->left = new_node;
						new_node->parent = parent;
						new_node->is_left_child = true;
					}
					else
						add(parent->left, new_node);
				}
				check_color(new_node);
			}

			void check_color(node_pointer node)
			{
				if (!node)
					return ;
				if (node == _root)
					return ;
				if (node && node->color == red && node->parent->color == red)
					correct_tree(node);
				check_color(node->parent);
			}

			node_pointer get_aunt(node_pointer node)
			{
				if (!node->parent || !node->parent->parent)
					return NULL;
				if (node->parent->is_left_child)
					return node->parent->parent->right;
				return node->parent->parent->left;
			}

			void color_flip(node_pointer node)
			{
				node_pointer aunt = get_aunt(node);
				
				if (aunt)
					aunt->color = black;
				if (node->parent && node->parent->parent && node->parent->parent != _root)
					node->parent->parent->color = red;
				if (node->parent)
					node->parent->color = black;
			}
			
			void correct_tree(node_pointer node)
			{
				node_pointer aunt = get_aunt(node);
				
				if (!aunt || aunt->color == black)
					return rotate(node);
				color_flip(node);
			}

			void rotate(node_pointer node)
			{
				if (node->is_left_child)
				{
					if (node->parent && node->parent->is_left_child)
					{
						if (node->parent->parent)
							right_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->right)
							node->parent->right->color = red;
					}
					else
					{
						if (node->parent->parent)
							right_left_rotate(node->parent->parent);
						node->color = black;
						node->right->color = red;
						node->left->color = red;
					}
				}
				else // if right child
				{
					if (node->parent && !node->parent->is_left_child)
					{
						if (node->parent->parent)
							left_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->left)
							node->parent->left->color = red;
					}
					else
					{
						if (node->parent->parent)
							left_right_rotate(node->parent->parent);
						node->color = black;
						node->right->color = red;
						node->left->color = red;
					}
				}
			}

			void right_rotate(node_pointer node)
			{
				node_pointer tmp = node->left;
				node->left = tmp->right;
				if (node->left)
				{
					node->left->parent = node;
					node->left->is_left_child = false;
				}
				if (!node->parent)
				{	
					_root = tmp;
					tmp->parent = NULL;
				}
				else
				{
					tmp->parent = node->parent;
					if (node->is_left_child)
					{	
						tmp->is_left_child = true;
						tmp->parent->left = tmp;
					}
					else
					{
						tmp->is_left_child = false;
						tmp->parent->right = tmp;
					}
				}
				tmp->right = node;
				node->is_left_child = false;
				node->parent = tmp;
			}

			void left_rotate(node_pointer node)
			{
				node_pointer tmp = node->right;
				node->right = tmp->left;
				if (node->right)
				{
					node->right->parent = node;
					node->right->is_left_child = false;
				}
				if (!node->parent)
				{	
					_root = tmp;
					tmp->parent = NULL;
				}
				else
				{
					tmp->parent = node->parent;
					if (node->is_left_child)
					{	
						tmp->is_left_child = true;
						tmp->parent->left = tmp;
					}
					else
					{
						tmp->is_left_child = false;
						tmp->parent->right = tmp;
					}
				}
				tmp->left = node;
				node->is_left_child = true;
				node->parent = tmp;
			}

			void left_right_rotate(node_pointer node)
			{
				left_rotate(node->left);
				right_rotate(node);
			}

			void right_left_rotate(node_pointer node)
			{
				right_rotate(node->right);
				left_rotate(node);
			}

			int black_nodes(node_pointer node)
			{
				if (!node)
					return 1;
				int rhs_black_nodes = black_nodes(node->right);
				int lhs_black_nodes = black_nodes(node->left);
				if (rhs_black_nodes != lhs_black_nodes)
				{
					// throw an error or fix the tree
					return -1;
				}
				if (node->color == black)
					lhs_black_nodes++;
				return lhs_black_nodes;
			}

			node_pointer get_minimum_value() const
			{
				node_pointer tmp = _root;
				
				while (tmp && tmp->left)
					tmp = tmp->left;
				return tmp;
			}

			node_pointer get_maximum_value()
			{
				node_pointer tmp = _root;
				
				while (tmp && tmp->right && tmp->right != _nil_node)
					tmp = tmp->right;
				return tmp;
			}
		
			void attach_nil_node()
			{
				node_pointer tmp = get_maximum_value();

				if (tmp && tmp != _nil_node)
				{
					tmp->right = _nil_node;
					_nil_node->parent = tmp;
				}
			}

			void detach_nil_node()
			{
				node_pointer tmp = get_maximum_value();

				if (tmp && tmp != _nil_node)
				{
					tmp->right = NULL;
					_nil_node->parent = NULL;
				}
			}
			
			void clear(node_pointer current)
			{
				if (current == _nil_node)
					return ;
				if (!current)
					return ;
				if (current->left)
					clear(current->left);
				if (current->right)
					clear(current->right);
				_node_allocator.destroy(current);
				_node_allocator.deallocate(current, 1);
				current = NULL;
			}
	};

	
};

#endif