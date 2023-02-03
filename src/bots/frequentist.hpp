#pragma once

#include "../move.hpp"
#include "../bot.hpp"

class Frequentist : public Bot {
   private:
    std::array<uint32_t, 3> counts = {0, 0, 0};

   public:
    virtual Move get_move(const std::optional<Move> last_move) {
        if (last_move.has_value()) {
            counts[static_cast<int>(last_move.value())]++;
        }
        // get the most frequent move
        Move max = Move::ROCK;
        for (size_t i = 0; i < counts.size(); i++) {
            if (counts[i] > counts[max]) {
                max = static_cast<Move>(i);
            }
        }
        return beats(max);
    }
    virtual std::string name() { return "Frequentist"; }
};