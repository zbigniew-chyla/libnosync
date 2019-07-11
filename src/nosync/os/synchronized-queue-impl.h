// This file is part of libnosync library. See LICENSE file for license details.
#ifndef NOSYNC__OS__SYNCHRONIZED_QUEUE_IMPL_H
#define NOSYNC__OS__SYNCHRONIZED_QUEUE_IMPL_H


namespace nosync::os
{

template<typename T>
synchronized_queue<T>::synchronized_queue()
    : elements(), elements_mutex(), elements_present_cv()
{
}


template<typename T>
void synchronized_queue<T>::enqueue(T element)
{
    std::scoped_lock lock(elements_mutex);
    bool was_empty = elements.empty();
    elements.push_back(std::move(element));
    if (was_empty) {
        elements_present_cv.notify_all();
    }
}


template<typename T>
T synchronized_queue<T>::dequeue()
{
    std::unique_lock<std::mutex> lock(elements_mutex);
    elements_present_cv.wait(
        lock,
        [&]() {
            return !elements.empty();
        });

    auto element = std::move(elements.front());
    elements.pop_front();

    return element;
}

}

#endif /* NOSYNC__OS__SYNCHRONIZED_QUEUE_IMPL_H */
