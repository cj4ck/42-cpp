/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:22 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/03 19:26:58 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if(argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for(int i = 1; i < argc; i++){
			int l = 0;
			while(argv[i][l] && argv[i][l] == ' ')
				l++;
			while(argv[i][l]){
				while(argv[i][l] && argv[i][l] != ' ')
					std::cout << (char)toupper(argv[i][l++]);
				while(argv[i][l] && argv[i][l] == ' ')
					l++;
				if(argv[i][l])
					std::cout << " ";
			}
		if(i + 1 < argc)
			std::cout << " ";
		}
	}

	std::cout << "\n";
	return 0;
}

