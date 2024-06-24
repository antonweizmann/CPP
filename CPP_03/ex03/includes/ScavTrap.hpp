/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:32:42 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/19 11:38:05 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
			void	attack(const std::string& target);
			ScavTrap(std::string name);
			~ScavTrap();
			ScavTrap();
			ScavTrap(const ScavTrap& src);
			ScavTrap& operator=(const ScavTrap& src);
			void	guardGate(void);
};

#endif
