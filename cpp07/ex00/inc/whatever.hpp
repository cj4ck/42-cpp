/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:50:42 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/20 08:03:05 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(const T a, const T b) {
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max(const T a, const T b) {
	if (a > b)
		return (a);
	else
		return (b);
}