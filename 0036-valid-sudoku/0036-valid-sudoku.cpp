// Algo covers in 6 steps and concept of this question is Hashing + 2D Matrix Traversal
// 1. Create three 2D arrays to track digits already seen in each row, column, and 3x3 box.
// 2. Traverse every cell of the 9x9 Sudoku board.
// 3. Skip the cell if it contains an empty character '.'.
// 4. Convert the digit into an index from 0 to 8 and calculate its 3x3 box index.
// 5. If the digit already exists in the same row, column, or box, return false; otherwise, mark it as seen.
// 6. If all cells are checked without conflicts, return true.
//here is the code 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '1';
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rows[i][num] ||
                    cols[j][num] ||
                    boxes[boxIndex][num]) {
                    return false;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};