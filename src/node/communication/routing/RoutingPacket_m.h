//
// Generated file, do not edit! Created by opp_msgc 4.5 from src/node/communication/routing/RoutingPacket.msg.
//

#ifndef _ROUTINGPACKET_M_H_
#define _ROUTINGPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Struct generated from src/node/communication/routing/RoutingPacket.msg by opp_msgc.
 */
struct NetMacInfoExchange_type
{
    NetMacInfoExchange_type();
    double RSSI;
    double LQI;
    int nextHop;
    int lastHop;
};

void doPacking(cCommBuffer *b, NetMacInfoExchange_type& a);
void doUnpacking(cCommBuffer *b, NetMacInfoExchange_type& a);

/**
 * Class generated from <tt>src/node/communication/routing/RoutingPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet RoutingPacket {
 * 	NetMacInfoExchange_type netMacInfoExchange;
 * 	
 * 	string source;
 * 	string destination;
 * 	unsigned int sequenceNumber; 
 * 	int filtered;	
 * 	int sended;	
 * 	int compromised;
 * }
 * </pre>
 */
class RoutingPacket : public ::cPacket
{
  protected:
    NetMacInfoExchange_type netMacInfoExchange_var;
    opp_string source_var;
    opp_string destination_var;
    unsigned int sequenceNumber_var;
    int filtered_var;
    int sended_var;
    int compromised_var;

  private:
    void copy(const RoutingPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RoutingPacket&);

  public:
    RoutingPacket(const char *name=NULL, int kind=0);
    RoutingPacket(const RoutingPacket& other);
    virtual ~RoutingPacket();
    RoutingPacket& operator=(const RoutingPacket& other);
    virtual RoutingPacket *dup() const {return new RoutingPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual NetMacInfoExchange_type& getNetMacInfoExchange();
    virtual const NetMacInfoExchange_type& getNetMacInfoExchange() const {return const_cast<RoutingPacket*>(this)->getNetMacInfoExchange();}
    virtual void setNetMacInfoExchange(const NetMacInfoExchange_type& netMacInfoExchange);
    virtual const char * getSource() const;
    virtual void setSource(const char * source);
    virtual const char * getDestination() const;
    virtual void setDestination(const char * destination);
    virtual unsigned int getSequenceNumber() const;
    virtual void setSequenceNumber(unsigned int sequenceNumber);
    virtual int getFiltered() const;
    virtual void setFiltered(int filtered);
    virtual int getSended() const;
    virtual void setSended(int sended);
    virtual int getCompromised() const;
    virtual void setCompromised(int compromised);
};

inline void doPacking(cCommBuffer *b, RoutingPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RoutingPacket& obj) {obj.parsimUnpack(b);}


#endif // _ROUTINGPACKET_M_H_
