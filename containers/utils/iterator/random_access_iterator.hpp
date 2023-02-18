/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:44:31 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/07 16:13:14 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_HPP
# define RANDOM_ACCESS_HPP

# include "iterator_traits.hpp"
# include "type_traits.hpp"

namespace ft
{


	/* ------------- random access iterator ------------- */

	template <typename _Iterator>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, _Iterator, std::ptrdiff_t, _Iterator*, _Iterator&> 
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
			
			random_access_iterator() : current(_Iterator()) { }
			
			explicit random_access_iterator(const _Iterator& i) : current(i) {	}
			
			template <typename Iter>
			random_access_iterator(const random_access_iterator<Iter> &rhs)
			{
				*this = rhs;
			}
			
			~random_access_iterator(void) { }

			template <typename Iter>
			random_access_iterator & operator=(const random_access_iterator<Iter>& rhs)
			{
				current = rhs.base();
				return *this;
			}
			
			reference operator*() const
			{
				return *current;
			}

			pointer operator->() const
			{
				return current;
			}
			
			random_access_iterator& operator++()
			{
				++current;
				return *this;
			}

			random_access_iterator operator++(int)
			{
				return random_access_iterator(current++);
			}

			random_access_iterator& operator--()
			{
				--current;
				return *this;
			}

			random_access_iterator operator--(int)
			{
				return random_access_iterator(current--);
			}

			reference operator[](const difference_type& n) const
			{
				return current[n];
			}

			random_access_iterator& operator+=(const difference_type& n)
			{
				current += n;
				return *this;
			}

			random_access_iterator& operator-=(const difference_type& n)
			{
				current -= n;
				return *this;
			}

			random_access_iterator operator+(const difference_type& n) const
			{
				return random_access_iterator(current + n);
			}

			random_access_iterator operator+(const difference_type& n)
			{
				return random_access_iterator(current + n);
			}

			random_access_iterator operator-(const difference_type& n) const
			{
				return random_access_iterator(current - n);
			}

			random_access_iterator operator-(const difference_type& n)
			{
				return random_access_iterator(current - n);
			}

			difference_type	operator-(const random_access_iterator& n) const
			{
				return (current - n.current);
			}

			difference_type	operator+(const random_access_iterator& n) const
			{
				return (current + n.current);
			}
			
			const _Iterator& base() const
			{
				return current;
			}
	};

	template<typename _IteratorL, typename _IteratorR>
		inline bool operator==(const random_access_iterator<_IteratorL>& __lhs, const random_access_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() == __rhs.base();
		}

	template<typename _Iterator>
		inline bool
		operator==(const random_access_iterator<_Iterator>& __lhs,
			const random_access_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() == __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator!=(const random_access_iterator<_IteratorL>& __lhs,
			const random_access_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() != __rhs.base();
		}

	template<typename _Iterator>
		inline bool
		operator!=(const random_access_iterator<_Iterator>& __lhs,
			const random_access_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() != __rhs.base();
		}
		
	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<(const random_access_iterator<_IteratorL>& __lhs,
			const random_access_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() < __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator<(const random_access_iterator<_Iterator>& __lhs,
			const random_access_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() < __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>(const random_access_iterator<_IteratorL>& __lhs,
			const random_access_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() > __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator>(const random_access_iterator<_Iterator>& __lhs,
			const random_access_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() > __rhs.base();
		}
		
	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<=(const random_access_iterator<_IteratorL>& __lhs,
			const random_access_iterator<_IteratorR>& __rhs)
		{
			return !(__lhs > __rhs);
		}
	
	template<typename _Iterator>
		inline bool
		operator<=(const random_access_iterator<_Iterator>& __lhs,
			const random_access_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() <= __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>=(const random_access_iterator<_IteratorL>& __lhs,
			const random_access_iterator<_IteratorR>& __rhs)
		{
			return __lhs.base() >= __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator>=(const random_access_iterator<_Iterator>& __lhs,
			const random_access_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() >= __rhs.base();
		}

	template<typename _Iterator>
		inline typename random_access_iterator<_Iterator>::difference_type
		operator-(const random_access_iterator<typename remove_cv<_Iterator>::type>& __lhs,
			const random_access_iterator<typename remove_cv<_Iterator>::type>& __rhs)
		{
			return __lhs.base() - __rhs.base();
		}
		
	template<typename _Iterator>
		inline random_access_iterator<_Iterator>
		operator+(typename random_access_iterator<_Iterator>::difference_type
			__n, const random_access_iterator<_Iterator>& __i)
		{
			return random_access_iterator<_Iterator>(__i.base() + __n);
		}
}

#endif
