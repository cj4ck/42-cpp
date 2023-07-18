/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:28:00 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/06 22:22:20 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon){
	_name = name;
}
// HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {} | const
HumanA::~HumanA() {}
void HumanA::attack() {
	std::cout << BLUE << _name << R << " attacks with their " << RED  << _weapon.getType() << R << std::endl;
}
