/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:27:50 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/13 20:51:25 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#include <unistd.h>
#include <chrono>
#include <thread>

#include "colors.h"
#include "animations.hpp"

#define base_hp 10
#define base_ep 10
#define base_ad 0
#define base_ep_cost 1

class ClapTrap {
  public:
				ClapTrap();
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap& src);
				~ClapTrap();
	ClapTrap&	operator=(ClapTrap const &src);

	void		attack(const std::string& target);
	void		takeDamage(const unsigned int amount);
	void		beRepaired(const unsigned int amount);

	int			getHP() const;
	int			getEP() const;
	int			getAD() const;
	std::string	getName() const;

  private:
	int			_hp;
	int			_ep;
	int			_ad;
	std::string	_name;
};

void	animation(std::string robot, std::string action);
