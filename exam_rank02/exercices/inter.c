/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:32:42 by pablo             #+#    #+#             */
/*   Updated: 2020/12/13 14:45:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

#include <unistd.h>

int main(int argc,char  **argv)
{
    int i;
    int j;
    char ascii[255];

    i = 0;
    while(i < 255)
        ascii[i++] = '0';
    i = 0;
    if(argc == 3)
    {
        while (argv[1][i])
        {
            j = 0;
            while (argv[2][j])
            {
                if(argv[1][i] == argv[2][j] && ascii[(unsigned int)argv[1][i]] == '0')
                {
                    write(1,&argv[1][i],1);
                    ascii[(unsigned int)argv[1][i]] = 1;
                    break ;
                }
                j++;
            }
            i++;
        }
        write(1,"\n",1); 
    }
     return (0);
}

