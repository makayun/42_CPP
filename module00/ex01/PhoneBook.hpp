/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:33:15 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/13 18:16:17 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		std::array<Contact, 8>	book;
		int						contacts_total;

	public:
		PhoneBook();
		~PhoneBook();

		int	add_contact(void);
		int	search(void);
		int	print_head(void);
		int	print_contact(int id);
		int	print_book(void);
};

#endif
