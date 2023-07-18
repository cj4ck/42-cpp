/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:55 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/06 22:22:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon){
	_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << BLUE << _name << R " attacks with their " << RED << _weapon->getType() << R << std::endl;
}