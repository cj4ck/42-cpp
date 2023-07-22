/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:44:12 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/20 12:01:35 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Array.hpp"

#define MAX_VAL 750

int main() {
    Array<int> a(42);
    Array<char> b(1);

    std::cout << std::endl;
    try {
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i + 1;
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = 'a' + i;
        std::cout << BLUE <<"a elements: " << std::endl << E;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << "   " << a[i] << E;
        std::cout << E;
        std::cout << BLUE << "b elements: " << E << E;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << "   " << b[i] << E;
        std::cout << E;
        std::cout << BLUE << "b[b.size()] : ";
        std::cout << b[b.size()] << E;
	} catch (std::exception &e) { std::cout << ERROR << e.what() << E; }
    std::cout << E;
    return(0);
}
