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
	if (lst.empty())
	{
		std::cout << "map is empty" << std::endl;
		return ;
	}
	std::cout << "map size: " << lst.size() << std::endl;
	std::cout << "map values:\n";
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

void test_map()
{
	std::cout << std::endl;
	std::cout << PURPLE("***** TESTING MAP *****") << std::endl;


	ft::map<int, std::string> mp;
    ft::map<int, std::string>::iterator it = mp.begin();
    ft::map<int, std::string>::const_iterator cit = mp.begin();
    
    if (it == cit)
        std::cout << "iterator and const iterator are comparable in map!!" << std::endl;
    else
        std::cout << "fail..." << std::endl;

// 	TITLE("--> Testing default constructor and insert with 3 values");
	
// // Testing default constructor
// 	ft::map<int, std::string> mp;

// 	SUBTITLE("Map : ");
// 	ft::map<int, std::string> my_map;
// 	my_map.insert(ft::make_pair(1, "one"));
// 	my_map.insert(ft::make_pair(2, "two"));
// 	my_map.insert(ft::make_pair(3, "three"));
// 	my_map.insert(ft::make_pair(4, "one"));
// 	my_map.insert(ft::make_pair(5, "two"));
// 	my_map.insert(ft::make_pair(6, "three"));
// 	my_map.insert(ft::make_pair(7, "one"));
// 	my_map.insert(ft::make_pair(8, "two"));
// 	my_map.insert(ft::make_pair(9, "three"));
// 	my_map.insert(ft::make_pair(10, "one"));
// 	my_map.insert(ft::make_pair(11, "two"));
// 	my_map.insert(ft::make_pair(12, "three"));
// 	my_map.insert(ft::make_pair(13, "one"));
// 	my_map.insert(ft::make_pair(14, "two"));
// 	my_map.insert(ft::make_pair(15, "three"));
// 	print(my_map);
	
// 	// my_map.print();

// 	TITLE("Testing operator=\n-> creating my_other_map, map<int, string> and assigning it my_map");
// 	// Testing operator=
// 	ft::map<int, std::string> my_other_map;
// 	my_other_map = my_map;
// 	print(my_other_map);

// 	// Testing get_allocator
// 	std::allocator<ft::pair<const int, std::string> > my_allocator = my_map.get_allocator();
// 	(void)my_allocator;

// 	TITLE("Testing at\n-> my_map.at(1)");
// 	// Testing at
// 	std::cout << my_map.at(1) << std::endl;

// 	TITLE("Testing operator[]\n-> my_map[2]");
// 	// Testing operator[]
// 	std::cout << my_map[2] << std::endl;

// 	TITLE("Testing begin and end.\n-> printing my_map with for loop until begin() == end()");
// 	// Testing begin and end
// 	for (ft::map<int, std::string>::iterator it = my_map.begin(); it != my_map.end(); ++it)
// 		std::cout << it->first << ": " << it->second << std::endl;

// 	TITLE("Testing rbegin and rend.\n-> printing my_map with for loop until rbegin() == rend()");
// 	// Testing rbegin and rend
// 	for (ft::map<int, std::string>::reverse_iterator it = my_map.rbegin(); it != my_map.rend(); ++it) {
// 		std::cout << it->first << ": " << it->second << std::endl;
// 	}

// 	TITLE("Testing capacity empty and size");
// 	// Testing capacity, empty, and size
// 	std::cout << "Capacity: " << my_map.size() << std::endl;
// 	std::cout << "Empty: " << my_map.empty() << std::endl;
// 	std::cout << "Size: " << my_map.size() << std::endl;

// 	TITLE("Testing max_size");
// 	// Testing max_size
// 	std::cout << "Max size: " << my_map.max_size() << std::endl;
// 	WARNING("max_size may differ between ft_containers and std containers!");

// 	// Testing clear
// 	TITLE("Testing clear");
// 	my_map.clear();
// 	print(my_map);

// 	// Testing insert with value
// 	TITLE("Testing insert with value");
// 	my_map.insert(ft::make_pair(1, "one"));
// 	my_map.insert(ft::make_pair(2, "two"));
// 	my_map.insert(ft::make_pair(3, "three"));
// 	print(my_map);


// 	// Testing insert with range
// 	TITLE("Testing insert with iterator range");
// 	ft::map<int, std::string> another_map;
// 	another_map.insert(ft::make_pair(4, "four"));
// 	another_map.insert(ft::make_pair(5, "five"));
// 	another_map.insert(ft::make_pair(6, "six"));
// 	my_map.insert(another_map.begin(), another_map.end());
// 	print(my_map);

// 	// my_map.print();

// 	// Testing erase with key
// 	TITLE("Testing erase with key\n-> erasing 2");
// 	my_map.erase(2);
// 	print(my_map);

// 	// my_map.print();

// 	// Testing erase with iterator
// 	TITLE("Testing erase with iterator\n-> erasing 3");
// 	ft::map<int, std::string>::iterator it = my_map.find(3);
// 	my_map.erase(it);
// 	print(my_map);

// 	// my_map.print();

// 	TITLE("Testing swap\n-> swap my_map with another_map");
// 	std::cout << "my_map before swap:" << std::endl;
// 	print(my_map);
// 	std::cout << "another_map before swap:" << std::endl;
// 	print(another_map);

// 	// Testing swap
// 	my_map.swap(another_map);

// 	std::cout << "my_map after swap:" << std::endl;
// 	print(my_map);
// 	std::cout << "another_map after swap:" << std::endl;
// 	print(another_map);

// 	// Testing count
// 	TITLE("Testing count\n-> returns the number of element matching key 4 (it is either 1 or 0)");
// 	std::cout << "Count of key 4: " << my_map.count(4) << std::endl;
// 	TITLE("Testing count\n-> erasing 4 and now checking the number of element matching key 4");
// 	my_map.erase(4);
// 	print(my_map);
// 	std::cout << "Count of key 4: " << my_map.count(4) << std::endl;

// 	// Testing find
// 	TITLE("Testing find\n-> searching for key 4");
// 	ft::map<int, std::string>::iterator found = my_map.find(4);
// 	if (found != my_map.end())
// 		std::cout << "Found " << found->first << ": " << found->second << std::endl;
// 	else
// 		std::cout << "Not found" << std::endl;
// 	SUBTITLE("-> searching for key 6");
// 	found = my_map.find(6);
// 	if (found != my_map.end())
// 		std::cout << "Found " << found->first << ": " << found->second << std::endl;
// 	else
// 		std::cout << "Not found" << std::endl;

// 	 // Testing equal_range
// 	TITLE("Testing equal_range\n-> searching for key 4");
// 	RETURNS("std::pair containing a pair of iterators defining the wanted range: \
// 			 the first pointing to the first element that is not less than key and the second pointing to the first element greater than key.");
// 	ft::map<int, std::string>::iterator it_low;
// 	ft::map<int, std::string>::iterator it_high;
// 	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ret;

// 	my_map.insert(ft::make_pair(4, "four"));
// 	ret = my_map.equal_range(4);

// 	it_low = ret.first;
// 	it_high = ret.second;

// 	std::cout << "\tfirst element that is not less than key = " << it_low->first << std::endl;
// 	std::cout << "\tfirst element greater than key = " << it_high->first << std::endl;

// 	// my_map.print();

	

// 	// Testing lower_bound
// 	TITLE("Testing lower_bound\n-> searching for lower bound of key 4");
// 	ft::map<int, std::string>::iterator low = my_map.lower_bound(4);
// 	std::cout << "Lower bound of 4: " << low->first << ": " << low->second << std::endl;

// 	// Testing upper_bound
// 	TITLE("Testing upper_bound\n-> searching for upper_bound of key 4");
// 	ft::map<int, std::string>::iterator up = my_map.upper_bound(4);
// 	std::cout << "Upper bound of 4: " << up->first << ": " << up->second << std::endl;

// 	// Testing key_comp
// 	TITLE("Testing key_comp\n->key_comp(3, 4)");
// 	RETURNS("Returns the function object that compares the keys, which is a copy of this container's constructor argument comp. Default is std::less");
// 	ft::map<int, std::string>::key_compare my_key_comp = my_map.key_comp();
// 	std::cout << my_key_comp(3, 4) << std::endl;
// 	TITLE("Testing key_comp\n->key_comp(5, 4)");
// 	std::cout << my_key_comp(5, 4) << std::endl;

// 	// Testing value_comp
// 	// ft::map<int, std::string>::value_compare my_value_comp = my_map.value_comp();
// 	// std::cout << my_value_comp(std::make_pair(2, "two"), std::make_pair(1, "one")) << std::endl;


// 	ft::map<int, int> map1;
//     ft::map<int, int> map2;

// 	TITLE("Testing map non-member functions\n->creating map1 and map2");

//     // insert some values
//     map1.insert(ft::make_pair(1, 10));
//     map1.insert(ft::make_pair(2, 20));
//     map1.insert(ft::make_pair(3, 30));

//     map2.insert(ft::make_pair(1, 10));
//     map2.insert(ft::make_pair(2, 20));
//     map2.insert(ft::make_pair(4, 40));

// 	std::cout << "map 1:\n" << std::endl;
// 	print(map1);

// 	std::cout << "map 2:\n" << std::endl;
// 	print(map2);

// 	TITLE("Testing == operator\n-> map1 == map2 ?");

//     // test == operator
//     if (map1 == map2)
// 		std::cout << "map1 and map2 are equal" << std::endl;
// 	else
// 		std::cout << "map1 and map2 are not equal" << std::endl;
		
// 	TITLE("Testing != operator\n-> map1 != map2 ?");

//     // test != operator
//     if (map1 != map2)
// 		std::cout << "map1 and map2 are not equal" << std::endl;
//     else
// 		std::cout << "map1 and map2 are equal" << std::endl;
		
// 	TITLE("Testing < operator\n-> map1 < map2 ?");

// 	// test < operator
//     if (map1 < map2)
// 		std::cout << "map1 is less than map2" << std::endl;
// 	else
// 		std::cout << "map1 is not less than map2" << std::endl;
	
// 	TITLE("Testing <= operator\n-> map1 <= map2 ?");

//     // test <= operator
//     if (map1 <= map2)
// 		std::cout << "map1 is less than or equal to map2" << std::endl;
// 	else
// 		std::cout << "map1 is not less than or equal to map2" << std::endl;

// 	TITLE("Testing > operator\n-> map1 > map2 ?");

//     // test > operator
//     if (map1 > map2)
// 		std::cout << "map1 is greater than map2" << std::endl;
// 	else
// 		std::cout << "map1 is not greater than map2" << std::endl;
		
// 	TITLE("Testing >= operator\n-> map1 >= map2 ?");

// 	// test >= operator
//     if (map1 >= map2)
// 		std::cout << "map1 is greater than or equal to map2" << std::endl;
// 	else
// 		std::cout << "map1 is not greater than or equal to map2" << std::endl;
		
// 	TITLE("Testing non member swap function\n-> map1 == map2 ?");

//     // test swap function
//     std::cout << "map1 before swap:" << std::endl;
//     print(map1);
// 	nl();
//     std::cout << "map2 before swap:" << std::endl;
//     print(map2);
// 	nl();

//     std::swap(map1, map2);

//     std::cout << "map1 after swap:" << std::endl;
//     print(map1);
// 	nl();
//     std::cout << "map2 after swap:" << std::endl;
//     print(map2);
// 	nl();

}
