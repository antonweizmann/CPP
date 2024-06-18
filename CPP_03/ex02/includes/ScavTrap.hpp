/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:32:42 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/18 17:10:28 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
			void	attack(const std::string& target);
			ScavTrap(std::string& name);
			~ScavTrap();
			ScavTrap();
			ScavTrap(const ScavTrap& src);
			ScavTrap& operator=(const ScavTrap& src);
			void	guardGate(void);
};

#endif
