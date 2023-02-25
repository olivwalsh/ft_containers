/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:43:56 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/25 14:33:23 by owalsh           ###   ########.fr       */
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

	 
	ft::set<int> const st;
	ft::set<int>::iterator it = st.begin(); 
	// <-- no error, actually ! set allows for const_iterator => iterator conversion

	(void)it;
	
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

