#include <iostream>
using namespace std;

void swap(int * a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int left, int right)
{
    int pivot = array[right]; //step 2A (slide)

    int A = left-1; //step 2A (slide)


    for (int j = left; j<right; j++) //step 2B (slide)
    {
        if(array[j]<= pivot) //step 2B when element<pivot
        {
            A++;

            swap(&array[A], &array[j]); //swap function implemented above
        }

    }
    swap(&array[A+1], &array[right]); //step 2C (slide)

    return (A+1); //step 2C (slide)

}


void quicksort (int array[], int left, int right)
{
    if(left<right)
        // we'll keep calling partition() and
        //recursively calling quicksort() until the partition is reduced to a single element (i.e left = right)
    {
        int pi = partition(array, left, right); //Partitioning is done using another function

        quicksort(array, left, pi-1); //call quicksort again for the left subgroup

        quicksort(array, pi+1, right); //call quicksort again for the right subgroup

    }
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int data[n];
    cout<<"Enter array to be sorted: ";

    for(int i=0; i<n; i++)
    {
        cin>>data[i];
    }


    cout<<"\nBefore sorting: ";
     for(int i=0; i<n; i++)
    {
        cout<<data[i]<<" ";
    }

    quicksort(data, 0, n-1);

    cout<<"\n\nAfter sorting: ";
     for(int i=0; i<n; i++)
    {
        cout<<data[i]<<" ";;
    }

    cout<<"\n\n";

}
