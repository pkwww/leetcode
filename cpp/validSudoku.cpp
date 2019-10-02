#include <vector>
#include <iostream>
using namespace std;
class Solution {
  using Board = vector<vector<char>>;

private:
  bool isVecUnique(vector<int> &v) {
    // 1-9
    vector<int> counter(9, 0);
    for (int value : v) {
      cout << "[";
      for (auto c: counter) {
        cout << c << ", ";
      }
      cout << "]" << endl;
      int counter_index = value - 1;
      if (counter[counter_index] != 0) {
        cout << endl << "wtf: " << value << endl;
        return false;
      }
      counter[counter_index] = 1;
    }
    return true;
  }

  bool validRow(Board &board, int row) {
    cout << "row: " << row << endl;
    vector<int> numInRow{};
    for (int j = 0; j < 9; j++) {
      char curr_char = board[row][j];
      if (curr_char == '.') {
        continue;
      }
      numInRow.push_back(curr_char - '0');
    }
    cout << "row content: [";
    for (int r: numInRow) {
      cout << r << ", ";
    }
    cout << "]" << endl;
    return isVecUnique(numInRow);
  }

  bool validCol(Board &board, int col) {
    cout << "col: " << col << endl;
    vector<int> numInCol{};
    for (int i = 0; i < 9; i++) {
      char curr_char = board[i][col];
      if (curr_char == '.') {
        continue;
      }
      numInCol.push_back(curr_char - '0');
    }
    cout << "col content: [";
    for (int r: numInCol) {
      cout << r << ", ";
    }
    cout << "]" << endl;
    return isVecUnique(numInCol);
  }

  bool validSubbox(Board &board, int subboxRow, int subboxCol) {
    cout << " Hello ?" << endl;
    int subboxRowOffset = subboxRow * 3;
    int subboxColOffset = subboxCol * 3;
    vector<int> numInSubbox{};
    for (int k = 0; k < 3; k++) {
      for (int l = 0; l < 3; l++) {
        cout << "row: " << k + subboxRowOffset << ";;; col: " << l + subboxColOffset << endl;
        char curr_char = board[k + subboxRowOffset][l + subboxColOffset];
        if (curr_char == '.') {
          continue;
        }
        numInSubbox.push_back(curr_char - '0');
      }
    }
    return isVecUnique(numInSubbox);
  }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      if (!validRow(board, i)) {
        return false;
      }
    }

    for (int j = 0; j < 9; j++) {
      if (!validCol(board, j)) {
        return false;
      }
    }

    for (int k = 0; k < 3; k++) {
      for (int l = 0; l < 3; l++) {
        if (!validSubbox(board, k, l)) {
          return false;
        }
      }
    }

    return true;
  }
};
