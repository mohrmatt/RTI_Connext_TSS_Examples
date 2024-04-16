
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS 3.x version".
*/

#include "util/rti_tss_common.h"
#include "rti_tss_impl.h"

#include "FACE/types.hpp"
#include "FACE/Common.hpp"
#include "FACE/TSS/Common.hpp"
#include "RTI/TSS/Base.hpp"

#include "../../../../ShapeType.hpp"
#include "../../../../ShapeType.h"
#include "../../../../ShapeTypeSupport.h"
#include "TypedTS_Impl.hpp"

extern "C"
{
    void RTI_ShapeTypeExtended_ReadCallback_forwarder(
        FACE::TSS::CONNECTION_ID_TYPE connection_id,
        void *message,
        void *callback);
} /* extern C */

void 
RTI_ShapeTypeExtended_ReadCallback_forwarder(
    FACE::TSS::CONNECTION_ID_TYPE connection_id,
    void *message,
    void *callback)
{
    FACE::TSS::TRANSACTION_ID_TYPE transaction_id = 0; 
    FACE::TSS::HEADER_TYPE header;
    FACE::TSS::QoS_EVENT_TYPE qos_params;
    FACE::RETURN_CODE_TYPE::Value retcode;

    FACE::DM::RTI::ShapeTypeExtended *typed_message =
    (FACE::DM::RTI::ShapeTypeExtended*)message;
    FACE::TSS::RTI::ShapeTypeExtended::Read_Callback *read_callback =
    (FACE::TSS::RTI::ShapeTypeExtended::Read_Callback*)callback;

    if (read_callback != NULL)
    {
        read_callback->Callback_Handler(
            connection_id,  
            transaction_id, 
            *typed_message,
            header,
            qos_params,
            retcode);
    }
}

namespace RTI {
    namespace ShapeTypeExtended {

        Read_Callback::Read_Callback() : FACE::TSS::RTI::ShapeTypeExtended::Read_Callback()
        {
        }

        Read_Callback::Read_Callback(const Read_Callback&): FACE::TSS::RTI::ShapeTypeExtended::Read_Callback()
        {
        }

        Read_Callback::~Read_Callback()
        {
        }

        void Read_Callback::Callback_Handler(
            FACE::TSS::CONNECTION_ID_TYPE connection_id,
            FACE::TSS::TRANSACTION_ID_TYPE transaction_id,
            const FACE::DM::RTI::ShapeTypeExtended& message,
            const FACE::TSS::HEADER_TYPE& header,
            const FACE::TSS::QoS_EVENT_TYPE& qos_parameters,
            FACE::RETURN_CODE_TYPE::Value& return_code)
        {
            /* Implement handler */
            UNUSED_ARG(connection_id);
            UNUSED_ARG(transaction_id);
            UNUSED_ARG(message);
            UNUSED_ARG(header);
            UNUSED_ARG(qos_parameters);
            UNUSED_ARG(return_code);

            printf("[FACE::DM::RTI::ShapeTypeExtended Callback_Handler called]\n");
        }

        TypedTS::TypedTS() : FACE::TSS::RTI::ShapeTypeExtended::TypedTS()
        {
            #if RTI_CALLBACK_IMPLEMENTED
            callback = NULL;
            #endif  
        }

        TypedTS::TypedTS(const TypedTS&) : FACE::TSS::RTI::ShapeTypeExtended::TypedTS()
        {
            #if RTI_CALLBACK_IMPLEMENTED
            callback = NULL;
            #endif  
        }

        TypedTS::~TypedTS()
        {
        }

        void TypedTS::Receive_Message(
            FACE::TSS::CONNECTION_ID_TYPE connection_id,
            FACE::TIMEOUT_TYPE timeout,
            FACE::TSS::TRANSACTION_ID_TYPE& transaction_id,
            FACE::DM::RTI::ShapeTypeExtended& message,
            FACE::TSS::HEADER_TYPE& header,
            FACE::TSS::QoS_EVENT_TYPE& qos_parameters,
            FACE::RETURN_CODE_TYPE::Value& return_code)
        {
            UNUSED_ARG(transaction_id);
            UNUSED_ARG(header);
            UNUSED_ARG(qos_parameters);

            RTI_TSS_Impl_receive_untyped(
                connection_id,
                timeout,
                (void*)&message,
                return_code);
        }

        void TypedTS::Send_Message(
            FACE::TSS::CONNECTION_ID_TYPE connection_id,
            FACE::TIMEOUT_TYPE timeout,
            FACE::TSS::TRANSACTION_ID_TYPE& transaction_id,
            FACE::DM::RTI::ShapeTypeExtended& message,
            FACE::RETURN_CODE_TYPE::Value& return_code)
        {
            UNUSED_ARG(timeout);
            UNUSED_ARG(transaction_id);

            RTI_TSS_Impl_send_untyped(
                connection_id,
                (void*)&message,
                return_code);
        }

        void TypedTS::Register_Callback(
            FACE::TSS::CONNECTION_ID_TYPE connection_id,
            FACE::TSS::RTI::ShapeTypeExtended::Read_Callback& callback,
            FACE::RETURN_CODE_TYPE::Value& return_code)
        {
            #if RTI_CALLBACK_IMPLEMENTED
            RTI_TSS_Impl_register_callback(
                connection_id,
                RTI_ShapeTypeExtended_ReadCallback_forwarder,
                (void*)&callback,
                sizeof(FACE_DM_RTI_ShapeTypeExtended),
                return_code);

            #else
            (void)connection_id;
            (void)callback;
            return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
            #endif /* RTI_CALLBACK_IMPLEMENTED */    
        }

    } // RTI
} // ShapeTypeExtended

#if defined(FACE_SEQUENCE_AND_STRING_SERIALIZABLE) && !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER

namespace FACE {

    template<>
    Sequence<FACE::DM::RTI::ShapeTypeExtended >::Sequence_Methods
    Sequence<FACE::DM::RTI::ShapeTypeExtended >::_seq_methods =
    {
        true,
        (RTI_INT32 (*)(const DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_get_maximum,
        (RTI_INT32 (*)(const DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_get_length,
        (DDS_Char* (*)(const DDS_CharSeq*, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_get_reference,
        (DDS_Char* (*)(const DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_get_contiguous_buffer,

        #ifndef RTI_CONNEXT_MICRO
        (DDS_Boolean (*)(DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_initialize,
        #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
        (DDS_Boolean (*)(DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_finalize,
        #endif
        (DDS_Boolean (*)(DDS_CharSeq*, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_set_maximum,
        (DDS_Boolean (*)(DDS_CharSeq*, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_set_length,
        (DDS_Boolean (*)(DDS_Char*, const DDS_Char*))FACE_DM_RTI_ShapeTypeExtended_copy,
        (DDS_Boolean (*)(const DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_has_ownership,
        (DDS_Boolean (*)(DDS_CharSeq*, DDS_Char*, RTI_INT32, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_loan_contiguous,
        (DDS_Boolean (*)(DDS_CharSeq*, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_set_absolute_maximum,
        #else
        (RTI_BOOL (*)(DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_initialize,
        #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
        (RTI_BOOL (*)(DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_finalize,
        #endif
        (RTI_BOOL (*)(DDS_CharSeq*, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_set_maximum,
        (RTI_BOOL (*)(DDS_CharSeq*, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_set_length,
        (RTI_BOOL (*)(DDS_Char*, const DDS_Char*))FACE_DM_RTI_ShapeTypeExtended_copy,
        (RTI_BOOL (*)(const DDS_CharSeq*))FACE_DM_RTI_ShapeTypeExtendedSeq_has_ownership,
        (RTI_BOOL (*)(DDS_CharSeq*, void*, RTI_INT32, RTI_INT32))FACE_DM_RTI_ShapeTypeExtendedSeq_loan_contiguous,
        #endif
    };

    #if (defined(_MSC_VER) || defined(WIN32))
    template class Sequence<FACE::DM::RTI::ShapeTypeExtended >;
    #endif /* (_MSC_VER || WIN32) */

} // namespace FACE

#endif /* FACE_SEQUENCE_AND_STRING_SERIALIZABLE && !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER */
