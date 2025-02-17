/**
 * @file application_heartbeat.hpp
 * @author Roman Koch (koch.roman@gmail.com)
 *
 * @copyright Copyright (c) 2025 Roman Koch
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <atomic>
#include <functional>
#include <thread>

namespace application::heartbeat {

class Heartbeat {
   public:
    Heartbeat(unsigned int interval_seconds, std::function<void()> callback);
    ~Heartbeat();
    void start();
    void stop();

   private:
    void run();
    unsigned int interval;
    std::function<void()> callback;
    std::atomic<bool> running;
    std::thread worker;
};

}  // namespace application::heartbeat
