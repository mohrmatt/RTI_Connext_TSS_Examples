

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl
using RTI Code Generator (rtiddsgen) version 3.1.2.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ShapeTypePlugin_434673847_h
#define ShapeTypePlugin_434673847_h

#include "ShapeType.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "FACE/typesPlugin.h"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeFillKindPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const FACE_DM_RTI_ShapeFillKind *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeFillKindPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeFillKind *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeFillKindPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const FACE_DM_RTI_ShapeFillKind * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeFillKindPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeFillKindPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const FACE_DM_RTI_ShapeFillKind *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeFillKindPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeFillKind * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeFillKindPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeFillKind *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    FACE_DM_RTI_ShapeFillKindPluginSupport_print_data(
        const FACE_DM_RTI_ShapeFillKind *sample, const char *desc, int indent_level);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ShapeType
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ShapeType)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ShapeType must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ShapeType.
    */
    typedef  struct FACE_DM_RTI_ShapeType FACE_DM_RTI_ShapeTypeKeyHolder;

    #define FACE_DM_RTI_ShapeTypePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define FACE_DM_RTI_ShapeTypePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define FACE_DM_RTI_ShapeTypePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define FACE_DM_RTI_ShapeTypePlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define FACE_DM_RTI_ShapeTypePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define FACE_DM_RTI_ShapeTypePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define FACE_DM_RTI_ShapeTypePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeType*
    FACE_DM_RTI_ShapeTypePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeType*
    FACE_DM_RTI_ShapeTypePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeType*
    FACE_DM_RTI_ShapeTypePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePluginSupport_copy_data(
        FACE_DM_RTI_ShapeType *out,
        const FACE_DM_RTI_ShapeType *in);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePluginSupport_destroy_data_w_params(
        FACE_DM_RTI_ShapeType *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePluginSupport_destroy_data_ex(
        FACE_DM_RTI_ShapeType *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePluginSupport_destroy_data(
        FACE_DM_RTI_ShapeType *sample);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePluginSupport_print_data(
        const FACE_DM_RTI_ShapeType *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeType*
    FACE_DM_RTI_ShapeTypePluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeType*
    FACE_DM_RTI_ShapeTypePluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePluginSupport_destroy_key_ex(
        FACE_DM_RTI_ShapeTypeKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePluginSupport_destroy_key(
        FACE_DM_RTI_ShapeTypeKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    FACE_DM_RTI_ShapeTypePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    FACE_DM_RTI_ShapeTypePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    FACE_DM_RTI_ShapeTypePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType *out,
        const FACE_DM_RTI_ShapeType *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const FACE_DM_RTI_ShapeType *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const FACE_DM_RTI_ShapeType *sample); 

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypePlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const FACE_DM_RTI_ShapeType *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypePlugin_deserialize_from_cdr_buffer(
        FACE_DM_RTI_ShapeType *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    FACE_DM_RTI_ShapeTypePlugin_data_to_string(
        const FACE_DM_RTI_ShapeType *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypePlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const FACE_DM_RTI_ShapeType * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    FACE_DM_RTI_ShapeTypePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const FACE_DM_RTI_ShapeType *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeKeyHolder *key, 
        const FACE_DM_RTI_ShapeType *instance);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeType *instance, 
        const FACE_DM_RTI_ShapeTypeKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_instance_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        DDS_KeyHash_t *keyhash,
        const FACE_DM_RTI_ShapeType *instance,
        RTIEncapsulationId encapsulationId);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypePlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * FACE_DM_RTI_ShapeTypePlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    FACE_DM_RTI_ShapeTypePlugin_new(void);

    NDDSUSERDllExport extern void
    FACE_DM_RTI_ShapeTypePlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ShapeTypeExtended
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ShapeTypeExtended)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ShapeTypeExtended must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ShapeTypeExtended.
    */
    typedef  struct FACE_DM_RTI_ShapeTypeExtended FACE_DM_RTI_ShapeTypeExtendedKeyHolder;

    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define FACE_DM_RTI_ShapeTypeExtendedPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeTypeExtended*
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeTypeExtended*
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeTypeExtended*
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_copy_data(
        FACE_DM_RTI_ShapeTypeExtended *out,
        const FACE_DM_RTI_ShapeTypeExtended *in);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data_w_params(
        FACE_DM_RTI_ShapeTypeExtended *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data_ex(
        FACE_DM_RTI_ShapeTypeExtended *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_data(
        FACE_DM_RTI_ShapeTypeExtended *sample);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_print_data(
        const FACE_DM_RTI_ShapeTypeExtended *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeTypeExtended*
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern FACE_DM_RTI_ShapeTypeExtended*
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_key_ex(
        FACE_DM_RTI_ShapeTypeExtendedKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPluginSupport_destroy_key(
        FACE_DM_RTI_ShapeTypeExtendedKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    FACE_DM_RTI_ShapeTypeExtendedPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended *out,
        const FACE_DM_RTI_ShapeTypeExtended *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const FACE_DM_RTI_ShapeTypeExtended *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const FACE_DM_RTI_ShapeTypeExtended *sample); 

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const FACE_DM_RTI_ShapeTypeExtended *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_from_cdr_buffer(
        FACE_DM_RTI_ShapeTypeExtended *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    FACE_DM_RTI_ShapeTypeExtendedPlugin_data_to_string(
        const FACE_DM_RTI_ShapeTypeExtended *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypeExtendedPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const FACE_DM_RTI_ShapeTypeExtended * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const FACE_DM_RTI_ShapeTypeExtended *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtendedKeyHolder *key, 
        const FACE_DM_RTI_ShapeTypeExtended *instance);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        FACE_DM_RTI_ShapeTypeExtended *instance, 
        const FACE_DM_RTI_ShapeTypeExtendedKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_instance_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        DDS_KeyHash_t *keyhash,
        const FACE_DM_RTI_ShapeTypeExtended *instance,
        RTIEncapsulationId encapsulationId);

    NDDSUSERDllExport extern RTIBool 
    FACE_DM_RTI_ShapeTypeExtendedPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * FACE_DM_RTI_ShapeTypeExtendedPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    FACE_DM_RTI_ShapeTypeExtendedPlugin_new(void);

    NDDSUSERDllExport extern void
    FACE_DM_RTI_ShapeTypeExtendedPlugin_delete(struct PRESTypePlugin *);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* ShapeTypePlugin_434673847_h */

