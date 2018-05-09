bool isSubsetSum(int coins[], int soma, int M)
{
    bool *possible = new bool[soma + 1]();
    possible[0] = true;
    for (int c = 0; c < M; c++)
    {
        for (int i = soma - coins[c]; i >= 0; i--)
        {
            if (possible[i])
            {
                possible[i + coins[c]] = true;
            }
        }
    }
    return possible[soma];
}
