/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:08:51 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/26 15:10:55 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/26 13:51:55 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{       
    public:
        explicit FragTrap(const std::string &in_name);
        FragTrap(const FragTrap &copy);
        FragTrap& operator=(const FragTrap &copy);
        ~FragTrap();

        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif

