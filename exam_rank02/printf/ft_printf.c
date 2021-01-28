#include "unistd.h"
#include "stdarg.h"

int ft_strlen(char *c)
{
    int i = 0;
    while (c[i])
        i++;
    return (i);
}

int ft_putchar(char a)
{
    write(1, &a, 1);
    return 1;
}
int ft_strchr( char *set,char a)
{
    int i = 0;
    while (set[i])
    {
        if (a == set[i])
            return 1;
        i++;
    }
    return 0;
}
int print_spaces(int n, int zero)
{
    char c = (zero)?'0':' ';
    int i = 0;
    while (i < n)
    {
        write(1,&c,1);
        i++;
    }
    return n;
}
void lennum(long long int n, char *base, int *len)
{
    int b = ft_strlen(base);
    if( n >= b)
        lennum(n/b,base,len);
    *len = *len +1; 
}
void putnbr(long long int n, char *base)
{
   int b = ft_strlen(base);
    if( n >= b)
        putnbr(n/b,base);
     ft_putchar(base[n%b]);
}
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////


int printstr(char *str,int pre, int wid)
{
    int len = 0;
    int aux = 0;
    if(str == NULL)
        str = "(null)";
    len = ft_strlen(str);
    if(pre == 0)
        len = 0;
    if(pre > 0 && pre < len)
        len = pre;
    if(wid > len)
        aux += print_spaces(wid - len, 0);
    write(1,str, len);
    return len + aux;
    
}

int printnum(long int n,int pre, int wid)
{
    int len;
    int final = 0;
    int neg = 0;

    len = 0;
    if(n == 0 && pre == 0)
        len = -1;
    if(n < 0)
    {
        neg = 1;
        n *= -1;
        wid--;
    }
    lennum(n,"0123456789",&len);
    if(wid > pre && wid > len)
    {
        if(pre > len)
            final += print_spaces(wid - pre,0);
        else
            final += print_spaces(wid - len,0);
    }
    if(neg == 1)
        final += ft_putchar('-');
    if(pre > len)
        final += print_spaces(pre - len,1);
    if(!(n == 0 && pre == 0))
        putnbr(n,"0123456789");
    return len + final;
}
int printexa(unsigned int n,int pre, int wid)
{
    int len;
    int final = 0;

    len = 0;
    if(n == 0 && pre == 0)
        len = -1;
    lennum(n,"0123456789abcdef",&len);
    if(wid > pre && wid > len)
    {
        if(pre > len)
            final += print_spaces(wid - pre,0);
        else
            final += print_spaces(wid - len,0);
    }
    if(pre > len)
        final += print_spaces(pre - len,1);
    if(!(n == 0 && pre == 0))
        putnbr(n,"0123456789abcdef");
    return len + final;
}
int ft_printf(const char *input, ...)
{
    int i = 0;
    int len = 0;
    int pre = -1;
    int wid = 0;
    va_list args;

    va_start(args, input);
    while (input[i])
    {
        wid = 0;
        pre = -1;
        if (input[i] == '%' && input[i + 1])
        {
            i++;
            while (ft_strchr("0123456789", input[i]))
            {
                wid = wid * 10 + (input[i] - '0');
                i++;
            }
            if (input[i] == '.')
            {
                i++;
                pre = 0;
                while (ft_strchr("0123456789", input[i]))
                {
                    pre = pre * 10 + (input[i] - '0');
                    i++;
                }
            }
            if(ft_strchr("sdx",input[i]))
            {
                if(input[i]=='s')
                    len+= printstr(va_arg(args,char *),pre,wid);
                if(input[i] == 'd')
                    len += printnum(va_arg(args,int),pre,wid);
                 if(input[i] == 'x')
                    len += printexa(va_arg(args,int),pre,wid);
            }
            else 
                break ;
        }
        else
                len += ft_putchar(input[i]);
        i++;
    }
    return (len);
}