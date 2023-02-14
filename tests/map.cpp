/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:16:05 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/13 16:12:52 by owalsh           ###   ########.fr       */
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
	// first insert function version (single parameter):
	if (mymap.empty())
		std::cout << "Map is still empty"<< std::endl;
	else
		std::cout << "Map is not empty"<< std::endl;
		
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );
	// print(mymap);
	if (mymap.empty())
		std::cout << "Map is still empty"<< std::endl;
	else
		std::cout << "Map is not empty"<< std::endl;
		
	return 0;
}

