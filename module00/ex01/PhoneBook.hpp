/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:33:15 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/16 11:23:50 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class	PhoneBook
{
	private:
		Contact	book[MAX_CONTACTS];
		int		contacts_total;
		void	fancy_line(void);
		void	fancy_field(std::string str);
		int		print_head(void);
		int		print_contact(int id);
		int		print_book(void);

	public:
		PhoneBook();
		~PhoneBook();

		int	add_contact(void);
		int	search(void);
};

#endif
