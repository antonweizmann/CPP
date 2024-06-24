/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:00:30 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/19 11:37:57 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
			std::string _name;
	public:
			DiamondTrap();
			DiamondTrap(std::string name);
			~DiamondTrap();
			DiamondTrap(const DiamondTrap& src);
			DiamondTrap& operator=(const DiamondTrap& src);
			using	ScavTrap::attack;
			void whoAmI();
};

#endif
