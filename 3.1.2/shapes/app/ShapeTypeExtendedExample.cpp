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
#include "gen/FACE/DM/RTI/ShapeTypeExtended/TypedTS_Impl.hpp"

/* include RTI TSS implementation header */
#include "rti_tss_impl.h"

/* include the custom configuration interface */
#include "CustomConfiguration.hpp"

#define XMAX 250
#define YMAX 250
#define PUB_SLEEP_USEC  500000

#define LINUX
#if defined(LINUX)
  #include <unistd.h>
#endif

/*
 * Listener callback for receiving data
 */
static int received_count = 0;

/* TSS instance */
static RTI::TSS::Base *TSS_Base;
static RTI::ShapeTypeExtended::TypedTS *ShapeTypeExtended_TSS_TypedTS;
static FACE::Configuration *Custom_Config;

#if RTI_CALLBACK_IMPLEMENTED
/* Callback instance */
static RTI::ShapeTypeExtended::Read_Callback *ShapeTypeExtended_ReadCallback;
#endif /* RTI_CALLBACK_IMPLEMENTED */

enum QOS
{
    DEFAULT,
    LATE,
    OWNERSHIP1,
    OWNERSHIP2
};

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

    FACE::DM::RTI::ShapeTypeExtended ShapeTypeExtended_sample;
    FACE::TSS::HEADER_TYPE header;
    FACE::TSS::QoS_EVENT_TYPE qos_parameters;
    FACE::TSS::TRANSACTION_ID_TYPE transaction_id(0);

    struct timespec sleep_time = {0, 500000000};
#if !defined(RTI_WIN32)
    struct timespec loop_time;
    struct timespec rem_time;
    int rval;
#endif

    TSS_Base = new RTI::TSS::Base;
    ShapeTypeExtended_TSS_TypedTS = new RTI::ShapeTypeExtended::TypedTS;

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
            "ShapeTypeExtended subscriber",
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
        ShapeTypeExtended_ReadCallback = new RTI::ShapeTypeExtended::Read_Callback;

        ShapeTypeExtended_TSS_TypedTS->Register_Callback(
                connection_id,
                *ShapeTypeExtended_ReadCallback,
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
            ShapeTypeExtended_TSS_TypedTS->Receive_Message(
                    connection_id,
                    timeout,
                    transaction_id,
                    ShapeTypeExtended_sample,
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
                printf("received data: color[%s] x[%d] y[%d] size[%d] angle[%f] fill[%d]\n",
                       ShapeTypeExtended_sample.color.buffer(),
                       ShapeTypeExtended_sample.x,
                       ShapeTypeExtended_sample.y,
                       ShapeTypeExtended_sample.shapesize,
                       ShapeTypeExtended_sample.angle,
		       ShapeTypeExtended_sample.fillKind);

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
    delete (ShapeTypeExtended_TSS_TypedTS);

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
publisher_main(int num_messages, int domain_id, QOS qos)
{
    FACE::RETURN_CODE_TYPE::Value retcode;
    FACE::TIMEOUT_TYPE timeout(FACE_INF_TIME_VALUE);
    FACE::TSS::CONNECTION_ID_TYPE connection_id;
    FACE::TSS::MESSAGE_SIZE_TYPE max_message_size;

    FACE::DM::RTI::ShapeTypeExtended ShapeTypeExtended_sample;

    FACE::TSS::TRANSACTION_ID_TYPE transaction_id(0);

    struct timespec sleep_time = {2, 0};
#if !defined(RTI_WIN32)
    struct timespec loop_time;
    struct timespec rem_time;
    int rval;
#endif
    int count;

    TSS_Base = new RTI::TSS::Base;
    ShapeTypeExtended_TSS_TypedTS = new RTI::ShapeTypeExtended::TypedTS;
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

    // Color of shape being published
    FACE::String color;

    // Shape size being published
    int shapesize = 0;

    // publisher name defined in connection list
    char pub_name[30];

    if (qos == LATE) {
       sprintf(pub_name, "%s", "ShapeTypeExtended publisher2");
       color = FACE::String("GREEN");
       shapesize = 50;
    }
    else if (qos == OWNERSHIP1) {
       sprintf(pub_name, "%s", "ShapeTypeExtended publisher3");
       color = FACE::String("BLUE");
       shapesize = 50;
    }
    else if (qos == OWNERSHIP2) {
       sprintf(pub_name, "%s", "ShapeTypeExtended publisher4");
       color = FACE::String("BLUE");
       shapesize = 30;
    }
    else {
       sprintf(pub_name, "%s", "ShapeTypeExtended publisher1");
       color = FACE::String("ORANGE");
       shapesize = 50;
    }

    /* create connection for publishing FACE TSS */
    TSS_Base->Create_Connection(
            pub_name,
            timeout, /* not used */
            connection_id,
            max_message_size,
            retcode);

    if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
    {
        printf("!Failed Create_Connection(rc=%d)\n", retcode);
        return;
    }

    FACE::String orange = FACE::String("ORANGE");
    ShapeTypeExtended_sample.color = orange;
    ShapeTypeExtended_sample.fillKind = FACE::DM::RTI::ShapeFillKind::HORIZONTAL_HATCH_FILL;    
    
    int xdelta = 20;
    int ydelta = 10;
    ShapeTypeExtended_sample.shapesize = 30;

    /* publishing loop */
    for (count = 0; (count < num_messages) || (num_messages == 0); count++)
    {
        printf("sending message %d\n", count);
        ShapeTypeExtended_sample.color     = color;
	ShapeTypeExtended_sample.x     = (ShapeTypeExtended_sample.x + xdelta) % XMAX;
	ShapeTypeExtended_sample.y     = (ShapeTypeExtended_sample.y + ydelta) % YMAX;

	ShapeTypeExtended_sample.angle = ShapeTypeExtended_sample.angle + 20;
	ShapeTypeExtended_sample.shapesize = shapesize;

	if (qos != OWNERSHIP1 && qos != OWNERSHIP2)
	    ShapeTypeExtended_sample.fillKind = FACE::DM::RTI::ShapeFillKind::HORIZONTAL_HATCH_FILL;

        /* send message */
        ShapeTypeExtended_TSS_TypedTS->Send_Message(
                connection_id,
                timeout,
                transaction_id, /* ignored */
                ShapeTypeExtended_sample,
                retcode);
        if (retcode != FACE::RETURN_CODE_TYPE::NO_ERROR)
        {
            printf("error sending message %d: %d\n", count, retcode);
        }


#if defined(RTI_WIN32)
        Sleep((DWORD)sleep_time.tv_sec * 1000);
#elif defined(LINUX)
	usleep(PUB_SLEEP_USEC);
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
    delete (ShapeTypeExtended_TSS_TypedTS);

    delete (TSS_Base);

#endif

    return;
}

static void
printUsage()
{
    printf("ShapeTypeExtended Example [-pub|-sub|+sub] [-num <num samples>] [-id "
           "<domain id>] [-late] [-ownership1] [-ownership2]\n");
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
    QOS is_qos = DEFAULT;
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
	else if(!strcmp("-late", argv[i]))
	{
            is_qos = LATE;
	}
	else if(!strcmp("-ownership1", argv[i]))
	{
            is_qos = OWNERSHIP1;
	}
	else if(!strcmp("-ownership2", argv[i]))
	{
            is_qos = OWNERSHIP2;
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
           " RTI Connext TSS ShapeTypeExtended Example (%s)\n"
           "---------------------------------------------------------\n",
           CONNEXT_TYPE);

    if (is_pub)
    {
        publisher_main(num_count, domain_id, is_qos);
    }
    else
    {
        subscriber_main(cb_sub, num_count, domain_id);
    }

    return 0;
}
