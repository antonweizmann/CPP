/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:32:42 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:00 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
			std::string		_name;
			unsigned int	_health;
			unsigned int	_energy;
			unsigned int	_attack;
	public:
			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
			ClapTrap(std::string& name);
			~ClapTrap();
			ClapTrap();
			ClapTrap(const ClapTrap& src);
			ClapTrap& operator=(const ClapTrap& src);
};

#endif
