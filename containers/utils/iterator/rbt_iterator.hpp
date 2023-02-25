/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:13:12 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/25 10:25:13 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "red_black_tree.hpp"
# include "type_traits.hpp"
# include <algorithm>
# include <memory>
# include <stdexcept>
# include <iostream>
# include <new>

# define black	true
# define red	false

namespace ft
{

	template <typename Value>
	class node
	{
		public:
			typedef Value				value_type;
			typedef ft::node<Value>*	node_pointer;
			
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
			node(const node& copy )
				: value(copy.value), left(copy.left), right(copy.right), parent(copy.parent), is_left_child(copy.is_left_child), color(copy.color) { }
			
			~node() { }
		
		private:
			node_pointer _node;
	};
	
	template <typename T, typename node_type>
	class rbt_iterator
	{
		public:
			typedef	T 									value_type;
			typedef T&									reference;
			typedef T*									pointer;
			typedef const T&							const_reference;
			typedef const T*							const_pointer;
			
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef std::ptrdiff_t 						difference_type;

			typedef node_type*							node_pointer;

			node_pointer					node;
			
			rbt_iterator() : node() { }
			rbt_iterator(node_pointer n) : node(n) { }
			rbt_iterator(rbt_iterator const &other) : node(other.node) { }

			~rbt_iterator() { }

			rbt_iterator& operator=(rbt_iterator const &rhs)
			{
				node = rhs.node;      
				return *this;
			}

			operator rbt_iterator<const value_type, node_type>()
			{
				return rbt_iterator<const value_type, node_type>(node);
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
				node = rb_increment(node);
				return *this;
			}

			rbt_iterator operator++(int)
			{
				rbt_iterator tmp = *this;
				node = rb_increment(node);
				return tmp;
			}

			rbt_iterator &operator--()
			{
				node = rb_decrement(node);
				return *this;
			}

			rbt_iterator operator--(int)
			{
				rbt_iterator tmp = *this;
				node = rb_decrement(node);
				return tmp;
			}

			bool operator==(const rbt_iterator<const value_type, node_type>& rhs ) const
			{ 
				return node == rhs.node;
			}

			bool operator!=(const rbt_iterator<const value_type, node_type>& x) const
			{
				return node != x.node;
			}
			
			private:
				

				node_pointer rb_increment(node_pointer current)
				{
					node_pointer tmp = NULL;
					
		
					if (!current)
						return NULL;

					if (current && current->right)
					{
						tmp = current->right;
						while (tmp && tmp->left)
							tmp = tmp->left;
					}
					else
					{
						tmp = current->parent;
						while (tmp && !current->is_left_child)
						{
							current = tmp;
							tmp = tmp->parent;
						}
					}
					return tmp;
				}

				node_pointer rb_decrement(node_pointer current)
				{
					node_pointer tmp = NULL;
					
					if (!current)
						return NULL;

					if (current && current->left)
					{
						tmp = current->left;
						while (tmp && tmp->right)
							tmp = tmp->right;
					}
					else
					{
						tmp = current->parent;
						while (tmp && current->is_left_child)
						{
							current = tmp;
							tmp = tmp->parent;
						}
					}
					return tmp;
				}
				
		
	};

};

#endif