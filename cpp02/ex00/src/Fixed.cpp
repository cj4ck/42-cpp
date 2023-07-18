/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 17:31:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _fixed_point(0) {
	std::cout << INFO << "Default constructor called" << R << std::endl;
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

Fixed& Fixed::operator=(Fixed const &rs) {
	std::cout << INFO << "Copy assignment operator called" << R << std::endl;
	this->_fixed_point = rs.getRawBits();
	return(*this);
}
