/**
 * @file Fakeread.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 * 
 * @brief The class Fakeread models the action fakeread (i.e. tampers 
 *        sensors measurements).
 */


#ifndef FAKEREAD_H
#define FAKEREAD_H


#include "Action.h"
#include <omnetpp.h>
#include "exprtk.hpp"


using namespace std;


class Fakeread : public Action {
private:
    // target sensor index 
    int targetSensorIndex;
    // table of symbols
    exprtk::symbol_table<double> symbolTable;
    // parsed expression
    exprtk::expression<double> expression;
    // parser
    exprtk::parser<double> exprParser;
    // variables
    double time;
    double sensedValue;

public:
    /**
     * @brief Constructor.
     */
    Fakeread(int targetSensorIndex, string expressionToParse);
    
    /**
     * @brief Destructor.
     */
    virtual ~Fakeread();
	
    /**
     * @brief Executes the fakeread action, i.e. tampers the sensor 
     *        readings.
     */
	void execute(cMessage* msg);
};

#endif
