/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:39:56 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:40:38 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

#define CAT_COLOR "\033[1;35m"

#ifndef RES_COLOR
#define RES_COLOR "\033[0m"
#endif

class Cat : public Animal
{
	public:
		Cat();
		explicit	Cat(const Cat &copy);
		Cat&		operator=(const Cat &copy);
		virtual		~Cat();

		void		makeSound(void) const;
};

#endif
