/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:46:01 by lgiband           #+#    #+#             */
/*   Updated: 2023/02/06 11:30:18 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <set>

#include "utils.hpp"

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "set.hpp"
#endif

#include "utils.hpp"

extern std::string name;

template<typename K, typename V>
void	display_set(std::ofstream &out, ft::set<K, V> &set, std::string str = "")
{
	out << str << "-> s:" << set.size() << ", e:" << set.empty();
	for (typename ft::set<K, V>::iterator it = set.begin(); it != set.end(); it++)
		out << "  " << *it;
	out << std::endl;
}

void	test_constructor_set(std::ofstream &out)
{
	out << name << "constructor" << std::endl;

	ft::set<int>		set;

	for (int i = 0; i < 10; i++)
		set.insert(i*2);

	ft::set<int>		set2(set);
	ft::set<int>		set3;
	ft::set<int>		set4(set.begin(), set.end());
	set3 = set2;

	out << "<Set set(),set2(set),set3=set2,set4(m.b(),m.e())>" << std::endl;

	display_set(out, set, "set: ");
	display_set(out, set2, "set2: ");
	display_set(out, set3, "set3: ");
	display_set(out, set4, "set4: ");

	out << "<Remove 1 element from each set>" << std::endl;
	set.erase(2);
	set2.erase(3);
	set3.erase(4);
	set4.erase(5);
	
	display_set(out, set, "set: ");
	display_set(out, set2, "set2: ");
	display_set(out, set3, "set3: ");
	display_set(out, set4, "set4: ");

	out << "<Set set4.clear(), set3=set4>" << std::endl;
	set4.clear();
	set3 = set4;

	display_set(out, set3, "set3: ");
	display_set(out, set4, "set4: ");
	
	set3.insert(2);
	set3.insert(4);
	set3.insert(6);
	set4.insert(2);

	display_set(out, set3, "set3: ");
	display_set(out, set4, "set4: ");
}

void	test_iterator_set(std::ofstream &out)
{
	out << name << "iterator" << std::endl;

	ft::set<std::string> myset;

    myset.insert("eleven");
    myset.insert("ten");
    myset.insert("nine");
    myset.insert("eight");
    myset.insert("seven");
    myset.insert("six");
    myset.insert("five");
    myset.insert("four");
    myset.insert("three");
    myset.insert("two");
    myset.insert("one");

    ft::set<std::string>::iterator it = myset.begin();
    ft::set<std::string>::const_iterator cit = myset.begin();
    ft::set<std::string>::reverse_iterator rit = myset.rbegin();
    ft::set<std::string>::const_reverse_iterator rcit = myset.rbegin();

	ft::set<std::string>::iterator eit = --myset.end();
    ft::set<std::string>::const_iterator ecit = --myset.end();
    ft::set<std::string>::reverse_iterator erit = --myset.rend();
    ft::set<std::string>::const_reverse_iterator ercit = --myset.rend();

	out << "<set Iterator ++>" << std::endl;
    for (; it != myset.end(); it++) { out << *it << ", "; }
	out << std::endl;
	out << "<set Const Iterator++>" << std::endl;
    for (; cit != myset.end(); cit++) {out << *cit << ", ";}
		
	out << std::endl;
	out << "<set Reverse Iterator ++>" << std::endl;
    for (; rit != myset.rend(); rit++) {out << *rit << ", ";}
		
	out << std::endl;
	out << "<set Const Reverse Iterator ++>" << std::endl;
    for (; rcit != myset.rend(); rcit++) {out << *rcit << ", ";}
		
	out << std::endl;

	out << "<set Iterator -- >" << std::endl;
	for (; eit != myset.begin(); eit--){out << *eit << ", ";}
	out << std::endl;

	out << "<set Const Iterator -- >" << std::endl;
	for (; ecit != myset.begin(); ecit--){out << *ecit << ", ";}

	out << std::endl;
	out << "<set Reverse Iterator -- >" << std::endl;
	for (; erit != myset.rbegin(); erit--){out << *erit << ", ";}
		
	out << std::endl;
	out << "<set Const Reverse Iterator -- >" << std::endl;
	for (; ercit != myset.rbegin(); ercit--){out << *ercit << ", ";}
		
	out << std::endl;
}

void	test_set_capacity(std::ofstream &out)
{
	out << name << "capacity" << std::endl;

	ft::set<std::string> myset;

	myset.insert("eleven");
	myset.insert("ten");
	myset.insert("nine");
	myset.insert("eight");
	myset.insert("seven");
	myset.insert("six");
	myset.insert("five");
	myset.insert("four");
	myset.insert("three");
	myset.insert("two");
	myset.insert("one");

	out << "<set size>" << std::endl;
	out << myset.size() << std::endl;

	out << "<set max_size>" << std::endl;
	out << myset.max_size() << std::endl;

	out << "<set empty>" << std::endl;
	out << myset.empty() << std::endl;

	out << "<set clear>" << std::endl;
	myset.clear();
	out << myset.empty() << std::endl;
	out << myset.size() << std::endl;
}

void	test_set_insert(std::ofstream &out)
{
	out << name << "insert" << std::endl;

	ft::set<std::string> myset;
	myset.insert("eleven");
	display_set(out, myset, "set 11=eleven ");
	myset.insert("ten");
	display_set(out, myset, "set 11=ten ");
	myset.insert("NINE");
	display_set(out, myset, "set 11=nine ");

	ft::pair<ft::set<std::string>::iterator, bool> mypair = myset.insert("ten");
	out << *(mypair.first) << " " << *(mypair.first) << " " << mypair.second << std::endl;
	mypair = myset.insert("ten");
	out << *(mypair.first) << " " << *(mypair.first) << " " << mypair.second << std::endl;

	myset.insert("minus one");
	display_set(out, myset, "set -1=minus one ");

	myset.insert(myset.begin(), "twelve");
	display_set(out, myset, "set 12=twelve ");
	
	myset.insert(myset.begin(), "twelve");
	display_set(out, myset, "set 12=twelve ");

	myset.insert(++myset.begin(), "thirteen");
	display_set(out, myset, "set 13=thirteen ");
	
	myset.insert(++myset.begin(), "thirteen");
	display_set(out, myset, "set 13=thirteen ");

	myset.insert(--myset.end(), "fourteen");
	display_set(out, myset, "set 14=fourteen ");

	ft::set<std::string>::iterator it = myset.begin();
	for (int i = 0; i < 5; i++)
		it++;
	myset.insert(it, "fourteen");
	display_set(out, myset, "set 14=fourteen ");

	myset.insert(it, "quinze");
	display_set(out, myset, "set 15=quinze ");

	ft::set<std::string> myset2;
	myset2.insert(myset.begin(), myset.end());
	display_set(out, myset2, "set2 ");

	myset2.insert("scainque");
	display_set(out, myset2, "set2 5=scainque ");
	display_set(out, myset, "set ");

	ft::set<std::string> myset3;
	myset3.insert(myset.end(), myset.end());
	display_set(out, myset3, "set3 ");

	ft::set<std::string> myset4;
	myset4.insert(myset.begin(), myset.begin());
	display_set(out, myset4, "set4 ");

	ft::set<std::string> myset5;
	myset5.insert(myset.begin(), ++myset.begin());
	display_set(out, myset5, "set5 ");

	ft::set<std::string> myset6;
	myset6.insert(--myset.end(), myset.end());
	display_set(out, myset6, "set6 ");
}

void	test_set_erase(std::ofstream &out)
{
	out << name << "erase" << std::endl;

	ft::set<std::string> myset;
	myset.insert("one");
	myset.insert("two");
	myset.insert("three");
	myset.insert("four");
	myset.insert("five");
	myset.insert("six");
	myset.insert("seven");
	myset.insert("eight");
	myset.insert("nine");
	myset.insert("ten");
	myset.insert("eleven");
	myset.insert("twelve");
	myset.insert("thirteen");
	myset.insert("fourteen");
	myset.insert("fifteen");
	myset.insert("sixteen");
	myset.insert("seventeen");
	myset.insert("eighteen");
	myset.insert("nineteen");
	myset.insert("twenty");
	myset.insert("twenty oe");
	myset.insert("twenty to");
	myset.insert("twenty thre");
	myset.insert("twenty for");
	myset.insert("twenty fie");
	myset.insert("twenty sx");
	myset.insert("twenty sevn");
	myset.insert("twenty eigt");
	myset.insert("twenty nie");
	myset.insert("thirty");
	myset.insert("thirty oe");
	myset.insert("thirty to");
	
	display_set(out, myset, "myset contains");

	out << "<key erase>" << std::endl;

	out << myset.erase("one") << std::endl;
	display_set(out, myset, "myset erase 1");
	out << myset.erase("thirty oe") << std::endl;
	display_set(out, myset, "myset erase 31");
	out << myset.erase("sixteen") << std::endl;
	display_set(out, myset, "myset erase 16");
	out << myset.erase("thirty to") << std::endl;
	display_set(out, myset, "myset erase 32");
	out << myset.erase("fifteen") << std::endl;
	display_set(out, myset, "myset erase 15");
	out << myset.erase("seventeen") << std::endl;
	display_set(out, myset, "myset erase 17");
	out << myset.erase("seventeen") << std::endl;
	display_set(out, myset, "myset erase 17");


	out << "<iterator erase>" << std::endl;
	ft::set<std::string>::iterator it = myset.begin();
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	ft::set<std::string>::iterator it3 = it;
	it3++;
	myset.erase(myset.begin(), it);
	display_set(out, myset, "myset erase begin");
	ft::set<std::string>::iterator it2 = it3;
	it2++;
	myset.erase(it3);
	display_set(out, myset, "myset erase begin");
	it2++;
	it2++;
	myset.erase(it2);
	display_set(out, myset, "myset erase begin + 2");

	myset.erase(myset.begin(), myset.end());
	display_set(out, myset, "erase all");
}

void	test_set_insert_too_many(std::ofstream &out)
{
	out << name << "insert too many" << std::endl;
	
	ft::set<std::string> myset;

	for (int i = 0; i < 100000; i++)
		myset.insert("test");
	display_set(out, myset, "myset contains");
}

void	test_set_swap(std::ofstream &out)
{
	out << name << "swap" << std::endl;

	ft::set<std::string> myset;
	ft::set<std::string> myset2;

	myset.insert("one");
	myset.insert("two");
	myset.insert("three");
	myset.insert("four");

	myset2.insert("five");
	myset2.insert("six");
	myset2.insert("seven");
	myset2.insert("eight");

	display_set(out, myset, "myset contains");
	display_set(out, myset2, "myset2 contains");

	myset.swap(myset2);

	display_set(out, myset, "myset contains");
	display_set(out, myset2, "myset2 contains");
	
	ft::set<std::string> myset3;
	ft::set<std::string> myset4;

	myset3.insert("one");
	myset3.insert("two");
	myset3.insert("three");
	myset3.insert("four");

	myset4.insert("five");
	myset4.insert("six");
	myset4.insert("seven");
	myset4.insert("eight");

	display_set(out, myset3, "myset3 contains");
	display_set(out, myset4, "myset4 contains");

	swap(myset3, myset4);

	display_set(out, myset3, "myset3 contains");
	display_set(out, myset4, "myset4 contains");
}

void	test_set_comparison(std::ofstream &out)
{
	out << name << "comparison" << std::endl;

	ft::set<std::string> myset;
	ft::set<std::string> myset2;

	for (int i = 0; i < 20; i++)
	{
		myset.insert("test");
		myset2.insert("test");
	}

	out << "myset == myset2 : " << (myset == myset2) << std::endl;
	out << "myset != myset2 : " << (myset != myset2) << std::endl;
	out << "myset < myset2 : " << (myset < myset2) << std::endl;
	out << "myset <= myset2 : " << (myset <= myset2) << std::endl;
	out << "myset > myset2 : " << (myset > myset2) << std::endl;
	out << "myset >= myset2 : " << (myset >= myset2) << std::endl;

	myset2.insert("test");
	out << "<myset2 insert 20>" << std::endl;

	out << "myset == myset2 : " << (myset == myset2) << std::endl;
	out << "myset != myset2 : " << (myset != myset2) << std::endl;
	out << "myset < myset2 : " << (myset < myset2) << std::endl;
	out << "myset <= myset2 : " << (myset <= myset2) << std::endl;
	out << "myset > myset2 : " << (myset > myset2) << std::endl;
	out << "myset >= myset2 : " << (myset >= myset2) << std::endl;
}

void	test_set_find(std::ofstream &out)
{
	out << name << "find" << std::endl;

	ft::set<int> myset;

	for (int i = 0; i < 20; i++)
		myset.insert(i);

	ft::set<int>::iterator it = myset.find(10);
	out << "myset.find(10) : " << *it << std::endl;
	it = myset.find(30);
	//out << "myset.find(30) : " << *it << " " << it->second << std::endl;

	ft::set<int>::const_iterator it2 = myset.find(10);
	out << "myset.find(10) : " << *it2 << std::endl;
	it2 = myset.find(30);
	//out << "myset.find(30) : " << *it2 << " " << it2->second << std::endl;

	out << myset.count(10) << std::endl;
	out << myset.count(30) << std::endl;
}

void	test_set_bound(std::ofstream &out)
{
	out << name << "bound" << std::endl;

	ft::set<int> myset;

	for (int i = 0; i < 30;i+=3)
		myset.insert(i);

	const ft::set<int> myset2(myset);

	ft::set<int>::iterator it = myset.lower_bound(10);
	ft::set<int>::iterator dit = myset.upper_bound(10);
	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ret = myset.equal_range(10);

	out << "myset.lower_bound(10) : " << *it << std::endl;
	out << "myset.upper_bound(10) : " << *dit << std::endl;
	for (ft::set<int>::iterator it = ret.first; it != ret.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it = myset.lower_bound(11);
	dit = myset.upper_bound(11);
	ret = myset.equal_range(11);

	out << "myset.lower_bound(11) : " << *it << std::endl;
	out << "myset.upper_bound(11) : " << *dit << std::endl;
	for (ft::set<int>::iterator it = ret.first; it != ret.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it = myset.lower_bound(12);
	dit = myset.upper_bound(12);
	ret = myset.equal_range(12);

	out << "myset.lower_bound(12) : " << *it << std::endl;
	out << "myset.upper_bound(12) : " << *dit << std::endl;
	for (ft::set<int>::iterator it = ret.first; it != ret.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it = myset.lower_bound(13);
	dit = myset.upper_bound(13);
	ret = myset.equal_range(13);

	out << "myset.lower_bound(13) : " << *it << std::endl;
	out << "myset.upper_bound(13) : " << *dit << std::endl;
	for (ft::set<int>::iterator it = ret.first; it != ret.second; ++it)
		out << *it << std::endl;
	out << std::endl;
	
	

	
	ft::set<int>::const_iterator it2 = myset2.lower_bound(10);
	ft::set<int>::const_iterator dit2 = myset2.upper_bound(10);
	ft::pair<ft::set<int>::const_iterator, ft::set<int>::const_iterator> ret2 = myset2.equal_range(10);
	out << "myset2.lower_bound(10) : " << *it2 << std::endl;
	out << "myset2.upper_bound(10) : " << *dit2 << std::endl;
	for (ft::set<int>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it2 = myset2.lower_bound(11);
	dit2 = myset2.upper_bound(11);
	ret2 = myset2.equal_range(11);

	out << "myset2.lower_bound(11) : " << *it2 << std::endl;
	out << "myset2.upper_bound(11) : " << *dit2 << std::endl;
	for (ft::set<int>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it2 = myset2.lower_bound(12);
	dit2 = myset2.upper_bound(12);
	ret2 = myset2.equal_range(12);

	out << "myset2.lower_bound(12) : " << *it2 << std::endl;
	out << "myset2.upper_bound(12) : " << *dit2 << std::endl;
	for (ft::set<int>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it2 = myset2.lower_bound(13);
	dit2 = myset2.upper_bound(13);
	ret2 = myset2.equal_range(13);

	out << "myset2.lower_bound(13) : " << *it2 << std::endl;
	out << "myset2.upper_bound(13) : " << *dit2 << std::endl;
	for (ft::set<int>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << *it << std::endl;
	out << std::endl;

	it2 = myset2.lower_bound(27);
	ret2 = myset2.equal_range(27);

	out << "myset2.lower_bound(27) : " << *it2 << std::endl;
	for (ft::set<int>::const_iterator it = ret2.first; it != ret2.second; ++it)
		out << *it << std::endl;
	out << std::endl;
}

void	test_set(std::ofstream &out)
{
	out << name << "set" << std::endl;

		void	(*fonc[])(std::ofstream&) = {&test_constructor_set, &test_iterator_set, &test_set_capacity,
										&test_set_insert, &test_set_insert_too_many, &test_set_erase,
										&test_set_swap, &test_set_comparison, &test_set_find, &test_set_bound};
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