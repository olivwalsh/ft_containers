/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:03:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/23 19:05:55 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef typename	T::value_type				value_type;
			typedef typename	Allocator					allocator_type;
			typedef typename	Allocator::pointer			pointer;
			typedef 			const pointer				const_pointer;
			typedef typename	Allocator::value_type		reference;
			typedef 			const reference				const_reference;
			typedef typename	Allocator::size_type		size_type;
			typedef typename	Allocator::difference_type difference_type;
	
			// using iterator               = /* implementation-defined */;
			// using const_iterator         = /* implementation-defined */;
			// using reverse_iterator       = std::reverse_iterator<iterator>;
			// using const_reverse_iterator = std::reverse_iterator<const_iterator>;
			
			 
	};
}

#endif