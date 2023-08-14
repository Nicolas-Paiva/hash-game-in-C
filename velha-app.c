#include <stdio.h>

// 1. Demonstrar o "tabuleiro"
void displayGame(char array[3][3]);

// 2. Coleta input do usuário para linha e coluna e mostra o jogo atualizado
void playX(char array[3][3]);
void playO(char array [3][3]);

// 3. Parando o jogo se alguem vencer
int checkWin(char array[3][3]);

int main(void){

  char velha[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  displayGame(velha);

  for(int i = 1 ; i < 10 ; i++){
    if(i % 2 != 0){
      playX(velha);
    } else {
      playO(velha);
    }
    if(checkWin(velha) == 1){
      break;
    }
  }

  return 0;
}

// Displays the board
void displayGame(char array[3][3]){
  putchar('\n');
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3 ; j++){
      if(j == 1){
        printf("| %c |", array[i][j]);
      } else {
        printf(" %c ", array[i][j]);
      }
    }
    putchar('\n');
    if(i < 2){
    printf(" ---------");
    }
    putchar('\n');
  }
}
  
// Updates the board when the player one plays (Player selects line and column)
void playX(char array[3][3]){
  int line, column;
  printf("Jogador 1, selecione a linha e a coluna (1 - 3): ");
  scanf("%d %d", &line, &column);
  if(array[line - 1][column - 1] == ' '){
    array[line - 1][column - 1] = 'X';
  } else{
    printf("\nPosição inválida, selecione uma posição novamente.\n");
    playX(array);
  }
  displayGame(array);
}

// Updates the board when the player two plays (Player selects line and column)
void playO(char array[3][3]){
  int line, column;
  printf("Jogador 2, selecione a linha e a coluna (1 - 3): ");
  scanf("%d %d", &line, &column);
  if(array[line - 1][column - 1] == ' '){
    array[line - 1][column - 1] = 'O';
  } else{
    printf("\nPosição já ocupada, selecione uma posição novamente.\n");
    playO(array);
  }
  displayGame(array);
} 

int checkWin(char array[3][3]) {
  // Checking row victory:
  for (int i = 0; i < 3; i++) {
    if ((array[i][0] == array[i][1] && array[i][0] == array[i][2]) && array[i][0] != ' ') {
      printf("Jogador %d venceu!\n", array[i][0] == 'X' ? 1 : 2);
      return 1;
    }
  }

  // Checking column victory:
  for (int j = 0; j < 3; j++) {
    if ((array[0][j] == array[1][j] && array[0][j] == array[2][j]) && array[0][j] != ' ') {
      printf("Jogador %d venceu!\n", array[0][j] == 'X' ? 1 : 2);
      return 1;
    }
  }

  // Checking diagonal victory:
  if((array[0][0] == array[1][1] && array[0][0] == array[2][2]) || (array[0][2] == array[1][1] && array[0][2] == array[2][0]) && array[1][1] != ' '){
    printf("Jogador %d venceu!", array[1][1] == 'X' ? 1 : 2);
    return 1;
  }
  return 0;
}


