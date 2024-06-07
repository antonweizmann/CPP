/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:08 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/07 13:35:22 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde (int N, std::string name);

int	main()
{
	Zombie *testZombie;
	int		N = 5;
	testZombie = zombieHorde(N, "Amber");
	for (int i = 0; i < N; i++)
		testZombie[i].announce();
	delete []testZombie;
}
