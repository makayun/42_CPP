/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:07:53 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:08:54 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define WRA_COLOR "\033[1;31m"

#ifndef RES_COLOR
#define RES_COLOR "\033[0m"
#endif

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		explicit	WrongAnimal(const std::string &in_type);
		explicit	WrongAnimal(const WrongAnimal &copy);
		WrongAnimal&		operator=(const WrongAnimal &copy);
		virtual		~WrongAnimal();

		virtual void		makeSound(void) const;
		const std::string	getType(void) const;
};

#endif
