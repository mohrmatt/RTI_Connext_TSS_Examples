

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl 
using RTI Code Generator (rtiddsgen) version 3.1.2.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "ShapeType.h"

#ifndef NDDS_STANDALONE_TYPE
#include "ShapeTypePlugin.h"
#endif

/* ========================================================================= */
const char *FACE_DM_RTI_ShapeFillKindTYPENAME = "FACE::DM::RTI::ShapeFillKind";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * FACE_DM_RTI_ShapeFillKind_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member FACE_DM_RTI_ShapeFillKind_g_tc_members[4]=
    {

        {
            (char *)"SOLID_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FACE_DM_RTI_ShapeFillKind_SOLID_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"TRANSPARENT_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FACE_DM_RTI_ShapeFillKind_TRANSPARENT_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"HORIZONTAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FACE_DM_RTI_ShapeFillKind_HORIZONTAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"VERTICAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FACE_DM_RTI_ShapeFillKind_VERTICAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode FACE_DM_RTI_ShapeFillKind_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"FACE::DM::RTI::ShapeFillKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            FACE_DM_RTI_ShapeFillKind_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for FACE_DM_RTI_ShapeFillKind*/

    if (is_initialized) {
        return &FACE_DM_RTI_ShapeFillKind_g_tc;
    }

    FACE_DM_RTI_ShapeFillKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    FACE_DM_RTI_ShapeFillKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    FACE_DM_RTI_ShapeFillKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

    FACE_DM_RTI_ShapeFillKind_g_tc._data._sampleAccessInfo =
    FACE_DM_RTI_ShapeFillKind_get_sample_access_info();
    FACE_DM_RTI_ShapeFillKind_g_tc._data._typePlugin =
    FACE_DM_RTI_ShapeFillKind_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &FACE_DM_RTI_ShapeFillKind_g_tc;
}

RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeFillKind_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo FACE_DM_RTI_ShapeFillKind_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo;
    }

    FACE_DM_RTI_ShapeFillKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo.memberAccessInfos = 
    FACE_DM_RTI_ShapeFillKind_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(FACE_DM_RTI_ShapeFillKind);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &FACE_DM_RTI_ShapeFillKind_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *FACE_DM_RTI_ShapeFillKind_get_type_plugin_info()
{
    static RTIXCdrTypePlugin FACE_DM_RTI_ShapeFillKind_g_typePlugin = 
    {
        (RTIXCdrTypePluginSerializeFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_serialize, 
        (RTIXCdrTypePluginSerializeKeyFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_serialize_key, 
        (RTIXCdrTypePluginDeserializeFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_deserialize_sample, 
        (RTIXCdrTypePluginDeserializeKeyFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_deserialize_key_sample, 
        (RTIXCdrTypePluginSkipFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_skip,
        (RTIXCdrTypePluginGetSerializedSampleSizeFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_size, 
        (RTIXCdrTypePluginGetSerializedSampleMaxSizeFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size_ex, 
        (RTIXCdrTypePluginGetSerializedKeyMaxSizeFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_key_max_size_ex, 
        (RTIXCdrTypePluginGetSerializedSampleMinSizeFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_min_size, 
        (RTIXCdrTypePluginSerializedSampleToKeyFunction) 
        FACE_DM_RTI_ShapeFillKindPlugin_serialized_sample_to_key,
        (RTIXCdrTypePluginInitializeSampleFunction) 
        FACE_DM_RTI_ShapeFillKind_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction) 
        FACE_DM_RTI_ShapeFillKind_finalize_w_return,
        NULL
    };

    return &FACE_DM_RTI_ShapeFillKind_g_typePlugin;
}
#endif

RTIBool FACE_DM_RTI_ShapeFillKind_initialize(
    FACE_DM_RTI_ShapeFillKind* sample) {
    *sample = FACE_DM_RTI_ShapeFillKind_SOLID_FILL;
    return RTI_TRUE;
}

RTIBool FACE_DM_RTI_ShapeFillKind_initialize_ex(
    FACE_DM_RTI_ShapeFillKind* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return FACE_DM_RTI_ShapeFillKind_initialize_w_params(
        sample,&allocParams);

}

RTIBool FACE_DM_RTI_ShapeFillKind_initialize_w_params(
    FACE_DM_RTI_ShapeFillKind* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = FACE_DM_RTI_ShapeFillKind_SOLID_FILL;
    return RTI_TRUE;
}

RTIBool FACE_DM_RTI_ShapeFillKind_finalize_w_return(
    FACE_DM_RTI_ShapeFillKind* sample)
{
    if (sample) {} /* To avoid warnings */

    return RTI_TRUE;
}

void FACE_DM_RTI_ShapeFillKind_finalize(
    FACE_DM_RTI_ShapeFillKind* sample)
{

    if (sample==NULL) {
        return;
    }
}

void FACE_DM_RTI_ShapeFillKind_finalize_ex(
    FACE_DM_RTI_ShapeFillKind* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    FACE_DM_RTI_ShapeFillKind_finalize_w_params(
        sample,&deallocParams);
}

void FACE_DM_RTI_ShapeFillKind_finalize_w_params(
    FACE_DM_RTI_ShapeFillKind* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void FACE_DM_RTI_ShapeFillKind_finalize_optional_members(
    FACE_DM_RTI_ShapeFillKind* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool FACE_DM_RTI_ShapeFillKind_copy(
    FACE_DM_RTI_ShapeFillKind* dst,
    const FACE_DM_RTI_ShapeFillKind* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FACE_DM_RTI_ShapeFillKind' sequence class.
*/
#define T FACE_DM_RTI_ShapeFillKind
#define TSeq FACE_DM_RTI_ShapeFillKindSeq

#define T_initialize_w_params FACE_DM_RTI_ShapeFillKind_initialize_w_params

#define T_finalize_w_params   FACE_DM_RTI_ShapeFillKind_finalize_w_params
#define T_copy       FACE_DM_RTI_ShapeFillKind_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *FACE_DM_RTI_ShapeTypeTYPENAME = "ShapeType";
//const char *FACE_DM_RTI_ShapeTypeTYPENAME = "FACE::DM::RTI::ShapeType";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * FACE_DM_RTI_ShapeType_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode FACE_DM_RTI_ShapeType_g_tc_color_string = DDS_INITIALIZE_STRING_TYPECODE_W_SAMPLE_ACCESS_INFO((128L), &DDS_g_sai_face_string);

    static DDS_TypeCode_Member FACE_DM_RTI_ShapeType_g_tc_members[4]=
    {

        {
            (char *)"color",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"x",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"y",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"shapesize",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode FACE_DM_RTI_ShapeType_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"FACE::DM::RTI::ShapeType", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            FACE_DM_RTI_ShapeType_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for FACE_DM_RTI_ShapeType*/

    if (is_initialized) {
        return &FACE_DM_RTI_ShapeType_g_tc;
    }

    FACE_DM_RTI_ShapeType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    FACE_DM_RTI_ShapeType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&FACE_DM_RTI_ShapeType_g_tc_color_string;
    FACE_DM_RTI_ShapeType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)FACE_Long_get_typecode();
    FACE_DM_RTI_ShapeType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)FACE_Long_get_typecode();
    FACE_DM_RTI_ShapeType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)FACE_Long_get_typecode();

    /* Initialize the values for member annotations. */
    FACE_DM_RTI_ShapeType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    FACE_DM_RTI_ShapeType_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    FACE_DM_RTI_ShapeType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    FACE_DM_RTI_ShapeType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    FACE_DM_RTI_ShapeType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    FACE_DM_RTI_ShapeType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
    FACE_DM_RTI_ShapeType_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    FACE_DM_RTI_ShapeType_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    FACE_DM_RTI_ShapeType_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
    FACE_DM_RTI_ShapeType_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    FACE_DM_RTI_ShapeType_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    FACE_DM_RTI_ShapeType_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    FACE_DM_RTI_ShapeType_g_tc._data._sampleAccessInfo =
    FACE_DM_RTI_ShapeType_get_sample_access_info();
    FACE_DM_RTI_ShapeType_g_tc._data._typePlugin =
    FACE_DM_RTI_ShapeType_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &FACE_DM_RTI_ShapeType_g_tc;
}

RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeType_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo FACE_DM_RTI_ShapeType_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo FACE_DM_RTI_ShapeType_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &FACE_DM_RTI_ShapeType_g_sampleAccessInfo;
    }

    FACE_DM_RTI_ShapeType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FACE_DM_RTI_ShapeType *)NULL)->color);

    FACE_DM_RTI_ShapeType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FACE_DM_RTI_ShapeType *)NULL)->x);

    FACE_DM_RTI_ShapeType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FACE_DM_RTI_ShapeType *)NULL)->y);

    FACE_DM_RTI_ShapeType_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FACE_DM_RTI_ShapeType *)NULL)->shapesize);

    FACE_DM_RTI_ShapeType_g_sampleAccessInfo.memberAccessInfos = 
    FACE_DM_RTI_ShapeType_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(FACE_DM_RTI_ShapeType);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            FACE_DM_RTI_ShapeType_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            FACE_DM_RTI_ShapeType_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    FACE_DM_RTI_ShapeType_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &FACE_DM_RTI_ShapeType_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *FACE_DM_RTI_ShapeType_get_type_plugin_info()
{
    static RTIXCdrTypePlugin FACE_DM_RTI_ShapeType_g_typePlugin = 
    {
        (RTIXCdrTypePluginSerializeFunction) 
        FACE_DM_RTI_ShapeTypePlugin_serialize, 
        (RTIXCdrTypePluginSerializeKeyFunction) 
        FACE_DM_RTI_ShapeTypePlugin_serialize_key, 
        (RTIXCdrTypePluginDeserializeFunction) 
        FACE_DM_RTI_ShapeTypePlugin_deserialize_sample, 
        (RTIXCdrTypePluginDeserializeKeyFunction) 
        FACE_DM_RTI_ShapeTypePlugin_deserialize_key_sample, 
        (RTIXCdrTypePluginSkipFunction) 
        FACE_DM_RTI_ShapeTypePlugin_skip,
        (RTIXCdrTypePluginGetSerializedSampleSizeFunction) 
        FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_size, 
        (RTIXCdrTypePluginGetSerializedSampleMaxSizeFunction) 
        FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size_ex, 
        (RTIXCdrTypePluginGetSerializedKeyMaxSizeFunction) 
        FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_ex, 
        (RTIXCdrTypePluginGetSerializedSampleMinSizeFunction) 
        FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_min_size, 
        (RTIXCdrTypePluginSerializedSampleToKeyFunction) 
        FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_key,
        (RTIXCdrTypePluginInitializeSampleFunction) 
        FACE_DM_RTI_ShapeType_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction) 
        FACE_DM_RTI_ShapeType_finalize_w_return,
        NULL
    };

    return &FACE_DM_RTI_ShapeType_g_typePlugin;
}
#endif

RTIBool FACE_DM_RTI_ShapeType_initialize(
    FACE_DM_RTI_ShapeType* sample) {
    return FACE_DM_RTI_ShapeType_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool FACE_DM_RTI_ShapeType_initialize_ex(
    FACE_DM_RTI_ShapeType* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return FACE_DM_RTI_ShapeType_initialize_w_params(
        sample,&allocParams);

}

RTIBool FACE_DM_RTI_ShapeType_initialize_w_params(
    FACE_DM_RTI_ShapeType* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!FACE_String_initialize(&sample->color, (128L))){
        return RTI_FALSE;
    }

    sample->x = 0;

    sample->y = 0;

    sample->shapesize = 0;

    return RTI_TRUE;
}

RTIBool FACE_DM_RTI_ShapeType_finalize_w_return(
    FACE_DM_RTI_ShapeType* sample)
{
    FACE_DM_RTI_ShapeType_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void FACE_DM_RTI_ShapeType_finalize(
    FACE_DM_RTI_ShapeType* sample)
{

    FACE_DM_RTI_ShapeType_finalize_ex(sample,RTI_TRUE);
}

void FACE_DM_RTI_ShapeType_finalize_ex(
    FACE_DM_RTI_ShapeType* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    FACE_DM_RTI_ShapeType_finalize_w_params(
        sample,&deallocParams);
}

void FACE_DM_RTI_ShapeType_finalize_w_params(
    FACE_DM_RTI_ShapeType* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if(!FACE_String_finalize(&sample->color)){
        return;
    }

}

void FACE_DM_RTI_ShapeType_finalize_optional_members(
    FACE_DM_RTI_ShapeType* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool FACE_DM_RTI_ShapeType_copy(
    FACE_DM_RTI_ShapeType* dst,
    const FACE_DM_RTI_ShapeType* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!FACE_String_copy(&dst->color,
    &src->color,
    (128L)))
    {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->x, &src->x)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->y, &src->y)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->shapesize, &src->shapesize)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FACE_DM_RTI_ShapeType' sequence class.
*/
#define T FACE_DM_RTI_ShapeType
#define TSeq FACE_DM_RTI_ShapeTypeSeq

#define T_initialize_w_params FACE_DM_RTI_ShapeType_initialize_w_params

#define T_finalize_w_params   FACE_DM_RTI_ShapeType_finalize_w_params
#define T_copy       FACE_DM_RTI_ShapeType_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *FACE_DM_RTI_ShapeTypeExtendedTYPENAME = "ShapeTypeExtended";
//const char *FACE_DM_RTI_ShapeTypeExtendedTYPENAME = "FACE::DM::RTI::ShapeTypeExtended";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * FACE_DM_RTI_ShapeTypeExtended_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member FACE_DM_RTI_ShapeTypeExtended_g_tc_members[2]=
    {

        {
            (char *)"fillKind",/* Member name */
            {
                4,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"angle",/* Member name */
            {
                5,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode FACE_DM_RTI_ShapeTypeExtended_g_tc =
    {{
            DDS_TK_VALUE, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"FACE::DM::RTI::ShapeTypeExtended", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            FACE_DM_RTI_ShapeTypeExtended_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for FACE_DM_RTI_ShapeTypeExtended*/

    if (is_initialized) {
        return &FACE_DM_RTI_ShapeTypeExtended_g_tc;
    }

    FACE_DM_RTI_ShapeTypeExtended_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)FACE_DM_RTI_ShapeFillKind_get_typecode();
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)FACE_Float_get_typecode();

    /* Initialize the values for member annotations. */
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    FACE_DM_RTI_ShapeTypeExtended_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    FACE_DM_RTI_ShapeTypeExtended_g_tc._data._typeCode = (RTICdrTypeCode *)FACE_DM_RTI_ShapeType_get_typecode(); /* Base class */

    FACE_DM_RTI_ShapeTypeExtended_g_tc._data._sampleAccessInfo =
    FACE_DM_RTI_ShapeTypeExtended_get_sample_access_info();
    FACE_DM_RTI_ShapeTypeExtended_g_tc._data._typePlugin =
    FACE_DM_RTI_ShapeTypeExtended_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &FACE_DM_RTI_ShapeTypeExtended_g_tc;
}

RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeTypeExtended_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo FACE_DM_RTI_ShapeTypeExtended_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo;
    }

    FACE_DM_RTI_ShapeTypeExtended_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FACE_DM_RTI_ShapeTypeExtended *)NULL)->fillKind);

    FACE_DM_RTI_ShapeTypeExtended_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FACE_DM_RTI_ShapeTypeExtended *)NULL)->angle);

    FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo.memberAccessInfos = 
    FACE_DM_RTI_ShapeTypeExtended_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(FACE_DM_RTI_ShapeTypeExtended);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &FACE_DM_RTI_ShapeTypeExtended_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *FACE_DM_RTI_ShapeTypeExtended_get_type_plugin_info()
{
    static RTIXCdrTypePlugin FACE_DM_RTI_ShapeTypeExtended_g_typePlugin = 
    {
        (RTIXCdrTypePluginSerializeFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize, 
        (RTIXCdrTypePluginSerializeKeyFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_key, 
        (RTIXCdrTypePluginDeserializeFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_sample, 
        (RTIXCdrTypePluginDeserializeKeyFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key_sample, 
        (RTIXCdrTypePluginSkipFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_skip,
        (RTIXCdrTypePluginGetSerializedSampleSizeFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_size, 
        (RTIXCdrTypePluginGetSerializedSampleMaxSizeFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size_ex, 
        (RTIXCdrTypePluginGetSerializedKeyMaxSizeFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_ex, 
        (RTIXCdrTypePluginGetSerializedSampleMinSizeFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_min_size, 
        (RTIXCdrTypePluginSerializedSampleToKeyFunction) 
        FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_key,
        (RTIXCdrTypePluginInitializeSampleFunction) 
        FACE_DM_RTI_ShapeTypeExtended_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction) 
        FACE_DM_RTI_ShapeTypeExtended_finalize_w_return,
        NULL
    };

    return &FACE_DM_RTI_ShapeTypeExtended_g_typePlugin;
}
#endif

RTIBool FACE_DM_RTI_ShapeTypeExtended_initialize(
    FACE_DM_RTI_ShapeTypeExtended* sample) {
    return FACE_DM_RTI_ShapeTypeExtended_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool FACE_DM_RTI_ShapeTypeExtended_initialize_ex(
    FACE_DM_RTI_ShapeTypeExtended* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return FACE_DM_RTI_ShapeTypeExtended_initialize_w_params(
        sample,&allocParams);

}

RTIBool FACE_DM_RTI_ShapeTypeExtended_initialize_w_params(
    FACE_DM_RTI_ShapeTypeExtended* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    if (!FACE_DM_RTI_ShapeType_initialize_w_params((FACE_DM_RTI_ShapeType*)sample,allocParams)) {
        return RTI_FALSE;
    }

    sample->fillKind = FACE_DM_RTI_ShapeFillKind_SOLID_FILL;
    sample->angle = 0.0f;

    return RTI_TRUE;
}

RTIBool FACE_DM_RTI_ShapeTypeExtended_finalize_w_return(
    FACE_DM_RTI_ShapeTypeExtended* sample)
{
    FACE_DM_RTI_ShapeTypeExtended_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void FACE_DM_RTI_ShapeTypeExtended_finalize(
    FACE_DM_RTI_ShapeTypeExtended* sample)
{

    FACE_DM_RTI_ShapeTypeExtended_finalize_ex(sample,RTI_TRUE);
}

void FACE_DM_RTI_ShapeTypeExtended_finalize_ex(
    FACE_DM_RTI_ShapeTypeExtended* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    FACE_DM_RTI_ShapeTypeExtended_finalize_w_params(
        sample,&deallocParams);
}

void FACE_DM_RTI_ShapeTypeExtended_finalize_w_params(
    FACE_DM_RTI_ShapeTypeExtended* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }
    FACE_DM_RTI_ShapeType_finalize_w_params((FACE_DM_RTI_ShapeType*)sample,deallocParams);

    FACE_DM_RTI_ShapeFillKind_finalize_w_params(&sample->fillKind,deallocParams);

}

void FACE_DM_RTI_ShapeTypeExtended_finalize_optional_members(
    FACE_DM_RTI_ShapeTypeExtended* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    FACE_DM_RTI_ShapeType_finalize_optional_members((FACE_DM_RTI_ShapeType*)sample,deletePointers);

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool FACE_DM_RTI_ShapeTypeExtended_copy(
    FACE_DM_RTI_ShapeTypeExtended* dst,
    const FACE_DM_RTI_ShapeTypeExtended* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if(!FACE_DM_RTI_ShapeType_copy((FACE_DM_RTI_ShapeType*)dst,(const FACE_DM_RTI_ShapeType*)src)) {
        return RTI_FALSE;
    }

    if (!FACE_DM_RTI_ShapeFillKind_copy(
        &dst->fillKind,(const FACE_DM_RTI_ShapeFillKind*)&src->fillKind)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyFloat (
        &dst->angle, &src->angle)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FACE_DM_RTI_ShapeTypeExtended' sequence class.
*/
#define T FACE_DM_RTI_ShapeTypeExtended
#define TSeq FACE_DM_RTI_ShapeTypeExtendedSeq

#define T_initialize_w_params FACE_DM_RTI_ShapeTypeExtended_initialize_w_params

#define T_finalize_w_params   FACE_DM_RTI_ShapeTypeExtended_finalize_w_params
#define T_copy       FACE_DM_RTI_ShapeTypeExtended_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

