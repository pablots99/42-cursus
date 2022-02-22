/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:32:44 by pablo             #+#    #+#             */
/*   Updated: 2021/02/24 19:25:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct s_circle
{
        char type;
        float x;
        float y;
        float r;
        char c;
        struct s_circle *next;
} t_circle;

typedef struct s_config
{
        int width;
        int height;
        char background;
        t_circle *circles;
} t_config;

void save_circle(FILE *file, t_circle **circle,char c)
{
         t_circle *aux;
         t_circle *list;

        list = *circle;
        aux = malloc(sizeof(t_circle));
        fscanf(file, "%f %f %f %c", &aux->x, &aux->y, &aux->r, &aux->c);
        aux->type = c;
        aux->next = NULL;
        while (list && (list->next))
                list = list->next;
        if(!list )
                 *circle = aux;
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

                if (type == 'c'  || type == 'C')
                        save_circle(file, &c->circles,type);
                else if ((type != ' ') && (type != '\n'))
                        err++;
        }
        return (err ? 1 : 0);
}
char paint_circle(t_circle *circles,int x, int y)
{
         t_circle *list;
         float val;
         char a;

        a = 0;
         list = circles;
         while (list)
         {      
                 val = sqrtf(powf(x - list->x, 2) + powf(y - list->y, 2));
                 if (list->type == 'c' &&  (val <= list->r && val > list->r -1))
                        a =  list->c;
                 if (list->type == 'C' && val <= list->r)
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
                        a = paint_circle(c.circles,x,y);
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
        t_circle *aux;
        t_circle *circle = c->circles;
        while (circle)
        {       aux = circle;
                circle = circle->next;
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
