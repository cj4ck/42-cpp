/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:46:00 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/20 08:03:14 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/whatever.hpp"
#include "../inc/Colors.hpp"

int main() {
	int	a = 2;
	int	b = 3;
	::swap(a, b);
	std::cout << GREEN << "a = " << a << ", b = " << b << E;
	std::cout << GREEN << "min( a, b ) = " << ::min(a, b) << E;
	std::cout << GREEN << "max( a, b ) = " << ::max(a, b) << E;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << GREEN << "c = " << c << ", d = " << d << E;
	std::cout << GREEN << "min( c, d ) = " << ::min(c, d) << E;
	std::cout << GREEN << "max( c, d ) = " << ::max(c, d) << E;
	return 0;
}
