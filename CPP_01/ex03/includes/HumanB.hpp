/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:10:51 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/07 15:03:07 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
			std::string	_name;
			Weapon		*_weapon;
	public:
			HumanB(std::string name);
			~HumanB();
			void	attack();
			void	setWeapon(Weapon &weapon);
};
#endif
