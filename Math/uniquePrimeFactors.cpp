vector<int> uniquePrimeFactors(int n){
    vector<int> ans;
    if(n%2==0) ans.push_back(2);
    while (n% 2 == 0){
        n/=2;
    }
    for (int i=3;i<=sqrt(n);i+=2){
        bool flag=false;
        while (n % i == 0){
           flag=true;
           n/=i;
        }
        if(flag) ans.push_back(i);
    }
    if (n>1)
        ans.push_back(n);
    return ans;
}
