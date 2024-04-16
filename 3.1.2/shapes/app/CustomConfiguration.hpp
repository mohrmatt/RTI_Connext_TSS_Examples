
/*******************************************************************************
 *  Copyright (c) 2018-2021 Real-Time Innovations, Inc.  All rights reserved.
 *
 *  No duplications, whole or partial, manual or electronic, may be made
 *  without express written permission.  Any such copies, or revisions thereof,
 *  must display this notice unaltered.
 *  This code contains trade secrets of Real-Time Innovations, Inc.
 *******************************************************************************/

#ifndef CUSTOM_CONFIGURATION_HPP
#define CUSTOM_CONFIGURATION_HPP

#include "gen/ShapeType_TSSConfigInterface.hpp"

/** CustomConfiguration is an extension of the generated Configuration.
 * This allows customization of the configuration without creating an entirely
 * new config.
 * */
class CustomConfiguration : public FACE::Configuration
{
  public:
    CustomConfiguration(FACE::Long domain_id) : _domain_id(domain_id)
    {
        _initialized = DDS_BOOLEAN_FALSE;
    }

    void Initialize(
            const FACE::Configuration::INITIALIZATION_TYPE
                    &initialization_information,
            FACE::RETURN_CODE_TYPE::Value &return_code)
    {
        UNUSED_ARG(initialization_information);

        if (_initialized)
        {
            return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
            return;
        }

        if (!_populate_custom_system_config() ||
            !_populate_custom_domain_config() ||
            !_populate_type_support_config() ||
            !_populate_custom_connection_config())
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

        if (strcmp(container_name_ptr, RTI_TSS_SYSTEM_CONFIGURATION_CONTAINER_NAME) == 0) {
            handle = system_configurations_handle;
        }
        else if (strcmp(container_name_ptr, RTI_TSS_DOMAIN_PARTICIPANT_CONFIGURATION_CONTAINER_NAME) == 0) {
            handle = domain_configurations_handle;
        }
        else if (strcmp(container_name_ptr, RTI_TSS_TYPE_SUPPORT_CONFIGURATION_CONTAINER_NAME) == 0) {
            handle = type_support_configurations_handle;
        }
        else if (strcmp(container_name_ptr, RTI_TSS_CONNECTION_CONFIGURATION_CONTAINER_NAME) == 0) {
            handle = connection_configurations_handle;
        }
        else {
            handle = 0;
            return_code = FACE::RETURN_CODE_TYPE::INVALID_CONFIG;
        }
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
            RTI_TSS_System_Configuration_T **sys_config = (RTI_TSS_System_Configuration_T**) buffer;

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

    void Close(HANDLE_TYPE handle, FACE::RETURN_CODE_TYPE::Value &return_code)
    {
        UNUSED_ARG(handle);

        return_code = FACE::RETURN_CODE_TYPE::NO_ERROR;
    }

  protected:
      /*
       * These handle values are identifiers, they should be unique!
       */
      static const FACE::Configuration::HANDLE_TYPE system_configurations_handle = 1;
      static const FACE::Configuration::HANDLE_TYPE domain_configurations_handle = 2;
      static const FACE::Configuration::HANDLE_TYPE type_support_configurations_handle = 3;
      static const FACE::Configuration::HANDLE_TYPE connection_configurations_handle = 4;

      static const FACE::UnsignedLong _system_configurations_length = 1;
      RTI_TSS_System_Configuration_T _system_configurations[_system_configurations_length];

      static const FACE::UnsignedLong _domain_configurations_length = 2;
      RTI_TSS_DDS_DomainParticipant_Configuration_T _domain_configurations[_domain_configurations_length];

      static const FACE::UnsignedLong _type_support_configurations_length = 2;
      RTI_TSS_TypeSupport_Configuration_T _type_support_configurations[_type_support_configurations_length];

      static const FACE::UnsignedLong _connection_configurations_length = 7;
      RTI_TSS_Connection_Configuration_T _connection_configurations[_connection_configurations_length];

      FACE::Boolean _strcmp_uppercase(const char *left, const char *right)
      {
          char uppercase_left[256];
          char uppercase_right[256];

          RTI_TSS_Utility_string_to_upper((char *) uppercase_left, left);
          RTI_TSS_Utility_string_to_upper((char *) uppercase_right, right);

          return (strcmp(uppercase_left, uppercase_right) == 0);
      }

      FACE::Boolean _get_system_config(RTI_TSS_System_Configuration_T **cfg, const char *cfg_name)
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

      FACE::Boolean _get_domain_config(RTI_TSS_DDS_DomainParticipant_Configuration_T **cfg, const char *cfg_name)
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

      FACE::Boolean _get_type_config(RTI_TSS_TypeSupport_Configuration_T **cfg, const char *cfg_name)
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

      FACE::Boolean _get_connection_config(RTI_TSS_Connection_Configuration_T **cfg, const char *cfg_name)
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

  private:
    /** We write a custom function to populate the domain configurations to use
     * the Domain ID that was provided to the constructor.
     * */
    FACE::Boolean _populate_custom_domain_config()
    {
        if (!RTI_TSS_DDS_DomainParticipant_Configuration_initialize(&_domain_configurations[0]))
        {
            return false;
        }

	/*
	 * The config name is referenced in the connection config.
	 */
        _domain_configurations[0].config_name = "SHAPES_DEMO";
        _domain_configurations[0].domain_id = _domain_id;
        _domain_configurations[0].configure_domain_participant_qos_fn =
                FACE_DM_RTI_ShapeType_participant_qos;
        _domain_configurations[0].user_data = NULL;
#ifdef RTI_CONNEXT_MICRO
        _set_discovery_config(_domain_configurations[0].discovery_config);
#else
        _domain_configurations[0].qos_library =
                "FACE_DM_RTI_ShapeType_Library";
        _domain_configurations[0].qos_profile =
                "Default_Profile";
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

        _type_support_configurations[0].type_name = "ShapeType";
        _type_support_configurations[0].register_type_fn =
        FACE_DM_RTI_ShapeTypeTypeSupport_register_type;

        /***** FACE::DM::RTI::ShapeTypeExtended *****/
        if (!RTI_TSS_TypeSupport_Configuration_initialize(&_type_support_configurations[1]))
        {
            return false;
        }

        _type_support_configurations[1].type_name = "ShapeTypeExtended";
        _type_support_configurations[1].register_type_fn =
        FACE_DM_RTI_ShapeTypeExtendedTypeSupport_register_type;

        return true;
    }


    /* 
     * We can also change any parameters in the connection config.
     * */
    FACE::Boolean _populate_custom_connection_config()
    {
        /***** ShapeType Publisher Circle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[0]))
        {
            return false;
        }
        _connection_configurations[0].config_name                 = "ShapeType publisher";
        _connection_configurations[0].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[0].direction                   = FACE_SOURCE;
        _connection_configurations[0].topic_name                  = "Circle";
        _connection_configurations[0].type_name                   = "ShapeType";
        _connection_configurations[0].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[0].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[0].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeType_datawriter_qos;
        _connection_configurations[0].configure_subscriber_qos_fn = NULL;
        _connection_configurations[0].configure_datareader_qos_fn = NULL;
        _connection_configurations[0].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[0].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[0].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[0].qos_profile                 = "Default_Profile";
#endif
        
	/***** ShapeType Subscriber Square *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[1]))
        {
            return false;
        }
        _connection_configurations[1].config_name                 = "ShapeType subscriber";
        _connection_configurations[1].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[1].direction                   = FACE_DESTINATION;
        _connection_configurations[1].topic_name                  = "Square";
        _connection_configurations[1].type_name                   = "ShapeType";
        _connection_configurations[1].configure_publisher_qos_fn  = NULL;
        _connection_configurations[1].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[1].configure_datawriter_qos_fn = NULL;
        _connection_configurations[1].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[1].configure_datareader_qos_fn = FACE_DM_RTI_ShapeType_datareader_qos;
        _connection_configurations[1].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[1].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[1].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[1].qos_profile                 = "Default_Profile";
#endif


	/***** ShapeTypeExtended Publisher Triangle Default QOS *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[2]))
        {
            return false;
        }
        _connection_configurations[2].config_name                 = "ShapeTypeExtended publisher1";
        _connection_configurations[2].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[2].direction                   = FACE_SOURCE;
        _connection_configurations[2].topic_name                  = "Triangle";
        _connection_configurations[2].type_name                   = "ShapeTypeExtended";
        _connection_configurations[2].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[2].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[2].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeType_datawriter_qos;
        _connection_configurations[2].configure_subscriber_qos_fn = NULL;
        _connection_configurations[2].configure_datareader_qos_fn = NULL;
        _connection_configurations[2].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[2].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[2].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[2].qos_profile                 = "Default_Profile";
#endif

	/***** ShapeTypeExtended Subscriber Square *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[3]))
        {
            return false;
        }
        _connection_configurations[3].config_name                 = "ShapeTypeExtended subscriber";
        _connection_configurations[3].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[3].direction                   = FACE_DESTINATION;
        _connection_configurations[3].topic_name                  = "Triangle";
        _connection_configurations[3].type_name                   = "ShapeTypeExtended";
        _connection_configurations[3].configure_publisher_qos_fn  = NULL;
        _connection_configurations[3].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[3].configure_datawriter_qos_fn = NULL;
        _connection_configurations[3].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[3].configure_datareader_qos_fn = FACE_DM_RTI_ShapeType_datareader_qos;
        _connection_configurations[3].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[3].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[3].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[3].qos_profile                 = "Default_Profile";
#endif

	/***** ShapeTypeExtended Publisher Triangle Late Joiners *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[4]))
        {
            return false;
        }
        _connection_configurations[4].config_name                 = "ShapeTypeExtended publisher2";
        _connection_configurations[4].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[4].direction                   = FACE_SOURCE;
        _connection_configurations[4].topic_name                  = "Triangle";
        _connection_configurations[4].type_name                   = "ShapeTypeExtended";
        _connection_configurations[4].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[4].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[4].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeType_datawriter_qos;
        _connection_configurations[4].configure_subscriber_qos_fn = NULL;
        _connection_configurations[4].configure_datareader_qos_fn = NULL;
        _connection_configurations[4].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[4].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[4].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[4].qos_profile                 = "Late_Joiners_Demo";
#endif

	/***** ShapeTypeExtended Publisher Circle Ownership1 *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[5]))
        {
            return false;
        }
        _connection_configurations[5].config_name                 = "ShapeTypeExtended publisher3";
        _connection_configurations[5].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[5].direction                   = FACE_SOURCE;
        _connection_configurations[5].topic_name                  = "Circle";
        _connection_configurations[5].type_name                   = "ShapeTypeExtended";
        _connection_configurations[5].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[5].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[5].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeType_datawriter_qos;
        _connection_configurations[5].configure_subscriber_qos_fn = NULL;
        _connection_configurations[5].configure_datareader_qos_fn = NULL;
        _connection_configurations[5].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[5].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[5].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[5].qos_profile                 = "Ownership_Demo1";
#endif

        /***** ShapeTypeExtended Publisher Circle Ownership2 *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[6]))
        {
            return false;
        }
        _connection_configurations[6].config_name                 = "ShapeTypeExtended publisher4";
        _connection_configurations[6].domain_config_name          = "SHAPES_DEMO";
        _connection_configurations[6].direction                   = FACE_SOURCE;
        _connection_configurations[6].topic_name                  = "Circle";
        _connection_configurations[6].type_name                   = "ShapeTypeExtended";
        _connection_configurations[6].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[6].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[6].configure_datawriter_qos_fn = FACE_DM_RTI_ShapeType_datawriter_qos;
        _connection_configurations[6].configure_subscriber_qos_fn = NULL;
        _connection_configurations[6].configure_datareader_qos_fn = NULL;
        _connection_configurations[6].user_data                   = NULL;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[6].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[6].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[6].qos_profile                 = "Ownership_Demo2";
#endif

        return true;
    }

    /** We have updated the system config population to use the
     * HelloGoodbye_Qos.xml file to specify QoS by default when building against
     * pro
     * */
    FACE::Boolean _populate_custom_system_config()
    {
        if (!RTI_TSS_System_Configuration_initialize(
                    &_system_configurations[0]))
        {
            return false;
        }
        _system_configurations[0].config_name = "Shapes";
        _system_configurations[0].configure_domain_participant_factory_qos_fn =
                FACE_DM_RTI_ShapeType_participant_factory_qos;
#ifndef RTI_CONNEXT_MICRO
        /* Use the HelloGoodbye_Qos.xml file for QoS */
        _system_configurations[0].xml_qos_file = "ShapeType_Qos.xml";
#else
        _system_configurations[0].max_connections = 32;
        _system_configurations[0].max_topics = 3
                

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
                new RTI_TSS_Micro_Component_T[_system_configurations[0]
                                                      .components_length];

        // Writer History Component
        if (!RTI_TSS_Micro_Component_initialize(
                    &_system_configurations[0].components[0]))
        {
            return false;
        }
        _system_configurations[0].components[0].name =
                DDSHST_WRITER_DEFAULT_HISTORY_NAME;
        _system_configurations[0].components[0].component =
                WHSM_HistoryFactory_get_interface();
        _system_configurations[0].components[0].listener = NULL;
        _system_configurations[0].components[0].property = NULL;

        // Reader History Component
        if (!RTI_TSS_Micro_Component_initialize(
                    &_system_configurations[0].components[1]))
        {
            return false;
        }
        _system_configurations[0].components[1].name =
                DDSHST_READER_DEFAULT_HISTORY_NAME;
        _system_configurations[0].components[1].component =
                RHSM_HistoryFactory_get_interface();
        _system_configurations[0].components[1].listener = NULL;
        _system_configurations[0].components[1].property = NULL;

        // DPSE Component
        struct DPSE_DiscoveryPluginProperty *dpse_properties =
                (struct DPSE_DiscoveryPluginProperty *)malloc(
                        sizeof(struct DPSE_DiscoveryPluginProperty));

        if (DPSE_DiscoveryPluginProperty_initialize(dpse_properties) !=
            DDS_RETCODE_OK)
        {
            printf("Failed to Initialize DPSE properties");
            return false;
        }

        if (!RTI_TSS_Micro_Component_initialize(
                    &_system_configurations[0].components[2]))
        {
            return false;
        }
        _system_configurations[0].components[2].name = "dpse";
        _system_configurations[0].components[2].component =
                DPSE_DiscoveryFactory_get_interface();
        _system_configurations[0].components[2].listener = NULL;
        _system_configurations[0].components[2].property =
                (struct RT_ComponentFactoryProperty *)dpse_properties;

#if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
        // DPDE Component
        struct DPDE_DiscoveryPluginProperty *dpde_properties =
                (struct DPDE_DiscoveryPluginProperty *)malloc(
                        sizeof(struct DPDE_DiscoveryPluginProperty));

        if (DPDE_DiscoveryPluginProperty_initialize(dpde_properties) !=
            DDS_RETCODE_OK)
        {
            printf("Failed to Initialize DPDE properties");
            return false;
        }

        if (!RTI_TSS_Micro_Component_initialize(
                    &_system_configurations[0].components[i]))
        {
            return false;
        }
        _system_configurations[0].components[i].name = "dpde";
        _system_configurations[0].components[i].component =
                DPDE_DiscoveryFactory_get_interface();
        _system_configurations[0].components[i].listener = NULL;
        _system_configurations[0].components[i].property =
                (struct RT_ComponentFactoryProperty *)dpde_properties;
        i++;
#endif /* !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER */

#if !EXCLUDE_UDP

        // UDP Component
        if (!RTI_TSS_Micro_Component_initialize(
                    &_system_configurations[0].components[i]))
        {
            return false;
        }
        _system_configurations[0].components[i].name = NETIO_DEFAULT_UDP_NAME;
        _system_configurations[0].components[i].component =
                UDP_InterfaceFactory_get_interface();
        _system_configurations[0].components[i].listener = NULL;
        _system_configurations[0].components[i].property =
                (struct RT_ComponentFactoryProperty *)_new_udp_property();
#endif /* !EXCLUDE_UDP */

#endif /* RTI_CONNEXT_MICRO */

        return true;
    }

    int _domain_id;

    DDS_Boolean _initialized;
};

#endif // CUSTOM_CONFIGURATION_HPP
