/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:43:35 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/24 22:20:12 by owalsh           ###   ########.fr       */
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
	

	template <typename T>
	struct is_integral : ft::false_type { };

	template <>
	struct is_integral<bool> : ft::true_type {};

	template <>
	struct is_integral<char> : ft::true_type {};
	
};

#endif