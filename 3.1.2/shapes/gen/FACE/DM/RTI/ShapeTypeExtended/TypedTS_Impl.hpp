
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS 3.x version".
*/

#ifndef FACE_DM_RTI_ShapeTypeExtended_TSS_TypedTSImpl434673847_hpp
#define FACE_DM_RTI_ShapeTypeExtended_TSS_TypedTSImpl434673847_hpp

#include "util/rti_tss_common.h"

#include "FACE/types.hpp"
#include "FACE/Common.hpp"
#include "FACE/TSS/Common.hpp"

#include "../../../../ShapeType.hpp"
#include "TypedTS.hpp"

namespace RTI {
    namespace ShapeTypeExtended {
        class Read_Callback : public FACE::TSS::RTI::ShapeTypeExtended::Read_Callback
        {
          public:
            Read_Callback();
            Read_Callback(const Read_Callback&);
            Read_Callback& operator=(const Read_Callback&);
            ~Read_Callback();

            void Callback_Handler(
                FACE::TSS::CONNECTION_ID_TYPE connection_id,
                FACE::TSS::TRANSACTION_ID_TYPE transaction_id,
                const FACE::DM::RTI::ShapeTypeExtended& message,
                const FACE::TSS::HEADER_TYPE& header,
                const FACE::TSS::QoS_EVENT_TYPE& qos_parameters,
                FACE::RETURN_CODE_TYPE::Value& return_code
                );
        }; 

        class TypedTS : public FACE::TSS::RTI::ShapeTypeExtended::TypedTS 
        {
          public:
            TypedTS();
            TypedTS(const TypedTS&);
            ~TypedTS();

            void Receive_Message(
                FACE::TSS::CONNECTION_ID_TYPE connection_id,
                FACE::TIMEOUT_TYPE timeout,
                FACE::TSS::TRANSACTION_ID_TYPE& transaction_id,
                FACE::DM::RTI::ShapeTypeExtended& message,
                FACE::TSS::HEADER_TYPE& header,
                FACE::TSS::QoS_EVENT_TYPE& qos_parameters,
                FACE::RETURN_CODE_TYPE::Value& return_code
                );

            void Send_Message(
                FACE::TSS::CONNECTION_ID_TYPE connection_id,
                FACE::TIMEOUT_TYPE timeout,
                FACE::TSS::TRANSACTION_ID_TYPE& transaction_id,
                FACE::DM::RTI::ShapeTypeExtended& message,
                FACE::RETURN_CODE_TYPE::Value& return_code
                );

            void Register_Callback(
                FACE::TSS::CONNECTION_ID_TYPE connection_id,
                FACE::TSS::RTI::ShapeTypeExtended::Read_Callback& callback,
                FACE::RETURN_CODE_TYPE::Value& return_code
                );
            #if RTI_CALLBACK_IMPLEMENTED
          private:
            Read_Callback *callback;
            #endif  
        }; /* TypedTS */
    } // RTI
} // ShapeTypeExtended

#if defined(FACE_SEQUENCE_AND_STRING_SERIALIZABLE) && !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER

namespace FACE {
    #if !(defined(_MSC_VER) || defined(WIN32))
    template<>
    Sequence<FACE::DM::RTI::ShapeTypeExtended >::Sequence_Methods
    Sequence<FACE::DM::RTI::ShapeTypeExtended >::_seq_methods;
    #else
    extern template class
    Sequence<FACE::DM::RTI::ShapeTypeExtended >;
    #endif /* !(_MSC_VER || WIN32) */

} // namespace FACE

#endif /* FACE_SEQUENCE_AND_STRING_SERIALIZABLE && !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER */

#endif /* FACE_DM_RTI_ShapeTypeExtended_TSS_TypedTSImpl434673847__hpp */

