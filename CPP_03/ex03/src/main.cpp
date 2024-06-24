/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:03:56 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/19 11:36:55 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::string s= "ClpA";
	DiamondTrap	hehe(s);

	for (int i = 0; i < 12; i++)
	{
		hehe.attack("tatatarget");
	}
	hehe.beRepaired(21);
	hehe.highFivesGuys();
	hehe.whoAmI();
	return (0);
}
