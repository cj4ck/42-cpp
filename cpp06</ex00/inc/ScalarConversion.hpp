/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:00:45 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 16:49:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits.h>
#include <sstream>

#include "Colors.hpp"

class ScalarConversion {
  public :
	static void convert(const std::string & literal);
	static bool checkOverflow(const std::string & literal);
  private :
	ScalarConversion();
	~ScalarConversion();
	ScalarConversion(const ScalarConversion & obj);
	ScalarConversion & operator=(const ScalarConversion & rhs);
};
