/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:20:56 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/13 11:40:10 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_printnbr(int nbr);
int	ft_printchar(const char c);
int	ft_printnbrus(unsigned int nbr);
int	ft_printhexa_min(unsigned int n);
int	ft_printhexa_maj(unsigned int n);
int	ft_printstr(char *str);
int	ft_printadd(unsigned long int n);

#endif
