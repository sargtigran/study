
#include <array>
#include <stack>
#include <iostream>
#include <cassert>
#include <exception>


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

void PlaceQueens(Board& board)
{
    std::stack<std::pair<IndexType, IndexType>> st;
    IndexType i = 0;
    IndexType j = 0;
    IndexType N = board.size();

    while (i < N) {
        while (j < N) {
            if (IsFieldAvailable(board, i, j)) {
                board[i][j] = true;
                st.push({i, j});
                break;
            }
            ++j;
        }

        if (j >= N) {
            if (st.empty()) { 
                std::string n = std::to_string(N);
                throw std::logic_error("There is no solution for " + n + " queens on " + n + "x" + n + " board!");
            }
            i = st.top().first;
            j = st.top().second;
            st.pop();
            board[i][j] = false;
            ++j;
        } else {
            ++i;
            j = 0;
        }
    }
}

int main ()
{
    Board board;
    for (auto& v : board) {
        v.fill(false);
    }

    try {
        PlaceQueens(board);
        std::cout << board ;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
} 
