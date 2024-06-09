/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:55:14 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/09 13:56:14 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl harl_test;

	harl_test.complain("DEBUG");
	harl_test.complain("INFO");
	harl_test.complain("WARNING");
	harl_test.complain("ERROR");
}
