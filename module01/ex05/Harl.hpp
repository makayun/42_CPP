/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:41:36 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 15:15:02 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define MAX_HARL_LEVEL 4

class Harl {
	private:
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
		void		wrong_input( void );
		void		(Harl::*funcArray[MAX_HARL_LEVEL + 1])();
		std::string levels[MAX_HARL_LEVEL];

	public:
		Harl();
		~Harl();

		void	complain( std::string level );
		void	complain( const char *c_style_level );
};

#endif
