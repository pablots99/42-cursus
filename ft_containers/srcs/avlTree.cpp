/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:45 by pablo             #+#    #+#             */
/*   Updated: 2022/03/17 16:44:44 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include "containers/stack.hpp"
#include <iostream>
#include <math.h>

namespace ft {


		template<class T, class K>
		struct node {
			T	value;
			K	key;
			node *r;
			node *l;
			node()
		};

		template<class Key,class T,typename Compare = std::less<Key> >
		class Avl {
			private:
				node *_root;
			public:
		};




}
