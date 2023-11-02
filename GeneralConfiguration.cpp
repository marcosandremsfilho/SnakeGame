  #include "snakegame.h"
  // #include "game.cpp"
  enum BINDING {W, A, S, D, ENTER};
  char campo[MAXCIMA][MAXLADO];
  int cursor = 0;

  void gera()
  {
    for(int i = 0; i<= MAXCIMA; i++)
    {
      for(int j = 0; j<= MAXLADO; j++)
      {
        campo[i][j] = ' ';
        if(j == 0 || j == MAXLADO) campo[i][j] = muros;
        else if(i == 0 || i == MAXCIMA ) campo[i][j] = muros;
      }
    }
  }

  void iniciaCampo()
  {
    system("cls");
    for(int i = 0; i<= MAXCIMA; i++)
    {
      for(int j = 0; j<= MAXLADO; j++)
      {
      cout << campo[i][j];
      if (j == MAXLADO) cout << "\n";
      }
    }
  }

  void logo()
  {
    int k = -1;
    string linha1 = "SNAKE GAME BY MARCOS ANDRE";

    for(int i =  meioY - 10; i <= MAXCIMA - 1 ; i++){
      for(int j = meioX - 10;  j <=  MAXLADO - 1 ; j++){
        if (i == meioY- 2 && j <= meioX +5 && j >= meioX - 4) {
          k++;
          campo[i][j] = linha1[k];
          Sleep(TEMPO_INITIAL_MENU);
          iniciaCampo();
        } else if (i == meioY - 1 && j<= meioX + 1 && j >= meioX - 1) {
          k++;
          campo[i][j] = linha1[k];
          Sleep(TEMPO_INITIAL_MENU);
          iniciaCampo();
        } else if (i == meioY && j<= meioX + 6 && j >= meioX - 6) {
          k++;
          campo[i][j] = linha1[k];
          Sleep(TEMPO_INITIAL_MENU);
          iniciaCampo();
        }
      }
    }
  }

  void apaga()
  {
    for(int i = MAXCIMA - 1; i >= meioY - 2 ; i--)  {
      for(int j = MAXLADO - 1 ;  j >= meioX - 6; j--)    {
        if(i == meioY - 2 && j >= meioX - 4 && j <= meioX + 5){
          campo[i][j] = ' ';
          iniciaCampo();
        } else if(i == meioY - 1 && j >= meioX && j <= meioX + 2){
          campo[i][j] = ' ';
          iniciaCampo();
        } else if(i == meioY && j >= meioX - 6 && j <= meioX + 7){
          campo[i][j] = ' ';
          iniciaCampo();
        }
      }
    }
  }

  void IniciaMenu(){
    int k = -1;
    string frase1 = " - MENU - ";
    string start = " START ";
    string options = " OPTIONS ";
    string credits = " CREDITS ";
    for(int i =  meioY - 10; i <= MAXCIMA - 1 ; i++){
      for(int j = meioX - 10;  j <=  MAXLADO - 2 ; j++){
        if (i == meioY - 5 && j <= meioX + 4 && j >= meioX - 4){
          k++;
          campo[i][j] = frase1[k];
          Sleep(TEMPO_MENU);
          iniciaCampo();
          if( j == meioX + 4) k = 0;
        }
        if (i == meioY && j <= meioX + 2 && j >= meioX - 2){
          k++;
          campo[i][j] = start[k];
          Sleep(TEMPO_MENU);
          iniciaCampo();
          if( j == meioX + 2) k = 0;
        }
        if (i == meioY + 2 && j <= meioX + 3 && j >= meioX - 3){
          k++;
          campo[i][j] = options[k];
          Sleep(TEMPO_MENU);
          iniciaCampo();
          if( j == meioX + 3) k = 0;
        }

        if (i == meioY + 4 && j <= meioX + 3 && j >= meioX - 3){
          k++;
          campo[i][j] = credits[k];
          Sleep(TEMPO_MENU);
          iniciaCampo();
          if( j == meioX + 3) k = 0;
        }
      }
    }
  }

  void menu(){
    int k = -1;
    string frase1 = " - MENU - ";
    string start = " START ";
    string options = " OPTIONS ";
    string credits = " CREDITS ";
    for(int i =  meioY - 10; i <= MAXCIMA - 1 ; i++){
      for(int j = meioX - 10;  j <=  MAXLADO - 2 ; j++){
        if (i == meioY - 5 && j <= meioX + 4 && j >= meioX - 4){

          k++;
          campo[i][j] = frase1[k];
          if( j == meioX + 4) k = 0;
        } else if (i == meioY && j <= meioX + 2 && j >= meioX - 2){
          k++;
          campo[i][j] = start[k];
          if( j == meioX + 2) k = 0;
        } else if (i == meioY + 2 && j <= meioX + 3 && j >= meioX - 3){
          k++;
          campo[i][j] = options[k];
          if( j == meioX + 3) k = 0;
        } else if (i == meioY + 4 && j <= meioX + 3 && j >= meioX - 3){
          k++;
          campo[i][j] = credits[k];
          if( j == meioX + 3) k = 0;
        }
      }
    }
    iniciaCampo();
  }

  void credits(){
    logo();
    Sleep(500);
    apaga();
  }

  void menu_pointer(int index_number){
    if (index_number == 1){
      campo[meioY][meioX - 4] = '>';
      campo[meioY + 2][meioX - 6] = ' ';
      campo[meioY + 4][meioX - 5] = ' ';
    } else if (index_number == 2){
      campo[meioY][meioX - 4] = ' ';
      campo[meioY + 4][meioX - 5] = ' ';
      campo[meioY + 2][meioX - 6] = '>';
    } else if (index_number == 3){
      campo[meioY][meioX - 4] = ' ';
      campo[meioY + 2][meioX - 6] = ' ';
      campo[meioY + 4][meioX - 5] = '>';
    }

    menu();
  }

  int get_key(){
    char key = ' ';
    do{
      key = getch();
      if (key == 119 || key == 87){
        return W;
      } else if(key == 115 || key == 83){
        return S;
      } else if(key == 97 || key == 65){
        return A;
      } else if(key == 100 || key == 68){
        return D;
      } else if (key == 13){
        return ENTER;
      }
    }while(key == ' ');

    return key;
  }

  int get_menu_position(int  last_pointer, int cmd_index){
    if (last_pointer == 1 && cmd_index == S) return 2;
    if (last_pointer == 2 && cmd_index == W) return 1;
    if (last_pointer == 2 && cmd_index == S) return 3;
    if (last_pointer == 3 && cmd_index == W) return 2;

    if (cmd_index == ENTER) {
      return 4;
    }
    return last_pointer;
  } 

  void escolha(){
    int key;
    int pointer = 1;
    do{
      menu_pointer(pointer);
      key = get_key();
      pointer = get_menu_position(pointer, key);
    }while(pointer != ENTER); 
  }
