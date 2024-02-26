/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:10:39 by mstefano          #+#    #+#             */
/*   Updated: 2023/11/17 19:42:29 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list				args;
	int					print_len;
	int					ret;

	print_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			ret = ft_print_formats(args, ++str);
			if (ret < 0)
				return (-1);
			print_len += ret;
		}
		else
		{
			if (ft_print_character(*str) != 1)
				return (-1);
			++print_len;
		}
		str++;
	}
	va_end(args);
	return (print_len);
}

// int	main(void)
// {
// 	ft_printf("%s\n", "");
// 	printf("%s", "");
// 	return (0);
// }
	// ft_printf("Character: %c\n", character);
	// ft_printf("String: %s\n", string);
	// ft_printf("Pointer: %p\n", &i);
	// printf("Character: %c\n", character);
	// printf("String: %s\n", string);
	// printf("Pointer: %p", &i);
	// ft_printf("%d\n", -1);
	// printf ("%d", -1);
	// char				character;
	// char				*string;
	// unsigned long long	pointer_value;
	// int					i;

	// character = 'A';
	// string = "Hello, World!";
	// pointer_value = (unsigned long long)&main;
	// i = -1;
