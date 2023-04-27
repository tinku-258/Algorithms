// A segment tree is a binary tree where each node represents an interval.
//Generally a node would store one or more properties of an interval which can be queried later.

//Object Creation:-segmentTree *st=new segmentTree(n), where n is the size of input array
//st->build(inputArray,0,n-1);
//st->update(0,n-1,position,value);
//st->query(0,n-1,querid Range[left,right]);

class segmentTree{
  private:
     vector<int> tree;
  public:
    segmentTree(int size){
        // segment tree size can go upto 4*n (n=size of the array to be represented by segment tree)
         tree.resize(4*size);
     }
    void build(vector<int>& arr,int low,int high,int ind=0){
           // leaf node.
            if(low==high){
                tree[ind]=arr[low];
                return;
            }
            // build left,right segment
            int mid=low+(high-low)/2;
            build(arr,low,mid,2*ind+1);
            build(arr,mid+1,high,2*ind+2);
            // merge updates
            tree[ind]=tree[2*ind+1]+tree[2*ind+2]; // (depend on the query type(max,min,sum))
     }
    void update(int low,int high,int& pos,int& val,int ind=0){
        // leaf node. update element and return.
          if(low==high){ 
              tree[ind]=val;
              return;
          }
         
         // recurse deeper and update appropriate child
          int mid=low+(high-low)/2;
          if(pos<=mid){
              update(low,mid,pos,val,2*ind+1);
          }
          else{
              update(mid+1,high,pos,val,2*ind+2);
          }
          // merge updates
          tree[ind]=tree[2*ind+1]+tree[2*ind+2];
    }
    int query(int low,int high,int& left,int& right,int ind=0){
        //invalid query or current segment completely outside queried range
         if(left>high||left>high||right<low){ 
             return 0; //return VERY SMALL/LARGE value in case of max/min type query
         }
        // current segment completely inside queried range
        if(left<=low&&right>=high){ 
            return tree[ind];
        }

        // partial overlap of current segment and queried range. Recurse deeper.
        int mid=low+(high-low)/2;
        return query(low,mid,left,right,2*ind+1)+query(mid+1,high,left,right,2*ind+2);
     } 
};
