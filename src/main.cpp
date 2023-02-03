#include <array>
#include <iostream>
#include <vector>

#include "bot.hpp"
#include "bots/always_rock.hpp"
#include "bots/frequentist.hpp"
#include "bots/beat_last.hpp"

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

auto main() -> int {
    std::vector<std::unique_ptr<Bot>> bots;
    bots.push_back(std::make_unique<AlwaysRock>());
    bots.push_back(std::make_unique<Frequentist>());
    bots.push_back(std::make_unique<BeatLast>());

    for (size_t i = 0; i < bots.size(); i++) {
        for (size_t j = i + 1; j < bots.size(); j++) {
            std::array<uint32_t, 3> scores = play_match(*bots[i], *bots[j], 1000);
            std::cout << bots[i]->name() << " vs " << bots[j]->name() << ": " << scores[0]
                      << " draws, " << scores[1] << " wins, " << scores[2] << " losses\n";
        }
    }
}