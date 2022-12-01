#include <iostream>
using namespace std;

void swapPlace(int list[],int first, int second){

    int temp = list[first];
    list[first]=list[second];
    list[second] = temp;

}
int partition(int list[],int low, int high){
    int pivot = list[low];
    int i  =low+1;
    int j = high;
    while (i<j){
        while(list[i] < pivot){
            i++;
        }
        while(list[j]>pivot){
            j--;
        }
        if(i<j){
            swapPlace(list,i,j);
        }
    }
    swapPlace(list,j,low);
    return j;
}
void quickSort(int list[],int low,int high){
    if(low<high){
        int pivot = partition(list,low,high);
        quickSort(list,low,pivot-1);
        quickSort(list,pivot+1,high);
    }
}
int main(){
    int array[]={1,0,123,55,99,10,2};
    for(int i = 0 ; i<7;i++){
        cout<<"The element is : "<<array[i]<<endl;
    }
    cout<<"The sorted array is:"<<endl;
    quickSort(array,0,6);
    for(int i = 0 ; i<7;i++){
        cout<<"The element is : "<<array[i]<<endl;
    }

}