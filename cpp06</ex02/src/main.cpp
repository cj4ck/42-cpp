/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:11:30 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 22:28:45 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Colors.hpp"
#include <cstdlib>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate() {
    srand(time(NULL));
	if (std::rand() % 3 == 0)
		return (new A);
	else if (std::rand() % 2 == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p) {
	if (dynamic_cast< A* >(p))
		std::cout << GREEN << "A" << E;
	else if (dynamic_cast< B* >(p))
		std::cout << GREEN << "B" << E;
	else if (dynamic_cast< C* >(p))
		std::cout << GREEN << "C" << E;
	else
		std::cout << "unknown" << E;
}

void	identify(Base& p) {
	try {
		A& a = dynamic_cast< A& >(p);
		std::cout << GREEN << "\tObject is of type A" << E;
		(void)a;
	} catch(const std::exception& e) {
		std::cout << RED << "\tObject is not of type A" << E;
		try {
			B& b = dynamic_cast< B& >(p);
			std::cout << GREEN << "\tObject is of type B" << E;
			(void)b;
		} catch( const std::exception& e ) {
				std::cout << RED << "\tObject is not of type B" << E;
			try {
				C& c = dynamic_cast< C& >(p);
				std::cout << GREEN << "\tObject is of type C" << E;
				(void)c;
			} catch( const std::exception& e ) {
				std::cout << RED << "\tObject is not of type C" << E;
			}
		}
	}
}

int	main( void )
{
	std::string wait;
    Base*   a = generate();
    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << E;

	while (getline(std::cin, wait)) break;
    Base*   b = generate();
    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b ); std::cout << E;

	while (getline(std::cin, wait)) break;
    Base*   c = generate();
    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c ); std::cout << E;

    delete a;
    delete b;
    delete c;
    return (0);
}
