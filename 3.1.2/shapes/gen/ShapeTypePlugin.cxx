
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl
using RTI Code Generator (rtiddsgen) version 3.1.2.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <string.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#include "xcdr/xcdr_interpreter.h"
#include "xcdr/xcdr_stream.h"

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "dds_c/dds_c_typecode_impl.h"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "FACE/Sequence.hpp"
#include "FACE/Sequence_type_plugin.hpp"
#include "FACE/String.hpp"
#include "FACE/String_type_plugin.hpp"

#include "ShapeTypePlugin.h"

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

RTIBool 
FACE_DM_RTI_ShapeFillKindPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeFillKind *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool retval = RTI_TRUE;
    retval = PRESTypePlugin_interpretedSerialize(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_sample, 
        endpoint_plugin_qos);
    return retval;
}

RTIBool 
FACE_DM_RTI_ShapeFillKindPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeFillKind *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserialize(
        endpoint_data,
        sample,
        stream,   
        deserialize_encapsulation,
        deserialize_sample, 
        endpoint_plugin_qos);

}

RTIBool FACE_DM_RTI_ShapeFillKindPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSkip(
        endpoint_data,
        stream,   
        skip_encapsulation,
        skip_sample, 
        endpoint_plugin_qos);

}

unsigned int 
FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

unsigned int 
FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,
        NULL,
        include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

unsigned int FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const FACE_DM_RTI_ShapeFillKind * sample) 
{

    return PRESTypePlugin_interpretedGetSerializedSampleSize(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        sample);
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

RTIBool 
FACE_DM_RTI_ShapeFillKindPlugin_serialize_key_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeFillKind *sample, 
    struct RTICdrStream *stream,    
    RTIEncapsulationId encapsulation_id,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKeyForKeyhash(
        endpoint_data,
        sample, 
        stream,    
        encapsulation_id,
        endpoint_plugin_qos);
}

RTIBool 
FACE_DM_RTI_ShapeFillKindPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeFillKind *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKey(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_key,
        endpoint_plugin_qos);

}

RTIBool FACE_DM_RTI_ShapeFillKindPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeFillKind *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserializeKey(
        endpoint_data,
        sample,
        stream,
        deserialize_encapsulation,
        deserialize_key,
        endpoint_plugin_qos);
}

unsigned int
FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

unsigned int
FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_key_max_size_for_keyhash_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        overflow,
        encapsulation_id,
        current_alignment);
}

RTIBool 
FACE_DM_RTI_ShapeFillKindPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeFillKind *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation,  
        deserialize_key, 
        endpoint_plugin_qos);

}

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

void FACE_DM_RTI_ShapeFillKindPluginSupport_print_data(
    const FACE_DM_RTI_ShapeFillKind *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILogParamString_printPlain("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILogParamString_printPlain("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "FACE_DM_RTI_ShapeFillKind", indent_level + 1);
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */

/* ----------------------------------------------------------------------------
*  Type FACE_DM_RTI_ShapeType
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

FACE_DM_RTI_ShapeType*
FACE_DM_RTI_ShapeTypePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    FACE_DM_RTI_ShapeType *sample = NULL;

    if (alloc_params == NULL) {
        return NULL;
    }

    RTIOsapiHeap_allocateStructure(&(sample),FACE_DM_RTI_ShapeType);
    if (sample == NULL) {
        return NULL;
    }

    if (!FACE_DM_RTI_ShapeType_initialize_w_params(sample,alloc_params)) {
        struct DDS_TypeDeallocationParams_t deallocParams =
        DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
        deallocParams.delete_pointers = alloc_params->allocate_pointers;
        deallocParams.delete_optional_members = alloc_params->allocate_pointers;
        /* Coverity reports a possible uninit_use_in_call that will happen if the
        allocation fails. But if the allocation fails then sample == null and
        the method will return before reach this point.*/
        /* coverity[uninit_use_in_call : FALSE] */
        FACE_DM_RTI_ShapeType_finalize_w_params(sample, &deallocParams);
        RTIOsapiHeap_freeStructure(sample);
        sample=NULL;
    }
    return sample;
} 

FACE_DM_RTI_ShapeType *
FACE_DM_RTI_ShapeTypePluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    FACE_DM_RTI_ShapeType *sample = NULL;

    RTIOsapiHeap_allocateStructure(&(sample),FACE_DM_RTI_ShapeType);

    if(sample == NULL) {
        return NULL;
    }

    if (!FACE_DM_RTI_ShapeType_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        /* Coverity reports a possible uninit_use_in_call that will happen if the
        new fails. But if new fails then sample == null and the method will
        return before reach this point. */
        /* coverity[uninit_use_in_call : FALSE] */
        FACE_DM_RTI_ShapeType_finalize_ex(sample, RTI_TRUE);
        RTIOsapiHeap_freeStructure(sample);
        sample=NULL;
    }

    return sample;
}

FACE_DM_RTI_ShapeType *
FACE_DM_RTI_ShapeTypePluginSupport_create_data(void)
{
    return FACE_DM_RTI_ShapeTypePluginSupport_create_data_ex(RTI_TRUE);
}

void 
FACE_DM_RTI_ShapeTypePluginSupport_destroy_data_w_params(
    FACE_DM_RTI_ShapeType *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {
    FACE_DM_RTI_ShapeType_finalize_w_params(sample,dealloc_params);

    RTIOsapiHeap_freeStructure(sample);
}

void 
FACE_DM_RTI_ShapeTypePluginSupport_destroy_data_ex(
    FACE_DM_RTI_ShapeType *sample,RTIBool deallocate_pointers) {
    FACE_DM_RTI_ShapeType_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}

void 
FACE_DM_RTI_ShapeTypePluginSupport_destroy_data(
    FACE_DM_RTI_ShapeType *sample) {

    FACE_DM_RTI_ShapeTypePluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
FACE_DM_RTI_ShapeTypePluginSupport_copy_data(
    FACE_DM_RTI_ShapeType *dst,
    const FACE_DM_RTI_ShapeType *src)
{
    return FACE_DM_RTI_ShapeType_copy(dst,(const FACE_DM_RTI_ShapeType*) src);
}

void 
FACE_DM_RTI_ShapeTypePluginSupport_print_data(
    const FACE_DM_RTI_ShapeType *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILogParamString_printPlain("%s:\n", desc);
    } else {
        RTILogParamString_printPlain("\n");
    }

    if (sample == NULL) {
        RTILogParamString_printPlain("NULL\n");
        return;
    }

    RTICdrType_printString(
        sample->color.buffer(),"color", indent_level + 1);

    RTICdrType_printLong(
        &sample->x, "x", indent_level + 1);    

    RTICdrType_printLong(
        &sample->y, "y", indent_level + 1);    

    RTICdrType_printLong(
        &sample->shapesize, "shapesize", indent_level + 1);    

}

FACE_DM_RTI_ShapeType *
FACE_DM_RTI_ShapeTypePluginSupport_create_key_ex(RTIBool allocate_pointers){
    FACE_DM_RTI_ShapeType *key = NULL;

    RTIOsapiHeap_allocateStructure(&(key),FACE_DM_RTI_ShapeTypeKeyHolder);

    FACE_DM_RTI_ShapeType_initialize_ex(key,allocate_pointers, RTI_TRUE);

    return key;
}

FACE_DM_RTI_ShapeType *
FACE_DM_RTI_ShapeTypePluginSupport_create_key(void)
{
    return  FACE_DM_RTI_ShapeTypePluginSupport_create_key_ex(RTI_TRUE);
}

void 
FACE_DM_RTI_ShapeTypePluginSupport_destroy_key_ex(
    FACE_DM_RTI_ShapeTypeKeyHolder *key,RTIBool deallocate_pointers)
{
    FACE_DM_RTI_ShapeType_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}

void 
FACE_DM_RTI_ShapeTypePluginSupport_destroy_key(
    FACE_DM_RTI_ShapeTypeKeyHolder *key) {

    FACE_DM_RTI_ShapeTypePluginSupport_destroy_key_ex(key,RTI_TRUE);

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
FACE_DM_RTI_ShapeTypePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct PRESTypePluginDefaultParticipantData *pd = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    pd = (struct PRESTypePluginDefaultParticipantData *)
    PRESTypePluginDefaultParticipantData_new(participant_info);

    programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_FALSE;
    programProperty.optimizeEnum = RTI_XCDR_FALSE;
    programProperty.unboundedSize = RTIXCdrLong_MAX;

    programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        FACE_DM_RTI_ShapeType_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);
    if (programs == NULL) {
        PRESTypePluginDefaultParticipantData_delete(
            (PRESTypePluginParticipantData) pd);
        return NULL;
    }

    pd->programs = programs;
    return (PRESTypePluginParticipantData)pd;
}

void 
FACE_DM_RTI_ShapeTypePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{  		
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
FACE_DM_RTI_ShapeTypePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;
    unsigned int serializedSampleMaxSize = 0;

    unsigned int serializedKeyMaxSize = 0;
    unsigned int serializedKeyMaxSizeV2 = 0;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    if (participant_data == NULL) {
        return NULL;
    } 

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        FACE_DM_RTI_ShapeTypePluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        FACE_DM_RTI_ShapeTypePluginSupport_destroy_data,
        (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
        FACE_DM_RTI_ShapeTypePluginSupport_create_key ,            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
        FACE_DM_RTI_ShapeTypePluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    } 

    serializedKeyMaxSize =  FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    serializedKeyMaxSizeV2 =  FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_for_keyhash(
        epd,
        RTI_CDR_ENCAPSULATION_ID_CDR2_BE,
        0);

    if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
        epd,
        endpoint_info,
        serializedKeyMaxSize,
        serializedKeyMaxSizeV2))  
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
FACE_DM_RTI_ShapeTypePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
FACE_DM_RTI_ShapeTypePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType *sample,
    void *handle)
{
    FACE_DM_RTI_ShapeType_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType *dst,
    const FACE_DM_RTI_ShapeType *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return FACE_DM_RTI_ShapeTypePluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeType *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool retval = RTI_TRUE;
    retval = PRESTypePlugin_interpretedSerialize(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_sample, 
        endpoint_plugin_qos);
    return retval;
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserialize(
        endpoint_data,
        sample,
        stream,   
        deserialize_encapsulation,
        deserialize_sample, 
        endpoint_plugin_qos);

}

RTIBool
FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const FACE_DM_RTI_ShapeType *sample,
    DDS_DataRepresentationId_t representation)
{
    RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;

    if (length == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    FACE_DM_RTI_ShapeType_get_typecode();
    pd.programs = FACE_DM_RTI_ShapeTypePlugin_get_programs();
    if (pd.programs == NULL) {
        return RTI_FALSE;
    }

    encapsulationId = DDS_TypeCode_get_native_encapsulation(
        (DDS_TypeCode *) plugin.typeCode,
        representation);    
    if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size(
        (PRESTypePluginEndpointData)&epd, 
        RTI_TRUE, 
        encapsulationId,
        0);

    if (buffer == NULL) {
        *length = 
        FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            encapsulationId,
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = FACE_DM_RTI_ShapeTypePlugin_serialize(
        (PRESTypePluginEndpointData)&epd,
        sample,
        &stream,
        RTI_TRUE,
        encapsulationId,
        RTI_TRUE,
        NULL);

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;
}

RTIBool
FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer(
    char *buffer,
    unsigned int *length,
    const FACE_DM_RTI_ShapeType *sample)
{
    return FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer_ex(
        buffer,
        length,
        sample,
        DDS_AUTO_DATA_REPRESENTATION);
}

RTIBool
FACE_DM_RTI_ShapeTypePlugin_deserialize_from_cdr_buffer(
    FACE_DM_RTI_ShapeType *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePluginDefaultParticipantData pd;
    struct PRESTypePlugin plugin;

    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    FACE_DM_RTI_ShapeType_get_typecode();
    pd.programs = FACE_DM_RTI_ShapeTypePlugin_get_programs();
    if (pd.programs == NULL) {
        return RTI_FALSE;
    }

    epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
    epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    FACE_DM_RTI_ShapeType_finalize_optional_members(sample, RTI_TRUE);
    return FACE_DM_RTI_ShapeTypePlugin_deserialize_sample( 
        (PRESTypePluginEndpointData)&epd, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

#ifndef NDDS_STANDALONE_TYPE
DDS_ReturnCode_t
FACE_DM_RTI_ShapeTypePlugin_data_to_string(
    const FACE_DM_RTI_ShapeType *sample,
    char *_str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }
    if (!FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }
    data = DDS_DynamicData_new(
        FACE_DM_RTI_ShapeType_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        _str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}
#endif

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool result = RTI_FALSE;
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;

    result = FACE_DM_RTI_ShapeTypePlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    if (!result && stream->_xTypesState.unassignable ) {

        RTICdrLog_exception(
            &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
            "FACE_DM_RTI_ShapeType");

    }

    return result;

}

RTIBool FACE_DM_RTI_ShapeTypePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSkip(
        endpoint_data,
        stream,   
        skip_encapsulation,
        skip_sample, 
        endpoint_plugin_qos);

}

unsigned int 
FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

unsigned int 
FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    return PRESTypePlugin_interpretedGetSerializedSampleMinSize(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const FACE_DM_RTI_ShapeType * sample) 
{

    return PRESTypePlugin_interpretedGetSerializedSampleSize(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        sample);
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
FACE_DM_RTI_ShapeTypePlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_serialize_key_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeType *sample, 
    struct RTICdrStream *stream,    
    RTIEncapsulationId encapsulation_id,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKeyForKeyhash(
        endpoint_data,
        sample, 
        stream,    
        encapsulation_id,
        endpoint_plugin_qos);
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeType *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKey(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_key,
        endpoint_plugin_qos);

}

RTIBool FACE_DM_RTI_ShapeTypePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserializeKey(
        endpoint_data,
        sample,
        stream,
        deserialize_encapsulation,
        deserialize_key,
        endpoint_plugin_qos);
}

RTIBool FACE_DM_RTI_ShapeTypePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= FACE_DM_RTI_ShapeTypePlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    return result;    

}

unsigned int
FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

unsigned int
FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_for_keyhash_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        overflow,
        encapsulation_id,
        current_alignment);
}

unsigned int
FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;
    size = FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int
FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;
    size = FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_for_keyhash_ex(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation,  
        deserialize_key, 
        endpoint_plugin_qos);

}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeKeyHolder *dst, 
    const FACE_DM_RTI_ShapeType *src)
{
    if (endpoint_data) {} /* To avoid warnings */   

    if (!FACE_String_copy(&dst->color,
    &src->color,
    (128L)))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeType *dst, const
    FACE_DM_RTI_ShapeTypeKeyHolder *src)
{
    if (endpoint_data) {} /* To avoid warnings */   
    if (!FACE_String_copy(&dst->color,
    &src->color,
    (128L)))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const FACE_DM_RTI_ShapeType *instance,
    RTIEncapsulationId encapsulationId)
{
    return PRESTypePlugin_interpretedInstanceToKeyHash(
        endpoint_data,
        keyhash,
        instance,
        encapsulationId);
}

RTIBool 
FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    FACE_DM_RTI_ShapeType * sample = NULL;
    sample = (FACE_DM_RTI_ShapeType *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);
    if (sample == NULL) {
        return RTI_FALSE;
    }

    if (!FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_key(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation, 
        RTI_TRUE,
        endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
    if (!FACE_DM_RTI_ShapeTypePlugin_instance_to_keyhash(
        endpoint_data, 
        keyhash, 
        sample,
        RTICdrStream_getEncapsulationKind(stream))) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

struct RTIXCdrInterpreterPrograms * FACE_DM_RTI_ShapeTypePlugin_get_programs(void)
{
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
    struct RTIXCdrInterpreterPrograms *retPrograms = NULL;

    programProperty.generateWithOnlyKeyFields = RTI_XCDR_FALSE;
    programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_FALSE;
    programProperty.optimizeEnum = RTI_XCDR_FALSE;
    programProperty.unboundedSize = RTIXCdrLong_MAX;

    retPrograms =
    DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        FACE_DM_RTI_ShapeType_get_typecode(),
        &programProperty,
        RTI_XCDR_SER_PROGRAM
        | RTI_XCDR_DESER_PROGRAM
        | RTI_XCDR_GET_MAX_SER_SIZE_PROGRAM
        | RTI_XCDR_GET_SER_SIZE_PROGRAM);

    return retPrograms;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *FACE_DM_RTI_ShapeTypePlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    FACE_DM_RTI_ShapeTypePlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    FACE_DM_RTI_ShapeTypePlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    FACE_DM_RTI_ShapeTypePlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    FACE_DM_RTI_ShapeTypePlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    FACE_DM_RTI_ShapeTypePlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    FACE_DM_RTI_ShapeTypePlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    FACE_DM_RTI_ShapeTypePlugin_destroy_sample;
    plugin->finalizeOptionalMembersFnc =
    (PRESTypePluginFinalizeOptionalMembersFunction)
    FACE_DM_RTI_ShapeType_finalize_optional_members;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) FACE_DM_RTI_ShapeTypePlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) FACE_DM_RTI_ShapeTypePlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_min_size;
    plugin->getDeserializedSampleMaxSizeFnc = NULL; 
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    FACE_DM_RTI_ShapeTypePlugin_return_sample;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    FACE_DM_RTI_ShapeTypePlugin_serialize_key;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    FACE_DM_RTI_ShapeTypePlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    FACE_DM_RTI_ShapeTypePlugin_deserialize_key_sample;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    FACE_DM_RTI_ShapeTypePlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    FACE_DM_RTI_ShapeTypePlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    FACE_DM_RTI_ShapeTypePlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    FACE_DM_RTI_ShapeTypePlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    plugin->typeCode =  (struct RTICdrTypeCode *)FACE_DM_RTI_ShapeType_get_typecode();
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    FACE_DM_RTI_ShapeTypePlugin_return_buffer;
    plugin->getBufferWithParams = NULL;
    plugin->returnBufferWithParams = NULL;  
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_size;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    plugin->endpointTypeName = FACE_DM_RTI_ShapeTypeTYPENAME;
    plugin->isMetpType = RTI_FALSE;
    return plugin;
}

void
FACE_DM_RTI_ShapeTypePlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type FACE_DM_RTI_ShapeTypeExtended
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

FACE_DM_RTI_ShapeTypeExtended*
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    FACE_DM_RTI_ShapeTypeExtended *sample = NULL;

    if (alloc_params == NULL) {
        return NULL;
    }

    RTIOsapiHeap_allocateStructure(&(sample),FACE_DM_RTI_ShapeTypeExtended);
    if (sample == NULL) {
        return NULL;
    }

    if (!FACE_DM_RTI_ShapeTypeExtended_initialize_w_params(sample,alloc_params)) {
        struct DDS_TypeDeallocationParams_t deallocParams =
        DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
        deallocParams.delete_pointers = alloc_params->allocate_pointers;
        deallocParams.delete_optional_members = alloc_params->allocate_pointers;
        /* Coverity reports a possible uninit_use_in_call that will happen if the
        allocation fails. But if the allocation fails then sample == null and
        the method will return before reach this point.*/
        /* coverity[uninit_use_in_call : FALSE] */
        FACE_DM_RTI_ShapeTypeExtended_finalize_w_params(sample, &deallocParams);
        RTIOsapiHeap_freeStructure(sample);
        sample=NULL;
    }
    return sample;
} 

FACE_DM_RTI_ShapeTypeExtended *
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    FACE_DM_RTI_ShapeTypeExtended *sample = NULL;

    RTIOsapiHeap_allocateStructure(&(sample),FACE_DM_RTI_ShapeTypeExtended);

    if(sample == NULL) {
        return NULL;
    }

    if (!FACE_DM_RTI_ShapeTypeExtended_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        /* Coverity reports a possible uninit_use_in_call that will happen if the
        new fails. But if new fails then sample == null and the method will
        return before reach this point. */
        /* coverity[uninit_use_in_call : FALSE] */
        FACE_DM_RTI_ShapeTypeExtended_finalize_ex(sample, RTI_TRUE);
        RTIOsapiHeap_freeStructure(sample);
        sample=NULL;
    }

    return sample;
}

FACE_DM_RTI_ShapeTypeExtended *
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data(void)
{
    return FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data_ex(RTI_TRUE);
}

void 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data_w_params(
    FACE_DM_RTI_ShapeTypeExtended *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {
    FACE_DM_RTI_ShapeTypeExtended_finalize_w_params(sample,dealloc_params);

    RTIOsapiHeap_freeStructure(sample);
}

void 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data_ex(
    FACE_DM_RTI_ShapeTypeExtended *sample,RTIBool deallocate_pointers) {
    FACE_DM_RTI_ShapeTypeExtended_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}

void 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data(
    FACE_DM_RTI_ShapeTypeExtended *sample) {

    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_copy_data(
    FACE_DM_RTI_ShapeTypeExtended *dst,
    const FACE_DM_RTI_ShapeTypeExtended *src)
{
    return FACE_DM_RTI_ShapeTypeExtended_copy(dst,(const FACE_DM_RTI_ShapeTypeExtended*) src);
}

void 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_print_data(
    const FACE_DM_RTI_ShapeTypeExtended *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILogParamString_printPlain("%s:\n", desc);
    } else {
        RTILogParamString_printPlain("\n");
    }

    if (sample == NULL) {
        RTILogParamString_printPlain("NULL\n");
        return;
    }

    FACE_DM_RTI_ShapeTypePluginSupport_print_data((const FACE_DM_RTI_ShapeType*)sample,"",indent_level);

    FACE_DM_RTI_ShapeFillKindPluginSupport_print_data(
        (const FACE_DM_RTI_ShapeFillKind*) &sample->fillKind, "fillKind", indent_level + 1);

    RTICdrType_printFloat(
        &sample->angle, "angle", indent_level + 1);    

}

FACE_DM_RTI_ShapeTypeExtended *
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_key_ex(RTIBool allocate_pointers){
    FACE_DM_RTI_ShapeTypeExtended *key = NULL;

    RTIOsapiHeap_allocateStructure(&(key),FACE_DM_RTI_ShapeTypeExtendedKeyHolder);

    FACE_DM_RTI_ShapeTypeExtended_initialize_ex(key,allocate_pointers, RTI_TRUE);

    return key;
}

FACE_DM_RTI_ShapeTypeExtended *
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_key(void)
{
    return  FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_key_ex(RTI_TRUE);
}

void 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_key_ex(
    FACE_DM_RTI_ShapeTypeExtendedKeyHolder *key,RTIBool deallocate_pointers)
{
    FACE_DM_RTI_ShapeTypeExtended_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}

void 
FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_key(
    FACE_DM_RTI_ShapeTypeExtendedKeyHolder *key) {

    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_key_ex(key,RTI_TRUE);

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
FACE_DM_RTI_ShapeTypeExtendedPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct PRESTypePluginDefaultParticipantData *pd = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    pd = (struct PRESTypePluginDefaultParticipantData *)
    PRESTypePluginDefaultParticipantData_new(participant_info);

    programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_FALSE;
    programProperty.optimizeEnum = RTI_XCDR_FALSE;
    programProperty.unboundedSize = RTIXCdrLong_MAX;

    programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        FACE_DM_RTI_ShapeTypeExtended_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);
    if (programs == NULL) {
        PRESTypePluginDefaultParticipantData_delete(
            (PRESTypePluginParticipantData) pd);
        return NULL;
    }

    pd->programs = programs;
    return (PRESTypePluginParticipantData)pd;
}

void 
FACE_DM_RTI_ShapeTypeExtendedPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{  		
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
FACE_DM_RTI_ShapeTypeExtendedPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;
    unsigned int serializedSampleMaxSize = 0;

    unsigned int serializedKeyMaxSize = 0;
    unsigned int serializedKeyMaxSizeV2 = 0;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    if (participant_data == NULL) {
        return NULL;
    } 

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data,
        (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
        FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_key ,            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
        FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    } 

    serializedKeyMaxSize =  FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    serializedKeyMaxSizeV2 =  FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_for_keyhash(
        epd,
        RTI_CDR_ENCAPSULATION_ID_CDR2_BE,
        0);

    if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
        epd,
        endpoint_info,
        serializedKeyMaxSize,
        serializedKeyMaxSizeV2))  
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
FACE_DM_RTI_ShapeTypeExtendedPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
FACE_DM_RTI_ShapeTypeExtendedPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended *sample,
    void *handle)
{
    FACE_DM_RTI_ShapeTypeExtended_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended *dst,
    const FACE_DM_RTI_ShapeTypeExtended *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return FACE_DM_RTI_ShapeTypeExtendedPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool retval = RTI_TRUE;
    retval = PRESTypePlugin_interpretedSerialize(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_sample, 
        endpoint_plugin_qos);
    return retval;
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserialize(
        endpoint_data,
        sample,
        stream,   
        deserialize_encapsulation,
        deserialize_sample, 
        endpoint_plugin_qos);

}

RTIBool
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const FACE_DM_RTI_ShapeTypeExtended *sample,
    DDS_DataRepresentationId_t representation)
{
    RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;

    if (length == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    FACE_DM_RTI_ShapeTypeExtended_get_typecode();
    pd.programs = FACE_DM_RTI_ShapeTypeExtendedPlugin_get_programs();
    if (pd.programs == NULL) {
        return RTI_FALSE;
    }

    encapsulationId = DDS_TypeCode_get_native_encapsulation(
        (DDS_TypeCode *) plugin.typeCode,
        representation);    
    if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
        (PRESTypePluginEndpointData)&epd, 
        RTI_TRUE, 
        encapsulationId,
        0);

    if (buffer == NULL) {
        *length = 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            encapsulationId,
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize(
        (PRESTypePluginEndpointData)&epd,
        sample,
        &stream,
        RTI_TRUE,
        encapsulationId,
        RTI_TRUE,
        NULL);

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;
}

RTIBool
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
    char *buffer,
    unsigned int *length,
    const FACE_DM_RTI_ShapeTypeExtended *sample)
{
    return FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer_ex(
        buffer,
        length,
        sample,
        DDS_AUTO_DATA_REPRESENTATION);
}

RTIBool
FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_from_cdr_buffer(
    FACE_DM_RTI_ShapeTypeExtended *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePluginDefaultParticipantData pd;
    struct PRESTypePlugin plugin;

    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    FACE_DM_RTI_ShapeTypeExtended_get_typecode();
    pd.programs = FACE_DM_RTI_ShapeTypeExtendedPlugin_get_programs();
    if (pd.programs == NULL) {
        return RTI_FALSE;
    }

    epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
    epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    FACE_DM_RTI_ShapeTypeExtended_finalize_optional_members(sample, RTI_TRUE);
    return FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_sample( 
        (PRESTypePluginEndpointData)&epd, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

#ifndef NDDS_STANDALONE_TYPE
DDS_ReturnCode_t
FACE_DM_RTI_ShapeTypeExtendedPlugin_data_to_string(
    const FACE_DM_RTI_ShapeTypeExtended *sample,
    char *_str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }
    if (!FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }
    data = DDS_DynamicData_new(
        FACE_DM_RTI_ShapeTypeExtended_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        _str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}
#endif

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    RTIBool result = RTI_FALSE;
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;

    result = FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    if (!result && stream->_xTypesState.unassignable ) {

        RTICdrLog_exception(
            &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
            "FACE_DM_RTI_ShapeTypeExtended");

    }

    return result;

}

RTIBool FACE_DM_RTI_ShapeTypeExtendedPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSkip(
        endpoint_data,
        stream,   
        skip_encapsulation,
        skip_sample, 
        endpoint_plugin_qos);

}

unsigned int 
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

unsigned int 
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    return PRESTypePlugin_interpretedGetSerializedSampleMinSize(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const FACE_DM_RTI_ShapeTypeExtended * sample) 
{

    return PRESTypePlugin_interpretedGetSerializedSampleSize(
        endpoint_data,
        include_encapsulation,
        encapsulation_id,
        current_alignment,
        sample);
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_key_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,    
    RTIEncapsulationId encapsulation_id,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKeyForKeyhash(
        endpoint_data,
        sample, 
        stream,    
        encapsulation_id,
        endpoint_plugin_qos);
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const FACE_DM_RTI_ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializeKey(
        endpoint_data,
        sample, 
        stream,    
        serialize_encapsulation,
        encapsulation_id,
        serialize_key,
        endpoint_plugin_qos);

}

RTIBool FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedDeserializeKey(
        endpoint_data,
        sample,
        stream,
        deserialize_encapsulation,
        deserialize_key,
        endpoint_plugin_qos);
}

RTIBool FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    return result;    

}

unsigned int
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
        endpoint_data,
        overflow,
        include_encapsulation,
        encapsulation_id,
        current_alignment);
}

unsigned int
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_for_keyhash_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    return PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        overflow,
        encapsulation_id,
        current_alignment);
}

unsigned int
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;
    size = FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int
FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;
    size = FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_for_keyhash_ex(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    return PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation,  
        deserialize_key, 
        endpoint_plugin_qos);

}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtendedKeyHolder *dst, 
    const FACE_DM_RTI_ShapeTypeExtended *src)
{
    if (!FACE_DM_RTI_ShapeTypePlugin_instance_to_key(endpoint_data,(FACE_DM_RTI_ShapeType *)dst,(const FACE_DM_RTI_ShapeType*)src)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    FACE_DM_RTI_ShapeTypeExtended *dst, const
    FACE_DM_RTI_ShapeTypeExtendedKeyHolder *src)
{
    if (!FACE_DM_RTI_ShapeTypePlugin_key_to_instance(endpoint_data,(FACE_DM_RTI_ShapeType*)dst,(const FACE_DM_RTI_ShapeType*)src)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const FACE_DM_RTI_ShapeTypeExtended *instance,
    RTIEncapsulationId encapsulationId)
{
    return PRESTypePlugin_interpretedInstanceToKeyHash(
        endpoint_data,
        keyhash,
        instance,
        encapsulationId);
}

RTIBool 
FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    FACE_DM_RTI_ShapeTypeExtended * sample = NULL;
    sample = (FACE_DM_RTI_ShapeTypeExtended *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);
    if (sample == NULL) {
        return RTI_FALSE;
    }

    if (!FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_key(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation, 
        RTI_TRUE,
        endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
    if (!FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_keyhash(
        endpoint_data, 
        keyhash, 
        sample,
        RTICdrStream_getEncapsulationKind(stream))) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

struct RTIXCdrInterpreterPrograms * FACE_DM_RTI_ShapeTypeExtendedPlugin_get_programs(void)
{
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
    struct RTIXCdrInterpreterPrograms *retPrograms = NULL;

    programProperty.generateWithOnlyKeyFields = RTI_XCDR_FALSE;
    programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_FALSE;
    programProperty.optimizeEnum = RTI_XCDR_FALSE;
    programProperty.unboundedSize = RTIXCdrLong_MAX;

    retPrograms =
    DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        FACE_DM_RTI_ShapeTypeExtended_get_typecode(),
        &programProperty,
        RTI_XCDR_SER_PROGRAM
        | RTI_XCDR_DESER_PROGRAM
        | RTI_XCDR_GET_MAX_SER_SIZE_PROGRAM
        | RTI_XCDR_GET_SER_SIZE_PROGRAM);

    return retPrograms;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *FACE_DM_RTI_ShapeTypeExtendedPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_destroy_sample;
    plugin->finalizeOptionalMembersFnc =
    (PRESTypePluginFinalizeOptionalMembersFunction)
    FACE_DM_RTI_ShapeTypeExtended_finalize_optional_members;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_min_size;
    plugin->getDeserializedSampleMaxSizeFnc = NULL; 
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_return_sample;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_key;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key_sample;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    plugin->typeCode =  (struct RTICdrTypeCode *)FACE_DM_RTI_ShapeTypeExtended_get_typecode();
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_return_buffer;
    plugin->getBufferWithParams = NULL;
    plugin->returnBufferWithParams = NULL;  
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_size;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    plugin->endpointTypeName = FACE_DM_RTI_ShapeTypeExtendedTYPENAME;
    plugin->isMetpType = RTI_FALSE;
    return plugin;
}

void
FACE_DM_RTI_ShapeTypeExtendedPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
