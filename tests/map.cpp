/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:16:05 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/15 12:55:49 by owalsh           ###   ########.fr       */
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
// int main ()
// {
//   ft::map<char,int> mymap;

//   mymap['x']=100;
//   mymap['y']=200;
//   mymap['z']=300;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   mymap.clear();
//   mymap['a']=1101;
//   mymap['b']=2202;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }


// int main()
// {
// 	ft::pair<int, std::string>			my_pair(8, "salut");
// 	ft::map<int, std::string>			test;
// 	ft::map<int, std::string>::iterator	it;

// 	test.insert(my_pair);
// 	test.insert(ft::pair<int, std::string>(-4, "bar"));
// 	test.insert(ft::pair<int, std::string>(2, "machin"));
// 	test.insert(ft::pair<int, std::string>(3, "foo"));
// 	test.insert(ft::pair<int, std::string>(746, "Marcel"));
// 	test.insert(ft::pair<int, std::string>(1, "truc"));
// 	it = test.begin();
// 	std::cout << '\n';

// 	while (it != test.end())
// 	{
// 		// cout << "start of while\n";
// 		std::cout << it->first << ", " << it->second << '\n';
// 		it++;
// // 		cout << "iterator incremented\n";

// // #ifndef STD
// // 		cout << it.getPointer() << '\n';
// // 		cout << test.end().getPointer() << '\n';
// // #endif

// 	}
// 	std::cout << "End of display loop\n";
// }


int main ()
{
	ft::map<char,int> mymap;


	if (mymap.begin() != mymap.end())
		std::cout << "This should not happen\n";

	std::cout << "first insert\n";

	mymap['b'] = 100;
	std::cout << "second insert\n";

	mymap['a'] = 200;
	mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		std::cout << "This is wrong\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "Hello there\n";
	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
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
