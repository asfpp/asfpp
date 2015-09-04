//
// Generated file, do not edit! Created by opp_msgc 4.5 from src/node/application/clusterAggregator/ClusterAggregatorPacket.msg.
//

#ifndef _CLUSTERAGGREGATORPACKET_M_H_
#define _CLUSTERAGGREGATORPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "ApplicationPacket_m.h"
// }}



/**
 * Class generated from <tt>src/node/application/clusterAggregator/ClusterAggregatorPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet ClusterAggregatorDataPacket extends ApplicationPacket {
 * 	int sourceNodeID;	
 * 	int digest;		
 * }
 * </pre>
 */
class ClusterAggregatorDataPacket : public ::ApplicationPacket
{
  protected:
    int sourceNodeID_var;
    int digest_var;

  private:
    void copy(const ClusterAggregatorDataPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ClusterAggregatorDataPacket&);

  public:
    ClusterAggregatorDataPacket(const char *name=NULL, int kind=0);
    ClusterAggregatorDataPacket(const ClusterAggregatorDataPacket& other);
    virtual ~ClusterAggregatorDataPacket();
    ClusterAggregatorDataPacket& operator=(const ClusterAggregatorDataPacket& other);
    virtual ClusterAggregatorDataPacket *dup() const {return new ClusterAggregatorDataPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSourceNodeID() const;
    virtual void setSourceNodeID(int sourceNodeID);
    virtual int getDigest() const;
    virtual void setDigest(int digest);
};

inline void doPacking(cCommBuffer *b, ClusterAggregatorDataPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ClusterAggregatorDataPacket& obj) {obj.parsimUnpack(b);}


#endif // _CLUSTERAGGREGATORPACKET_M_H_
