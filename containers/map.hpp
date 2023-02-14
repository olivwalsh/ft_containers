/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:36:24 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/13 15:48:33 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "bidirectional_iterator.hpp"
# include "red_black_tree.hpp"
# include "algorithm.hpp"

namespace ft
{
	template <class Key,
				class T,
				class Compare = std::less<Key>, 
				class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:
			class															value_compare;
			
			typedef				Key 										key_type;
			typedef				T											mapped_type;
			typedef				ft::pair<const Key, T>							value_type;	
			typedef				Compare										key_compare;
			typedef				Allocator									allocator_type;
			
			typedef	typename	Allocator::size_type						size_type;
			typedef typename 	Allocator::difference_type					difference_type;
			
			typedef	typename	Allocator::reference						reference;
			typedef	typename	Allocator::const_reference					const_reference;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			
		private:
			typedef 			ft::red_black_tree<key_type,
													value_type,
													value_compare,
													allocator_type>
																			tree_type;
		
		public:
			typedef	typename	tree_type::iterator							iterator;
			typedef	typename	tree_type::const_pointer					const_iterator;
			
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		

		public:
		
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map<Key, T, Compare, Allocator>;
				
				protected:
					Compare comp;

					value_compare(Compare c) : comp(c) { }
				
				public:
					bool operator()(const value_type & x, const value_type & y) const
					{
						return comp(x.first, y.first);
					}
			};


			/* ------------- constructors ------------- */
			explicit map(const Compare& comp = key_compare(), const Allocator& alloc = allocator_type())
				: tree(comp, alloc), compare(comp), allocator(alloc) { }

			// template <class InputIt>
			// map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
			// {
				
			// }

			map(const map& rhs)
			{
				*this = rhs;
			}

			~map() { }

			map & operator=(const map & other)
			{
				tree = other.tree;
				allocator = other.allocator;
				compare = other.compare;
				return *this;
			}

			allocator_type get_allocator() const
			{
				return allocator;
			}
			
			
			/* ------------- element access ------------- */

			// mapped_type& at(const key_type& key)
			// {

			// }
			
			// const mapped_type& at(const key_type& key) const
			// {
				
			// }

			// mapped_type& operator[](const key_type& key)
			// {
				
			// }
			
			/* ------------- iterators ------------- */

			iterator begin()
			{
				return tree.begin();
			}

			const_iterator begin() const
			{
				return tree.begin();
			}

			iterator end()
			{
				return tree.end();
			}

			const_iterator end() const
			{
				return tree.end();
			}

			reverse_iterator rbegin()
			{
				return tree.rbegin();
			}

			const_reverse_iterator rbegin() const
			{
				return tree.rbegin();
			}

			reverse_iterator rend()
			{
				return tree.rend();
			}

			const_reverse_iterator rend() const
			{
				return tree.rend();
			}
		
			
			/* ------------- cpacity ------------- */

			bool empty() const
			{
				return tree.empty();
			}
			
			size_type size() const
			{
				return tree.size();
			}

			size_type max_size() const
			{
				return tree.max_size();
			}
			
			
			/* ------------- modifiers ------------- */

			void clear()
			{
				tree.clear();	
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				return tree.insert(value);
			}

			// iterator insert(iterator pos, const value_type& value)
			// {
				
			// }

			// template <class InputIt>
			// void insert(InputIt first, InputIt last)
			// {
				
			// }

			// iterator erase(iterator pos)
			// {
				
			// }

			// iterator erase(iterator first, iterator last)
			// {

			// }

			// size_type erase(const Key& key)
			// {
				
			// }
			
			void swap(map& other)
			{
				tree.swap(other.tree);				
			}
			
			
			/* ------------- lookup ------------- */

			// size_type count(const Key& key) const
			// {
				
			// }
			
			// iterator find(const Key& key)
			// {
				
			// }

			// const_iterator find(const Key& key) const
			// {
				
			// }

			// ft::pair<iterator, iterator> equal_range(const Key& key)
			// {

			// }

			// ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const
			// {
				
			// }
			
			// iterator lower_bound(const Key& key)
			// {
				
			// }

			// const_iterator lower_bound(const Key& key) const
			// {
				
			// }

			// iterator upper_bound(const Key& key)
			// {
				
			// }

			// const_iterator upper_bound(const Key& key) const
			// {
				
			// }

			/* ------------- observers ------------- */

			key_compare key_comp() const
			{
				return compare;
			}

			value_compare value_comp() const
			{
				return value_compare(tree.key_comp());
			}
		
		private:
			tree_type		tree;
			key_compare		compare;
			allocator_type	allocator;
		
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs.size() && rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return rhs > lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
	
};

#endif