#include<stdio.h>

int main(){
    int arr[5];
    printf("Enter the array elements one by one");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int temp[n];
    for(int i=0; i<n; i++)
    temp[i] = arr[i];
    
    //sort the copied array
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x = temp[i];
            temp[i] = temp[j];
            temp[j] = x;
        }
    }
    
    for(int i=0; i<n; i++){
    
        for(int j=0; j<n; j++){
            if(temp[j]==arr[i])
            {
                arr[i] = j+1;
                break;
            }
        }
    }
    
    for(int i=0; i<n; i++)
    printf("%d ", arr[i]);
}