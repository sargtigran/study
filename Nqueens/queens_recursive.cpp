
#include <array>
#include <iostream>


// Type definitions
using IndexType = size_t;

template <size_t N> using _Board = std::array<std::array<bool, N>, N>;
using Board = _Board<30>;

std::ostream& operator << (std::ostream& out, const Board& b) 
{
    for (auto v : b) {
        for (auto e : v) {
            out << e << " ";
        }
        out << std::endl;
    }
    return out;
}

bool IsFieldAvailable(const Board& board, IndexType i, IndexType j)
{
    for (int k = i; k >= 0; --k) {
        if (board[k][j]) return false;
    }

    for (int k = i, l = j; k >= 0 && l < board.size(); --k, ++l) {
        if (board[k][l]) return false;
    }

    for (int k = i, l = j; k >= 0 && l >= 0; --k, --l) {
        if (board[k][l]) return false;
    }

    return true;
}

bool PlaceQueens(Board& board, IndexType i)
{
    if (i == board.size()) {
        return true;
    }

    int j = 0;
    while (j < board.size()) {
        if (IsFieldAvailable(board, i, j)) {
            board[i][j] = true;
            if (PlaceQueens(board, i + 1)) {
                return true;
            }
            board[i][j] = false;
        }
        ++j;
    }
    return false;
}

int main ()
{
    Board board;
    for (auto& v : board) {
        v.fill(false);
    }

    if (PlaceQueens(board, 0)) {
        std::cout << board ;
    } else {
        std::string n = std::to_string(board.size());
        std::cout << "Error: There is no solution for " + n + " queens on " + n + "x" + n + " board!" << std::endl;
    }
    return 0;
} 
