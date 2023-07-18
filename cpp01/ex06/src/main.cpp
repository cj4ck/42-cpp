/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:40:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 16:43:55 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl harl;
	std::string tab_of_levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	
	if(ac != 2){
		std::cout << INFO << "Correct input: ./harlFilter \"filter level\"" << std::endl;
		return (1);
	}
	//Start conversation
	for (int i = 0; i < 10 ; i++)
	{
		harl.complain( tab_of_levels[std::rand() % 4], av[1]);
	}
	return (0);
}