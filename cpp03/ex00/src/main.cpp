/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/13 20:53:14 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

void boot_animation();

int	main() {
//!System tests
	// ClapTrap a("Joe");
	// ClapTrap b("Rob");
	// ClapTrap c(a);
	// ClapTrap e;
	// e = c;

// boot_animation();
	ClapTrap a("Joe");
	ClapTrap b("Rob");
	while(a.getHP() != 0 || b.getHP() != 0){
		a.attack(b.getName());
		b.attack(a.getName());
	}

//!robot is dead after attack (#define base_hp 10#define base_ep 10#define base_ad 10#define base_ep_cost 1)
	// b.attack(a.getName());
	// a.takeDamage(b.getAD());
	// sleep(2);
	// a.attack(b.getName()); //try to attack being dead
	// sleep(2);
	// a.takeDamage(b.getAD()); //try to take dmg after being dead
	// sleep(2);
	// a.beRepaired(100);

	// a.attack(b.getName());
	// b.takeDamage(a.getAD());
	// sleep(2);
	// b.attack(a.getName()); //try to attack being dead
	// sleep(2);
	// b.takeDamage(a.getAD()); //try to take dmg after being dead
	// sleep(2);
	// b.beRepaired(100);

//!robots are too tired to do anything (#define base_hp 10#define base_ep 10#define base_ad 10#define base_ep_cost 5)
	// a.beRepaired(0);
	// sleep(2);
	// b.beRepaired(0);
	// sleep(2);
	// a.attack(b.getName());
	// sleep(2);
	// b.attack(a.getName());
	// a.beRepaired(0);
	// sleep(2);
	// b.beRepaired(0);
	// sleep(2);
	// a.attack(b.getName());
	// sleep(2);
	// b.attack(a.getName());
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
