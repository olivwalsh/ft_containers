/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/30 16:22:57 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if REAL
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif


int main()
{
	ft::vector<int> vec;

	if (vec.empty())
		std::cout << "Before insert, vec is empty" << std::endl;
	vec.insert(vec.begin(), 3, 2);
								  
	if (vec.empty())
		std::cout << "After insert, vec is still empty" << std::endl;
	
	ft::vector<int>::iterator it;
	

	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	vec.insert(vec.begin(), 2, 6);

	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";

	vec.clear();

	return 0;
}
