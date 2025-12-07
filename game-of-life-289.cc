// Emulation
//
// In order to update in-place, encode the previous live status to bit 0 and
// the next generation live status to bit 1.
//
// Implementation Notes:
// - Iterate through the eight directions and exclude invalid directions.
class Solution {
private:
    bool should_live(vector<vector<int>> &board, int i, int j) {
        int lives = 0;
        int live_in_next_generation = 0;
        for (int x = i-1; x <= i+1; x++) {
            if (x < 0 || x >= board.size()) {
                continue;
            }
            for (int y = j-1; y <= j+1; y++) {
                if (y < 0 || y >= board[i].size()) {
                    continue;
                }
                if (i == x && j == y) {
                    continue;
                }
                if (board[x][y] & 1) {
                    lives++;
                }
            }
        }
        if (board[i][j] & 1) {
            return lives == 3 || lives == 2;
        }
        return lives == 3;

    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (should_live(board, i, j)) {
                    board[i][j] |= 1 << 1;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
