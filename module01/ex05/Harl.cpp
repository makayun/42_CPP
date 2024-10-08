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
    funcArray[0] = &Harl::debug;
    funcArray[1] = &Harl::info;
    funcArray[2] = &Harl::warning;
    funcArray[3] = &Harl::error;
    funcArray[MAX_HARL_LEVEL] = &Harl::wrong_input;

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
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

void Harl::complain( const char *c_style_level )
{
    std::cout << "\001\033[36m\002";

    if (c_style_level == NULL)
        std::cout << "Don't you try to make me angry!" << std::endl;
    else
        Harl::complain(std::string(c_style_level));

    std::cout << "\001\033[0m\002";
}
