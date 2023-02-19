/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:36:24 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/18 21:27:28 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include <iostream>
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "red_black_tree.hpp"
# include "algorithm.hpp"
# include "type_traits.hpp"

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
			typedef				ft::pair<const Key, T>						value_type;	
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
			typedef	typename	tree_type::const_iterator					const_iterator;
			
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		

		public:
		
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map<Key, T, Compare, Allocator>;
				
				protected:
					key_compare comp;

					value_compare(key_compare c) : comp(c) { }
				
				public:
					bool operator()(const value_type & x, const value_type & y) const
					{
						return comp(x.first, y.first);
					}
			};


			/* ------------- constructors ------------- */
			explicit map(const Compare& comp = key_compare(), const Allocator& alloc = allocator_type())
				: tree(value_compare(comp), alloc), compare(comp), allocator(alloc) { }

			template <class InputIt>
			map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
				: tree(value_compare(comp), alloc), compare(comp), allocator(alloc)
			{
				tree.insert(first, last);
			}

			map(const map& rhs)
				: tree(value_compare(rhs.compare), rhs.allocator), compare(rhs.compare), allocator(rhs.allocator)
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

			void print()
			{
				tree.printTree();
			}

			allocator_type get_allocator() const
			{
				return allocator;
			}
			
			
			/* ------------- element access ------------- */

			mapped_type& at(const key_type& key)
			{
				iterator node = find(key);
				
				if (node == end())
					throw std::out_of_range("map:at");
				return (*node).second;
			}
			
			const mapped_type& at(const key_type& key) const
			{
				const_iterator node = find(key);
				
				if (node == end())
					throw std::out_of_range("map:at");
				return (*node).second;
			}

			mapped_type& operator[](const key_type& key)
			{
				return (*(insert(get_value(key)).first)).second; 
			}
			
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
				if (empty())
					return rend();
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				if (empty())
					return rend();
				return reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return reverse_iterator(begin());
			}
		
			
			/* ------------- capacity ------------- */

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

			iterator insert(iterator pos, const value_type& value)
			{
				(void)pos;
				return insert(value).first;
			}

			template <class InputIt>
			void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0)
			{
				tree.insert(first, last);
			}

			iterator erase(iterator pos)
			{
				if (pos == end())
					return end();
				tree.erase(*pos);
				return pos;
			}

			iterator erase(iterator first, iterator last)
			{
				size_type distance = std::distance(first, last);

				if (distance && distance < max_size())
				{
					while( first != last)
					{
						value_type	tmp = (*first++);
						tree.erase(tmp);
					}
				}
				return last;
			}

			size_type erase(const Key& key)
			{
				return tree.erase(get_value(key));
			}
			
			void swap(map& other)
			{
				tree.swap(other.tree);				
			}
			
			
			/* ------------- lookup ------------- */

			size_type count(const Key& key) const
			{
				ft::pair<const_iterator, const_iterator> tmp = equal_range(key);

				size_type count = std::distance(tmp.first, tmp.second); 
				return count;
			}
			
			iterator find(const Key& key)
			{
				return iterator(tree.find(get_value(key)));
			}

			const_iterator find(const Key& key) const
			{
				return iterator(tree.find(get_value(key)));
			}

			ft::pair<iterator, iterator> equal_range(const Key& key)
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}
			
			iterator lower_bound(const Key& key)
			{
				iterator it = begin();
				
				while (it != end() && it->first < key)
					it++;
				return it;
			}

			const_iterator lower_bound(const Key& key) const
			{
				const_iterator it = begin();
				
				while (it != end() && it->first < key)
					it++;
				return it;
			}

			iterator upper_bound(const Key& key)
			{
				iterator it = begin();
				
				while (it != end() && it->first <= key)
					it++;
				return it;
			}

			const_iterator upper_bound(const Key& key) const
			{
				const_iterator it = begin();
				
				while (it != end() && it->first <= key)
					it++;
				return it;				
			}

			/* ------------- observers ------------- */

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_comp());
			}
		
		private:
			tree_type		tree;
			key_compare		compare;
			allocator_type	allocator;

			value_type get_value(const key_type &key) const
			{
				return ft::make_pair(key, mapped_type());	
			}
		
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
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