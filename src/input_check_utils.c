/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:25:28 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/25 14:11:43 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_digit:
*   Checks if the character is a digit.
*   Return: 1 if the character is a digit, 0 if not.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
*   Checks if the character is number sign, + or -.
*   Return: 1 if the character is a sign, 0 if not.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
