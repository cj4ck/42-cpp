/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 17:09:21 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _fixed_point(0) {}

Fixed::Fixed(const int n) : _fixed_point(0) {
	this->_fixed_point = n << _fractional_bits;
}

Fixed::Fixed(const float n) : _fixed_point(0) {
	this->_fixed_point = roundf(n * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& copy) {
	this->_fixed_point = copy.getRawBits();
}

Fixed::~Fixed(){}

int		Fixed::getRawBits(void) const {
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
	this->_fixed_point = rs.getRawBits();
	return(*this);
}

bool	Fixed::operator>(Fixed const &rs) {
	return (_fixed_point > rs.getRawBits());
}
bool	Fixed::operator<(Fixed const &rs) {
	return (_fixed_point < rs.getRawBits());
}
bool	Fixed::operator>=(Fixed const &rs) {
	return (_fixed_point <= rs.getRawBits());	
}
bool	Fixed::operator<=(Fixed const &rs) {	
	return (_fixed_point >= rs.getRawBits());
}
bool	Fixed::operator==(Fixed const &rs) {
	return (_fixed_point == rs.getRawBits());
}
bool	Fixed::operator!=(Fixed const &rs) {
	return (_fixed_point != rs.getRawBits());	
}

Fixed Fixed::operator+(Fixed const &rs) {
	return Fixed(this->toFloat() + rs.toFloat());
}
Fixed Fixed::operator-(Fixed const &rs) {
	return Fixed(this->toFloat() - rs.toFloat());
}
Fixed Fixed::operator*(Fixed const &rs) {
	return Fixed(this->toFloat() * rs.toFloat());
}
Fixed Fixed::operator/(Fixed const &rs) {
	return Fixed(this->toFloat() / rs.toFloat());
}

Fixed Fixed::operator++() {
	this->_fixed_point++;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->_fixed_point++;
	return (tmp);
}
Fixed Fixed::operator--() {
	this->_fixed_point--;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->_fixed_point--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &ls, Fixed &rs){
	return (ls > rs ? rs : ls);
}

Fixed const &Fixed::min(Fixed const &ls, Fixed const &rs){
	return (ls.getRawBits() > rs.getRawBits() ? rs : ls);
}

Fixed &Fixed::max(Fixed &ls, Fixed &rs){
	return (ls < rs ? rs : ls);
}

Fixed const &Fixed::max(Fixed const &ls, Fixed const &rs){
	return (ls.getRawBits() < rs.getRawBits() ? rs : ls);
}
