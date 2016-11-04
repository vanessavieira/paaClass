#include <bits/stdc++.h>
using namespace std;

typedef char matrix[200][200];

int coluna_atual;
#define MAX_COL_LINE 50

int isAnswer( matrix v, int il, int fl, int ic, int fc )
{
    int type = v[il][ic];
    for( int i = il ; i < fl ; ++i )
    {
      for( int j = ic ; j < fc ; ++j )
      {
        if( v[i][j] != type )
        {
          return 0;
        }
      }
    }
  return 1;
}
void verificacaoParticao(matrix v, int il, int fl, int ic, int fc)
{
        if(  il == fl || ic == fc )
        {
          // Fora da matriz
          return;
        }
        else if( isAnswer( v , il, fl, ic, fc ) )
        {
            // Matriz igual
            printf("%c", v[il][ic]);
            ++coluna_atual;
            if( coluna_atual == 50 )
            {
              printf("\n");
              coluna_atual = 0;
            }
        }
        else
        {
            printf("D");
            ++coluna_atual;
            if( coluna_atual == 50 )
            {
              printf("\n");
              coluna_atual = 0;
            }
            int meio_coluna = ceil((ic + fc) / 2.0);
            int meio_linha = ceil((il + fl) / 2.0);
            verificacaoParticao(v, il, meio_linha, ic, meio_coluna); //1 quadrante
            verificacaoParticao(v, il, meio_linha, meio_coluna, fc); //2 quadrante
            verificacaoParticao(v, meio_linha, fl, ic, meio_coluna); //3 quadrante
            verificacaoParticao(v, meio_linha, fl, meio_coluna, fc); //4 quadrante
        }
}

int main()
{
    matrix v;
    int n_casos, n_linhas, n_colunas;

    scanf("%d", &n_casos);

    for (int i = 0; i < n_casos; ++i)
    {
        scanf ("%d%d", &n_linhas, &n_colunas);

        for (int k = 0; k < n_linhas; ++k)
        {
            getchar();
            for (int j = 0; j < n_colunas; ++j)
            {
                scanf("%c", &v[k][j]);
            }

        }
        coluna_atual = 0;
        verificacaoParticao(v, 0, n_linhas, 0, n_colunas);
        printf("\n");
    }

    return 0;
}
