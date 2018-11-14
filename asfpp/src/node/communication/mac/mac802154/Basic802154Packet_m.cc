//
// Generated file, do not edit! Created by nedtool 5.4 from node/communication/mac/mac802154/Basic802154Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "Basic802154Packet_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("Mac802154Packet_type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("Mac802154Packet_type"));
    e->insert(MAC_802154_BEACON_PACKET, "MAC_802154_BEACON_PACKET");
    e->insert(MAC_802154_ASSOCIATE_PACKET, "MAC_802154_ASSOCIATE_PACKET");
    e->insert(MAC_802154_DATA_PACKET, "MAC_802154_DATA_PACKET");
    e->insert(MAC_802154_ACK_PACKET, "MAC_802154_ACK_PACKET");
    e->insert(MAC_802154_GTS_REQUEST_PACKET, "MAC_802154_GTS_REQUEST_PACKET");
)

Basic802154GTSspec::Basic802154GTSspec()
{
    this->owner = 0;
    this->start = 0;
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const Basic802154GTSspec& a)
{
    doParsimPacking(b,a.owner);
    doParsimPacking(b,a.start);
    doParsimPacking(b,a.length);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Basic802154GTSspec& a)
{
    doParsimUnpacking(b,a.owner);
    doParsimUnpacking(b,a.start);
    doParsimUnpacking(b,a.length);
}

class Basic802154GTSspecDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Basic802154GTSspecDescriptor();
    virtual ~Basic802154GTSspecDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Basic802154GTSspecDescriptor)

Basic802154GTSspecDescriptor::Basic802154GTSspecDescriptor() : omnetpp::cClassDescriptor("Basic802154GTSspec", "")
{
    propertynames = nullptr;
}

Basic802154GTSspecDescriptor::~Basic802154GTSspecDescriptor()
{
    delete[] propertynames;
}

bool Basic802154GTSspecDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Basic802154GTSspec *>(obj)!=nullptr;
}

const char **Basic802154GTSspecDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Basic802154GTSspecDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Basic802154GTSspecDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Basic802154GTSspecDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Basic802154GTSspecDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "owner",
        "start",
        "length",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Basic802154GTSspecDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "owner")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "start")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Basic802154GTSspecDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Basic802154GTSspecDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Basic802154GTSspecDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Basic802154GTSspecDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Basic802154GTSspecDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Basic802154GTSspecDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->owner);
        case 1: return long2string(pp->start);
        case 2: return long2string(pp->length);
        default: return "";
    }
}

bool Basic802154GTSspecDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        case 0: pp->owner = string2long(value); return true;
        case 1: pp->start = string2long(value); return true;
        case 2: pp->length = string2long(value); return true;
        default: return false;
    }
}

const char *Basic802154GTSspecDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Basic802154GTSspecDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Basic802154Packet)

Basic802154Packet::Basic802154Packet(const char *name, short kind) : ::MacPacket(name,kind)
{
    this->Mac802154PacketType = 0;
    this->PANid = 0;
    this->srcID = 0;
    this->dstID = 0;
    this->seqNum = 0;
    this->beaconOrder = 0;
    this->frameOrder = 0;
    this->BSN = 0;
    this->CAPlength = 0;
    this->GTSlength = 0;
    GTSlist_arraysize = 0;
    this->GTSlist = 0;
}

Basic802154Packet::Basic802154Packet(const Basic802154Packet& other) : ::MacPacket(other)
{
    GTSlist_arraysize = 0;
    this->GTSlist = 0;
    copy(other);
}

Basic802154Packet::~Basic802154Packet()
{
    delete [] this->GTSlist;
}

Basic802154Packet& Basic802154Packet::operator=(const Basic802154Packet& other)
{
    if (this==&other) return *this;
    ::MacPacket::operator=(other);
    copy(other);
    return *this;
}

void Basic802154Packet::copy(const Basic802154Packet& other)
{
    this->Mac802154PacketType = other.Mac802154PacketType;
    this->PANid = other.PANid;
    this->srcID = other.srcID;
    this->dstID = other.dstID;
    this->seqNum = other.seqNum;
    this->beaconOrder = other.beaconOrder;
    this->frameOrder = other.frameOrder;
    this->BSN = other.BSN;
    this->CAPlength = other.CAPlength;
    this->GTSlength = other.GTSlength;
    delete [] this->GTSlist;
    this->GTSlist = (other.GTSlist_arraysize==0) ? nullptr : new Basic802154GTSspec[other.GTSlist_arraysize];
    GTSlist_arraysize = other.GTSlist_arraysize;
    for (unsigned int i=0; i<GTSlist_arraysize; i++)
        this->GTSlist[i] = other.GTSlist[i];
}

void Basic802154Packet::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MacPacket::parsimPack(b);
    doParsimPacking(b,this->Mac802154PacketType);
    doParsimPacking(b,this->PANid);
    doParsimPacking(b,this->srcID);
    doParsimPacking(b,this->dstID);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->beaconOrder);
    doParsimPacking(b,this->frameOrder);
    doParsimPacking(b,this->BSN);
    doParsimPacking(b,this->CAPlength);
    doParsimPacking(b,this->GTSlength);
    b->pack(GTSlist_arraysize);
    doParsimArrayPacking(b,this->GTSlist,GTSlist_arraysize);
}

void Basic802154Packet::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MacPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->Mac802154PacketType);
    doParsimUnpacking(b,this->PANid);
    doParsimUnpacking(b,this->srcID);
    doParsimUnpacking(b,this->dstID);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->beaconOrder);
    doParsimUnpacking(b,this->frameOrder);
    doParsimUnpacking(b,this->BSN);
    doParsimUnpacking(b,this->CAPlength);
    doParsimUnpacking(b,this->GTSlength);
    delete [] this->GTSlist;
    b->unpack(GTSlist_arraysize);
    if (GTSlist_arraysize==0) {
        this->GTSlist = 0;
    } else {
        this->GTSlist = new Basic802154GTSspec[GTSlist_arraysize];
        doParsimArrayUnpacking(b,this->GTSlist,GTSlist_arraysize);
    }
}

int Basic802154Packet::getMac802154PacketType() const
{
    return this->Mac802154PacketType;
}

void Basic802154Packet::setMac802154PacketType(int Mac802154PacketType)
{
    this->Mac802154PacketType = Mac802154PacketType;
}

int Basic802154Packet::getPANid() const
{
    return this->PANid;
}

void Basic802154Packet::setPANid(int PANid)
{
    this->PANid = PANid;
}

int Basic802154Packet::getSrcID() const
{
    return this->srcID;
}

void Basic802154Packet::setSrcID(int srcID)
{
    this->srcID = srcID;
}

int Basic802154Packet::getDstID() const
{
    return this->dstID;
}

void Basic802154Packet::setDstID(int dstID)
{
    this->dstID = dstID;
}

int Basic802154Packet::getSeqNum() const
{
    return this->seqNum;
}

void Basic802154Packet::setSeqNum(int seqNum)
{
    this->seqNum = seqNum;
}

int Basic802154Packet::getBeaconOrder() const
{
    return this->beaconOrder;
}

void Basic802154Packet::setBeaconOrder(int beaconOrder)
{
    this->beaconOrder = beaconOrder;
}

int Basic802154Packet::getFrameOrder() const
{
    return this->frameOrder;
}

void Basic802154Packet::setFrameOrder(int frameOrder)
{
    this->frameOrder = frameOrder;
}

int Basic802154Packet::getBSN() const
{
    return this->BSN;
}

void Basic802154Packet::setBSN(int BSN)
{
    this->BSN = BSN;
}

int Basic802154Packet::getCAPlength() const
{
    return this->CAPlength;
}

void Basic802154Packet::setCAPlength(int CAPlength)
{
    this->CAPlength = CAPlength;
}

int Basic802154Packet::getGTSlength() const
{
    return this->GTSlength;
}

void Basic802154Packet::setGTSlength(int GTSlength)
{
    this->GTSlength = GTSlength;
}

void Basic802154Packet::setGTSlistArraySize(unsigned int size)
{
    Basic802154GTSspec *GTSlist2 = (size==0) ? nullptr : new Basic802154GTSspec[size];
    unsigned int sz = GTSlist_arraysize < size ? GTSlist_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        GTSlist2[i] = this->GTSlist[i];
    GTSlist_arraysize = size;
    delete [] this->GTSlist;
    this->GTSlist = GTSlist2;
}

unsigned int Basic802154Packet::getGTSlistArraySize() const
{
    return GTSlist_arraysize;
}

Basic802154GTSspec& Basic802154Packet::getGTSlist(unsigned int k)
{
    if (k>=GTSlist_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", GTSlist_arraysize, k);
    return this->GTSlist[k];
}

void Basic802154Packet::setGTSlist(unsigned int k, const Basic802154GTSspec& GTSlist)
{
    if (k>=GTSlist_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", GTSlist_arraysize, k);
    this->GTSlist[k] = GTSlist;
}

class Basic802154PacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Basic802154PacketDescriptor();
    virtual ~Basic802154PacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Basic802154PacketDescriptor)

Basic802154PacketDescriptor::Basic802154PacketDescriptor() : omnetpp::cClassDescriptor("Basic802154Packet", "MacPacket")
{
    propertynames = nullptr;
}

Basic802154PacketDescriptor::~Basic802154PacketDescriptor()
{
    delete[] propertynames;
}

bool Basic802154PacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Basic802154Packet *>(obj)!=nullptr;
}

const char **Basic802154PacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Basic802154PacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Basic802154PacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int Basic802154PacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *Basic802154PacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Mac802154PacketType",
        "PANid",
        "srcID",
        "dstID",
        "seqNum",
        "beaconOrder",
        "frameOrder",
        "BSN",
        "CAPlength",
        "GTSlength",
        "GTSlist",
    };
    return (field>=0 && field<11) ? fieldNames[field] : nullptr;
}

int Basic802154PacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='M' && strcmp(fieldName, "Mac802154PacketType")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PANid")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcID")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstID")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconOrder")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameOrder")==0) return base+6;
    if (fieldName[0]=='B' && strcmp(fieldName, "BSN")==0) return base+7;
    if (fieldName[0]=='C' && strcmp(fieldName, "CAPlength")==0) return base+8;
    if (fieldName[0]=='G' && strcmp(fieldName, "GTSlength")==0) return base+9;
    if (fieldName[0]=='G' && strcmp(fieldName, "GTSlist")==0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Basic802154PacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "Basic802154GTSspec",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : nullptr;
}

const char **Basic802154PacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Basic802154PacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "Mac802154Packet_type";
            return nullptr;
        default: return nullptr;
    }
}

int Basic802154PacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 10: return pp->getGTSlistArraySize();
        default: return 0;
    }
}

const char *Basic802154PacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Basic802154PacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getMac802154PacketType(), "Mac802154Packet_type");
        case 1: return long2string(pp->getPANid());
        case 2: return long2string(pp->getSrcID());
        case 3: return long2string(pp->getDstID());
        case 4: return long2string(pp->getSeqNum());
        case 5: return long2string(pp->getBeaconOrder());
        case 6: return long2string(pp->getFrameOrder());
        case 7: return long2string(pp->getBSN());
        case 8: return long2string(pp->getCAPlength());
        case 9: return long2string(pp->getGTSlength());
        case 10: {std::stringstream out; out << pp->getGTSlist(i); return out.str();}
        default: return "";
    }
}

bool Basic802154PacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setMac802154PacketType((Mac802154Packet_type)string2enum(value, "Mac802154Packet_type")); return true;
        case 1: pp->setPANid(string2long(value)); return true;
        case 2: pp->setSrcID(string2long(value)); return true;
        case 3: pp->setDstID(string2long(value)); return true;
        case 4: pp->setSeqNum(string2long(value)); return true;
        case 5: pp->setBeaconOrder(string2long(value)); return true;
        case 6: pp->setFrameOrder(string2long(value)); return true;
        case 7: pp->setBSN(string2long(value)); return true;
        case 8: pp->setCAPlength(string2long(value)); return true;
        case 9: pp->setGTSlength(string2long(value)); return true;
        default: return false;
    }
}

const char *Basic802154PacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 10: return omnetpp::opp_typename(typeid(Basic802154GTSspec));
        default: return nullptr;
    };
}

void *Basic802154PacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 10: return (void *)(&pp->getGTSlist(i)); break;
        default: return nullptr;
    }
}


