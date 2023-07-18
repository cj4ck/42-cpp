/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 16:16:57 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Harl.hpp"

int	main() {
	Harl harl;
	std::string tab_of_levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	
	//Start conversation
	for (int i = 0; i < 10 ; i++)
	{
		harl.complain( tab_of_levels[std::rand() % 4]);
	}
	return (0);
}