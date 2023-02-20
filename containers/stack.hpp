/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:36:26 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/20 18:54:50 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

	/* ------------- stack ------------- */

	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef				Container					container_type;
			typedef typename	Container::value_type		value_type;
			typedef typename	Container::size_type		size_type;
			typedef typename	Container::reference		reference;
			typedef typename	Container::const_reference	const_reference;

	
			explicit stack(const Container& cont = Container()) : c(cont)
			{
			}

			stack( const stack& other ) : c(other.c)
			{
				// *this = other;
			}
			
			~stack() { }

			stack & operator=(const stack& other)
			{
				c = other.c;
				return *this;
			}

			reference top()
			{
				return c.back();
			}

			const_reference top() const
			{
				return c.back();
			}
			
			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			void push(const value_type& value)
			{
				return c.push_back(value);
			}

			void pop()
			{
				return c.pop_back();
			}

			template <class U, class V>
			friend bool operator==(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs);

			template <class U, class V>
			friend bool operator!=(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs);
			
			template <class U, class V>
			friend bool operator>(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs);
			
			template <class U, class V>
			friend bool operator>=(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs);
			
			template <class U, class V>
			friend bool operator<(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs);
			
			template <class U, class V>
			friend bool operator<=(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs);

		protected:
			Container	c;
	};

	template <class U, class V>
	bool operator==(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class U, class V>
	bool operator!=(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs)
	{
		return lhs.c != rhs.c;
	}

	template <class U, class V>
	bool operator>(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs)
	{
		return lhs.c > rhs.c;
	}

	template <class U, class V>
	bool operator>=(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs)
	{
		return lhs.c >= rhs.c;
	}

	template <class U, class V>
	bool operator<(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class U, class V>
	bool operator<=(const ft::stack<U, V>& lhs, const ft::stack<U, V>& rhs)
	{
		return lhs.c <= rhs.c;
	}
	
};

#endif