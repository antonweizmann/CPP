/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:04:20 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/07 14:31:45 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP


#include <iostream>
#include <string>

class Weapon {
	private:
			std::string	_type;
	public:
			const std::string &getType();
			void	setType(std::string new_type);
			Weapon(std::string type);
			Weapon();
			~Weapon();
};

#endif
