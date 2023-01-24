/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:43:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/24 22:55:54 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

/*
	is_integral returns true for:
		- five standard signed integer types: signed char, short int, int, long int, long long int
		- implementation defined extended signed integer types
		- unsigned integer types
		- all char types: char, wchar_t, char8_t, char16_t, char32_t
		- bool
		- + all these types with const, volatile and const volatile
*/ 
namespace ft
{
	template <bool B>
	struct bool_constant
	{
		static const bool value = B;
	};

	struct true_type : public bool_constant<true> {};

	struct false_type : public bool_constant<false> {};

	/* ------------- remove const volatile ------------- */
	template< class T >
	struct remove_cv
	{ 
		typedef T type;
	};

	template< class T >
	struct remove_cv <const T>
	{ 
		typedef T type;
	};

	template< class T >
	struct remove_cv <volatile T>
	{ 
		typedef T type;
	};

	template< class T >
	struct remove_cv <const volatile T>
	{ 
		typedef T type;
	};

	/* ------------- is_integral ------------- */
	template <typename T>
	struct is_int : ft::false_type { };

	template <>
	struct is_int<signed char> : ft::true_type {};
	
	template <>
	struct is_int<short int> : ft::true_type {};
	
	template <>
	struct is_int<int> : ft::true_type {};

	template <>
	struct is_int<long int> : ft::true_type {};

	template <>
	struct is_int<long long int> : ft::true_type {};

	template <>
	struct is_int<bool> : ft::true_type {};
	
	template <>
	struct is_int<char> : ft::true_type {};

	template <typename T>
	struct is_integral : is_int<typename remove_cv<T>::type> {};
	
};

#endif