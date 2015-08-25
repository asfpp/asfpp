/*
 * This class implements objects Variable provided by the attack specification language.
 * A variable objects include the following two fields:
 *	- value
 *	- type, i.e. either NUMBER, STRING, or NOTYPE (default)
 *
 * Associations between name and content of each variable rely on 'variableTable'.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */



#ifndef VARIABLE_
#define VARIABLE_

#include<iostream>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

using namespace std;

// NONE is already declared in Action.h
enum varType{NUMBER, STRING, NOTYPE};

class Variable{

	string value;
	varType type;

	public:

		Variable();
		Variable(const string v, const varType t);
		Variable(const Variable& obj);

		Variable operator+( const Variable& other ) const;
		Variable operator+( const int number ) const;
		Variable& operator++(); // Prefix
		Variable& operator++(int); // Postfix

		Variable operator-( const Variable& other ) const;
		Variable& operator--(); // Prefix
		Variable& operator--(int); // Postfix

		Variable operator*( const Variable& other ) const;
		Variable operator%( const Variable& other )const;
		Variable operator/( const Variable& other ) const;

		Variable& operator=( const Variable& other );
		Variable& operator-=( const Variable& other );
		Variable& operator+=( const Variable& other );
		Variable& operator*=( const Variable& other );
		Variable& operator/=( const Variable& other );
		Variable& operator%=( const Variable& other );

		// Cast operator
		Variable cast_int() const;
		Variable cast_double() const;

		// Return an int with the variable value, or error if it is a STRING
		operator int();
		// Return a double with the variable value, or error if it is a STRING
		operator double();
		// return the bool 
		operator bool();

		// Used when the Variable is a const object
		operator double() const;
		operator int() const;

		// Comparison operators. Returned values Variable objects, in order to be managed within the variable stack (see Attack.h)
		Variable operator==( const Variable& other);
		Variable operator!=( const Variable& other );
		Variable operator<( const Variable& other );
		Variable operator>( const Variable& other );
		Variable operator<=( const Variable& other );
		Variable operator>=( const Variable& other );

		// Logical operators
		Variable operator&&( const Variable& other);
		Variable operator||( const Variable& other);
		Variable operator!();

		string getValue(){ return this->value; }
		varType getType(){ return this->type; }

		~Variable(){ value.clear(); }

		friend std::ostream& operator<<(std::ostream& os, Variable& obj);

};

// Return the variable type, i.e. either NUMBER or STRING
varType getFormat(string value);

#endif
