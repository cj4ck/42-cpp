/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/14 16:46:20 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

void boot_animation();

int	main() {
// !System tests
	DiamondTrap a("Joe");
	DiamondTrap b("Rob");
	std::cout << "\t "<< SYS_MSG << a.getName() << " DiamondTrap ClapTrap name: "<< a.ClapTrap::getName() << E;
	std::cout << "\t "<< SYS_MSG << a.getName() << " DiamondTrap name: "<< a.getName() << E;
	std::cout << "\t "<< SYS_MSG << a.getName() << " DiamondTrap HP: "<< a.getHP() << E;
	std::cout << "\t "<< SYS_MSG << a.getName() << " DiamondTrap EP: "<< a.getEP() << E;
	std::cout << "\t "<< SYS_MSG << a.getName() << " DiamondTrap AD: "<< a.getAD() << E << E;

	std::cout << "\t "<< SYS_MSG << a.FragTrap::getName() << " FragTrap ClapTrap name: "<< a.FragTrap::ClapTrap::getName() << E;
	std::cout << "\t "<< SYS_MSG << a.FragTrap::getName() << " FragTrap name: "<< a.FragTrap::getName() << E;
	std::cout << "\t "<< SYS_MSG << a.FragTrap::getName() << " FragTrap HP: "<< a.FragTrap::getHP() << E;
	std::cout << "\t "<< SYS_MSG << a.FragTrap::getName() << " FragTrap EP: "<< a.FragTrap::getEP() << E;
	std::cout << "\t "<< SYS_MSG << a.FragTrap::getName() << " FragTrap AD: "<< a.FragTrap::getAD() << E << E;

	std::cout << "\t "<< SYS_MSG << a.ScavTrap::getName() << " ScavTrap ClapTrap name: "<< a.ScavTrap::ClapTrap::getName() << E;
	std::cout << "\t "<< SYS_MSG << a.ScavTrap::getName() << " ScavTrap name: "<< a.ScavTrap::getName() << E;
	std::cout << "\t "<< SYS_MSG << a.ScavTrap::getName() << " ScavTrap HP: "<< a.ScavTrap::getHP() << E;
	std::cout << "\t "<< SYS_MSG << a.ScavTrap::getName() << " ScavTrap EP: "<< a.ScavTrap::getEP() << E;
	std::cout << "\t "<< SYS_MSG << a.ScavTrap::getName() << " ScavTrap AD: "<< a.ScavTrap::getAD() << E << E;

	
	a.whoAmI();
	b.whoAmI();
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
