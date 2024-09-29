/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/28 00:21:30 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    private:
        bool    gate_keeper_mode;
        void    scav_init();
        
    public:
        ScavTrap();
        explicit    ScavTrap(const std::string &in_name);
        explicit    ScavTrap(const ScavTrap &copy);
        ScavTrap&   operator=(const ScavTrap &copy);
        ~ScavTrap();

        void attack(const std::string &target);
        void guardGate();
};

#endif

