// This file is part of libnosync library. See LICENSE file for license details.
#include <nosync/event-loop-utils.h>
#include <utility>

using std::function;
using std::move;
using std::unique_ptr;


namespace nosync
{

unique_ptr<activity_handle> invoke_later(event_loop &evloop, function<void()> &&task)
{
    return evloop.invoke_at(evloop.get_etime(), move(task));
}


unique_ptr<activity_handle> invoke_with_etime_delay(
    event_loop &evloop, eclock::duration delay, function<void()> &&task)
{
    return evloop.invoke_at(evloop.get_etime() + delay, move(task));
}

}
