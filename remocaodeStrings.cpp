#include <bits/stdc++.h>
using namespace std;

vector<string> results;
struct indexes {
    int groups_index_i;
    int groups_index_j;
};



int searchString(vector<string> results, string N)
{
    //found
    if (std::find(results.begin(), results.end(), N) != results.end())
    {
        return 1;
    }
    else
    {
        printf("nao achou\n");
        return -1;
    }

}

string concatenate(string n, indexes indices)
{
    string temp;

    for (int i = 0; i < indices.groups_index_i; i++)
    {
        temp.push_back(n[i]);
    }
    for (int j = indices.groups_index_j + 1; j < n.length(); j++)
    {
        temp.push_back(n[j]);
    }
    cout << "concatenado: " << temp << "\n";
    return temp;

  //TOP
}

vector<indexes> findGroup(string N)
{
    vector<indexes> indices;
    indexes new_index;

    int j = 0;
    int k = 0;

    for (int i = 0; i < N.length(); ++i)
    {
        if (N[i] != N[j])
        {
            k = i - 1;
            if (k - j >= 1)
            {
                new_index.groups_index_i = j;
                new_index.groups_index_j = k;
                indices.push_back(new_index);
            }
            j = i;
        }
    }

    return indices;
}


bool backtracking(string n)
{
  // TODO AFTER: VERIFICAR SE JA NAO TEM RESPOSTA NO DP
  // CASO VERDADEIRO: busca o resultado no array
  // CASO FALSO: calcula e faz isso aqui de baixo \/

  vector<indexes> indices = findGroup(n);
  bool result = false;

  for (int i = 0; i < indices.size(); i++) {
    // remove a substring e adiciona
    string nova_string = concatenate(n, indices[i]);
    result = result || backtracking(nova_string);
  }

  // CASO O RESULTADO SEJA VERDADEIRO, ADICIONA STRING NO RESULTS
  return result;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();


    while (T--)
    {
        string N;
        getline(cin, N);

		  bool final_result = backtracking(N);

      if (final_result) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
    return 0;
}
