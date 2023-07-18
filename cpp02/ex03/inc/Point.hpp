/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:23:37 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 18:06:03 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Fixed.hpp"
#include "colors.h"

class Point {
  public:
	Point();
	Point(const Point&);
	Point(const float x, const float y);
	~Point();
	Point&	operator=(Point const &src);

	Fixed	getX() const;
	Fixed	getY() const;
  private:
	Fixed const	_x;
	Fixed const	_y;
};
