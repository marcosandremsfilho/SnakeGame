#include "snakegame.h"

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
  string linha1 = "SNAKE GAME BY MARCOS ANDRE AND JOAO TADINI";

  for(int i =  meioY - 10; i <= MAXCIMA - 1 ; i++)
  {
    for(int j = meioX - 10;  j <=  MAXLADO - 1 ; j++)
    {
      if (i == meioY- 2 && j <= meioX +5 && j >= meioX - 4)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY - 1 && j<= meioX + 1 && j >= meioX - 1)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY && j<= meioX + 6 && j >= meioX - 6)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY + 1 && j<= meioX + 2 && j >= meioX-1)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY + 2 && j<= meioX + 6 && j >= meioX - 5)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
    }
  }
}

void apaga()
{
  int TEMPO2 = TEMPO - 45;
  for(int i = MAXCIMA - 1; i >= meioY - 2 ; i--)
  {
    for(int j = MAXLADO - 1 ;  j >= meioX - 6; j--)
    {
      if(i == meioY - 2 && j >= meioX - 4 && j <= meioX + 5)
      {
        campo[i][j] = ' ';
        iniciaCampo();
      }
      else if(i == meioY - 1 && j >= meioX && j <= meioX + 2)
      {
        campo[i][j] = ' ';
        iniciaCampo();
      }
      else if(i == meioY && j >= meioX - 6 && j <= meioX + 7)
      {
        campo[i][j] = ' ';
        iniciaCampo();
      }
      else if(i == meioY + 1 && j >= meioX && j <= meioX + 3)
      {
        campo[i][j] = ' ';
        iniciaCampo();
      }
      else if(i == meioY + 2 && j >= meioX - 6 && j <= meioX + 6)
      {
        campo[i][j] = ' ';
        iniciaCampo();
      }
    }
  }
}

void IniciaMenu()
{
  int k = -1;
  string frase1 = " - MENU - ";
  string start = " START ";
  string options = " OPTIONS ";
  string credits = " CREDITS ";
  int t = TEMPO - 25;
  for(int i =  meioY - 10; i <= MAXCIMA - 1 ; i++)
  {
    for(int j = meioX - 10;  j <=  MAXLADO - 2 ; j++)
    {
      if (i == meioY - 5 && j <= meioX + 4 && j >= meioX - 4)
      {

        k++;
        campo[i][j] = frase1[k];
        Sleep(t);
        iniciaCampo();
        if( j == meioX + 4) k = 0;
      }

      if (i == meioY && j <= meioX + 2 && j >= meioX - 2)
      {

        k++;
        campo[i][j] = start[k];
        Sleep(t);
        iniciaCampo();
        if( j == meioX + 2) k = 0;

      }

      if (i == meioY + 2 && j <= meioX + 3 && j >= meioX - 3)
      {

        k++;
        campo[i][j] = options[k];
        Sleep(t);
        iniciaCampo();
        if( j == meioX + 3) k = 0;

      }

      if (i == meioY + 4 && j <= meioX + 3 && j >= meioX - 3)
      {

        k++;
        campo[i][j] = credits[k];
        Sleep(t);
        iniciaCampo();
        if( j == meioX + 3) k = 0;

      }
    }
  }
}

void menu()
{
  int k = -1;
  string frase1 = " - MENU - ";
  string start = " START ";
  string options = " OPTIONS ";
  string credits = " CREDITS ";
  for(int i =  meioY - 10; i <= MAXCIMA - 1 ; i++)
  {
    for(int j = meioX - 10;  j <=  MAXLADO - 2 ; j++)
    {
      if (i == meioY - 5 && j <= meioX + 4 && j >= meioX - 4)
      {

        k++;
        campo[i][j] = frase1[k];
        if( j == meioX + 4) k = 0;
      }

      else if (i == meioY && j <= meioX + 2 && j >= meioX - 2)
      {

        k++;
        campo[i][j] = start[k];
        if( j == meioX + 2) k = 0;

      }

      else if (i == meioY + 2 && j <= meioX + 3 && j >= meioX - 3)
      {

        k++;
        campo[i][j] = options[k];
        if( j == meioX + 3) k = 0;

      }

      else if (i == meioY + 4 && j <= meioX + 3 && j >= meioX - 3)
      {

        k++;
        campo[i][j] = credits[k];
        if( j == meioX + 3) k = 0;

      }
    }
  }
  iniciaCampo();
}

void credits()
{
  logo();
  Sleep(500);
  apaga();
}

void escolha()
{
  char k;
  int aux;

  aux = 1;

  menu();
  do
  {
    switch (aux) {
      case 1:
      campo[meioY][meioX - 4] = '>';
      campo[meioY + 4][meioX - 5] = ' ';
      campo[meioY + 2][meioX - 5] = ' ';
      menu();

      k = getch();
      if(k == 'w')
      {
        aux--;
        if(aux == 0) aux = 3;

      }
      else if(k == 's')
      {
        aux ++;
        if(aux == 4) aux = 1;
      }

        break;

      case 2:
        campo[meioY][meioX - 4] = ' ';
        campo[meioY + 4][meioX - 5] = ' ';
        campo[meioY + 2][meioX - 5] = '>';
        menu();
        k = getch();
        if(k == 'w')
        {
          aux--;
          if(aux == 0) aux = 3;

        }
        else if(k == 's')
        {
          aux ++;
          if(aux == 4) aux = 1;
        }
        break;

      case 3:

      campo[meioY][meioX - 4] = ' ';
      campo[meioY + 4][meioX - 5] = '>';
      campo[meioY + 2][meioX - 5] = ' ';
        menu();
        k = getch();
        if(k == 'w')
        {
          aux--;
          if(aux == 0) aux = 3;

        }
        else if(k == 's')
        {
          aux ++;
          if(aux == 4) aux = 1;
        }
        else if(k == '\n') credits();

        break;

    }


  }while(k != '4');
}
