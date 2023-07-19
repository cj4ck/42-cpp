/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:11:30 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 22:09:01 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Colors.hpp"
#include <cstdlib>
#include <tr1/random>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
    Base *tmp;
    int rd;

    srand(time(NULL));
    rd = 1 + (rand() % 3);
    std::cout << GREEN << "Generate ";
    if (rd == 1)
    {
        tmp = new A;
        std::cout << "A" << std::endl;
    }
    if (rd == 2)
    {
        tmp = new B;
        std::cout << "B" << std::endl;
    }
    if (rd == 3)
    {
        tmp = new C;
        std::cout << "C" << std::endl;
    }
    std::cout << E;
    return(tmp);
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
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();

    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << E;

    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b ); std::cout << E;

    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c ); std::cout << E;

    delete a;
    delete b;
    delete c;
    return (0);
}
