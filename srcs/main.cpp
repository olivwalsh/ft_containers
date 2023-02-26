/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:18:05 by lgiband           #+#    #+#             */
/*   Updated: 2023/02/26 15:45:30 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <unistd.h>

#if NAMESPACE == 0
	namespace ft = std;
	#include <stack>
	std::string	name = "std_";
#else
	std::string	name = "ft_";
	#include "stack.hpp"
#endif


void	take_time(std::ofstream& out)
{
	out << name << "take_time" << std::endl;

	usleep(1000000);
}

void	time_test(void f(std::ofstream &), std::ofstream& out)
{
	clock_t start = clock();
	f(out);
	clock_t end = clock();
	out << std::fixed << "Time: " << (end - start) / ((double)CLOCKS_PER_SEC / (70 / 3)) << std::endl;
}

std::string	progressBar(long unsigned int value, long unsigned int max_value, long unsigned int size_max, char c)
{
	std::string	s;

	if (value == max_value)
		s = std::string(size_max, c);
	else
		s = std::string(value * size_max / max_value, c) + std::string(size_max - value * size_max / max_value, ' ');
	return (s);
}

int	main(void)
{
	std::ofstream	out;
	std::string		path = "test/" + name + "test"; 
	
	void	(*fonc[])(std::ofstream&) = {&stack_test_with_vector, &stack_test_with_deque,
	 									&reverse_iterator_test,
	 									&test_equal, &test_lexicographical_compare, &test_pair, &test_vector, &test_map, &test_set};


	// &test_is_integral &test_enable_if need to use c++11

	out.open(path.c_str());

	if (!out.is_open())
	{
		std::cerr << "Fail to open file" << std::endl;
		return (0);
	}
	

	for (long unsigned int i = 0; i < sizeof(fonc) / sizeof(fonc[0]); i++)
	{
		std::cout  << "\33[2K\r" << "\033[0;32m"
			<< "[" << progressBar(i, sizeof(fonc) / sizeof(fonc[0]), 100, '=') << "]  "
			<< i << "/" << sizeof(fonc) / sizeof(fonc[0]) << "\033[0m"
			<< std::flush;
		time_test(fonc[i], out);
	}
	std::cout  << "\33[2K\r" << "\033[0;32m"
			<< "[" << progressBar(sizeof(fonc) / sizeof(fonc[0]), sizeof(fonc) / sizeof(fonc[0]), 100, '=') << "]  "
			<< sizeof(fonc) / sizeof(fonc[0]) << "/" << sizeof(fonc) / sizeof(fonc[0]) << "\033[0m"
			<< std::endl;
	out.close();

}