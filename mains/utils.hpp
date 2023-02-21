/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:10:12 by foctavia          #+#    #+#             */
/*   Updated: 2023/02/21 14:06:21 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if REAL
	#include <map>
	#include <vector>
	#include <set>
	#include <stack>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "vector.hpp"
	#include "set.hpp"
	#include "stack.hpp"
#endif

#include <iostream>
#include <sys/time.h>

#define _pair namespace::pair

#define RED(s) "\033[1;31m" s "\033[m"
#define GREEN(s) "\033[1;32m" s "\033[m"
#define YELLOW(s) "\033[1;33m" s "\033[m"
#define BLUE(s) "\033[1;34m" s "\033[m"
#define PURPLE(s) "\033[1;35m" s "\033[m"
#define GREEN_ "\033[1;32m"
#define ITALIC_GREEN_ "\033[3;32m"
#define YELLOW_ "\033[1;33m"
#define BLUE_ "\033[1;34m"
#define PURPLE_ "\033[1;35m"
#define BOLD_ "\e[1m"
#define ITALIC_ "\e[3m"
#define RESET_ "\033[m"

#define nl() std::cout << std::endl;


void	MAINTITLE(std::string s);
void	TITLE(std::string s);
void	SUBTITLE(std::string s);
void	RETURNS(std::string s);
void	WARNING(std::string s);

void	test_vector( void );
void	test_map( void );
void	test_stack( void );
void	test_set( void );
void	check_performance(std::string container, struct timeval start);

template< typename T >
void	print( T &vector )
{
	std::cout << "size : " << vector.size() << "  capacity : " << vector.capacity() << std::endl;
	
	if (vector.empty())
		std::cout << "Vector is empty" << std::endl << std::endl;
	else
	{
		std::cout << "content : ";
		for (size_t i = 0; i < vector.size(); ++i)
			std::cout << vector[i] << " ";
			
		std::cout << std::endl << std::endl;
	}
}

template< class Key >
void	printSet(ft::set< Key > &st)
{
	std::cout << "size : " << st.size() << std::endl;
	
	if (st.empty())
		std::cout << "Set is empty" << std::endl << std::endl;
	else
	{	
		std::cout << "content :" << std::endl;
		for (typename ft::set< Key >::iterator it = st.begin(); it != st.end(); it++)
			std::cout << *it << "  ";
		std::cout << std::endl << std::endl;
	}
}
