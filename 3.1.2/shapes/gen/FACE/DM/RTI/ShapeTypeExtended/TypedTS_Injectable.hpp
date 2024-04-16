
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS 3.x version".
*/

#ifndef FACE_DM_RTI_ShapeTypeExtended_TypedTS_Injectable_434673847_hpp
#define FACE_DM_RTI_ShapeTypeExtended_TypedTS_Injectable_434673847_hpp

#include "../../../../ShapeType.hpp"
#include "TypedTS.hpp"

namespace FACE {
    namespace TSS {
        namespace RTI {
            namespace ShapeTypeExtended {
                namespace TypedTS_Injectable {
                    class Injectable
                    {
                        protected:
                        Injectable() {}
                      private:
                        Injectable(const Injectable&);
                        Injectable& operator=(const Injectable&);
                      public:
                        virtual ~Injectable() {}
                        virtual void Set_Reference(
                            const FACE::STRING_TYPE& interface_name,
                            FACE::TSS::RTI::ShapeTypeExtended::TypedTS **interface_reference,
                            FACE::GUID_TYPE id,
                            FACE::RETURN_CODE_TYPE::Value& return_code
                            ) = 0;
                    };
                }
            } // RTI
        } // ShapeTypeExtended
    } /* namespace TSS */
} /* namespace FACE */

#endif /* FACE_DM_RTI_ShapeTypeExtended_TypedTS_Injectable_434673847_hpp */
