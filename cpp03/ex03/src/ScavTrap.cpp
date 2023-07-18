/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:18:34 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/14 16:37:48 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() {std::cout << SYS_MSG_CON << "ScavTrap Default constructor" << G << " called" << E;}

ScavTrap::ScavTrap(std::string name) :  ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hp	= base_hp;
	this->_ep 	= base_ep;
	this->_ad 	= base_ad;
	std::cout << SYS_MSG_CON << "ScavTrap Copy constructor " << G << "called " << SYS << _name << E;
}

ScavTrap::ScavTrap(const ScavTrap& src) {
	this->_name = src.getName();
	this->_ad 	= src.getAD();
	this->_ep 	= src.getEP();
	this->_hp 	= src.getHP();
	std::cout << SYS_MSG_CON << "ScavTrap Copy constructor " << G << "called " << SYS << _name << E;
}

ScavTrap::~ScavTrap() {std::cout << SYS_MSG_DES << "ScavTrap Destructor " << G << "called " << SYS << _name << E;}

ScavTrap&	ScavTrap::operator=(ScavTrap const &src) {
	this->_name = src.getName();
	this->_ad 	= src.getAD();
	this->_ep 	= src.getEP();
	this->_hp 	= src.getHP();
	std::cout << SYS_MSG_CON << "ScavTrap Asign operator " << G << "called from " << SYS << _name << E;
	return(*this);
}

void	ScavTrap::attack(const std::string& target) {
		clap_trap_h();
		if (_hp < 1) {
			std::cout << "\t\t\t "<< INFO << _name << G << " ScavTrap is dead therefore he can't attack anymore 💀... " << E;
			if(_name == "Joe")
				a_dead();
			else
				b_dead();
		}
		else if (_ep < base_ep_cost) {
			std::cout << "\t\t\t "<< INFO << _name << BASE_T << "11m" << " ScavTrap energy level is too low, to attack ⚡️ ... " << E;
			robots_animation();
		}
		else {
			this->_ep -= base_ep_cost;
			std::cout << "\t\t\t "<< INFO << _name <<  " ScavTrap is attacking " << target << " causing " << this->_ad << " dmg" << E;
			animation(_name, "attack");
		}
		return;
}

void ScavTrap::guardGate() {
	clap_trap_h();
	std::cout << "\t\t\t "<< INFO << _name << BASE_T << "11m" << " ScavTrap is now in Gate keeper mode.🚪" << E;
	robots_animation();
	sleep(2);
}
