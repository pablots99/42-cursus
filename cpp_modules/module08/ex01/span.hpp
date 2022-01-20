/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:31:56 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/20 13:38:06 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CPP
#define SAPN_CPP

class Span { 

    private:
        const unsigned int _N;
        int  *nums;
    public:
        Span(unsigned int n);
        Span();

}

#endif