//
// Generated file, do not edit! Created by nedtool 4.6 from src/globalfilter/UnconditionalFireMessage.msg.
//

#ifndef _UNCONDITIONALFIREMESSAGE_M_H_
#define _UNCONDITIONALFIREMESSAGE_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>src/globalfilter/UnconditionalFireMessage.msg:7</tt> by nedtool.
 * <pre>
 * message UnconditionalFireMessage
 * {
 *     int index;
 * 
 * }
 * </pre>
 */
class UnconditionalFireMessage : public ::cMessage
{
  protected:
    int index_var;

  private:
    void copy(const UnconditionalFireMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UnconditionalFireMessage&);

  public:
    UnconditionalFireMessage(const char *name=NULL, int kind=0);
    UnconditionalFireMessage(const UnconditionalFireMessage& other);
    virtual ~UnconditionalFireMessage();
    UnconditionalFireMessage& operator=(const UnconditionalFireMessage& other);
    virtual UnconditionalFireMessage *dup() const {return new UnconditionalFireMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getIndex() const;
    virtual void setIndex(int index);
};

inline void doPacking(cCommBuffer *b, UnconditionalFireMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, UnconditionalFireMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef _UNCONDITIONALFIREMESSAGE_M_H_

