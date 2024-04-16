

/*
WARNING: THIS FILE IS AUTO-GENERATED. IF MODIFIED, MOVE BEFORE RE-GENERATING.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS version".
*/

#ifndef ShapeTypeConfigInterface_434673847_hpp
#define ShapeTypeConfigInterface_434673847_hpp

#include "FACE/Configuration.hpp"
#include "RTI/TSS/Configuration.h"
#include "util/rti_tss_util.h"
#include "stdlib.h"

#ifdef RTI_CONNEXT_MICRO
#include "rti_me_c.h"
#if !EXCLUDE_UDP
#include "netio/netio_udp.h"
#endif
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"
#if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
#include "disc_dpde/disc_dpde_discovery_plugin.h"
#endif
#endif

#include "ShapeTypePlugin.h"
#include "ShapeTypeSupport.h"

extern DDS_Boolean FACE_DM_RTI_ShapeType_participant_factory_qos(DDS_DomainParticipantFactoryQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeType_participant_qos(DDS_DomainParticipantQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeType_topic_qos(DDS_TopicQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeType_publisher_qos(DDS_PublisherQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeType_subscriber_qos(DDS_SubscriberQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeType_datawriter_qos(DDS_DataWriterQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeType_datareader_qos(DDS_DataReaderQos*, void*);

extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_participant_factory_qos(DDS_DomainParticipantFactoryQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_participant_qos(DDS_DomainParticipantQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_topic_qos(DDS_TopicQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_publisher_qos(DDS_PublisherQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_subscriber_qos(DDS_SubscriberQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_datawriter_qos(DDS_DataWriterQos*, void*);
extern DDS_Boolean FACE_DM_RTI_ShapeTypeExtended_datareader_qos(DDS_DataReaderQos*, void*);

namespace RTI { namespace ShapeType {

        class Configuration: public FACE::Configuration
        {
          public:
            Configuration() : _initialized(DDS_BOOLEAN_FALSE)
            {
                /* We set all memory to zero so, in case the instance gets destroyed
                * before getting initialized, all pointers are NULL
                */
                memset(_system_configurations, 0,
                sizeof(RTI_TSS_System_Configuration_T) * _system_configurations_length);
                memset(_domain_configurations, 0,
                sizeof(RTI_TSS_DDS_DomainParticipant_Configuration_T) * _domain_configurations_length);
                memset(_type_support_configurations, 0,
                sizeof(RTI_TSS_TypeSupport_Configuration_T) * _type_support_configurations_length);
                memset(_connection_configurations, 0,
                sizeof(RTI_TSS_Connection_Configuration_T) * _connection_configurations_length);
            }

            ~Configuration()
            {
                #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                _free_system_configurations();
                _free_domain_configurations();
                _free_type_support_configurations();
                _free_connection_configurations();
                #endif
            }

            void Initialize(const FACE::Configuration::INITIALIZATION_TYPE &initialization_information,
            FACE::RETURN_CODE_TYPE::Value &return_code)
            {
                UNUSED_ARG(initialization_information);

                if (_initialized)
                {
                    return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
                    return;
                }

                #ifdef RTI_CONNEXT_MICRO

                /* OSAPI needs to be set up before it can be used. OSAPI
                should only be called once by the program otherwise undefined
                behavior may occur.*/
                if (!_set_osapi_property())
                {
                    return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                    return;
                }

                DDS_DomainParticipantFactory *factory = NULL;
                factory = DDS_DomainParticipantFactory_get_instance();
                if (factory == NULL)
                {
                    return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                    return;
                }
                /* If and only if the set up above are successfully,
                *  OSAPI can be used after this point.
                */
                #endif
                if (!_populate_system_config() ||
                !_populate_domain_config() ||
                !_populate_type_support_config() ||
                !_populate_connection_config())
                {
                    return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                    return;
                }

                _initialized = DDS_BOOLEAN_TRUE;
                return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
            }

            void Open(const FACE::Configuration::CONTAINER_NAME_TYPE &container_name,
            FACE::Configuration::HANDLE_TYPE &handle,
            FACE::RETURN_CODE_TYPE::Value &return_code)
            {
                const char *container_name_ptr = NULL;
                #ifdef FACE_SEQUENCE_AND_STRING_IMPLEMENTED
                container_name_ptr = container_name.buffer();
                #else
                container_name_ptr = container_name;
                #endif

                if (!_initialized)
                {
                    return_code = FACE::RETURN_CODE_TYPE::NOT_AVAILABLE;
                    return;
                }

                return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;

                if (strcmp(container_name_ptr,
                RTI_TSS_SYSTEM_CONFIGURATION_CONTAINER_NAME) == 0)
                {
                    handle = system_configurations_handle;
                }
                else if (strcmp(container_name_ptr,
                RTI_TSS_DOMAIN_PARTICIPANT_CONFIGURATION_CONTAINER_NAME) == 0)
                {
                    handle = domain_configurations_handle;
                }
                else if (strcmp(container_name_ptr,
                RTI_TSS_TYPE_SUPPORT_CONFIGURATION_CONTAINER_NAME) == 0)
                {
                    handle = type_support_configurations_handle;
                }
                else if (strcmp(container_name_ptr,
                RTI_TSS_CONNECTION_CONFIGURATION_CONTAINER_NAME) == 0)
                {
                    handle = connection_configurations_handle;
                }
                else
                {
                    handle = 0;
                    return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                }
            }

            void Read(FACE::Configuration::HANDLE_TYPE handle,
            const FACE::Configuration::SET_NAME_TYPE &set_name,
            FACE::SYSTEM_ADDRESS_TYPE buffer,
            FACE::Configuration::BUFFER_SIZE_TYPE buffer_size,
            FACE::Configuration::BUFFER_SIZE_TYPE &bytes_read,
            FACE::RETURN_CODE_TYPE::Value &return_code)
            {
                const char *set_name_ptr = NULL;

                UNUSED_ARG(buffer_size);

                if (buffer == NULL)
                {
                    return_code = FACE::RETURN_CODE_TYPE::INVALID_PARAM;
                    return;
                }

                if (!_initialized)
                {
                    return_code = FACE::RETURN_CODE_TYPE::NOT_AVAILABLE;
                    return;
                }

                #ifdef FACE_SEQUENCE_AND_STRING_IMPLEMENTED
                set_name_ptr = set_name.buffer();
                #else
                set_name_ptr = set_name;
                #endif

                if (handle == system_configurations_handle)
                {
                    RTI_TSS_System_Configuration_T **sys_config =
                    (RTI_TSS_System_Configuration_T**) buffer;

                    if (!_get_system_config(sys_config, set_name_ptr))
                    {
                        return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                        return;
                    }

                    bytes_read = sizeof(void*);
                }
                else if (handle == domain_configurations_handle)
                {
                    RTI_TSS_DDS_DomainParticipant_Configuration_T **domain_config =
                    (RTI_TSS_DDS_DomainParticipant_Configuration_T**) buffer;

                    if (!_get_domain_config(domain_config, set_name_ptr))
                    {
                        return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                        return;
                    }

                    bytes_read = sizeof(void*);
                }
                else if (handle == type_support_configurations_handle)
                {
                    RTI_TSS_TypeSupport_Configuration_T **type_config =
                    (RTI_TSS_TypeSupport_Configuration_T**) buffer;

                    if (!_get_type_config(type_config, set_name_ptr))
                    {
                        return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                        return;
                    }

                    bytes_read = sizeof(void*);
                }
                else if (handle == connection_configurations_handle)
                {
                    RTI_TSS_Connection_Configuration_T **connection_config =
                    (RTI_TSS_Connection_Configuration_T**) buffer;

                    if (!_get_connection_config(connection_config, set_name_ptr))
                    {
                        return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
                        return;
                    }

                    bytes_read = sizeof(void*);
                }
                else
                {
                    return_code = FACE::RETURN_CODE_TYPE::INVALID_PARAM;
                    return;
                }

                return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
            }

            void Get_Size(FACE::Configuration::HANDLE_TYPE handle,
            const FACE::Configuration::SET_NAME_TYPE &set_name,
            FACE::Configuration::BUFFER_SIZE_TYPE &size,
            FACE::RETURN_CODE_TYPE::Value &return_code)
            {
                UNUSED_ARG(handle);
                UNUSED_ARG(set_name);
                UNUSED_ARG(size);
                return_code = FACE::RETURN_CODE_TYPE::NOT_AVAILABLE;
            }

            void Seek(FACE::Configuration::HANDLE_TYPE handle,
            const FACE::Configuration::WHENCE_TYPE::Value &whence,
            FACE::Configuration::OFFSET_TYPE offset,
            FACE::RETURN_CODE_TYPE::Value &return_code)
            {
                UNUSED_ARG(handle);
                UNUSED_ARG(whence);
                UNUSED_ARG(offset);
                return_code = FACE::RETURN_CODE_TYPE::NOT_AVAILABLE;
            }

            void Close(HANDLE_TYPE handle,
            FACE::RETURN_CODE_TYPE::Value &return_code)
            {
                UNUSED_ARG(handle);
                return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
            }

            protected:
            static const FACE::Configuration::HANDLE_TYPE system_configurations_handle = 1;
            static const FACE::Configuration::HANDLE_TYPE domain_configurations_handle = 2;
            static const FACE::Configuration::HANDLE_TYPE type_support_configurations_handle = 3;
            static const FACE::Configuration::HANDLE_TYPE connection_configurations_handle = 4;

            static const FACE::UnsignedLong _system_configurations_length = 1;
            RTI_TSS_System_Configuration_T _system_configurations[_system_configurations_length];

            static const FACE::UnsignedLong _domain_configurations_length = 1;
            RTI_TSS_DDS_DomainParticipant_Configuration_T _domain_configurations[_domain_configurations_length];

            static const FACE::UnsignedLong _type_support_configurations_length = 2;
            RTI_TSS_TypeSupport_Configuration_T _type_support_configurations[_type_support_configurations_length];

            static const FACE::UnsignedLong _connection_configurations_length = 2 * 2;
            RTI_TSS_Connection_Configuration_T _connection_configurations[_connection_configurations_length];

            DDS_Boolean _initialized;

            FACE::Boolean _strcmp_uppercase(const char *left, const char *right)
            {
                char uppercase_left[256];
                char uppercase_right[256];

                RTI_TSS_Utility_string_to_upper((char *) uppercase_left, left);
                RTI_TSS_Utility_string_to_upper((char *) uppercase_right, right);

                return (strcmp(uppercase_left, uppercase_right) == 0);
            }

            FACE::Boolean _get_system_config(RTI_TSS_System_Configuration_T **cfg,
            const char *cfg_name)
            {
                if ((cfg == NULL) ||
                (*cfg != NULL) ||
                (cfg_name == NULL))
                {
                    return false;
                }

                for (FACE::UnsignedLong i = 0; i < _system_configurations_length; i++)
                {
                    if (_strcmp_uppercase(_system_configurations[i].config_name, cfg_name))
                    {
                        *cfg = &_system_configurations[i];
                        return true;
                    }
                }

                return false;
            }

            FACE::Boolean _get_domain_config(RTI_TSS_DDS_DomainParticipant_Configuration_T **cfg,
            const char *cfg_name)
            {
                if ((cfg == NULL) ||
                (*cfg != NULL) ||
                (cfg_name == NULL))
                {
                    return false;
                }

                for (FACE::UnsignedLong i = 0; i < _domain_configurations_length; i++)
                {
                    if (_strcmp_uppercase(_domain_configurations[i].config_name, cfg_name))
                    {
                        *cfg = &_domain_configurations[i];
                        return true;
                    }
                }

                return false;
            }

            FACE::Boolean _get_type_config(RTI_TSS_TypeSupport_Configuration_T **cfg,
            const char *cfg_name)
            {
                if ((cfg == NULL) ||
                (*cfg != NULL) ||
                (cfg_name == NULL))
                {
                    return false;
                }

                for (FACE::UnsignedLong i = 0; i < _type_support_configurations_length; i++)
                {
                    if (_strcmp_uppercase(_type_support_configurations[i].type_name, cfg_name))
                    {
                        *cfg = &_type_support_configurations[i];
                        return true;
                    }
                }

                return false;
            }

            FACE::Boolean _get_connection_config(RTI_TSS_Connection_Configuration_T **cfg,
            const char *cfg_name)
            {
                if ((cfg == NULL) ||
                (*cfg != NULL) ||
                (cfg_name == NULL))
                {
                    return false;
                }

                for (FACE::UnsignedLong i = 0; i < _connection_configurations_length; i++)
                {
                    if (_strcmp_uppercase(_connection_configurations[i].config_name, cfg_name))
                    {
                        *cfg = &_connection_configurations[i];
                        return true;
                    }
                }

                return false;
            }

            #ifdef RTI_CONNEXT_MICRO

            FACE::Boolean _set_osapi_property()
            {
                /* User can override this function to set the osapi properties instead of
                * creating a plugin function and pass it to the now-deprecated
                * RTI_TSS_System_Configuration.configure_osapi_system_property_fn.
                * This function does nothing by default.
                *
                * The overriding function should follow the following steps:
                * 1. Create a varaible of struct OSAPI_SystemProperty and initializes it with
                *    OSAPI_SystemProperty_INITIALIZER
                * 2. Get the current osapi properties by passing the variable to
                *    OSAPI_System_get_property function.
                * 3. Modify the OSAPI_SystemProperty variable.
                *    Notable properties:
                *    - OSAPI_SystemProperty.timer_property.thread.port_property.parent.period
                *    - OSAPI_SystemProperty.timer_property.thread.port_property.parent.time_capacity
                *    - OSAPI_SystemProperty.timer_property.thread.port_property.parent.name
                *    - OSAPI_SystemProperty.timer_property.thread.port_property.parent.deadline
                *    - OSAPI_SystemProperty.timer_property.thread.stack_size
                *    - OSAPI_SystemProperty.timer_property.thread.priority
                * 4. Pass the modified OSAPI_SystemProperty variable to OSAPI_System_set_property.
                */

                return true;
            }

            #endif

            FACE::Boolean _populate_domain_config()
            {
                if (!RTI_TSS_DDS_DomainParticipant_Configuration_initialize(&_domain_configurations[0]))
                {
                    return false;
                }
                _domain_configurations[0].config_name = "domain_0";
                _domain_configurations[0].domain_id = 0;
                _domain_configurations[0].configure_domain_participant_qos_fn = FACE_DM_RTI_ShapeTypeExtended_participant_qos;
                _domain_configurations[0].user_data = NULL;
                #ifdef RTI_CONNEXT_MICRO
                _set_discovery_config(_domain_configurations[0].discovery_config);
                #else
                _domain_configurations[0].qos_library = "FACE_DM_RTI_ShapeTypeExtended_Library";
                _domain_configurations[0].qos_profile = "FACE_DM_RTI_ShapeTypeExtended_Profile";
                #endif

                return true;
            }

            FACE::Boolean _populate_type_support_config()
            {
                /***** FACE::DM::RTI::ShapeType *****/
                if (!RTI_TSS_TypeSupport_Configuration_initialize(&_type_support_configurations[0]))
                {
                    return false;
                }
                _type_support_configurations[0].type_name = "FACE::DM::RTI::ShapeType";
                _type_support_configurations[0].register_type_fn =
                FACE_DM_RTI_ShapeTypeTypeSupport_register_type;
                /***** FACE::DM::RTI::ShapeTypeExtended *****/
                if (!RTI_TSS_TypeSupport_Configuration_initialize(&_type_support_configurations[1]))
                {
                    return false;
                }
                _type_support_configurations[1].type_name = "FACE::DM::RTI::ShapeTypeExtended";
                _type_support_configurations[1].register_type_fn =
                FACE_DM_RTI_ShapeTypeExtendedTypeSupport_register_type;

                return true;
            }

            FACE::Boolean _populate_connection_config()
            {
                /***** FACE::DM::RTI::ShapeType *****/
                if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[0]))
                {
                    return false;
                }
                _connection_configurations[0].config_name = "FACE::DM::RTI::ShapeType publisher";
                _connection_configurations[0].domain_config_name = "domain_0";
                _connection_configurations[0].direction = FACE_SOURCE;
                _connection_configurations[0].topic_name = "Example FACE::DM::RTI::ShapeType";
                _connection_configurations[0].type_name = "FACE::DM::RTI::ShapeType";
                _connection_configurations[0].configure_publisher_qos_fn = FACE_DM_RTI_ShapeType_publisher_qos;
                _connection_configurations[0].configure_topic_qos_fn = FACE_DM_RTI_ShapeType_topic_qos;
                _connection_configurations[0].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeType_datawriter_qos;
                _connection_configurations[0].configure_subscriber_qos_fn = NULL;
                _connection_configurations[0].configure_datareader_qos_fn = NULL;
                _connection_configurations[0].user_data = NULL;
                #ifndef RTI_CONNEXT_MICRO
                _connection_configurations[0].bi_dir_ignore_self = DDS_BOOLEAN_TRUE;
                _connection_configurations[0].qos_library = "FACE_DM_RTI_ShapeType_Library";
                _connection_configurations[0].qos_profile = "FACE_DM_RTI_ShapeType_Profile";
                #endif

                if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[1]))
                {
                    return false;
                }
                _connection_configurations[1].config_name = "FACE::DM::RTI::ShapeType subscriber";
                _connection_configurations[1].domain_config_name = "domain_0";
                _connection_configurations[1].direction = FACE_DESTINATION;
                _connection_configurations[1].topic_name = "Example FACE::DM::RTI::ShapeType";
                _connection_configurations[1].type_name = "FACE::DM::RTI::ShapeType";
                _connection_configurations[1].configure_topic_qos_fn = FACE_DM_RTI_ShapeType_topic_qos;
                _connection_configurations[1].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
                _connection_configurations[1].configure_datareader_qos_fn = FACE_DM_RTI_ShapeType_datareader_qos;
                _connection_configurations[1].configure_publisher_qos_fn = NULL;
                _connection_configurations[1].configure_datawriter_qos_fn = NULL;
                _connection_configurations[1].user_data = NULL;
                #ifndef RTI_CONNEXT_MICRO
                _connection_configurations[1].bi_dir_ignore_self = DDS_BOOLEAN_TRUE;
                _connection_configurations[1].qos_library = "FACE_DM_RTI_ShapeType_Library";
                _connection_configurations[1].qos_profile = "FACE_DM_RTI_ShapeType_Profile";
                #endif

                /***** FACE::DM::RTI::ShapeTypeExtended *****/
                if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[2]))
                {
                    return false;
                }
                _connection_configurations[2].config_name = "FACE::DM::RTI::ShapeTypeExtended publisher";
                _connection_configurations[2].domain_config_name = "domain_0";
                _connection_configurations[2].direction = FACE_SOURCE;
                _connection_configurations[2].topic_name = "Example FACE::DM::RTI::ShapeTypeExtended";
                _connection_configurations[2].type_name = "FACE::DM::RTI::ShapeTypeExtended";
                _connection_configurations[2].configure_publisher_qos_fn = FACE_DM_RTI_ShapeTypeExtended_publisher_qos;
                _connection_configurations[2].configure_topic_qos_fn = FACE_DM_RTI_ShapeTypeExtended_topic_qos;
                _connection_configurations[2].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeTypeExtended_datawriter_qos;
                _connection_configurations[2].configure_subscriber_qos_fn = NULL;
                _connection_configurations[2].configure_datareader_qos_fn = NULL;
                _connection_configurations[2].user_data = NULL;
                #ifndef RTI_CONNEXT_MICRO
                _connection_configurations[2].bi_dir_ignore_self = DDS_BOOLEAN_TRUE;
                _connection_configurations[2].qos_library = "FACE_DM_RTI_ShapeTypeExtended_Library";
                _connection_configurations[2].qos_profile = "FACE_DM_RTI_ShapeTypeExtended_Profile";
                #endif

                if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[3]))
                {
                    return false;
                }
                _connection_configurations[3].config_name = "FACE::DM::RTI::ShapeTypeExtended subscriber";
                _connection_configurations[3].domain_config_name = "domain_0";
                _connection_configurations[3].direction = FACE_DESTINATION;
                _connection_configurations[3].topic_name = "Example FACE::DM::RTI::ShapeTypeExtended";
                _connection_configurations[3].type_name = "FACE::DM::RTI::ShapeTypeExtended";
                _connection_configurations[3].configure_topic_qos_fn = FACE_DM_RTI_ShapeTypeExtended_topic_qos;
                _connection_configurations[3].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeTypeExtended_subscriber_qos;
                _connection_configurations[3].configure_datareader_qos_fn = FACE_DM_RTI_ShapeTypeExtended_datareader_qos;
                _connection_configurations[3].configure_publisher_qos_fn = NULL;
                _connection_configurations[3].configure_datawriter_qos_fn = NULL;
                _connection_configurations[3].user_data = NULL;
                #ifndef RTI_CONNEXT_MICRO
                _connection_configurations[3].bi_dir_ignore_self = DDS_BOOLEAN_TRUE;
                _connection_configurations[3].qos_library = "FACE_DM_RTI_ShapeTypeExtended_Library";
                _connection_configurations[3].qos_profile = "FACE_DM_RTI_ShapeTypeExtended_Profile";
                #endif

                return true;
            }

            FACE::Boolean _populate_system_config()
            {
                if (!RTI_TSS_System_Configuration_initialize(&_system_configurations[0]))
                {
                    return false;
                }
                _system_configurations[0].config_name = "ShapeType";
                _system_configurations[0].configure_domain_participant_factory_qos_fn = FACE_DM_RTI_ShapeTypeExtended_participant_factory_qos;
                #ifndef RTI_CONNEXT_MICRO
                /* Uncomment the following line to load QoS settings from a different file than
                * USER_QOS_PROFILES.xml or the file pointed by the NDDS_QOS_PROFILES environment variable
                */
                /* _system_configurations[0].xml_qos_file = "ShapeType_Qos.xml"; */
                #else
                _system_configurations[0].max_connections = 32;
                _system_configurations[0].max_topics = _connection_configurations_length / 2;

                #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER && !EXCLUDE_UDP
                _system_configurations[0].components_length = 5;
                int i = 3;
                #elif !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER || !EXCLUDE_UDP
                _system_configurations[0].components_length = 4;
                int i = 3;
                #else
                _system_configurations[0].components_length = 3;
                #endif

                _system_configurations[0].components =
                new RTI_TSS_Micro_Component_T[_system_configurations[0].components_length];

                // Writer History Component
                if (!RTI_TSS_Micro_Component_initialize(&_system_configurations[0].components[0]))
                {
                    return false;
                }
                _system_configurations[0].components[0].name = DDSHST_WRITER_DEFAULT_HISTORY_NAME;
                _system_configurations[0].components[0].component = WHSM_HistoryFactory_get_interface();
                _system_configurations[0].components[0].listener = NULL;
                _system_configurations[0].components[0].property = NULL;

                // Reader History Component
                if (!RTI_TSS_Micro_Component_initialize(&_system_configurations[0].components[1]))
                {
                    return false;
                }
                _system_configurations[0].components[1].name = DDSHST_READER_DEFAULT_HISTORY_NAME;
                _system_configurations[0].components[1].component = RHSM_HistoryFactory_get_interface();
                _system_configurations[0].components[1].listener = NULL;
                _system_configurations[0].components[1].property = NULL;

                // DPSE Component
                struct DPSE_DiscoveryPluginProperty *dpse_properties =
                (struct DPSE_DiscoveryPluginProperty*) malloc(
                    sizeof(struct DPSE_DiscoveryPluginProperty));

                if (DPSE_DiscoveryPluginProperty_initialize(dpse_properties) != DDS_RETCODE_OK)
                {
                    printf("Failed to Initialize DPSE properties");
                    return false;
                }

                if (!RTI_TSS_Micro_Component_initialize(&_system_configurations[0].components[2]))
                {
                    return false;
                }
                _system_configurations[0].components[2].name = "dpse";
                _system_configurations[0].components[2].component = DPSE_DiscoveryFactory_get_interface();
                _system_configurations[0].components[2].listener = NULL;
                _system_configurations[0].components[2].property =
                (struct RT_ComponentFactoryProperty*) dpse_properties;
                #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                // DPDE Component
                struct DPDE_DiscoveryPluginProperty *dpde_properties =
                (struct DPDE_DiscoveryPluginProperty*) malloc(
                    sizeof(struct DPDE_DiscoveryPluginProperty));

                if (DPDE_DiscoveryPluginProperty_initialize(dpde_properties) != DDS_RETCODE_OK)
                {
                    printf("Failed to Initialize DPDE properties");
                    return false;
                }

                if (!RTI_TSS_Micro_Component_initialize(&_system_configurations[0].components[i]))
                {
                    return false;
                }
                _system_configurations[0].components[i].name = "dpde";
                _system_configurations[0].components[i].component = DPDE_DiscoveryFactory_get_interface();
                _system_configurations[0].components[i].listener = NULL;
                _system_configurations[0].components[i].property =
                (struct RT_ComponentFactoryProperty*) dpde_properties;
                i++;
                #endif /* !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER */

                #if !EXCLUDE_UDP

                // UDP Component
                if (!RTI_TSS_Micro_Component_initialize(&_system_configurations[0].components[i]))
                {
                    return false;
                }
                _system_configurations[0].components[i].name = NETIO_DEFAULT_UDP_NAME;
                _system_configurations[0].components[i].component = UDP_InterfaceFactory_get_interface();
                _system_configurations[0].components[i].listener = NULL;
                _system_configurations[0].components[i].property =
                (struct RT_ComponentFactoryProperty*) _new_udp_property();
                #endif /* !EXCLUDE_UDP */
                #endif /* RTI_CONNEXT_MICRO */

                return true;
            }

            #ifdef RTI_CONNEXT_MICRO
            #if !EXCLUDE_UDP
            struct UDP_InterfaceFactoryProperty *_new_udp_property()
            {
                struct UDP_InterfaceFactoryProperty *udp_property =
                (struct UDP_InterfaceFactoryProperty *) malloc(
                    sizeof(struct UDP_InterfaceFactoryProperty));
                memset(udp_property, 0, sizeof(struct UDP_InterfaceFactoryProperty));
                *udp_property = UDP_INTERFACE_FACTORY_PROPERTY_DEFAULT;

                #if FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
                REDA_StringSeq_set_maximum(&udp_property->allow_interface,1);
                REDA_StringSeq_set_length(&udp_property->allow_interface,1);

                /* The name of the interface can be the anything, up to
                * UDP_INTERFACE_MAX_IFNAME characters including the '\0' character
                */
                if (DDS_StringSeq_get_reference(&udp_property->allow_interface,0) != NULL)
                {
                    *DDS_StringSeq_get_reference(&udp_property->allow_interface,0) =
                    DDS_String_dup("loopback");
                }

                /* This function takes the following arguments:
                * Param 1 is the iftable in the UDP property
                * Param 2 is the IP address of the interface in host order
                * Param 3 is the Netmask of the interface
                * Param 4 is the name of the interface
                * Param 5 are flags. The following flags are supported for Security and
                *    Safety Base (use OR for multiple):
                    *        UDP_INTERFACE_INTERFACE_UP_FLAG - Interface is up
                    *
                    *    The following flags are supported for non-Security and non-Safety
                    *    Base:
                    *        UDP_INTERFACE_INTERFACE_MULTICAST_FLAG - Interface supports multicast
                    */
                    if (!UDP_InterfaceTable_add_entry(&udp_property->if_table,
                    0x7f000001,0xff000000,"loopback",
                    UDP_INTERFACE_INTERFACE_UP_FLAG))
                    {
                        printf("Failed UDP table add entry!\n");
                        return NULL;
                }
                #else
                /* For additional allowed interface(s), increase maximum and length, and
                * set interface below.
                */
                REDA_StringSeq_set_maximum(&udp_property->allow_interface,2);
                REDA_StringSeq_set_length(&udp_property->allow_interface,2);

                /* loopback interface */
                if ((REDA_StringSeq_get_reference(&udp_property->allow_interface,0) != NULL) &&
                (REDA_StringSeq_get_reference(&udp_property->allow_interface,1) != NULL))
                {
                    #if defined (RTI_LINUX)
                    printf("Enable interfaces\n");
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,0) = DDS_String_dup("lo");
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,1) = DDS_String_dup("enp0s10");
                    #elif defined (RTI_VXWORKS)
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,0) = DDS_String_dup("lo0");
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,1) = DDS_String_dup("geisc0");
                    #elif defined (RTI_DARWIN)
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,0) = DDS_String_dup("lo0");
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,1) = DDS_String_dup("en0");
                    #elif defined(RTI_WIN32)
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,0) = DDS_String_dup("Loopback Pseudo-Interface 1");
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,1) = DDS_String_dup("Local Area Connection");
                    #else
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,0) = DDS_String_dup("lo");
                    *REDA_StringSeq_get_reference(&udp_property->allow_interface,1) = DDS_String_dup("ce0");
                    #endif
                }

                #endif /* FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER */

                return udp_property;
            }
            #endif /*  !EXCLUDE_UDP */
            void _set_discovery_config(struct RTI_TSS_DiscoveryConfigPlugin &cfg)
            {
                /* This configuration will be used by those participants using DPSE */

                RTI_TSS_RemoteParticipantEntry_T *current_par_entry = NULL;
                RTI_TSS_RemoteSubscriptionEntry_T *current_sub_entry = NULL;
                RTI_TSS_RemotePublicationEntry_T *current_pub_entry = NULL;
                struct DDS_SubscriptionBuiltinTopicData rem_subscription_data =
                DDS_SubscriptionBuiltinTopicData_INITIALIZER;
                struct DDS_PublicationBuiltinTopicData rem_publication_data =
                DDS_PublicationBuiltinTopicData_INITIALIZER;

                RTI_TSS_DiscoveryConfigPlugin_initialize(&cfg);

                cfg.dpse_component_name = "dpse";

                /* The amount of remote participant_entries that will be asserted */
                cfg.length = 1;
                cfg.participant_entries = (RTI_TSS_RemoteParticipantEntry_T *)
                malloc(sizeof(RTI_TSS_RemoteParticipantEntry_T) * cfg.length);
                memset(cfg.participant_entries, 0, sizeof(RTI_TSS_RemoteParticipantEntry_T));

                cfg.participant_entries[0].participant_name = "RTI FACE Example";

                current_par_entry = &cfg.participant_entries[0];

                /* Configure remote subscribers and publishers */
                current_par_entry->sub_length = 2;
                current_par_entry->subscription_entries = (RTI_TSS_RemoteSubscriptionEntry_T *)
                malloc(sizeof(RTI_TSS_RemoteSubscriptionEntry_T) * current_par_entry->sub_length);
                memset(current_par_entry->subscription_entries, 0, sizeof(RTI_TSS_RemoteSubscriptionEntry_T) * current_par_entry->sub_length);

                current_par_entry->pub_length = 2;
                current_par_entry->publication_entries = (RTI_TSS_RemotePublicationEntry_T *)
                malloc( sizeof(RTI_TSS_RemotePublicationEntry_T) * current_par_entry->pub_length);
                memset(current_par_entry->publication_entries, 0, sizeof(RTI_TSS_RemotePublicationEntry_T) * current_par_entry->pub_length);

                rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 200;
                rem_subscription_data.topic_name = DDS_String_dup("Example FACE::DM::RTI::ShapeType");
                rem_subscription_data.type_name = DDS_String_dup("FACE::DM::RTI::ShapeType");
                rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;

                current_sub_entry = &current_par_entry->subscription_entries[0];
                current_sub_entry->data = rem_subscription_data;
                current_sub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                    FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);

                rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 100;
                rem_publication_data.topic_name = DDS_String_dup("Example FACE::DM::RTI::ShapeType");
                rem_publication_data.type_name = DDS_String_dup("FACE::DM::RTI::ShapeType");
                rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;

                current_pub_entry = &current_par_entry->publication_entries[0];
                current_pub_entry->data = rem_publication_data;
                current_pub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                    FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);
                rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 201;
                rem_subscription_data.topic_name = DDS_String_dup("Example FACE::DM::RTI::ShapeTypeExtended");
                rem_subscription_data.type_name = DDS_String_dup("FACE::DM::RTI::ShapeTypeExtended");
                rem_subscription_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;

                current_sub_entry = &current_par_entry->subscription_entries[1];
                current_sub_entry->data = rem_subscription_data;
                current_sub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                    FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);

                rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 101;
                rem_publication_data.topic_name = DDS_String_dup("Example FACE::DM::RTI::ShapeTypeExtended");
                rem_publication_data.type_name = DDS_String_dup("FACE::DM::RTI::ShapeTypeExtended");
                rem_publication_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;

                current_pub_entry = &current_par_entry->publication_entries[1];
                current_pub_entry->data = rem_publication_data;
                current_pub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                    FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);
            }
            #endif // RTI_CONNEXT_MICRO

            #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
            void _free_system_configurations()
            {
                for (FACE::UnsignedLong i = 0; i < _system_configurations_length; i++)
                {
                    _system_configurations[i].config_name = NULL;

                    #ifndef RTI_CONNEXT_MICRO
                    _system_configurations[i].xml_qos_file = NULL;

                    _system_configurations[i].qos_library = NULL;

                    _system_configurations[i].qos_profile = NULL;
                    #else
                    // Free Micro components
                    if (_system_configurations[i].components != NULL)
                    {
                        for (FACE::UnsignedLong j = 0; j < _system_configurations[i].components_length; j++)
                        {
                            _system_configurations[i].components[j].component = NULL;

                            if (_system_configurations[i].components[j].listener != NULL)
                            {
                                RTI_TSS_FREE(_system_configurations[i].components[j].listener);
                                _system_configurations[i].components[j].listener = NULL;
                            }

                            if (_system_configurations[i].components[j].property != NULL)
                            {
                                // If compiled with EXCLUDE_UDP,
                                // TSS will delete the UDP property
                                #if !EXCLUDE_UDP
                                if (strcmp(_system_configurations[i].components[j].name,
                                NETIO_DEFAULT_UDP_NAME) == 0)
                                {
                                    UDP_InterfaceFactoryProperty_finalize(
                                        (struct UDP_InterfaceFactoryProperty*)
                                        _system_configurations[i].components[j].property);
                                }
                                #endif
                                RTI_TSS_FREE(_system_configurations[i].components[j].property);
                                _system_configurations[i].components[j].property = NULL;
                            }

                            _system_configurations[i].components[j].name = NULL;
                        }

                        delete[] _system_configurations[i].components;
                        _system_configurations[i].components = NULL;
                    }
                    #endif // RTI_CONNEXT_MICRO
                }
            }

            void _free_domain_configurations()
            {
                for (FACE::UnsignedLong i = 0; i < _domain_configurations_length; i++)
                {
                    _domain_configurations[i].config_name = NULL;

                    #ifndef RTI_CONNEXT_MICRO
                    _domain_configurations[i].qos_library = NULL;

                    _domain_configurations[i].qos_profile = NULL;
                    #else
                    // Free discovery config
                    if (_domain_configurations[i].discovery_config.participant_entries != NULL)
                    {
                        for (FACE::UnsignedLong j = 0; j < _domain_configurations[i].discovery_config.length; j++)
                        {
                            RTI_TSS_RemoteParticipantEntry_T *current_par_entry =
                            &_domain_configurations[i].discovery_config.participant_entries[j];

                            if (current_par_entry->subscription_entries != NULL)
                            {
                                for (FACE::UnsignedLong k = 0; k < current_par_entry->sub_length; ++k)
                                {
                                    (void) DDS_SubscriptionBuiltinTopicData_finalize(
                                        &current_par_entry->subscription_entries[k].data);
                                }

                                RTI_TSS_FREE(current_par_entry->subscription_entries);
                                current_par_entry->subscription_entries = NULL;
                            }

                            if (current_par_entry->publication_entries != NULL)
                            {
                                for (FACE::UnsignedLong k = 0; k < current_par_entry->pub_length; ++k)
                                {
                                    (void) DDS_PublicationBuiltinTopicData_finalize(
                                        &current_par_entry->publication_entries[k].data);
                                }

                                RTI_TSS_FREE(current_par_entry->publication_entries);
                                current_par_entry->publication_entries = NULL;
                            }

                            current_par_entry->participant_name = NULL;
                        }

                        RTI_TSS_FREE(_domain_configurations[i].discovery_config.participant_entries);
                        _domain_configurations[i].discovery_config.participant_entries = NULL;
                    }

                    _domain_configurations[i].discovery_config.dpse_component_name = NULL;
                    #endif
                }
            }

            void _free_type_support_configurations()
            {
                for (FACE::UnsignedLong i = 0; i < _type_support_configurations_length; i++)
                {
                    _type_support_configurations[i].type_name = NULL;
                }
            }

            void _free_connection_configurations()
            {
                for (FACE::UnsignedLong i = 0; i < _connection_configurations_length; i++)
                {
                    _connection_configurations[i].config_name = NULL;

                    _connection_configurations[i].domain_config_name = NULL;

                    _connection_configurations[i].topic_name = NULL;

                    _connection_configurations[i].type_name = NULL;

                    #ifndef RTI_CONNEXT_MICRO
                    _connection_configurations[i].qos_library = NULL;

                    _connection_configurations[i].qos_profile = NULL;
                    #endif
                }
            }
            #endif
        };

    } /* namespace RTI */ } /* namespace ShapeType */

#endif /* ShapeTypeConfigInterface_hpp */
