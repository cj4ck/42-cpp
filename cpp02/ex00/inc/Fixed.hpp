/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:13:50 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 16:06:50 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "colors.h"

class Fixed {
  public:
	Fixed();
	Fixed(const Fixed&);
	~Fixed();
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed&	operator=(Fixed const &rs);
	
  private:
	int	_fixed_point;
	static const int	_fractional_bits = 8;
};
