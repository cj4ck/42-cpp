/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsDateValid.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:18:09 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/23 12:09:21 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

bool isLeapYear(int year) {
    if(year % 4 != 0) 
        return false; 
    else if(year % 100 != 0) 
        return true; 
    else if(year % 400 != 0) 
        return false;
    else 
        return true;
}

bool isMonthValid(int month) {
    return month >= 1 && month <= 12;
}

bool isDayValid(int year, int month, int day) {
    if (day < 1 || day > 31) 
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
        return false;
    if (month == 2) {
        if (isLeapYear(year) && day > 29)
            return false;
        if (!isLeapYear(year) && day > 28)
            return false;
    }
    return true;
}
