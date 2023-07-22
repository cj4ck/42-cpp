/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:27:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 21:06:53 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Data {
  public :
	Data();
	Data(Data const & str);
	Data & operator=(Data const & rhs);
	~Data();
	std::string intraName;
	// uintptr_t	test = UINTPTR_MAX;
};

std::ostream & operator<<(std::ostream & ostream, const Data &src);
