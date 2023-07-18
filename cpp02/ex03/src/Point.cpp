/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:31:15 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 18:20:42 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const Point& src) : _x(src._x), _y(src._y) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::~Point() {}

Point&	Point::operator=(Point const &src) {
	(void)src;
	return(*this);
}

Fixed	Point::getX() const {
	return(this->_x);
}

Fixed	Point::getY() const {
	return(this->_y);	
}
