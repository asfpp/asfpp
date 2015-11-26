//
// Generated file, do not edit! Created by nedtool 4.6 from src/actions/destroy/DestroyRequest.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DestroyRequest_m.h"

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

Register_Class(DestroyRequest);

DestroyRequest::DestroyRequest(const char *name, int kind) : ::cMessage(name,kind)
{
    take(&(this->entryWrapper_var));
}

DestroyRequest::DestroyRequest(const DestroyRequest& other) : ::cMessage(other)
{
    take(&(this->entryWrapper_var));
    copy(other);
}

DestroyRequest::~DestroyRequest()
{
    drop(&(this->entryWrapper_var));
}

DestroyRequest& DestroyRequest::operator=(const DestroyRequest& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DestroyRequest::copy(const DestroyRequest& other)
{
    this->entryWrapper_var = other.entryWrapper_var;
    this->entryWrapper_var.setName(other.entryWrapper_var.getName());
}

void DestroyRequest::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->entryWrapper_var);
}

void DestroyRequest::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->entryWrapper_var);
}

EntryWrapper& DestroyRequest::getEntryWrapper()
{
    return entryWrapper_var;
}

void DestroyRequest::setEntryWrapper(const EntryWrapper& entryWrapper)
{
    this->entryWrapper_var = entryWrapper;
}

class DestroyRequestDescriptor : public cClassDescriptor
{
  public:
    DestroyRequestDescriptor();
    virtual ~DestroyRequestDescriptor();

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

Register_ClassDescriptor(DestroyRequestDescriptor);

DestroyRequestDescriptor::DestroyRequestDescriptor() : cClassDescriptor("DestroyRequest", "cMessage")
{
}

DestroyRequestDescriptor::~DestroyRequestDescriptor()
{
}

bool DestroyRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DestroyRequest *>(obj)!=NULL;
}

const char *DestroyRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DestroyRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int DestroyRequestDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *DestroyRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "entryWrapper",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int DestroyRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "entryWrapper")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DestroyRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "EntryWrapper",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *DestroyRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DestroyRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DestroyRequest *pp = (DestroyRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DestroyRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DestroyRequest *pp = (DestroyRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getEntryWrapper(); return out.str();}
        default: return "";
    }
}

bool DestroyRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DestroyRequest *pp = (DestroyRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *DestroyRequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(EntryWrapper));
        default: return NULL;
    };
}

void *DestroyRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DestroyRequest *pp = (DestroyRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(&pp->getEntryWrapper()); break;
        default: return NULL;
    }
}


