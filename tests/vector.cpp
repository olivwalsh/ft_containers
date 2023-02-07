/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/07 11:24:46 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if REAL
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#include "utils.cpp"

int main()
{
	std::cout << GREEN("Testing container: vector") << std::endl;
	nl();
	std::cout << TITLE("vector: constructor") << std::endl;
	ft::vector<int> test;
	std::cout << TITLE("- default constructor") << std::endl;
	print(test);
	std::cout << GREEN("OK") << std::endl;
	std::cout << TITLE("- constructs an empty container with the given allocator alloc") << std::endl;
	std::cout << RED("KO") << std::endl;
	std::cout << TITLE("- constructs the container with count copies of elements with value value") << std::endl;
	ft::vector<int> test2(4, 12);
	print(test2);
	std::cout << GREEN("OK") << std::endl;
	std::cout << TITLE("- constructs the container with the contents of the range [first, last)") << std::endl;
	// for this test we need to use iterator.
	ft::vector<int>::iterator it = test2.begin();
	ft::vector<int> test3(it, it + 2);
	print(test3);
	std::cout << GREEN("OK - correct iterator range") << std::endl;
	try
	{
		ft::vector<int> test4(it, test.begin());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << GREEN("OK - wrong iterator range") << std::endl;
	}
	std::cout << TITLE("- copy constructor. Constructs the container with the copy of the contents of other.") << std::endl;
	ft::vector<int> test5(test2);
	print(test5);
	std::cout << GREEN("OK") << std::endl;
	
	return 0;
}
