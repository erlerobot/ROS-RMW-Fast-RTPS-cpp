#ifndef _RMW_FASTRTPS_CPP_SERVICETYPESUPPORT_IMPL_H_
#define _RMW_FASTRTPS_CPP_SERVICETYPESUPPORT_IMPL_H_

#include "rmw_fastrtps_cpp/ServiceTypeSupport.h"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"

#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>
#include <cassert>

using namespace rmw_fastrtps_cpp;

template <typename MembersType>
ServiceTypeSupport<MembersType>::ServiceTypeSupport()
{
}

template <typename ServiceMembersType, typename MessageMembersType>
RequestTypeSupport<ServiceMembersType, MessageMembersType>::RequestTypeSupport(const ServiceMembersType *members)
{
    assert(members);
    this->members_ = members->request_members_;

    std::string name = std::string(members->package_name_) + "::srv::dds_::" + members->service_name_ + "_Request_";
    this->setName(name.c_str());

    if(this->members_->member_count_ != 0)
        this->m_typeSize = static_cast<uint32_t>(this->calculateMaxSerializedSize(this->members_, 0));
    else
        this->m_typeSize = 4;
}

template <typename ServiceMembersType, typename MessageMembersType>
ResponseTypeSupport<ServiceMembersType, MessageMembersType>::ResponseTypeSupport(const ServiceMembersType *members)
{
    assert(members);
    this->members_ = members->response_members_;

    std::string name = std::string(members->package_name_) + "::srv::dds_::" + members->service_name_ + "_Response_";
    this->setName(name.c_str());

    if(this->members_->member_count_ != 0)
        this->m_typeSize = static_cast<uint32_t>(this->calculateMaxSerializedSize(this->members_, 0));
    else
        this->m_typeSize = 4;
}

#endif // _RMW_FASTRTPS_CPP_SERVICETYPESUPPORT_IMPL_H_
