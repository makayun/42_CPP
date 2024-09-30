/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:28:28 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 15:22:20 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		explicit	Animal(const std::string &in_type);
		explicit	Animal(const Animal &copy);
		Animal&		operator=(const Animal &copy);
		virtual		~Animal();

		virtual void		makeSound(void) const;
};

#endif
