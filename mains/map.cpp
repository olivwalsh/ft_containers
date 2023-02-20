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

#include "utils.hpp"

template <class Key, class T>
void print(ft::map<Key, T>& lst)
{
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main() {
	// Testing constructor
	ft::map<int, std::string> my_map;
	my_map.insert(ft::make_pair(1, "one"));
	my_map.insert(ft::make_pair(2, "two"));
	my_map.insert(ft::make_pair(3, "three"));

	// Testing operator=
	ft::map<int, std::string> my_other_map;
	my_other_map = my_map;

	// Testing get_allocator
	std::allocator<ft::pair<const int, std::string> > my_allocator = my_map.get_allocator();
	// ft::map<int, std::string> my_third_map(my_allocator);

	// Testing at
	std::cout << my_map.at(1) << std::endl;

	// Testing operator[]
	std::cout << my_map[2] << std::endl;

	// Testing begin and end
	for (ft::map<int, std::string>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << ": " << it->second << std::endl;

	// Testing rbegin and rend
	for (ft::map<int, std::string>::reverse_iterator it = my_map.rbegin(); it != my_map.rend(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	// Testing capacity, empty, and size
	std::cout << "Capacity: " << my_map.size() << std::endl;
	std::cout << "Empty: " << my_map.empty() << std::endl;
	std::cout << "Size: " << my_map.size() << std::endl;

	// // Testing max_size
	// std::cout << "Max size: " << my_map.max_size() << std::endl;

	// // Testing clear
	// my_map.clear();

	// // Testing insert with value
	// my_map.insert(ft::make_pair(1, "one"));
	// my_map.insert(ft::make_pair(2, "two"));
	// my_map.insert(ft::make_pair(3, "three"));

	// // Testing insert with range
	// ft::map<int, std::string> another_map;
	// another_map.insert(ft::make_pair(4, "four"));
	// another_map.insert(ft::make_pair(5, "five"));
	// another_map.insert(ft::make_pair(6, "six"));
	// my_map.insert(another_map.begin(), another_map.end());

	// // Testing erase with key
	// my_map.erase(2);

	// // Testing erase with iterator
	// ft::map<int, std::string>::iterator it = my_map.find(3);
	// my_map.erase(it);

	// // Testing swap
	// my_map.swap(another_map);

	// // Testing count
	// std::cout << "Count of key 4: " << my_map.count(4) << std::endl;

	// // Testing find
	// ft::map<int, std::string>::iterator found = my_map.find(4);
	// if (found != my_map.end())
	// 	std::cout << "Found " << found->first << ": " << found->second << std::endl;
	// else
	// 	std::cout << "Not found" << std::endl;

	//  // Testing equal_range
	// ft::pair<ft::map<int, stdstring>::iterator it_low, it_high;
	// ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ret;

	// ret = my_map.equal_range(4);
	// it_low = ret.first;
	// it_high = ret.second;

	// for (ft::map<int, std::string>::iterator it = it_low; it != it_high; ++it)
	// 	std::cout << it->first << ": " << it->second << std::endl;

	// // Testing lower_bound
	// ft::map<int, std::string>::iterator low = my_map.lower_bound(4);
	// std::cout << "Lower bound of 4: " << low->first << ": " << low->second << std::endl;

	// // Testing upper_bound
	// ft::map<int, std::string>::iterator up = my_map.upper_bound(4);
	// std::cout << "Upper bound of 4: " << up->first << ": " << up->second << std::endl;

	// // Testing key_comp
	// ft::map<int, std::string>::key_compare my_key_comp = my_map.key_comp();
	// std::cout << my_key_comp(3, 4) << std::endl;

	// // Testing value_comp
	// ft::map<int, std::string>::value_compare my_value_comp = my_map.value_comp();
	// std::cout << my_value_comp(std::make_pair(2, "two"), std::make_pair(1, "one")) << std::endl;

	return 0;
}
