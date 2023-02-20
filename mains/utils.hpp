
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

#define RED(s) "\033[1;31m" s "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"
# define ITALIC_GREEN "\033[3;32m"
# define RESET "\033[m"
# define YELLOW "\033[1;33m"
# define BOLD "\e[1m"
# define ITALIC "\e[3m"

// #define YELLOW(s) "\033[1;33m" s "\033[m"
#define BLUE(s) "\033[1;34m" s "\033[m"
#define PURPLE(s) "\033[1;35m" s "\033[m"

#define nl() std::cout << std::endl;

void TITLE(std::string s)
{
	std::cout << std::endl;
	std::cout << ITALIC_GREEN << s << RESET << std::endl;
}
void RETURNS(std::string s)
{
	std::cout << BOLD << "Return value" << RESET << std::endl;
	std::cout << ITALIC << s << RESET << std::endl;
}

void WARNING(std::string s)
{
	std::cout << YELLOW << " \u26A0 " << s << RESET << std::endl;
}

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

