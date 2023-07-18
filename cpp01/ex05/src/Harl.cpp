/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:42:42 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 16:21:25 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_debug_texts[0] = "Can't you do an exception for a single mother!?";
	_debug_texts[1] = "But, that doesn't apply to me!";
	_debug_texts[2] = "Do you know how much money I spend here every month?!";
	_debug_texts[3] = "Do you live in this area?!";
	
	_info_texts[0] = "My name is misspelled on the cup!";
	_info_texts[1] = "I've been discriminated against!";

	_warning_texts[0] = "I want to speak to your manager!";
	_warning_texts[1] = "I want to talk to the owner!";


	_error_texts[0] = "This is unacceptable! I want to speak to the manager now.";
	_error_texts[1] = "You ruined my family's entire vacation!";
	_error_texts[2] = "You just lost our business!";

	std::srand(std::time(0));
}


void Harl::complain(std::string level) {
	std::string lvl[4] = { "DEBUG","INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++){
		if(lvl[i] == level)
		{
			(this->*(ptr[i]))();
			return;
		}
	}
}

void Harl::debug() {
	std::cout << T_DEBUG << _debug_texts[std::rand() % 4] << R << "\n";
}
void Harl::info() {
	std::cout << BLUE << _info_texts[std::rand() % 2] << R << "\n";
}
void Harl::warning() {
	std::cout << BASE_T << "214m" << _warning_texts[std::rand() % 2] << R << "\n";
}
void Harl::error() {
	std::cout << RED << _error_texts[std::rand() % 3] << R << "\n";
}

Harl::~Harl(){}