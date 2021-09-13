#include "snakegame.h"

char campo[MAXCIMA][MAXLADO];

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
      else if (i == meioY - 1 && j<= meioX + 2 && j >= meioX)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY && j<= meioX + 7 && j >= meioX - 5)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY + 1 && j<= meioX + 3 && j >= meioX)
      {

        k++;
        campo[i][j] = linha1[k];
        Sleep(TEMPO);
        iniciaCampo();

      }
      else if (i == meioY + 2 && j<= meioX + 7 && j >= meioX - 4)
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
  for(int i = MAXCIMA - 1; i >= meioY - 2 ; i--)
  {
    for(int j = MAXLADO - 1 ;  j >= meioX - 6; j--)
    {
      if(i == meioY - 2 && j >= meioX - 4 && j <= meioX + 6)
      {
       campo[i][j] = ' ';
       Sleep(TEMPO);
       iniciaCampo();
     }
    else if(i == meioY - 1 && j >= meioX && j <= meioX + 2)
     {
      campo[i][j] = ' ';
      Sleep(TEMPO);
      iniciaCampo();
    }
    else if(i == meioY && j >= meioX - 6 && j <= meioX + 7)
    {
     campo[i][j] = ' ';
     Sleep(TEMPO);
     iniciaCampo();
    }
    else if(i == meioY + 1 && j >= meioX && j <= meioX + 3)
    {
      campo[i][j] = ' ';
      Sleep(TEMPO);
      iniciaCampo();
    }
    else if(i == meioY + 2 && j >= meioX - 4 && j <= meioX + 7)
    {
      campo[i][j] = ' ';
      Sleep(TEMPO);
      iniciaCampo();
    }
  }

  }
}

void menu()
{

}
