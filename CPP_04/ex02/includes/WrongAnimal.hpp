/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:40:12 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/19 15:57:02 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
			std::string type;
	public:
			WrongAnimal();
			virtual ~WrongAnimal();
			WrongAnimal(const WrongAnimal& src);
			WrongAnimal& operator=(const WrongAnimal& src);
			void	makeSound() const;;
			std::string getType(void) const;
};

#endif
