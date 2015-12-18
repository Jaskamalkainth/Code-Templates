const int maxN = 1e6+7;
ll  mobius[maxN];

void mob()
{
    mobius[1] = 1;
    for (int i = 2; i < maxN; i++)
    {
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j != 0)
                continue;
            mobius[i] -= mobius[j];
            if (i != j * j && j != 1)
                mobius[i] -= mobius[i / j];
        }
    }
}

