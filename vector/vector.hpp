/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:03:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/27 18:56:56 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "type_traits.hpp"
# include "iterator.hpp"

namespace ft
{
	template <typename _Iterator>
	class normal_iterator : public std::iterator<std::random_access_iterator_tag, class T, std::ptrdiff_t, T*, T&> 
	{
		protected:
			_Iterator											current;
			typedef				ft::iterator_traits<_Iterator>	__traits_type;
		
		public:
			typedef				_Iterator							iterator_type;
			typedef typename	__traits_type::iterator_category	iterator_category;
			typedef typename	__traits_type::value_type			value_type;
			typedef typename	__traits_type::difference_type		difference_type;
			typedef typename	__traits_type::reference			reference;
			typedef typename	__traits_type::pointer				pointer;
			
			normal_iterator() : current(_Iterator()) { }
			explicit
			normal_iterator(const _Iterator& i) : current(i) { }
			~normal_iterator(void) { }

			reference operator*() const
			{
				return *current;
			}

			pointer operator->() const
			{
				return current;
			}
			
			normal_iterator& operator++()
			{
				++current;
				return *this;
			}

			normal_iterator operator++(int)
			{
				return normal_iterator(current++);
			}
						
			reference operator[](const difference_type& n) const
			{
				return current[n];
			}

			normal_iterator& operator+=(const difference_type& n)
			{
				current += n;
				return *this;
			}

			normal_iterator& operator+(const difference_type& n) const
			{
				return normal_iterator(current + n);
			}

			normal_iterator operator-(const difference_type& n) const
			{
				return normal_iterator(current - n);
			}
			
			const _Iterator& base() const
			{
				return current;
			}
	};

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator==(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() == __rhs.base();
		}

	template<typename _Iterator>
		inline bool
		operator==(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() == __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator!=(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() != __rhs.base();
		}

	template<typename _Iterator>
		inline bool
		operator!=(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() != __rhs.base();
		}
		
	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() < __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator<(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() < __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{ 
			return __lhs.base() > __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator>(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() > __rhs.base();
		}
		
	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<=(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{
			return !(__lhs > __rhs);
		}
	
	template<typename _Iterator>
		inline bool
		operator<=(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{ 
			return __lhs.base() <= __rhs.base();
		}

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>=(const normal_iterator<_IteratorL>& __lhs,
			const normal_iterator<_IteratorR>& __rhs)
		{
			return __lhs.base() >= __rhs.base();
		}
	
	template<typename _Iterator>
		inline bool
		operator>=(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() >= __rhs.base();
		}

	template<typename _Iterator>
		inline typename normal_iterator<_Iterator>::difference_type
		operator-(const normal_iterator<_Iterator>& __lhs,
			const normal_iterator<_Iterator>& __rhs)
		{
			return __lhs.base() - __rhs.base();
		}
	
	template<typename _Iterator>
		inline normal_iterator<_Iterator>
		operator+(typename normal_iterator<_Iterator>::difference_type
			__n, const normal_iterator<_Iterator>& __i)
		{
			return normal_iterator<_Iterator>(__i.base() + __n);
		}
	
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef 			T								value_type;
			typedef				Allocator						allocator_type;
			typedef typename	Allocator::pointer				pointer;
			typedef 			const pointer					const_pointer;
			typedef typename	Allocator::value_type			reference;
			typedef 			const reference					const_reference;
			typedef typename	Allocator::size_type			size_type;
			typedef typename	Allocator::difference_type		difference_type;
	
			typedef ft::normal_iterator<pointer>				iterator;
			typedef ft::normal_iterator<const_pointer>			const_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			
			
			/* ------------- constructors ------------- */
			explicit vector(const Allocator& alloc = allocator_type())
				:	_size(0), _capacity(0), _first_element(NULL), _memory_handle(alloc) { }
			
			explicit vector(size_type count, const T& value = T(), const Allocator& alloc = allocator_type())
				:	_size(count), _capacity(count), _first_element(NULL), _memory_handle(alloc)
				{
					(void)value;
					// insert value up to nth elements when insert is ready
				}
			
			template <class InputIt>
			vector(InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0, 
				const Allocator& alloc = allocator_type())
			{
				// Check whether it's an integral type.  If so, it's not an iterator
				_memory_handle = alloc;
				_size = std::distance(first, last);
				_capacity = _size * 2;
				_first_element = _memory_handle.allocate(_size);
				// while (first != last)
				// {
				// 	_first_elem = first;
				// 	_first_elem++;
				// 	first++;
				// }
			}
			
			// vector(const vector& other);
			
			~vector()
			{
				_memory_handle.deallocate(_first_element, _size);
			}
			
			// vector& 				operator=(const vector& other);
			// void					assign(size_type count, const T& value);
			// template <class InputIt>
			// void					assign(InputIt first, InputIt last);
			
			allocator_type 			get_allocator() const
			{
				return _memory_handle;
			}
			
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
				return reverse_iterator(_first_element + _size);
			}
			
			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(_first_element + _size);
			}

			reverse_iterator		rend()
			{
				return reverse_iterator(_first_element);
			}
			
			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(_first_element);
			}

			// /* ------------- capacity ------------- */
			bool					empty() const
			{
				return _size == 0;
			}
			// size_type				size() const;
			// size_type				max_size() const;
			
			// void					reserve(size_type new_cap)
			// {
			// 	if (new_cap > _capacity)
			// 		_capacity.allocate(new_cap);
			// }
			// size_type				capacity() const;

			// /* ------------- modifiers ------------- */
			// void					clear();
			// iterator insert(const_iterator pos, const T& value)
			// {
				
			// }
			
			size_t	getPosition(iterator pos)
			{
				size_t index = 0;
				
				for (iterator it = this->begin(); it != this->end() && it != pos; ++it)
				{
					index++;
				}
				return (index);
			}
			
			iterator insert(iterator pos, size_type count, const T& value)
			{
				// in case we have the right capacity
				size_t index = getPosition(pos);
				if (empty())
				{
					_first_element = _memory_handle.allocate(count);
					
				}
				else
				{
					
					pointer tab_end = _first_element + _size - 1;
					// std::cout << "old tab end is " << _size - 1 << std::endl;
					// std::cout << "starting new tab end at " << index + count << std::endl;
					// copy the content of the tab from pos to end of tab, to pos + count until new end of tab
					for (pointer new_tab_end = tab_end + count; new_tab_end != _first_element + index + count - 1; --new_tab_end)
					{
						// std::cout << "*tab_end: " << *tab_end << std::endl;
						_memory_handle.construct(new_tab_end, *tab_end);
						_memory_handle.destroy(tab_end);
						tab_end--;
					}
					
				}
				// then add value at
				pointer tmp = _first_element + index;
				while (count--)
				{
					_memory_handle.construct(tmp, value);
					tmp++;
					_size++;
				}
				
				return iterator(_first_element + index);
			}
			
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
			
			
		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_first_element;
			allocator_type	_memory_handle;
			
			
	};
}

#endif