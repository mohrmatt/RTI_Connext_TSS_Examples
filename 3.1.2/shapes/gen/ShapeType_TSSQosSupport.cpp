

/*
WARNING: THIS FILE IS AUTO-GENERATED. IF MODIFIED, MOVE BEFORE RE-GENERATING.

This file was generated from ShapeType.idl using "rtiddsgen FACE TSS version".
*/

/* include RTI TSS header file for QoS configuration */
#include "util/rti_tss_common.h"

#ifdef RTI_CONNEXT_MICRO
#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
#if !EXCLUDE_UDP
#include "netio/netio_udp.h"
#endif
#endif

#include "log/ext_log.h"

/* function for customizing domain participant factory qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_participant_factory_qos(
    struct DDS_DomainParticipantFactoryQos* dpf_qos,
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);
    #ifdef RTI_CONNEXT_MICRO
    dpf_qos->resource_limits.max_participants = 1;
    #endif
    return DDS_BOOLEAN_TRUE;
}

/* function for customizing domain participant qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_participant_qos(
    struct DDS_DomainParticipantQos* dp_qos,
    void* plugin_data)
{
    /* the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" or
    * from the user-defined library and profile specified in the Domain Participant Config
    */
    #ifndef RTI_CONNEXT_MICRO
    /** Since the QoS is already loaded from the XML profile in pro, we need to 
    * finalize the existing initial peers list before we can create a new one 
    * */
    DDS_StringSeq_finalize(&(dp_qos->discovery.initial_peers));
    #endif

    #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    /* Discovery announcements to loopback and Connext default multicast */
    DDS_StringSeq_set_maximum(&(dp_qos->discovery.initial_peers),2);
    DDS_StringSeq_set_length(&(dp_qos->discovery.initial_peers),2);

    if ((DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) != NULL) &&
    (DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),1) != NULL))
    {
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) = 
        DDS_String_dup("127.0.0.1");
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),1) = 
        DDS_String_dup("239.255.0.1");
    }

    /*DDS_StringSeq_set_maximum(&(dp_qos->discovery.enabled_transports),2);
    DDS_StringSeq_set_length(&(dp_qos->discovery.enabled_transports),2);

    if ((DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 0) != NULL) &&
    (DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 1) != NULL))
    {
        printf("Enabling udp/multicast\n");
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 0) = 
        DDS_String_dup("_udp://");
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 1) = 
        DDS_String_dup("_udp://239.255.0.1");
    }

    if (DDS_StringSeq_set_maximum(&dp_qos->user_traffic.enabled_transports, 2))
    {
        if (DDS_StringSeq_set_length(&dp_qos->user_traffic.enabled_transports, 2))
        {
            *DDS_StringSeq_get_reference(&dp_qos->user_traffic.enabled_transports, 0) = DDS_String_dup("_udp://");
            *DDS_StringSeq_get_reference(&dp_qos->user_traffic.enabled_transports, 1) = DDS_String_dup("_udp://239.255.0.1");
        }
    }*/
    #else
    /* For safety profiles, multicast is not available */
    DDS_StringSeq_set_maximum(&(dp_qos->discovery.initial_peers),1);
    DDS_StringSeq_set_length(&(dp_qos->discovery.initial_peers),1);

    if (DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) != NULL)
    {
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) = 
        DDS_String_dup("127.0.0.1");
    }
    #endif // !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER

    #ifndef RTI_CONNEXT_MICRO 
    /* disable shared memory for Connext Pro */
    dp_qos->transport_builtin.mask = DDS_TRANSPORTBUILTIN_UDPv4;
    #endif

    #ifdef RTI_CONNEXT_MICRO
    #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER

    if (!RT_ComponentFactoryId_set_name(&(dp_qos->discovery.discovery.name),"dpde"))
    {
        Logger_error(__func__, "failed to set discovery plugin name\n", NULL);
        return DDS_BOOLEAN_FALSE;
    }
    #else
    if (!RT_ComponentFactoryId_set_name(&(dp_qos->discovery.discovery.name),"dpse"))
    {
        return DDS_BOOLEAN_FALSE;
    }
    #endif

    UNUSED_ARG(plugin_data);
    #if USE_RTI_MICRO_DPSE
    #if defined(RTI_WIN32)
    #pragma message ("Please modify participant names to be unique as DPSE requires it.")
    #else
    #warning "Please modify participant names to be unique as DPSE requires it."
    #endif    
    #endif
    sprintf(dp_qos->participant_name.name,"RTI FACE Example");

    /* Automatic Domain Participant ID */
    dp_qos->protocol.participant_id = -1;

    /* if there are more remote or local endpoints, you need to increase these limits */
    dp_qos->resource_limits.local_writer_allocation = 10;
    dp_qos->resource_limits.local_reader_allocation = 10;
    dp_qos->resource_limits.local_publisher_allocation = 10;
    dp_qos->resource_limits.local_subscriber_allocation = 10;
    dp_qos->resource_limits.local_topic_allocation = 10;
    dp_qos->resource_limits.local_type_allocation = 10;
    dp_qos->resource_limits.remote_participant_allocation = 80;
    dp_qos->resource_limits.remote_writer_allocation = 80;
    dp_qos->resource_limits.remote_reader_allocation = 80;
    dp_qos->resource_limits.max_destination_ports = 100;
    dp_qos->resource_limits.max_receive_ports = 100;   
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing publisher qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_publisher_qos(
    struct DDS_PublisherQos* pub_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    #ifndef RTI_CONNEXT_MICRO 
    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */

    /* example to increase the length of the partition qos */
    /*
    DDS_Boolean result = DDS_BOOLEAN_TRUE;
    int seq_length = DDS_StringSeq_get_length(&pub_qos->partition.name);
    char** partition = NULL;

    result = DDS_StringSeq_ensure_length(&pub_qos->partition.name,
    seq_length + 1, seq_length + 1);
    if (!result) 
    {
        Logger_error(
            __func__,
            "!Unable to set the sequence length for publisher qos (%d=>%d)\n",
            seq_length,
            seq_length+1);
        return DDS_BOOLEAN_FALSE;
    }

    partition = DDS_StringSeq_get_reference(&pub_qos->partition.name, seq_length);
    if (partition != NULL)
    {
        *partition = DDS_String_dup("my partition");
    }
    */
    #else
    DDS_PublisherQos_initialize(pub_qos);
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing subscriber qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_subscriber_qos(
    struct DDS_SubscriberQos* sub_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    #ifndef RTI_CONNEXT_MICRO 
    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */

    /*example to  increase the length of the partition qos */
    /*
    DDS_Boolean result = DDS_BOOLEAN_TRUE;
    int seq_length = DDS_StringSeq_get_length(&sub_qos->partition.name);
    char** partition = NULL;

    result = DDS_StringSeq_ensure_length(&sub_qos->partition.name,
    seq_length + 1, seq_length + 1);
    if (!result)
    {
        Logger_error(
            __func__,
            "!Unable to set the sequence length for subscriber qos (%d=>%d)\n",
            seq_length,
            seq_length + 1);
        return DDS_BOOLEAN_FALSE;
    }

    partition = DDS_StringSeq_get_reference(&sub_qos->partition.name, seq_length);
    if (partition != NULL)
    {
        *partition = DDS_String_dup("my partition");
    }
    */
    #else
    DDS_SubscriberQos_initialize(sub_qos);
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing topic qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_topic_qos(
    struct DDS_TopicQos* topic_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */
    #if defined(RTI_CONNEXT_MICRO) && !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    DDS_TopicQos_initialize(topic_qos);
    #else
    UNUSED_ARG(topic_qos);
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing data writer qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_datawriter_qos(
    struct DDS_DataWriterQos* writer_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */

    #ifndef RTI_CONNEXT_MICRO
    /* In order to support unbounded sequences/strings */
    if (DDS_PropertyQosPolicyHelper_assert_property(
        &writer_qos->property,
        "dds.data_writer.history.memory_manager.fast_pool.pool_buffer_max_size",
        "4096",
        DDS_BOOLEAN_FALSE) != DDS_RETCODE_OK)
    {
        return DDS_BOOLEAN_FALSE;
    }
    #else
    /* set qos for best effort communication without keys 
    writer_qos->reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    writer_qos->resource_limits.max_samples = 1;
    writer_qos->resource_limits.max_samples_per_instance = 1;
    writer_qos->resource_limits.max_instances = 1;
    writer_qos->history.depth = 1; */
    /* use these instead if reliable (also without keys) */
    writer_qos->reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    writer_qos->resource_limits.max_samples_per_instance = 200;
    writer_qos->resource_limits.max_instances = 20;
    writer_qos->resource_limits.max_samples =
    writer_qos->resource_limits.max_instances *
    writer_qos->resource_limits.max_samples_per_instance;
    writer_qos->history.depth = 32;
    writer_qos->protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    writer_qos->protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    #if FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    writer_qos->protocol.rtps_object_id = 100;
    #endif

    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing data reader qos */
DDS_Boolean 
FACE_DM_RTI_ShapeType_datareader_qos(
    struct DDS_DataReaderQos* reader_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    /* For Connext Pro
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */
    #ifndef RTI_CONNEXT_MICRO
    /* In order to support unbounded sequences/strings */
    reader_qos->reader_resource_limits.
    dynamically_allocate_fragmented_samples = DDS_BOOLEAN_TRUE;
    if (DDS_PropertyQosPolicyHelper_assert_property(
        &reader_qos->property,
        "dds.data_reader.history.memory_manager.fast_pool.pool_buffer_max_size",
        "4096",
        DDS_BOOLEAN_FALSE) != DDS_RETCODE_OK)
    {
        return DDS_BOOLEAN_FALSE;
    }
    #else
    /* set qos for best effort communication without keys */
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
    #if FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    reader_qos->protocol.rtps_object_id = 200;
    #endif

    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing domain participant factory qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_participant_factory_qos(
    struct DDS_DomainParticipantFactoryQos* dpf_qos,
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);
    #ifdef RTI_CONNEXT_MICRO
    dpf_qos->resource_limits.max_participants = 1;
    #endif
    return DDS_BOOLEAN_TRUE;
}

/* function for customizing domain participant qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_participant_qos(
    struct DDS_DomainParticipantQos* dp_qos,
    void* plugin_data)
{
    /* the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" or
    * from the user-defined library and profile specified in the Domain Participant Config
    */
    #ifndef RTI_CONNEXT_MICRO
    /** Since the QoS is already loaded from the XML profile in pro, we need to 
    * finalize the existing initial peers list before we can create a new one 
    * */
    DDS_StringSeq_finalize(&(dp_qos->discovery.initial_peers));
    #endif

    #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    /* Discovery announcements to loopback and Connext default multicast */
    DDS_StringSeq_set_maximum(&(dp_qos->discovery.initial_peers),2);
    DDS_StringSeq_set_length(&(dp_qos->discovery.initial_peers),2);

    if ((DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) != NULL) &&
    (DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),1) != NULL))
    {
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) = 
        DDS_String_dup("127.0.0.1");
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),1) = 
        DDS_String_dup("239.255.0.1");
    }

    /*DDS_StringSeq_set_maximum(&(dp_qos->discovery.enabled_transports),2);
    DDS_StringSeq_set_length(&(dp_qos->discovery.enabled_transports),2);

    if ((DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 0) != NULL) &&
    (DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 1) != NULL))
    {
        printf("Enabling udp/multicast\n");
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 0) = 
        DDS_String_dup("_udp://");
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.enabled_transports), 1) = 
        DDS_String_dup("_udp://239.255.0.1");
    }

    if (DDS_StringSeq_set_maximum(&dp_qos->user_traffic.enabled_transports, 2))
    {
        if (DDS_StringSeq_set_length(&dp_qos->user_traffic.enabled_transports, 2))
        {
            *DDS_StringSeq_get_reference(&dp_qos->user_traffic.enabled_transports, 0) = DDS_String_dup("_udp://");
            *DDS_StringSeq_get_reference(&dp_qos->user_traffic.enabled_transports, 1) = DDS_String_dup("_udp://239.255.0.1");
        }
    }*/
    #else
    /* For safety profiles, multicast is not available */
    DDS_StringSeq_set_maximum(&(dp_qos->discovery.initial_peers),1);
    DDS_StringSeq_set_length(&(dp_qos->discovery.initial_peers),1);

    if (DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) != NULL)
    {
        *DDS_StringSeq_get_reference(&(dp_qos->discovery.initial_peers),0) = 
        DDS_String_dup("127.0.0.1");
    }
    #endif // !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER

    #ifndef RTI_CONNEXT_MICRO 
    /* disable shared memory for Connext Pro */
    dp_qos->transport_builtin.mask = DDS_TRANSPORTBUILTIN_UDPv4;
    #endif

    #ifdef RTI_CONNEXT_MICRO
    #if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER

    if (!RT_ComponentFactoryId_set_name(&(dp_qos->discovery.discovery.name),"dpde"))
    {
        Logger_error(__func__, "failed to set discovery plugin name\n", NULL);
        return DDS_BOOLEAN_FALSE;
    }
    #else
    if (!RT_ComponentFactoryId_set_name(&(dp_qos->discovery.discovery.name),"dpse"))
    {
        return DDS_BOOLEAN_FALSE;
    }
    #endif

    UNUSED_ARG(plugin_data);
    #if USE_RTI_MICRO_DPSE
    #if defined(RTI_WIN32)
    #pragma message ("Please modify participant names to be unique as DPSE requires it.")
    #else
    #warning "Please modify participant names to be unique as DPSE requires it."
    #endif    
    #endif
    sprintf(dp_qos->participant_name.name,"RTI FACE Example");

    /* Automatic Domain Participant ID */
    dp_qos->protocol.participant_id = -1;

    /* if there are more remote or local endpoints, you need to increase these limits */
    dp_qos->resource_limits.local_writer_allocation = 10;
    dp_qos->resource_limits.local_reader_allocation = 10;
    dp_qos->resource_limits.local_publisher_allocation = 10;
    dp_qos->resource_limits.local_subscriber_allocation = 10;
    dp_qos->resource_limits.local_topic_allocation = 10;
    dp_qos->resource_limits.local_type_allocation = 10;
    dp_qos->resource_limits.remote_participant_allocation = 80;
    dp_qos->resource_limits.remote_writer_allocation = 80;
    dp_qos->resource_limits.remote_reader_allocation = 80;
    dp_qos->resource_limits.max_destination_ports = 100;
    dp_qos->resource_limits.max_receive_ports = 100;   
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing publisher qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_publisher_qos(
    struct DDS_PublisherQos* pub_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    #ifndef RTI_CONNEXT_MICRO 
    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */

    /* example to increase the length of the partition qos */
    /*
    DDS_Boolean result = DDS_BOOLEAN_TRUE;
    int seq_length = DDS_StringSeq_get_length(&pub_qos->partition.name);
    char** partition = NULL;

    result = DDS_StringSeq_ensure_length(&pub_qos->partition.name,
    seq_length + 1, seq_length + 1);
    if (!result) 
    {
        Logger_error(
            __func__,
            "!Unable to set the sequence length for publisher qos (%d=>%d)\n",
            seq_length,
            seq_length+1);
        return DDS_BOOLEAN_FALSE;
    }

    partition = DDS_StringSeq_get_reference(&pub_qos->partition.name, seq_length);
    if (partition != NULL)
    {
        *partition = DDS_String_dup("my partition");
    }
    */
    #else
    DDS_PublisherQos_initialize(pub_qos);
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing subscriber qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_subscriber_qos(
    struct DDS_SubscriberQos* sub_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    #ifndef RTI_CONNEXT_MICRO 
    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */

    /*example to  increase the length of the partition qos */
    /*
    DDS_Boolean result = DDS_BOOLEAN_TRUE;
    int seq_length = DDS_StringSeq_get_length(&sub_qos->partition.name);
    char** partition = NULL;

    result = DDS_StringSeq_ensure_length(&sub_qos->partition.name,
    seq_length + 1, seq_length + 1);
    if (!result)
    {
        Logger_error(
            __func__,
            "!Unable to set the sequence length for subscriber qos (%d=>%d)\n",
            seq_length,
            seq_length + 1);
        return DDS_BOOLEAN_FALSE;
    }

    partition = DDS_StringSeq_get_reference(&sub_qos->partition.name, seq_length);
    if (partition != NULL)
    {
        *partition = DDS_String_dup("my partition");
    }
    */
    #else
    DDS_SubscriberQos_initialize(sub_qos);
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing topic qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_topic_qos(
    struct DDS_TopicQos* topic_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */
    #if defined(RTI_CONNEXT_MICRO) && !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    DDS_TopicQos_initialize(topic_qos);
    #else
    UNUSED_ARG(topic_qos);
    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing data writer qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_datawriter_qos(
    struct DDS_DataWriterQos* writer_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    /* For Connext Pro 
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */

    #ifndef RTI_CONNEXT_MICRO
    /* In order to support unbounded sequences/strings */
    if (DDS_PropertyQosPolicyHelper_assert_property(
        &writer_qos->property,
        "dds.data_writer.history.memory_manager.fast_pool.pool_buffer_max_size",
        "4096",
        DDS_BOOLEAN_FALSE) != DDS_RETCODE_OK)
    {
        return DDS_BOOLEAN_FALSE;
    }
    #else
    /* set qos for best effort communication without keys 
    writer_qos->reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    writer_qos->resource_limits.max_samples = 1;
    writer_qos->resource_limits.max_samples_per_instance = 1;
    writer_qos->resource_limits.max_instances = 1;
    writer_qos->history.depth = 1; */
    /* use these instead if reliable (also without keys) */
    writer_qos->reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    writer_qos->resource_limits.max_samples_per_instance = 200;
    writer_qos->resource_limits.max_instances = 20;
    writer_qos->resource_limits.max_samples =
    writer_qos->resource_limits.max_instances *
    writer_qos->resource_limits.max_samples_per_instance;
    writer_qos->history.depth = 32;
    writer_qos->protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    writer_qos->protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    #if FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    writer_qos->protocol.rtps_object_id = 101;
    #endif

    #endif

    return DDS_BOOLEAN_TRUE;
}

/* function for customizing data reader qos */
DDS_Boolean 
FACE_DM_RTI_ShapeTypeExtended_datareader_qos(
    struct DDS_DataReaderQos* reader_qos, 
    void* plugin_data)
{
    UNUSED_ARG(plugin_data);

    /* For Connext Pro
    * the argument qos structure will already contain the QoS values loaded from the
    * profile "ShapeType_Library::ShapeType_Profile" 
    * or from the user-defined library and profile specified in the Domain Participant Config
    */
    #ifndef RTI_CONNEXT_MICRO
    /* In order to support unbounded sequences/strings */
    reader_qos->reader_resource_limits.
    dynamically_allocate_fragmented_samples = DDS_BOOLEAN_TRUE;
    if (DDS_PropertyQosPolicyHelper_assert_property(
        &reader_qos->property,
        "dds.data_reader.history.memory_manager.fast_pool.pool_buffer_max_size",
        "4096",
        DDS_BOOLEAN_FALSE) != DDS_RETCODE_OK)
    {
        return DDS_BOOLEAN_FALSE;
    }
    #else
    /* set qos for best effort communication without keys */
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
    #if FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    reader_qos->protocol.rtps_object_id = 201;
    #endif

    #endif

    return DDS_BOOLEAN_TRUE;
}

