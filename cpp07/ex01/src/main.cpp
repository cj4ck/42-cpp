/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:21:08 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/20 09:20:48 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include "../inc/Colors.hpp"
#include <functional>

int main() {
	const size_t len = 77;
	unsigned long int fib[len];

	generateFibonacci(fib, len);
	while(1) {
		iter(fib, len, display<unsigned long int>);
		system("clear");
		system("make");
	}
	return 0;
}
