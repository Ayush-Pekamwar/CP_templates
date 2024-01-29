const int N = 1e6;
vector<bool> a(N+1, 1);

void sieve()
{
    a[0] = 0;
    a[1] = 0;

    for (ll i = 2; i * i <= N; i++)
    {

        if (a[i] == 1)
        {
            for (ll j = i * i; j <= N; j += i)
            {
                a[j] = 0;
            }
        }
    }
}
