/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:04:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 15:58:24 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
  public:
	Zombie();
	~Zombie();
	void announce( void );
	void setName( std::string name );
  private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
