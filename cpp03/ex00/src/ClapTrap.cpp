/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:32:37 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/13 20:55:16 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << SYS_MSG_CON << "Default constructor" << G << " called" << E;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << SYS_MSG_CON << "Constructor " << G << "called for " << SYS << name << E;
	this->_hp = base_hp;
	this->_ep = base_ep;
	this->_ad = base_ad;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_ad = src._ad;
	std::cout << SYS_MSG_CON << "Copy constructor " << G << "called " << SYS << _name << E;
}

ClapTrap::~ClapTrap() {
	std::cout << SYS_MSG_DES << "Destructor " << G << "called " << SYS << _name << E;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &src) {
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_ad = src._ad;
	std::cout << SYS_MSG_CON << "Asign operator " << G << "called from " << SYS << _name << E;
	return(*this);
}

void	ClapTrap::attack(const std::string& target) {
		clap_trap_h();
		if (_hp < 1) {
			std::cout << "\t\t\t "<< INFO << _name << G << " is dead therefore he can't attack anymore 💀... " << E;
			if(_name == "Joe")
				a_dead();
			else
				b_dead();
		}
		else if (_ep < base_ep_cost) {
			std::cout << "\t\t\t "<< INFO << _name << BASE_T << "11m" << " energy level is too low, to attack ⚡️ ... " << E;
			robots_animation();
		}
		else {
			this->_ep -= base_ep_cost;
			std::cout << "\t\t\t "<< INFO << _name <<  " is attacking " << target << " causing " << this->_ad << " dmg" << E;
			animation(_name, "attack");
		}
		return;
}

void	ClapTrap::takeDamage(const unsigned int amount) {
		clap_trap_h();
		if (_hp < 1) {
			std::cout << "\t\t\t "<< INFO << _name << G <<  " is dead therefore he can't take any more dmg 💀 ... " << E;
			if(_name == "Joe")
				a_dead();
			else
				b_dead();
		}
		else {
			_hp -= amount;
			std::cout << "\t\t\t "<< INFO << _name << RED <<  " Has been slain 🔪" << E;
			if(_name == "Joe")
				a_dead();
			else
				b_dead();
		}
		return;
}

void	ClapTrap::beRepaired(const unsigned int amount) {
		clap_trap_h();
		if (_hp < 1) {
			std::cout << "\t\t\t "<< INFO << _name << G << " is dead therefore he can't repair himself 💀 ... " << E;
			if(_name == "Joe")
				a_dead();
			else
				b_dead();
		}
		else if (_ep < base_ep_cost) {
			std::cout << "\t\t\t "<< INFO << _name << BASE_T << "11m"  " energy level is too low, to repair himself ⚡️ ... " << E;
			robots_animation();
		}
		else {
			this->_ep -= base_ep_cost;
			this->_hp += amount;
			std::cout << "\t\t\t "<< INFO << _name <<  " is repairing itsef" << E;
			animation(_name, "repair");
		}
		return;
}

int			ClapTrap::getHP() const { return(_hp); }
int			ClapTrap::getEP() const { return(_ep); }
int			ClapTrap::getAD() const { return(_ad); }
std::string	ClapTrap::getName() const { return(_name); }

void	animation(std::string robot, std::string action) {
    for (int i = 0; i <= 5; ++i) {
		if(robot == "Joe") {
			if(action == "attack")
				attack_b_animation();
			else if (action == "repair")
				repair_b_animation();
		}
		else {
			if(action == "attack")
				attack_a_animation();
			else if (action == "repair")
				repair_a_animation();
		}
		std::cout << "\033[19A";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
		robots_animation();
		std::cout << "\033[19A";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	robots_animation();
}
