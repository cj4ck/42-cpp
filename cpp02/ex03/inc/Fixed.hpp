/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:13:50 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 16:55:50 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "colors.h"

class Fixed {
  public:
	Fixed();
	Fixed(const Fixed&);
	
	Fixed(const int);
	Fixed(const float);
	
	~Fixed();
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int 	toInt() const;

	Fixed&	operator=(Fixed const &rs);
	
	bool	operator>(Fixed const &rs);
	bool	operator<(Fixed const &rs);
	bool	operator>=(Fixed const &rs);
	bool	operator<=(Fixed const &rs);
	bool	operator==(Fixed const &rs);
	bool	operator!=(Fixed const &rs);

	Fixed	operator+(Fixed const &rs);
	Fixed	operator-(Fixed const &rs);
	Fixed	operator*(Fixed const &rs);
	Fixed	operator/(Fixed const &rs);
	
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	static Fixed&			min(Fixed &ls, Fixed &rs);
	static Fixed const &	min(Fixed const &ls, Fixed const &rs);
	static Fixed&			max(Fixed &ls, Fixed &rs);
	static Fixed const &	max(Fixed const &ls, Fixed const &rs);

  private:
	int	_fixed_point;
	static const int	_fractional_bits = 8;
};
