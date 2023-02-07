/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:47:07 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/06 18:34:40 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED(s) "\033[1;31m" s "\033[m"
#define GREEN(s) "\033[1;32m" s "\033[m"
#define TITLE(s) "\033[3;32m" s "\033[m"

#define nl() std::cout << std::endl;

# include <iostream> 

template <typename T>
void	print(T container)
{
	if (container.empty())
	{
		std::cout << "container is empty" << std::endl;
		return ;
	}
	std::cout << "container size: " << container.size() << std::endl;
	std::cout << "container values: ";
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	nl();
}