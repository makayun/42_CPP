/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:54:48 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/23 15:39:46 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int input ) : value(input << fractional_bits)
{
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float input ) : value(roundf(input * (1 << fractional_bits)))
{
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy )
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator overload
Fixed &Fixed::operator= ( const Fixed &copy )
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->setRawBits(copy.getRawBits());
    return *this;
}

// Comparison operators
bool Fixed::operator> ( const Fixed &to_compare ) const
{
	return (value > to_compare.getRawBits());
}

bool Fixed::operator< ( const Fixed &to_compare ) const
{
	return (value < to_compare.getRawBits());
}

bool Fixed::operator>= ( const Fixed &to_compare ) const
{
	return (value >= to_compare.getRawBits());
}

bool Fixed::operator<= ( const Fixed &to_compare ) const
{
	return (value <= to_compare.getRawBits());
}

bool Fixed::operator== ( const Fixed &to_compare ) const
{
	return (value == to_compare.getRawBits());
}

bool Fixed::operator!= ( const Fixed &to_compare ) const
{
	return (value != to_compare.getRawBits());
}

// Arithmetic operators
Fixed &Fixed::operator+ ( const Fixed &second_number )
{
	value += second_number.getRawBits();
	return *this;
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
