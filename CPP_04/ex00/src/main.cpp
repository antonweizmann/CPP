/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:00:23 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/19 16:17:42 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// const WrongAnimal* wrong = new WrongAnimal();
	// const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	// std::cout << wrong->getType() << " " << std::endl;
	// std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// std::cout << std::endl;
	// wrong->makeSound();
	// wrongCat->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	// delete wrong;
	// delete wrongCat;
	return 0;
}
