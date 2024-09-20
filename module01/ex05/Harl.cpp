/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:41:39 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 14:41:39 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    this->funcArray[0] = &Harl::debug;
    this->funcArray[1] = &Harl::info;
    this->funcArray[2] = &Harl::warning;
    this->funcArray[3] = &Harl::error;
    this->funcArray[4] = &Harl::wrong_input;

    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
}

Harl::~Harl() {
}

void Harl::debug( void ) {
    std::cout   << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
                << std::endl;
}

void Harl::info( void ) {
    std::cout   << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
                << std::endl;
}

void Harl::warning( void ) {
    std::cout   <<  "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
                << std::endl;
}

void Harl::error( void ) {
    std::cout   << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}

void Harl::wrong_input( void )
{
    std::cout   << "Oh, now you're mumbling some noncense..."
                << std::endl;
}

void Harl::complain( std::string level )
{
    int i = 0;

    while (i < MAX_HARL_LEVEL && this->levels[i].compare(level))
        i++;
    (this->*funcArray[i])();
}
