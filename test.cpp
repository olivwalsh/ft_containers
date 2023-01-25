/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/25 14:38:48 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if REAL
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <vector.hpp>
#endif

template <typename T>
typename ft::enable_if<ft::is_integral<T>::value, T>::type add(T a, T b)
{
    return a + b;
}

template <typename T>
typename ft::enable_if<!ft::is_integral<T>::value, T>::type add(T a, T b)
{
	(void)a;
	(void)b;
    std::cout << "This function is only available for integral types." << std::endl;
    return T();
}

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

	std::cout << "***TESTING ENABLE IF***" << "\n\n";
	std::cout << add(4, 2) << std::endl;
    std::cout << add("hoho", "hihi") << std::endl;
	
	return 0;
}
