/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:32:41 by pablo             #+#    #+#             */
/*   Updated: 2021/02/25 14:48:53 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct s_square
{
        char type;
        float x;
        float y;
        float width;
        float height;
        char c;
        struct s_square *next;
} t_square;

typedef struct s_config
{
        int width;
        int height;
        char background;
        t_square *squares;
} t_config;

void save_square(FILE *file, t_square **square,char c)
{
         t_square *aux;
         t_square *list;

        list = *square;
        aux = malloc(sizeof(t_square));
        fscanf(file, "%f %f %f %f %c", &aux->x, &aux->y, &aux->width,&aux->height, &aux->c);
        aux->type = c;
        aux->next = NULL;
        while (list && (list->next))
                list = list->next;
        if(!list )
                 *square = aux;
        else 
                list->next = aux;
}

int read_file(char *filename, t_config *c)
{
        FILE *file;
        char type;
        int err;

        err = 0;

        if (!(file = fopen(filename, "r")))
                return 1;
        if (fscanf(file, "%d %d %c", &c->width, &c->height, &c->background) == -1)
                return 1;
        while (fscanf(file, "%c", &type) != -1)
        {

                if (type == 'r'  || type == 'R')
                        save_square(file, &c->squares,type);
                else if ((type != ' ') && (type != '\n'))
                        err++;
        }
        return (err ? 1 : 0);
}
char paint_square(t_square *sq,int x, int y)
{
         t_square *list;
         float val;
         char a;

         a = 0;
         list = sq;
         while (list)
         {      
			 float x1 = list->x - list->width/2;
			 float y1 = list->y - list->height/2;
			 float x2 = list->x + list->width/2;
			 float y2 = list->y + list->height/2;
                 if (list->type == 'R' && (( x >= x1 &&  y>= y1) && (x <= x2 && y <= y2) ))
                        a =  list->c;
                 if (list->type == 'r' && ((( x > x1 && x < x1 + 1 ) && (y > y1 && y < y1 + 1)) &&  
				 							(( x < x2 && x > x2 - 1 ) && (y > y2 && y > y2 - 1))))
                        a =   list->c;
                 list = list->next;     
         }
         return a;
}

void paint_scene(t_config c)
{
        int x;
        int y;
        char a;

        y = 0;
        while (y < c.height)
        {
                x = 0;
                while (x < c.width)
                {
                        a = 0;
                        a = paint_square(c.squares,x,y);
                        if(!a)
                                a = c.background;
                        write(1, &a, 1);
                        x++;
                }
                write(1, "\n", 1);
                y++;
        }
}
void free_circles(t_config *c)
{
        t_square *aux;
        t_square *square = c->squares;
        while (square)
        {       aux = square;
                square = square->next;
                free(aux);
        }
        
}
int main(int argc, char **argv)
{
        t_config c;
        int err;

        err = 0;
        memset(&c, 0, sizeof(t_config));
        if (argc == 2)
                err = read_file(argv[1], &c);
        else
        {
                write(1, "Error: argument\n", 16);
               return 1;
        }
        if (err)
                printf("Error\n");
        else
                paint_scene(c);
        free_circles(&c);
        //system("leaks mini");
        return (err) ? 1 : 0;
}
