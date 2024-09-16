/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:33:26 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:04 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define ERROR   -1
#define ALL_FINE 1

#define MAX_FIELDS 5

enum e_field_type
{
	FIRST_NAME,
	SECOND_NAME,
	NICKNAME,
	PHONE_NUM,
	SECRET
};

class Contact
{
	private:
		std::string field[MAX_FIELDS];

	public:
		Contact();
		~Contact();

		int			set_field(int type, std::string field);
		std::string	get_field(int type) const;
};

#endif
