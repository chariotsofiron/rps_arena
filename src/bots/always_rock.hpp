#pragma once

#include "../bot.hpp"

class AlwaysRock : public Bot {
   public:
    virtual Move get_move(const std::optional<Move> last_move) { return Move::ROCK; }
    virtual std::string name() { return "AlwaysRock"; }
};
