/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:13:12 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/20 11:38:09 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "red_black_tree.hpp"

# define black	true
# define red	false

namespace ft
{

	template <typename Value>
	class node
	{
		public:
			// typedef Key					key_type;
			typedef Value				value_type;
			typedef ft::node<Value>*	node_pointer;
			
			// key_type					key;
			value_type					value;
			node_pointer				left;
			node_pointer				right;
			node_pointer				parent;
			bool						is_left_child;
			bool						color;


			node()
				: value(0), left(NULL), right(NULL), parent(NULL), is_left_child(false), color(red) { }
			node(const value_type &value)
				: value(value), left(NULL), right(NULL), parent(NULL), is_left_child(false), color(red) { }
			node(value_type val, node_pointer l, node_pointer r, node_pointer p, bool is_l, bool c)
				: value(val), left(l), right(r), parent(p), is_left_child(is_l), color(c) { }
			
			~node() { }

			node_pointer get_sibling()
			{
				if (!_node)
					return NULL;
				if (!_node->parent)
					return NULL;
				if (_node->is_left_child)
					return _node->right;
				return _node->left;
			}
		
		private:
			node_pointer _node;
	};
	
	template <typename T>
	class rbt_iterator
	{
		public:
			typedef	T 									value_type;
			typedef T&									reference;
			typedef T*									pointer;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef std::ptrdiff_t 						difference_type;

			typedef node<T>								node_type;
			typedef node<const T>						const_node_type;
			typedef node<T>								*node_pointer;
			typedef node<const T>						*const_node_pointer;
			
			typedef rbt_iterator<T>						iterator;
			typedef rbt_iterator<const T>				const_iterator;


			rbt_iterator() : node() { }
			
			explicit rbt_iterator(const node_pointer n) : node(n) { }

			template <typename _T>
			rbt_iterator(const rbt_iterator<_T> &src) : node(NULL)
			{
				*this = src;
			}

			template <typename Iter>
			rbt_iterator(const Iter &src) : node(NULL)
			{
				*this = src;
			}

			~rbt_iterator() { }

			rbt_iterator &operator=(const rbt_iterator<T> &rhs)
			{
				node = rhs.node;
				return *this;
			}

			node_pointer base() const
			{
				return node;
			}

			reference operator*() const
			{
				return node->value;	
			}

			pointer operator->() const
			{
				return &node->value;
			}

			rbt_iterator &operator++()
			{
				if (node && node->right)
				{
					node = node->right;
					while (node && node->left)
						node = node->left;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (tmp && node == tmp->right)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					if (node && node->right != tmp)
						node = tmp;
				}
				return *this;
			}

			rbt_iterator operator++(int)
			{
				rbt_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			rbt_iterator &operator--()
			{
				if (node && node->color == red && node->parent && node->parent->parent == node)
					node = node->right;
				else if (node && node->left)
				{
					node_pointer tmp = node->left;
					while (tmp && tmp->right)
						tmp = tmp->right;
					node = tmp;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (tmp && node == tmp->left)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					node = tmp;
				}
				return *this;
			}

			rbt_iterator operator--(int)
			{
				rbt_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			bool operator==(const rbt_iterator& x) const
			{
				return node == x.node;
			}

			bool operator!=(const rbt_iterator& x) const
			{
				return node != x.node;
			}

			node_pointer								node;
		
	};

	template <typename T>
	class rbt_const_iterator
	{
		public:
			typedef	T 									value_type;
			typedef const T&							reference;
			typedef const T*							pointer;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef std::ptrdiff_t 						difference_type;

			typedef node<T>								node_type;
			typedef node<const T>						const_node_type;
			typedef node<T>								*node_pointer;
			typedef node<const T>						*const_node_pointer;
			
			typedef rbt_iterator<T>						iterator;
			typedef rbt_const_iterator<T>				const_iterator;


			rbt_const_iterator() : node(NULL) { }
			
			explicit rbt_const_iterator(const node_pointer n) : node(n) { }

			rbt_const_iterator(const iterator &src) : node(src.node) { }

			~rbt_const_iterator() { }

			// rbt_const_iterator &operator=(const rbt_const_iterator<T> &rhs)
			// {
			// 	node = rhs.base();
			// 	return *this;
			// }

			node_pointer base() const
			{
				return node;
			}

			reference operator*() const
			{
				return node->value;	
			}

			pointer operator->() const
			{
				return &node->value;
			}

			rbt_const_iterator &operator++()
			{
				if (node && node->right)
				{
					node = node->right;
					while (node && node->left)
						node = node->left;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (tmp && node == tmp->right)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					if (node && node->right != tmp)
						node = tmp;
				}
				return *this;
			}

			rbt_const_iterator operator++(int)
			{
				rbt_const_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			rbt_const_iterator &operator--()
			{
				if (node && node->color == red && node->parent && node->parent->parent == node)
					node = node->right;
				else if (node && node->left)
				{
					node_pointer tmp = node->left;
					while (tmp && tmp->right)
						tmp = tmp->right;
					node = tmp;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (tmp && node == tmp->left)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					node = tmp;
				}
				return *this;
			}

			rbt_const_iterator operator--(int)
			{
				rbt_const_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			bool operator==(const rbt_const_iterator& x) const
			{
				return node == x.node;
			}

			bool operator!=(const rbt_const_iterator& x) const
			{
				return node != x.node;
			}

			node_pointer								node;
		
	};
};

#endif