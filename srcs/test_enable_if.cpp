/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_enable_if.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:25:30 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/19 13:27:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <type_traits>
#include <limits>
#include <fstream>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "enable_if.hpp"
#endif

extern std::string	name;

template <typename T>
typename ft::enable_if<std::numeric_limits<T>::is_integer, T>::type	multiply(T x)
{
	return (x * x);
}

void	test_enable_if(std::ofstream &out)
{
	out << name << "enable_if_test" << std::endl;

	out << multiply(2) << std::endl;
//	out << multiply("yo") << std::endl;
}
