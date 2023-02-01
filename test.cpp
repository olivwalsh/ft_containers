/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/01 16:18:39 by owalsh           ###   ########.fr       */
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
    ft::vector<int>::reverse_iterator    rit;

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

	// std::cout << "testing swap function" << std::endl;
	// vec.swap(vec2);
	// std::cout << "printing vec" << std::endl;
	//  for(it = vec.begin(); it != vec.end(); ++it)
    // 	std::cout << *it << " ";
    // std::cout << std::endl;
	// std::cout << "printing vec2" << std::endl;
    // for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
    //         std::cout << *it2 << " ";

	//  std::cout << std::endl;
	// std::cout << "printing vec2" << std::endl;
    // for(rit = vec2.rbegin(); rit != vec2.rend(); ++rit)
    //         std::cout << *rit << " ";
	
	ft::vector<int> vec_test;
	(void)vec_test;
	
	std::cout << "testing assign function" << std::endl;
	vec.assign(vec2.begin(), vec2.end());
	std::cout << "printing vec" << std::endl;
	 for(it = vec.begin(); it != vec.end(); ++it)
    	std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << "printing vec2" << std::endl;
    for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
            std::cout << *it2 << " ";
    std::cout << std::endl;
			
	std::cout << "testing if vec == vec2" << std::endl;
	if (vec == vec2)
		std::cout << "vec and vec2 are the same" << std::endl;
	else
		std::cout << "vec and vec2 are different bitch" << std::endl;
	

			
	return 0;
}
