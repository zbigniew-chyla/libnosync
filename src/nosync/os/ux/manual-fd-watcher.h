// This file is part of libnosync library. See LICENSE file for license details.
#ifndef NOSYNC__OS__UX__MANUAL_FD_WATCHER_H
#define NOSYNC__OS__UX__MANUAL_FD_WATCHER_H

#include <functional>
#include <nosync/os/ux/fd-watcher.h>
#include <map>
#include <memory>
#include <tuple>
#include <vector>


namespace nosync::os::ux
{

struct fd_watch;


class manual_fd_watcher : public fd_watcher
{
public:
    manual_fd_watcher();
    ~manual_fd_watcher() override;

    std::vector<std::tuple<int, fd_watch_mode>> get_watches_fd_info() const;
    bool notify_watches(int fd, fd_watch_mode mode);
    void quit();

    std::unique_ptr<activity_handle> add_watch(int fd, fd_watch_mode mode, std::function<void()> &&notify_func) override;

protected:
    std::shared_ptr<std::multimap<std::tuple<int, fd_watch_mode>, std::shared_ptr<fd_watch>>> watches;
    bool quit_request_pending;
};

}

#endif
