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

#ifndef QAPI_EMIT_EVENTS_H
#define QAPI_EMIT_EVENTS_H

#include "qapi/util.h"

typedef enum QAPIEvent {
    QAPI_EVENT_BLOCK_IMAGE_CORRUPTED,
    QAPI_EVENT_BLOCK_IO_ERROR,
    QAPI_EVENT_BLOCK_JOB_COMPLETED,
    QAPI_EVENT_BLOCK_JOB_CANCELLED,
    QAPI_EVENT_BLOCK_JOB_ERROR,
    QAPI_EVENT_BLOCK_JOB_READY,
    QAPI_EVENT_BLOCK_JOB_PENDING,
    QAPI_EVENT_BLOCK_WRITE_THRESHOLD,
    QAPI_EVENT_QUORUM_FAILURE,
    QAPI_EVENT_QUORUM_REPORT_BAD,
    QAPI_EVENT_JOB_STATUS_CHANGE,
    QAPI_EVENT_VSERPORT_CHANGE,
    QAPI_EVENT__MAX,
} QAPIEvent;

#define QAPIEvent_str(val) \
    qapi_enum_lookup(&QAPIEvent_lookup, (val))

extern const QEnumLookup QAPIEvent_lookup;

void qapi_event_emit(QAPIEvent event, QDict *qdict);

#endif /* QAPI_EMIT_EVENTS_H */
