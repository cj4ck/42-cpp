/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:24:47 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/21 09:20:12 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Colors.hpp"
#include "../inc/Data.hpp"

//! --- DISCLAIMER --- 
//! `int` is present in -std=c++11...
//! change `uintptr_t` to `char` to really understand what is happening there!

#include <iostream>

char serialize(Data* data) {
    return reinterpret_cast<char>(data);
}

Data* deserialize(char data) {
    return reinterpret_cast<Data*>(data);
}

int main() {
    Data* data;
    char rawData;
    Data* retData;

    data = new Data;
    data->intraName = "cjackows";

    std::cout << "Data ptr             : " << GREEN << data << E;
    std::cout << "Data                 : " << BLUE << *data << E;
    rawData = serialize(data);
    std::cout << "Serialized data ptr  : " << BLUE << rawData << E;
    retData = deserialize(rawData);
    std::cout << "Deserialized data ptr: " << GREEN << retData << E;
    	std::cout << "Deserialized data    : " << BLUE << *retData << E;	

    if (data == retData) {
    	std::cout << "Deserialized data    : " << BLUE << *retData << E;	
        std::cout << SYS_MSG << GREEN << "Deserialized pointer matches the original pointer." << E;
	}
	else {
        std::cout << SYS_MSG << RED << "Deserialized pointer don't matches the original pointer!" << E;
    	std::cout << "Deserialized data    : " << BLUE << *retData << E; //!data loss with char
	}

    if (data)
		delete data;
    return 0;
}
git@vogsphere.42wolfsburg.de:vogsphere/intra-uuid-70f7ad01-8b0e-4571-abe7-f37354826072-4977972-cjackowsgit@vogsphere.42wolfsburg.de:vogsphere/intra-uuid-70f7ad01-8b0e-4571-abe7-f37354826072-4977972-cjackows