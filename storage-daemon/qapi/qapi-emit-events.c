/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * QAPI Events emission
 *
 * Copyright (c) 2014 Wenchao Xia
 * Copyright (c) 2015-2018 Red Hat Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#include "qemu/osdep.h"
#include "qapi-emit-events.h"

const QEnumLookup QAPIEvent_lookup = {
    .array = (const char *const[]) {
        [QAPI_EVENT_BLOCK_IMAGE_CORRUPTED] = "BLOCK_IMAGE_CORRUPTED",
        [QAPI_EVENT_BLOCK_IO_ERROR] = "BLOCK_IO_ERROR",
        [QAPI_EVENT_BLOCK_JOB_COMPLETED] = "BLOCK_JOB_COMPLETED",
        [QAPI_EVENT_BLOCK_JOB_CANCELLED] = "BLOCK_JOB_CANCELLED",
        [QAPI_EVENT_BLOCK_JOB_ERROR] = "BLOCK_JOB_ERROR",
        [QAPI_EVENT_BLOCK_JOB_READY] = "BLOCK_JOB_READY",
        [QAPI_EVENT_BLOCK_JOB_PENDING] = "BLOCK_JOB_PENDING",
        [QAPI_EVENT_BLOCK_WRITE_THRESHOLD] = "BLOCK_WRITE_THRESHOLD",
        [QAPI_EVENT_QUORUM_FAILURE] = "QUORUM_FAILURE",
        [QAPI_EVENT_QUORUM_REPORT_BAD] = "QUORUM_REPORT_BAD",
        [QAPI_EVENT_JOB_STATUS_CHANGE] = "JOB_STATUS_CHANGE",
        [QAPI_EVENT_VSERPORT_CHANGE] = "VSERPORT_CHANGE",
    },
    .size = QAPI_EVENT__MAX
};

/* Dummy declaration to prevent empty .o file */
char qapi_dummy_qapi_emit_events_c;
