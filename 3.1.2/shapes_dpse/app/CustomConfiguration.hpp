
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

/* Function to configure the network interfaces */
struct UDP_InterfaceFactoryProperty *custom_new_udp_property()
{

  struct UDP_InterfaceFactoryProperty *udp_property =
      (struct UDP_InterfaceFactoryProperty *)malloc(sizeof(struct UDP_InterfaceFactoryProperty));
  memset(udp_property, 0, sizeof(struct UDP_InterfaceFactoryProperty));
  *udp_property = UDP_INTERFACE_FACTORY_PROPERTY_DEFAULT;

  udp_property->is_default_interface = RTI_TRUE;

  /* The number of interfaces can be > 1 if more than one are available to use */
  REDA_StringSeq_set_maximum(&udp_property->allow_interface, 1);
  REDA_StringSeq_set_length(&udp_property->allow_interface, 1);

  /* Since the interfaces are being configured manually, the interface name can be arbitrary.  The
     only requirement is that it matches one of the interfaces referenced by add_entry, below. */
  if (DDS_StringSeq_get_reference(&udp_property->allow_interface, 0) != NULL)
  {
    *DDS_StringSeq_get_reference(&udp_property->allow_interface, 0) = DDS_String_dup("loopback");
  }

  if (!UDP_InterfaceTable_add_entry(&udp_property->if_table,
             0x7f000001, 0xff000000, "loopback",
             UDP_INTERFACE_INTERFACE_UP_FLAG))
  {
    printf("Failed UDP table add entry!\n");
    return NULL;
  }

  return udp_property;
}

void _set_discovery_config_pub(struct RTI_TSS_DiscoveryConfigPlugin &cfg)
{
    /*
     * This configuration will be used by those participants using DPSE.
     * Declare structures which hold the remote participant and subscriber static
     * discovery information.  If the remote participant(s) had publishers, a
     * RemotePublicationEntry would aslo be required.  Note that the macro
     * DDS_SubscriptionBuiltinTopicData_INITIALIZER performs memory allocations and
     * therefore should only be used once to avoid memory leaks.  Since this is a
     * FACE Safety-Base application, there isn't an API available to free/finalize
     * those allocated resources.
     */

    RTI_TSS_RemoteParticipantEntry_T *current_par_entry = NULL;
    RTI_TSS_RemoteSubscriptionEntry_T *current_sub_entry = NULL;
    // RTI_TSS_RemotePublicationEntry_T *current_pub_entry = NULL; /* Unused */

    struct DDS_SubscriptionBuiltinTopicData rem_subscription_data =
               DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    // struct DDS_PublicationBuiltinTopicData rem_publication_data =
               // DDS_PublicationBuiltinTopicData_INITIALIZER; /* Unused */

    /*
     * Initialize the DiscoveryConfigPlugin configuration that was passed into this
     * function. The component_name will always be "dpse" in this case.
     */
    RTI_TSS_DiscoveryConfigPlugin_initialize(&cfg);
    cfg.dpse_component_name = "dpse";

    /*
     * The goal of this example is to highlight common customer use cases.
     * In the first domain id, this example will have a single publisher
     * and two subscriber to the same topic.
     */

    /*
     * Set the number of remote participant_entries that will be asserted.
     * Only one is used by this example.  Allocated and initialize the memory to hold the
     * remote participant entry data.
     *
     * Important to note, that when using DPSE participant names need to be unique for standalone
     * applications. Therefore, for this example, the publisher applicaiton, and two subscribing
     * applications are all unique. Below, we're setting the number of REMOTE participant length,
     * which does not include self. In this case, since the application can act as the publisher or
     * subscriber, we include all three participant names.
     *
     * The participant names are defined in the participant qos.
     */
    cfg.length = 1;
    cfg.participant_entries = (RTI_TSS_RemoteParticipantEntry *)
    malloc(sizeof(RTI_TSS_RemoteParticipantEntry) * cfg.length);

    memset(cfg.participant_entries, 0, (sizeof(RTI_TSS_RemoteParticipantEntry) * cfg.length));

    /* Declare the remote participant.  Note that the current_par_entry->participant_name
     * is set using the = operaotor.  We are relying on the C++ copy constructor
     * to allocate memory to hold the string and copy the string into this memory.
     * If the copy constructor is not available, an alternative technique will be required.
     *
     * Here we define the remote participant we plan to communicate with and the associated
     * end points. Important to note, that all remote participants must have a unique name.
     */

    /*
     * This application is only acting as a publisher, therefore we will only define subscribing
     * endpoints.
     */

    // ------------------------------------------------------------------------
    // start first dp entry: config for remote dr in dp FACE_SHAPES_DEMO_SUB1
    // ------------------------------------------------------------------------

    current_par_entry = &cfg.participant_entries[0];
    current_par_entry->participant_name = "FACE_SHAPES_DEMO_SUB1";
    current_par_entry->sub_length       = 6;
    current_par_entry->pub_length       = 0;

    // Configure remote subscribers
    current_par_entry->subscription_entries = (RTI_TSS_RemoteSubscriptionEntry_T *)
    malloc(sizeof(RTI_TSS_RemoteSubscriptionEntry_T) * current_par_entry->sub_length);
    memset(current_par_entry->subscription_entries, 0, sizeof(RTI_TSS_RemoteSubscriptionEntry_T) * current_par_entry->sub_length);

    /*
     * First datareader, with rtps_object_id 200. Square Topic. ShapeType type.
     * The rtps_object_id will be set in the subscriber qos. This value MUST match and
     * be unique globally.
     */
    rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 200;
    rem_subscription_data.topic_name                                 = DDS_String_dup("Square");
    rem_subscription_data.type_name                                  = DDS_String_dup("ShapeType");
    rem_subscription_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_sub_entry           = &current_par_entry->subscription_entries[0];
    current_sub_entry->data     = rem_subscription_data;
    current_sub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);

    /*
     * Second datareader, with rtps_object_id 201. Circle topic. ShapeType type.
     */
    rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 201;
    rem_subscription_data.topic_name                                 = DDS_String_dup("Circle");
    rem_subscription_data.type_name                                  = DDS_String_dup("ShapeType");
    rem_subscription_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_sub_entry           = &current_par_entry->subscription_entries[1];
    current_sub_entry->data     = rem_subscription_data;
    current_sub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);
    
    /*
     * Third datareader, with rtps_object_id 202. Triangle topic. ShapeType type.
     */
    rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 202;
    rem_subscription_data.topic_name                                 = DDS_String_dup("Triangle");
    rem_subscription_data.type_name                                  = DDS_String_dup("ShapeType");
    rem_subscription_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_sub_entry           = &current_par_entry->subscription_entries[2];
    current_sub_entry->data     = rem_subscription_data;
    current_sub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);

    rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 203;
    rem_subscription_data.topic_name                                 = DDS_String_dup("Square");
    rem_subscription_data.type_name                                  = DDS_String_dup("ShapeTypeExtended");
    rem_subscription_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_sub_entry           = &current_par_entry->subscription_entries[3];
    current_sub_entry->data     = rem_subscription_data;
    current_sub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);

    rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 204;
    rem_subscription_data.topic_name                                 = DDS_String_dup("Circle");
    rem_subscription_data.type_name                                  = DDS_String_dup("ShapeTypeExtended");
    rem_subscription_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_sub_entry           = &current_par_entry->subscription_entries[4];
    current_sub_entry->data     = rem_subscription_data;
    current_sub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);

    rem_subscription_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 205;
    rem_subscription_data.topic_name                                 = DDS_String_dup("Triangle");
    rem_subscription_data.type_name                                  = DDS_String_dup("ShapeTypeExtended");
    rem_subscription_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_sub_entry           = &current_par_entry->subscription_entries[5];
    current_sub_entry->data     = rem_subscription_data;
    current_sub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);


    // ----------------------------------------------
    // end first participant entry
    // ----------------------------------------------
}

void _set_discovery_config_sub(struct RTI_TSS_DiscoveryConfigPlugin &cfg)
{
    /*
     * This configuration will be used by those participants using DPSE.
     * Declare structures which hold the remote participant and subscriber static
     * discovery information.  If the remote participant(s) had publishers, a
     * RemotePublicationEntry would aslo be required.  Note that the macro
     * DDS_SubscriptionBuiltinTopicData_INITIALIZER performs memory allocations and
     * therefore should only be used once to avoid memory leaks.  Since this is a
     * FACE Safety-Base application, there isn't an API available to free/finalize
     * those allocated resources.
     */

    RTI_TSS_RemoteParticipantEntry_T *current_par_entry = NULL;
    // RTI_TSS_RemoteSubscriptionEntry_T *current_sub_entry = NULL; /* Unused */
    RTI_TSS_RemotePublicationEntry_T *current_pub_entry = NULL;

    // struct DDS_SubscriptionBuiltinTopicData rem_subscription_data =
               // DDS_SubscriptionBuiltinTopicData_INITIALIZER; /* Unused */
    struct DDS_PublicationBuiltinTopicData rem_publication_data =
               DDS_PublicationBuiltinTopicData_INITIALIZER;

    /*
     * Initialize the DiscoveryConfigPlugin configuration that was passed into this
     * function. The component_name will always be "dpse" in this case.
     */
    RTI_TSS_DiscoveryConfigPlugin_initialize(&cfg);
    cfg.dpse_component_name = "dpse";

    /*
     * The goal of this example is to highlight common customer use cases.
     * In the first domain id, this example will have a single publisher
     * and two subscriber to the same topic.
     */

    /*
     * Set the number of remote participant_entries that will be asserted.
     * Only one is used by this example.  Allocated and initialize the memory to hold the
     * remote participant entry data.
     *
     * Important to note, that when using DPSE participant names need to be unique for standalone
     * applications. Therefore, for this example, the publisher applicaiton, and two subscribing
     * applications are all unique. Below, we're setting the number of REMOTE participant length,
     * which does not include self. In this case, since the application can act as the publisher or
     * subscriber, we include all three participant names.
     *
     * The participant names are defined in the participant qos.
     */
    cfg.length = 1;
    cfg.participant_entries = (RTI_TSS_RemoteParticipantEntry *)
    malloc(sizeof(RTI_TSS_RemoteParticipantEntry) * cfg.length);

    memset(cfg.participant_entries, 0, (sizeof(RTI_TSS_RemoteParticipantEntry) * cfg.length));

    /* Declare the remote participant.  Note that the current_par_entry->participant_name
     * is set using the = operaotor.  We are relying on the C++ copy constructor
     * to allocate memory to hold the string and copy the string into this memory.
     * If the copy constructor is not available, an alternative technique will be required.
     *
     * Here we define the remote participant we plan to communicate with and the associated
     * end points. Important to note, that all remote participants must have a unique name.
     */

    /*
     * This application is only acting as a publisher, therefore we will only define subscribing
     * endpoints.
     */

    // ------------------------------------------------------------------------
    // start first dp entry: config for remote dr in dp FACE_SHAPES_DEMO_PUB1
    // ------------------------------------------------------------------------

    current_par_entry = &cfg.participant_entries[0];
    current_par_entry->participant_name = "FACE_SHAPES_DEMO_PUB1";
    current_par_entry->sub_length       = 0; 
    current_par_entry->pub_length       = 6;

    // Configure remote publishers
    current_par_entry->publication_entries = (RTI_TSS_RemotePublicationEntry_T *)
    malloc( sizeof(RTI_TSS_RemotePublicationEntry_T) * current_par_entry->pub_length);
    memset(current_par_entry->publication_entries, 0, sizeof(RTI_TSS_RemotePublicationEntry_T) * current_par_entry->pub_length);

    /*
     * First datawriter, with rtps_object_id 100. Square topic. ShapeType type.
     * The rtps_object_id will be set in the subscriber qos. This value MUST match and
     * be unique globally.
     */
    rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 100;
    rem_publication_data.topic_name                                 = DDS_String_dup("Square");
    rem_publication_data.type_name                                  = DDS_String_dup("ShapeType");
    rem_publication_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_pub_entry           = &current_par_entry->publication_entries[0];
    current_pub_entry->data     = rem_publication_data;
    current_pub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);
    
    rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 101;
    rem_publication_data.topic_name                                 = DDS_String_dup("Circle");
    rem_publication_data.type_name                                  = DDS_String_dup("ShapeType");
    rem_publication_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_pub_entry           = &current_par_entry->publication_entries[1];
    current_pub_entry->data     = rem_publication_data;
    current_pub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);
    
    rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 102;
    rem_publication_data.topic_name                                 = DDS_String_dup("Triangle");
    rem_publication_data.type_name                                  = DDS_String_dup("ShapeType");
    rem_publication_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_pub_entry           = &current_par_entry->publication_entries[2];
    current_pub_entry->data     = rem_publication_data;
    current_pub_entry->key_kind = FACE_DM_RTI_ShapeType_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeTypePlugin_get(), NULL);

    rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 103;
    rem_publication_data.topic_name                                 = DDS_String_dup("Square");
    rem_publication_data.type_name                                  = DDS_String_dup("ShapeTypeExtended");
    rem_publication_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_pub_entry           = &current_par_entry->publication_entries[3];
    current_pub_entry->data     = rem_publication_data;
    current_pub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);

    rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 104;
    rem_publication_data.topic_name                                 = DDS_String_dup("Circle");
    rem_publication_data.type_name                                  = DDS_String_dup("ShapeTypeExtended");
    rem_publication_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_pub_entry           = &current_par_entry->publication_entries[4];
    current_pub_entry->data     = rem_publication_data;
    current_pub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);

    rem_publication_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 105;
    rem_publication_data.topic_name                                 = DDS_String_dup("Triangle");
    rem_publication_data.type_name                                  = DDS_String_dup("ShapeTypeExtended");
    rem_publication_data.reliability.kind                           = DDS_RELIABLE_RELIABILITY_QOS;

    current_pub_entry           = &current_par_entry->publication_entries[5];
    current_pub_entry->data     = rem_publication_data;
    current_pub_entry->key_kind = FACE_DM_RTI_ShapeTypeExtended_get_key_kind(
                                   FACE_DM_RTI_ShapeTypeExtendedTypePlugin_get(), NULL);

    // ----------------------------------------------
    // end first participant entry
    // ----------------------------------------------
}

// Custom QOS configurations

/* function for customizing domain participant factory qos */
DDS_Boolean custom_participant_factory_qos(struct DDS_DomainParticipantFactoryQos* dpf_qos, void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    dpf_qos->resource_limits.max_participants = 2;

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing domain participant qos */
DDS_Boolean custom_participant_qos(struct DDS_DomainParticipantQos *dp_qos, void *plugin_data)
{
    /* Set the initial peers list - for FACE Safety-Base, multicast is not available */
    DDS_StringSeq_set_maximum(&(dp_qos->discovery.initial_peers), 1);
    DDS_StringSeq_set_length(&(dp_qos->discovery.initial_peers), 1);

    // configured only to use loopback
    if (DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers), 0) != NULL)
    {
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers), 0) =
            DDS_String_dup("127.0.0.1");
    }

    /* Set DPSE as the discovery module */
    if (!RT_ComponentFactoryId_set_name(&(dp_qos->discovery.discovery.name), "dpse"))
    {
        return DDS_BOOLEAN_FALSE;
    }

    /*
     * Set the participant name, must be unique. This function will be reused as
     * if multiple participants need to be configured. Therefore,
     * the participant name will be passed into this function using the user_data
     * config option.
     */
    sprintf(dp_qos->participant_name.name, "%s", static_cast<char *>(plugin_data));

    /* For simplicity, let the local domain participant determine its index automatically */
    dp_qos->protocol.participant_id = -1;

    /* Set the participant-level resources */
    dp_qos->resource_limits.local_writer_allocation = 10;
    dp_qos->resource_limits.local_reader_allocation = 10;
    dp_qos->resource_limits.local_publisher_allocation = 10;
    dp_qos->resource_limits.local_subscriber_allocation = 10;
    dp_qos->resource_limits.local_topic_allocation = 10;
    dp_qos->resource_limits.local_type_allocation = 10;
    dp_qos->resource_limits.remote_participant_allocation = 80;
    dp_qos->resource_limits.remote_writer_allocation = 80;
    dp_qos->resource_limits.remote_reader_allocation = 80;
    dp_qos->resource_limits.matching_writer_reader_pair_allocation = 30;
    dp_qos->resource_limits.max_destination_ports = 100;
    dp_qos->resource_limits.max_receive_ports = 100;

    return DDS_BOOLEAN_TRUE;
}

/* Function which customizes the datawriter qos */
static DDS_Boolean custom_datawriter_qos(struct DDS_DataWriterQos *writer_qos, void *plugin_data)
{
    /* set qos for best effort communication without keys
    writer_qos->reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    writer_qos->resource_limits.max_samples = 1;
    writer_qos->resource_limits.max_samples_per_instance = 1;
    writer_qos->resource_limits.max_instances = 1;
    writer_qos->history.depth = 1; */

    /* reliabile configuration */
    writer_qos->reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    writer_qos->resource_limits.max_samples_per_instance = 10;
    writer_qos->resource_limits.max_instances = 20;

    /* calculated max_samples_per_instance (10) * max_instances (20) */
    writer_qos->resource_limits.max_samples = 200;
    writer_qos->history.depth = 10;

    writer_qos->protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    writer_qos->protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    /* Connext Micro - DPSE
     * Set the local datawriter's object ID
     * Note: Object IDs must be globally unique
     */
    writer_qos->protocol.rtps_object_id = *((DDS_UnsignedLong *)plugin_data);

    return DDS_BOOLEAN_TRUE;
}

static DDS_Boolean custom_datareader_qos(struct DDS_DataReaderQos *reader_qos, void *plugin_data)
{
    /* reliabile configuration */
    reader_qos->reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    reader_qos->resource_limits.max_instances = 20;
    reader_qos->resource_limits.max_samples_per_instance = 200;

    reader_qos->resource_limits.max_samples =
    reader_qos->resource_limits.max_instances *
    reader_qos->resource_limits.max_samples_per_instance;
    reader_qos->history.depth = 32;

    /* if there are more remote writers, increase these limits */
    reader_qos->reader_resource_limits.max_remote_writers = 30;
    reader_qos->reader_resource_limits.max_remote_writers_per_instance = 30;

   /* Connext Micro - DPSE
    * Set the local datareader's object ID
    * Note: Object IDs must be globally unique
    */
    reader_qos->protocol.rtps_object_id = *((DDS_UnsignedLong *)plugin_data);

    return DDS_BOOLEAN_TRUE;
}


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

      /* TODO - Change me when adding more connections */
      static const FACE::UnsignedLong _connection_configurations_length = 12;
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

	const char *participant_name_pub1 = "FACE_SHAPES_DEMO_PUB1";

	/*
	 * The config name is referenced in the connection config as SHAPES_DEMO_PUB1.
	 * This configuration is used for publishers.
	 */
        _domain_configurations[0].config_name                         = "SHAPES_DEMO_PUB1";
        _domain_configurations[0].domain_id                           = _domain_id;
        _domain_configurations[0].configure_domain_participant_qos_fn = custom_participant_qos;
        _domain_configurations[0].user_data                           = (void*)participant_name_pub1;
#ifdef RTI_CONNEXT_MICRO
        _set_discovery_config_pub(_domain_configurations[0].discovery_config);
#else
        _domain_configurations[0].qos_library = "FACE_DM_RTI_ShapeType_Library";
        _domain_configurations[0].qos_profile = "Default_Profile";
#endif

	if (!RTI_TSS_DDS_DomainParticipant_Configuration_initialize(&_domain_configurations[1]))
        {
            return false;
        }

	const char *participant_name_sub1 = "FACE_SHAPES_DEMO_SUB1";

        /*
         * The config name is referenced in the connection config as SHAPES_DEMO_SUB1.
	 * This configuration is used for subscribers.
         */
        _domain_configurations[1].config_name                         = "SHAPES_DEMO_SUB1";
        _domain_configurations[1].domain_id                           = _domain_id;
        _domain_configurations[1].configure_domain_participant_qos_fn = custom_participant_qos;
        _domain_configurations[1].user_data                           = (void*)participant_name_sub1;
#ifdef RTI_CONNEXT_MICRO
        _set_discovery_config_sub(_domain_configurations[1].discovery_config);
#else
        _domain_configurations[1].qos_library = "FACE_DM_RTI_ShapeType_Library";
        _domain_configurations[1].qos_profile = "Default_Profile";
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
        // --------------------------------------------------------------
        // Start Publishers
        // --------------------------------------------------------------

	// set publisher rtps_object_id
        int *shapetype_sq_pub_roi = new int;
        *shapetype_sq_pub_roi = 100;

        /***** ShapeType Publisher Square *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[0]))
        {
            return false;
        }
        _connection_configurations[0].config_name                 = "ShapeType Square Publisher";
        _connection_configurations[0].domain_config_name          = "SHAPES_DEMO_PUB1";
        _connection_configurations[0].direction                   = FACE_SOURCE;
        _connection_configurations[0].topic_name                  = "Square";
        _connection_configurations[0].type_name                   = "ShapeType";
        _connection_configurations[0].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[0].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[0].configure_datawriter_qos_fn = custom_datawriter_qos;
        _connection_configurations[0].configure_subscriber_qos_fn = NULL;
        _connection_configurations[0].configure_datareader_qos_fn = NULL;
        _connection_configurations[0].user_data                   = (void*)shapetype_sq_pub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[0].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[0].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[0].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetype_ci_pub_roi = new int;
        *shapetype_ci_pub_roi = 101;

        /***** ShapeType Publisher Circle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[1]))
        {
            return false;
        }
        _connection_configurations[1].config_name                 = "ShapeType Circle Publisher";
        _connection_configurations[1].domain_config_name          = "SHAPES_DEMO_PUB1";
        _connection_configurations[1].direction                   = FACE_SOURCE;
        _connection_configurations[1].topic_name                  = "Circle";
        _connection_configurations[1].type_name                   = "ShapeType";
        _connection_configurations[1].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[1].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[1].configure_datawriter_qos_fn = custom_datawriter_qos;
        _connection_configurations[1].configure_subscriber_qos_fn = NULL;
        _connection_configurations[1].configure_datareader_qos_fn = NULL;
        _connection_configurations[1].user_data                   = (void*)shapetype_ci_pub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[1].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[1].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[1].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetype_tri_pub_roi = new int;
        *shapetype_tri_pub_roi = 102;

        /***** ShapeType Publisher Triangle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[2]))
        {
            return false;
        }
        _connection_configurations[2].config_name                 = "ShapeType Triangle Publisher";
        _connection_configurations[2].domain_config_name          = "SHAPES_DEMO_PUB1";
        _connection_configurations[2].direction                   = FACE_SOURCE;
        _connection_configurations[2].topic_name                  = "Triangle";
        _connection_configurations[2].type_name                   = "ShapeType";
        _connection_configurations[2].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[2].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[2].configure_datawriter_qos_fn = custom_datawriter_qos;
        _connection_configurations[2].configure_subscriber_qos_fn = NULL;
        _connection_configurations[2].configure_datareader_qos_fn = NULL;
        _connection_configurations[2].user_data                   = (void*)shapetype_tri_pub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[2].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[2].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[2].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetypex_sq_pub_roi1 = new int;
        *shapetypex_sq_pub_roi1 = 103;

        /*
	 * ShapeTypeExtended Square Publisher
	 * Domain X
	 * Object Id 103
	 */
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[3]))
        {
            return false;
        }
        _connection_configurations[3].config_name                 = "ShapeTypeExtended Square Publisher1";
        _connection_configurations[3].domain_config_name          = "SHAPES_DEMO_PUB1";
        _connection_configurations[3].direction                   = FACE_SOURCE;
        _connection_configurations[3].topic_name                  = "Square";
        _connection_configurations[3].type_name                   = "ShapeTypeExtended";
        _connection_configurations[3].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[3].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[3].configure_datawriter_qos_fn = custom_datawriter_qos;
        _connection_configurations[3].configure_subscriber_qos_fn = NULL;
        _connection_configurations[3].configure_datareader_qos_fn = NULL;
        _connection_configurations[3].user_data                   = (void*)shapetypex_sq_pub_roi1;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[3].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[3].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[3].qos_profile                 = "Default_Profile";
#endif
	
	// set publisher rtps_object_id
        int *shapetypex_ci_pub_roi1 = new int;
        *shapetypex_ci_pub_roi1 = 104;

        /*
	 * ShapeTypeExtended Circle Publisher
	 * Domain X
	 * Object Id 104
	 */
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[4]))
        {
            return false;
        }
        _connection_configurations[4].config_name                 = "ShapeTypeExtended Circle Publisher1";
        _connection_configurations[4].domain_config_name          = "SHAPES_DEMO_PUB1";
        _connection_configurations[4].direction                   = FACE_SOURCE;
        _connection_configurations[4].topic_name                  = "Circle";
        _connection_configurations[4].type_name                   = "ShapeTypeExtended";
        _connection_configurations[4].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[4].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[4].configure_datawriter_qos_fn = custom_datawriter_qos;
        _connection_configurations[4].configure_subscriber_qos_fn = NULL;
        _connection_configurations[4].configure_datareader_qos_fn = NULL;
        _connection_configurations[4].user_data                   = (void*)shapetypex_ci_pub_roi1;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[4].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[4].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[4].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetypex_tri_pub_roi1 = new int;
        *shapetypex_tri_pub_roi1 = 105;

        /*
	 * ShapeTypeExtended Triangle Publisher
	 * Domain X
	 * Object Id 105
	 */
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[5]))
        {
            return false;
        }
        _connection_configurations[5].config_name                 = "ShapeTypeExtended Triangle Publisher1";
        _connection_configurations[5].domain_config_name          = "SHAPES_DEMO_PUB1";
        _connection_configurations[5].direction                   = FACE_SOURCE;
        _connection_configurations[5].topic_name                  = "Triangle";
        _connection_configurations[5].type_name                   = "ShapeTypeExtended";
        _connection_configurations[5].configure_publisher_qos_fn  = FACE_DM_RTI_ShapeType_publisher_qos;
        _connection_configurations[5].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[5].configure_datawriter_qos_fn = custom_datawriter_qos;
        _connection_configurations[5].configure_subscriber_qos_fn = NULL;
        _connection_configurations[5].configure_datareader_qos_fn = NULL;
        _connection_configurations[5].user_data                   = (void*)shapetypex_tri_pub_roi1;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[5].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[5].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[5].qos_profile                 = "Default_Profile";
#endif

	// --------------------------------------------------------------
        // End Publishers
        // --------------------------------------------------------------
	
	// --------------------------------------------------------------
        // Start Subscribers
        // --------------------------------------------------------------

	// set publisher rtps_object_id
        int *shapetype_sq_sub_roi = new int;
        *shapetype_sq_sub_roi = 200;

	/***** ShapeType Subscriber Square *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[6]))
        {
            return false;
        }
        _connection_configurations[6].config_name                 = "ShapeType Square Subscriber";
        _connection_configurations[6].domain_config_name          = "SHAPES_DEMO_SUB1";
        _connection_configurations[6].direction                   = FACE_DESTINATION;
        _connection_configurations[6].topic_name                  = "Square";
        _connection_configurations[6].type_name                   = "ShapeType";
        _connection_configurations[6].configure_publisher_qos_fn  = NULL;
        _connection_configurations[6].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[6].configure_datawriter_qos_fn = NULL;
        _connection_configurations[6].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[6].configure_datareader_qos_fn = custom_datareader_qos;
        _connection_configurations[6].user_data                   = (void*)shapetype_sq_sub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[6].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[6].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[6].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetype_ci_sub_roi = new int;
        *shapetype_ci_sub_roi = 201;

        /***** ShapeType Subscriber Circle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[7]))
        {
            return false;
        }
        _connection_configurations[7].config_name                 = "ShapeType Circle Subscriber";
        _connection_configurations[7].domain_config_name          = "SHAPES_DEMO_SUB1";
        _connection_configurations[7].direction                   = FACE_DESTINATION;
        _connection_configurations[7].topic_name                  = "Circle";
        _connection_configurations[7].type_name                   = "ShapeType";
        _connection_configurations[7].configure_publisher_qos_fn  = NULL;
        _connection_configurations[7].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[7].configure_datawriter_qos_fn = NULL;
        _connection_configurations[7].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[7].configure_datareader_qos_fn = custom_datareader_qos;
        _connection_configurations[7].user_data                   = (void*)shapetype_ci_sub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[7].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[7].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[7].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetype_tri_sub_roi = new int;
        *shapetype_tri_sub_roi = 202;

        /***** ShapeType Subscriber Triangle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[8]))
        {
            return false;
        }
        _connection_configurations[8].config_name                 = "ShapeType Triangle Subscriber";
        _connection_configurations[8].domain_config_name          = "SHAPES_DEMO_SUB1";
        _connection_configurations[8].direction                   = FACE_DESTINATION;
        _connection_configurations[8].topic_name                  = "Triangle";
        _connection_configurations[8].type_name                   = "ShapeType";
        _connection_configurations[8].configure_publisher_qos_fn  = NULL;
        _connection_configurations[8].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[8].configure_datawriter_qos_fn = NULL;
        _connection_configurations[8].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[8].configure_datareader_qos_fn = custom_datareader_qos;
        _connection_configurations[8].user_data                   = (void*)shapetype_tri_sub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[8].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[8].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[8].qos_profile                 = "Default_Profile";
#endif
	
	// set publisher rtps_object_id
        int *shapetypex_sq_sub_roi = new int;
        *shapetypex_sq_sub_roi = 203;

	/***** ShapeTypeExtended Subscriber Square *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[9]))
        {
            return false;
        }
        _connection_configurations[9].config_name                 = "ShapeTypeExtended Square Subscriber";
        _connection_configurations[9].domain_config_name          = "SHAPES_DEMO_SUB1";
        _connection_configurations[9].direction                   = FACE_DESTINATION;
        _connection_configurations[9].topic_name                  = "Square";
        _connection_configurations[9].type_name                   = "ShapeTypeExtended";
        _connection_configurations[9].configure_publisher_qos_fn  = NULL;
        _connection_configurations[9].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[9].configure_datawriter_qos_fn = NULL;
        _connection_configurations[9].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[9].configure_datareader_qos_fn = custom_datareader_qos;
        _connection_configurations[9].user_data                   = (void*)shapetypex_sq_sub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[9].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[9].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[9].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetypex_ci_sub_roi = new int;
        *shapetypex_ci_sub_roi = 204;

        /***** ShapeTypeExtended Subscriber Circle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[10]))
        {
            return false;
        }
        _connection_configurations[10].config_name                 = "ShapeTypeExtended Circle Subscriber";
        _connection_configurations[10].domain_config_name          = "SHAPES_DEMO_SUB1";
        _connection_configurations[10].direction                   = FACE_DESTINATION;
        _connection_configurations[10].topic_name                  = "Circle";
        _connection_configurations[10].type_name                   = "ShapeTypeExtended";
        _connection_configurations[10].configure_publisher_qos_fn  = NULL;
        _connection_configurations[10].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[10].configure_datawriter_qos_fn = NULL;
        _connection_configurations[10].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[10].configure_datareader_qos_fn = custom_datareader_qos;
        _connection_configurations[10].user_data                   = (void*)shapetypex_ci_sub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[10].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[10].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[10].qos_profile                 = "Default_Profile";
#endif

	// set publisher rtps_object_id
        int *shapetypex_tri_sub_roi = new int;
        *shapetypex_tri_sub_roi = 205;

        /***** ShapeTypeExtended Subscriber Triangle *****/
        if (!RTI_TSS_Connection_Configuration_initialize(&_connection_configurations[11]))
        {
            return false;
        }
        _connection_configurations[11].config_name                 = "ShapeTypeExtended Triangle Subscriber";
        _connection_configurations[11].domain_config_name          = "SHAPES_DEMO_SUB1";
        _connection_configurations[11].direction                   = FACE_DESTINATION;
        _connection_configurations[11].topic_name                  = "Triangle";
        _connection_configurations[11].type_name                   = "ShapeTypeExtended";
        _connection_configurations[11].configure_publisher_qos_fn  = NULL;
        _connection_configurations[11].configure_topic_qos_fn      = FACE_DM_RTI_ShapeType_topic_qos;
        _connection_configurations[11].configure_datawriter_qos_fn = NULL;
        _connection_configurations[11].configure_subscriber_qos_fn = FACE_DM_RTI_ShapeType_subscriber_qos;
        _connection_configurations[11].configure_datareader_qos_fn = custom_datareader_qos;
        _connection_configurations[11].user_data                   = (void*)shapetypex_tri_sub_roi;
#ifndef RTI_CONNEXT_MICRO
        _connection_configurations[11].bi_dir_ignore_self          = DDS_BOOLEAN_TRUE;
        _connection_configurations[11].qos_library                 = "FACE_DM_RTI_ShapeType_Library";
        _connection_configurations[11].qos_profile                 = "Default_Profile";
#endif

	// --------------------------------------------------------------
        // End Subscribers
        // --------------------------------------------------------------

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
        _system_configurations[0].max_topics = 3;
                

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
                (struct RT_ComponentFactoryProperty *)custom_new_udp_property();
#endif /* !EXCLUDE_UDP */

#endif /* RTI_CONNEXT_MICRO */

        return true;
    }

    int _domain_id;

    DDS_Boolean _initialized;
};

#endif // CUSTOM_CONFIGURATION_HPP
