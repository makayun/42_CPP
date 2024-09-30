/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:54:48 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/30 14:18:07 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int input ) : value(input << fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float input ) : value(roundf(input * (1 << fractional_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator= ( const Fixed &copy )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->setRawBits(copy.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (this->value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float   Fixed::toFloat( void ) const
{
    return static_cast<float>( this->value ) / ( 1 << fractional_bits );
}

int     Fixed::toInt( void ) const
{
    return this->value >> fractional_bits;
}

std::ostream& operator<<( std::ostream& out, const Fixed& in)
{
    out << in.toFloat();
    return (out);
}
