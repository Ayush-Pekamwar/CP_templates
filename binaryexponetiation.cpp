const int M  = 1e9+7;
long long binpow(long long a, long long b) {
        // calculates a^b % M
        long long res = 1;
        a%=M;
        while (b > 0) {
            if (b & 1)
                res = (res * a)% M;
            a = (a * a)%M;
            b = b>>1;
        }
        return res;
    }
