#include "../includes/push_swap.h"

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