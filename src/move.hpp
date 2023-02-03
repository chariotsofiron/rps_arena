#pragma once

enum Move {
    ROCK,
    PAPER,
    SCISSORS
};

/// Returns the move that would beat the given move.
auto beats(Move move) -> Move;