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
  } else {
    return false;
  }
}

bool CheckWinCondition(char board[9], char &x, char &o) {
  if (board[0] == x && board[1] == x && board[2] == x
    || board[0] == o && board[1] == o && board[2] == o)
    return true;

  if (board[3] == x && board[4] == x && board[5] == x
    || board[3] == o && board[4] == o && board[5] == o)
    return true;

  if (board[6] == x && board[7] == x && board[8] == x
    || board[6] == o && board[7] == o && board[8] == o)
    return true;

  if (board[0] == x && board[3] == x && board[6] == x
    || board[0] == o && board[3] == o && board[6] == o)
    return true;

  if (board[1] == x && board[4] == x && board[7] == x
    || board[1] == o && board[4] == o && board[7] == o)
    return true;

  if (board[2] == x && board[5] == x && board[8] == x
    || board[2] == o && board[5] == o && board[8] == o)
    return true;

  if (board[0] == x && board[4] == x && board[8] == x
    || board[0] == o && board[4] == o && board[8] == o)
    return true;

  if (board[2] == x && board[4] == x && board[6] == x
    || board[2] == o && board[4] == o && board[6] == o)
    return true;

  return false;
}

void StartGame(char board[9], char &player_x, char &player_o) {
  while (true) {
    DrawBoard(board);

    int move;

    std::cout << "Vez do Jogador X\n";
    std::cout << "Escolha um movimento entre 1-9: ";
    std::cin >> move;
    move--;

    while (board[move] != ' ' || move < 0 || move > 8 || !isalnum(move)) {
      std::cout << "Lance invalido! Tente novamente: ";
      std::cin >> move;
      move--;
    }
    board[move] = player_x;

    DrawBoard(board);

    if (CheckWinCondition(board, player_x, player_o)) {
      std::cout << "Jogador X venceu!\n";
      break;
    } else if (CheckDraw(board)) {
      std::cout << "Empate!\n";
      break;
    }

    std::cout << "Vez do Jogador O\n";
    std::cout << "Escolha um movimento entre 1-9: ";
    std::cin >> move;
    move--;

    while (board[move] != ' ' || move < 0 || move > 8 || !isalnum(move)) {
      std::cout << "Lance invalido! Tente novamente: ";
      std::cin >> move;
      move--;
    }
    board[move] = player_o;

    if (CheckWinCondition(board, player_x, player_o)) {
      DrawBoard(board);
      std::cout << "Jogador O venceu\n";
      break;
    } else if (CheckDraw(board)) {
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
