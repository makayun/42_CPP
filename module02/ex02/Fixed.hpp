/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:39:42 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/23 09:15:47 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                 value;
        static const int    fractional_bits = 8;
        
    public:
    // Constructors
        Fixed( void );
        Fixed( const Fixed &copy);
        explicit Fixed( const int input );
        explicit Fixed( const float input);
        ~Fixed();

    // Copy assignment operator overload
        Fixed & operator= ( const Fixed &copy );

    // Comparison operators
        Fixed & operator>  ( const Fixed &to_compare );
        Fixed & operator<  ( const Fixed &to_compare );
        Fixed & operator>= ( const Fixed &to_compare );
        Fixed & operator<= ( const Fixed &to_compare );
        Fixed & operator== ( const Fixed &to_compare );
        Fixed & operator!= ( const Fixed &to_compare );

    // Arithmetic operators
        Fixed & operator+ ( const Fixed &)

        float   toFloat( void ) const;
        int     toInt( void ) const;
        
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

std::ostream &operator<<( std::ostream &out, Fixed const &in );

#endif