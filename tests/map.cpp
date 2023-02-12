/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:16:05 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/12 17:54:05 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if REAL
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

#include "utils.cpp"

int main()
{
	std::cout << "testing map" << std::endl;
	ft::map<std::string, int> m;
	return 0;
}
