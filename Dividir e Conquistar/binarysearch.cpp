#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vetor;

binarySearch(int x, int b, int e, vetor &v){

    int inicio = b;
    int fim = e;
    int middle;

    if (inicio > fim) return -1;
    else {
        middle = (inicio + fim)/2;
        if (v[middle] == x) return middle;
        if (v[middle] < x)
            return binarySearch(x, middle + 1, fim, v);
        else
            return binarySearch(x, inicio, middle - 1, v);
    }
}

int main(){

    int n;
    int n_qqueroachar;
    int foi;

    printf("quantos numeros no vetor?\n");
    scanf("%d", &n);
    vector<int> v(n);

    printf("\nquais valores no vetor?\n");
    for (int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());
    printf("\nesse é o seu vetor ordenado:\n");
    for (int i = 0; i < n; ++i){
        printf("%d", v[i]);
    }

    printf("\nqual numero vc quer procurar?\n");
    scanf("%d", &n_qqueroachar);

    foi = binarySearch(n_qqueroachar, 0, n, v);

    if (foi == -1){
        //nao achou
        printf("\n\nnao foi");
    } else {
        //achou
        printf("\n\nfoi");
    }

}
