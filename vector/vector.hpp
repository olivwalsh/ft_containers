/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:03:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/25 19:02:10 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "type_traits.hpp"
# include "iterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef typename	T::value_type				value_type;
			typedef				Allocator					allocator_type;
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
			
			
			// /* ------------- constructors ------------- */
			// vector();
			// explicit vector(const Allocator& alloc);
			// explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
			// template <class InputIt>
			// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
			// vector(const vector& other);
			// ~vector();
			
			// vector& 				operator=(const vector& other);
			// void					assign(size_type count, const T& value);
			// template <class InputIt>
			// void					assign(InputIt first, InputIt last);
			
			// allocator_type 			get_allocator() const;
			
			// /* ------------- element access ------------- */
			// reference				at(size_type pos);
			// const_reference			at(size_type pos);
			// reference				operator[](size_type pos);
			// const_reference 		operator[](size_type pos) const;
			// reference				front();
			// const_reference			front() const;
			// reference				back();
			// const_reference			back() const;
			// T*						data();
			// const T*				data() const;

			// /* ------------- iterators ------------- */
			// iterator				begin();
			// const_iterator			begin() const;
			// iterator				end();
			// const_iterator			end() const;
			// reverse_iterator		rbegin();
			// const_reverse_iterator	rbegin()const;
			// reverse_iterator		rend();
			// const_reverse_iterator	rend() const;

			// /* ------------- capacity ------------- */
			// bool					empty() const;
			// size_type				size() const;
			// size_type				max_size() const;
			// void					reserve(size_type new_cap);
			// size_type				capacity() const;

			// /* ------------- modifiers ------------- */
			// void					clear();
			// iterator				insert(const_iterator pos, const T& value);
			// iterator				insert(const_iterator pos, size_type count, const T& value);
			// template <class InputIt>
			// iterator				insert(const_iterator pos, InputIt first, InputIt last);
			// iterator				erase(iterator pos);
			// iterator				erase(iterator first, iterator last);
			// void					push_back(const T& value);
			// void					pop_back();
			// void					resize(size_type count, T value = T());
			// void					swap(vector& other);
			
			// /* ------------- operators cmp ------------- */
			// template<class T, class Alloc>
			// bool					operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
			// template<class T, class Alloc>
			// bool					operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
			// template<class T, class Alloc>
			// bool					operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
			// template<class T, class Alloc>
			// bool					operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
			// template<class T, class Alloc>
			// bool					operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
			// template<class T, class Alloc>
			// bool					operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);

			// template<class T, class Alloc>
			// void					swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs);
			
			

			
			
	};
}

#endif