//
// Generated file, do not edit! Created by nedtool 5.4 from node/communication/mac/baselineBanMac/BaselineMacPacket.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __BASELINEMACPACKET_M_H
#define __BASELINEMACPACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "MacPacket_m.h"

#define BASELINEBAN_HEADER_SIZE 7
#define BASELINEBAN_BEACON_SIZE 17 + 7
#define BASELINEBAN_CONNECTION_REQUEST_SIZE 28 + 7
#define BASELINEBAN_CONNECTION_ASSIGNMENT_SIZE 29 + 7

#define BROADCAST_NID 255
#define UNCONNECTED_BROADCAST_NID 0
// }}

/**
 * Enum generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:28</tt> by nedtool.
 * <pre>
 * enum SecurityLevel_type
 * {
 *     NOT_SECURED = 1;
 *     AUTHENTICATED_NOT_ENCRYPTED = 2;
 *     AUTHENTICATED_AND_ENCRYPTED = 3;
 *     //RESERVED = 4; 
 * }
 * </pre>
 */
enum SecurityLevel_type {
    NOT_SECURED = 1,
    AUTHENTICATED_NOT_ENCRYPTED = 2,
    AUTHENTICATED_AND_ENCRYPTED = 3
};

/**
 * Enum generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:35</tt> by nedtool.
 * <pre>
 * enum AcknowledgementPolicy_type
 * {
 *     N_ACK_POLICY = 1;
 *     I_ACK_POLICY = 2;
 *     L_ACK_POLICY = 3;
 *     B_ACK_POLICY = 4;
 * }
 * </pre>
 */
enum AcknowledgementPolicy_type {
    N_ACK_POLICY = 1,
    I_ACK_POLICY = 2,
    L_ACK_POLICY = 3,
    B_ACK_POLICY = 4
};

/**
 * Enum generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:42</tt> by nedtool.
 * <pre>
 * enum Frame_type
 * {
 *     MANAGEMENT = 1;
 *     CONTROL = 2;
 *     DATA = 3;
 * }
 * </pre>
 */
enum Frame_type {
    MANAGEMENT = 1,
    CONTROL = 2,
    DATA = 3
};

/**
 * Enum generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:48</tt> by nedtool.
 * <pre>
 * enum Frame_subtype
 * {
 *     RESERVED = 0;
 *     BEACON = 1;
 *     ASSOCIATION = 2;
 *     DISASSOCIATION = 3;
 *     PTK = 4;
 *     GTK = 5;
 *     CONNECTION_REQUEST = 6;
 *     CONNECTION_ASSIGNMENT = 7;
 *     DISCONNECTION = 8;
 *     I_ACK = 9;
 *     B_ACK = 10;
 *     I_ACK_POLL = 11;
 *     B_ACK_POLL = 12;
 *     POLL = 13;
 *     T_POLL = 14;
 * }
 * </pre>
 */
enum Frame_subtype {
    RESERVED = 0,
    BEACON = 1,
    ASSOCIATION = 2,
    DISASSOCIATION = 3,
    PTK = 4,
    GTK = 5,
    CONNECTION_REQUEST = 6,
    CONNECTION_ASSIGNMENT = 7,
    DISCONNECTION = 8,
    I_ACK = 9,
    B_ACK = 10,
    I_ACK_POLL = 11,
    B_ACK_POLL = 12,
    POLL = 13,
    T_POLL = 14
};

/**
 * Enum generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:66</tt> by nedtool.
 * <pre>
 * enum statusCode_type
 * {
 *     ACCEPTED = 0;
 *     REJ_NO_BANDWIDTH = 1;
 *     REJ_NO_NID = 2;
 *     REJ_NO_RESOURCES = 3;
 *     REJ_NO_HIGH_SECURITY = 4;
 *     REJ_NO_LOW_SECURITY = 5;
 *     REJ_NO_REASON = 6;
 *     MODIFIED = 7;
 * }
 * </pre>
 */
enum statusCode_type {
    ACCEPTED = 0,
    REJ_NO_BANDWIDTH = 1,
    REJ_NO_NID = 2,
    REJ_NO_RESOURCES = 3,
    REJ_NO_HIGH_SECURITY = 4,
    REJ_NO_LOW_SECURITY = 5,
    REJ_NO_REASON = 6,
    MODIFIED = 7
};

/**
 * Class generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:77</tt> by nedtool.
 * <pre>
 * packet BaselineMacPacket extends MacPacket
 * {
 *     //MAC Header fields
 *     int HID;										//2 bytes, 2 last bytes of full MAC address
 *     int NID;										//1 byte, short MAC address
 *     //MAC header control fields
 *     int protocolVersion;							//2 bits
 *     int securityLevel \@enum(SecurityLevel_type);		//2 bits
 *     int TKindex;									//1 bit
 *     int retry;										//1 bit
 *     int ackPolicy \@enum(AcknowledgementPolicy_type);	//2 bits	total: 1 byte
 *     int frameType \@enum(Frame_type);					//2 bits
 *     int frameSubtype \@enum(Frame_subtype);			//2 bits
 *     int moreData;									//1 bit
 *     int firstFrame;									//1 bit		total: 2 bytes
 *     int sequenceNum;								//1 byte
 *     int fragmentNumber; 							//3 bits
 *     //reserved 5 bits											total: 4 bytes
 * 													//			total header: 7 bytes
 * }
 * 
 * // We define all different packet types that carry extra information on their 
 * // packet body, as separate packets. All derived from BaselinePacket.
 * </pre>
 */
class BaselineMacPacket : public ::MacPacket
{
  protected:
    int HID;
    int NID;
    int protocolVersion;
    int securityLevel;
    int TKindex;
    int retry;
    int ackPolicy;
    int frameType;
    int frameSubtype;
    int moreData;
    int firstFrame;
    int sequenceNum;
    int fragmentNumber;

  private:
    void copy(const BaselineMacPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BaselineMacPacket&);

  public:
    BaselineMacPacket(const char *name=nullptr, short kind=0);
    BaselineMacPacket(const BaselineMacPacket& other);
    virtual ~BaselineMacPacket();
    BaselineMacPacket& operator=(const BaselineMacPacket& other);
    virtual BaselineMacPacket *dup() const override {return new BaselineMacPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getHID() const;
    virtual void setHID(int HID);
    virtual int getNID() const;
    virtual void setNID(int NID);
    virtual int getProtocolVersion() const;
    virtual void setProtocolVersion(int protocolVersion);
    virtual int getSecurityLevel() const;
    virtual void setSecurityLevel(int securityLevel);
    virtual int getTKindex() const;
    virtual void setTKindex(int TKindex);
    virtual int getRetry() const;
    virtual void setRetry(int retry);
    virtual int getAckPolicy() const;
    virtual void setAckPolicy(int ackPolicy);
    virtual int getFrameType() const;
    virtual void setFrameType(int frameType);
    virtual int getFrameSubtype() const;
    virtual void setFrameSubtype(int frameSubtype);
    virtual int getMoreData() const;
    virtual void setMoreData(int moreData);
    virtual int getFirstFrame() const;
    virtual void setFirstFrame(int firstFrame);
    virtual int getSequenceNum() const;
    virtual void setSequenceNum(int sequenceNum);
    virtual int getFragmentNumber() const;
    virtual void setFragmentNumber(int fragmentNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaselineMacPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaselineMacPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:100</tt> by nedtool.
 * <pre>
 * packet BaselineBeaconPacket extends BaselineMacPacket
 * {
 *     //Beacon payload fields
 *     int senderAddress;							//6 bytes
 *     int beaconShiftingSequenceIndex; 			//1 byte
 *     int beaconShiftingSequencePhase;
 *     int beaconPeriodLength;						//1 byte
 *     int allocationSlotLength;					//1 byte
 *     int RAP1Length;								//1 byte
 *     int RAP2Length;								//1 byte
 *     // 6 more bytes for capabilites and channel hopping state
 * 												//		total: 17 bytes + 7 bytes in header
 * }
 * </pre>
 */
class BaselineBeaconPacket : public ::BaselineMacPacket
{
  protected:
    int senderAddress;
    int beaconShiftingSequenceIndex;
    int beaconShiftingSequencePhase;
    int beaconPeriodLength;
    int allocationSlotLength;
    int RAP1Length;
    int RAP2Length;

  private:
    void copy(const BaselineBeaconPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BaselineBeaconPacket&);

  public:
    BaselineBeaconPacket(const char *name=nullptr, short kind=0);
    BaselineBeaconPacket(const BaselineBeaconPacket& other);
    virtual ~BaselineBeaconPacket();
    BaselineBeaconPacket& operator=(const BaselineBeaconPacket& other);
    virtual BaselineBeaconPacket *dup() const override {return new BaselineBeaconPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSenderAddress() const;
    virtual void setSenderAddress(int senderAddress);
    virtual int getBeaconShiftingSequenceIndex() const;
    virtual void setBeaconShiftingSequenceIndex(int beaconShiftingSequenceIndex);
    virtual int getBeaconShiftingSequencePhase() const;
    virtual void setBeaconShiftingSequencePhase(int beaconShiftingSequencePhase);
    virtual int getBeaconPeriodLength() const;
    virtual void setBeaconPeriodLength(int beaconPeriodLength);
    virtual int getAllocationSlotLength() const;
    virtual void setAllocationSlotLength(int allocationSlotLength);
    virtual int getRAP1Length() const;
    virtual void setRAP1Length(int RAP1Length);
    virtual int getRAP2Length() const;
    virtual void setRAP2Length(int RAP2Length);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaselineBeaconPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaselineBeaconPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:113</tt> by nedtool.
 * <pre>
 * packet BaselineConnectionRequestPacket extends BaselineMacPacket
 * {
 *     int recipientAddress;						//6 bytes
 *     int senderAddress;							//6 bytes
 *     int formerHubAddress;						//6 bytes
 *     //4 bytes for capabilities and security
 *     int changeIndication;						//1 byte
 *     int nextWakeup;								//1 byte
 *     int wakeupInterval;							//1 byte
 *     int uplinkRequest;							//these requests are complex structures of atleast 
 *     int downlinkRequest;						//atleast 7 bytes length, here we will simplyfy it
 *     int bilinkRequest;							//by saying that this particular number of slots
 * 												//is requested
 * 												//    		total: 28 bytes + 7 bytes in header
 * }
 * </pre>
 */
class BaselineConnectionRequestPacket : public ::BaselineMacPacket
{
  protected:
    int recipientAddress;
    int senderAddress;
    int formerHubAddress;
    int changeIndication;
    int nextWakeup;
    int wakeupInterval;
    int uplinkRequest;
    int downlinkRequest;
    int bilinkRequest;

  private:
    void copy(const BaselineConnectionRequestPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BaselineConnectionRequestPacket&);

  public:
    BaselineConnectionRequestPacket(const char *name=nullptr, short kind=0);
    BaselineConnectionRequestPacket(const BaselineConnectionRequestPacket& other);
    virtual ~BaselineConnectionRequestPacket();
    BaselineConnectionRequestPacket& operator=(const BaselineConnectionRequestPacket& other);
    virtual BaselineConnectionRequestPacket *dup() const override {return new BaselineConnectionRequestPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getRecipientAddress() const;
    virtual void setRecipientAddress(int recipientAddress);
    virtual int getSenderAddress() const;
    virtual void setSenderAddress(int senderAddress);
    virtual int getFormerHubAddress() const;
    virtual void setFormerHubAddress(int formerHubAddress);
    virtual int getChangeIndication() const;
    virtual void setChangeIndication(int changeIndication);
    virtual int getNextWakeup() const;
    virtual void setNextWakeup(int nextWakeup);
    virtual int getWakeupInterval() const;
    virtual void setWakeupInterval(int wakeupInterval);
    virtual int getUplinkRequest() const;
    virtual void setUplinkRequest(int uplinkRequest);
    virtual int getDownlinkRequest() const;
    virtual void setDownlinkRequest(int downlinkRequest);
    virtual int getBilinkRequest() const;
    virtual void setBilinkRequest(int bilinkRequest);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaselineConnectionRequestPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaselineConnectionRequestPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:128</tt> by nedtool.
 * <pre>
 * packet BaselineConnectionAssignmentPacket extends BaselineMacPacket
 * {
 *     int recipientAddress;                       //6 bytes
 *     int senderAddress;                          //6 bytes
 *     int channelDwellLength;						//1 byte
 *     int channelDwellPhase;						//1 byte
 *     int minRAPlength;							//1 byte
 *     int statusCode \@enum(statusCode_type);		//1 byte
 *     //4 bytes for capabilities and security
 *     int assignedNID;							//1 byte
 *     int changeIndication;                       //1 byte
 *     int nextWakeup;								//1 byte
 *     int wakeupinterval;							//1 byte
 * 
 *     int uplinkRequestStart;						//these requests are complex structures of at least 
 *     int uplinkRequestEnd;						//7 bytes length, here we will simplify them
 *     int downlinkRequestStart;					//by saying that this particular number of slots assigned
 *     int downlinkRequestEnd;
 *     int bilinkRequestStart;
 *     int bilinkRequestEnd;
 * 												//		total: 29 bytes + 7 bytes in header
 * }
 * </pre>
 */
class BaselineConnectionAssignmentPacket : public ::BaselineMacPacket
{
  protected:
    int recipientAddress;
    int senderAddress;
    int channelDwellLength;
    int channelDwellPhase;
    int minRAPlength;
    int statusCode;
    int assignedNID;
    int changeIndication;
    int nextWakeup;
    int wakeupinterval;
    int uplinkRequestStart;
    int uplinkRequestEnd;
    int downlinkRequestStart;
    int downlinkRequestEnd;
    int bilinkRequestStart;
    int bilinkRequestEnd;

  private:
    void copy(const BaselineConnectionAssignmentPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BaselineConnectionAssignmentPacket&);

  public:
    BaselineConnectionAssignmentPacket(const char *name=nullptr, short kind=0);
    BaselineConnectionAssignmentPacket(const BaselineConnectionAssignmentPacket& other);
    virtual ~BaselineConnectionAssignmentPacket();
    BaselineConnectionAssignmentPacket& operator=(const BaselineConnectionAssignmentPacket& other);
    virtual BaselineConnectionAssignmentPacket *dup() const override {return new BaselineConnectionAssignmentPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getRecipientAddress() const;
    virtual void setRecipientAddress(int recipientAddress);
    virtual int getSenderAddress() const;
    virtual void setSenderAddress(int senderAddress);
    virtual int getChannelDwellLength() const;
    virtual void setChannelDwellLength(int channelDwellLength);
    virtual int getChannelDwellPhase() const;
    virtual void setChannelDwellPhase(int channelDwellPhase);
    virtual int getMinRAPlength() const;
    virtual void setMinRAPlength(int minRAPlength);
    virtual int getStatusCode() const;
    virtual void setStatusCode(int statusCode);
    virtual int getAssignedNID() const;
    virtual void setAssignedNID(int assignedNID);
    virtual int getChangeIndication() const;
    virtual void setChangeIndication(int changeIndication);
    virtual int getNextWakeup() const;
    virtual void setNextWakeup(int nextWakeup);
    virtual int getWakeupinterval() const;
    virtual void setWakeupinterval(int wakeupinterval);
    virtual int getUplinkRequestStart() const;
    virtual void setUplinkRequestStart(int uplinkRequestStart);
    virtual int getUplinkRequestEnd() const;
    virtual void setUplinkRequestEnd(int uplinkRequestEnd);
    virtual int getDownlinkRequestStart() const;
    virtual void setDownlinkRequestStart(int downlinkRequestStart);
    virtual int getDownlinkRequestEnd() const;
    virtual void setDownlinkRequestEnd(int downlinkRequestEnd);
    virtual int getBilinkRequestStart() const;
    virtual void setBilinkRequestStart(int bilinkRequestStart);
    virtual int getBilinkRequestEnd() const;
    virtual void setBilinkRequestEnd(int bilinkRequestEnd);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaselineConnectionAssignmentPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaselineConnectionAssignmentPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:150</tt> by nedtool.
 * <pre>
 * packet BaselineBAckPacket extends BaselineMacPacket
 * {
 *     int nextBlockSize;							//1 byte
 *     int oldestFrameExpected;					//1 byte
 *     int frameStatusBitmap;						//1 byte
 * 												//		total: 3 bytes + 7 bytes in header
 * }
 * </pre>
 */
class BaselineBAckPacket : public ::BaselineMacPacket
{
  protected:
    int nextBlockSize;
    int oldestFrameExpected;
    int frameStatusBitmap;

  private:
    void copy(const BaselineBAckPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BaselineBAckPacket&);

  public:
    BaselineBAckPacket(const char *name=nullptr, short kind=0);
    BaselineBAckPacket(const BaselineBAckPacket& other);
    virtual ~BaselineBAckPacket();
    BaselineBAckPacket& operator=(const BaselineBAckPacket& other);
    virtual BaselineBAckPacket *dup() const override {return new BaselineBAckPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getNextBlockSize() const;
    virtual void setNextBlockSize(int nextBlockSize);
    virtual int getOldestFrameExpected() const;
    virtual void setOldestFrameExpected(int oldestFrameExpected);
    virtual int getFrameStatusBitmap() const;
    virtual void setFrameStatusBitmap(int frameStatusBitmap);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaselineBAckPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaselineBAckPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>node/communication/mac/baselineBanMac/BaselineMacPacket.msg:157</tt> by nedtool.
 * <pre>
 * packet BaselineTPollPacket extends BaselineMacPacket
 * {
 *     int currentBeaconPeriod;				//1 byte
 *     int currentAllocationSlot;				//1 byte
 *     int currentSlotOffset;					//2 byte
 *     //the next two fields present only if NIC == UnconnectedBroadcast
 *     int beaconPeriodLength;					//1 byte
 *     int allocationSlotLength;				//1 byte
 * 											//if connected,	total: 4 bytes + 7 bytes in header
 * 											//unconnected, 	total: 6 bytes + 7 bytes in header
 * }
 * </pre>
 */
class BaselineTPollPacket : public ::BaselineMacPacket
{
  protected:
    int currentBeaconPeriod;
    int currentAllocationSlot;
    int currentSlotOffset;
    int beaconPeriodLength;
    int allocationSlotLength;

  private:
    void copy(const BaselineTPollPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BaselineTPollPacket&);

  public:
    BaselineTPollPacket(const char *name=nullptr, short kind=0);
    BaselineTPollPacket(const BaselineTPollPacket& other);
    virtual ~BaselineTPollPacket();
    BaselineTPollPacket& operator=(const BaselineTPollPacket& other);
    virtual BaselineTPollPacket *dup() const override {return new BaselineTPollPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getCurrentBeaconPeriod() const;
    virtual void setCurrentBeaconPeriod(int currentBeaconPeriod);
    virtual int getCurrentAllocationSlot() const;
    virtual void setCurrentAllocationSlot(int currentAllocationSlot);
    virtual int getCurrentSlotOffset() const;
    virtual void setCurrentSlotOffset(int currentSlotOffset);
    virtual int getBeaconPeriodLength() const;
    virtual void setBeaconPeriodLength(int beaconPeriodLength);
    virtual int getAllocationSlotLength() const;
    virtual void setAllocationSlotLength(int allocationSlotLength);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BaselineTPollPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BaselineTPollPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef __BASELINEMACPACKET_M_H

