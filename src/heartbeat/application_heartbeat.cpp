/**
 * @file application_heartbeat.cpp
 * @author Roman Koch (koch.roman@gmail.com)
 *
 * @copyright Copyright (c) 2025 Roman Koch
 * SPDX-License-Identifier: MIT
 */

#include "application_heartbeat.hpp"

#include <chrono>
#include <iostream>

namespace application::heartbeat {

Heartbeat::Heartbeat(unsigned int interval_seconds, std::function<void()> callback) : interval(interval_seconds), callback(callback), running(false) {}

Heartbeat::~Heartbeat() { stop(); }

void Heartbeat::start() {
    if (running.exchange(true))
        return;
    worker = std::thread(&Heartbeat::run, this);
}

void Heartbeat::stop() {
    running = false;
    if (worker.joinable()) {
        worker.join();
    }
}

void Heartbeat::run() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(interval));
        if (running && callback) {
            callback();
        }
    }
}

}  // namespace application::heartbeat
