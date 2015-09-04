//
// Generated file, do not edit! Created by opp_msgc 4.5 from src/wirelessChannel/WirelessChannelMessages.msg.
//

#ifndef _WIRELESSCHANNELMESSAGES_M_H_
#define _WIRELESSCHANNELMESSAGES_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>src/wirelessChannel/WirelessChannelMessages.msg</tt> by opp_msgc.
 * <pre>
 * message WirelessChannelSignalBegin {
 * 	int nodeID;
 * 	double power_dBm;
 * 	double carrierFreq;
 * 	double bandwidth;
 * 	int modulationType;
 * 	int encodingType;
 * 	bool skip;	
 * }
 * </pre>
 */
class WirelessChannelSignalBegin : public ::cMessage
{
  protected:
    int nodeID_var;
    double power_dBm_var;
    double carrierFreq_var;
    double bandwidth_var;
    int modulationType_var;
    int encodingType_var;
    bool skip_var;

  private:
    void copy(const WirelessChannelSignalBegin& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const WirelessChannelSignalBegin&);

  public:
    WirelessChannelSignalBegin(const char *name=NULL, int kind=0);
    WirelessChannelSignalBegin(const WirelessChannelSignalBegin& other);
    virtual ~WirelessChannelSignalBegin();
    WirelessChannelSignalBegin& operator=(const WirelessChannelSignalBegin& other);
    virtual WirelessChannelSignalBegin *dup() const {return new WirelessChannelSignalBegin(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getNodeID() const;
    virtual void setNodeID(int nodeID);
    virtual double getPower_dBm() const;
    virtual void setPower_dBm(double power_dBm);
    virtual double getCarrierFreq() const;
    virtual void setCarrierFreq(double carrierFreq);
    virtual double getBandwidth() const;
    virtual void setBandwidth(double bandwidth);
    virtual int getModulationType() const;
    virtual void setModulationType(int modulationType);
    virtual int getEncodingType() const;
    virtual void setEncodingType(int encodingType);
    virtual bool getSkip() const;
    virtual void setSkip(bool skip);
};

inline void doPacking(cCommBuffer *b, WirelessChannelSignalBegin& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, WirelessChannelSignalBegin& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/wirelessChannel/WirelessChannelMessages.msg</tt> by opp_msgc.
 * <pre>
 * packet WirelessChannelSignalEnd {
 * 	int nodeID;		
 * 	bool skip;		
 * }
 * </pre>
 */
class WirelessChannelSignalEnd : public ::cPacket
{
  protected:
    int nodeID_var;
    bool skip_var;

  private:
    void copy(const WirelessChannelSignalEnd& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const WirelessChannelSignalEnd&);

  public:
    WirelessChannelSignalEnd(const char *name=NULL, int kind=0);
    WirelessChannelSignalEnd(const WirelessChannelSignalEnd& other);
    virtual ~WirelessChannelSignalEnd();
    WirelessChannelSignalEnd& operator=(const WirelessChannelSignalEnd& other);
    virtual WirelessChannelSignalEnd *dup() const {return new WirelessChannelSignalEnd(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getNodeID() const;
    virtual void setNodeID(int nodeID);
    virtual bool getSkip() const;
    virtual void setSkip(bool skip);
};

inline void doPacking(cCommBuffer *b, WirelessChannelSignalEnd& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, WirelessChannelSignalEnd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/wirelessChannel/WirelessChannelMessages.msg</tt> by opp_msgc.
 * <pre>
 * message WirelessChannelNodeMoveMessage {
 * 	int nodeID;
 * 	double x;
 * 	double y;
 * 	double z;
 * 	double phi;
 * 	double theta;
 * }
 * </pre>
 */
class WirelessChannelNodeMoveMessage : public ::cMessage
{
  protected:
    int nodeID_var;
    double x_var;
    double y_var;
    double z_var;
    double phi_var;
    double theta_var;

  private:
    void copy(const WirelessChannelNodeMoveMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const WirelessChannelNodeMoveMessage&);

  public:
    WirelessChannelNodeMoveMessage(const char *name=NULL, int kind=0);
    WirelessChannelNodeMoveMessage(const WirelessChannelNodeMoveMessage& other);
    virtual ~WirelessChannelNodeMoveMessage();
    WirelessChannelNodeMoveMessage& operator=(const WirelessChannelNodeMoveMessage& other);
    virtual WirelessChannelNodeMoveMessage *dup() const {return new WirelessChannelNodeMoveMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getNodeID() const;
    virtual void setNodeID(int nodeID);
    virtual double getX() const;
    virtual void setX(double x);
    virtual double getY() const;
    virtual void setY(double y);
    virtual double getZ() const;
    virtual void setZ(double z);
    virtual double getPhi() const;
    virtual void setPhi(double phi);
    virtual double getTheta() const;
    virtual void setTheta(double theta);
};

inline void doPacking(cCommBuffer *b, WirelessChannelNodeMoveMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, WirelessChannelNodeMoveMessage& obj) {obj.parsimUnpack(b);}


#endif // _WIRELESSCHANNELMESSAGES_M_H_
