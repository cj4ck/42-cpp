/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:38:17 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 16:40:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "colors.h"

class Harl {
  public:
	Harl();
	~Harl();
	void complain(std::string level, std::string filter);

  private:
  	std::string _debug_texts[4];
	std::string _info_texts[2];
	std::string _warning_texts[2];
	std::string _error_texts[3];
	void debug();
	void info();
	void warning();
	void error();
};

