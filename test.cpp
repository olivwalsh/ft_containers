/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/27 18:13:13 by owalsh           ###   ########.fr       */
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

// template <typename T>
// typename ft::enable_if<ft::is_integral<T>::value, T>::type add(T a, T b)
// {
//     return a + b;
// }

// template <typename T>
// typename ft::enable_if<!ft::is_integral<T>::value, T>::type add(T a, T b)
// {
// 	(void)a;
// 	(void)b;
//     std::cout << "This function is only available for integral types." << std::endl;
//     return T();
// }

int main()
{
	ft::vector<int> vec;

	if (vec.empty())
		std::cout << "Before insert, vec is empty" << std::endl;
	vec.insert(vec.begin(), 3, 2);
								  
	if (vec.empty())
		std::cout << "After insert, vec is still empty" << std::endl;
	
	ft::vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";

	return 0;
}
