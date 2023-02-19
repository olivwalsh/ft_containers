/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:41:18 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/19 16:31:46 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	
	template <class T1, class T2>
	class pair
	{
		public:
			typedef	T1	first_type;
			typedef	T2	second_type;

			first_type first;
			second_type second;

			pair() : first(), second() { }
			pair( const first_type& x, const second_type& y ) : first(x), second(y) { }
			
			template <class U1, class U2>
			pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }

			// pair	&operator=( const pair &p )
			// {
				
			// 	// first = p.first;
			// 	second = p.second;
			// 	return *this;
			// }

			// template< class U1, class U2 >
			// pair	&operator=( const pair< U1, U2 > &p )
			// {
			// 	first = p.first;
			// 	second = p.second;

			// 	return *this;
			// }
		
	};

	template< class T1, class T2 >
	pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	}

	template< class T1, class T2 >
	bool operator==( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	
	template< class T1, class T2 >
	bool operator!=( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator<( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template< class T1, class T2 >
	bool operator<=( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return rhs < lhs;
	}

	template< class T1, class T2 >
	bool operator>=( const pair<T1, T2>& lhs, const pair<T1, T2>& rhs )
	{
		return !(lhs < rhs);
	}

};

#endif