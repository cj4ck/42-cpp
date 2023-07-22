/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:20:43 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/20 19:14:47 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <unistd.h>

template <typename T> 
void display(T const & elem, T const & nextElem, int color) {
	int colorCodes[] = {196, 202, 208, 154, 51, 21, 129};
	// int colorCodes[] = {159, 159, 195, 195, 195, 231, 159};
	int colorCode = colorCodes[color % 7];
	std::cout << "\033[38;5;" << colorCode << "m" << elem << " + " << nextElem << " = " << elem + nextElem << "\033[0m" << std::endl;
	usleep(50000);
}

template <typename T>
void iter(T *tab, size_t len, void (*fct)(T const & elem, T const & nextElem, int color)) {
	for (size_t i = 0; i < len - 1; i++) {
		fct(tab[i], tab[i+1], i);
	}
}



template <typename T>
void generateFibonacci(T* array, size_t len) {
	if (len > 0) array[0] = 0;
	if (len > 1) array[1] = 1;
	for (size_t i = 2; i < len; i++) {
		array[i] = array[i - 1] + array[i - 2];
	}
}
