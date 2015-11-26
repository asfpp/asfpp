//
// Generated file, do not edit! Created by nedtool 4.6 from src/globalfilter/DestroyFireMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DestroyFireMessage_m.h"

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

Register_Class(DestroyFireMessage);

DestroyFireMessage::DestroyFireMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    take(&(this->physicalAttackWrapper_var));
}

DestroyFireMessage::DestroyFireMessage(const DestroyFireMessage& other) : ::cMessage(other)
{
    take(&(this->physicalAttackWrapper_var));
    copy(other);
}

DestroyFireMessage::~DestroyFireMessage()
{
    drop(&(this->physicalAttackWrapper_var));
}

DestroyFireMessage& DestroyFireMessage::operator=(const DestroyFireMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DestroyFireMessage::copy(const DestroyFireMessage& other)
{
    this->physicalAttackWrapper_var = other.physicalAttackWrapper_var;
    this->physicalAttackWrapper_var.setName(other.physicalAttackWrapper_var.getName());
}

void DestroyFireMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->physicalAttackWrapper_var);
}

void DestroyFireMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->physicalAttackWrapper_var);
}

PhysicalAttackWrapper& DestroyFireMessage::getPhysicalAttackWrapper()
{
    return physicalAttackWrapper_var;
}

void DestroyFireMessage::setPhysicalAttackWrapper(const PhysicalAttackWrapper& physicalAttackWrapper)
{
    this->physicalAttackWrapper_var = physicalAttackWrapper;
}

class DestroyFireMessageDescriptor : public cClassDescriptor
{
  public:
    DestroyFireMessageDescriptor();
    virtual ~DestroyFireMessageDescriptor();

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

Register_ClassDescriptor(DestroyFireMessageDescriptor);

DestroyFireMessageDescriptor::DestroyFireMessageDescriptor() : cClassDescriptor("DestroyFireMessage", "cMessage")
{
}

DestroyFireMessageDescriptor::~DestroyFireMessageDescriptor()
{
}

bool DestroyFireMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DestroyFireMessage *>(obj)!=NULL;
}

const char *DestroyFireMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DestroyFireMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int DestroyFireMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *DestroyFireMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "physicalAttackWrapper",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int DestroyFireMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "physicalAttackWrapper")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DestroyFireMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "PhysicalAttackWrapper",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *DestroyFireMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DestroyFireMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DestroyFireMessage *pp = (DestroyFireMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DestroyFireMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DestroyFireMessage *pp = (DestroyFireMessage *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getPhysicalAttackWrapper(); return out.str();}
        default: return "";
    }
}

bool DestroyFireMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DestroyFireMessage *pp = (DestroyFireMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *DestroyFireMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(PhysicalAttackWrapper));
        default: return NULL;
    };
}

void *DestroyFireMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DestroyFireMessage *pp = (DestroyFireMessage *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(&pp->getPhysicalAttackWrapper()); break;
        default: return NULL;
    }
}


