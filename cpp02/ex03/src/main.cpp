/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:11:30 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 18:32:20 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include <cmath>
#

float ft_fabs(float i){
	if(i < 0)
		return(-i);
	return(i);
}

float area(Point a, Point b, Point c) {
	    return (
			ft_fabs(
				(
					   a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
					 + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
					 + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
				)
				/ 2.0
				));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    /* Calculate area of triangle ABC */
    float A = area(a, b, c);

    /* Calculate area of triangle PBC */
    float A1 = area(point, b, c);

    /* Calculate area of triangle PAC */
    float A2 = area(a, point, c);

    /* Calculate area of triangle PAB */
    float A3 = area(a, b, point);

    /* Check if sum of A1, A2 and A3 is same as A */
    return (A == A1 + A2 + A3);
}

int	main() {
		float x, y;

		std::cout << INFO << "Enter the coordinates for point a: " << R << std::endl;
		std::cin >> x >> y;
		Point a(x, y);

		std::cout << INFO << "Enter the coordinates for point b: " << R << std::endl;
		std::cin >> x >> y;
		Point b(x, y);

		std::cout << INFO << "Enter the coordinates for point c: " << R << std::endl;
		std::cin >> x >> y;
		Point c(x, y);

		std::cout << INFO << "Enter the coordinates for point: " << R << std::endl;
		std::cin >> x >> y;
		Point point(x, y);
		// Point	a(0, 0);
		// Point	b(5, 0);
		// Point	c(5, 5);
		// Point	point(4, 4);
		if(bsp(a, b, c, point))
			std::cout << GREEN<< "Point exists in a triangle 🎉" << R << std::endl;
		else
			std::cout << RED << "Point doesn't exists in a triangle ;\\" << R << std::endl;
		return(0);
}
