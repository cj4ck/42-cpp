/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/13 21:51:33 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

void boot_animation();

int	main() {
//!System tests
	// ScavTrap a("Joe");
	// ScavTrap b("Rob");
	// ScavTrap c(a);
	// ScavTrap e;
	// e = c;

// boot_animation();
	ScavTrap a("Joe");
	ScavTrap b("Rob");
	b.guardGate();
	while(a.getHP() > 0 || b.getHP() > 0){
		a.attack(b.getName());
		b.takeDamage(a.getAD());
		b.attack(a.getName());
		a.takeDamage(b.getAD());
	}
	return(0);
}


void showProgressBar(int progress, int total, int barWidth = 25){
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
    for (int i = 0; i <= 10; ++i){
   		system("clear");
		clap_trap_h();
		std::cout << "\t\t\t\t\t " << R;
        showProgressBar(i, 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
	system("clear");
	clap_trap_h();
}
