//
// Generated file, do not edit! Created by nedtool 5.4 from node/communication/routing/aodvRouting/AodvRoutingRrepPacket.msg.
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
#include "AodvRoutingRrepPacket_m.h"

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

Register_Class(AodvRREPPacket)

AodvRREPPacket::AodvRREPPacket(const char *name, short kind) : ::PacketId(name,kind)
{
    this->flagR = false;
    this->flagA = false;
    this->prefixSz = 0;
    this->hopCount = 0;
    this->destinationSeqNum = 0;
    this->lifetime = 0;
}

AodvRREPPacket::AodvRREPPacket(const AodvRREPPacket& other) : ::PacketId(other)
{
    copy(other);
}

AodvRREPPacket::~AodvRREPPacket()
{
}

AodvRREPPacket& AodvRREPPacket::operator=(const AodvRREPPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRREPPacket::copy(const AodvRREPPacket& other)
{
    this->flagR = other.flagR;
    this->flagA = other.flagA;
    this->prefixSz = other.prefixSz;
    this->hopCount = other.hopCount;
    this->originator = other.originator;
    this->destinationSeqNum = other.destinationSeqNum;
    this->destinationAodv = other.destinationAodv;
    this->lifetime = other.lifetime;
}

void AodvRREPPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::PacketId::parsimPack(b);
    doParsimPacking(b,this->flagR);
    doParsimPacking(b,this->flagA);
    doParsimPacking(b,this->prefixSz);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->originator);
    doParsimPacking(b,this->destinationSeqNum);
    doParsimPacking(b,this->destinationAodv);
    doParsimPacking(b,this->lifetime);
}

void AodvRREPPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doParsimUnpacking(b,this->flagR);
    doParsimUnpacking(b,this->flagA);
    doParsimUnpacking(b,this->prefixSz);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->originator);
    doParsimUnpacking(b,this->destinationSeqNum);
    doParsimUnpacking(b,this->destinationAodv);
    doParsimUnpacking(b,this->lifetime);
}

bool AodvRREPPacket::getFlagR() const
{
    return this->flagR;
}

void AodvRREPPacket::setFlagR(bool flagR)
{
    this->flagR = flagR;
}

bool AodvRREPPacket::getFlagA() const
{
    return this->flagA;
}

void AodvRREPPacket::setFlagA(bool flagA)
{
    this->flagA = flagA;
}

int AodvRREPPacket::getPrefixSz() const
{
    return this->prefixSz;
}

void AodvRREPPacket::setPrefixSz(int prefixSz)
{
    this->prefixSz = prefixSz;
}

int AodvRREPPacket::getHopCount() const
{
    return this->hopCount;
}

void AodvRREPPacket::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

const char * AodvRREPPacket::getOriginator() const
{
    return this->originator.c_str();
}

void AodvRREPPacket::setOriginator(const char * originator)
{
    this->originator = originator;
}

unsigned long AodvRREPPacket::getDestinationSeqNum() const
{
    return this->destinationSeqNum;
}

void AodvRREPPacket::setDestinationSeqNum(unsigned long destinationSeqNum)
{
    this->destinationSeqNum = destinationSeqNum;
}

const char * AodvRREPPacket::getDestinationAodv() const
{
    return this->destinationAodv.c_str();
}

void AodvRREPPacket::setDestinationAodv(const char * destinationAodv)
{
    this->destinationAodv = destinationAodv;
}

double AodvRREPPacket::getLifetime() const
{
    return this->lifetime;
}

void AodvRREPPacket::setLifetime(double lifetime)
{
    this->lifetime = lifetime;
}

class AodvRREPPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AodvRREPPacketDescriptor();
    virtual ~AodvRREPPacketDescriptor();

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

Register_ClassDescriptor(AodvRREPPacketDescriptor)

AodvRREPPacketDescriptor::AodvRREPPacketDescriptor() : omnetpp::cClassDescriptor("AodvRREPPacket", "PacketId")
{
    propertynames = nullptr;
}

AodvRREPPacketDescriptor::~AodvRREPPacketDescriptor()
{
    delete[] propertynames;
}

bool AodvRREPPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvRREPPacket *>(obj)!=nullptr;
}

const char **AodvRREPPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AodvRREPPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AodvRREPPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int AodvRREPPacketDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *AodvRREPPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flagR",
        "flagA",
        "prefixSz",
        "hopCount",
        "originator",
        "destinationSeqNum",
        "destinationAodv",
        "lifetime",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int AodvRREPPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagR")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagA")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixSz")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "originator")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationSeqNum")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAodv")==0) return base+6;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifetime")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AodvRREPPacketDescriptor::getFieldTypeString(int field) const
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
        "int",
        "int",
        "string",
        "unsigned long",
        "string",
        "double",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **AodvRREPPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *AodvRREPPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AodvRREPPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AodvRREPPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvRREPPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlagR());
        case 1: return bool2string(pp->getFlagA());
        case 2: return long2string(pp->getPrefixSz());
        case 3: return long2string(pp->getHopCount());
        case 4: return oppstring2string(pp->getOriginator());
        case 5: return ulong2string(pp->getDestinationSeqNum());
        case 6: return oppstring2string(pp->getDestinationAodv());
        case 7: return double2string(pp->getLifetime());
        default: return "";
    }
}

bool AodvRREPPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlagR(string2bool(value)); return true;
        case 1: pp->setFlagA(string2bool(value)); return true;
        case 2: pp->setPrefixSz(string2long(value)); return true;
        case 3: pp->setHopCount(string2long(value)); return true;
        case 4: pp->setOriginator((value)); return true;
        case 5: pp->setDestinationSeqNum(string2ulong(value)); return true;
        case 6: pp->setDestinationAodv((value)); return true;
        case 7: pp->setLifetime(string2double(value)); return true;
        default: return false;
    }
}

const char *AodvRREPPacketDescriptor::getFieldStructName(int field) const
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

void *AodvRREPPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


