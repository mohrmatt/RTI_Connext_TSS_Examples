

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl
using RTI Code Generator (rtiddsgen) version 3.1.2.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ShapeType_434673847_h
#define ShapeType_434673847_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

#include "FACE/Sequence.hpp"
#include "FACE/Sequence_type_plugin.hpp"
#include "FACE/String.hpp"
#include "FACE/String_type_plugin.hpp"

#include "FACE/types.h"
typedef enum FACE_DM_RTI_ShapeFillKind
{
    FACE_DM_RTI_ShapeFillKind_SOLID_FILL , 
    FACE_DM_RTI_ShapeFillKind_TRANSPARENT_FILL , 
    FACE_DM_RTI_ShapeFillKind_HORIZONTAL_HATCH_FILL , 
    FACE_DM_RTI_ShapeFillKind_VERTICAL_HATCH_FILL 
} FACE_DM_RTI_ShapeFillKind;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * FACE_DM_RTI_ShapeFillKind_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *FACE_DM_RTI_ShapeFillKind_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeFillKind_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeFillKind_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(FACE_DM_RTI_ShapeFillKindSeq, FACE_DM_RTI_ShapeFillKind);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeFillKind_initialize(
    FACE_DM_RTI_ShapeFillKind* self);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeFillKind_initialize_ex(
    FACE_DM_RTI_ShapeFillKind* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeFillKind_initialize_w_params(
    FACE_DM_RTI_ShapeFillKind* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeFillKind_finalize_w_return(
    FACE_DM_RTI_ShapeFillKind* self);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeFillKind_finalize(
    FACE_DM_RTI_ShapeFillKind* self);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeFillKind_finalize_ex(
    FACE_DM_RTI_ShapeFillKind* self,RTIBool deletePointers);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeFillKind_finalize_w_params(
    FACE_DM_RTI_ShapeFillKind* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeFillKind_finalize_optional_members(
    FACE_DM_RTI_ShapeFillKind* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeFillKind_copy(
    FACE_DM_RTI_ShapeFillKind* dst,
    const FACE_DM_RTI_ShapeFillKind* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *FACE_DM_RTI_ShapeTypeTYPENAME;

}

struct FACE_DM_RTI_ShapeTypeSeq;
#ifndef NDDS_STANDALONE_TYPE
class FACE_DM_RTI_ShapeTypeTypeSupport;
class FACE_DM_RTI_ShapeTypeDataWriter;
class FACE_DM_RTI_ShapeTypeDataReader;
#endif
class FACE_DM_RTI_ShapeType 
{
  public:
    typedef struct FACE_DM_RTI_ShapeTypeSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef FACE_DM_RTI_ShapeTypeTypeSupport TypeSupport;
    typedef FACE_DM_RTI_ShapeTypeDataWriter DataWriter;
    typedef FACE_DM_RTI_ShapeTypeDataReader DataReader;
    #endif

    FACE::String   color ;
    DDS_Long   x ;
    DDS_Long   y ;
    DDS_Long   shapesize ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * FACE_DM_RTI_ShapeType_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *FACE_DM_RTI_ShapeType_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeType_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeType_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(FACE_DM_RTI_ShapeTypeSeq, FACE_DM_RTI_ShapeType);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeType_initialize(
    FACE_DM_RTI_ShapeType* self);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeType_initialize_ex(
    FACE_DM_RTI_ShapeType* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeType_initialize_w_params(
    FACE_DM_RTI_ShapeType* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeType_finalize_w_return(
    FACE_DM_RTI_ShapeType* self);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeType_finalize(
    FACE_DM_RTI_ShapeType* self);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeType_finalize_ex(
    FACE_DM_RTI_ShapeType* self,RTIBool deletePointers);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeType_finalize_w_params(
    FACE_DM_RTI_ShapeType* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeType_finalize_optional_members(
    FACE_DM_RTI_ShapeType* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeType_copy(
    FACE_DM_RTI_ShapeType* dst,
    const FACE_DM_RTI_ShapeType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *FACE_DM_RTI_ShapeTypeExtendedTYPENAME;

}

struct FACE_DM_RTI_ShapeTypeExtendedSeq;
#ifndef NDDS_STANDALONE_TYPE
class FACE_DM_RTI_ShapeTypeExtendedTypeSupport;
class FACE_DM_RTI_ShapeTypeExtendedDataWriter;
class FACE_DM_RTI_ShapeTypeExtendedDataReader;
#endif
class FACE_DM_RTI_ShapeTypeExtended 
: public FACE_DM_RTI_ShapeType{
  public:
    typedef struct FACE_DM_RTI_ShapeTypeExtendedSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef FACE_DM_RTI_ShapeTypeExtendedTypeSupport TypeSupport;
    typedef FACE_DM_RTI_ShapeTypeExtendedDataWriter DataWriter;
    typedef FACE_DM_RTI_ShapeTypeExtendedDataReader DataReader;
    #endif

    FACE_DM_RTI_ShapeFillKind   fillKind ;
    DDS_Float   angle ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * FACE_DM_RTI_ShapeTypeExtended_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *FACE_DM_RTI_ShapeTypeExtended_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeTypeExtended_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FACE_DM_RTI_ShapeTypeExtended_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(FACE_DM_RTI_ShapeTypeExtendedSeq, FACE_DM_RTI_ShapeTypeExtended);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeTypeExtended_initialize(
    FACE_DM_RTI_ShapeTypeExtended* self);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeTypeExtended_initialize_ex(
    FACE_DM_RTI_ShapeTypeExtended* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeTypeExtended_initialize_w_params(
    FACE_DM_RTI_ShapeTypeExtended* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeTypeExtended_finalize_w_return(
    FACE_DM_RTI_ShapeTypeExtended* self);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeTypeExtended_finalize(
    FACE_DM_RTI_ShapeTypeExtended* self);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeTypeExtended_finalize_ex(
    FACE_DM_RTI_ShapeTypeExtended* self,RTIBool deletePointers);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeTypeExtended_finalize_w_params(
    FACE_DM_RTI_ShapeTypeExtended* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void FACE_DM_RTI_ShapeTypeExtended_finalize_optional_members(
    FACE_DM_RTI_ShapeTypeExtended* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool FACE_DM_RTI_ShapeTypeExtended_copy(
    FACE_DM_RTI_ShapeTypeExtended* dst,
    const FACE_DM_RTI_ShapeTypeExtended* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<FACE_DM_RTI_ShapeType> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code<FACE_DM_RTI_ShapeTypeExtended> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* ShapeType */

