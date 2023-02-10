/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:52 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/10 15:09:16 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

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

# define black	true
# define red	false

namespace ft
{
	template <typename Key, typename Value>
	class node
	{
		public:
			typedef Key					key_type;
			typedef Value				value_type;
			typedef node<Key, Value>	*node_pointer;
			
			key_type					key;
			value_type					value;
			node_pointer				left;
			node_pointer				right;
			node_pointer				parent;
			bool						is_left_child;
			bool						color;


			node()
				: key(0), value(0), left(NULL), right(NULL), parent(NULL), is_left_child(false), color(red) { }
			node(const key_type &key, const value_type &value)
				: key(key), value(value), left(NULL), right(NULL), parent(NULL), is_left_child(false), color(red) { }
			node( const node & lhs)
			{
				*this = lhs;
			}
			~node();

			node & operator=(const node &rhs)
			{
				key = rhs.key;
				value = rhs.value;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				is_left_child = rhs.is_left_child;
				color = rhs.color;
				return *this;
			}
			
	};
	
	template <typename Key,
				typename Value,
				typename Compare = std::less<Key>,
				typename Allocator = std::allocator<node<Key, Value> >
				>
	class red_black_tree
	{
		public:
			typedef				Key												key_type;
			typedef 			Value											value_type;
			typedef 			Compare											key_compare;
			typedef				Allocator 										allocator_type;
			
			typedef typename	Allocator::size_type							size_type;
			typedef typename	Allocator::difference_type						difference_type;
			
			typedef typename	Allocator::reference							reference;
			typedef typename	Allocator::const_reference						const_reference;
			typedef typename	Allocator::pointer								pointer;
			typedef typename	Allocator::const_pointer						const_pointer;

			typedef 			node<Key, Value>								node_type;
			typedef				node<Key, Value>								*node_pointer;
			
			// typedef				ft::bidirectional_iterator<pointer>				iterator;
			// typedef				ft::const_bidirectional_iterator<pointer>		const_iterator;

			// typedef				ft::reverse_iterator< iterator >				reverse_iterator;
			// typedef				ft::reverse_iterator< const iterator >			const_reverse_iterator;

			typedef typename 	Allocator::template rebind< node_type >::other	node_allocator;

			/* ------------- constructors ------------- */
			red_black_tree(const Compare &comp, const allocator_type &alloc = allocator_type())
				: _root(NULL), _size(0), _compare(comp), _node_allocator(alloc) { }

			red_black_tree(const red_black_tree &rhs)
				: _root(NULL), _size(0), _compare(rhs._compare), _node_allocator(rhs._node_allocator)
			{
				*this = rhs;
			}

			~red_black_tree() { }

			red_black_tree & operator=(const red_black_tree &rhs)
			{
				_compare = rhs._compare;
				_root = rhs._root;
				_node_allocator = rhs._node_allocator;
				_size = rhs._size;
				return *this;
			}
			
			void add(Key key, Value value)
			{
				node<Key, Value> node = new ft::node<Key, Value>(key, value);

				if (!_root)
				{
					_root = node;
					node.color = black;
					_size++;
					return ;
				}
				add(_root, node);
				_size++;
			}

		private:
			void add(node_pointer parent, node_pointer new_node)
			{
				if (_compare(new_node->key, parent->key) > 0)
				{
					// add right
					if (!parent->right)
					{	
						parent->right = new_node;
						new_node->parent = parent;
						return ;
					}
					return add(parent->right, new_node);
				}
				if (!parent->left)
				{	
					parent->left = new_node;
					new_node->parent = parent;
					new_node->is_left_child = true;
				}
				return add(parent->left, new_node);
				check_color(new_node);
			}

			void check_color(node_pointer node)
			{
				if (node == _root)
					return ;
				if (node->color == red && node->parent->color == red)
					correct_tree(node);
				check_color(node->parent);
			}

			void correct_tree(node_pointer node)
			{
				if (node->parent->is_left_child)
				{
					// aunt is node parent parent right 
					if (!node->parent->parent->right || node->parent->parent->right->color == black)
						return rotate(node);
					if (node->parent->parent->right)
						node->parent->parent->right->color = black;
					node->parent->parent->color = red;
					node->parent->color = black;
					return ;
				}
				else // aunt is grandparent's left child
				{
					if (!node->parent->parent->left || node->parent->parent->left->color == black)
						return rotate(node);
					if (node->parent->parent->left)
						node->parent->parent->left->color = black;
					node->parent->parent->color = red;
					node->parent->color = black;
					return ;	
				}
			}

			void rotate(node_pointer node)
			{
				if (node->is_left_child)
				{
					if (node->parent->is_left_child)
					{
						right_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->right)
							node->parent->right->color = red;
						return ;
					}
					right_left_rotate(node->parent->parent);
					node->color = black;
					node->right->color = red;
					node->left->color = red;
					return ;
				}
				else // if right child
				{
					if (!node->parent->is_left_child)
					{
						left_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->left)
							node->parent->left->color = red;
						return ;
					}
					left_right_rotate(node->parent->parent);
					node->color = black;
					node->right->color = red;
					node->left->color = red;
					return ;
				}
			}

			void right_rotate(node_pointer node)
			{
				(void)node;	
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
				tmp->left - node;
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
		
		private:
			node_pointer	_root;
			size_type		_size;
			key_compare		_compare;
			node_allocator	_node_allocator;

			
	};

	
};

#endif