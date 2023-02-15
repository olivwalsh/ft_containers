/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:52 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/15 16:12:07 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "type_traits.hpp"

/*
	The rules:
		- root is black
		- null nodes are black
		- every path from root to null must have the same amount of black nodes
		- there are no two consecutives red nodes
		- every insertion is red

	when new insertion:
		if red aunt: color flip
		if black aunt: rotate
	
*/

# define black	true
# define red	false

namespace ft
{

	/* ------------- NODE (RED BLACK TREE) CLASS ------------- */

	template <typename Value>
	class node
	{
		public:
			// typedef Key					key_type;
			typedef Value				value_type;
			typedef node<Value>			*node_pointer;
			
			// key_type					key;
			value_type					value;
			node_pointer				left;
			node_pointer				right;
			node_pointer				parent;
			bool						is_left_child;
			bool						color;


			node()
				: value(0), left(NULL), right(NULL), parent(NULL), is_left_child(false), color(red) { }
			node(const value_type &value)
				: value(value), left(NULL), right(NULL), parent(NULL), is_left_child(false), color(red) { }
			node(value_type val, node_pointer l, node_pointer r, node_pointer p, bool is_l, bool c)
				: value(val), left(l), right(r), parent(p), is_left_child(is_l), color(c) { }
			
			// node( const node & lhs)
			// {
			// 	*this = lhs;
			// }
			
			~node() { }

			// node & operator=(const node &rhs)
			// {
			// 	// key = rhs.key;
			// 	value = rhs.value;
			// 	left = rhs.left;
			// 	right = rhs.right;
			// 	parent = rhs.parent;
			// 	is_left_child = rhs.is_left_child;
			// 	color = rhs.color;
			// 	return *this;
			// }
			
	};
	
	template <typename T>
	class rbt_iterator
	{
		public:
			typedef	T 									value_type;
			typedef T&									reference;
			typedef T*									pointer;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef std::ptrdiff_t 						difference_type;

			typedef node<T>								node_type;
			typedef node<const T>						const_node_type;
			typedef node<T>								*node_pointer;
			typedef node<const T>						*const_node_pointer;
			
			typedef rbt_iterator<T>						iterator;
			typedef rbt_iterator<const T>				const_iterator;


			rbt_iterator() : node() { }
			
			explicit rbt_iterator(const node_pointer n) : node(n) { }

			template <typename _T>
			rbt_iterator(const rbt_iterator<_T> &src) : node(NULL)
			{
				*this = src;
			}

			~rbt_iterator() { }

			rbt_iterator &operator=(const rbt_iterator<T> &rhs)
			{
				node = rhs.node;
				return *this;
			}

			node_pointer base() const
			{
				return node;
			}

			reference operator*() const
			{
				return node->value;	
			}

			pointer operator->() const
			{
				return &node->value;
			}

			rbt_iterator &operator++()
			{
				if (node->right)
				{
					node = node->right;
					while (node->left)
						node = node->left;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (node == tmp->right)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					if (node->right != tmp)
						node = tmp;
				}
				return *this;
			}

			rbt_iterator operator++(int)
			{
				rbt_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			rbt_iterator &operator--()
			{
				if (node->color == red && node->parent->parent == node)
					node = node->right;
				else if (node->left)
				{
					node_pointer tmp = node->left;
					while (tmp->right)
						tmp = tmp->right;
					node = tmp;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (node == tmp->left)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					node = tmp;
				}
				return *this;
			}

			rbt_iterator operator--(int)
			{
				rbt_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			bool operator==(const rbt_iterator& x) const
			{
				return node == x.node;
			}

			bool operator!=(const rbt_iterator& x) const
			{
				return node != x.node;
			}

			node_pointer								node;
		
	};

	template <typename T>
	class rbt_const_iterator
	{
		public:
			typedef	T 									value_type;
			typedef const T&							reference;
			typedef const T*							pointer;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef std::ptrdiff_t 						difference_type;

			typedef node<T>								node_type;
			typedef node<const T>						const_node_type;
			typedef node<T>								*node_pointer;
			typedef node<const T>						*const_node_pointer;
			
			typedef rbt_iterator<T>						iterator;
			typedef rbt_const_iterator<T>				const_iterator;


			rbt_const_iterator() : node(NULL) { }
			
			explicit rbt_const_iterator(const node_pointer n) : node(n) { }

			rbt_const_iterator(const iterator &src) : node(src.node) { }

			~rbt_const_iterator() { }

			// rbt_const_iterator &operator=(const rbt_const_iterator<T> &rhs)
			// {
			// 	node = rhs.base();
			// 	return *this;
			// }

			node_pointer base() const
			{
				return node;
			}

			reference operator*() const
			{
				return node->value;	
			}

			pointer operator->() const
			{
				return &node->value;
			}

			rbt_const_iterator &operator++()
			{
				if (node->right)
				{
					node = node->right;
					while (node->left)
						node = node->left;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (node == tmp->right)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					if (node->right != tmp)
						node = tmp;
				}
				return *this;
			}

			rbt_const_iterator operator++(int)
			{
				rbt_const_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			rbt_const_iterator &operator--()
			{
				if (node->color == red && node->parent->parent == node)
					node = node->right;
				else if (node->left)
				{
					node_pointer tmp = node->left;
					while (tmp->right)
						tmp = tmp->right;
					node = tmp;
				}
				else
				{
					node_pointer tmp = node->parent;
					while (node == tmp->left)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					node = tmp;
				}
				return *this;
			}

			rbt_const_iterator operator--(int)
			{
				rbt_const_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			bool operator==(const rbt_const_iterator& x) const
			{
				return node == x.node;
			}

			bool operator!=(const rbt_const_iterator& x) const
			{
				return node != x.node;
			}

			node_pointer								node;
		
	};

	/* ------------- RED BLACK TREE CLASS ------------- */


	template <typename Key,
				typename Value,
				typename Compare = std::less<Key>,
				typename Allocator = std::allocator<Value>
				>
	class red_black_tree
	{
		public:
			typedef				Key												key_type;
			typedef 			Value											value_type;
			typedef 			Compare											value_compare;
			typedef				Allocator 										allocator_type;
			
			typedef typename	Allocator::size_type							size_type;
			typedef typename	Allocator::difference_type						difference_type;
			
			typedef typename	Allocator::reference							reference;
			typedef typename	Allocator::const_reference						const_reference;
			typedef typename	Allocator::pointer								pointer;
			typedef typename	Allocator::const_pointer						const_pointer;

			typedef 			node<Value>										node_type;
			typedef				node<Value>										*node_pointer;
			
			typedef				ft::rbt_iterator<value_type>					iterator;
			typedef				ft::rbt_const_iterator<value_type>				const_iterator;

			typedef				ft::reverse_iterator< iterator >				reverse_iterator;
			typedef				ft::reverse_iterator< const_iterator >			const_reverse_iterator;

			typedef typename 	Allocator::template rebind< node_type >::other	node_allocator;

			/* ------------- constructors ------------- */
			red_black_tree(const Compare &comp, const allocator_type &alloc = allocator_type())
				: _root(NULL), _size(0), _compare(comp), _node_allocator(alloc)
			{
				_root = init_nil_node();
			}

			red_black_tree(const red_black_tree &rhs)
				: _nil_node(NULL), _root(NULL), _size(0), _compare(rhs._compare), _node_allocator(rhs._node_allocator)
			{
				*this = rhs;
			}

			~red_black_tree()
			{
				clear(_root);
				_node_allocator.destroy(_nil_node);
				_node_allocator.deallocate(_nil_node, 1);
				_nil_node = NULL;
			}

			red_black_tree & operator=(const red_black_tree &rhs)
			{
				clear();
				_compare = rhs._compare;
				_node_allocator = rhs._node_allocator;
				if (!_nil_node)
					_root = init_nil_node();
				if (!rhs.empty())
					insert(rhs.begin(), rhs.end());
				return *this;
			}

			void clear()
			{
				clear(_root);
				_nil_node->parent = _root;
				_nil_node->right = NULL;
				_nil_node->left = NULL;
				_nil_node->is_left_child = false;
				_nil_node->color = black;
				_root = _nil_node;
				_size = 0;
			}

			/* ------------- iterators ------------- */

			iterator begin()
			{
				return iterator(get_minimum_value());
			}

			const_iterator begin() const
			{
				return const_iterator(get_minimum_value());
			}
			
			iterator end()
			{
				return iterator(_nil_node);
			}

			const_iterator end() const
			{
				return const_iterator(_nil_node);
			}


			/* ------------- capacity ------------- */

			bool empty( void ) const
			{ 
				return this->_size == 0; 
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _node_allocator.max_size();
			}
			
			void swap(red_black_tree &other)
			{
				node_pointer	tmp_nil_node = _nil_node;
				node_pointer	tmp_root = _root;
				size_type		tmp_size = _size;
				value_compare	tmp_compare = _compare;
				node_allocator	tmp_node_allocator = _node_allocator;

				_nil_node = other._nil_node;
				_root = other._root;
				_size = other._size;
				_compare = other._compare;
				_node_allocator = other._node_allocator;
				
				other._nil_node = tmp_nil_node;
				other._root = tmp_root;
				other._size = tmp_size;
				other._compare = tmp_compare;
				other._node_allocator = tmp_node_allocator;
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				node_pointer duplicate = find(value);
				if (duplicate != _nil_node)
					return ft::make_pair(iterator(duplicate), false);
			
				node_pointer new_node = create_node(value);
				if (_root == _nil_node)
				{
					_root = new_node;
					_root->color = black;
					_size++;
					attach_nil_node();
				}
				else
				{
					detach_nil_node();
					add(_root, new_node);
					attach_nil_node();
					_size++;
				}
				return ft::make_pair(iterator(new_node), true);
			}

			template <class InputIt>
			void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0)
			{
				for (; first != last; ++first)
					insert(*first);
			}

			size_type get_height()
			{
				if (_root == NULL)
					return 0;
				return get_height(_root) - 1;
			}
			
			size_type get_height(node_pointer node)
			{
				if (!node)
					return 0;
				int left_height = get_height(node->left) + 1;
				int right_height = get_height(node->right) + 1;
				if (left_height > right_height)
					return left_height;
				return right_height;
			}

			node_pointer find(const value_type& value)
			{
				node_pointer	tmp = lower_bound(value);

				if (tmp == _nil_node || _compare(value, tmp->value))
					return _nil_node;

				return tmp;
			}

			/**
			 *  @return  node pointer pointing to first element equal to or greater
			 *           than value, or end().
			 **/
			node_pointer lower_bound(const value_type& value)
			{
				node_pointer tmp = _root;
				node_pointer lower = _nil_node;

				while (tmp && tmp != _nil_node)
				{
					if (!_compare(tmp->value, value))
					{
						lower = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return lower;
			}

			/**
			 *  @return  node pointer pointing to first element greater
			 *           than value, or end().
			 **/
			node_pointer upper_bound(const value_type& value)
			{
				node_pointer tmp = _root;
				node_pointer upper = _nil_node;
				
				while (tmp && tmp != _nil_node)
				{
					if (_compare(value, tmp->value))
					{
						upper = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return upper;
			}

		private:
			node_pointer	_nil_node;
			node_pointer	_root;
			size_type		_size;
			value_compare	_compare;
			node_allocator	_node_allocator;
		
			node_pointer init_nil_node()
			{
				_nil_node = create_node(value_type());
				_nil_node->parent = _root;
				_nil_node->right = NULL;
				_nil_node->left = NULL;
				_nil_node->is_left_child = false;
				_nil_node->color = black;
				return _nil_node;
			}

			node_pointer create_node(const value_type &value)
			{
				node_pointer tmp = _node_allocator.allocate(1);
		
				_node_allocator.construct(tmp, value);
				return tmp;
			}
			
			node_pointer tree_contains_value(const value_type& value)
			{
				node_pointer tmp = _root;
				
				while (tmp)
				{
					if (_compare(value, tmp->value))
						tmp = tmp->left;
					else if (_compare(tmp->value, value))
						tmp = tmp->right;
					else
						return tmp;
				}
				return NULL;
			}
			
			void add(node_pointer parent, node_pointer new_node)
			{
				if (_compare(parent->value, new_node->value))
				{
					// add right
					if (!parent->right)
					{	
						parent->right = new_node;
						new_node->parent = parent;
					}
					else
						add(parent->right, new_node);
				}
				else
				{
					if (!parent->left)
					{	
						parent->left = new_node;
						new_node->parent = parent;
						new_node->is_left_child = true;
					}
					else
						add(parent->left, new_node);
				}
				check_color(new_node);
			}

			void check_color(node_pointer node)
			{
				if (!node)
					return ;
				if (node == _root)
					return ;
				if (node && node->color == red && node->parent->color == red)
					correct_tree(node);
				check_color(node->parent);
			}

			node_pointer get_aunt(node_pointer node)
			{
				if (!node->parent || !node->parent->parent)
					return NULL;
				if (node->parent->is_left_child)
					return node->parent->parent->right;
				return node->parent->parent->left;
			}

			void color_flip(node_pointer node)
			{
				node_pointer aunt = get_aunt(node);
				
				if (aunt)
					aunt->color = black;
				node->parent->parent->color = red;
				node->parent->color = black;
			}
			
			void correct_tree(node_pointer node)
			{
				node_pointer aunt = get_aunt(node);
				
				if (!aunt || aunt->color == black)
					return rotate(node);
				color_flip(node);
			}

			void rotate(node_pointer node)
			{
				if (node->is_left_child)
				{
					if (node->parent && node->parent->is_left_child)
					{
						if (node->parent->parent)
							right_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->right)
							node->parent->right->color = red;
					}
					else
					{
						if (node->parent->parent)
							right_left_rotate(node->parent->parent);
						node->color = black;
						node->right->color = red;
						node->left->color = red;
					}
				}
				else // if right child
				{
					if (node->parent && !node->parent->is_left_child)
					{
						if (node->parent->parent)
							left_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->left)
							node->parent->left->color = red;
					}
					else
					{
						if (node->parent->parent)
							left_right_rotate(node->parent->parent);
						node->color = black;
						node->right->color = red;
						node->left->color = red;
					}
				}
			}

			void right_rotate(node_pointer node)
			{
				node_pointer tmp = node->left;
				node->left = tmp->right;
				if (node->left)
				{
					node->left->parent = node;
					node->left->is_left_child = false;
				}
				if (!node->parent)
				{	
					_root = tmp;
					tmp->parent = NULL;
				}
				else
				{
					tmp->parent = node->parent;
					if (node->is_left_child)
					{	
						tmp->is_left_child = true;
						tmp->parent->left = tmp;
					}
					else
					{
						tmp->is_left_child = false;
						tmp->parent->right = tmp;
					}
				}
				tmp->right = node;
				node->is_left_child = false;
				node->parent = tmp;
			}

			void left_rotate(node_pointer node)
			{
				node_pointer tmp = node->right;
				node->right = tmp->left;
				if (node->right)
				{
					node->right->parent = node;
					node->right->is_left_child = false;
				}
				if (!node->parent)
				{	
					_root = tmp;
					tmp->parent = NULL;
				}
				else
				{
					tmp->parent = node->parent;
					if (node->is_left_child)
					{	
						tmp->is_left_child = true;
						tmp->parent->left = tmp;
					}
					else
					{
						tmp->is_left_child = false;
						tmp->parent->right = tmp;
					}
				}
				tmp->left = node;
				node->is_left_child = true;
				node->parent = tmp;
			}

			void left_right_rotate(node_pointer node)
			{
				left_rotate(node->left);
				right_rotate(node);
			}

			void right_left_rotate(node_pointer node)
			{
				right_rotate(node->right);
				left_rotate(node);
			}

			int black_nodes(node_pointer node)
			{
				if (!node)
					return 1;
				int rhs_black_nodes = black_nodes(node->right);
				int lhs_black_nodes = black_nodes(node->left);
				if (rhs_black_nodes != lhs_black_nodes)
				{
					// throw an error or fix the tree
					return -1;
				}
				if (node->color == black)
					lhs_black_nodes++;
				return lhs_black_nodes;
			}

			node_pointer get_minimum_value() const
			{
				node_pointer tmp = _root;
				
				while (tmp && tmp->left)
					tmp = tmp->left;
				return tmp;
			}

			node_pointer get_maximum_value()
			{
				node_pointer tmp = _root;
				
				while (tmp && tmp->right && tmp->right != _nil_node)
					tmp = tmp->right;
				return tmp;
			}
		
			void attach_nil_node()
			{
				node_pointer tmp = get_maximum_value();

				if (tmp && tmp != _nil_node)
				{
					tmp->right = _nil_node;
					_nil_node->parent = tmp;
				}
			}

			void detach_nil_node()
			{
				node_pointer tmp = get_maximum_value();

				if (tmp && tmp != _nil_node)
				{
					tmp->right = NULL;
					_nil_node->parent = NULL;
				}
			}
			
			void clear(node_pointer current)
			{
				if (current == _nil_node)
					return ;
				if (!current)
					return ;
				if (current->left)
					clear(current->left);
				if (current->right)
					clear(current->right);
				_node_allocator.destroy(current);
				_node_allocator.deallocate(current, 1);
				current = NULL;
			}
	};

	
};

#endif