/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:50:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/25 13:40:27 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef bidirectional_iterator_hpp
#define bidirectional_iterator_hpp
#include "iterator.hpp"


namespace ft {

	template <typename Iter>
	class my_bidirectional_iterator: public ft::iterator<std::bidirectional_iterator_tag,Iter>
	{

		public:
			

	}




};


#endif
