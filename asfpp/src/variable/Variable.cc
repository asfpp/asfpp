#include "Variable.h"

Variable::Variable(){

	value = "";
	type = NOTYPE;
}


Variable::Variable(const string v, const varType t){
	
	value = v;
	type = t;

}


Variable::Variable(const Variable& obj){
	
	this->value = obj.value;
	this->type = obj.type;

}

/**
 * Return a Variable object. The value of this new object depends on the operands type.
 * 
 * 	Both NUMBER : return a Variable whose value is the arithmetical sum.
 *
 *	Both STRING : return a Variable whose value is a concatenation of the two strings.
 *
 *	Different types "ASF-Error: Type mismatch".
 *
 * @return Variable object if both operands have the same types, an error otherwise.
 */
Variable Variable::operator+( const Variable& other ) const {
	
	string r_value;
	varType r_type;

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("\n\nASF-ASF-Error: Type mismatch.\n\n");


	switch(this->type){


		case NUMBER: 
			r_value = dtos( double(*this) + double(other) );
			r_type = NUMBER;
			break;
			
		case STRING: 	
			// must check if they have a NUMBER format ?
			r_value =  this->value + other.value;
			r_type = STRING;
			break;

	}	
	

	return Variable(r_value, r_type);

}


Variable Variable::operator+( const int number ) const {
	
	string r_value;


	if(this->type != NUMBER )
		opp_error("ASF-Error: Type mismatch.");



	r_value = dtos( double(*this) + number );

	return Variable(r_value, NUMBER);

}

/**
 * Prefix increment operator "++<variable>"
 *
 * @return Increment the variable value by one if it is a NUMBER. Return an error otherwise.
 */
Variable& Variable::operator++(){
	

	switch(this->type){


		case NUMBER: 
			*this = *this + 1 ;
			break;
			
		default: 	
			opp_error("ASF-Error: Operator not supported.");

	}	
	
	return *this;

}

/**
 * Postfix increment operator "<variable>++"
 *
 * @return Increment the variable value by one if it is a NUMBER. Return an error otherwise.
 */
Variable& Variable::operator++(int){

	// Invoke the prefix operator
	return ++(*this);

}

/**
 * Addition assignment operator ( <variable1>+= <variable2>)
 *
 */
Variable& Variable::operator+=( const Variable& other ){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER:
			*this = *this + other ;
			break;
			
		case STRING: 	
			this->value = this->value + other.value;
			break;

	}	
	
	return *this;
}

/**
 * Return a Variable object. It support only NUMBER variables.
 *
 * 	Both NUMBER : return a Variable whose value is the arithmetical subtraction.
 *
 *	Different types : "ASF-Error: Type mismatch".
 *
 *      Others types : "ASF-Error: Operator not supported."
 *
 *
 * @return Variable object if both operands have the same types, an error otherwise.
 */
Variable Variable::operator-( const Variable& other ) const{
	
	string r_value;
	varType r_type;

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){


		case NUMBER:
			r_value = dtos( double(*this) - double(other) );
			r_type = NUMBER;
			break;
			
		case STRING: 	
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return Variable(r_value, r_type);

}

/**
 * Prefix decrement operator "--<variable>"
 *
 * @return Decrement the variable value by one if it is a NUMBER. Otherwise, return an error.
 */
Variable& Variable::operator--(){

	switch(this->type){

		case NUMBER:
			this->value = dtos( double(*this) - 1 );
			break;

		default:
			opp_error("ASF-Error: Operator not supported.");
	}

	return *this;

}

/**
 * Postfix decrement operator "<variable>--"
 *
 * @return Decrements by one the value of the variable if it's a NUMBER, otherwise return an error.
 */
Variable& Variable::operator--(int){

	// Invoke the prefix operator
	return --(*this);

}

Variable& Variable::operator-=( const Variable& other ){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER:
			this->value = dtos( double(*this) - double(other) );
			break;
			
		case STRING: 	
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return *this;
	
}

Variable Variable::operator*( const Variable& other ) const{

	string r_value;

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER: 
			r_value = dtos( double(*this) * double(other) );
			break;
			
		case STRING:
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return Variable(r_value, NUMBER);
	
}

Variable Variable::operator%( const Variable& other)const{

	string r_value;

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER:
			r_value = itos( int(*this) % int(other) );
			break;
			
		case STRING:
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return Variable(r_value, NUMBER);
}

Variable Variable::operator/( const Variable& other) const{

	string r_value;

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER:
			if(double(other) == 0)
			  opp_error("ASF-Error: Division by zero.");
				
			r_value = dtos( double(*this) / double(other) );
			break;
			
		case STRING:
			opp_error("ASF-Error: Operator not supported.");
			break;

	}
	
	return Variable(r_value, NUMBER);
}

Variable& Variable::operator=(const Variable& other){

	this->value = other.value;
	this->type = other.type;

	return *this;

}

Variable& Variable::operator*=(const Variable& other){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER:
			*this = *this * other;
			break;
			
		case STRING:
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return *this;

}

Variable& Variable::operator/=( const Variable& other){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch(this->type){

		case NUMBER: 
			*this = *this / other;
			break;
			
		case STRING:
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return *this;
	
}

Variable& Variable::operator%=( const Variable& other){
	
	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");
	

	switch(this->type){

		case NUMBER:
			*this = *this % other;
			break;
			
		case STRING:
			opp_error("ASF-Error: Operator not supported.");
			break;

	}	
	
	return *this;
}

/**
 *  This operator check if the 2 variables have the same type and then the same value. If they are the same 
 *  type check if the STRING one has a NUMBER format and than check if they have the same value using a cast.
 *
 *  @return True if the two operands have the same value and False if their values or types are different.
 */
Variable Variable::operator==(const Variable &other){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch( this->type ){	

			case STRING :
				if ( this->value.compare(other.value) == 0 )
					return Variable("1", NUMBER);
				return Variable("0", NUMBER);
			
			case NUMBER :
				if ( double(*this) == double(other) )
					return Variable("1", NUMBER);
				return Variable("0", NUMBER);

	}

}

Variable Variable::operator!=(const Variable &other){

	// use "equal" operator
	if ( !(*this == other) )
		return Variable("1", NUMBER);
	return Variable("0", NUMBER);

}


Variable Variable::operator>(const Variable &other){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch( this->type ){	

			case STRING :
				if ( this->value.compare(other.value) > 0 )
					return Variable("1", NUMBER);
				return Variable("0", NUMBER);
			
			case NUMBER :
				if ( double(*this) > double(other) )
					return Variable("1", NUMBER);
				return Variable("0", NUMBER);

	}

}

Variable Variable::operator<(const Variable &other){

	// The two variables are of different types: print an error and stop
	if(this->type != other.type )
		opp_error("ASF-Error: Type mismatch.\n");

	switch( this->type ){	

			case STRING :
				if ( this->value.compare(other.value) < 0 )
					return Variable("1", NUMBER);
				return Variable("0", NUMBER);
			
			case NUMBER :
				if ( double(*this) < double(other) )
					return Variable("1", NUMBER);
				return Variable("0", NUMBER);

	}

}

Variable Variable::operator>=(const Variable &other){

	// use "equal" and "greater than" operators already defined
	if ( (*this == other) || (*this > other)) 
		return Variable("1", NUMBER);
	return Variable("0", NUMBER);

}

Variable Variable::operator<=(const Variable &other){

	// use "equal" and "smaller than" operators already defined
	if ((*this == other) || (*this < other))
		return Variable("1", NUMBER);
	return Variable("0", NUMBER);

}

Variable Variable::operator&&(const Variable &other){

	if ( int(*this) && int(other) ) 
		return Variable("1", NUMBER);
	return Variable("0", NUMBER);

}

Variable Variable::operator||(const Variable &other){

	if ( int(*this) || int(other) ) 
		return Variable("1", NUMBER);
	return Variable("0", NUMBER);

}

Variable Variable::operator!(){

	if ( int(*this) ) 
		return Variable("0", NUMBER);
	return Variable("1", NUMBER);

}

// TYPE CAST


/*
 * This function take a variable and return, if it's a NUMBER or have a NUMBER format, a Variable object
 * with value cast to int.
 *
 * @return Variable object with value as a integer. Run-Time error if it isn't a NUMBER type or format. 
 */
Variable Variable::cast_int() const{
	
	string r_value;	

	switch(this->type){


		case STRING: 	
				if( getFormat(this->value) != NUMBER )
					opp_error("ASF-Error: Operator not supported.");
				

		case NUMBER: 	r_value = itos( int(*this) );
				break;


	}	
	
	return Variable(r_value, NUMBER);
}

/*
 * This function take a variable and return, if it's a NUMBER or have a NUMBER format, a Variable object
 * with value cast to double.
 *
 * @return Variable object with value as a double. Run-Time error if it isn't a NUMBER type or format. 
 */
Variable Variable::cast_double() const{
	
	string r_value;	

	switch(this->type){

		case STRING:
			if( getFormat(this->value) != NUMBER )
				opp_error("ASF-Error: Operator not supported.");	

		case NUMBER: 	r_value = dtos( double(*this) );
				break;


	}	
	
	return Variable(r_value, NUMBER);
}

/*
 * This function take a variable and return, if it's a NUMBER or have a NUMBER format, an integer with
 *  the value of the Variable.
 *
 * @return A integer with the value of the Variable. Run-Time error if it isn't a NUMBER type or format. 
 */
Variable::operator int(){
	
	int r_value;	

	switch(this->type){

		case STRING: 
			if( getFormat(this->value) != NUMBER )
				opp_error("ASF-Error: Operator not supported.");

		case NUMBER: 	r_value = atoi( (this->value).c_str() );
				break;


	}	
	
	return r_value;
	
}

// Return true or false if the variable is of type NUMBER and its value is greater or lower than zero, respectively. Return an error otherwise.
Variable::operator bool() {
	
	int r_value;

	switch(this->type){

		case STRING:
			if( getFormat(this->value) != NUMBER )
				opp_error("ASF-Error: Operator not supported.");

		case NUMBER:
			r_value = atoi( (this->value).c_str() );
			break;

	}	
	
	if( r_value )
		return true;
	else
		return false;

}


/*
 * This function take a variable and return, if it's a NUMBER or have a NUMBER format, a double with
 *  the value of the Variable.
 *
 * @return A double with the value of the Variable. Run-Time error if it isn't a NUMBER type or format. 
 */
Variable::operator double(){
	
	double r_value;	

	switch(this->type){


		case STRING: 	
				if( getFormat(this->value) != NUMBER )
					opp_error("ASF-Error: Operator not supported.");				

		case NUMBER: 	r_value = atof( (this->value).c_str() );
				break;


	}	
	
	return r_value;
}


// Used when the Variable is a const object
Variable::operator double() const{
	double r_value;	

	switch(this->type){


		case STRING: 	
				if( getFormat(this->value) != NUMBER )
					opp_error("ASF-Error: Operator not supported.");
				

		case NUMBER: 	r_value = atof( (this->value).c_str() );
				break;


	}	
	
	return r_value;
}

// Used when the Variable is a const object
Variable::operator int() const{
	int r_value;	

	switch(this->type){


		case STRING: 	
				if( getFormat(this->value) != NUMBER )
					opp_error("ASF-Error: Operator not supported.");
				

		case NUMBER: 	r_value = atoi( (this->value).c_str() );
				break;


	}	
	
	return r_value;
}


// Non member function

std::ostream& operator<<(std::ostream& os, Variable& obj){

	os << obj.getValue();
  
	return os;
}

varType getFormat(string value){
	
	char * p;
	double d = strtod( value.c_str(), &p );
	
	if ( *p == 0 )
	   return NUMBER;

	return STRING;

}
