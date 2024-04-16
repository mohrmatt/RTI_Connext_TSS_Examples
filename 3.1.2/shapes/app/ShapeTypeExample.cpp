/*******************************************************************************
 *  Copyright (c) 2018-2021 Real-Time Innovations, Inc.  All rights reserved.
 *
 *  No duplications, whole or partial, manual or electronic, may be made
 *  without express written permission.  Any such copies, or revisions thereof,
 *  must display this notice unaltered.
 *  This code contains trade secrets of Real-Time Innovations, Inc.
 *******************************************************************************/

/*
 * This example demonstrates how to use the RTI TSS library
 * 	by an application that makes use of a separate library
 * 	to provide type support and configuration.  Thus, this
 * 	example includes only the minimum necessary code to
 * 	build a FACE UoP using the RTI TSS implementation.
 *
 * 	This example also demonstrates how to setup a callback
 * 	to process received data.
 *
 *  Follow the Examples section in user documentation
 *  to build and run this example.
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

/* include face header file */
#include "RTI/TSS/Base.hpp"

/* include rtiddsgen generated definition of data type */
#include "gen/ShapeType.hpp"

/* include the type specific face header file */
#include "gen/FACE/DM/RTI/ShapeType/TypedTS_Impl.hpp"

/* include RTI TSS implementation header */
#include "rti_tss_impl.h"

/* include the custom configuration interface */
#include "CustomConfiguration.hpp"

/*
 * Listener callback for receiving data
 */
static int received_count = 0;

/* TSS instance */
static RTI::TSS::Base *TSS_Base;
static RTI::ShapeType::TypedTS *ShapeType_TSS_TypedTS;
static FACE::Configuration *Custom_Config;

#if RTI_CALLBACK_IMPLEMENTED
/* Callback instance */
static RTI::ShapeType::Read_Callback *ShapeType_ReadCallback;
#endif /* RTI_CALLBACK_IMPLEMENTED */

/*
 * Subscriber
 */
static void
subscriber_main(int callback_sub, int num_messages, int domain_id)
{
    FACE::RETURN_CODE_TYPE::Value retcode;
    FACE::TIMEOUT_TYPE timeout(FACE_INF_TIME_VALUE);
    FACE::TSS::CONNECTION_ID_TYPE connection_id;
    FACE::TSS::MESSAGE_SIZE_TYPE max_message_size;

    FACE::DM::RTI::ShapeType ShapeType_sample;
    FACE::TSS::HEADER_TYPE header;
    FACE::TSS::QoS_EVENT_TYPE qos_parameters;
    FACE::TSS::TRANSACTION_ID_TYPE transaction_id(0);

    struct timespec sleep_time = {2, 0};
#if !defined(RTI_WIN32)
    struct timespec loop_time;
    struct timespec rem_time;
    int rval;
#endif

    TSS_Base = new RTI::TSS::Base;
    ShapeType_TSS_TypedTS = new RTI::ShapeType::TypedTS;

    /** We can set the DDS domain id (and other configurable parameters) using a
     * custom configuration interface.
     * */
    Custom_Config = new CustomConfiguration(domain_id);

    TSS_Base->Set_Reference("ThisIsIgnored", &Custom_Config, 0, retcode);
    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("Failed Set_Reference (rc=%d)\n", retcode);
        return;
    }

    TSS_Base->Initialize("Shapes", retcode);
    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("!Failed Initialize(rc=%d)\n", retcode);
        return;
    }

    /* create connection for publishing FACE TSS */
    TSS_Base->Create_Connection(
            "ShapeType subscriber",
            timeout, /* not used */
            connection_id,
            max_message_size,
            retcode);

    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("!Failed Create_Connection(rc=%d)\n", retcode);
        return;
    }

#if RTI_CALLBACK_IMPLEMENTED
    /* register callback as needed */
    if (callback_sub)
    {
        ShapeType_ReadCallback = new RTI::ShapeType::Read_Callback;

        ShapeType_TSS_TypedTS->Register_Callback(
                connection_id,
                *ShapeType_ReadCallback,
                retcode);

        if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
        {
            printf("!Failed Register_Callback(rc=%d)\n", retcode);
            return;
        }
    }
#endif /* RTI_CALLBACK_IMPLEMENTED */

    /* polling (non-callback) reception loop */
    while ((received_count < num_messages) || (num_messages == 0))
    {
#if defined(RTI_WIN32)
        Sleep((DWORD)sleep_time.tv_sec * 1000);
#else
        /* sleep for 4 seconds */
        loop_time = sleep_time;
        do
        {
            rval = nanosleep(&loop_time, &rem_time);
            if ((rval == -1) && (errno == EINTR))
            {
                loop_time = rem_time;
            }
        } while ((rval == -1) && (errno == EINTR));
#endif

        if (!callback_sub)
        {
            ShapeType_TSS_TypedTS->Receive_Message(
                    connection_id,
                    timeout,
                    transaction_id,
                    ShapeType_sample,
                    header,         /* not used */
                    qos_parameters, /* not used */
                    retcode);

            if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
            {
                /* FACE::NOT_AVAILABLE (2) can be returned if
                 * Receive_Message returns no data.
                 * Uncomment below to print errors.
                 */
                 printf("Receive_Message returned an error: %d\n", retcode);
            }
            else
            {
                printf("received data: color[%s] x[%d] y[%d] size[%d]\n",
                       ShapeType_sample.color.buffer(),
                       ShapeType_sample.x,
                       ShapeType_sample.y,
                       ShapeType_sample.shapesize);

                received_count++;
            }
        }
    }

    /* destroy connection */
    TSS_Base->Destroy_Connection(connection_id, retcode);
    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("error destroying connection: %d\n", retcode);
    }

#if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    delete (ShapeType_TSS_TypedTS);

    /* NOTE: Deletion of the Base must be done last, as its destructor will
     * finalize all resources of the RTI TSS implementation.
     */
    delete (TSS_Base);
#endif

    return;
}

/*
 * Publisher
 */
static void
publisher_main(int num_messages, int domain_id)
{
    FACE::RETURN_CODE_TYPE::Value retcode;
    FACE::TIMEOUT_TYPE timeout(FACE_INF_TIME_VALUE);
    FACE::TSS::CONNECTION_ID_TYPE connection_id;
    FACE::TSS::MESSAGE_SIZE_TYPE max_message_size;

    FACE::DM::RTI::ShapeType ShapeType_sample;

    FACE::TSS::TRANSACTION_ID_TYPE transaction_id(0);

    struct timespec sleep_time = {2, 0};
#if !defined(RTI_WIN32)
    struct timespec loop_time;
    struct timespec rem_time;
    int rval;
#endif
    int count;

    TSS_Base = new RTI::TSS::Base;
    ShapeType_TSS_TypedTS = new RTI::ShapeType::TypedTS;
    Custom_Config = new CustomConfiguration(domain_id);

    if (num_messages == 0)
    {
        printf("Sending unlimited samples ...\n");
    }
    else
    {
        printf("Sending %d samples ...\n", num_messages);
    }

    TSS_Base->Set_Reference("ThisIsIgnored", &Custom_Config, 0, retcode);
    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("Failed Set_Reference (rc=%d)\n", retcode);
        return;
    }

    TSS_Base->Initialize("Shapes", retcode);
    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("!Failed Initialize(rc=%d)\n", retcode);
        return;
    }

    /* create connection for publishing FACE TSS */
    TSS_Base->Create_Connection(
            "ShapeType publisher",
            timeout, /* not used */
            connection_id,
            max_message_size,
            retcode);

    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("!Failed Create_Connection(rc=%d)\n", retcode);
        return;
    }

    /* publishing loop */
    for (count = 0; (count < num_messages) || (num_messages == 0); count++)
    {
        printf("sending message %d\n", count);
	ShapeType_sample.x     = rand() % 250;
	ShapeType_sample.y     = rand() % 250;
	ShapeType_sample.shapesize = 50;

	FACE::String green = FACE::String("GREEN");
        ShapeType_sample.color = green;

        /* send message */
        ShapeType_TSS_TypedTS->Send_Message(
                connection_id,
                timeout,
                transaction_id, /* ignored */
                ShapeType_sample,
                retcode);
        if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
        {
            printf("error sending message %d: %d\n", count, retcode);
        }

#if defined(RTI_WIN32)
        Sleep((DWORD)sleep_time.tv_sec * 1000);
#else
        loop_time = sleep_time;
        do
        {
            rval = nanosleep(&loop_time, &rem_time);
            if ((rval == -1) && (errno == EINTR))
            {
                loop_time = rem_time;
            }
        } while ((rval == -1) && (errno == EINTR));
#endif
    }

    /* destroy connection */
    TSS_Base->Destroy_Connection(connection_id, retcode);
    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("error destroying connection: %d\n", retcode);
    }

#if !FACE_COMPLIANCE_LEVEL_SAFETY_BASE_OR_STRICTER
    delete (ShapeType_TSS_TypedTS);

    delete (TSS_Base);

#endif

    return;
}

static void
printUsage()
{
    printf("ShapeType Example [-pub|-sub|+sub] [-num <num samples>] [-id "
           "<domain id>]\n");
}

int
main(int argc, char **argv)
{
    /* default: publisher */
    int is_pub = 1;
    int cb_sub = 0;
    int num_count = 0;
    int domain_id = 0;
    int i = 0;
#ifdef RTI_CONNEXT_MICRO
    const char *CONNEXT_TYPE = "Connext DDS Micro";
#else
    const char *CONNEXT_TYPE = "Connext DDS Pro";
#endif

    for (i = 1; i < argc; i++)
    {
        if (!strcmp("-sub", argv[i]))
        {
            is_pub = 0;
            cb_sub = 0;
        }
        else if (!strcmp("+sub", argv[i]))
        {
            is_pub = 0;
            cb_sub = 1;
        }
        else if (!strcmp("-pub", argv[i]))
        {
            is_pub = 1;
        }
        else if (!strcmp("-num", argv[i]))
        {
            if ((++i) >= argc)
            {
                printf("Missing argument for -num");
                printUsage();
                return 0;
            }
            else
            {
                num_count = atoi(argv[i]);
            }
        }
        else if (!strcmp("-id", argv[i]))
        {
            if ((++i) >= argc)
            {
                printf("Missing argument for -id");
                printUsage();
                return 0;
            }
            else
            {
                domain_id = atoi(argv[i]);
            }
        }
        else
        {
            printf("Unknown argument: [%s]\n", argv[i]);
            printUsage();
            return 0;
        }
    }

    printf("---------------------------------------------------------\n"
           " RTI Connext TSS ShapeType Example (%s)\n"
           "---------------------------------------------------------\n",
           CONNEXT_TYPE);

    if (is_pub)
    {
        publisher_main(num_count, domain_id);
    }
    else
    {
        subscriber_main(cb_sub, num_count, domain_id);
    }

    return 0;
}
