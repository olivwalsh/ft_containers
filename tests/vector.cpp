/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:58:20 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/03 11:02:39 by owalsh           ###   ########.fr       */
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


// int main()
// {
// 	ft::vector<int>    vec(3, 2);
    
//     if (vec.empty())
//         std::cout << "is empty" << std::endl;
        
//     ft::vector<int>::iterator    it;
//     ft::vector<int>::reverse_iterator    rit;

// 	std::cout << "printing vec" << std::endl;
//     for(it = vec.begin(); it != vec.end(); ++it)
//             std::cout << *it << " ";
        
//     std::cout << std::endl;

//     vec.insert(vec.begin(), 3, 6);
// 	std::cout << "printing vec" << std::endl;
//     for(it = vec.begin(); it != vec.end(); ++it)
//             std::cout << *it << " ";
        
//     std::cout << std::endl;

//     ft::vector<int>    vec2;

//     vec2.insert(vec2.begin(), vec.begin()+3, vec.end());

//     ft::vector<int>::iterator    it2;
    
// 	std::cout << "printing vec2" << std::endl;
//     for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
//             std::cout << *it2 << " ";
    
//     std::cout << std::endl;

// 	std::cout << "testing push back" << std::endl;
	

// 	vec2.push_back(7);
// 	vec2.push_back(882);
// 	vec2.erase(vec2.end() -1);
// 	std::cout << "printing vec2" << std::endl;
//     for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
//             std::cout << *it2 << " ";
    
//     std::cout << std::endl;

// 	std::cout << "testing erase range with vec" << std::endl;

// 	vec.erase(vec.begin() + 1, vec.end() - 2);
// 	std::cout << "printing vec" << std::endl;
//     for(it = vec.begin(); it != vec.end(); ++it)
//     	std::cout << *it << " ";
    
//     std::cout << std::endl;

// 	std::cout << "testing swap function" << std::endl;
// 	vec.swap(vec2);
// 	std::cout << "printing vec" << std::endl;
// 	 for(it = vec.begin(); it != vec.end(); ++it)
//     	std::cout << *it << " ";
//     std::cout << std::endl;
// 	std::cout << "printing vec2" << std::endl;
//     for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
//             std::cout << *it2 << " ";

// 	std::cout << std::endl;
// 	std::cout << "printing vec2 with reverse iterator" << std::endl;
//     for(rit = vec2.rbegin(); rit != vec2.rend(); ++rit)
//             std::cout << *rit << " ";
//     std::cout << std::endl;
	
// 	ft::vector<int> vec_test;
// 	(void)vec_test;
	
// 	std::cout << "testing assign function" << std::endl;
// 	vec.assign(vec2.begin(), vec2.end());
// 	std::cout << "printing vec" << std::endl;
// 	 for(it = vec.begin(); it != vec.end(); ++it)
//     	std::cout << *it << " ";
//     std::cout << std::endl;
// 	std::cout << "printing vec2" << std::endl;
//     for(it2 = vec2.begin(); it2 != vec2.end(); ++it2)
//             std::cout << *it2 << " ";
//     std::cout << std::endl;
			
// 	std::cout << "testing if vec == vec2" << std::endl;
// 	if (vec == vec2)
// 		std::cout << "vec and vec2 are the same" << std::endl;
// 	else
// 		std::cout << "vec and vec2 are different bitch" << std::endl;
	

			
// 	return 0;
// }

// using namespace ft;

template <class T>
void	print(ft::vector<ft::vector<T> >& lst)
{
	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(ft::vector<T>& lst)
{
	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main ()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

{
	ft::vector<int> foo,bar;

	foo.push_back(100);
	foo.push_back(200);

	bar.push_back(11);
	bar.push_back(22);
	bar.push_back(33);


	ft::vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	ft::vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	swap(bar, foo); //tmp iterates through bar
					//tmp2 iterates through foo


	ft::vector<int>	other;

	other.push_back(73);
	other.push_back(173);
	other.push_back(763);
	other.push_back(73854);
	other.push_back(74683);
	other.push_back(753);

	ft::vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	std::cout << "foo contains:\n";
	for (ft::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << '\n';

	std::cout << "bar contains:\n";
	for (ft::vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << '\n';

	while(tmp != bar.end())
	{
		std::cout << *tmp << '\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << *tmp2 << '\n';
		tmp2++;
	}
	tmp2--;

	swap(other, foo); //tmp2 iterates through other
					//tmp3 iterates throught foo
	print(other);
	print(foo);
	print(bar);
	while(tmp != bar.begin())
	{
		std::cout << *tmp << '\n';
		tmp--;
	}
	std::cout << *tmp << '\n';

	while(tmp2 != other.begin())
	{
		std::cout << *tmp2 << '\n';
		tmp2--;
	}
		std::cout << *tmp2 << '\n';

	while(tmp3 != foo.end())
	{
		std::cout << *tmp3 << '\n';
		tmp3++;
	}
	tmp3--;

	swap(bar, foo);
	swap(foo, bar);
	swap(bar, foo); //tmp3 iterates through bar
				//tmp iterates through foo

	print(other);
	print(foo);
	print(bar);

	while(tmp != foo.end())
	{
		std::cout << *tmp << '\n';
		tmp++;
	}

	while(tmp2 != other.end())
	{
		std::cout << *tmp2 << '\n';
		tmp2++;
	}

	while(tmp3 != bar.begin())
	{
		std::cout << *tmp3 << '\n';
		tmp3--;
	}
	std::cout << *tmp3 << '\n';
}

  return 0;
}
