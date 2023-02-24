/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:43:56 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/24 09:52:24 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/*
	For make diff with std, comment checkPerformance
	For make performance, uncomment checkPerformance
*/
	
int main( void )
{
	struct timeval	start;
	
	gettimeofday(&start, NULL);
	test_vector();
	check_performance("vector : ", start);
	
	gettimeofday(&start, NULL);
	test_stack();
	check_performance("stack : ", start);

	gettimeofday(&start, NULL);
	test_map();
	check_performance("map : ", start);

	gettimeofday(&start, NULL);
	test_set();
	check_performance("set : ", start);
	
    return 0;
}

