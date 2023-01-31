/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/01/31 19:16:30 by owalsh           ###   ########.fr       */
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

    vec2.insert(vec2.begin(), vec.begin()+3, vec.end());

    ft::vector<int>::iterator    it2;
    
	std::cout << "printing vec2" << std::endl;
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
            std::cout << *it2 << " ";
    
    std::cout << std::endl;

	std::cout << "testing push back" << std::endl;
	

	vec2.push_back(7);
	vec2.push_back(882);
	vec2.erase(vec2.end() -1);
	std::cout << "printing vec2" << std::endl;
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
            std::cout << *it2 << " ";
    
    std::cout << std::endl;

	std::cout << "testing erase range with vec" << std::endl;

	vec.erase(vec.begin() + 1, vec.end() - 2);
	std::cout << "printing vec" << std::endl;
    for(it = vec.begin(); it != vec.end(); ++it)
    	std::cout << *it << " ";
    
    std::cout << std::endl;

	std::cout << "testing swap function" << std::endl;
	vec.swap(vec2);
	std::cout << "printing vec" << std::endl;
	 for(it = vec.begin(); it != vec.end(); ++it)
    	std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << "printing vec2" << std::endl;
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
            std::cout << *it2 << " ";
	return 0;
}
