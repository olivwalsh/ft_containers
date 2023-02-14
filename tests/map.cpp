/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:16:05 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/14 16:01:42 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if REAL
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

#include "utils.cpp"

template <class Key, class T>
void print(ft::map<Key, T>& lst)
{
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	ft::map<char,int> mymap;


	if (mymap.begin() != mymap.end())
		std::cout << "This should not happen\n";
		
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		std::cout << "This is wrong\n";
  // show content:
  	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "Hello there\n";
	for (ft::map<char,int>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout << "General Kenobi\n";

	ft::map<char, int>::const_iterator it = mymap.begin();
	ft::map<char, int>::const_iterator ti = mymap.end();
	std::cout << "Wupwup\n";

	it++;
	++it;
	it--;
	--it;
	std::cout << "marker1\n";

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	std::cout << "Trump is a kiddo\n";
	ft::map<char, int>::iterator end = mymap.end();
	while(it != end)
	{
    	std::cout << it->first << " => " << it->second << '\n';
		it++;
	}

	return 0;
}

