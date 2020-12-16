/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:41:04 by pablo             #+#    #+#             */
/*   Updated: 2020/12/15 11:01:05 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char ascii[255];

    i = 0;
    while (i < 255)
        ascii[i++] = '0';
    i = 1;
    if (argc == 3)
    {
        while (i < 3)
        {
            j = 0;
            while (argv[i][j])
            {
                if (argv[i][j] && ascii[(unsigned int)argv[i][j]] == '0')
                {
                    write(1, &argv[i][j], 1);
                    ascii[(unsigned int)argv[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}