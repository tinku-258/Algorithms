// returns the list of prime numbers upto N

vector<int> sieve(int N)
    {
        vector<bool> prime(N+1,true);
        vector<int> result;
        int p=2;
        while(p*p<=N)
        {
              for(int i=2;p*i<=N;i++)
              {
                  prime[p*i]=false;
              }
              p++;
              while(prime[p]==false)
                p++;
        }
        for(int i=2;i<=N;i++)
        {
            if(prime[i]==true)
              result.push_back(i);
        }
        return result;
    }
