#define MAX 210

int numbers, M, D, total_queries;
int arr[MAX], memo[MAX][MAX][15];

int dp(int i, int sum, int c)
{
    if(c == M && sum == 0)
        return 1;
    if(c == M && sum != 0)
        return 0;
    if(i == numbers)
        return 0;
    if(memo[i][sum][c] != -1)
        return memo[i][sum][c];

    memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+arr[i])%D, c+1);

    return memo[i][sum][c];
}

int main()
{
    int i, j, res;

    j = 1;
    while(1)
    {
        scanf("%d %d", &numbers, &total_queries);

        if(numbers == 0 && total_queries == 0)
            break;

        for(i = 0; i < numbers; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("SET %d:\n", j);

        for(i = 0; i < total_queries; i++)
        {
            scanf("%d %d", &D, &M);
            memset(memo, -1, sizeof(memo));
            res = dp(0, 0, 0);
            printf("QUERY %d: %d\n", i+1, res);
        }
        j++;
    }
    return 0;
}
