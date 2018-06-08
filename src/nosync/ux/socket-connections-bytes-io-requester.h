// This file is part of libnosync library. See LICENSE file for license details.
#ifndef NOSYNC_UNIX__SOCKET_CONNECTIONS_BYTES_IO_REQUESTER_H
#define NOSYNC_UNIX__SOCKET_CONNECTIONS_BYTES_IO_REQUESTER_H

#include <chrono>
#include <memory>
#include <nosync/bytes-io.h>
#include <nosync/request-handler.h>
#include <nosync/result-handler.h>
#include <nosync/ux/fd-watching-event-loop.h>
#include <nosync/ux/socket-address.h>


namespace nosync::ux
{

void request_socket_connection_bytes_io(
    fd_watching_event_loop &evloop, const std::shared_ptr<socket_address> &addr,
    std::chrono::nanoseconds timeout, result_handler<std::shared_ptr<bytes_io>> &&res_handler);

std::shared_ptr<request_handler<std::shared_ptr<socket_address>, std::shared_ptr<bytes_io>>> make_socket_connections_bytes_io_requester(
    fd_watching_event_loop &evloop);

}

#endif /* NOSYNC_UNIX__SOCKET_CONNECTIONS_BYTES_IO_REQUESTER_H */
