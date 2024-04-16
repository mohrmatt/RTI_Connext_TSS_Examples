
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl
using RTI Code Generator (rtiddsgen) version 3.1.2.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ShapeTypeSupport_434673847_h
#define ShapeTypeSupport_434673847_h

/* Uses */
#include "ShapeType.h"

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    #if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)

    #endif

    /* ========================================================================= */
    /**
    Uses:     T

    Defines:  TTypeSupport, TDataWriter, TDataReader

    Organized using the well-documented "Generics Pattern" for
    implementing generics in C and C++.
    */

    #if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
    /* If the code is building on Windows, start exporting symbols.
    */
    #undef NDDSUSERDllExport
    #define NDDSUSERDllExport __declspec(dllexport)

    #endif

    DDS_TYPESUPPORT_C(FACE_DM_RTI_ShapeTypeTypeSupport, FACE_DM_RTI_ShapeType);
    DDS_DATAWRITER_WITH_DATA_CONSTRUCTOR_METHODS_C(FACE_DM_RTI_ShapeTypeDataWriter, FACE_DM_RTI_ShapeType);
    DDS_DATAREADER_C(FACE_DM_RTI_ShapeTypeDataReader, FACE_DM_RTI_ShapeTypeSeq, FACE_DM_RTI_ShapeType);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
    /* If the code is building on Windows, stop exporting symbols.
    */
    #undef NDDSUSERDllExport
    #define NDDSUSERDllExport
    #endif
    /* ========================================================================= */
    /**
    Uses:     T

    Defines:  TTypeSupport, TDataWriter, TDataReader

    Organized using the well-documented "Generics Pattern" for
    implementing generics in C and C++.
    */

    #if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
    /* If the code is building on Windows, start exporting symbols.
    */
    #undef NDDSUSERDllExport
    #define NDDSUSERDllExport __declspec(dllexport)

    #endif

    DDS_TYPESUPPORT_C(FACE_DM_RTI_ShapeTypeExtendedTypeSupport, FACE_DM_RTI_ShapeTypeExtended);
    DDS_DATAWRITER_WITH_DATA_CONSTRUCTOR_METHODS_C(FACE_DM_RTI_ShapeTypeExtendedDataWriter, FACE_DM_RTI_ShapeTypeExtended);
    DDS_DATAREADER_C(FACE_DM_RTI_ShapeTypeExtendedDataReader, FACE_DM_RTI_ShapeTypeExtendedSeq, FACE_DM_RTI_ShapeTypeExtended);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
    /* If the code is building on Windows, stop exporting symbols.
    */
    #undef NDDSUSERDllExport
    #define NDDSUSERDllExport
    #endif

    #ifdef __cplusplus
}
#endif

#endif  /* ShapeTypeSupport_434673847_h */

