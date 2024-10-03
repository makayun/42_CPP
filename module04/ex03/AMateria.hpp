/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:30:35 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/03 13:41:52 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	private:

	protected:

	public:
		AMateria();
		explicit    AMateria(const AMateria &copy);
		AMateria&    operator=(const AMateria &copy);
		~AMateria();
};

#endif
