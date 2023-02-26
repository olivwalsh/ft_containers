/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:57:24 by lgiband           #+#    #+#             */
/*   Updated: 2023/02/06 11:21:32 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <map>

#include "utils.hpp"

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "map.hpp"
#endif

#include "utils.hpp"

extern std::string name;

template<typename K, typename V>
void	display_map(std::ofstream &out, ft::map<K, V> &map, std::string str = "")
{
	out << str << "-> s:" << map.size() << ", e:" << map.empty();
	for (typename ft::map<K, V>::iterator it = map.begin(); it != map.end(); it++)
		out << " " << it->first << ":" << it->second;
	out << std::endl;
}

void	test_constructor_map(std::ofstream &out)
{
	out << name << "constructor" << std::endl;

	ft::map<int, int>		map;

	for (int i = 0; i < 10; i++)
		map.insert(ft::make_pair(i, i * 2));

	ft::map<int, int>		map2(map);
	ft::map<int, int>		map3;
	ft::map<int, int>		map4(map.begin(), map.end());
	map3 = map2;

	out << "<Set map(),map2(map),map3=map2,map4(m.b(),m.e())>" << std::endl;

	display_map(out, map, "map: ");
	display_map(out, map2, "map2: ");
	display_map(out, map3, "map3: ");
	display_map(out, map4, "map4: ");

	out << "<Remove 1 element from each map>" << std::endl;
	map.erase(2);
	map2.erase(3);
	map3.erase(4);
	map4.erase(5);
	
	display_map(out, map, "map: ");
	display_map(out, map2, "map2: ");
	display_map(out, map3, "map3: ");
	display_map(out, map4, "map4: ");

	out << "<Set map4.clear(), map3=map4>" << std::endl;
	map4.clear();
	map3 = map4;

	display_map(out, map3, "map3: ");
	display_map(out, map4, "map4: ");
	
	map3.insert(ft::make_pair(1, 2));
	map3.insert(ft::make_pair(2, 4));
	map3.insert(ft::make_pair(3, 6));

	map4.insert(ft::make_pair(1, 2));

	display_map(out, map3, "map3: ");
	display_map(out, map4, "map4: ");
}

void	test_iterator_map(std::ofstream &out)
{
	out << name << "iterator" << std::endl;

	ft::map<int, std::string> mymap;

    mymap.insert(ft::make_pair(11, "eleven"));
    mymap.insert(ft::make_pair(10, "ten"));
    mymap.insert(ft::make_pair(9, "nine"));
    mymap.insert(ft::make_pair(8, "eight"));
    mymap.insert(ft::make_pair(7, "seven"));
    mymap.insert(ft::make_pair(6, "six"));
    mymap.insert(ft::make_pair(5, "five"));
    mymap.insert(ft::make_pair(4, "four"));
    mymap.insert(ft::make_pair(3, "three"));
    mymap.insert(ft::make_pair(2, "two"));
    mymap.insert(ft::make_pair(1, "one"));

    ft::map<int, std::string>::iterator it = mymap.begin();
    ft::map<int, std::string>::const_iterator cit = mymap.begin();
    ft::map<int, std::string>::reverse_iterator rit = mymap.rbegin();
    ft::map<int, std::string>::const_reverse_iterator rcit = mymap.rbegin();

	ft::map<int, std::string>::iterator eit = --mymap.end();
    ft::map<int, std::string>::const_iterator ecit = --mymap.end();
    ft::map<int, std::string>::reverse_iterator erit = --mymap.rend();
    ft::map<int, std::string>::const_reverse_iterator ercit = --mymap.rend();

	out << "<map Iterator ++>" << std::endl;
    for (; it != mymap.end(); it++) { out << it->first << " => " << it->second << ", "; }
	out << std::endl;
	out << "<map Const Iterator++>" << std::endl;
    for (; cit != mymap.end(); cit++) {out << cit->first << " => " << cit->second << ", ";}
		
	out << std::endl;
	out << "<map Reverse Iterator ++>" << std::endl;
    for (; rit != mymap.rend(); rit++) {out << rit->first << " => " << rit->second << ", ";}
		
	out << std::endl;
	out << "<map Const Reverse Iterator ++>" << std::endl;
    for (; rcit != mymap.rend(); rcit++) {out << rcit->first << " => " << rcit->second << ", ";}
		
	out << std::endl;

	out << "<map Iterator -- >" << std::endl;
	for (; eit != mymap.begin(); eit--){out << eit->first << " => " << eit->second << ", ";}
	out << std::endl;

	out << "<map Const Iterator -- >" << std::endl;
	for (; ecit != mymap.begin(); ecit--){out << ecit->first << " => " << ecit->second << ", ";}

	out << std::endl;
	out << "<map Reverse Iterator -- >" << std::endl;
	for (; erit != mymap.rbegin(); erit--){out << erit->first << " => " << erit->second << ", ";}
		
	out << std::endl;
	out << "<map Const Reverse Iterator -- >" << std::endl;
	for (; ercit != mymap.rbegin(); ercit--){out << ercit->first << " => " << ercit->second << ", ";}
		
	out << std::endl;
}

void	test_map_capacity(std::ofstream &out)
{
	out << name << "capacity" << std::endl;

	ft::map<int, std::string> mymap;

	mymap.insert(ft::make_pair(11, "eleven"));
	mymap.insert(ft::make_pair(10, "ten"));
	mymap.insert(ft::make_pair(9, "nine"));
	mymap.insert(ft::make_pair(8, "eight"));
	mymap.insert(ft::make_pair(7, "seven"));
	mymap.insert(ft::make_pair(6, "six"));
	mymap.insert(ft::make_pair(5, "five"));
	mymap.insert(ft::make_pair(4, "four"));
	mymap.insert(ft::make_pair(3, "three"));
	mymap.insert(ft::make_pair(2, "two"));
	mymap.insert(ft::make_pair(1, "one"));

	out << "<map size>" << std::endl;
	out << mymap.size() << std::endl;

	out << "<map max_size>" << std::endl;
	out << mymap.max_size() << std::endl;

	out << "<map empty>" << std::endl;
	out << mymap.empty() << std::endl;

	out << "<map clear>" << std::endl;
	mymap.clear();
	out << mymap.empty() << std::endl;
	out << mymap.size() << std::endl;
}

void	test_map_element_access(std::ofstream &out)
{
	out << name << "element_access" << std::endl;

	ft::map<int, std::string> mymap;

	mymap.insert(ft::make_pair(11, "eleven"));
	mymap.insert(ft::make_pair(10, "ten"));
	mymap.insert(ft::make_pair(9, "nine"));
	mymap.insert(ft::make_pair(8, "eight"));
	mymap.insert(ft::make_pair(7, "seven"));
	mymap.insert(ft::make_pair(6, "six"));
	mymap.insert(ft::make_pair(5, "five"));
	mymap.insert(ft::make_pair(4, "four"));
	mymap.insert(ft::make_pair(3, "three"));
	mymap.insert(ft::make_pair(2, "two"));
	mymap.insert(ft::make_pair(1, "one"));

	out << "<map operator []>" << std::endl;
	out << mymap[1] << std::endl;
	out << mymap[2] << std::endl;
	out << mymap[3] << std::endl;
	out << mymap[4] << std::endl;
	out << mymap[5] << std::endl;
	out << mymap[6] << std::endl;
	out << mymap[7] << std::endl;
	out << mymap[8] << std::endl;
	out << mymap[9] << std::endl;
	out << mymap[10] << std::endl;
	out << mymap[11] << std::endl;

	out << "<map at>" << std::endl;
	out << mymap.at(1) << std::endl;
	out << mymap.at(2) << std::endl;
	out << mymap.at(3) << std::endl;
	out << mymap.at(4) << std::endl;
	out << mymap.at(5) << std::endl;
	out << mymap.at(6) << std::endl;
	out << mymap.at(7) << std::endl;
	out << mymap.at(8) << std::endl;
	out << mymap.at(9) << std::endl;
	out << mymap.at(10) << std::endl;
	out << mymap.at(11) << std::endl;

	out << mymap[-1] << std::endl;
	out << mymap.at(-1) << std::endl;
	out << mymap[15] << std::endl;
	out << mymap.at(15) << std::endl;
}

void	test_map_insert(std::ofstream &out)
{
	out << name << "insert" << std::endl;

	ft::map<int, std::string> mymap;
	mymap.insert(ft::make_pair(11, "eleven"));
	display_map(out, mymap, "map 11=eleven ");
	mymap.insert(ft::make_pair(11, "ten"));
	display_map(out, mymap, "map 11=ten ");
	mymap[11] = "nine";
	display_map(out, mymap, "map 11=nine ");

	ft::pair<ft::map<int, std::string>::iterator, bool> mypair = mymap.insert(ft::make_pair(10, "ten"));
	out << mypair.first->first << " " << mypair.first->second << " " << mypair.second << std::endl;
	mypair = mymap.insert(ft::make_pair(10, "ten"));
	out << mypair.first->first << " " << mypair.first->second << " " << mypair.second << std::endl;

	mymap.insert(ft::make_pair(-1, "minus one"));
	display_map(out, mymap, "map -1=minus one ");

	out << mymap.insert(mymap.begin(), ft::make_pair(12, "twelve"))->first << std::endl;
	display_map(out, mymap, "map 12=twelve ");
	
	out << mymap.insert(mymap.begin(), ft::make_pair(12, "twelve"))->first << std::endl;
	display_map(out, mymap, "map 12=twelve ");

	out << mymap.insert(++mymap.begin(), ft::make_pair(13, "thirteen"))->first << std::endl;
	display_map(out, mymap, "map 13=thirteen ");
	
	out << mymap.insert(++mymap.begin(), ft::make_pair(13, "thirteen"))->first << std::endl;
	display_map(out, mymap, "map 13=thirteen ");

	out << mymap.insert(--mymap.end(), ft::make_pair(14, "fourteen"))->first << std::endl;
	display_map(out, mymap, "map 14=fourteen ");

	ft::map<int, std::string>::iterator it = mymap.begin();
	for (int i = 0; i < 5; i++)
		it++;
	out << mymap.insert(it, ft::make_pair(14, "fourteen"))->first << std::endl;
	display_map(out, mymap, "map 14=fourteen ");

	out << mymap.insert(it, ft::make_pair(15, "quinze"))->first << std::endl;
	display_map(out, mymap, "map 15=quinze ");

	ft::map<int, std::string> mymap2;
	mymap2.insert(mymap.begin(), mymap.end());
	display_map(out, mymap2, "map2 ");

	mymap2.insert(ft::make_pair(5, "scainque"));
	display_map(out, mymap2, "map2 5=scainque ");
	display_map(out, mymap, "map ");

	ft::map<int, std::string> mymap3;
	mymap3.insert(mymap.end(), mymap.end());
	display_map(out, mymap3, "map3 ");

	ft::map<int, std::string> mymap4;
	mymap4.insert(mymap.begin(), mymap.begin());
	display_map(out, mymap4, "map4 ");

	ft::map<int, std::string> mymap5;
	mymap5.insert(mymap.begin(), ++mymap.begin());
	display_map(out, mymap5, "map5 ");

	ft::map<int, std::string> mymap6;
	mymap6.insert(--mymap.end(), mymap.end());
	display_map(out, mymap6, "map6 ");
}

void	test_map_erase(std::ofstream &out)
{
	out << name << "erase" << std::endl;

	ft::map<int, std::string> mymap;
	mymap.insert(ft::make_pair(1, "one"));
	mymap.insert(ft::make_pair(2, "two"));
	mymap.insert(ft::make_pair(3, "three"));
	mymap.insert(ft::make_pair(4, "four"));
	mymap.insert(ft::make_pair(5, "five"));
	mymap.insert(ft::make_pair(6, "six"));
	mymap.insert(ft::make_pair(7, "seven"));
	mymap.insert(ft::make_pair(8, "eight"));
	mymap.insert(ft::make_pair(9, "nine"));
	mymap.insert(ft::make_pair(10, "ten"));
	mymap.insert(ft::make_pair(11, "eleven"));
	mymap.insert(ft::make_pair(12, "twelve"));
	mymap.insert(ft::make_pair(13, "thirteen"));
	mymap.insert(ft::make_pair(14, "fourteen"));
	mymap.insert(ft::make_pair(15, "fifteen"));
	mymap.insert(ft::make_pair(16, "sixteen"));
	mymap.insert(ft::make_pair(17, "seventeen"));
	mymap.insert(ft::make_pair(18, "eighteen"));
	mymap.insert(ft::make_pair(19, "nineteen"));
	mymap.insert(ft::make_pair(20, "twenty"));
	mymap.insert(ft::make_pair(21, "twenty one"));
	mymap.insert(ft::make_pair(22, "twenty two"));
	mymap.insert(ft::make_pair(23, "twenty three"));
	mymap.insert(ft::make_pair(24, "twenty four"));
	mymap.insert(ft::make_pair(25, "twenty five"));
	mymap.insert(ft::make_pair(26, "twenty six"));
	mymap.insert(ft::make_pair(27, "twenty seven"));
	mymap.insert(ft::make_pair(28, "twenty eight"));
	mymap.insert(ft::make_pair(29, "twenty nine"));
	mymap.insert(ft::make_pair(30, "thirty"));
	mymap.insert(ft::make_pair(31, "thirty one"));
	mymap.insert(ft::make_pair(32, "thirty two"));
	
	display_map(out, mymap, "mymap contains");

	out << "<key erase>" << std::endl;

	out << mymap.erase(1) << std::endl;
	display_map(out, mymap, "mymap erase 1");
	out << mymap.erase(31) << std::endl;
	display_map(out, mymap, "mymap erase 31");
	out << mymap.erase(16) << std::endl;
	display_map(out, mymap, "mymap erase 16");
	out << mymap.erase(32) << std::endl;
	display_map(out, mymap, "mymap erase 32");
	out << mymap.erase(15) << std::endl;
	display_map(out, mymap, "mymap erase 15");
	out << mymap.erase(17) << std::endl;
	display_map(out, mymap, "mymap erase 17");
	out << mymap.erase(17) << std::endl;
	display_map(out, mymap, "mymap erase 17");


	out << "<iterator erase>" << std::endl;
	ft::map<int, std::string>::iterator it = mymap.begin();
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	ft::map<int, std::string>::iterator it3 = it;
	it3++;
	mymap.erase(mymap.begin(), it);
	display_map(out, mymap, "mymap erase begin");
	ft::map<int, std::string>::iterator it2 = it3;
	it2++;
	mymap.erase(it3);
	display_map(out, mymap, "mymap erase begin");
	it2++;
	it2++;
	mymap.erase(it2);
	display_map(out, mymap, "mymap erase begin + 2");

	mymap.erase(mymap.begin(), mymap.end());
	display_map(out, mymap, "erase all");
}

void	test_map_insert_too_many(std::ofstream &out)
{
	out << name << "insert too many" << std::endl;
	
	ft::map<int, std::string> mymap;

	for (int i = 0; i < 100000; i++)
		mymap.insert(ft::make_pair(i, "test"));
	display_map(out, mymap, "mymap contains");
}

void	test_map_swap(std::ofstream &out)
{
	out << name << "swap" << std::endl;

	ft::map<int, std::string> mymap;
	ft::map<int, std::string> mymap2;

	mymap.insert(ft::make_pair(1, "one"));
	mymap.insert(ft::make_pair(2, "two"));
	mymap.insert(ft::make_pair(3, "three"));
	mymap.insert(ft::make_pair(4, "four"));

	mymap2.insert(ft::make_pair(5, "five"));
	mymap2.insert(ft::make_pair(6, "six"));
	mymap2.insert(ft::make_pair(7, "seven"));
	mymap2.insert(ft::make_pair(8, "eight"));

	display_map(out, mymap, "mymap contains");
	display_map(out, mymap2, "mymap2 contains");

	mymap.swap(mymap2);

	display_map(out, mymap, "mymap contains");
	display_map(out, mymap2, "mymap2 contains");
	
	ft::map<int, std::string> mymap3;
	ft::map<int, std::string> mymap4;

	mymap3.insert(ft::make_pair(1, "one"));
	mymap3.insert(ft::make_pair(2, "two"));
	mymap3.insert(ft::make_pair(3, "three"));
	mymap3.insert(ft::make_pair(4, "four"));

	mymap4.insert(ft::make_pair(5, "five"));
	mymap4.insert(ft::make_pair(6, "six"));
	mymap4.insert(ft::make_pair(7, "seven"));
	mymap4.insert(ft::make_pair(8, "eight"));

	display_map(out, mymap3, "mymap3 contains");
	display_map(out, mymap4, "mymap4 contains");

	swap(mymap3, mymap4);

	display_map(out, mymap3, "mymap3 contains");
	display_map(out, mymap4, "mymap4 contains");
}

void	test_map_comparison(std::ofstream &out)
{
	out << name << "comparison" << std::endl;

	ft::map<int, std::string> mymap;
	ft::map<int, std::string> mymap2;

	for (int i = 0; i < 20; i++)
	{
		mymap.insert(ft::make_pair(i, "test"));
		mymap2.insert(ft::make_pair(i, "test"));
	}

	out << "mymap == mymap2 : " << (mymap == mymap2) << std::endl;
	out << "mymap != mymap2 : " << (mymap != mymap2) << std::endl;
	out << "mymap < mymap2 : " << (mymap < mymap2) << std::endl;
	out << "mymap <= mymap2 : " << (mymap <= mymap2) << std::endl;
	out << "mymap > mymap2 : " << (mymap > mymap2) << std::endl;
	out << "mymap >= mymap2 : " << (mymap >= mymap2) << std::endl;

	mymap2.insert(ft::make_pair(20, "test"));
	out << "<mymap2 insert 20>" << std::endl;

	out << "mymap == mymap2 : " << (mymap == mymap2) << std::endl;
	out << "mymap != mymap2 : " << (mymap != mymap2) << std::endl;
	out << "mymap < mymap2 : " << (mymap < mymap2) << std::endl;
	out << "mymap <= mymap2 : " << (mymap <= mymap2) << std::endl;
	out << "mymap > mymap2 : " << (mymap > mymap2) << std::endl;
	out << "mymap >= mymap2 : " << (mymap >= mymap2) << std::endl;
}

void	test_map_find(std::ofstream &out)
{
	out << name << "find" << std::endl;

	ft::map<int, std::string> mymap;

	for (int i = 0; i < 20; i++)
		mymap.insert(ft::make_pair(i, "test"));

	ft::map<int, std::string>::iterator it = mymap.find(10);
	out << "mymap.find(10) : " << it->first << " " << it->second << std::endl;
	it = mymap.find(30);
	//out << "mymap.find(30) : " << it->first << " " << it->second << std::endl;

	ft::map<int, std::string>::const_iterator it2 = mymap.find(10);
	out << "mymap.find(10) : " << it2->first << " " << it2->second << std::endl;
	it2 = mymap.find(30);
	//out << "mymap.find(30) : " << it2->first << " " << it2->second << std::endl;

	out << mymap.count(10) << std::endl;
	out << mymap.count(30) << std::endl;
}

void	test_map_bound(std::ofstream &out)
{
	out << name << "bound" << std::endl;

	ft::map<int, std::string> mymap;

	for (int i = 0; i < 30;i+=3)
		mymap.insert(ft::make_pair(i, "test"));

	const ft::map<int, std::string> mymap2(mymap);

	ft::map<int, std::string>::iterator it = mymap.lower_bound(10);
	ft::map<int, std::string>::iterator dit = mymap.upper_bound(10);
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ret = mymap.equal_range(10);

	out << "mymap.lower_bound(10) : " << it->first << " " << it->second << std::endl;
	out << "mymap.upper_bound(10) : " << dit->first << " " << dit->second << std::endl;
	for (ft::map<int, std::string>::iterator it = ret.first; it != ret.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it = mymap.lower_bound(11);
	dit = mymap.upper_bound(11);
	ret = mymap.equal_range(11);

	out << "mymap.lower_bound(11) : " << it->first << " " << it->second << std::endl;
	out << "mymap.upper_bound(11) : " << dit->first << " " << dit->second << std::endl;
	for (ft::map<int, std::string>::iterator it = ret.first; it != ret.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it = mymap.lower_bound(12);
	dit = mymap.upper_bound(12);
	ret = mymap.equal_range(12);

	out << "mymap.lower_bound(12) : " << it->first << " " << it->second << std::endl;
	out << "mymap.upper_bound(12) : " << dit->first << " " << dit->second << std::endl;
	for (ft::map<int, std::string>::iterator it = ret.first; it != ret.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it = mymap.lower_bound(13);
	dit = mymap.upper_bound(13);
	ret = mymap.equal_range(13);

	out << "mymap.lower_bound(13) : " << it->first << " " << it->second << std::endl;
	out << "mymap.upper_bound(13) : " << dit->first << " " << dit->second << std::endl;
	for (ft::map<int, std::string>::iterator it = ret.first; it != ret.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;
	
	

	
	ft::map<int, std::string>::const_iterator it2 = mymap2.lower_bound(10);
	ft::map<int, std::string>::const_iterator dit2 = mymap2.upper_bound(10);
	ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> ret2 = mymap2.equal_range(10);
	out << "mymap2.lower_bound(10) : " << it2->first << " " << it2->second << std::endl;
	out << "mymap2.upper_bound(10) : " << dit2->first << " " << dit2->second << std::endl;
	for (ft::map<int, std::string>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it2 = mymap2.lower_bound(11);
	dit2 = mymap2.upper_bound(11);
	ret2 = mymap2.equal_range(11);

	out << "mymap2.lower_bound(11) : " << it2->first << " " << it2->second << std::endl;
	out << "mymap2.upper_bound(11) : " << dit2->first << " " << dit2->second << std::endl;
	for (ft::map<int, std::string>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it2 = mymap2.lower_bound(12);
	dit2 = mymap2.upper_bound(12);
	ret2 = mymap2.equal_range(12);

	out << "mymap2.lower_bound(12) : " << it2->first << " " << it2->second << std::endl;
	out << "mymap2.upper_bound(12) : " << dit2->first << " " << dit2->second << std::endl;
	for (ft::map<int, std::string>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it2 = mymap2.lower_bound(13);
	dit2 = mymap2.upper_bound(13);
	ret2 = mymap2.equal_range(13);

	out << "mymap2.lower_bound(13) : " << it2->first << " " << it2->second << std::endl;
	out << "mymap2.upper_bound(13) : " << dit2->first << " " << dit2->second << std::endl;
	for (ft::map<int, std::string>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;

	it2 = mymap2.lower_bound(27);
	ret2 = mymap2.equal_range(27);

	out << "mymap2.lower_bound(13) : " << it2->first << " " << it2->second << std::endl;
	for (ft::map<int, std::string>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << it->first << " " << it->second << std::endl;
	out << std::endl;
}

void	test_map_observer(std::ofstream &out)
{
	out << name << "map observer" << std::endl;

	ft::map<int, std::string> mymap;
	ft::map<int, std::string>::key_compare mycomp = mymap.key_comp();
	ft::map<int, std::string>::value_compare mycomp2 = mymap.value_comp();

	mymap[100] = "a";
	mymap[200] = "b";
	mymap[300] = "c";

	out << "mymap contains:" << std::endl;
	ft::pair<int, std::string> highest = *mymap.rbegin(); // last element

	ft::map<int, std::string>::iterator it = mymap.begin();
	ft::map<int, std::string>::iterator it2 = mymap.begin();
	do
	{
		out << it->first << " => " << it->second << std::endl;
		
	} while (mycomp2((*it++), highest));

	do
	{
		out << it2->first << " => " << it2->second << std::endl;
		
	} while (mycomp((*it2++).first, highest.first));

	out << std::endl;
}

void	test_map(std::ofstream &out)
{
	out << name << "map" << std::endl;

		void	(*fonc[])(std::ofstream&) = {&test_constructor_map, &test_iterator_map, &test_map_capacity,
										&test_map_element_access, &test_map_insert, &test_map_insert_too_many, &test_map_erase,
										&test_map_swap, &test_map_comparison, &test_map_find, &test_map_bound, &test_map_observer};
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