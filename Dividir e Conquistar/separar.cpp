#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vetor;

void separa(vetor &a, int b, int numElementos, int *j)
{
	*j = b;
	for (int i = b; i <= numElementos; ++i) {
		if (a[i] < 0) {
			swap(a[*j], a[i]);
			(*j)++;
		}
	}
}

int main() {

    int numElementos, j;

	scanf("%d", &numElementos);

	vector<int> a(numElementos);

	for (int i = 0; i < numElementos; ++i) {
		scanf("%d", &a[i]);
	}

	separa(a, 0, numElementos-1, &j);

	for (int i = 0; i < numElementos; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;

}
