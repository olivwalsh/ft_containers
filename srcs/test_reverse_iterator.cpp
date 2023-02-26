/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:53:53 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/24 12:05:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "reverse_iterator.hpp"
	#include "vector.hpp"
#endif

extern std::string name;

void	comparison_operator_test(std::ofstream &out)
{
	int a[] = {0, 1, 2, 3};
	out << "<Set: array, 0->1->2->3>" << std::endl;
	
	out << "<Comparison operators>" << std::endl;
    ft::reverse_iterator<int*> x(a + 4);
	ft::reverse_iterator<int*> y(a + 4);
	ft::reverse_iterator<int*> z(a + 3);
 
    out
        << std::boolalpha
        << "*x == " << *x << '\n' // 3
        << "*y == " << *y << '\n' // 3
        << "*z == " << *z << '\n' // 2
        << "x == y ? " << (x == y) << '\n' // true
        << "x != y ? " << (x != y) << '\n' // false
        << "x <  y ? " << (x <  y) << '\n' // false
        << "x <= y ? " << (x <= y) << '\n' // true
        << "x == z ? " << (x == z) << '\n' // false
        << "x != z ? " << (x != z) << '\n' // true
        << "x <  z ? " << (x <  z) << '\n' // true
        << "x <= z ? " << (x <= z) << '\n' // true
		;
	
	out << "<Edit: z--, y++>" << std::endl;
	z--;
	y++;
	out << std::boolalpha
        << "*x == " << *x << '\n' // 3
        << "*y == " << *y << '\n' // 3
        << "*z == " << *z << '\n' // 2
        << "x == y ? " << (x == y) << '\n' // true
        << "x != y ? " << (x != y) << '\n' // false
        << "x <  y ? " << (x <  y) << '\n' // false
        << "x <= y ? " << (x <= y) << '\n' // true
        << "x == z ? " << (x == z) << '\n' // false
        << "x != z ? " << (x != z) << '\n' // true
        << "x <  z ? " << (x <  z) << '\n' // true
        << "x <= z ? " << (x <= z) << '\n' // true
		;
	
}

void	modification_operator_test(std::ofstream &out)
{
	out << "<Modification operators>" << std::endl;
	ft::vector<int> v;

	out << "<Set: ft::vector, 1->2->3->4->5>" << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);

	out << "<Set: x:end, y:begin>" << std::endl;

	ft::reverse_iterator<ft::vector<int>::iterator> x(v.begin() + 9);
	ft::reverse_iterator<ft::vector<int>::iterator> y(v.begin() + 7);
	
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	for (int i = 0; i < 6; i++)
	{
		out << "<Edit: x++, y++>" << std::endl;
		x++;
		y++;
		out << "*x == " << *x << std::endl;
		out << "*y == " << *y << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		out << "<Edit: x--, y-->" << std::endl;
		x--;
		y--;
		out << "*x == " << *x << std::endl;
		out << "*y == " << *y << std::endl;
	}
	out << "<Edit: x + 4, y + 4>" << std::endl;
	x = x + 4;
	y = y + 4;
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	out << "<Edit: x - 1, y - 1>" << std::endl;
	x = x - 1;
	y = x - 1;
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	out << "<Edit: x += 4, y += 4>" << std::endl;
	x += 4;
	y += 4;
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	out << "<Edit: x -= 1, y -= 1>" << std::endl;
	x -= 1;
	y -= 1;
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	out << "<Edit: --x, --y>" << std::endl;
	out << "*--x == " << *--x << ", *x ==" << *x << std::endl;
	out << "*--y == " << *--y << ", *y ==" << *y << std::endl;
	out << "<Edit: ++x, ++y>" << std::endl;
	out << "*++x == " << *++x << ", *x ==" << *x << std::endl;
	out << "*++y == " << *++y << ", *y ==" << *y << std::endl;
	out << "<Edit: x--, y-->" << std::endl;
	out << "*x-- == " << *x-- << ", *x ==" << *x << std::endl;
	out << "*y-- == " << *y-- << ", *y ==" << *y << std::endl;
	out << "<Edit: x++, y++>" << std::endl;
	out << "*x++ == " << *x++ << ", *x ==" << *x << std::endl;
	out << "*y++ == " << *y++ << ", *y ==" << *y << std::endl;
}

void	access_operator_test(std::ofstream &out)
{
	out << "<Modification operators>" << std::endl;
	ft::vector<int> v;

	out << "<Set: ft::vector, 1->2->3->4->5>" << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	ft::reverse_iterator<ft::vector<int>::iterator> x(v.end());
	
	out << "*x == " << *x << std::endl;
	out << "x[0] == " << x[0] << std::endl;
	out << "x[2] == " << x[2] << std::endl;
	out << "<Edit: x++>" << std::endl;
	x++;
	out << "(&x)->base() == " << *((&(x))->base()) << std::endl;
}

void	constructor_test(std::ofstream &out)
{
	out << "<Constructor reverse_iterator test>" << std::endl;
	ft::vector<int> v;

	out << "<Set: ft::vector, 1->2->3->4->5>" << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	out << "<Set: x:end, y:begin>" << std::endl;
	ft::reverse_iterator<ft::vector<int>::iterator> x(v.end());
	ft::reverse_iterator<ft::vector<int>::iterator> y;
	ft::reverse_iterator<ft::vector<int>::iterator> z(x);

	y = x;
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	out << "*z == " << *z << std::endl;
	out << std::boolalpha << "x == y : " << (x == y) << std::endl;
	out << std::boolalpha << "x == z : " << (x == z) << std::endl;
	out << std::boolalpha << "y == z : " << (y == z) << std::endl;
	
	out << "<Edit: x++>" << std::endl;
	x++;
	out << "*x == " << *x << std::endl;
	out << "*y == " << *y << std::endl;
	out << "*z == " << *z << std::endl;
	out << std::boolalpha << "x == y : " << (x == y) << std::endl;
	out << std::boolalpha << "x == z : " << (x == z) << std::endl;
	out << std::boolalpha << "y == z : " << (y == z) << std::endl;
	
}

void	reverse_iterator_test(std::ofstream &out)
{
	out << name << "reverse_iterator_test" << std::endl;
	
	constructor_test(out);
	comparison_operator_test(out);
	modification_operator_test(out);
	access_operator_test(out);
}