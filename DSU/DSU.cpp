class DSU{
  vector<int> parent,size;
  int count;
  public:
      DSU(int n){
          parent.resize(n);
          size.resize(n,1);
          count=n;
          for(int i=0;i<n;i++){
              parent[i]=i;
          }
      }
      int findParent(int node){
           if(parent[node]==node) return node;
           return parent[node]=findParent(parent[node]);
      }
      void unionBySize(int a,int b){
          int Pa=findParent(a);
          int Pb=findParent(b);
          if(Pa==Pb) return;
          if(size[Pa]>size[Pb]){
              parent[Pb]=Pa;
              size[Pa]+=size[Pb];
              size[Pb]=0;
          }
          else{
              parent[Pa]=Pb;
              size[Pb]+=size[Pa];
              size[Pa]=0;
          }
          count--;
      }
    int compo_count(){
        return count;
    }
};
