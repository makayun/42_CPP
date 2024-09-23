/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:39:42 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/22 01:56:22 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int                 value;
        static const int    fractional_bits = 8;
        
    public:
        Fixed();
        Fixed( const Fixed &copy);  
        Fixed& operator= ( const Fixed &copy );
        ~Fixed();

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif
