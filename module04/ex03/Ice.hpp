/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:36:32 by mmakegon          #+#    #+#             */
/*   Updated: 2024/10/07 13:06:28 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"


class Ice : public AMateria
{
	public:
		Ice(void);
		explicit	Ice(const Ice &copy);
		Ice&		operator=(const Ice &copy);
		~Ice(void);

		void		use(ICharacter& target);
		Ice*		clone(void)const;
};

#endif
