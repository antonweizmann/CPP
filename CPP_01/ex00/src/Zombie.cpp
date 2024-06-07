/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:55:30 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/07 13:14:38 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << std::endl;
}

