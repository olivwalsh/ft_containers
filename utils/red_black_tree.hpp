/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:54:52 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/12 22:45:14 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

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
			node( const node & lhs)
			{
				*this = lhs;
			}
			~node();

			node & operator=(const node &rhs)
			{
				// key = rhs.key;
				value = rhs.value;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				is_left_child = rhs.is_left_child;
				color = rhs.color;
				return *this;
			}
			
	};
	
	template <typename T>
	class rbt_iterator
	{
		typedef	T 									value_type;
		typedef T&									reference;
		typedef const T&							const_reference;
		typedef T*									pointer;
		typedef const T*							const_pointer;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t 							difference_type;

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

	/* ------------- RED BLACK TREE CLASS ------------- */


	template <typename Key,
				typename Value,
				typename Compare = std::less<Key>,
				typename Allocator = std::allocator<node<Value> >
				>
	class red_black_tree
	{
		public:
			typedef				Key												key_type;
			typedef 			Value											value_type;
			typedef 			Compare											key_compare;
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
			typedef				ft::rbt_iterator<const value_type>				const_iterator;

			typedef				ft::reverse_iterator< iterator >				reverse_iterator;
			typedef				ft::reverse_iterator< const iterator >			const_reverse_iterator;

			typedef typename 	Allocator::template rebind< node_type >::other	node_allocator;

			/* ------------- constructors ------------- */
			red_black_tree(const Compare &comp, const allocator_type &alloc = allocator_type())
				: _root(NULL), _size(0), _compare(comp), _node_allocator(alloc) { }

			red_black_tree(const red_black_tree &rhs)
				: _root(NULL), _size(0), _compare(rhs._compare), _node_allocator(rhs._node_allocator)
			{
				*this = rhs;
			}

			~red_black_tree() { }

			red_black_tree & operator=(const red_black_tree &rhs)
			{
				_compare = rhs._compare;
				_root = rhs._root;
				_node_allocator = rhs._node_allocator;
				_size = rhs._size;
				return *this;
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{
				node_pointer node;
				(void)value;
				
				return ft::make_pair(iterator(node), true);
			}
			
			void add(Value value)
			{
				node_pointer node = new node_pointer(value);

				if (!_root)
				{
					_root = node;
					node->color = black;
					_size++;
					return ;
				}
				add(_root, node);
				_size++;
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

		private:
			void add(node_pointer parent, node_pointer new_node)
			{
				if (_compare(new_node->key, parent->key) > 0)
				{
					// add right
					if (!parent->right)
					{	
						parent->right = new_node;
						new_node->parent = parent;
						return ;
					}
					return add(parent->right, new_node);
				}
				if (!parent->left)
				{	
					parent->left = new_node;
					new_node->parent = parent;
					new_node->is_left_child = true;
				}
				return add(parent->left, new_node);
				check_color(new_node);
			}

			void check_color(node_pointer node)
			{
				if (node == _root)
					return ;
				if (node->color == red && node->parent->color == red)
					correct_tree(node);
				check_color(node->parent);
			}

			void correct_tree(node_pointer node)
			{
				if (node->parent->is_left_child)
				{
					// aunt is node parent parent right 
					if (!node->parent->parent->right || node->parent->parent->right->color == black)
						return rotate(node);
					if (node->parent->parent->right)
						node->parent->parent->right->color = black;
					node->parent->parent->color = red;
					node->parent->color = black;
					return ;
				}
				else // aunt is grandparent's left child
				{
					if (!node->parent->parent->left || node->parent->parent->left->color == black)
						return rotate(node);
					if (node->parent->parent->left)
						node->parent->parent->left->color = black;
					node->parent->parent->color = red;
					node->parent->color = black;
					return ;	
				}
			}

			void rotate(node_pointer node)
			{
				if (node->is_left_child)
				{
					if (node->parent->is_left_child)
					{
						right_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->right)
							node->parent->right->color = red;
						return ;
					}
					right_left_rotate(node->parent->parent);
					node->color = black;
					node->right->color = red;
					node->left->color = red;
					return ;
				}
				else // if right child
				{
					if (!node->parent->is_left_child)
					{
						left_rotate(node->parent->parent);
						node->color = red;
						node->parent->color = black;
						if (node->parent->left)
							node->parent->left->color = red;
						return ;
					}
					left_right_rotate(node->parent->parent);
					node->color = black;
					node->right->color = red;
					node->left->color = red;
					return ;
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
		
		private:
			node_pointer	_root;
			size_type		_size;
			key_compare		_compare;
			node_allocator	_node_allocator;

			
	};

	
};

#endif