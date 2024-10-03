/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:39:22 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/03 13:42:23 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	private:

	protected:

	public:
		ICharacter();
		explicit    ICharacter(const ICharacter &copy);
		ICharacter&    operator=(const ICharacter &copy);
		~ICharacter();
};

#endif
