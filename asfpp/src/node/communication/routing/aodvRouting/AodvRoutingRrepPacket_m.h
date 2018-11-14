//
// Generated file, do not edit! Created by nedtool 5.4 from node/communication/routing/aodvRouting/AodvRoutingRrepPacket.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __AODVROUTINGRREPPACKET_M_H
#define __AODVROUTINGRREPPACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "PacketId_m.h"
// }}

/**
 * Class generated from <tt>node/communication/routing/aodvRouting/AodvRoutingRrepPacket.msg:22</tt> by nedtool.
 * <pre>
 * //id =2
 * packet AodvRREPPacket extends PacketId
 * {
 *     bool flagR;
 *     bool flagA;
 *     int prefixSz;
 *     int hopCount;
 *     string originator;
 *     unsigned long destinationSeqNum;
 *     string destinationAodv;
 *     double lifetime;
 * }
 * </pre>
 */
class AodvRREPPacket : public ::PacketId
{
  protected:
    bool flagR;
    bool flagA;
    int prefixSz;
    int hopCount;
    ::omnetpp::opp_string originator;
    unsigned long destinationSeqNum;
    ::omnetpp::opp_string destinationAodv;
    double lifetime;

  private:
    void copy(const AodvRREPPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AodvRREPPacket&);

  public:
    AodvRREPPacket(const char *name=nullptr, short kind=0);
    AodvRREPPacket(const AodvRREPPacket& other);
    virtual ~AodvRREPPacket();
    AodvRREPPacket& operator=(const AodvRREPPacket& other);
    virtual AodvRREPPacket *dup() const override {return new AodvRREPPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getFlagR() const;
    virtual void setFlagR(bool flagR);
    virtual bool getFlagA() const;
    virtual void setFlagA(bool flagA);
    virtual int getPrefixSz() const;
    virtual void setPrefixSz(int prefixSz);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
    virtual const char * getOriginator() const;
    virtual void setOriginator(const char * originator);
    virtual unsigned long getDestinationSeqNum() const;
    virtual void setDestinationSeqNum(unsigned long destinationSeqNum);
    virtual const char * getDestinationAodv() const;
    virtual void setDestinationAodv(const char * destinationAodv);
    virtual double getLifetime() const;
    virtual void setLifetime(double lifetime);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AodvRREPPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AodvRREPPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef __AODVROUTINGRREPPACKET_M_H
