/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:09 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/24 13:45:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string in_name ) : name(in_name) {
	std::cout	<< "A trap known as "
				<< name
				<< "is setted"
				<< std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy ) {
	*this = copy;
}

ClapTrap &ClapTrap::operator= ( const ClapTrap &copy ) {
	if (this != &copy) {
		hit_p = copy.get_hp();
	}
}
