#include "push_swap.h"

/* error_message:
*   Writes "Error\n" to the standard output.
*/
void    error_message(void)
{
    write(1, "Error\n", 6);
    return ;
}

/* ft_atoi:
*   Converts an alphanumeric string of characters into a long integer.
*/
long int ft_atoi(const char *str)
{
    long int    nb;
    int         isneg;
    int         i;

    nb = 0;
    isneg = 1;
    i = 0;
    
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (is_digit(str[i]))
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return (nb * isneg);
}

/* ft_strcmp:
*   Compares two strings of characters.
*   Returns: 0 if they match, another value if they don't.
*/
int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}