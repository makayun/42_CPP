/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:06:02 by mmakegon          #+#    #+#             */
/*   Updated: 2024/10/07 14:12:26 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		explicit	Cure(const Cure &copy);
		Cure&		operator=(const Cure &copy);
		~Cure(void);

		void		use(ICharacter& target);
		Cure*		clone(void)const;
};
