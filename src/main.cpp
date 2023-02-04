#include <fmt/core.h>

#include <array>
#include <iostream>
#include <vector>

#include "bot.hpp"
#include "bots/always_rock.hpp"
#include "bots/beat_last.hpp"
#include "bots/frequentist.hpp"
#include "move.hpp"

/// Returns (draws, player 1 wins, player 2 wins)
auto play_match(Bot& player1, Bot& player2, int n_rounds) -> std::array<uint32_t, 3> {
    std::array<uint32_t, 3> scores = {0, 0, 0};
    std::optional<Move> last_move1;
    std::optional<Move> last_move2;
    for (int i = 0; i < n_rounds; i++) {
        Move move1 = player1.get_move(last_move2);
        Move move2 = player2.get_move(last_move1);
        last_move1 = move1;
        last_move2 = move2;

        if (move1 == move2) {
            scores[0]++;
        } else if (move1 == beats(move2)) {
            scores[1]++;
        } else {
            scores[2]++;
        }
    }
    return scores;
}

constexpr int N_ROUNDS = 1000;

auto main() -> int {
    std::vector<std::unique_ptr<Bot>> bots;
    bots.push_back(std::make_unique<AlwaysRock>());
    bots.push_back(std::make_unique<Frequentist>());
    bots.push_back(std::make_unique<BeatLast>());

    // create a win-matrix
    fmt::print("{:19}", "");  // spacing for bot name
    for (size_t i = 0; i < bots.size(); i++) {
        fmt::print("{:6}", i);
    }
    fmt::print("\n");
    for (size_t i = 0; i < bots.size(); i++) {
        fmt::print("{:>14}: {:3} ", bots[i]->name(), i);
        for (size_t j = 0; j < bots.size(); j++) {
            std::array<uint32_t, 3> scores = play_match(*bots[i], *bots[j], N_ROUNDS);
            fmt::print("{:>5},", scores[1]);
        }
        fmt::print("\n");
    }
}