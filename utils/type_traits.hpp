/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:43:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/25 14:40:26 by owalsh           ###   ########.fr       */
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
	struct is_integral_helper : ft::false_type { };

	template <>
	struct is_integral_helper<signed char> : ft::true_type {};

	template <>
	struct is_integral_helper<unsigned char> : ft::true_type {};
	
	template <>
	struct is_integral_helper<short int> : ft::true_type {};

	template <>
	struct is_integral_helper<unsigned short int> : ft::true_type {};
	
	template <>
	struct is_integral_helper<int> : ft::true_type {};

	template <>
	struct is_integral_helper<unsigned int> : ft::true_type {};

	template <>
	struct is_integral_helper<long int> : ft::true_type {};

	template <>
	struct is_integral_helper<long long int> : ft::true_type {};

	template <>
	struct is_integral_helper<bool> : ft::true_type {};
	
	template <>
	struct is_integral_helper<char> : ft::true_type {};

	template <>
	struct is_integral_helper<wchar_t> : ft::true_type {};

	template <typename T>
	struct is_integral : is_integral_helper<typename remove_cv<T>::type> {};

	/* ------------- enable_if ------------- */
	template <bool B, typename T = void>
	struct enable_if { };

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	
};

#endif