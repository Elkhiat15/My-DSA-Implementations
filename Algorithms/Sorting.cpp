#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>& Arr){
    int MinIndex;

    for (int i = 0; i < Arr.size() - 1; ++i) {
        MinIndex = i;

        for (int j = i+1; j < Arr.size(); ++j) {
            if(Arr[j] <  Arr[MinIndex])
                MinIndex = j;
        }

        swap( Arr[MinIndex], Arr[i]);
    }
}

void BubbleSort(vector<int>& Arr){
    bool Swapped = true;
    for (int i = 0; i < Arr.size(); ++i) {
        for (int j = 1; j < Arr.size(); ++j) {
            if(Arr[j] < Arr[j-1])
                swap(Arr[j], Arr[j-1]), Swapped= false;
        }
        if(Swapped)
            break;
    }
}

void CountSort(vector<int>& Arr){

    int Size = Arr.size();
    int MaxNumber = Arr[0];

    for (int i = 1; i < Size; ++i){
        if(Arr[i] < 0)
        {
            cout<<"This version of Count Sort can't deal with negative numbers\n";
            return;
        }
        MaxNumber = max(MaxNumber, Arr[i]);
    }

    vector<int> CumulativeCount(MaxNumber + 1, 0);
    //Store the count for each element
    for (int i = 0; i < Size; ++i)
        CumulativeCount[Arr[i]]++;

    //Calculate the cumulative sum
    for (int i = 1; i <= MaxNumber; ++i)
        CumulativeCount[i] += CumulativeCount[i-1];

    vector<int> Temp(Size , 0);
    for (int i = Size - 1; i >= 0  ; --i) {
        Temp[CumulativeCount[Arr[i]] - 1] = Arr[i];
        CumulativeCount[Arr[i]]--;
    }

    Arr = Temp;
}
void RadixSort(vector<int>& Arr){}
void BucketSort(vector<int>& Arr){}

void InsertionSort(vector<int>& Arr){
    int Size = Arr.size();
    for (int i = 1; i < Size; ++i) {
        int Key = Arr[i];
        int Comp = i - 1;

        while (Comp >= 0 && Arr[Comp] > Key){
            Arr[Comp + 1] = Arr[Comp];
            Comp--;
        }
        Arr[Comp + 1]= Key;
    }
    return;
}

int Partition(vector<int> & Arr,int Begin,int End){
    int pivot = Arr[End];
    int Index = Begin - 1;

    for (int i = Begin; i < End; ++i) {
        if(Arr[i] <= pivot){
            Index++;
            swap(Arr[Index], Arr[i]);
        }
    }
    swap(Arr[++Index], Arr[End]);
    return Index;
}

void QuickSort(vector<int> & Arr, int Begin = 0, int End = -1){
    if(End == -1)
        End = Arr.size() - 1;

    if(Begin < End){
        int Pivot = Partition(Arr, Begin, End);
        QuickSort(Arr, Begin, Pivot - 1);
        QuickSort(Arr, Pivot + 1, End);
    }
}

void Merge(vector<int> & Arr, int Begin,int Mid,  int End){
    int Size1 = Mid - Begin + 1;
    int Size2 = End - Mid;
    vector<int> LeftSub(Size1);
    vector<int> RightSub(Size2);

    for (int i = 0, j = Begin; i < Size1; ++i, ++j)
        LeftSub[i] = Arr[j];
    for (int i = 0, j = Mid + 1 ; i < End; ++i, ++j)
        RightSub[i] = Arr[j];

    int Comp1 = 0, Comp2 = 0, Index = Begin;

    while (Comp1 < Size1 && Comp2 < Size2){
        if(LeftSub[Comp1] <= RightSub[Comp2])
            Arr[Index++] = LeftSub[Comp1++];
        else
            Arr[Index++] = RightSub[Comp2++];
    }

    while (Comp1 < Size1)
        Arr[Index++] = LeftSub[Comp1++];

    while (Comp2 < Size2)
        Arr[Index++] = RightSub[Comp2++];
}

void MergeSort(vector<int> & Arr, int Begin=0, int End = -1){
    if(End == -1)
        End = Arr.size() - 1;
    if(Begin >= End)
        return;
    int Mid = Begin + (End - Begin)/2;
    MergeSort(Arr, Begin, Mid);
    MergeSort(Arr, Mid + 1, End);
    Merge(Arr, Begin, Mid, End);

}

void PrintSorted(const vector<int> & Arr){
    for (int Element : Arr ) {
        cout<<Element<<" ";
    }
    cout<<endl;
}

bool CheckSorted(const vector<int> & Arr){
    int Size = Arr.size();
    if(Size == 1)
        return true;
    for (int i = 1; i < Size; ++i) {
        if(Arr[i] < Arr[i -1])
            return false;
    }
    return true;
}

void Test(int Choose = 0 ){
    vector<int> TestArr = {5, 2, 4, 6,4,2,3 ,1, 3 };

    switch (Choose) {
        case 1:{
            cout<<"Selection Sort:\n";
            SelectionSort(TestArr);
            break;
        }
        case 2:{
            cout<<"Bubble Sort:\n";
            BubbleSort(TestArr);
            break;
        }
        case 3:{
            cout<<"Insertion Sort:\n";
            InsertionSort(TestArr);
            break;
        }
        case 4:{
            cout<<"Quick Sort:\n";
            QuickSort(TestArr);
            break;
        }
        case 5:{
            cout<<"Merge Sort:\n";
            MergeSort(TestArr);
            break;
        }
        case 6:{
            cout<<"Count Sort:\n";
            CountSort(TestArr);
            break;
        }
        default :{
            cout<<"Please, Enter a valid number between 1 and 7\n";
            return;
    }
    }
    PrintSorted(TestArr);
    cout<<CheckSorted(TestArr)<<endl;
}
int main() {
    Test(6);
    return 0;
}