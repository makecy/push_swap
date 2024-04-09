/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:34:37 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/09 18:23:39 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long long	ft_atoll(const char *str)
{
	long long	i;
	int			j;

	i = 0;
	j = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		j = -j;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i * j);
}

int	is_dup(t_stack_node *stack)
{
	t_stack_node	*temp;

	while (stack->next)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->value == stack->value)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

bool	check_int_range(char *num_str)
{
	long long	num;

	num = ft_atoll(num_str);
	if (num > INT_MAX || num < INT_MIN || ft_strlen(num_str) > 11)
	{
		return (true);
	}
	return (false);
}
t_stack_node	*last_node(t_stack_node *stack_a)
{
	t_stack_node	*last;

	last = stack_a;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

// ____________________________________________________________________//
// ____________________________________________________________________//
//						ONLY USE FOR VALGRIND							//
// ____________________________________________________________________//
// ____________________________________________________________________//

// int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	else
// 		return (0);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	total;
// 	void	*ptr;

// 	total = count * size;
// 	ptr = malloc(total);
// 	if (ptr != NULL)
// 		ft_memset(ptr, 0, total);
// 	return (ptr);
// }

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*a;

// 	a = (unsigned char *)b;
// 	while (len > 0)
// 	{
// 		*a = (unsigned char)c;
// 		a++;
// 		len--;
// 	}
// 	return (b);
// }

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 1;
// 	while (*str == 32 || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == 45)
// 	{
// 		j = -j;
// 		str++;
// 	}
// 	else if (*str == 43)
// 		str++;
// 	while (*str >= 48 && *str <= 57)
// 	{
// 		i = i * 10 + (*str - 48);
// 		str++;
// 	}
// 	return (i * j);
// }
// static size_t	count_words(const char *str, char c)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		while (*str == c)
// 			str++;
// 		if (*str)
// 			count++;
// 		while (*str && *str != c)
// 			str++;
// 	}
// 	return (count);
// }

// static void	mem_free(char **str, int count)
// {
// 	while (count >= 0)
// 	{
// 		free(str[count]);
// 		count--;
// 	}
// 	free(str);
// }

// static void	mem_allocate(char ***array, char const *s, char c)
// {
// 	char		**array_n;
// 	char const	*temp;

// 	array_n = *array;
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		temp = s;
// 		while (*temp && *temp != c)
// 			temp++;
// 		if (temp > s)
// 		{
// 			*array_n = ft_substr(s, 0, temp - s);
// 			if (!*array_n)
// 			{
// 				mem_free(*array, array_n - *array);
// 				*array = NULL;
// 				return ;
// 			}
// 			array_n++;
// 		}
// 		s = temp;
// 	}
// 	*array_n = 0;
// }

// char	**ft_split(char const *s, char c)
// {
// 	int			count;
// 	char		**result;

// 	if (s == NULL)
// 		return (NULL);
// 	count = count_words(s, c);
// 	result = (char **)malloc(sizeof(char *) * (count + 1));
// 	if (!result)
// 		return (NULL);
// 	mem_allocate(&result, s, c);
// 	return (result);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	slength;
// 	size_t	i;

// 	i = 0;
// 	slength = ft_strlen(s);
// 	if (!s)
// 		return (NULL);
// 	if (len > slength - start)
// 		len = slength - start;
// 	if (start >= slength)
// 		return (ft_strdup(""));
// 	substr = malloc(sizeof(char) * (len + 1));
// 	if (!substr)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		substr[i] = s[i + start];
// 		i++;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	count;

// 	count = 0;
// 	if (!s)
// 		return (0);
// 	while (s[count])
// 		count++;
// 	return (count);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*a;
// 	size_t	len;
// 	size_t	i;

// 	a = (char *)s1;
// 	len = ft_strlen(s1);
// 	a = malloc(len * sizeof(char) + 1);
// 	if (!a)
// 	{
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (len > i)
// 	{
// 		a[i] = s1[i];
// 		i++;
// 	}
// 	a[i] = '\0';
// 	return (a);
// }
// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && (s1[i] || s2[i]))
// 	{
// 		if ((unsigned char)s1[i] > (unsigned char)s2[i])
// 			return (1);
// 		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
// 			return (-1);
// 		i++;
// 	}
// 	return (0);
// }
