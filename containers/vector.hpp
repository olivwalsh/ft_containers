/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:03:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/26 17:10:47 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "type_traits.hpp"
# include "iterator_traits.hpp"
# include "algorithm.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

# include <stdlib.h>
# include <iostream>
# include <typeinfo>

namespace ft
{	
	
	/* ------------- vector ------------- */
	
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef 			T											value_type;
			typedef				Allocator									allocator_type;
			typedef typename	Allocator::pointer							pointer;
			typedef typename	Allocator::const_pointer					const_pointer;
			typedef typename	Allocator::reference						reference;
			typedef typename	Allocator::const_reference					const_reference;
			typedef typename	Allocator::size_type						size_type;
			typedef typename	Allocator::difference_type					difference_type;
	
			typedef				ft::random_access_iterator<pointer>			iterator;
			typedef				ft::random_access_iterator<const_pointer>	const_iterator;
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			
			/* ------------- constructors ------------- */
			
			explicit vector(const Allocator& alloc = allocator_type())
				:	_size(0), _capacity(0), _first_element(NULL), _memory_handle(alloc) { }
			
			explicit vector(size_type count, const T& value = T(), const Allocator& alloc = allocator_type())
				:	_size(0), _capacity(0), _first_element(NULL), _memory_handle(alloc)
			{
				insert(begin(), count, value);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, int>::type = 0, 
				const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0), _first_element(NULL), _memory_handle(alloc)
			{
				_size = std::distance(first, last);
				if (_size > max_size())
					throw std::length_error("vector");
					
				_memory_handle = alloc;
				_first_element = _memory_handle.allocate(_size);
				_capacity = _size;
				
				for (size_type i = 0; i < _size; i++)
					_memory_handle.construct(_first_element + i, *(first++));
			}
			
			vector(const vector& other)
				: _size(0), _capacity(0), _first_element(NULL), _memory_handle(other.get_allocator())
			{
				*this = other;
			}
			
			~vector()
			{
				this->clear();
				_memory_handle.deallocate(_first_element, _capacity);
			}
			
			vector& operator=(const vector& other)
			{
				this->reserve(other.size());
				this->assign(other.begin(), other.end());
				return *this;
			}
			
			void assign(size_type count, const T& value)
			{
				if (_size)
					erase(begin(), end());
				insert(begin(), count, value);
			}
			
			template <class InputIt>
			void assign(InputIt first, InputIt last,  typename ft::enable_if<!is_integral<InputIt>::value, int>::type = 0)
			{
				if (_size)
					erase(begin(), end());
				insert(begin(), first, last);
			}
			
			allocator_type 			get_allocator() const
			{
				return _memory_handle;
			}
			
			
			/* ------------- element access ------------- */
			
			reference at(size_type pos)
			{
				if (pos < 0 || pos >= _size)
					throw std::out_of_range("vector::at(index) -> wrong index provided");
				else
					return *(_first_element + pos);
			}
			
			const_reference at(size_type pos) const
			{
				if (pos < 0 || pos >= _size)
					throw std::out_of_range("vector::at(index) -> wrong index provided");
				else
					return *(_first_element + pos);
			}
			
			reference operator[](size_type pos)
			{
				return *(_first_element + pos);
			}
			
			const_reference operator[](size_type pos) const
			{
				return *(_first_element + pos);
			}
			
			reference front()
			{
				return *_first_element;	
			}
			
			const_reference front() const
			{
				return *_first_element;
			}
			
			reference back()
			{
				return *(_first_element + _size - 1);
			}
			
			const_reference back() const
			{
				return *(_first_element + _size - 1);
			}
			
			pointer data()
			{
				return _first_element;
			}
			
			const pointer data() const
			{
				return _first_element;
			}
			

			/* ------------- iterators ------------- */
			
			iterator				begin(void)
			{
				return iterator(_first_element);
			}
			
			const_iterator			begin() const
			{
				return const_iterator(_first_element);
			}

			iterator				end(void)
			{
				return iterator(_first_element + _size);
			}
			
			const_iterator			end() const
			{
				return const_iterator(_first_element + _size);
			}
			
			reverse_iterator		rbegin()
			{
				return reverse_iterator(iterator(_first_element + _size));
			}
			
			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(const_iterator(_first_element + _size));
			}

			reverse_iterator		rend()
			{
				return reverse_iterator(iterator(_first_element));
			}
			
			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(const_iterator(_first_element));
			}


			/* ------------- capacity ------------- */
			
			bool					empty() const
			{
				return _size == 0;
			}
			size_type				size() const
			{
				return _size;
			}
			
			size_type				max_size() const
			{
				return _memory_handle.max_size();
			}
			
			pointer allocate_and_copy(size_type new_capacity)
			{
				pointer tmp = _memory_handle.allocate(new_capacity);
				for (size_type i = 0; i < _size; i++)
					_memory_handle.construct(tmp + i, _first_element[i]);
				return tmp;
			}

			void					reserve(size_type new_capacity)
			{
				if (new_capacity >= max_size())
					throw std::length_error("vector::reserve");
				if (_capacity < new_capacity)
				{
					pointer tmp = allocate_and_copy(new_capacity);
					for (size_type i = 0; i < _size; i++)
						_memory_handle.destroy(_first_element + i);
					_memory_handle.deallocate(_first_element, _capacity);
					_first_element = tmp;
					_capacity = new_capacity;
				}
				
			}
			
			size_type				capacity() const
			{
				return _capacity;
			}
			

			/* ------------- modifiers ------------- */
			
			void clear()
			{
				for (size_type i = 0; i < _size; ++i)
					_memory_handle.destroy(_first_element + i);
				_size = 0;
			}
			
			iterator insert(iterator pos, const T& value)
			{
				return insert(pos, 1, value);
			}
			
			iterator insert(iterator pos, size_type count, const T& value)
			{
				if (!count)
					return pos;
					
				size_type index = getIteratorPosition(pos);
				if (_size + count > _capacity)
				{
					size_type new_capacity = getNewCapacity(count);
					reserve(new_capacity);
				}
				if (!empty()) {
					pointer src_end = _first_element + _size;
					pointer dest_end = _first_element + _size + count;
					std::copy_backward(_first_element + index, src_end, dest_end);
				}

				pointer tmp = _first_element + index;
				for (size_type i = 0; i < count; ++i) {
					_memory_handle.construct(tmp + i, value);
				}

				_size += count;
				return iterator(_first_element + index);
			}
			
			template <class InputIt>
			void insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0)
			{
				typedef typename ft::iterator_traits<InputIt>::iterator_category category;
				if (typeid(category) != typeid(std::input_iterator_tag))
				{
					size_type distance = ft::distance(first, last);
					if (distance && distance >= max_size())
						return ;
   				}
				for (; first != last; ++first)
					pos = (insert(pos, 1, *first) + 1);
			}
			
			
			iterator erase(iterator pos)
			{
				if (pos != end() - 1)
					return erase(pos, pos + 1);
				else
				{
					_memory_handle.destroy(_first_element + _size - 1);
					_size--;
					return end();
				}
			}
			
			iterator erase(iterator first, iterator last)
			{
				size_type dist = std::distance(first, last);
				for (iterator it = first; it != last; ++it)
					_memory_handle.destroy(it.base());
				if (first + dist == end())
				{
					_size -= dist;
					return first;
				}
				for (iterator it = first; it != end() - dist; ++it)
				{
					_memory_handle.construct(it.base(), *(it + dist));
					_memory_handle.destroy(it.base() + dist);
				}
				_size -= dist;
				return first;
			}
			
			void push_back(const T& value)
			{
				insert(end(), 1, value);
			}
			
			void pop_back()
			{
				if (_size)
					erase(end() - 1);
			}
			
			void resize(size_type count, T value = T())
			{
				if (count >= max_size())
					throw std::length_error("ft::vector::resize -> provided count exceeds max_size()");
				if (count && count < _size)
					erase(iterator(_first_element + count), end());
				else if (count && count > _size)
					insert(end(), count - _size, value);
				else if (!count)
					clear();
			}
			
			void swap(vector& other)
			{
				size_type		tmp_size = _size;
				size_type		tmp_capacity = _capacity;
				pointer			tmp_first_element = _first_element;
				allocator_type	tmp_memory_handle = _memory_handle;
				
				_size = other.size();
				_capacity = other.capacity();
				_first_element = other.data();
				_memory_handle = other.get_allocator();
				other._size = tmp_size;
				other._capacity = tmp_capacity;
				other._first_element = tmp_first_element;
				other._memory_handle = tmp_memory_handle;
			}
			
		private:
		
			size_t	getNewCapacity(size_t count)
			{
				if (empty())
					return count;
				else if (_size + count <= _capacity)
					return _capacity;
				else if (_size + count <= _size * 2)
					return _size * 2;
				return _size + count;
			}

			size_t	getIteratorPosition(iterator pos)
			{
				size_t index = 0;
				
				for (iterator it = this->begin(); it != this->end() && it != pos; ++it)
					index++;
				return (index);
			}

			pointer	castIteratorToPointer(iterator position)
			{
				size_type index = 0;
				
				for (iterator it = begin(); it != end() && it != position; ++it)
					index++;
				return _first_element + index;
			}
			
			
		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_first_element;
			allocator_type	_memory_handle;
			
			
	};
	
	
	/* ------------- vector - non member functions ------------- */
	
	template<class T, class Alloc>
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
	}
	
	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	
	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return !(lhs > rhs);
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return rhs < lhs;
	}
	
	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
	
}

#endif