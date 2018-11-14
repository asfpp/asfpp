//
// Generated file, do not edit! Created by nedtool 5.4 from node/communication/mac/mac802154/Basic802154Packet.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __BASIC802154PACKET_M_H
#define __BASIC802154PACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "MacPacket_m.h"
// }}

/**
 * Enum generated from <tt>node/communication/mac/mac802154/Basic802154Packet.msg:19</tt> by nedtool.
 * <pre>
 * enum Mac802154Packet_type
 * {
 *     MAC_802154_BEACON_PACKET = 1001;
 *     MAC_802154_ASSOCIATE_PACKET = 1002;
 *     MAC_802154_DATA_PACKET = 1003;
 *     MAC_802154_ACK_PACKET = 1004;
 *     MAC_802154_GTS_REQUEST_PACKET = 1005;
 * }
 * </pre>
 */
enum Mac802154Packet_type {
    MAC_802154_BEACON_PACKET = 1001,
    MAC_802154_ASSOCIATE_PACKET = 1002,
    MAC_802154_DATA_PACKET = 1003,
    MAC_802154_ACK_PACKET = 1004,
    MAC_802154_GTS_REQUEST_PACKET = 1005
};

/**
 * Struct generated from node/communication/mac/mac802154/Basic802154Packet.msg:27 by nedtool.
 */
struct Basic802154GTSspec
{
    Basic802154GTSspec();
    int owner;
    int start;
    int length;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const Basic802154GTSspec& a);
void __doUnpacking(omnetpp::cCommBuffer *b, Basic802154GTSspec& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Basic802154GTSspec& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Basic802154GTSspec& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>node/communication/mac/mac802154/Basic802154Packet.msg:33</tt> by nedtool.
 * <pre>
 * packet Basic802154Packet extends MacPacket
 * {
 *     int Mac802154PacketType \@enum(Mac802154Packet_type);
 *     int PANid;
 *     int srcID;
 *     int dstID;
 *     int seqNum;
 * 
 *     // those fields belong to beacon packet (MAC_802154_BEACON_PACKET)
 *     int beaconOrder;
 *     int frameOrder;
 *     int BSN;
 *     int CAPlength;
 *     int GTSlength;
 *     Basic802154GTSspec GTSlist[];
 * }
 * </pre>
 */
class Basic802154Packet : public ::MacPacket
{
  protected:
    int Mac802154PacketType;
    int PANid;
    int srcID;
    int dstID;
    int seqNum;
    int beaconOrder;
    int frameOrder;
    int BSN;
    int CAPlength;
    int GTSlength;
    Basic802154GTSspec *GTSlist; // array ptr
    unsigned int GTSlist_arraysize;

  private:
    void copy(const Basic802154Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Basic802154Packet&);

  public:
    Basic802154Packet(const char *name=nullptr, short kind=0);
    Basic802154Packet(const Basic802154Packet& other);
    virtual ~Basic802154Packet();
    Basic802154Packet& operator=(const Basic802154Packet& other);
    virtual Basic802154Packet *dup() const override {return new Basic802154Packet(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getMac802154PacketType() const;
    virtual void setMac802154PacketType(int Mac802154PacketType);
    virtual int getPANid() const;
    virtual void setPANid(int PANid);
    virtual int getSrcID() const;
    virtual void setSrcID(int srcID);
    virtual int getDstID() const;
    virtual void setDstID(int dstID);
    virtual int getSeqNum() const;
    virtual void setSeqNum(int seqNum);
    virtual int getBeaconOrder() const;
    virtual void setBeaconOrder(int beaconOrder);
    virtual int getFrameOrder() const;
    virtual void setFrameOrder(int frameOrder);
    virtual int getBSN() const;
    virtual void setBSN(int BSN);
    virtual int getCAPlength() const;
    virtual void setCAPlength(int CAPlength);
    virtual int getGTSlength() const;
    virtual void setGTSlength(int GTSlength);
    virtual void setGTSlistArraySize(unsigned int size);
    virtual unsigned int getGTSlistArraySize() const;
    virtual Basic802154GTSspec& getGTSlist(unsigned int k);
    virtual const Basic802154GTSspec& getGTSlist(unsigned int k) const {return const_cast<Basic802154Packet*>(this)->getGTSlist(k);}
    virtual void setGTSlist(unsigned int k, const Basic802154GTSspec& GTSlist);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Basic802154Packet& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Basic802154Packet& obj) {obj.parsimUnpack(b);}


#endif // ifndef __BASIC802154PACKET_M_H
