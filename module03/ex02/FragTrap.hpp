/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/28 00:34:39 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
    private:
        void        frag_init();
         
    public:
        FragTrap();
        explicit    FragTrap(const std::string &in_name);
        explicit    FragTrap(const FragTrap &copy);
        FragTrap&   operator=(const FragTrap &copy);
        ~FragTrap();

        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif

