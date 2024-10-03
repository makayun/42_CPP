/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:39:56 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 13:14:51 by mmakegon         ###   ########.fr       */
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
		~Cat();

		void		makeSound(void) const;
};

#endif
