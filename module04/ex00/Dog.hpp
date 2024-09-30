/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:14:37 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:40:42 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

#define DOG_COLOR "\033[1;34m"

#ifndef RES_COLOR
#define RES_COLOR "\033[0m"
#endif

class Dog : public Animal
{
	public:
		Dog();
		explicit	Dog(const Dog &copy);
		Dog&		operator=(const Dog &copy);
		virtual		~Dog();

		void	makeSound(void) const;
};

#endif
