#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>&arr,int n){
 for(int i =0;i<n-1;i++){
        int minIndex = i;
    for(int j = i+1;j<n;j++){
        if(arr[minIndex]>arr[j]){
            minIndex = j;
        }
    }
    swap(arr[minIndex],arr[i]);
  }

  for(auto it :arr){
    cout<<it<<" ";
  }
}

void BubbleSort(vector<int>&arr,int n){
  for(int i = n-1;i>=0;i--){
    cout<<"Paas"<<endl;
    for(int j = 0;j<=i-1;j++){
        cout<<"comparison"<<endl;
        if(arr[j]>arr[j+1]){
            cout<<"Here swaped"<<endl;
            swap(arr[j],arr[j+1]);
        }
    }
  }


    for(auto it : arr){
    cout<<it<<" ";
  }
}

void InsertionSort(vector<int>&arr,int n){
  for(int i =0;i<n;i++){
    int j =i;
    while(j> 0 && arr[j-1]>arr[j]){
        swap(arr[j-1],arr[j]);
        j--;
    }
  }

      for(auto it : arr){
    cout<<it<<" ";
  }
}
void merge(vector<int>&arr,int low , int mid,int high){
  vector<int>temp;

  int left = low;
  int right = mid +1;
  while(left <=mid && right <=high){
    if(arr[left]<=arr[right]){
        temp.push_back(arr[left]);
        left++;
    }else{
       temp.push_back(arr[right]);
       right++;
    }
  }

  while(left<=mid){
    temp.push_back(arr[left]);
    left++;
  }
  while(right<=high){
    temp.push_back(arr[right]);
    right++;
  }

  for(int i = low;i<=high;i++){
    arr[i] = temp[i - low];
  }
}


void mergeSort(vector<int>&arr,int low ,int high){
    if(high == low) return;
    int mid = (low + high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
  vector<int> arr = {5,3,7,2,9,1};
  int n = arr.size();

  //selectionSort(arr,n);
  //BubbleSort(arr,n);
  //InsertionSort(arr,n);

  mergeSort(arr,0,5);

  for(auto it : arr){
    cout<<it<<" ";
  }
}
