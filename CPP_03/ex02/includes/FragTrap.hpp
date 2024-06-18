/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:32:42 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/18 17:14:17 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
			void	attack(const std::string& target);
			FragTrap(std::string& name);
			~FragTrap();
			FragTrap();
			FragTrap(const FragTrap& src);
			FragTrap& operator=(const FragTrap& src);
			void	highFivesGuys(void);
};

#endif
