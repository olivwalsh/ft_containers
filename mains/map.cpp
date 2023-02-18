/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft::ft::map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:16:05 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/15 16:06:04 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if REAL
	#include <ft::ft::map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

#include "utils.cpp"
#include <list>

template <class Key, class T>
void print(ft::map<Key, T>& lst)
{
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	ft::map<int,int> mymap;
	ft::map<int,int>::iterator it;

	// insert some values:
	mymap[3]=10;
	mymap[1]=20;
	mymap[5]=30;
	mymap[7]=40;
	// mymap['e']=50;
	// mymap['f']=60;

	mymap.print();
	// it=mymap.find('b');
	// mymap.erase (it);                   // erasing by iterator
	// std::cout << "erase iterator to b\n";
	// mymap.print();

	// mymap.erase ('c');                  // erasing by key
	// std::cout << "erase by key 'c'\n";
	// mymap.print();

	// it=mymap.find ('e');
	// std::cout << "erase by range 'e' to end\n";
	// mymap.erase ( it, mymap.end() );    // erasing by range
	// mymap.print();

	// std::cout << " display :\n";
	// // show content:
	// for (it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

  return 0;
}