// Tutorial 2 - Lagrange and Cubic Spline Interpolation
#include<iostream>
#include<fstream>
using namespace std;

//Definining a function Interpolation
float interpolation(int x[], int y[], float xp, int n)
{
    float p;
    int i,j;
    float yp = 0.0;
    for(i=0;i<n;i++)
    {
         p = 1;
         for(j=0;j<n;j++)
         {
              if(i!=j)
              {
                p = p * (xp - x[j])/(x[i] - x[j]);
               }
         }
         yp = yp + p * y[i];
    }
    return yp;
}
//Defining function first derivative
float first_derivative(int x[],int y[], float xp, int n)
{
    float p; // initialise values
    int i,j,k;
    float yp = 0.0; // yp will return the final derivative
    for (i=0;i<n;i++) // outer loop
    {
        float lj = 0.0; // kp is assigned value of zero after every loop
        for (j=0;j<n;j++)
        {
            if(i!=j)
            {
                p = 1;
                for (k=0;k<n;k++)
                {
                    if (k!=i && k!=j)
                    {
                        p = p*(xp - x[k])/(x[i] - x[k]);
                    }
                }
                lj = lj + (1/(x[i]-x[j]))*p;
            }
        }
        yp = yp + lj * y[i];
    }
    return yp;
}

int main()
{
    float r[50][50],k[50],d[50][50];
    int i,j;
    int x[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int y[] = {0,2,7,12,22,35,48,53,67,90,120,87,62,35,23,18,15,9,3,1,0};
    int length;
    length = sizeof(x) / sizeof(x[0]); // Calculates the length of the array
    cout << "The given data is..."<<endl;
    cout << "X" <<"\t" <<"Y"<<endl;
    
    for (i = 0; i<21;i++)
        {
            cout << x[i]<<"\t"<<y[i]<<endl;
        }
    
    for (i=0;i<21;i++)
        {
            k[i] = x[i]+0.33;
        }
    for(i=0;i<20;i++)
    {
        for(j=0;j<=20;j++)
        {
            r[i][j] = interpolation(x,y,k[i],j);
            d[i][j] = first_derivative(x,y,k[i],j);
        }
        cout<<"Value of f(x) at x = "<<k[i]<<" using "<<"21"<<" points is : "<<r[i][20]<<" m/s"<<endl;
        //cout<<"Value of f'(x) at x = "<<k[i]<<" using "<<"21"<<" points is : "<<d[i][20]<<" m/s^2"<<endl;
    }
    // Writing the file
    ofstream Myfile("/Users/saurabh/Desktop/L.csv");
    for(i=0;i<20;i++)
    {
        Myfile << k[i]<<" ";
        for(j=0;j<=21;j++)
        {
            Myfile << r[i][j]<<" ";
        }
        Myfile << endl;
    }
    Myfile.close();
    return 0;
}




