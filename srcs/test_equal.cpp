/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_equal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:32:09 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/19 13:27:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "equal.hpp"
#endif

extern std::string name;

void	test_equal(std::ofstream &out)
{
	out << name << "equal" << std::endl;
	
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {1, 2, 3, 4, 5};
	int b2[] = {1, 2, 3, 4, 6};

	std::string c = "aloalo";
	std::string d = "kayak";

	out << "{1, 2, 3, 4, 5} == {1, 2, 3, 4, 5} : " << ft::equal(a, a + 5, b) << std::endl;
	out << "{1, 2, 3, 4, 5} == {1, 2, 3, 4, 6} : " << ft::equal(a, a + 5, b2) << std::endl;
	out << "aloalo == kayak : " << ft::equal(c.begin(), c.end(), d.begin()) << std::endl;
	out << "kayak == (reverse)kayak : " << ft::equal(d.begin(), d.end(), d.rbegin(), std::equal_to<char>()) << std::endl;
}
