#include <iostream>
using namespace std;


int MaxProduct(int *a, int n)
{
    int maxProduct = 1; // max positive product at current position
    int minProduct = 1; // min negative product at current position
    int r = 1; // result, max multiplication totally

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            maxProduct *= a[i];
            minProduct = min(minProduct * a[i], 1);
        }
        else if (a[i] == 0)
        {
            maxProduct = 1;
            minProduct = 1;
        }
        else // a[i] < 0
        {
            int temp = maxProduct;
            maxProduct = max(minProduct * a[i], 1);
            minProduct = temp * a[i];
        }

        r = max(r, maxProduct);
    }

    return r;
}



int main(){
int len;
int array[] = {1,5,-7};
cout<<MaxProduct(array,3)<<endl;

int array1[] = {1,5,-7,-3,2,1,-4,8,2};
len = sizeof(array1)/sizeof(int);
cout<<MaxProduct(array1,len)<<endl;

int array2[] = {1,2,-3,4,5};
len =  sizeof(array2)/sizeof(int);
cout<<MaxProduct(array2,len)<<endl;

int array3[] = {-1,2,3,-4,5};
len =  sizeof(array3)/sizeof(int);
cout<<MaxProduct(array3,len)<<endl;
    
}