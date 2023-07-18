/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:22 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/04 18:27:10 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "PhoneBook.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void boot_animation();
void display_instructions();

int main()
{

	system("clear");
	std::cout << BASE_T << "236m" << " 🤖 Beep Boop Bup... (static noises)\n" << R;
	// boot_animation();
	std::cout << F << BASE_B << "56m" << ITALIC << BOLD << "   🙋 Welcome " << std::setw(15)<< std::left << std::getenv("LOGNAME") << "\n" << R;
	std::cout << F << BASE_B << "56m" << ITALIC << BOLD << "✨ My Awesome PhoneBook 📖 ✨" << R << "\n\n";

	std::string input;
	PhoneBook phone_book;
	while(1){
		std::cout << F << BASE_B << "56m[◎]" << R << " Please insert an action: ";
		getline(std::cin, input, '\n');
		if(input == "ADD")
			phone_book.add_contact();
		else if(input == "SEARCH")
			phone_book.search_contact();
		else if(input == "EXIT")
		{
			system("clear");
			std::cout << F << BASE_B << "56m" << ITALIC << BOLD << "Bye " << std::getenv("LOGNAME") << "🙋🚪" << R << "\n";
			sleep(1);
			system("clear");
			break;
		}
		else
		{
			std::cout << R << ERROR << "UNKNOWN COMMAND\n" << R;
			display_instructions();
		}
	}
	return 0;
}

void showProgressBar(int progress, int total, int barWidth = 15){
    float ratio = static_cast<float>(progress) / total;
    int completedWidth = static_cast<int>(ratio * barWidth);

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < completedWidth)
            std::cout << PROGRESS_DONE_CHAR;
        // else if (i == completedWidth)
        //     std::cout << ">";
        else
            std::cout << PROGRESS_TODO_CHAR;
    }
    std::cout << "] " << static_cast<int>(ratio * 100.0) << "%\r";
    std::cout.flush();
}

void boot_animation()
{
	sleep(1);
    for (int i = 0; i <= 10; ++i){
		std::cout << BASE_T << "123m" << ITALIC << BOLD << " Booting My Awesome PhoneBook " << R;
        showProgressBar(i, 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "\033[2A\r\033[K\n";
}


void display_instructions()
{
	std::cout << "  ► Insert " << UNDERLINE << "\"ADD\"" << R << " to add a new contact.\n";
	std::cout << "  ► Insert " << UNDERLINE << "\"SEARCH\"" << R << " to search contacts.\n";
	std::cout << "  ► Insert " << UNDERLINE << "\"EXIT\"" << R << " to exit a program.\n\n";
}