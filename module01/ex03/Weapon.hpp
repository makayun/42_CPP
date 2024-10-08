/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:55:19 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 12:43:01 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon ( void );
		explicit Weapon ( const std::string &in_type );
		~Weapon( void );

		const std::string	&getType ( void ) const;
		int					setType (const std::string &new_type);

};

#endif
