/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:11:30 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/12 17:20:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iomanip>

/* Overloading the insertion operator because compiler doesn't know how to
handle the Fixed class */
std::ostream &operator<<(std::ostream &stream, Fixed const &value)
{
	stream << value.toFloat();
	return (stream);
}

int	main() {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << BASE_B << "39m" << std::setw(10) << "[a]" <<R<< " " << a << std::endl;
	std::cout << BASE_B << "39m" << std::setw(10) << "[++a]" <<R<<	" " << ++a << std::endl;
	std::cout << BASE_B << "39m" << std::setw(10) << "[a]" <<R<<	" " << a << std::endl;
	std::cout << BASE_B << "39m" << std::setw(10) << "[a++]" <<R<<	" " << a++ << std::endl;
	std::cout << BASE_B << "39m" << std::setw(10) << "[a]" <<R<<	" " << a << std::endl;
	std::cout << BASE_B << "39m" << std::setw(10) << "[b]" <<R<<	" " << b << std::endl;
	std::cout << BASE_B << "39m" << "[max(a,b)]" <<R<< " " << Fixed::max( a, b ) << std::endl;

	return(0);
}
