// This file is part of libnosync library. See LICENSE file for license details.
#ifndef NOSYNC_UX__PIPED_COMMAND_H
#define NOSYNC_UX__PIPED_COMMAND_H

#include <functional>
#include <nosync/bytes-io.h>
#include <nosync/request-handler.h>
#include <nosync/ux/fd-watching-event-loop.h>
#include <memory>
#include <string>
#include <sys/types.h>
#include <tuple>
#include <vector>


namespace nosync::ux
{

std::tuple<::pid_t, std::shared_ptr<bytes_io>> start_piped_command(
    fd_watching_event_loop &evloop, const std::shared_ptr<request_handler<::pid_t, int>> &subproc_reaper,
    const std::string &cmd_path, const std::vector<std::string> &cmd_args,
    std::function<void(int)> &&status_collector);

std::tuple<::pid_t, std::shared_ptr<bytes_io>> start_piped_shell_command(
    fd_watching_event_loop &evloop, const std::shared_ptr<request_handler<::pid_t, int>> &subproc_reaper,
    const std::string &shell_cmd, std::function<void(int)> &&status_collector);

}

#endif /* NOSYNC_UX__PIPED_COMMAND_H */