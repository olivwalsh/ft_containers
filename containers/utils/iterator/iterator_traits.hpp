/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:18:10 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/24 18:46:59 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>

namespace ft
{
	
	/* ------------- iterator traits ------------- */
	
	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <typename Tp>
	struct iterator_traits <Tp*>
	{
		typedef			std::random_access_iterator_tag iterator_category;
		typedef 		Tp								value_type;
		typedef 		std::ptrdiff_t					difference_type;
		typedef 		Tp*								pointer;
		typedef 		Tp&								reference;
	};

	template <typename Tp>
	struct iterator_traits <const Tp*>
	{
		typedef 		std::random_access_iterator_tag iterator_category;
		typedef 		Tp								value_type;
		typedef 		std::ptrdiff_t					difference_type;
		typedef const	Tp*								pointer;
		typedef const	Tp&								reference;
	};
	
	template <typename It>
	typename iterator_traits<It>::difference_type
	iterator_difference(It first, It last)
	{
		return (last - first);
	}

	template <typename It>
	typename iterator_traits<It>::difference_type
	compute_difference(It first, It last, std::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <typename It>
	typename iterator_traits<It>::difference_type
	compute_difference(It first, It last, std::bidirectional_iterator_tag)
	{
		size_t	i = 0;
		while (first != last)
		{
			first++;
			i++;
		}
		return (i);
	}

	template <typename It>
	typename iterator_traits<It>::difference_type
	compute_difference(It first, It last, std::input_iterator_tag)
	{
		typename std::iterator_traits<It>::difference_type count = 0;
		while (first != last)
		{
			++count;
			++first;
		}
		return count;
	}

	template <typename It>
	typename iterator_traits<It>::difference_type
	distance(It first, It last)
	{
		return (compute_difference(first, last, typename ft::iterator_traits<It>::iterator_category()));
	}

		
};

#endif