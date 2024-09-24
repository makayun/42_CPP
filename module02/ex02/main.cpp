/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:09:28 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/24 11:49:45 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	{
        Fixed       a;
        const Fixed b (12.34f);

        std::cout   << "a = " << a << "\n"
                    << "b = " << b << "\n"
                    << "a = a + b\n"
                    << "a = " << (a = a + b) << "\n"
                    << std::endl;

        Fixed   c(43.21f);
        Fixed   d(a - b);
        
        std::cout   << "c = " << c << "\n"
                    << "d = a - b\n"
                    << "d = " << d << "\n"
                    << "c * d = " << (c * d) << "\n"
                    << "c / d = " << (c / d) << "\n"
                    << std::endl;
    }

    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        
        std::cout   << "a   = " << a << std::endl;
        std::cout   << "++a = " << ++a << std::endl;
        std::cout   << "a   = " << a << "\n"
                    << "a++ = " << a++ << "\n"
                    << "a   = " << a << "\n"
                    << std::endl;

        std::cout   << "b   = " << b << "\n"
                    << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
    }
    
	return (0);
}
