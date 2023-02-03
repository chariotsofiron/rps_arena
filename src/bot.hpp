#pragma once

#include "move.hpp"
#include <optional>

class Bot {
   public:
    virtual ~Bot() = default;
    virtual auto get_move(std::optional<Move> last_move) -> Move = 0;
    virtual auto name() -> std::string = 0;
};