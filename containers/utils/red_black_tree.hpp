/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:52 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/25 17:37:16 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "rbt_iterator.hpp"
# include "type_traits.hpp"
# include <iostream>
# include <string>

# define RED_NODE "\033[1;31m"
# define BLACK "\033[1;30m"
# define RESET "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"

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


	template <	typename Value,
				typename Compare,
				typename Allocator = std::allocator<Value>
				>
	class red_black_tree
	{
		public:
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
			typedef				node<Value>*									node_pointer;
			
			typedef				ft::rbt_iterator<value_type, node_type>			iterator;
			typedef				ft::rbt_iterator<const value_type, node_type> 	const_iterator;

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
			void insert(InputIt first, InputIt last)
			{
				typedef typename ft::iterator_traits<InputIt>::iterator_category category;
				if (typeid(category) != typeid(std::input_iterator_tag))
				{
					size_type distance = ft::distance(first, last);
					if (distance && distance >= max_size())
						return ;
   				}
				
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
						return false;
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
				if (node && node->color == red && node->parent && node->parent->color == red)
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
				if (_root && _root->color == red)
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
					std::cout << RED_NODE << "One of the red-black tree rules has been violated" << RESET << std::endl;
				else
					std::cout << GREEN("Tree is balanced!") << std::endl;
			}
			
			void print_tree()
			{
				if (_root) 
				{
					print_helper("", _root, true);
					std::cout << std::endl;
				}
				check_rules_violation();
			}

			void print_helper(std::string prefix, node_pointer node, bool is_left)
			{
				if (node && node != _nil_node)
				{
					print_helper( prefix + "    " , node->right, false);
					std::cout << prefix;
					std::cout << (is_left ? "└──" : "┌──" );
					if (node != _nil_node)
					{
						if (node->color == red)
							std::cout << RED_NODE;
						else
							std::cout << BLACK;
						std::cout << " " << node->value.first << RESET << std::endl;
					}
					else
						std::cout << " #" << std::endl;
					print_helper( prefix + (is_left ? "    " : "│   "), node->left, true);
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

			void transplant(node_pointer node, node_pointer replace)
			{
				bool				is_left = node->is_left_child;
				node_pointer		parent = node->parent;
				node_pointer		left = node->left;
				node_pointer		right = node->right;

				if (node == _root)
				{
					_root = replace;
					_root->parent = NULL;
					_root->color = black;
				}
				else if (!parent)
					_root = replace;	
				else
				{
					if (is_left)
						parent->left = replace;
					else
						parent->right = replace;
				}
				
				if (replace)
				{	
					replace->parent = parent;
					replace->is_left_child = is_left;
					if (left != replace)
						replace->left = left;
					if (right != replace)
						replace->right = right;
					if (left && left != replace)
						left->parent = replace;
					if (right && right != replace)
						right->parent = replace;
				}	
			}

			node_pointer get_child(node_pointer parent, bool is_left)
			{	
				if (is_left)
					return parent->left;
				return parent->right;
			}

			node_pointer get_sibling(node_pointer parent, bool is_left)
			{	
				if (is_left)
					return parent->right;
				return parent->left;
			}

			void fix_double_black(node_pointer parent, bool is_left)
			{
				node_pointer	sibling = get_sibling(parent, is_left);
				node_pointer	child = get_child(parent, is_left);

				if (child && child->color == red)
				{
					child->color = black;
					return ;
				}
				
				if (is_left)
				{	
					if (sibling && sibling->color == red)
					{
						sibling->color = black;
						parent->color = red;
						left_rotate(parent);
						fix_double_black(parent, is_left);
					}
					else if (sibling && (!sibling->right || (sibling->right && sibling->right->color == black))
						&& (!sibling->left || (sibling->left && sibling->left->color == black)))
					{
						sibling->color = red;
						if (parent->color == red)
							parent->color = black;
						else if (parent->color == black && parent == _root)
							return ;
						else
							fix_double_black(parent->parent, parent->is_left_child);
					}
					else
					{
						if (sibling && sibling->left && sibling->left->color == red 
							&& (!sibling->right || (sibling->right && sibling->right->color == black)))
						{
							if (sibling->left)
								sibling->left->color = black;
							sibling->color = red;
							right_rotate(sibling);
							sibling = parent->right;
						}
						if (sibling)
						{
							sibling->color = parent->color;
							parent->color = black;
							if (sibling->right)
								sibling->right->color = black;
							left_rotate(parent);
						}						
					}
				}
				else
				{
					if (sibling && sibling->color == red)
					{
						sibling->color = black;
						parent->color = red;
						right_rotate(parent);
						fix_double_black(parent, is_left);
					}
					else if (sibling && (!sibling->left || (sibling->left && sibling->left->color == black))
						&& (!sibling->right || (sibling->right && sibling->right->color == black)))
					{
						sibling->color = red;
						if (parent->color == red)
							parent->color = black;
						else if (parent->color == black && parent == _root)
							return ;
						else
							fix_double_black(parent->parent, parent->is_left_child);
					}
					else
					{
						if (sibling && sibling->right && sibling->right->color == red
							&& (!sibling->left || (sibling->left && sibling->left->color == black)))
						{
							if (sibling->right)
								sibling->right->color = black;
							sibling->color = red;
							left_rotate(sibling);
							sibling = parent->left;
						}
						if (sibling)
						{
							sibling->color = parent->color;
							parent->color = black;
							if (sibling->left)
								sibling->left->color = black;
							right_rotate(parent);
						}
					}
				}
			}

			void check_tree_balanced(node_pointer node, node_pointer replace, node_pointer parent, bool is_left)
			{		
				if (node->color == black && replace && replace->color == red)
					replace->color = black;
				else if (node->color == red && replace && replace->color == black)
				{
					replace->color = red;
					fix_double_black(parent, is_left);
				}
				else if (node->color == black && (!replace || (replace && replace->color == black))
					&& get_child(parent, is_left) != _root)
					fix_double_black(parent, is_left);
			}
			
			void _erase(node_pointer node)
			{
				node_pointer	replace = NULL;
				node_pointer	parent = NULL;
				bool			is_left;

				if (!node->left && !node->right)
				{
					transplant(node, NULL);
					parent = node->parent;
					is_left = node->is_left_child;
				}
				else if (!node->left || !node->right)
				{
					if (!node->right)
						replace = node->left;
					else
						replace = node->right;
					is_left = replace->is_left_child;
					parent = node->parent;
					transplant(node, replace);
				}
				else
				{
					replace = get_successor(node);
					if (replace == node->right)
					{
						is_left = replace->is_left_child;
						parent = replace;
						transplant(node, replace);
					}
					else
					{
						parent = replace->parent;
						is_left = replace->is_left_child;
						transplant(replace, replace->right);
						transplant(node, replace);
					}
				}
				
				if (parent)
					check_tree_balanced(node, replace, parent, is_left);
				
				destroy_node(node);
			}

			bool has_red_child(node_pointer node)
			{
				if (node && node->left && node->left->color == red)
					return true;
				if (node && node->right && node->right->color == red)
					return true;
				return false;
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
					node->left->is_left_child = true;
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
				if (!node)
					return ;
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