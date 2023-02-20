

#if REAL
	#include <map>
	#include <vector>
	#include <set>
	#include <stack>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "vector.hpp"
	#include "set.hpp"
	#include "stack.hpp"
#endif

#include <iostream>

#define _pair namespace::pair

// #define RED(s) "\033[1;31m" s "\033[m"
#define GREEN(s) "\033[1;32m" s "\033[m"
#define TITLE(s) "\033[3;32m" s "\033[m"

#define nl() std::cout << std::endl;


template <typename T>
void	print(T container)
{
	if (container.empty())
	{
		std::cout << "container is empty" << std::endl;
		return ;
	}
	std::cout << "container size: " << container.size() << std::endl;
	std::cout << "container values: ";
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	nl();
}

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

