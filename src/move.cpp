#include "move.hpp"

auto beats(Move move) -> Move {
    switch (move) {
        case Move::ROCK:
            return Move::PAPER;
        case Move::PAPER:
            return Move::SCISSORS;
        case Move::SCISSORS:
            return Move::ROCK;
    }
}