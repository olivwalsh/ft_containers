#include "common.hpp"

#define T1 int

int		main(void)
{

	ft::set<T1> const st;
	ft::set<T1>::iterator it = st.begin(); 
	// <-- no error, actually ! set allows for const_iterator => iterator conversion

	(void)it;

	// TESTED_NAMESPACE::set<T1> st;

	// std::cout << "hello" << std::endl;
	// TESTED_NAMESPACE::set<T1>::iterator ite = st.begin();
	// *ite = 42; // < -- error as well ; T is always const, even with regular iterator
	return (0);
}
