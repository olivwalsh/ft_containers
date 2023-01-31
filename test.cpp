/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/30 19:02:15 by owalsh           ###   ########.fr       */
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
	ft::vector<int>    vec(3, 2);
    
    if (vec.empty())
        std::cout << "is empty" << std::endl;
        
    ft::vector<int>::iterator    it;

	std::cout << "printing vec" << std::endl;
    for(it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        
    std::cout << std::endl;

    vec.insert(vec.begin(), 3, 6);
	std::cout << "printing vec" << std::endl;
    for(it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        
    std::cout << std::endl;

    ft::vector<int>    vec2;

    vec2.insert(vec2.begin(), vec.begin(), vec.begin() + 4);

    ft::vector<int>::iterator    it2;
    
	std::cout << "printing vec2" << std::endl;
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
            std::cout << *it2 << " ";
    
    std::cout << std::endl;


	return 0;
}
