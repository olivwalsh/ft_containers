/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:51:17 by lgiband           #+#    #+#             */
/*   Updated: 2023/02/06 11:18:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <typeinfo>

#include "utils.hpp"

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#include "utils.hpp"

extern std::string name;

template<typename T>
void	display_vector(ft::vector<T> &v, std::ofstream& out)
{
	out << v.size() << " " << v.empty() << " ";
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++ )
		out << *it << " ";
	out << std::endl;
}

template<typename T>
void	display_vector_content(ft::vector<T> &v, std::ofstream& out, std::string prompt = "")
{
	out << prompt << " ";
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++ )
		out << *it << " ";
	out << std::endl;
}

void	test_vector_constructor(std::ofstream& out)
{
	out << "<Vector Constructor>" << std::endl;
	
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	ft::vector<int> v1;
	ft::vector<int> v2(v1);
	ft::vector<int> v3((size_t)5, 42);
	ft::vector<int> v4(a.begin() + 2, a.end());

	v1 = v3;
	ft::vector<int, std::allocator<int> > v5;

	//v1 = v1;
	v1[0] = 1;
	v3[0] = 1;
	v3[1] = 21;
	display_vector(v1, out);
	display_vector(v2, out);
	display_vector(v3, out);
	display_vector(v4, out);
	display_vector(v5, out);

	ft::vector<std::string> v6(5, "Hello");
	ft::vector<std::string> v7(v6);
	ft::vector<std::string> v8;
	ft::vector<std::string> v9(v8.begin(), v8.end());

	v8 = v6;

	display_vector(v6, out);
	display_vector(v7, out);
	display_vector(v8, out);
	display_vector(v9, out);
	
}

void	test_vector_element_access(std::ofstream& out)
{
	out << "<Vector Element Access>" << std::endl;

	std::vector<int> a;
	std::vector<int> a2;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	
	a2.push_back(6);
	a2.push_back(7);
	a2.push_back(8);
	a2.push_back(9);
	a2.push_back(10);
	
	ft::vector<int> v(a.begin(), a.end());
	ft::vector<int> v2(a2.begin(), a2.end());
	
	out << "<Set: v={1, 2, 3, 4, 5}, v2={6, 7, 8, 9, 10}>" << std::endl;
	
	out << "v.front() = " << v.front() << std::endl;
	out << "v2.front() = " << v2.front() << std::endl;
	out << "v.back() = " << v.back() << std::endl;
	out << "v2.back() = " << v2.back() << std::endl;
	out << "v[2] = " << v[2] << std::endl;
	out << "v2[2] = " << v2[2] << std::endl;
	out << "v.at(2) = " << v.at(2) << std::endl;
	out << "v2.at(2) = " << v2.at(2) << std::endl;
	out << "<Set: v[4] = 42>" << std::endl;
	v[4] = 42;
	out << "v[4] = " << v[4] << std::endl;
	out << "<Set: v.at(3) = 21>" << std::endl;
	v.at(3) = 21;
	out << "v.at(3) = " << v.at(3) << std::endl;
	out << "Get allocator: " << v.get_allocator().max_size() << std::endl;
}

void	test_vector_iterator(std::ofstream &out)
{
	out << "<Vector Iterator>" << std::endl;

	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	ft::vector<int> v(a.begin(), a.end());
	const ft::vector<int> v2(a.begin(), a.end());

	out << "<Set: v={1, 2, 3, 4, 5}>" << std::endl;

	out << "v.begin() = " << *v.begin() << std::endl;
	out << "v.end() = " << *(v.end() - 1) << std::endl;
	out << "v.rbegin() = " << *v.rbegin() << std::endl;
	out << "v.rend() = " << *(v.rend() - 1) << std::endl;

	out << "v.begin() + 2 = " << *(v.begin() + 2) << std::endl;
	out << "v.end() - 2 = " << *(v.end() - 2) << std::endl;
	out << "v.rbegin() + 2 = " << *(v.rbegin() + 2) << std::endl;
	out << "v.rend() - 2 = " << *(v.rend() - 2) << std::endl;

	out << "<Iterator ++>" << std::endl;
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++ )
		out << *it << " ";
	out << std::endl;
	out << "<Iterator -->" << std::endl;
	for (ft::vector<int>::iterator it = v.end() - 1; it != v.begin() - 1; it-- )
		out << *it << " ";
	out << std::endl;
	out << "<Reverse Iterator ++>" << std::endl;
	for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++ )
		out << *it << " ";
	out << std::endl;
	out << "<Reverse Iterator -->" << std::endl;
	for (ft::vector<int>::reverse_iterator it = v.rend() - 1; it != v.rbegin() - 1; it-- )
		out << *it << " ";
	out << std::endl;
	out << "<Const Iterator ++>" << std::endl;
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); it++ )
		out << *it << " ";
	out << std::endl;
	out << "<Const Iterator -->" << std::endl;
	for (ft::vector<int>::const_iterator it = v.end() - 1; it != v.begin() - 1; it-- )
		out << *it << " ";
	out << std::endl;
	out << "<Const Reverse Iterator ++>" << std::endl;
	for (ft::vector<int>::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++ )
		out << *it << " ";
	out << std::endl;
	out << "<Const Reverse Iterator -->" << std::endl;
	for (ft::vector<int>::const_reverse_iterator it = v.rend() - 1; it != v.rbegin() - 1; it-- )
		out << *it << " ";
	out << std::endl;
	
}

template<typename It2, typename It1>
void	compare(It1 it1, It2 it2, std::ofstream &out)
{
	out << std::boolalpha << "it1 == it2: " << (it1 == it2) << std::endl;
	out << std::boolalpha << "it1 != it2: " << (it1 != it2) << std::endl;
	out << std::boolalpha << "it1 < it2: " << (it1 < it2) << std::endl;
	out << std::boolalpha << "it1 <= it2: " << (it1 <= it2) << std::endl;
	out << std::boolalpha << "it1 > it2: " << (it1 > it2) << std::endl;
	out << std::boolalpha << "it1 >= it2: " << (it1 >= it2) << std::endl;
}

void	test_vector_comparison(std::ofstream &out)
{
	out << "<Vector Comparison>" << std::endl;

	std::vector<int> a;
	std::vector<int> a2;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	
	a2.push_back(6);
	a2.push_back(7);
	a2.push_back(8);
	a2.push_back(9);
	a2.push_back(10);

	ft::vector<int> v(a.begin(), a.end());
	ft::vector<int> v2(a2.begin(), a2.end());
	ft::vector<int> v3(a.begin(), a.end());
	ft::vector<int> v4;

	out << "<Set a={1, 2, 3, 4, 5}, a2={6, 7, 8, 9, 10}>" << std::endl;
	out << "<Set a3={1, 2, 3, 4, 5}>" << std::endl;

	//std::cout << typeid(*v.begin()).name() << std::endl;
	//std::cout << typeid(a).name() << std::endl;
	out << "v == v2 = " << (v == v2) << std::endl;
	out << "v == v3 = " << (v == v3) << std::endl;
	out << "v == v4 = " << (v == v4) << std::endl;
	out << "v != v2 = " << (v != v2) << std::endl;
	out << "v != v3 = " << (v != v3) << std::endl;
	out << "v != v4 = " << (v != v4) << std::endl;
	out << "v < v2 = " << (v < v2) << std::endl;
	out << "v < v3 = " << (v < v3) << std::endl;
	out << "v < v4 = " << (v < v4) << std::endl;
	out << "v <= v2 = " << (v <= v2) << std::endl;
	out << "v <= v3 = " << (v <= v3) << std::endl;
	out << "v <= v4 = " << (v <= v4) << std::endl;
	out << "v > v2 = " << (v > v2) << std::endl;
	out << "v > v3 = " << (v > v3) << std::endl;
	out << "v > v4 = " << (v > v4) << std::endl;
	out << "v >= v2 = " << (v >= v2) << std::endl;
	out << "v >= v3 = " << (v >= v3) << std::endl;
	out << "v >= v4 = " << (v >= v4) << std::endl;

	out << "<Swap>" << std::endl;
	
	out << "<From :>" << std::endl;
	display_vector(v, out);
	display_vector(v2, out);

	ft::swap(v, v2);
	
	out << "<To :>" << std::endl;
	display_vector(v, out);
	display_vector(v2, out);

	out << "<From :>" << std::endl;
	display_vector(v, out);
	display_vector(v4, out);

	ft::swap(v, v4);
	
	out << "<To :>" << std::endl;
	display_vector(v, out);
	display_vector(v4, out);

	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator it2 = v2.begin();
	ft::vector<int>::const_iterator it3 = v.begin();
	ft::vector<int>::const_iterator it4 = v2.begin();
	ft::vector<int>::reverse_iterator it5 = v.rbegin();
	ft::vector<int>::reverse_iterator it6 = v2.rbegin();
	ft::vector<int>::const_reverse_iterator it7 = v.rbegin();
	ft::vector<int>::const_reverse_iterator it8 = v2.rbegin();

	ft::vector<int>::iterator eit = v.end();
	ft::vector<int>::iterator eit2 = v2.end();
	ft::vector<int>::const_iterator eit3 = v.end();
	ft::vector<int>::const_iterator eit4 = v2.end();
	ft::vector<int>::reverse_iterator eit5 = v.rend();
	ft::vector<int>::reverse_iterator eit6 = v2.rend();
	ft::vector<int>::const_reverse_iterator eit7 = v.rend();
	ft::vector<int>::const_reverse_iterator eit8 = v2.rend();

	out << "<Vector compare Iterators>" << std::endl;

	compare(it, it2, out);
	compare(it3, it4, out);
	compare(it5, it6, out);
	compare(it7, it8, out);
	compare(eit, eit2, out);
	compare(eit3, eit4, out);
	compare(eit5, eit6, out);
	compare(eit7, eit8, out);
	compare(it, eit, out);
	compare(it3, eit3, out);
	compare(it5, eit5, out);
	compare(it7, eit7, out);
	out << "it == it3 = " << (it == it3) << std::endl;
	out << "it == it5 = " << (it3 == it) << std::endl;
	out << "it == it7 = " << (it5 == it7) << std::endl;
	out << "it == it7 = " << (it7 == it5) << std::endl;
}

void	test_vector_assign(std::ofstream &out)
{
	out << "<Vector Assign>" << std::endl;

	std::vector<int> a;
	std::vector<int> a2;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	
	a2.push_back(6);
	a2.push_back(7);
	a2.push_back(8);
	a2.push_back(9);
	a2.push_back(10);
	a2.push_back(11);
	a2.push_back(12);
	a2.push_back(13);
	a2.push_back(14);
	a2.push_back(15);

	ft::vector<int> v(a.begin(), a.end());
	ft::vector<int> v2(a2.begin(), a2.end());
	ft::vector<int> v3(a.begin(), a.end());

	out << "<Set v={1, 2, 3, 4, 5}>\n<Set v2={6, 7, 8, 9, 10, 11, 12, 13, 14, 15}>\n<Set v3={1, 2, 3, 4, 5}>" << std::endl;
	
	display_vector(v, out);

	out << "<Set v=v2>" << std::endl;
	v.assign(v2.begin(), v2.end());
	display_vector(v, out);
	out << "<Set v=v3>" << std::endl;
	v.assign(v3.begin(), v3.end());
	display_vector(v, out);

	ft::vector<int> v4(a.begin(), a.end());

	v4.assign((size_t)10, 42);
	out << "<Set v4.assign(10, 42)>" << std::endl;
	display_vector(v4, out);
	
	v4.assign((size_t)2, 21);
	out << "<Set v4.assign(2, 21)>" << std::endl;
	display_vector(v4, out);

	ft::vector<std::string> v5;
	ft::vector<std::string> v6;

	v5.push_back("Hello");
	v5.push_back("World");
	v5.push_back("!");
	out << "<Set v5={\"Hello\", \"World\", \"!\"}>" << std::endl;
	display_vector(v5, out);
	v6.assign(v5.begin(), v5.end());
	out << "<Set v6=v5>" << std::endl;
	display_vector(v6, out);

	v6.assign(0, "Hello");
	out << "<Set v6.assign(0, \"Hello\")>" << std::endl;
	display_vector(v6, out);
	v6.assign(1, "Hello");
	out << "<Set v6.assign(1, \"Hello\")>" << std::endl;
	display_vector(v6, out);

	v6.assign(64, "hell");
	out << "<Set v6.assign(64, \"hell\")>" << std::endl;
	display_vector(v6, out);
}

void	test_vector_pushback_ten(std::ofstream& out)
{
	out << "<Vector Pushback 10>" << std::endl;

	ft::vector<int>	v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	out << v.size() << " " << v.capacity() << " " << v.empty() << std::endl;

}

void	test_vector_pushback_hundred(std::ofstream& out)
{
	out << "<Vector Pushback 100>" << std::endl;

	ft::vector<int>	v;

	
	for (int i = 0; i < 100; i++)
		v.push_back(i);
	out << v.size() << " " << v.capacity() << " " << v.empty() << std::endl;

}

void	test_vector_pushback_thousands(std::ofstream& out)
{
	out << "<Vector Pushback 1000>" << std::endl;

	ft::vector<int>	v;
	
	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	out << v.size() << " " << v.capacity() << " " << v.empty() << std::endl;
}

void	test_vector_pushback_too_many(std::ofstream& out)
{
	out << "<Vector Pushback 1000000>" << std::endl;

	ft::vector<int>	v;
	
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	out << v.size() << " " << v.capacity() << " " << v.empty() << std::endl;
}

void	test_vector_pop(std::ofstream &out)
{
	out << "<Vector Pop>" << std::endl;
	
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
	{	
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		display_vector(v, out);
		
		for (int i = 0; i < 10; i++) //std crash if pop_back() is called on empty vector
			v.pop_back();
		display_vector(v, out);

	}
}

void	test_vector_insert(std::ofstream& out)
{
	out << "<Vector Insert>" << std::endl;

	ft::vector<int> v;
	ft::vector<std::string> v2;

	for (int i = 0; i < 7; i++)
		v.push_back(i);

	for (int i = 0; i < 10; i++)
	{
		v.insert(v.begin() + 3, 10 + i);
		display_vector(v, out);
	}
	for (int i = 0; i < 10; i++)
	{
		v.insert(v.begin(), 20 + i);
		display_vector(v, out);
	}
	out << "v.insert(v.begin() + 3, 100 + i) = " << *(v.insert(v.begin() + 3, 100 + 15)) << std::endl;

	v.insert(v.begin() + 1, 5);
	display_vector(v, out);

	v.insert(v.end(), 5);
	display_vector(v, out);

	v.insert(v.begin(), 5);
	display_vector(v, out);

	std::string	str[] = {"Hello", "World", "!"};
	v2.assign(str, str + 3);
	display_vector_content(v2, out);
	v2.insert(v2.begin() + 1, "C++");
	display_vector_content(v2, out);
	v2.insert(v2.begin(), "C++");
	display_vector_content(v2, out);
	v2.insert(v2.end(), "C++");

	display_vector_content(v2, out);

	ft::vector<char> v3;

	std::istringstream str2("1 2 3 4 5 6 7");
    std::istreambuf_iterator<char> it(str2), end;

	v3.insert(v3.end(), it, end);
	display_vector_content(v3, out);
}

void	test_vector_insert_fill(std::ofstream& out)
{
	out << "<Vector Insert Fill>" << std::endl;

	ft::vector<int> v;

	for (int i = 0; i < 7; i++)
		v.push_back(i);

	v.insert(v.begin() + 3, (size_t)10, 42);
	display_vector_content(v, out, "v = ");
	v.push_back(42);
	display_vector_content(v, out, "v = ");

	v.insert(v.begin() + 8, (size_t)1000, 21);
	display_vector_content(v, out, "v = ");
}

void	test_vector_insert_range(std::ofstream& out)
{
	out << "<Vector Insert Range>" << std::endl;

	//10 elements
	//std::string str[] = {"Hello", "World", "!", "I", "am", "a", "string", "vector", "!", "!"};

	ft::vector<int> v;
	ft::vector<int> v2;
	ft::vector<int> v3;

	for (int i = 0; i < 7; i++)
		v2.push_back(i);

	for (int i = 0; i < 100; i++)
		v.push_back(i);

	out << "<Set v: >" << std::endl;
	display_vector(v, out);
	out << "<Set: v2 = v2[0:4]v[:]v2[4:]>" << std::endl;
	v2.insert(v2.begin() + 3, v.begin(), v.end());
	display_vector_content(v2, out, "v2 = ");
	v2.push_back(42);
	display_vector_content(v2, out, "v2 = ");

	out << "<Set same x20>" << std::endl;
	for (int i = 0; i < 20; i++)
		v2.insert(v2.begin(), v.begin(), v.end());
	display_vector_content(v2, out, "v2: ");

	out << "<Set v3 empty and run v x20>" << std::endl;
	for (int i = 0; i < 20; i++)
		v3.insert(v3.begin(), v.begin(), v.end());
	v3.push_back(42);
	display_vector_content(v3, out, "v3: ");
}

void	test_vector_insert_toomany(std::ofstream& out)
{
	out << "<Vector Insert Too Many>" << std::endl;

	ft::vector<int> v;

	for (int i = 0; i < 10000; i++)
		v.insert(v.begin(), i);
	display_vector(v, out);
}

void	test_vector_erase(std::ofstream &out)
{
	out << "<Vector Erase>" << std::endl;
	
	ft::vector<int> v;
	ft::vector<int> v2;
	
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	for (int i = 0; i < 10000; i++)
		v2.push_back(i);
		
	out << "ret: " << *(v.erase(v.begin() + 3)) << std::endl;
	out << "ret: " << *(v2.erase(v2.begin() + 3, v2.begin() + 7)) << std::endl;

	display_vector(v, out);
	display_vector(v2, out);

	for (int i = 0; i < 4000; i++)
		v2.erase(v2.begin() + 2);
	display_vector(v2, out);

	//for (int i = 0; i < 20; i++)
	v2.erase(v2.begin() + 5 , v2.begin() + 100);
	display_vector(v2, out);
}

void	test_vector_clear(std::ofstream &out)
{
	out << "<Vector Clear>" << std::endl;
	
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	display_vector(v, out);
	v.clear();
	display_vector(v, out);
	v.clear();
	display_vector(v, out);
}

void	test_vector_swap(std::ofstream &out)
{
	out << "<Vector Swap>" << std::endl;

	ft::vector<int> v;
	ft::vector<int> v2;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	for (int i = 0; i < 10000; i++)
		v2.push_back(i);

	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator it2 = v2.begin();

	display_vector(v, out);
	display_vector(v2, out);
	v.swap(v2);

	for (; it2 != v.end(); it2++)
		out << *it2 << " ";
	out << std::endl;
	for (; it != v2.end(); it++)
		out << *it << " ";

	v.swap(v);
	display_vector(v, out);
}

void	test_vector_resize(std::ofstream &out)
{
	out << "<Vector Resize>" << std::endl;

	ft::vector<int> v;
	
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	display_vector(v, out);
	v.resize(5);
	display_vector(v, out);
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	v.resize(20, 42);
	display_vector_content(v, out, "v.resize(20, 42): ");
	v.resize(118, 21);
	display_vector_content(v, out, "v.resize(118, 21): ");
	v.resize(100000, 5);
	display_vector_content(v, out, "v.resize(100000, 5): ");
    ft::vector<int> c;

	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
    out << "The vector holds: ";
    display_vector_content(c, out, "c: ");

 
    c.resize(5);
    out << "After resize up to 5: ";
    display_vector_content(c, out, "c: ");

 
    c.resize(2);
    out << "After resize down to 2: ";
    display_vector_content(c, out, "c: ");
 
    c.resize(6, 4);
    out << "After resize up to 6 (initializer = 4): ";
    display_vector_content(c, out, "c: ");
}

void	test_vector_reserve(std::ofstream& out)
{
	out << "<Vector Reserve>" << std::endl;

	ft::vector<int> v;

	out << "<Set v.reserve(100)>" << std::endl;
	v.reserve(100);
	out << "v.capacity(): " << v.capacity() << std::endl;
	out << "<Set v.reserve(1000)>" << std::endl;
	v.reserve(1000);
	out << "v.capacity(): " << v.capacity() << std::endl;
	out << "<Set v.reserve(5)>" << std::endl;
	v.reserve(5);
	out << "v.capacity(): " << v.capacity() << std::endl;
	out << "<Set v.reserve(0)>" << std::endl;
	v.reserve(0);
	out << "v.capacity(): " << v.capacity() << std::endl;
	out << "<Set v.reserve(45465654)>" << std::endl;
	v.reserve(45465654);
	out << "v.capacity(): " << v.capacity() << std::endl;
}

void	test_vector(std::ofstream &out)
{
	out << name << "vector" << std::endl;

		void	(*fonc[])(std::ofstream&) = {&test_vector_constructor, &test_vector_element_access, &test_vector_iterator,
										&test_vector_comparison, &test_vector_assign, &test_vector_reserve,
										&test_vector_pushback_ten, &test_vector_pushback_hundred, &test_vector_pushback_thousands,
										&test_vector_pushback_too_many, &test_vector_pop, &test_vector_insert,
										&test_vector_insert_toomany, &test_vector_insert_fill, &test_vector_insert_range,
										&test_vector_erase, &test_vector_swap, &test_vector_clear, &test_vector_resize};
	//std::cout  << "\n";
	for (long unsigned int i = 0; i < sizeof(fonc) / sizeof(fonc[0]); i++)
	{
		std::cout << "\33[2K\r" << "\033[0;33m"
			<< "[" << progressBar(i, sizeof(fonc) / sizeof(fonc[0]), 40, '=') << "]  "
			<< i << "/" << sizeof(fonc) / sizeof(fonc[0]) << "\033[0m"
			<< std::flush;
		time_test(fonc[i], out);
	}
	
}