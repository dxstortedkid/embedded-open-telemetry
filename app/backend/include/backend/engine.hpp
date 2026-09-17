#pragma once
#include "common/shared_context.hpp"
#include <stop_token>

class BackendEngine {
public:
    void run(std::stop_token st, SharedContext& ctx);
};