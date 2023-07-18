/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:04:37 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 15:59:39 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define N 10

int main(void) {
	Zombie	*horde = zombieHorde(N, "zombie");
	for(int	i = 0; i < N; i++){
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
