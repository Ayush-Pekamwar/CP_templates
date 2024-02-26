
// for checking primes , and marking them in a
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


// sieve for calculating number of divisiors
ll divisors[N + 1];
for (int i = 1; i <= n; ++i){
     for (int j = i; j <= n; j += i){
          ++divisors[j];    
     }
}

// sieve for sum of divisors of a number
ll sumdiv[n + 1];
for (int i = 1; i <= n; ++i)
 for (int j = i; j <= n; j += i)
  sumdiv[j] += i;




