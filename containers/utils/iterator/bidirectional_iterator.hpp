/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:15:25 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/09 15:01:20 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{
	template <typename T>
	class rb_tree_iterator
	{
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;

		// typedef std::bidirectional_iterator_tag iterator_category;
		// typedef ptrdiff_t						difference_type;
		// typedef rb_tree_iterator<T>				self;
		
	};

};

#endif
