/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:55:19 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/18 01:32:11 by mmakagon         ###   ########.fr       */
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
		int					setType (std::string new_type);

};

#endif
