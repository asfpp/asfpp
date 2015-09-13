//
// Generated file, do not edit! Created by opp_msgc 4.5 from src/node/application/clusterAggregator/ClusterAggregatorPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ClusterAggregatorPacket_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
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

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(ClusterAggregatorDataPacket);

ClusterAggregatorDataPacket::ClusterAggregatorDataPacket(const char *name, int kind) : ::ApplicationPacket(name,kind)
{
    this->sourceNodeID_var = 0;
    this->digest_var = 0;
}

ClusterAggregatorDataPacket::ClusterAggregatorDataPacket(const ClusterAggregatorDataPacket& other) : ::ApplicationPacket(other)
{
    copy(other);
}

ClusterAggregatorDataPacket::~ClusterAggregatorDataPacket()
{
}

ClusterAggregatorDataPacket& ClusterAggregatorDataPacket::operator=(const ClusterAggregatorDataPacket& other)
{
    if (this==&other) return *this;
    ::ApplicationPacket::operator=(other);
    copy(other);
    return *this;
}

void ClusterAggregatorDataPacket::copy(const ClusterAggregatorDataPacket& other)
{
    this->sourceNodeID_var = other.sourceNodeID_var;
    this->digest_var = other.digest_var;
}

void ClusterAggregatorDataPacket::parsimPack(cCommBuffer *b)
{
    ::ApplicationPacket::parsimPack(b);
    doPacking(b,this->sourceNodeID_var);
    doPacking(b,this->digest_var);
}

void ClusterAggregatorDataPacket::parsimUnpack(cCommBuffer *b)
{
    ::ApplicationPacket::parsimUnpack(b);
    doUnpacking(b,this->sourceNodeID_var);
    doUnpacking(b,this->digest_var);
}

int ClusterAggregatorDataPacket::getSourceNodeID() const
{
    return sourceNodeID_var;
}

void ClusterAggregatorDataPacket::setSourceNodeID(int sourceNodeID)
{
    this->sourceNodeID_var = sourceNodeID;
}

int ClusterAggregatorDataPacket::getDigest() const
{
    return digest_var;
}

void ClusterAggregatorDataPacket::setDigest(int digest)
{
    this->digest_var = digest;
}

class ClusterAggregatorDataPacketDescriptor : public cClassDescriptor
{
  public:
    ClusterAggregatorDataPacketDescriptor();
    virtual ~ClusterAggregatorDataPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ClusterAggregatorDataPacketDescriptor);

ClusterAggregatorDataPacketDescriptor::ClusterAggregatorDataPacketDescriptor() : cClassDescriptor("ClusterAggregatorDataPacket", "ApplicationPacket")
{
}

ClusterAggregatorDataPacketDescriptor::~ClusterAggregatorDataPacketDescriptor()
{
}

bool ClusterAggregatorDataPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ClusterAggregatorDataPacket *>(obj)!=NULL;
}

const char *ClusterAggregatorDataPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ClusterAggregatorDataPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int ClusterAggregatorDataPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *ClusterAggregatorDataPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sourceNodeID",
        "digest",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int ClusterAggregatorDataPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceNodeID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "digest")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ClusterAggregatorDataPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *ClusterAggregatorDataPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ClusterAggregatorDataPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ClusterAggregatorDataPacket *pp = (ClusterAggregatorDataPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ClusterAggregatorDataPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ClusterAggregatorDataPacket *pp = (ClusterAggregatorDataPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSourceNodeID());
        case 1: return long2string(pp->getDigest());
        default: return "";
    }
}

bool ClusterAggregatorDataPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ClusterAggregatorDataPacket *pp = (ClusterAggregatorDataPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceNodeID(string2long(value)); return true;
        case 1: pp->setDigest(string2long(value)); return true;
        default: return false;
    }
}

const char *ClusterAggregatorDataPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ClusterAggregatorDataPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ClusterAggregatorDataPacket *pp = (ClusterAggregatorDataPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


