/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:23:31 by lgiband           #+#    #+#             */
/*   Updated: 2023/01/19 13:26:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <fstream>

#include <map>
#include <stack>
#include <vector>

#if NAMESPACE == 0
	namespace ft = std;
#else
	#include "stack.hpp"
#endif

#include "utils.hpp"

extern std::string name;

void	stack_test_with_vector(std::ofstream &out)
{
	out << name << "stack_vector\n";
	ft::stack<int> ft_stack;

	out << "Stack empty: " << ft_stack.empty() << std::endl;

	out << "\n<Set Stack>" << std::endl;
	
	ft_stack.push(1);
	ft_stack.push(2);
	ft_stack.push(3);
	ft_stack.push(4);

	out << "Stack no-empty: " << ft_stack.empty() << std::endl;
	out << "Stack top: " << ft_stack.top() << std::endl;
	out << "Stack size: " << ft_stack.size() << std::endl;
	
	out << "\n<Pop one element>" << std::endl;
	ft_stack.pop();

	out << "Stack top: " << ft_stack.top() << std::endl;
	out << "Stack size: " << ft_stack.size() << std::endl;

	out << "\n<Operator Test>" << std::endl;
	
	ft::stack<int> ft_stack2 = ft_stack;
	out << "Operator =: " << ft_stack2.top() << " " << ft_stack2.size() << std::endl;
	out << "Operator ==: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator !=: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator >: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator =>: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <=: " << (ft_stack == ft_stack2) << std::endl;

	out << "\n<Add one elem>" << std::endl;
	ft_stack2.push(5);

	out << "Operator =: " << ft_stack2.top() << " " << ft_stack2.size() << std::endl;
	out << "Operator ==: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator !=: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator >: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator =>: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <=: " << (ft_stack == ft_stack2) << std::endl;
}

void	stack_test_with_deque(std::ofstream &out)
{
	out << name << "stack_deque\n";
	ft::stack<int, std::deque<int> > ft_stack;

	out << "Stack empty: " << ft_stack.empty() << std::endl;

	out << "\n<Set Stack>" << std::endl;
	
	ft_stack.push(1);
	ft_stack.push(2);
	ft_stack.push(3);
	ft_stack.push(4);

	out << "Stack no-empty: " << ft_stack.empty() << std::endl;
	out << "Stack top: " << ft_stack.top() << std::endl;
	out << "Stack size: " << ft_stack.size() << std::endl;
	
	out << "\n<Pop one element>" << std::endl;
	ft_stack.pop();

	out << "Stack top: " << ft_stack.top() << std::endl;
	out << "Stack size: " << ft_stack.size() << std::endl;

	out << "\n<Operator Test>" << std::endl;
	
	ft::stack<int, std::deque<int> > ft_stack2 = ft_stack;
	out << "Operator =: " << ft_stack2.top() << " " << ft_stack2.size() << std::endl;
	out << "Operator ==: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator !=: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator >: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator =>: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <=: " << (ft_stack == ft_stack2) << std::endl;

	out << "\n<Add one elem>" << std::endl;
	ft_stack2.push(5);

	out << "Operator =: " << ft_stack2.top() << " " << ft_stack2.size() << std::endl;
	out << "Operator ==: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator !=: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator >: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator =>: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <: " << (ft_stack == ft_stack2) << std::endl;
	out << "Operator <=: " << (ft_stack == ft_stack2) << std::endl;
}
