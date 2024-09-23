/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:39:42 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/23 15:38:16 by mmakagon         ###   ########.fr       */
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
        bool operator>  ( const Fixed &to_compare ) const;
        bool operator<  ( const Fixed &to_compare ) const;
        bool operator>= ( const Fixed &to_compare ) const;
        bool operator<= ( const Fixed &to_compare ) const;
        bool operator== ( const Fixed &to_compare ) const;
        bool operator!= ( const Fixed &to_compare ) const;

    // Arithmetic operators
        Fixed &operator+ ( const Fixed &second_number );
		Fixed &operator- ( const Fixed &second_number );
		Fixed &operator* ( const Fixed &second_number );
		Fixed &operator/ ( const Fixed &second_number );

        float   toFloat( void ) const;
        int     toInt( void ) const;

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

std::ostream &operator<<( std::ostream &out, Fixed const &in );

#endif
