/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:53:07 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/18 11:56:36 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(long n);
int	ft_printunsnbr(unsigned int n);
int	ft_printhex(char str, unsigned int n);
int	ft_printptr(void *ptr);
int	ft_printf(const char *str, ...);

#endif