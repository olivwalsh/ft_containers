/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:57:21 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/01 13:38:53 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{

	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; first1 != last2 && first2 != last2; ++first1, ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; first1 != last1 && first2 != last2; ++first1, ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template< class InputIt1, class InputIt2 >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2)) 
			{
				return false;
			}
		}
		
		return true;
	}
	
	template <class InputIt1, class InputIt2, class BinaryPredictate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredictate p)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(p(*first1, *first2)))
				return false;
		}
		return true;
	}
};

#endif