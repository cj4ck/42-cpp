/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:52:43 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/08 15:36:26 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "colors.h"

int	replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile) {
		std::cerr << ERROR << "Failed to open input file: " << filename << R << std::endl;
		return 1;
	}

	std::string line, fileContents;
	while (std::getline(inputFile, line)) {
		size_t pos = line.find(s1);
		while (pos != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos = line.find(s1, pos + s2.length());
		}
		fileContents += line + "\n";
	}

	inputFile.close();

	std::string replace = filename + ".replace";
	std::ofstream outputFile(replace.c_str());
	if (!outputFile) {
		std::cerr << ERROR << "Failed to open output file: " << replace << R << std::endl;
		return 1;
	}

	outputFile << fileContents;
	outputFile.close();
	return 0;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << BLUE << "Usage: " << av[0] << " <filename> <s1> <s2>" << R << std::endl;
		return 1;
	}

	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);

	if(replaceStringInFile(filename, s1, s2))
		return 1;
	std::cout << GREEN << "Replacement complete." << std::endl;
	return 0;
}
