/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:45:58 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/19 14:48:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "is_integral.hpp"
#endif

extern std::string name;

void	test_is_integral(std::ofstream &out)
{
	(void)out;
	out << name << "is_integral_test" << std::endl;

	out << "<Need to be True>" << std::endl;

	out << "bool -> "<< std::boolalpha << ft::is_integral<bool>::value << std::endl;
	out << "char -> "<< std::boolalpha << ft::is_integral<char>::value << std::endl;
	out << "signed char -> "<< std::boolalpha << ft::is_integral<signed char>::value << std::endl;
	out << "unsigned char -> "<< std::boolalpha << ft::is_integral<unsigned char>::value << std::endl;
	out << "wchar_t -> "<< std::boolalpha << ft::is_integral<wchar_t>::value << std::endl;
	out << "short -> "<< std::boolalpha << ft::is_integral<short>::value << std::endl;
	out << "unsigned short -> "<< std::boolalpha << ft::is_integral<unsigned short>::value << std::endl;
	out << "int -> "<< std::boolalpha << ft::is_integral<int>::value << std::endl;
	out << "long int -> "<< std::boolalpha << ft::is_integral<long int>::value << std::endl;
	out << "long long int -> "<< std::boolalpha << ft::is_integral<long long int>::value << std::endl;
	out << "unsigned int -> "<< std::boolalpha << ft::is_integral<unsigned int>::value << std::endl;
	out << "unsigned char -> "<< std::boolalpha << ft::is_integral<unsigned char>::value << std::endl;
	out << "unsigned short int -> "<< std::boolalpha << ft::is_integral<unsigned short int>::value << std::endl;
	out << "long -> "<< std::boolalpha << ft::is_integral<long>::value << std::endl;
	out << "unsigned long -> "<< std::boolalpha << ft::is_integral<unsigned long>::value << std::endl;
	out << "unsigned long int -> "<< std::boolalpha << ft::is_integral<unsigned long int>::value << std::endl;
	out << "long long -> "<< std::boolalpha << ft::is_integral<long long>::value << std::endl;
	out << "unsigned long long -> "<< std::boolalpha << ft::is_integral<unsigned long long>::value << std::endl;
	out << "unsigned long long int -> "<< std::boolalpha << ft::is_integral<unsigned long long int>::value << std::endl;
	
	out << "<Need to be False>" << std::endl;
	out << "float -> "<< std::boolalpha << ft::is_integral<float>::value << std::endl;
	out << "double -> "<< std::boolalpha << ft::is_integral<double>::value << std::endl;
	out << "long double -> "<< std::boolalpha << ft::is_integral<long double>::value << std::endl;
	out << "std::string -> "<< std::boolalpha << ft::is_integral<std::string>::value << std::endl;
	out << "std::vector<int> -> "<< std::boolalpha << ft::is_integral<std::vector<int> >::value << std::endl;
	out << "std::vector<std::string> -> "<< std::boolalpha << ft::is_integral<std::vector<std::string> >::value << std::endl;
	out << "std::vector<std::vector<int> > -> "<< std::boolalpha << ft::is_integral<std::vector<std::vector<int> > >::value << std::endl;
}
