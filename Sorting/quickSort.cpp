void quickSort(vector<int>& nums,int l,int r){
        if(l<r){
            int m=partition(nums,l,r);
            quickSort(nums,l,m-1);
            quickSort(nums,m+1,r);
        }
    }

int partition(vector<int>& nums,int l,int r){
         int pivot=nums[l];
         int left=l,right=r;
         while(left<=right){
             if(nums[left]>pivot&&nums[right]<=pivot){
                 swap(nums[left],nums[right]);
             }
             if(nums[left]<=pivot){
                 left++;
             }
             if(nums[right]>pivot){
                 right--;
             }
         }
         swap(nums[l],nums[right]);
         return right;
    }
