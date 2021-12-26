#include "utility.hpp"
using namespace daytime::server;

#include <ctime>

std::string daytime::server::make_daytime_string() {
    auto now = std::time(nullptr);
    return std::ctime(&now);
}
