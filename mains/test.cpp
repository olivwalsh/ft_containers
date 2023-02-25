/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:43:56 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/25 10:26:40 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/*
	For make diff with std, comment checkPerformance
	For make performance, uncomment checkPerformance
*/
	
int main( void )
{
	// struct timeval	start;
	
	// gettimeofday(&start, NULL);
	// test_vector();
	// check_performance("vector : ", start);

	 
	ft::set<int> myset;

  	for (int i=1; i<=5; i++)
		myset.insert(i*10);   // myset: 10 20 30 40 50

	ft::pair<ft::set<int>::const_iterator, ft::set<int>::const_iterator> ret;
	// ret = myset.equal_range(30); /// --> this doesnt work.

	ft::set<int>::const_iterator lit = myset.lower_bound(30);
	ft::set<int>::const_iterator uit = myset.upper_bound(30);
	ret = ft::make_pair(lit, uit); // making a pair of 2 const works

	// ret = ft::make_pair(myset.lower_bound(30), myset.upper_bound(30));
	
	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
	
	// ft::set<int>::iterator it = myset.begin();
	// std::cout << "set begin " << *it << std::endl;
	// std::cout << "set cbegin " << *cit << std::endl;
	// if (it == cit)
	// 	std::cout << "set can compare a const and non const iterator!" << std::endl;


	
	// gettimeofday(&start, NULL);
	// test_stack();
	// check_performance("stack : ", start);

	// gettimeofday(&start, NULL);
	// test_map();
	// check_performance("map : ", start);

	// gettimeofday(&start, NULL);
	// test_set();
	// check_performance("set : ", start);
	
    return 0;
}

