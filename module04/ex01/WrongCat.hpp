/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:08:01 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:13:01 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

#define WRC_COLOR "\033[1;33m"

#ifndef RES_COLOR
#define RES_COLOR "\033[0m"
#endif

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		explicit	WrongCat(const WrongCat &copy);
		WrongCat&	operator=(const WrongCat &copy);
		virtual		~WrongCat();

		void		makeSound(void) const;
};

#endif
