/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "ShapeType.h"

#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

/*** SOURCE_BEGIN ***/

/* ========================================================================= */

RTI_BOOL
FACE_DM_RTI_ShapeFillKind_initialize(FACE_DM_RTI_ShapeFillKind* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    /* The following initializes the enum value to zero. However,
    * some enumerations may not have a member with the value zero. In such
    * cases, it may be desirable to modify the generated code to use a valid
    * enumeration member instead.
    */
    *sample = (FACE_DM_RTI_ShapeFillKind)0;
    return RTI_TRUE;
}

FACE_DM_RTI_ShapeFillKind *
FACE_DM_RTI_ShapeFillKind_create(void)
{
    FACE_DM_RTI_ShapeFillKind* sample;
    OSAPI_Heap_allocate_struct(&sample, FACE_DM_RTI_ShapeFillKind);
    if (sample != NULL)
    {
        if (!FACE_DM_RTI_ShapeFillKind_initialize(sample))
        {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
FACE_DM_RTI_ShapeFillKind_finalize(FACE_DM_RTI_ShapeFillKind* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

#ifndef RTI_CERT
void
FACE_DM_RTI_ShapeFillKind_delete(FACE_DM_RTI_ShapeFillKind* sample)
{
    if (sample != NULL)
    {
        /* FACE_DM_RTI_ShapeFillKind_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        FACE_DM_RTI_ShapeFillKind_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif
#endif

RTI_BOOL
FACE_DM_RTI_ShapeFillKind_copy(FACE_DM_RTI_ShapeFillKind* dst,const FACE_DM_RTI_ShapeFillKind* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    *dst = *src;
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FACE_DM_RTI_ShapeFillKind' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T FACE_DM_RTI_ShapeFillKind
#define TSeq FACE_DM_RTI_ShapeFillKindSeq
#define T_initialize FACE_DM_RTI_ShapeFillKind_initialize
#define T_finalize   FACE_DM_RTI_ShapeFillKind_finalize
#define T_copy       FACE_DM_RTI_ShapeFillKind_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *FACE_DM_RTI_ShapeTypeTYPENAME = "ShapeType";
// const char *FACE_DM_RTI_ShapeTypeTYPENAME = "FACE::DM::RTI::ShapeType";

RTI_BOOL
FACE_DM_RTI_ShapeType_initialize(FACE_DM_RTI_ShapeType* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!FACE_String_initialize(
        &sample->color,
        128))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_init_long(&sample->x);
    CDR_Primitive_init_long(&sample->y);
    CDR_Primitive_init_long(&sample->shapesize);
    return RTI_TRUE;
}

FACE_DM_RTI_ShapeType *
FACE_DM_RTI_ShapeType_create(void)
{
    FACE_DM_RTI_ShapeType* sample;
    OSAPI_Heap_allocate_struct(&sample, FACE_DM_RTI_ShapeType);
    if (sample != NULL)
    {
        if (!FACE_DM_RTI_ShapeType_initialize(sample))
        {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
FACE_DM_RTI_ShapeType_finalize(FACE_DM_RTI_ShapeType* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    FACE_String_finalize(&sample->color);
    return RTI_TRUE;
}

#ifndef RTI_CERT
void
FACE_DM_RTI_ShapeType_delete(FACE_DM_RTI_ShapeType* sample)
{
    if (sample != NULL)
    {
        /* FACE_DM_RTI_ShapeType_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        FACE_DM_RTI_ShapeType_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif
#endif

RTI_BOOL
FACE_DM_RTI_ShapeType_copy(FACE_DM_RTI_ShapeType* dst,const FACE_DM_RTI_ShapeType* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!FACE_String_copy(
        &dst->color, &src->color,
        128))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_long(&dst->x, &src->x);
    CDR_Primitive_copy_long(&dst->y, &src->y);
    CDR_Primitive_copy_long(&dst->shapesize, &src->shapesize);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FACE_DM_RTI_ShapeType' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T FACE_DM_RTI_ShapeType
#define TSeq FACE_DM_RTI_ShapeTypeSeq
#define T_initialize FACE_DM_RTI_ShapeType_initialize
#define T_finalize   FACE_DM_RTI_ShapeType_finalize
#define T_copy       FACE_DM_RTI_ShapeType_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *FACE_DM_RTI_ShapeTypeExtendedTYPENAME = "ShapeTypeExtended";
// const char *FACE_DM_RTI_ShapeTypeExtendedTYPENAME = "FACE::DM::RTI::ShapeTypeExtended";

RTI_BOOL
FACE_DM_RTI_ShapeTypeExtended_initialize(FACE_DM_RTI_ShapeTypeExtended* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!FACE_DM_RTI_ShapeType_initialize((FACE_DM_RTI_ShapeType*)sample))
    {
        return RTI_FALSE;
    }
    if (!FACE_DM_RTI_ShapeFillKind_initialize(&sample->fillKind))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_init_float(&sample->angle);
    return RTI_TRUE;
}

FACE_DM_RTI_ShapeTypeExtended *
FACE_DM_RTI_ShapeTypeExtended_create(void)
{
    FACE_DM_RTI_ShapeTypeExtended* sample;
    OSAPI_Heap_allocate_struct(&sample, FACE_DM_RTI_ShapeTypeExtended);
    if (sample != NULL)
    {
        if (!FACE_DM_RTI_ShapeTypeExtended_initialize(sample))
        {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
FACE_DM_RTI_ShapeTypeExtended_finalize(FACE_DM_RTI_ShapeTypeExtended* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    FACE_DM_RTI_ShapeType_finalize((FACE_DM_RTI_ShapeType*)sample);
    FACE_DM_RTI_ShapeFillKind_finalize(&sample->fillKind);
    return RTI_TRUE;
}

#ifndef RTI_CERT
void
FACE_DM_RTI_ShapeTypeExtended_delete(FACE_DM_RTI_ShapeTypeExtended* sample)
{
    if (sample != NULL)
    {
        /* FACE_DM_RTI_ShapeTypeExtended_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        FACE_DM_RTI_ShapeTypeExtended_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif
#endif

RTI_BOOL
FACE_DM_RTI_ShapeTypeExtended_copy(FACE_DM_RTI_ShapeTypeExtended* dst,const FACE_DM_RTI_ShapeTypeExtended* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if(!FACE_DM_RTI_ShapeType_copy((FACE_DM_RTI_ShapeType*)dst,(FACE_DM_RTI_ShapeType*)src))
    {
        return RTI_FALSE;
    }
    if (!FACE_DM_RTI_ShapeFillKind_copy(
        &dst->fillKind, &src->fillKind))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_float(&dst->angle, &src->angle);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FACE_DM_RTI_ShapeTypeExtended' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T FACE_DM_RTI_ShapeTypeExtended
#define TSeq FACE_DM_RTI_ShapeTypeExtendedSeq
#define T_initialize FACE_DM_RTI_ShapeTypeExtended_initialize
#define T_finalize   FACE_DM_RTI_ShapeTypeExtended_finalize
#define T_copy       FACE_DM_RTI_ShapeTypeExtended_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

