#include<stdio.h>

void merge(int arr[] ,int mid ,int left ,int right);
void mergesort(int arr[] , int left , int right);
void printarray(int arr[],int n);

int main(){
    int n,i;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter array elements : ");
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered array is ");
    printarray(arr , n);

    mergesort(arr,0,n-1);
    printf("After sorting :");
    printarray(arr ,n);
}

void merge(int arr[] ,int mid ,int left ,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;

    int arrleft[n1],rightarr[n2];

    for(i=0;i<n1;i++){
        arrleft[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        rightarr[j]=arr[mid+1+j];
    }

    i=0;
    j=0;
    k=left;

    while(i<n1 && j<n2){
        if(arrleft[i]<=rightarr[j]){
            arr[k]=arrleft[i];
            i++;
        }
        else{
            arr[k]=rightarr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=arrleft[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[] , int left , int right){

    if(left < right){
        int mid = left + (right-left)/2;

        mergesort(arr ,left ,mid);
        mergesort(arr ,mid+1 ,right);

        merge(arr ,mid ,left ,right);
    }
}


void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
