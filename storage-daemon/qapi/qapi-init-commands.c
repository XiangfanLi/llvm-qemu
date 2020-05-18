/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * QAPI Commands initialization
 *
 * Copyright IBM, Corp. 2011
 * Copyright (C) 2014-2018 Red Hat, Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#include "qemu/osdep.h"
#include "qapi-commands.h"
#include "qapi-init-commands.h"

void qmp_init_marshal(QmpCommandList *cmds)
{
    QTAILQ_INIT(cmds);

    qmp_register_command(cmds, "query-block",
                         qmp_marshal_query_block, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "query-blockstats",
                         qmp_marshal_query_blockstats, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "query-block-jobs",
                         qmp_marshal_query_block_jobs, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block_passwd",
                         qmp_marshal_block_passwd, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block_resize",
                         qmp_marshal_block_resize, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-snapshot-sync",
                         qmp_marshal_blockdev_snapshot_sync, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-snapshot",
                         qmp_marshal_blockdev_snapshot, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "change-backing-file",
                         qmp_marshal_change_backing_file, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-commit",
                         qmp_marshal_block_commit, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "drive-backup",
                         qmp_marshal_drive_backup, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-backup",
                         qmp_marshal_blockdev_backup, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "query-named-block-nodes",
                         qmp_marshal_query_named_block_nodes, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "x-debug-query-block-graph",
                         qmp_marshal_x_debug_query_block_graph, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "drive-mirror",
                         qmp_marshal_drive_mirror, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-dirty-bitmap-add",
                         qmp_marshal_block_dirty_bitmap_add, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-dirty-bitmap-remove",
                         qmp_marshal_block_dirty_bitmap_remove, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-dirty-bitmap-clear",
                         qmp_marshal_block_dirty_bitmap_clear, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-dirty-bitmap-enable",
                         qmp_marshal_block_dirty_bitmap_enable, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-dirty-bitmap-disable",
                         qmp_marshal_block_dirty_bitmap_disable, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-dirty-bitmap-merge",
                         qmp_marshal_block_dirty_bitmap_merge, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "x-debug-block-dirty-bitmap-sha256",
                         qmp_marshal_x_debug_block_dirty_bitmap_sha256, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-mirror",
                         qmp_marshal_blockdev_mirror, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-stream",
                         qmp_marshal_block_stream, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-set-speed",
                         qmp_marshal_block_job_set_speed, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-cancel",
                         qmp_marshal_block_job_cancel, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-pause",
                         qmp_marshal_block_job_pause, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-resume",
                         qmp_marshal_block_job_resume, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-complete",
                         qmp_marshal_block_job_complete, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-dismiss",
                         qmp_marshal_block_job_dismiss, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-job-finalize",
                         qmp_marshal_block_job_finalize, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-add",
                         qmp_marshal_blockdev_add, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "x-blockdev-reopen",
                         qmp_marshal_x_blockdev_reopen, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-del",
                         qmp_marshal_blockdev_del, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-create",
                         qmp_marshal_blockdev_create, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "block-set-write-threshold",
                         qmp_marshal_block_set_write_threshold, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "x-blockdev-change",
                         qmp_marshal_x_blockdev_change, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "x-blockdev-set-iothread",
                         qmp_marshal_x_blockdev_set_iothread, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "nbd-server-start",
                         qmp_marshal_nbd_server_start, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "nbd-server-add",
                         qmp_marshal_nbd_server_add, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "nbd-server-remove",
                         qmp_marshal_nbd_server_remove, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "nbd-server-stop",
                         qmp_marshal_nbd_server_stop, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-snapshot-internal-sync",
                         qmp_marshal_blockdev_snapshot_internal_sync, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "blockdev-snapshot-delete-internal-sync",
                         qmp_marshal_blockdev_snapshot_delete_internal_sync, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "job-pause",
                         qmp_marshal_job_pause, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "job-resume",
                         qmp_marshal_job_resume, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "job-cancel",
                         qmp_marshal_job_cancel, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "job-complete",
                         qmp_marshal_job_complete, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "job-dismiss",
                         qmp_marshal_job_dismiss, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "job-finalize",
                         qmp_marshal_job_finalize, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "query-jobs",
                         qmp_marshal_query_jobs, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "query-chardev",
                         qmp_marshal_query_chardev, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "query-chardev-backends",
                         qmp_marshal_query_chardev_backends, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "ringbuf-write",
                         qmp_marshal_ringbuf_write, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "ringbuf-read",
                         qmp_marshal_ringbuf_read, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "chardev-add",
                         qmp_marshal_chardev_add, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "chardev-change",
                         qmp_marshal_chardev_change, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "chardev-remove",
                         qmp_marshal_chardev_remove, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "chardev-send-break",
                         qmp_marshal_chardev_send_break, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "qmp_capabilities",
                         qmp_marshal_qmp_capabilities, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "query-version",
                         qmp_marshal_query_version, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "query-commands",
                         qmp_marshal_query_commands, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "query-events",
                         qmp_marshal_query_events, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "quit",
                         qmp_marshal_quit, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "qom-list",
                         qmp_marshal_qom_list, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "qom-get",
                         qmp_marshal_qom_get, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "qom-set",
                         qmp_marshal_qom_set, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "qom-list-types",
                         qmp_marshal_qom_list_types, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "qom-list-properties",
                         qmp_marshal_qom_list_properties, QCO_ALLOW_PRECONFIG);
    qmp_register_command(cmds, "object-del",
                         qmp_marshal_object_del, QCO_NO_OPTIONS);
    qmp_register_command(cmds, "transaction",
                         qmp_marshal_transaction, QCO_NO_OPTIONS);
}

/* Dummy declaration to prevent empty .o file */
char qapi_dummy_qapi_init_commands_c;
