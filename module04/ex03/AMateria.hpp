/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:30:35 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/14 10:28:04 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
		AMateria(void);

	public:
		explicit	AMateria(std::string const & type);
		explicit	AMateria(const AMateria& copy);
		AMateria&	operator=(const AMateria& copy);
		virtual		~AMateria(void);


		std::string const&	getType() const;
		virtual void		use(ICharacter& target);
		virtual AMateria*	clone() const = 0;
		/* "Pure viirtual function",	^^^^
		this class bassically can't use it
		and it should be overwriten in the child class.
		Makes this class an "abstract one".*/

};

#endif
