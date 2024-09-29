/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 09:47:09 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
    private:
        bool        gate_keeper_mode;
        void        scav_init();

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

