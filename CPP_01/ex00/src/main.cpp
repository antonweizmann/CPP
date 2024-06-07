/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:08 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/07 13:15:23 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int	main()
{
	Zombie *testZombie;

	randomChump("Franky");
	testZombie = newZombie("Peter");
	testZombie->announce();
	delete testZombie;
}
