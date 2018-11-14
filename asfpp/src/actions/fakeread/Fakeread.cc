/**
 * @file Fakeread.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Fakeread.h"
#include "SensorManagerMessage_m.h"


Fakeread::Fakeread(int targetSensorIndex, string expressionToParse) : Action(FAKEREAD)
{
    // set the index of the target sensor
    this->targetSensorIndex = targetSensorIndex;
    // add variables and constants
    symbolTable.add_variable("t", time);
    symbolTable.add_variable("s", sensedValue);
    symbolTable.add_constants();
    // register symbol table
    expression.register_symbol_table(symbolTable);
    // compile the expression to parse
    exprParser.compile(expressionToParse,expression);
    // initialize variables
    time = 0.0;
    sensedValue = 0.0;
}


Fakeread::~Fakeread() {
    
    
}


void Fakeread::execute(cMessage* msg)
{
    // if sensor is the target one, tamper the value
    int sensorIndex = ((SensorReadingMessage*)msg)->getSensorIndex();
    if (sensorIndex == targetSensorIndex) {
        // retrieve the sensor reading
        sensedValue = ((SensorReadingMessage*)msg)->getSensedValue();
        // take the actual simulation time
        time = simTime().dbl();
        // evaluate expression
        double fakeSensedValue = expression.value();
        // overwrite the sensor reading
        ((SensorReadingMessage*)msg)->setSensedValue(fakeSensedValue);
    }
}
