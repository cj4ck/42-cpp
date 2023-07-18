/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:18:34 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/14 16:20:03 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() {std::cout << SYS_MSG_CON << "FragTrap Default constructor" << G << " called" << E;}

FragTrap::FragTrap(std::string name) :  ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hp	= base_hp;
	this->_ep 	= base_ep;
	this->_ad 	= base_ad;
	std::cout << SYS_MSG_CON << "FragTrap Copy constructor " << G << "called " << SYS << _name << E;
}

FragTrap::FragTrap(const FragTrap& src) {
	this->_name = src.getName();
	this->_ad 	= src.getAD();
	this->_ep 	= src.getEP();
	this->_hp 	= src.getHP();
	std::cout << SYS_MSG_CON << "FragTrap Copy constructor " << G << "called " << SYS << _name << E;
}

FragTrap::~FragTrap() {std::cout << SYS_MSG_DES << "FragTrap Destructor " << G << "called " << SYS << _name << E;}

FragTrap&	FragTrap::operator=(FragTrap const &src) {
	this->_name = src.getName();
	this->_ad 	= src.getAD();
	this->_ep 	= src.getEP();
	this->_hp 	= src.getHP();
	std::cout << SYS_MSG_CON << "FragTrap Asign operator " << G << "called from " << SYS << _name << E;
	return(*this);
}

void FragTrap::highFivesGuys(){
	clap_trap_h();
	std::cout << "\t\t\t "<< INFO << _name <<  " is giving high five ✋ " << E;
	robots_animation();
}
