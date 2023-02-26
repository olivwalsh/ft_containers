/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:53:22 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/26 19:34:49 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include <memory>
# include <iostream>
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include <utility>
# include "red_black_tree.hpp"
# include "algorithm.hpp"
# include "type_traits.hpp"

namespace ft
{
	template <class Key,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<Key>
				>
	class set
	{
		public:

			class value_compare;
			
			typedef				Key											value_type;
			typedef	typename	std::size_t									size_type;
			typedef typename 	std::ptrdiff_t								difference_type;
			typedef				Compare										key_compare;
			typedef				Allocator									allocator_type;
			
			typedef				value_type&									reference;
			typedef		const 	value_type&									const_reference;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			
		private:
			typedef 			ft::red_black_tree< value_type,
													key_compare,
													allocator_type>			tree_type;

		public:
			typedef	typename	tree_type::const_iterator							iterator;
			typedef	typename	tree_type::const_iterator					const_iterator;
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			class value_compare : public std::binary_function< value_type, value_type, bool >
			{
				private:
					friend class set< Key, Compare, Allocator >;
				
				protected:	
					key_compare		comp;

					value_compare( key_compare c ) : comp( c )	{ }
				
				public:

					bool	operator()( const value_type &lhs, const value_type &rhs ) const
					{
						return comp(lhs, rhs);
					}
			};
			
			/* ------------- constructors ------------- */

			explicit set( const key_compare &comp = key_compare(), const Allocator& alloc = Allocator() )
				: tree(comp, alloc), compare(comp), allocator(alloc) { }
			
			template< class InputIt >
			set( InputIt first, InputIt last, const key_compare &comp = key_compare(), const Allocator& alloc = Allocator() )
				: tree(comp, alloc), compare(comp), allocator(alloc)
			{
				tree.insert(first, last);
			}
	 
	 		set( const set& other )
				: tree(other.compare, other.allocator), compare(other.compare), allocator(other.allocator)
			{
				*this = other;
			}
			
			~set() { }

			set& operator=( const set& other )
			{
				tree = other.tree;
				return *this;
			}

			allocator_type get_allocator() const
			{
				return allocator;
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
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}
			
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
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

			/* ------------- capacity ------------- */
			
			void clear()
			{
				return tree.clear();
			}
			
			ft::pair<iterator, bool> insert( const value_type& value )
			{
				return tree.insert(value);
			}
			
			iterator insert( iterator pos, const value_type& value )
			{
				(void)pos;
				return insert(value).first;
			}
			
			template <class InputIt>
			void insert( InputIt first, InputIt last )
			{
				tree.insert(first, last);
			}
			
			iterator erase( iterator pos )
			{
				if (pos != end())
					tree.erase(*pos);
				return pos;
			}
			
			iterator erase( iterator first, iterator last )
			{
				size_type distance = ft::distance(first, last);

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
			
			size_type erase( const Key& key )
			{
				return tree.erase(key);
			}
			
			void swap( set& other )
			{
				tree.swap(other.tree);
			}


			/* ------------- lookup ------------- */
			
			size_type count( const Key& key ) const
			{
				return iterator(tree.find(key)) != end() ? 1 : 0;
			}
			
			iterator find( const Key& key )
			{
				return iterator(tree.find(key));
			}
			
			const_iterator find( const Key& key ) const
			{
				return tree.find(key);
			}
			
			ft::pair<iterator,iterator> equal_range( const value_type& key )
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}
			
			ft::pair<const_iterator, const_iterator> equal_range( const value_type& key ) const
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}
			
			iterator lower_bound( const value_type& key )
			{
				iterator it = begin();
				
				while (it != end() && *it < key)
					it++;
				return it;
			}
			
			const_iterator lower_bound( const value_type& key ) const
			{
				const_iterator it = begin();
				
				while (it != end() && *it < key)
					it++;
				return it;
			}
			
			iterator upper_bound( const value_type& key )
			{
				iterator it = begin();
				
				while (it != end() && *it <= key)
					it++;
				return it;
			}
			
			const_iterator upper_bound( const value_type& key ) const
			{
				const_iterator it = begin();
				
				while (it != end() && *it <= key)
					it++;
				return it;
			}

			
			/* ------------- observers ------------- */
			
			key_compare key_comp() const
			{
				return key_compare();
			}
			
			set::value_compare value_comp() const
			{
				return value_compare(key_comp());
			}


		private:
			tree_type		tree;
			key_compare		compare;
			allocator_type	allocator;
		
			
	};

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class Compare, class Alloc>
	void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
	

};

#endif