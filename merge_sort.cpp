#include<iostream>
using namespace std;
	void accept(int *,int);
	void display(int *,int);
	void betweenpassdisplay(int *,int,int);
	void mergesort(int *,int);
	void divide(int [],int,int);
	void mergearr(int arr[],int start,int m,int end1);
int main()
{

	int arrsize,c;
	cout<<"\n Enter the number of elements:";
    cin>>arrsize;
    int arr[arrsize];
	do
	{
		cout<<"\n\n\n enter your choice \n 1.Accept \n 2.Display \n 3.Odd even sort sort. \n 0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{

				accept(arr,arrsize);
				break;
				}
			case 2:{
				display(arr,arrsize);
				break;
				}
			case 3:{
				mergesort(arr,arrsize);
				break;
				}

			 default:{
					cout<<"\n wrong input entered!!!";
					break;
				      }
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<4 && c>0);
	return 0;
}

	void accept(int *arr,int arrsize)
	{
		for(int i=0;i<arrsize;i++)
        {
            cout<<"\n enter the element at position "<<i+1<<":";
            cin>>arr[i];
        }

	}

	void display(int *arr,int arrsize)
		{
			for(int i=0;i<arrsize;i++)
			{
				cout<<arr[i]<<" ";
			}
		}

void mergesort(int *arr,int arrsize){
    int end1=arrsize-1,start=0;
    divide(arr,start,end1);
}

void divide(int arr[],int start,int end1){



    int m=(start+end1)/2;

     if(start<end1)
			{
                    betweenpassdisplay(arr,start,m);
    cout<<" <--left|split|right--> ";

    betweenpassdisplay(arr,m+1,end1);
    cout<<"\n";
			      divide(arr,start,m);
			      divide(arr,m+1,end1);
			      mergearr(arr,start,m,end1);
			      cout<<"\n";
                    betweenpassdisplay(arr,start,m);
                    cout<<" <--left//mergesort\\right--> ";
                    betweenpassdisplay(arr,m+1,end1);
                    cout<<"\n";
			}


}
void mergearr(int arr[],int start,int m,int end1){
    int i, j, k;
    int n1 = m - start + 1;
    int n2 =  end1 - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = start; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void betweenpassdisplay(int *arr,int s,int e){

    for(int i=s;i<=e;i++)
    {
        cout<<" "<<arr[i];
    }
}
