/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 17:09:44 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _fixed_point(0) {
	std::cout << INFO << "Default constructor called" << R << std::endl;
}

Fixed::Fixed(const int n) : _fixed_point(0) {
	std::cout << INFO << "Polimotphic constructor for int called" << R << std::endl;
	this->_fixed_point = n << _fractional_bits;
}

Fixed::Fixed(const float n) : _fixed_point(0) {
	std::cout << INFO << "Polimorphic constructor for float called" << R << std::endl;
	this->_fixed_point = roundf(n * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << INFO << "Copy constructor called" << R << std::endl;
	this->_fixed_point = copy.getRawBits();
}

Fixed::~Fixed(){
	std::cout << INFO << "Destructor called" << R << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << INFO << "getRawBits member function called" << R << std::endl;
	return(this->_fixed_point);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixed_point = raw;
}

float	Fixed::toFloat() const {
	return(static_cast<float>(_fixed_point) / (1 << _fractional_bits));
}

int		Fixed::toInt() const {
	return(_fixed_point >> _fractional_bits);
}

Fixed& Fixed::operator=(Fixed const &rs) {
	std::cout << INFO << "Copy assignment operator called" << R << std::endl;
	this->_fixed_point = rs.getRawBits();
	return(*this);
}
