/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:18:10 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/17 18:42:40 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	
	
	/* ------------- reverse iterator ------------- */
	
	template <class Iter>
	class reverse_iterator
	{

		protected:
			Iter 														current;
			typedef				ft::iterator_traits<Iter>				__traits_type;
		
		public:
			typedef				Iter									iterator_type;
			typedef typename	__traits_type::iterator_category		iterator_category;
			typedef typename	__traits_type::value_type				value_type;
			typedef typename	__traits_type::difference_type			difference_type;
			typedef typename	__traits_type::pointer					pointer;
			typedef	typename	__traits_type::reference				reference;

			reverse_iterator() : current( iterator_type() ) { }
			explicit
			reverse_iterator(iterator_type __x) : current(__x) { }
			
			reverse_iterator(const reverse_iterator& __x) : current(__x.current) { }
			
			template <class _Iter>
			reverse_iterator(const reverse_iterator<_Iter>& __x)
				: current(__x.base()) { }

			~reverse_iterator() { }
			
			template <class _Iter>
			reverse_iterator& operator=(const reverse_iterator<_Iter>& copy)
			{
				current = copy.base();
				return *this;
			}
			
			iterator_type base() const
			{
				return current;
			}
			
			reference operator*() const
			{
				Iter __tmp = current;
				return *--__tmp;
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			reverse_iterator& operator++()
			{
				--current;
				return *this;	
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator __tmp = *this;
				--current;
				return __tmp;
			}

			reverse_iterator& operator--()
			{
				++current;
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator __tmp = *this;
				++current;
				return __tmp;
			}

			reverse_iterator operator+(difference_type __n) const
			{
				return reverse_iterator(current - __n);
			}

			reverse_iterator& operator+=(difference_type __n)
			{
				current -= __n;
				return *this;
			}

			reverse_iterator operator-(difference_type __n) const
			{
				return reverse_iterator(current + __n);
			}

			reverse_iterator& operator-=(difference_type __n)
			{
				current += __n;
				return *this;
			}

			reference operator[](difference_type __n) const
			{
				return *(*this + __n);
			}

			difference_type operator+(const reverse_iterator& rhs) const
			{
				return current + rhs.current;
			}

			difference_type operator-(const reverse_iterator& rhs) const
			{
				return rhs.current - current;
			}
			
	};

	template <typename _IteratorL, typename _IteratorR>
		inline bool operator==(const reverse_iterator<_IteratorL>& lhs,
								const reverse_iterator<_IteratorR>& rhs)
		{
			return lhs.base() == rhs.base();
		}
	
	template <typename _IteratorL, typename _IteratorR>
		bool operator!=(const reverse_iterator<_IteratorL>& lhs,
								const reverse_iterator<_IteratorR>& rhs)
		{
			return !(lhs == rhs);
		}
	
	template <typename _IteratorL, typename _IteratorR>
		inline bool operator<(const reverse_iterator<_IteratorL>& lhs,
								const reverse_iterator<_IteratorR>& rhs)
		{
			return rhs.base() < lhs.base();
		}

	template <typename _IteratorL, typename _IteratorR>
		inline bool operator>(const reverse_iterator<_IteratorL>& lhs,
								const reverse_iterator<_IteratorR>& rhs)
		{
			return rhs < lhs;
		}
	
	template <typename _IteratorL, typename _IteratorR>
		inline bool operator<=(const reverse_iterator<_IteratorL>& lhs,
								const reverse_iterator<_IteratorR>& rhs)
		{
			return !(rhs < lhs);
		}

	template <typename _IteratorL, typename _IteratorR>
		inline bool operator>=(const reverse_iterator<_IteratorL>& lhs,
								const reverse_iterator<_IteratorR>& rhs)
		{
			return !(rhs > lhs);
		}

	template< typename Iter >
	inline reverse_iterator< Iter >
	operator+(typename reverse_iterator< Iter >::difference_type n, const reverse_iterator< Iter > &x)
	{ 
		return reverse_iterator< Iter >(x.base() - n);
	}

	template< typename Iter >
	inline reverse_iterator< Iter >
	operator-(typename reverse_iterator< Iter >::difference_type n, const reverse_iterator< Iter > &x)
	{ 
		return reverse_iterator< Iter >(x.base() + n);
	}
	
};

#endif