#include <iostream>
using  namespace std;

int main ()
{
        int n = 0;
        cout << "n = ";
        cin >> n;
        if(n > 475)
        {
                n=475;
                cout << "This is longer than 100. I can only show you up until the number of digits is 99, F(475).";
                cout << endl;
        }
        cout << endl;
        int size = 100;
        int temp = 0; // for carry

        int FN1[size];
        int FN2[size];
        int FN3[size];

        for(int i = 0; i < size; i++)
        {
                FN1[i] = 0;
                FN2[i] = 0;
                FN3[i] = 0;
        }
        FN2[0] = 1;

        for(int i = 0; i < n; i++)
        {

                for(int i = 0; i < size; i++)
                {
                        FN3[i]=FN1[i] + FN2[i]+ temp;
                        temp = 0;
                        if(FN3[i] > 9)
                        {
                                temp = FN3[i]/10;
                                FN3[i] = FN3[i]%10;
                        }

                }
                for(int i = 0; i < size; i++)
                {
                        FN2[i] = FN1[i];
                }
                for(int i = 0; i < size; i++)
                {
                        FN1[i] = FN3[i];
                }
        }





        //check method;
        for(int i = size-1; i >= 0; i--)
        {
                cout << FN3[i];
        }
}
