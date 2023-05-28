// returns the list of prime numbers upto N

 vector<int> sieve(int N)
    {
        vector<bool> prime(N+1,true);
        vector<int> result;
        int p=2;
        while(p*p<=N)
        {    
            if(prime[p]==true){
             result.push_back(p);
              for(int i=2;p*i<=N;i++)
              {
                  prime[p*i]=false;
              }  
            }
             p++;
        }
        while(p<=N){
            if(prime[p]==true){
                result.push_back(p);
            }
            p++;
        }
        return result;
    }
