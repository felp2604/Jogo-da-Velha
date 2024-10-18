#include <iostream>

void DrawBoard(char board[9]) {
  std::cout << '\n';
  std::cout << board[0] << " | " << board[1] << " | " << board[2] << '\n';
  std::cout << "---------\n";
  std::cout << board[3] << " | " << board[4] << " | " << board[5] << '\n';
  std::cout << "---------\n";
  std::cout << board[6] << " | " << board[7] << " | " << board[8] << '\n';
}

bool CheckDraw(char board[9]) {
  int temp = 0;
  for (int i = 0; i < 9; i++) {
    if (board[i] == 'X' || board[i] == 'O') {
      temp++;
    }
  }
  if (temp == 9) {
    return true;
  }
   else {
    return false;
  }
}

bool CheckWinCondition(char board[9], char &player) {
  if (board[0] == player && board[1] == player && board[2] == player)
    return true;

  if (board[3] == player && board[4] == player && board[5] == player)
    return true;

  if (board[6] == player && board[7] == player && board[8] == player)
    return true;

  if (board[0] == player && board[3] == player && board[6] == player)
    return true;

  if (board[1] == player && board[4] == player && board[7] == player)
    return true;

  if (board[2] == player && board[5] == player && board[8] == player)
    return true;

  if (board[0] == player && board[4] == player && board[8] == player)
    return true;

  if (board[2] == player && board[4] == player && board[6] == player)
    return true;

  return false;
}

void GetMove(char board[9], char &player) {
    int move;
    std::cout << "Vez do Jogador " << player << "\n";
    std::cout << "Escolha um movimento entre 1-9: ";
    std::cin >> move;
    while (board[move-1] != ' ' || move < 1 || move > 9) {
        std::cout << "Lance invalido! Tente novamente: ";
        std::cin >> move;
    }
    move--;
    board[move] = player;
}

void StartGame(char board[9], char &player_x, char &player_o) {
  while (true) {
    DrawBoard(board);

    GetMove(board, player_x);

    DrawBoard(board);

    if (CheckWinCondition(board, player_x)) {
      std::cout << "Jogador X venceu!\n";
      break;
    } else if (CheckDraw(board)) {
      std::cout << "Empate!\n";
      break;
    }

    GetMove(board, player_o);

    if (CheckWinCondition(board, player_o)) {
      DrawBoard(board);
      std::cout << "Jogador O venceu\n";
      break;
    }
    else if (CheckDraw(board)) {
      std::cout << "Empate!\n";
      break;
    }
  }
}

int main() {
  char player_x = 'X';
  char player_o = 'O';

  char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  StartGame(board, player_x, player_o);
}
