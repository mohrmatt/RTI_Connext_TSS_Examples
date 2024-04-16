
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS 3.x version".
*/

#ifndef FACE_DM_RTI_ShapeType_TSS_TypedTS434673847_hpp
#define FACE_DM_RTI_ShapeType_TSS_TypedTS434673847_hpp

#include "FACE/types.hpp"
#include "FACE/Common.hpp"
#include "FACE/TSS/Common.hpp"

#include "../../../../ShapeType.hpp"

namespace FACE {
    namespace TSS {
        namespace RTI {
            namespace ShapeType {
                class Read_Callback
                {
                    protected:
                    Read_Callback() {}
                  private:
                    Read_Callback(const Read_Callback&);
                    Read_Callback& operator=(const Read_Callback&);
                  public:
                    virtual ~Read_Callback() {}

                    virtual void Callback_Handler(
                        FACE::TSS::CONNECTION_ID_TYPE connection_id,
                        FACE::TSS::TRANSACTION_ID_TYPE transaction_id,
                        const FACE::DM::RTI::ShapeType& message,
                        const FACE::TSS::HEADER_TYPE& header,
                        const FACE::TSS::QoS_EVENT_TYPE& qos_parameters,
                        FACE::RETURN_CODE_TYPE::Value& return_code
                        ) = 0;
                }; /* interface Read_Callback */

                class TypedTS
                {
                    protected:
                    TypedTS() {}
                  private:
                    TypedTS(const TypedTS&);
                    TypedTS& operator=(const TypedTS&);
                  public:
                    virtual ~TypedTS() {}

                    virtual void Receive_Message(
                        FACE::TSS::CONNECTION_ID_TYPE connection_id,
                        FACE::TIMEOUT_TYPE timeout,
                        FACE::TSS::TRANSACTION_ID_TYPE& transaction_id,
                        FACE::DM::RTI::ShapeType& message,
                        FACE::TSS::HEADER_TYPE& header,
                        FACE::TSS::QoS_EVENT_TYPE& qos_parameters,
                        FACE::RETURN_CODE_TYPE::Value& return_code
                        ) = 0;

                    virtual void Send_Message(
                        FACE::TSS::CONNECTION_ID_TYPE connection_id,
                        FACE::TIMEOUT_TYPE timeout,
                        FACE::TSS::TRANSACTION_ID_TYPE& transaction_id,
                        FACE::DM::RTI::ShapeType& message,
                        FACE::RETURN_CODE_TYPE::Value& return_code
                        ) = 0;

                    virtual void Register_Callback(
                        FACE::TSS::CONNECTION_ID_TYPE connection_id,
                        FACE::TSS::RTI::ShapeType::Read_Callback& callback,
                        FACE::RETURN_CODE_TYPE::Value& return_code
                        ) = 0;
                }; /* TypedTS */
            } // RTI
        } // ShapeType
    } /* namespace TSS */
} /* namespace FACE */

#endif /* FACE_DM_RTI_ShapeType_TSS_TypedTS434673847_hpp */

