/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:37:23 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 08:24:52 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include "Colors.hpp"

template<typename T>
void easyfind(T &a, int len) {
	typename T::iterator it = std::find(a.begin(), a.end(), len);
	if (it != a.end())
		std::cout << SYS_MSG << GREEN << "Element found at position " << std::distance(a.begin(), it) << E;
	else {
		std::cout << SYS_MSG << RED << "Element not found" << E;
		throw std::exception();
	}
}
