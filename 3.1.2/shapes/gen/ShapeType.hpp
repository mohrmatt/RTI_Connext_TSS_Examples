
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS version".
*/

#ifndef ShapeType_434673847_hpp
#define ShapeType_434673847_hpp

#include "ShapeType.h"

#include "FACE/types.hpp"
namespace FACE {
    namespace DM {
        namespace RTI {
            struct ShapeFillKind
            {
                enum Value
                {
                    SOLID_FILL,
                    TRANSPARENT_FILL,
                    HORIZONTAL_HATCH_FILL,
                    VERTICAL_HATCH_FILL
                };
              private:
                ShapeFillKind();
            };

            class ShapeType{
              public:
                FACE::String color;
                FACE::Long x;
                FACE::Long y;
                FACE::Long shapesize;

                ShapeType(FACE::Boolean initialize = true)
                {
                    if (initialize)
                    {
                        FACE_DM_RTI_ShapeType_initialize(
                            (FACE_DM_RTI_ShapeType*) this);
                    }
                }

                ~ShapeType()
                {
                    #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                    FACE_DM_RTI_ShapeType_finalize(
                        (FACE_DM_RTI_ShapeType*) this);
                    #endif // !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                }

            };

            class ShapeTypeExtended: public FACE::DM::RTI::ShapeType{
              public:
                FACE::DM::RTI::ShapeFillKind::Value fillKind;
                FACE::Float angle;

                ShapeTypeExtended(FACE::Boolean initialize = true)
                {
                    if (initialize)
                    {
                        FACE_DM_RTI_ShapeTypeExtended_initialize(
                            (FACE_DM_RTI_ShapeTypeExtended*) this);
                    }
                }

                ~ShapeTypeExtended()
                {
                    #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                    FACE_DM_RTI_ShapeTypeExtended_finalize(
                        (FACE_DM_RTI_ShapeTypeExtended*) this);
                    #endif // !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                }

            };

        } /* namespace RTI  */
    } /* namespace DM  */
} /* namespace FACE  */

#endif /* ShapeType_hpp */

