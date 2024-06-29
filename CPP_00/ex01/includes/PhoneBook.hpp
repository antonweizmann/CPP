/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:14:35 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/29 14:37:32 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <sstream>
class PhoneBook
{
	private:
			Contact	_contacts[8];
			int		_max_reached;
	public:
			PhoneBook(void);
			~PhoneBook(void);
			void	run_phonebook(void);
			int		fill_contact(int index);
			void	search(void);
};
#endif
