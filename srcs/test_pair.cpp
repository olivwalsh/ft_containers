/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:10:25 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/24 12:12:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "pair.hpp"
	#include "vector.hpp"
#endif

extern std::string name;

template <typename T1, typename T2>
void print_pair(std::string rem, ft::pair<T1, T2> const& pair, std::ofstream& out)
{
	out << rem << "(" << pair.first << ", " << pair.second << ")\n";
}

void	test_pair(std::ofstream& out)
{
	out << name << "pair" << std::endl;
	
    ft::pair<int, float> p1;
    print_pair("(1) Value-initialized: ", p1, out);
 
    ft::pair<int, double> p2(42, 3.1415);
    print_pair("(2) Initialized with two values: ", p2, out);

	ft::pair <std::string,double> product1;                     // default constructor
	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	ft::pair <std::string,double> product3 (product2);          // copy constructor

	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	out << "The price of " << product1.first << " is $" << product1.second << '\n';
	out << "The price of " << product2.first << " is $" << product2.second << '\n';
	out << "The price of " << product3.first << " is $" << product3.second << '\n';

	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	out << "foo: " << foo.first << ", " << foo.second << '\n';
	out << "bar: " << bar.first << ", " << bar.second << '\n';

	ft::vector<ft::pair<int, std::string> > v;
	v.push_back(ft::make_pair(2, "baz"));
	v.push_back(ft::make_pair(2, "bar"));
	v.push_back(ft::make_pair(1, "foo"));
	v.push_back(ft::make_pair(3, "qux"));

	for (ft::vector<ft::pair<int, std::string> >::iterator it = v.begin(); it != v.end(); ++it)
		out << "{" << it->first << ", " << it->second << "}\n";

	out << "<Set sort>\n";
    std::sort(v.begin(), v.end());
 
	for (ft::vector<ft::pair<int, std::string> >::iterator it = v.begin(); it != v.end(); ++it)
		out << "{" << it->first << ", " << it->second << "}\n";

}