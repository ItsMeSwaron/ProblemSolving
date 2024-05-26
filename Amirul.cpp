#include<bits/stdc++.h>
int Days (int a[],int n, int cap){
    int days = 1, load = 0;
    for(int i = 0; i<n;i++){
        if(a[i] + load > cap){
            days++;
            load = a[i];
        }
        else{
            load += a[i]; 
        }
    }
    return days;
}
int minimumWeightCapacity(int a[],int n, int max, int sum, int d){
    int low = max;
    int high = sum;
    while(low<=high){
        int mid = (low+high)/2;
        int numofDays = Days(a,n,mid);
        if(numofDays <= d){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n = 3;
    int arr[n] = {9,8,10};
    int D = 3;
    int sum = 0;
    int max = 0;
    for(int i = 0;i<n;i++){
        sum+= arr[i];
        if(max < arr[i]){
            max = arr[i];
        }
    }
    int minimumCapacity = minimumWeightCapacity(arr,n,max,sum,D);
    std :: cout<<"Minimum Capacity Of Boat To Ship Weights In "<< D <<" Days Should Be: "<< minimumCapacity <<"\n\n";
}