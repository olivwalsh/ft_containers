/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:18:10 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/25 17:49:19 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

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
		typedef std::random_access_iterator_tag iterator_category;
		typedef Tp								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Tp*								pointer;
		typedef Tp&								reference;
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
	
	

};

#endif