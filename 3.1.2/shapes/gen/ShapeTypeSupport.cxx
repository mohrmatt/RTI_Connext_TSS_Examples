
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl
using RTI Code Generator (rtiddsgen) version 3.1.2.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include "ShapeTypeSupport.h"
#include "ShapeTypePlugin.h"

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'FACE_DM_RTI_ShapeType' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   FACE_DM_RTI_ShapeTypeTYPENAME

/* Defines */
#define TDataWriter FACE_DM_RTI_ShapeTypeDataWriter
#define TData       FACE_DM_RTI_ShapeType

#define ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#undef ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   FACE_DM_RTI_ShapeTypeTYPENAME

/* Defines */
#define TDataReader FACE_DM_RTI_ShapeTypeDataReader
#define TDataSeq    FACE_DM_RTI_ShapeTypeSeq
#define TData       FACE_DM_RTI_ShapeType

#define ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#undef ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    FACE_DM_RTI_ShapeTypeTYPENAME
#define TPlugin_new  FACE_DM_RTI_ShapeTypePlugin_new
#define TPlugin_delete  FACE_DM_RTI_ShapeTypePlugin_delete

/* Defines */
#define TTypeSupport FACE_DM_RTI_ShapeTypeTypeSupport
#define TData        FACE_DM_RTI_ShapeType
#define TDataReader  FACE_DM_RTI_ShapeTypeDataReader
#define TDataWriter  FACE_DM_RTI_ShapeTypeDataWriter
#define TGENERATE_SER_CODE
#ifndef NDDS_STANDALONE_TYPE
#define TGENERATE_TYPECODE
#endif

#include "dds_c/generic/dds_c_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#ifndef NDDS_STANDALONE_TYPE
#undef TGENERATE_TYPECODE
#endif
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'FACE_DM_RTI_ShapeTypeExtended' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   FACE_DM_RTI_ShapeTypeExtendedTYPENAME

/* Defines */
#define TDataWriter FACE_DM_RTI_ShapeTypeExtendedDataWriter
#define TData       FACE_DM_RTI_ShapeTypeExtended

#define ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#undef ENABLE_TDATAWRITER_DATA_CONSTRUCTOR_METHODS

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   FACE_DM_RTI_ShapeTypeExtendedTYPENAME

/* Defines */
#define TDataReader FACE_DM_RTI_ShapeTypeExtendedDataReader
#define TDataSeq    FACE_DM_RTI_ShapeTypeExtendedSeq
#define TData       FACE_DM_RTI_ShapeTypeExtended

#define ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#undef ENABLE_TDATAREADER_DATA_CONSISTENCY_CHECK_METHOD

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    FACE_DM_RTI_ShapeTypeExtendedTYPENAME
#define TPlugin_new  FACE_DM_RTI_ShapeTypeExtendedPlugin_new
#define TPlugin_delete  FACE_DM_RTI_ShapeTypeExtendedPlugin_delete

/* Defines */
#define TTypeSupport FACE_DM_RTI_ShapeTypeExtendedTypeSupport
#define TData        FACE_DM_RTI_ShapeTypeExtended
#define TDataReader  FACE_DM_RTI_ShapeTypeExtendedDataReader
#define TDataWriter  FACE_DM_RTI_ShapeTypeExtendedDataWriter
#define TGENERATE_SER_CODE
#ifndef NDDS_STANDALONE_TYPE
#define TGENERATE_TYPECODE
#endif

#include "dds_c/generic/dds_c_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#ifndef NDDS_STANDALONE_TYPE
#undef TGENERATE_TYPECODE
#endif
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

