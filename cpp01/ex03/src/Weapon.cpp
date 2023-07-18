/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:08:13 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 16:04:33 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {}
const std::string &Weapon::getType() const {
	return(this->_type);
}

void Weapon::setType(std::string type) {
	_type = type;
}
