/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:54:48 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/24 11:44:26 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

///////////////////////////////////////////////////////////////////////////////

// Constructors

Fixed::Fixed() : value(0) {
}

Fixed::Fixed( const int input ) : value(input << fractional_bits) {
}

Fixed::Fixed( const float input ) : value(roundf(input * (1 << fractional_bits))) {
}

Fixed::Fixed( const Fixed &copy ) {
    *this = copy;
}

Fixed::~Fixed() {
}

///////////////////////////////////////////////////////////////////////////////

// Copy assignment operator overload

Fixed &Fixed::operator= ( const Fixed &copy ) {
    if (this != &copy)
        this->setRawBits(copy.getRawBits());
    return *this;
}

///////////////////////////////////////////////////////////////////////////////

// Comparison operators

bool Fixed::operator> ( const Fixed &to_compare ) const {
	return (value > to_compare.getRawBits());
}

bool Fixed::operator< ( const Fixed &to_compare ) const {
	return (value < to_compare.getRawBits());
}

bool Fixed::operator>= ( const Fixed &to_compare ) const {
	return (value >= to_compare.getRawBits());
}

bool Fixed::operator<= ( const Fixed &to_compare ) const {
	return (value <= to_compare.getRawBits());
}

bool Fixed::operator== ( const Fixed &to_compare ) const {
	return (value == to_compare.getRawBits());
}

bool Fixed::operator!= ( const Fixed &to_compare ) const {
	return (value != to_compare.getRawBits());
}

///////////////////////////////////////////////////////////////////////////////

// Arithmetic operators

Fixed Fixed::operator+ ( const Fixed &second_number ) {
	return (Fixed(this->toFloat() + second_number.toFloat()));
}

Fixed Fixed::operator- ( const Fixed &second_number ) {
	return (Fixed(this->toFloat() - second_number.toFloat()));
}

Fixed Fixed::operator* ( const Fixed &second_number ) {
	return (Fixed(this->toFloat() * second_number.toFloat()));
}

Fixed Fixed::operator/ ( const Fixed &second_number ) {
    const int zero_check = second_number.getRawBits();
    if (zero_check == 0)
        std::cerr << "(division by zero doesn't work correctly yet, try another century) ";
    return (Fixed(this->toFloat() / second_number.toFloat()));
}

///////////////////////////////////////////////////////////////////////////////

// Increment / decrement

Fixed   &Fixed::operator++( void ) {
    ++this->value;
    return *this;
}

Fixed   &Fixed::operator--( void ) {
    --this->value;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );

    tmp.value = this->value++;
    return tmp;
}

Fixed   Fixed::operator--( int ) {
    Fixed tmp( *this );
    
    tmp.value = this->value--;
    return tmp;
}

///////////////////////////////////////////////////////////////////////////////

// Get / set

int Fixed::getRawBits( void ) const {
    return (this->value);
}

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
}

///////////////////////////////////////////////////////////////////////////////

// Min / max

Fixed &Fixed::min( Fixed &a, Fixed &b ) {
    return (a < b ? a : b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
    return (a > b ? a : b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
    return (a < b ? a : b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
    return (a > b ? a : b);
}

///////////////////////////////////////////////////////////////////////////////

// Convert

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->value ) / ( 1 << fractional_bits );
}

int     Fixed::toInt( void ) const {
    return this->value >> fractional_bits;
}

///////////////////////////////////////////////////////////////////////////////

// Output

std::ostream& operator<<( std::ostream& out, const Fixed& in) {
    out << in.toFloat();
    return (out);
}
