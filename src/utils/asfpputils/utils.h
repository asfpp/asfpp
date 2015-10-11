/**
 * @file utils.h
 * 
 * @authors Marco Tiloca <marco.tiloca84@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief This file provides utility functions used by Castalia's 
 *        modules related to attacks evaluation.
 */


#ifndef _UTILS_H_
#define _UTILS_H_


#include <sstream>
#include <vector>
#include <map>

#include "CastaliaModule.h"
#include "CastaliaMessages.h"

#include "MultipathRingsRoutingPacket_m.h"
#include "Mac802154Packet_m.h"


using namespace std;

/* Split the 'str' string upon every occurrence of character 'delim' 
 * M.T.
 */
void tokenize(vector<string>& tokens, const string str, const char delim);


/**
 * @brief Splits the string 'str' upon every occurrence of char 'delim'.
 * @param str Is the string to tokenize.
 * @param delim Is the delimiter character.
 * @return Returns a vector of strings containing the tokens.
 */ 
vector<string> tokenize(const string str, const char delim);



/* Convert an integer into a string
 * A.P.
 */
string itos(const int i);


/* Convert a double into a string 
 * A.P.
 */
string dtos( const double number);


/* Given a layer name, return the associated integer value specified in CastaliaMessages.h
 *  A.P.
 * 
 * @param layer		layer name.
 * @return		the associated integer value
 */
int layertoi(const string layer);


/*
 *  Set the packet as filtered, in order to avoid multiple filtering and processing <A.P.>
 *
 *  @param packet	packet 
 *  @param value	it can be TRUE or FALSE
 */
void setFilteredRecursively( cMessage* packet, const int value);

/*
 *  Set the packet as compromised <A.P.>
 *
 *  @param packet	packet 
 */
void setCompromisedRecursively( cMessage* packet);


int highestPacketLayer(cMessage* packet);

/*
 * This method make an hard copy of a packet. Hard copy means that it make a real copy of the packet
 * and his inner packets (encapsulated one). <A.P.>
 *
 * @param packets	,it's the packet to be copied
 * @return			the copy of a packet or NULL if there is some problem
 */
cPacket* hardCopy(cPacket* packet);

/* Compare two elements by means of a specified operator.
 * Comapared elements must support such operators.
 *
 *  @param field1	is the first parameter
 *  @param field2	is the second parameter
 *  @param oper		is the comparison operator (supported : =, !=,
 */
template<class T>
bool evaluate( T f1, T f2, const string comp_operator) {

	if(comp_operator.compare("==") && comp_operator.compare("!=") && comp_operator.compare(">=") && comp_operator.compare("<=") && comp_operator.compare(">") && comp_operator.compare("<")) {

		cout<<" ERROR : Operator "<<comp_operator<<" not supported."<<endl;
		return false;

	}


	if(comp_operator == "==") 	
		return f1 == f2;

	if(comp_operator == "!=")
		return f1 != f2;

	if(comp_operator == ">")
		return f1 > f2;
			
	if(comp_operator == "<") 
		return f1 < f2 ;
		
	if(comp_operator == ">=" || comp_operator == "=>")
		return f1 >= f2;

	if(comp_operator == "<=" || comp_operator == "=<")
		return f1 <= f2;

}

/**
 * @brief Evaluate arithmetic expressions between two elements 
 *        by means of a specified operator. The compared elements 
 *        must support such operators.
 * @param field1 Is the first parameter
 * @param field2 Is the second parameter
 * @param oper Is the comparison operator
 */

template<class T>
float evaluateArithmetic(T f1, T f2, const string comp_operator) {

	if (comp_operator.compare("+") && comp_operator.compare("-") && comp_operator.compare("*") && comp_operator.compare("/") && comp_operator.compare("%")) {
		EV << "Operator not supported" <<endl;
		return false;
	}

	if (comp_operator == "+") {
		return (f1 + f2);
	}

	if (comp_operator == "-") {
		return (f1 - f2);
	}
			
	if (comp_operator == "*") {
		return (f1 * f2);
	}
    
    if (comp_operator == "%") {
		return ((int)f1 % (int)f2);
	}
    
}


#endif
