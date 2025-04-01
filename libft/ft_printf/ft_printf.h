/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcid-san <dcid-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:30:53 by dcid-san          #+#    #+#             */
/*   Updated: 2024/10/28 16:11:34 by dcid-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putptr_fd(void *ptr, int fd);
int	ft_put_int_fd(int n, int fd);
int	ft_print_str(char *str);
int	ft_put_unsigned_fd(unsigned int n, int fd);
int	ft_put_hexa(unsigned int nb, char c);

#endif
