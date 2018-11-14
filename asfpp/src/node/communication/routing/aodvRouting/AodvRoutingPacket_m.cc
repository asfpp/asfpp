//
// Generated file, do not edit! Created by nedtool 5.4 from node/communication/routing/aodvRouting/AodvRoutingPacket.msg.
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
#include "AodvRoutingPacket_m.h"

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

Register_Class(AodvRREQPacket)

AodvRREQPacket::AodvRREQPacket(const char *name, short kind) : ::PacketId(name,kind)
{
    this->flagJ = false;
    this->flagR = false;
    this->flagG = false;
    this->flagD = false;
    this->flagU = false;
    this->hopCount = 0;
    this->rreqID = 0;
    this->sourceSeqNum = 0;
    this->destinationSeqNum = 0;
    this->ttl = 0;
}

AodvRREQPacket::AodvRREQPacket(const AodvRREQPacket& other) : ::PacketId(other)
{
    copy(other);
}

AodvRREQPacket::~AodvRREQPacket()
{
}

AodvRREQPacket& AodvRREQPacket::operator=(const AodvRREQPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRREQPacket::copy(const AodvRREQPacket& other)
{
    this->flagJ = other.flagJ;
    this->flagR = other.flagR;
    this->flagG = other.flagG;
    this->flagD = other.flagD;
    this->flagU = other.flagU;
    this->hopCount = other.hopCount;
    this->rreqID = other.rreqID;
    this->sourceAodv = other.sourceAodv;
    this->sourceSeqNum = other.sourceSeqNum;
    this->destinationSeqNum = other.destinationSeqNum;
    this->destinationAodv = other.destinationAodv;
    this->ttl = other.ttl;
}

void AodvRREQPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PacketId::parsimPack(b);
    doParsimPacking(b,this->flagJ);
    doParsimPacking(b,this->flagR);
    doParsimPacking(b,this->flagG);
    doParsimPacking(b,this->flagD);
    doParsimPacking(b,this->flagU);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->rreqID);
    doParsimPacking(b,this->sourceAodv);
    doParsimPacking(b,this->sourceSeqNum);
    doParsimPacking(b,this->destinationSeqNum);
    doParsimPacking(b,this->destinationAodv);
    doParsimPacking(b,this->ttl);
}

void AodvRREQPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doParsimUnpacking(b,this->flagJ);
    doParsimUnpacking(b,this->flagR);
    doParsimUnpacking(b,this->flagG);
    doParsimUnpacking(b,this->flagD);
    doParsimUnpacking(b,this->flagU);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->rreqID);
    doParsimUnpacking(b,this->sourceAodv);
    doParsimUnpacking(b,this->sourceSeqNum);
    doParsimUnpacking(b,this->destinationSeqNum);
    doParsimUnpacking(b,this->destinationAodv);
    doParsimUnpacking(b,this->ttl);
}

bool AodvRREQPacket::getFlagJ() const
{
    return this->flagJ;
}

void AodvRREQPacket::setFlagJ(bool flagJ)
{
    this->flagJ = flagJ;
}

bool AodvRREQPacket::getFlagR() const
{
    return this->flagR;
}

void AodvRREQPacket::setFlagR(bool flagR)
{
    this->flagR = flagR;
}

bool AodvRREQPacket::getFlagG() const
{
    return this->flagG;
}

void AodvRREQPacket::setFlagG(bool flagG)
{
    this->flagG = flagG;
}

bool AodvRREQPacket::getFlagD() const
{
    return this->flagD;
}

void AodvRREQPacket::setFlagD(bool flagD)
{
    this->flagD = flagD;
}

bool AodvRREQPacket::getFlagU() const
{
    return this->flagU;
}

void AodvRREQPacket::setFlagU(bool flagU)
{
    this->flagU = flagU;
}

int AodvRREQPacket::getHopCount() const
{
    return this->hopCount;
}

void AodvRREQPacket::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

int AodvRREQPacket::getRreqID() const
{
    return this->rreqID;
}

void AodvRREQPacket::setRreqID(int rreqID)
{
    this->rreqID = rreqID;
}

const char * AodvRREQPacket::getSourceAodv() const
{
    return this->sourceAodv.c_str();
}

void AodvRREQPacket::setSourceAodv(const char * sourceAodv)
{
    this->sourceAodv = sourceAodv;
}

unsigned long AodvRREQPacket::getSourceSeqNum() const
{
    return this->sourceSeqNum;
}

void AodvRREQPacket::setSourceSeqNum(unsigned long sourceSeqNum)
{
    this->sourceSeqNum = sourceSeqNum;
}

unsigned long AodvRREQPacket::getDestinationSeqNum() const
{
    return this->destinationSeqNum;
}

void AodvRREQPacket::setDestinationSeqNum(unsigned long destinationSeqNum)
{
    this->destinationSeqNum = destinationSeqNum;
}

const char * AodvRREQPacket::getDestinationAodv() const
{
    return this->destinationAodv.c_str();
}

void AodvRREQPacket::setDestinationAodv(const char * destinationAodv)
{
    this->destinationAodv = destinationAodv;
}

unsigned int AodvRREQPacket::getTtl() const
{
    return this->ttl;
}

void AodvRREQPacket::setTtl(unsigned int ttl)
{
    this->ttl = ttl;
}

class AodvRREQPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AodvRREQPacketDescriptor();
    virtual ~AodvRREQPacketDescriptor();

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

Register_ClassDescriptor(AodvRREQPacketDescriptor)

AodvRREQPacketDescriptor::AodvRREQPacketDescriptor() : omnetpp::cClassDescriptor("AodvRREQPacket", "PacketId")
{
    propertynames = nullptr;
}

AodvRREQPacketDescriptor::~AodvRREQPacketDescriptor()
{
    delete[] propertynames;
}

bool AodvRREQPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvRREQPacket *>(obj)!=nullptr;
}

const char **AodvRREQPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AodvRREQPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AodvRREQPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int AodvRREQPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *AodvRREQPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flagJ",
        "flagR",
        "flagG",
        "flagD",
        "flagU",
        "hopCount",
        "rreqID",
        "sourceAodv",
        "sourceSeqNum",
        "destinationSeqNum",
        "destinationAodv",
        "ttl",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int AodvRREQPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagJ")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagR")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagG")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagD")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagU")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "rreqID")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAodv")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceSeqNum")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationSeqNum")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAodv")==0) return base+10;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AodvRREQPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "int",
        "int",
        "string",
        "unsigned long",
        "unsigned long",
        "string",
        "unsigned int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **AodvRREQPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *AodvRREQPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AodvRREQPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AodvRREQPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvRREQPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlagJ());
        case 1: return bool2string(pp->getFlagR());
        case 2: return bool2string(pp->getFlagG());
        case 3: return bool2string(pp->getFlagD());
        case 4: return bool2string(pp->getFlagU());
        case 5: return long2string(pp->getHopCount());
        case 6: return long2string(pp->getRreqID());
        case 7: return oppstring2string(pp->getSourceAodv());
        case 8: return ulong2string(pp->getSourceSeqNum());
        case 9: return ulong2string(pp->getDestinationSeqNum());
        case 10: return oppstring2string(pp->getDestinationAodv());
        case 11: return ulong2string(pp->getTtl());
        default: return "";
    }
}

bool AodvRREQPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlagJ(string2bool(value)); return true;
        case 1: pp->setFlagR(string2bool(value)); return true;
        case 2: pp->setFlagG(string2bool(value)); return true;
        case 3: pp->setFlagD(string2bool(value)); return true;
        case 4: pp->setFlagU(string2bool(value)); return true;
        case 5: pp->setHopCount(string2long(value)); return true;
        case 6: pp->setRreqID(string2long(value)); return true;
        case 7: pp->setSourceAodv((value)); return true;
        case 8: pp->setSourceSeqNum(string2ulong(value)); return true;
        case 9: pp->setDestinationSeqNum(string2ulong(value)); return true;
        case 10: pp->setDestinationAodv((value)); return true;
        case 11: pp->setTtl(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AodvRREQPacketDescriptor::getFieldStructName(int field) const
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

void *AodvRREQPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AodvHelloMessage)

AodvHelloMessage::AodvHelloMessage(const char *name, short kind) : ::PacketId(name,kind)
{
    this->destinationSeqNum = 0;
}

AodvHelloMessage::AodvHelloMessage(const AodvHelloMessage& other) : ::PacketId(other)
{
    copy(other);
}

AodvHelloMessage::~AodvHelloMessage()
{
}

AodvHelloMessage& AodvHelloMessage::operator=(const AodvHelloMessage& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvHelloMessage::copy(const AodvHelloMessage& other)
{
    this->destinationSeqNum = other.destinationSeqNum;
}

void AodvHelloMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PacketId::parsimPack(b);
    doParsimPacking(b,this->destinationSeqNum);
}

void AodvHelloMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doParsimUnpacking(b,this->destinationSeqNum);
}

unsigned long AodvHelloMessage::getDestinationSeqNum() const
{
    return this->destinationSeqNum;
}

void AodvHelloMessage::setDestinationSeqNum(unsigned long destinationSeqNum)
{
    this->destinationSeqNum = destinationSeqNum;
}

class AodvHelloMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AodvHelloMessageDescriptor();
    virtual ~AodvHelloMessageDescriptor();

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

Register_ClassDescriptor(AodvHelloMessageDescriptor)

AodvHelloMessageDescriptor::AodvHelloMessageDescriptor() : omnetpp::cClassDescriptor("AodvHelloMessage", "PacketId")
{
    propertynames = nullptr;
}

AodvHelloMessageDescriptor::~AodvHelloMessageDescriptor()
{
    delete[] propertynames;
}

bool AodvHelloMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvHelloMessage *>(obj)!=nullptr;
}

const char **AodvHelloMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AodvHelloMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AodvHelloMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int AodvHelloMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *AodvHelloMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destinationSeqNum",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int AodvHelloMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationSeqNum")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AodvHelloMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **AodvHelloMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *AodvHelloMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AodvHelloMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AodvHelloMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvHelloMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getDestinationSeqNum());
        default: return "";
    }
}

bool AodvHelloMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setDestinationSeqNum(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AodvHelloMessageDescriptor::getFieldStructName(int field) const
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

void *AodvHelloMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AodvRREPAckPacket)

AodvRREPAckPacket::AodvRREPAckPacket(const char *name, short kind) : ::PacketId(name,kind)
{
}

AodvRREPAckPacket::AodvRREPAckPacket(const AodvRREPAckPacket& other) : ::PacketId(other)
{
    copy(other);
}

AodvRREPAckPacket::~AodvRREPAckPacket()
{
}

AodvRREPAckPacket& AodvRREPAckPacket::operator=(const AodvRREPAckPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRREPAckPacket::copy(const AodvRREPAckPacket& other)
{
}

void AodvRREPAckPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PacketId::parsimPack(b);
}

void AodvRREPAckPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
}

class AodvRREPAckPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AodvRREPAckPacketDescriptor();
    virtual ~AodvRREPAckPacketDescriptor();

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

Register_ClassDescriptor(AodvRREPAckPacketDescriptor)

AodvRREPAckPacketDescriptor::AodvRREPAckPacketDescriptor() : omnetpp::cClassDescriptor("AodvRREPAckPacket", "PacketId")
{
    propertynames = nullptr;
}

AodvRREPAckPacketDescriptor::~AodvRREPAckPacketDescriptor()
{
    delete[] propertynames;
}

bool AodvRREPAckPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvRREPAckPacket *>(obj)!=nullptr;
}

const char **AodvRREPAckPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AodvRREPAckPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AodvRREPAckPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int AodvRREPAckPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *AodvRREPAckPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int AodvRREPAckPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AodvRREPAckPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **AodvRREPAckPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *AodvRREPAckPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AodvRREPAckPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AodvRREPAckPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvRREPAckPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool AodvRREPAckPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AodvRREPAckPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *AodvRREPAckPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AodvRERRPacket)

AodvRERRPacket::AodvRERRPacket(const char *name, short kind) : ::PacketId(name,kind)
{
    this->flagN = false;
    this->destCount = 0;
    unreachableDestAddr_arraysize = 0;
    this->unreachableDestAddr = 0;
    unreachableDestSeqNum_arraysize = 0;
    this->unreachableDestSeqNum = 0;
}

AodvRERRPacket::AodvRERRPacket(const AodvRERRPacket& other) : ::PacketId(other)
{
    unreachableDestAddr_arraysize = 0;
    this->unreachableDestAddr = 0;
    unreachableDestSeqNum_arraysize = 0;
    this->unreachableDestSeqNum = 0;
    copy(other);
}

AodvRERRPacket::~AodvRERRPacket()
{
    delete [] this->unreachableDestAddr;
    delete [] this->unreachableDestSeqNum;
}

AodvRERRPacket& AodvRERRPacket::operator=(const AodvRERRPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRERRPacket::copy(const AodvRERRPacket& other)
{
    this->flagN = other.flagN;
    this->destCount = other.destCount;
    delete [] this->unreachableDestAddr;
    this->unreachableDestAddr = (other.unreachableDestAddr_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.unreachableDestAddr_arraysize];
    unreachableDestAddr_arraysize = other.unreachableDestAddr_arraysize;
    for (unsigned int i=0; i<unreachableDestAddr_arraysize; i++)
        this->unreachableDestAddr[i] = other.unreachableDestAddr[i];
    delete [] this->unreachableDestSeqNum;
    this->unreachableDestSeqNum = (other.unreachableDestSeqNum_arraysize==0) ? nullptr : new unsigned long[other.unreachableDestSeqNum_arraysize];
    unreachableDestSeqNum_arraysize = other.unreachableDestSeqNum_arraysize;
    for (unsigned int i=0; i<unreachableDestSeqNum_arraysize; i++)
        this->unreachableDestSeqNum[i] = other.unreachableDestSeqNum[i];
}

void AodvRERRPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PacketId::parsimPack(b);
    doParsimPacking(b,this->flagN);
    doParsimPacking(b,this->destCount);
    b->pack(unreachableDestAddr_arraysize);
    doParsimArrayPacking(b,this->unreachableDestAddr,unreachableDestAddr_arraysize);
    b->pack(unreachableDestSeqNum_arraysize);
    doParsimArrayPacking(b,this->unreachableDestSeqNum,unreachableDestSeqNum_arraysize);
}

void AodvRERRPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doParsimUnpacking(b,this->flagN);
    doParsimUnpacking(b,this->destCount);
    delete [] this->unreachableDestAddr;
    b->unpack(unreachableDestAddr_arraysize);
    if (unreachableDestAddr_arraysize==0) {
        this->unreachableDestAddr = 0;
    } else {
        this->unreachableDestAddr = new ::omnetpp::opp_string[unreachableDestAddr_arraysize];
        doParsimArrayUnpacking(b,this->unreachableDestAddr,unreachableDestAddr_arraysize);
    }
    delete [] this->unreachableDestSeqNum;
    b->unpack(unreachableDestSeqNum_arraysize);
    if (unreachableDestSeqNum_arraysize==0) {
        this->unreachableDestSeqNum = 0;
    } else {
        this->unreachableDestSeqNum = new unsigned long[unreachableDestSeqNum_arraysize];
        doParsimArrayUnpacking(b,this->unreachableDestSeqNum,unreachableDestSeqNum_arraysize);
    }
}

bool AodvRERRPacket::getFlagN() const
{
    return this->flagN;
}

void AodvRERRPacket::setFlagN(bool flagN)
{
    this->flagN = flagN;
}

int AodvRERRPacket::getDestCount() const
{
    return this->destCount;
}

void AodvRERRPacket::setDestCount(int destCount)
{
    this->destCount = destCount;
}

void AodvRERRPacket::setUnreachableDestAddrArraySize(unsigned int size)
{
    ::omnetpp::opp_string *unreachableDestAddr2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = unreachableDestAddr_arraysize < size ? unreachableDestAddr_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableDestAddr2[i] = this->unreachableDestAddr[i];
    for (unsigned int i=sz; i<size; i++)
        unreachableDestAddr2[i] = 0;
    unreachableDestAddr_arraysize = size;
    delete [] this->unreachableDestAddr;
    this->unreachableDestAddr = unreachableDestAddr2;
}

unsigned int AodvRERRPacket::getUnreachableDestAddrArraySize() const
{
    return unreachableDestAddr_arraysize;
}

const char * AodvRERRPacket::getUnreachableDestAddr(unsigned int k) const
{
    if (k>=unreachableDestAddr_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableDestAddr_arraysize, k);
    return this->unreachableDestAddr[k].c_str();
}

void AodvRERRPacket::setUnreachableDestAddr(unsigned int k, const char * unreachableDestAddr)
{
    if (k>=unreachableDestAddr_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableDestAddr_arraysize, k);
    this->unreachableDestAddr[k] = unreachableDestAddr;
}

void AodvRERRPacket::setUnreachableDestSeqNumArraySize(unsigned int size)
{
    unsigned long *unreachableDestSeqNum2 = (size==0) ? nullptr : new unsigned long[size];
    unsigned int sz = unreachableDestSeqNum_arraysize < size ? unreachableDestSeqNum_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableDestSeqNum2[i] = this->unreachableDestSeqNum[i];
    for (unsigned int i=sz; i<size; i++)
        unreachableDestSeqNum2[i] = 0;
    unreachableDestSeqNum_arraysize = size;
    delete [] this->unreachableDestSeqNum;
    this->unreachableDestSeqNum = unreachableDestSeqNum2;
}

unsigned int AodvRERRPacket::getUnreachableDestSeqNumArraySize() const
{
    return unreachableDestSeqNum_arraysize;
}

unsigned long AodvRERRPacket::getUnreachableDestSeqNum(unsigned int k) const
{
    if (k>=unreachableDestSeqNum_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableDestSeqNum_arraysize, k);
    return this->unreachableDestSeqNum[k];
}

void AodvRERRPacket::setUnreachableDestSeqNum(unsigned int k, unsigned long unreachableDestSeqNum)
{
    if (k>=unreachableDestSeqNum_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableDestSeqNum_arraysize, k);
    this->unreachableDestSeqNum[k] = unreachableDestSeqNum;
}

class AodvRERRPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AodvRERRPacketDescriptor();
    virtual ~AodvRERRPacketDescriptor();

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

Register_ClassDescriptor(AodvRERRPacketDescriptor)

AodvRERRPacketDescriptor::AodvRERRPacketDescriptor() : omnetpp::cClassDescriptor("AodvRERRPacket", "PacketId")
{
    propertynames = nullptr;
}

AodvRERRPacketDescriptor::~AodvRERRPacketDescriptor()
{
    delete[] propertynames;
}

bool AodvRERRPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvRERRPacket *>(obj)!=nullptr;
}

const char **AodvRERRPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AodvRERRPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AodvRERRPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int AodvRERRPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *AodvRERRPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flagN",
        "destCount",
        "unreachableDestAddr",
        "unreachableDestSeqNum",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int AodvRERRPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagN")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destCount")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableDestAddr")==0) return base+2;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableDestSeqNum")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AodvRERRPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "string",
        "unsigned long",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **AodvRERRPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *AodvRERRPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AodvRERRPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        case 2: return pp->getUnreachableDestAddrArraySize();
        case 3: return pp->getUnreachableDestSeqNumArraySize();
        default: return 0;
    }
}

const char *AodvRERRPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvRERRPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlagN());
        case 1: return long2string(pp->getDestCount());
        case 2: return oppstring2string(pp->getUnreachableDestAddr(i));
        case 3: return ulong2string(pp->getUnreachableDestSeqNum(i));
        default: return "";
    }
}

bool AodvRERRPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlagN(string2bool(value)); return true;
        case 1: pp->setDestCount(string2long(value)); return true;
        case 2: pp->setUnreachableDestAddr(i,(value)); return true;
        case 3: pp->setUnreachableDestSeqNum(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *AodvRERRPacketDescriptor::getFieldStructName(int field) const
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

void *AodvRERRPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


