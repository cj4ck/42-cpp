/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:27:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 19:49:05 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Data {
  public :
	Data(Data const & src);
	Data(std::string const & str);
	Data & operator=(Data const & rhs);
	~Data();
	std::string _str;
  private :
	Data();
};

std::ostream & operator<<(std::ostream & ostream, const Data &src);
