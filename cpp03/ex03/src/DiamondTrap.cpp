/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:18:34 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/14 16:45:51 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {std::cout << SYS_MSG_CON << "DiamondTrap Default constructor" << G << " called" << E;}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav"), FragTrap(name + "_frag") {
	this->_name = name;
	FragTrap::_hp = 100;
	ScavTrap::_ep = 50;
	FragTrap::_ad = 30;

	std::cout << SYS_MSG_CON << "DiamondTrap constructor " << G << "called " << SYS << _name << E;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) {
	this->_name = src.getName();
	this->_ad 	= src.getAD();
	this->_ep 	= src.getEP();
	this->_hp 	= src.getHP();
	std::cout << SYS_MSG_CON << "DiamondTrap Copy constructor " << G << "called " << SYS << _name << E;
}

DiamondTrap::~DiamondTrap() {std::cout << SYS_MSG_DES << "DiamondTrap Destructor " << G << "called " << SYS << _name << E;}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &src) {
	this->_name = src.getName();
	this->_ad 	= src.getAD();
	this->_ep 	= src.getEP();
	this->_hp 	= src.getHP();
	std::cout << SYS_MSG_CON << "DiamondTrap Asign operator " << G << "called from " << SYS << _name << E;
	return(*this);
}

void DiamondTrap::whoAmI() {std::cout << "\t " << SYS_MSG <<  " My DiamondTrap name is " << _name << ", my ClapTrap name is " << ClapTrap::getName() << E;}
