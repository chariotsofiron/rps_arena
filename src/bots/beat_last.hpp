#pragma once

#include <optional>
#include "../bot.hpp"
#include "../move.hpp"

class BeatLast : public Bot {
   public:
    virtual Move get_move(const std::optional<Move> last_move) {
        if (last_move.has_value()) {
            return beats(last_move.value());
        } else {
            return Move::ROCK;
        }
    }
    virtual std::string name() { return "BeatLast"; }
};