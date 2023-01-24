/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/24 22:19:17 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

int main()
{
	std::cout << "***TESTING IS_INTEGRAL TEMPLATE***" << "\n" << "\n";
	std::cout << std::boolalpha;
	std::cout << "char : " << ft::is_integral<char>::value << std::endl;
	std::cout << "const char : " << ft::is_integral<const char >::value << std::endl;
	std::cout << "const volatile int : " << ft::is_integral<const volatile int>::value << std::endl;
	std::cout << "float : " << ft::is_integral<float>::value << "\n";
	std::cout << "int : " << ft::is_integral<int>::value << "\n";
	std::cout << "ft::vector<int> : " << ft::is_integral<ft::vector<int> >::value << "\n";
	std::cout << "short : " << ft::is_integral<short>::value << "\n";
	std::cout << "***" << "\n";
	return 0;
}
