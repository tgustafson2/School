/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sort.h
 * Author: tgust
 *
 * Created on July 16, 2020, 6:14 PM
 */

#ifndef SORT_H
#define SORT_H
template <class T>
class Sort{
public:
    static void MergeSort(T[], int, int);
    static void Merge(T [], int, int, int);
    static void QuickSort(T [], int, int);
    static void ShellSort(T [],int);
    static void HeapSort(T [], int);
    static void heapify(T [],int, int);
    static void Swap(T *, T *);
    static int Parti(T [], int, int);
    
};
template<class T>
void Sort<T>::Swap(T* i, T* j){
    T temp =*i;
    *i=*j;
    *j=temp;
}
template <class T>
void Sort<T>::MergeSort(T arr[], int left, int right){
    
    if (left<right){
        int middle = (left+(right-1))/2;
        MergeSort(arr,left, middle);
        MergeSort(arr,middle+1, right);
        Merge(arr, left, middle, right);
    }
    
}
template <class T>
void Sort<T>::Merge(T arr [], int left, int middle, int right){
    
    int i, j, k;
    int n1= middle - left +1;
    int n2= right-middle;
    T *L=new int [n1];
    T *R=new int[n2];
    
    for (i=0; i<n1; i++){
        L[i]=arr[left+i];
    }
    for (j=0; j<n2; j++){
        R[j]=arr[middle+1+j];
    }
    
    i=0,j=0,k=left;
    
    while (i < n1 && j<n2){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
template <class T>
int Sort<T>::Parti(T arr[], int low, int high){
    T pivot= arr[high];
    int i=low-1;
    
    for (int j=low; j<high; j++){
        
        if (arr[j]<pivot){
            i++;
            Swap (&arr[i], &arr[j]);
        }
    }
    Swap (&arr[i+1], &arr[high]);
    return (i+1);
}
template <class T>
void Sort<T>::QuickSort(T arr[], int low, int high){
    
    if (low<high){
        int partindx= Parti(arr, low, high);
        
        QuickSort(arr, low, partindx-1);
        QuickSort(arr, partindx+1,high);
    }
}
template <class T>
void Sort<T>::heapify(T arr[], int n, int i){
    
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if (left<n&& arr[left]>arr[largest])
        largest=left;
    if (right<n&& arr[right]>arr[largest])
        largest=right;
    
    if (largest !=i){
        Swap(&arr[i],&arr[largest]);
        heapify(arr,n, largest);
    }
}
template <class T>
void Sort<T>::HeapSort(T arr[], int n){
    
    for (int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for (int i=n-1; i>0; i--){
        Swap(&arr[0],&arr[i]);
        heapify (arr,i,0);
    }
}
template <class T>
void Sort<T>::ShellSort(T arr[], int n){
    for (int gap=n/2; gap>0; gap/=2){
        
        for (int i=gap; i<n; i++){
            T temp=arr[i];
            
            int j;
            for (j=i; j>=gap&&arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            
            arr[j]=temp;
        }
    }
}


#endif /* SORT_H */

