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

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
			std::string type;
	public:
			Animal();
			virtual ~Animal();
			Animal(const Animal& src);
			Animal& operator=(const Animal& src);
			virtual void	makeSound() const = 0;
			std::string getType(void) const;
};

#endif
