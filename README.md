
# Implementation of C++ STL containers

### Purpose of the project
Discover meta programming.
Recode the STL containers: vector, map, stack and set.
Learn about the underlying data structures of these containers to better identify which container suits a specific problem.

### Steps to do containers
- Learn about template functions and  meta programming. Learning about code generalisation, reducing compilation potential errors, reducing execution time through optimised compilation (inline bool, enable_if, const volatile, etc…)
https://jonathanpoelen.github.io/2020/04/sfinae/#emplacement-des-expressions-pour-le-sfinae
https://www.youtube.com/watch?v=tiAVWcjIF6o https://www.youtube.com/watch?v=dLZcocFOb5Q
    - Start with type traits. You will need to use functions such as enable_if, is_integral (remove_cv), equal, lexicographical_compare
    - Then do the iterator that will be used for vector (normal_iterator in source code, random_access_iterator in my code).
    - Learn about the Allocator and check ISO c++98 standard.
https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf
    - Do reverse_iterator. 
    - Then you can start vector:
        - Start with typedef, typenames, attributes, all the prototypes.
        - I started with the member function insert, since you need it to start testing your vector and iterator. But you can start with something else if it makes more sense to you.
        - My first version of insert was much longer until I did other key functions like reserve. 
        - After you can do erase.
        - After you can do the rest and test step by step
        - Use a tester after you did your own tests, so you know you can go on with the project with a reliable vector container.
    - After vector, it's easy to do stack
    - Then I continued with map implemented with the RED BLACK TREE 
https://www.youtube.com/watch?v=nMExd4DthdA&list=RDCMUC6Aa5t0vHN8uj_BCbgrRZcQ&start_radio=1&rv=nMExd4DthdA&t=5
-> great videos from San Diego State University - Data Structures Lectures about red black tree rules, rotation, colour flipping etc.
    - Check that your insert and erase function lead to a balanced tree with your own tree visualization. Or use mine.
    - After map, it's easy to do set
      
### Red-Black Tree visualization


## Sources
https://en.cppreference.com/w/cpp/container
https://cplusplus.com/reference/stl/
https://en.wikipedia.org/wiki/Introduction_to_Algorithms


