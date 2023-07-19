/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:47 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 21:07:14 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/Data.hpp"

//! --- DISCLAIMER --- 
//! `uintptr_t` is present in -std=c++11...
//! change `uintptr_t` to `char` to really understand what is happening there!

#include <iostream>

uintptr_t serialize(Data* data) {
    return reinterpret_cast<uintptr_t>(data);
}

Data* deserialize(uintptr_t data) {
    return reinterpret_cast<Data*>(data);
}

int main() {
    Data* data;
    uintptr_t rawData;
    Data* retData;

    data = new Data;
    data->intraName = "cjackows";

    std::cout << "Data ptr             : " << GREEN << data << E;
    std::cout << "Data                 : " << BLUE << *data << E;
    rawData = serialize(data);
    std::cout << "Serialized data ptr  : " << BLUE << rawData << E;
    retData = deserialize(rawData);
    std::cout << "Deserialized data ptr: " << GREEN << retData << E;

    if (data == retData) {
    	std::cout << "Deserialized data    : " << BLUE << *retData << E;	
        std::cout << SYS_MSG << GREEN << "Deserialized pointer matches the original pointer." << E;
	}
	else {
    	// std::cout << "Deserialized data    : " << BLUE << *retData << E; !data loss with char
        std::cout << SYS_MSG << RED << "Deserialized pointer don't matches the original pointer!" << E;
	}

    if (data)
		delete data;
    return 0;
}
