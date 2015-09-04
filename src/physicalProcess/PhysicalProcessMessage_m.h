//
// Generated file, do not edit! Created by opp_msgc 4.5 from src/physicalProcess/PhysicalProcessMessage.msg.
//

#ifndef _PHYSICALPROCESSMESSAGE_M_H_
#define _PHYSICALPROCESSMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>src/physicalProcess/PhysicalProcessMessage.msg</tt> by opp_msgc.
 * <pre>
 * message PhysicalProcessMessage {
 * 	double value;
 * 	double xCoor;
 * 	double yCoor;
 * 	int srcID;		
 * 	int sensorIndex;
 * }
 * </pre>
 */
class PhysicalProcessMessage : public ::cMessage
{
  protected:
    double value_var;
    double xCoor_var;
    double yCoor_var;
    int srcID_var;
    int sensorIndex_var;

  private:
    void copy(const PhysicalProcessMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PhysicalProcessMessage&);

  public:
    PhysicalProcessMessage(const char *name=NULL, int kind=0);
    PhysicalProcessMessage(const PhysicalProcessMessage& other);
    virtual ~PhysicalProcessMessage();
    PhysicalProcessMessage& operator=(const PhysicalProcessMessage& other);
    virtual PhysicalProcessMessage *dup() const {return new PhysicalProcessMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual double getValue() const;
    virtual void setValue(double value);
    virtual double getXCoor() const;
    virtual void setXCoor(double xCoor);
    virtual double getYCoor() const;
    virtual void setYCoor(double yCoor);
    virtual int getSrcID() const;
    virtual void setSrcID(int srcID);
    virtual int getSensorIndex() const;
    virtual void setSensorIndex(int sensorIndex);
};

inline void doPacking(cCommBuffer *b, PhysicalProcessMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PhysicalProcessMessage& obj) {obj.parsimUnpack(b);}


#endif // _PHYSICALPROCESSMESSAGE_M_H_
