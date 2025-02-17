/**
 * @file main.cpp
 * @author Roman Koch (koch.roman@gmail.com)
 *
 * @copyright Copyright (c) 2025 Roman Koch
 * SPDX-License-Identifier: MIT
 */

#include <iostream>
#include <thread>

#include "application_heartbeat.hpp"

using namespace application::heartbeat;

void print_message() { std::cout << "Heartbeat triggered!" << std::endl; }

int main() {
    std::cout << "### START ###" << std::endl;
    Heartbeat hb(2, print_message);
    hb.start();

    std::this_thread::sleep_for(std::chrono::seconds(10));  // 10 Sekunden laufen lassen
    std::cout << "### STOP ###" << std::endl;
    hb.stop();

    return 0;
}
