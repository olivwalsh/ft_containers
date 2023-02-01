/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:44:31 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/01 15:30:33 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITERATOR_HPP
# define NORMAL_ITERATOR_HPP

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template <typename _Iterator>
	class normal_iterator : public std::iterator<std::random_access_iterator_tag, _Iterator, std::ptrdiff_t, _Iterator*, _Iterator&> 
	{
		protected:
			_Iterator												current;
			typedef				ft::iterator_traits<_Iterator>		__traits_type;
		
		public:
			typedef				_Iterator							iterator_type;
			typedef typename	__traits_type::iterator_category	iterator_category;
			typedef typename	__traits_type::value_type			value_type;
			typedef typename	__traits_type::difference_type		difference_type;
			typedef typename	__traits_type::reference			reference;
			typedef typename	__traits_type::pointer				pointer;
			
			normal_iterator() : current(_Iterator()) { }
			
			explicit normal_iterator(const _Iterator& i) : current(i) {	}
			
			~normal_iterator(void) { }

			reference operator*() const
			{
				return *current;
			}

			pointer operator->() const
			{
				return current;
			}
			
			normal_iterator& operator++()
			{
				++current;
				return *this;
			}

			normal_iterator operator++(int)
			{
				return normal_iterator(current++);
			}

			normal_iterator& operator--()
			{
				--current;
				return *this;
			}

			normal_iterator operator--(int)
			{
				return normal_iterator(current--);
			}

			reference operator[](const difference_type& n) const
			{
				return current[n];
			}

			normal_iterator& operator+=(const difference_type& n)
			{
				current += n;
				return *this;
			}

			normal_iterator& operator-=(const difference_type& n)
			{
				current -= n;
				return *this;
			}

			normal_iterator operator+(const difference_type& n) const
			{
				return normal_iterator(current + n);
			}

			normal_iterator operator+(const difference_type& n)
			{
				return normal_iterator(current + n);
			}

			normal_iterator operator-(const difference_type& n) const
			{
				return normal_iterator(current - n);
			}

			normal_iterator operator-(const difference_type& n)
			{
				return normal_iterator(current - n);
			}
			
			const _Iterator& base() const
			{
				return current;
			}
	};

	template<typename _IteratorL, typename _IteratorR>
		inline bool operator==(const normal_iterator<_IteratorL>& __lhs, const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() == __rhs.base();
		}

	template<typename _Iterator>
		inline bool
		operator==(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() == __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator!=(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() != __rhs.base();
		}

	template<typename _Iterator>
		inline bool
		operator!=(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() != __rhs.base();
		}
		
	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() < __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator<(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() < __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() > __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator>(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() > __rhs.base();
		}
		
	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<=(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{
			return !(__lhs > __rhs);
		}
	
	template<typename _Iterator>
		inline bool
		operator<=(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() <= __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>=(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{
			return __lhs.base() >= __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator>=(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() >= __rhs.base();
		}

	template<typename _Iterator>
		inline typename normal_iterator<_Iterator>::difference_type
		operator-(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() - __rhs.base();
		}
	
	template<typename _Iterator>
		inline normal_iterator<_Iterator>
		operator+(typename normal_iterator<_Iterator>::difference_type
			__n, const normal_iterator<_Iterator>& __i)
		{
			return normal_iterator<_Iterator>(__i.base() + __n);
		}
}

#endif
