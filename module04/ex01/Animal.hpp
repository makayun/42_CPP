/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:28:28 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/01 23:57:41 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define ANML_COLOR "\033[1;32m"

#ifndef RES_COLOR
#define RES_COLOR "\033[0m"
#endif

class Animal
{
	protected:
		Brain		*brain;
		std::string	type;
		void		growBrain(void);

	public:
		Animal();
		explicit			Animal(const std::string &in_type);
		explicit			Animal(const Animal &copy);
		Animal&				operator=(const Animal &copy);
		virtual				~Animal();

		virtual void		makeSound(void) const;
		const std::string	getType(void) const;

		Brain* 				findBrain(void);
		const std::string	getIdea(size_t id) const;
		void				setIdea(const std::string &in_idea, size_t id);
};

#endif
