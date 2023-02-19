#include "common.hpp"
#include <list>

#include <iostream>

#if REAL
    #include <vector>
	#include <map>
    namespace ft = std;
#else
	#include <vector.hpp>
	#include <map.hpp>
#endif

void vectorTest( void );
void mapTest( void );

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	// printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	// printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	mp.print();

	ft_erase(mp, ++mp.begin());
	// mp.print();
	ft::map<T1, T2>::iterator it = mp.begin();
	std::cout << "Lets erase begin. begin is " << printPair(it) << std::endl;

	ft_erase(mp, mp.begin());
	// mp.print();

	ft_erase(mp, --mp.end());
	// mp.print();

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());
	printSize(mp);

	return (0);
}
