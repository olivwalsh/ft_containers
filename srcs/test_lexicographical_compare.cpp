/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexicographical_compare.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:45:55 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/19 13:26:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "lexicographical_compare.hpp"
#endif

extern std::string name;

void	test_lexicographical_compare(std::ofstream &out)
{
	out << name << "lexicographical_compare" << std::endl;
	
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {1, 2, 3, 4, 5};
	int b2[] = {1, 2, 3, 4, 6};

	std::string c = "aloalo";
	std::string d = "kayak";

	out << "{1, 2, 3, 4, 5} == {1, 2, 3, 4, 5} : " << ft::lexicographical_compare(a, a + 5, b, b + 5) << std::endl;
	out << "{1, 2, 3, 4, 5} == {1, 2, 3, 4, 6} : " << ft::lexicographical_compare(a, a + 5, b2, b2 + 5) << std::endl;
	out << "aloalo == kayak : " << ft::lexicographical_compare(c.begin(), c.end(), d.begin(), d.end()) << std::endl;
	out << "kayak == (reverse)kayak : " << ft::lexicographical_compare(d.begin(), d.end(), d.rbegin(), d.rend(), std::equal_to<char>()) << std::endl;
}
