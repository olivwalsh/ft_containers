/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:36:24 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/09 15:02:14 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "bidirectional_iterator.hpp"
# include "red_black_tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< std::pair<const Key, T> > >
	class map
	{
		public:
			typedef				Key 										key_type;
			typedef				T											mapped_type;
			typedef				std::pair<const Key, T>						value_type;
			typedef				std::size_t									size_type;
			typedef				std::ptrdiff_t								difference_type;
			typedef				Compare										key_compare;
			typedef				Allocator									allocator_type;
			typedef				value_type&									reference;
			typedef				const value_type&							const_reference;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			// typedef				ft::bidirectional_iterator<pointer>			iterator;
			// typedef				ft::bidirectional_iterator<const_pointer>	const_iterator;
			// typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		

			/* ------------- constructors ------------- */
			map();
			explicit map(const Compare& comp, const Allocator& alloc = Allocator())
			{
				(void)comp;
				(void)alloc;
			}
			
			/* ------------- element access ------------- */
			
			/* ------------- iterators ------------- */
			
			/* ------------- cpacity ------------- */
			
			/* ------------- modifiers ------------- */
			
			/* ------------- lookup ------------- */

			/* ------------- observers ------------- */
		
		
	};
};

#endif