/********************* Cubic Spline Interpolation **********************/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

// Function Spline
float spline (float x[],float f[],float p,int n)
{
    int i,j;
    float h[50],a=0,b=0,c=0,d=0,sum=0,s[50]={0},F[50],m[50][50]={0},temp;
    for(i=n-1;i>0;i--)
    {
        F[i]=(f[i]-f[i-1])/(x[i]-x[i-1]);
        h[i-1]=x[i]-x[i-1];
    }

    //*********** formation of matrix **************//
    for(i=1;i<n-1;i++)
    {
    m[i][i]=2*(h[i-1]+h[i]);
    if(i!=1)
    {
        m[i][i-1]=h[i-1];
        m[i-1][i]=h[i-1];
    }
    m[i][n-1]=6*(F[i+1]-F[i]);
    }

    //***********  forward elimination **************//

    for(i=1;i<n-2;i++)
    {
        temp=(m[i+1][i]/m[i][i]);
        for(j=1;j<=n-1;j++)
            m[i+1][j]-=temp*m[i][j];
    }

    //*********** back ward substitution *********//
    for(i=n-2;i>0;i--)
    {
        sum=0;
        for(j=i;j<=n-2;j++)
            sum+=m[i][j]*s[j];
        s[i]=(m[i][n-1]-sum)/m[i][i];
    }
    
    for(i=0;i<n-1;i++)
    {
        if(x[i]<=p&&p<=x[i+1])
        {
            a=(s[i+1]-s[i])/(6*h[i]);
            b=s[i]/2;
            c=(f[i+1]-f[i])/h[i]-(2*h[i]*s[i]+s[i+1]*h[i])/6;
            d=f[i];
            sum=a*pow((p-x[i]),3)+b*pow((p-x[i]),2)+c*(p-x[i])+d;
            //cout<<"coefficients of sub interval : "<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
        }
    }
    return sum;
}

int main()
{
    int n,i,j,choice;
    char ch = 'y';
    float x[50],f[50],p,yp,k[50],r[50][50];
    cout<<"Enter Choice: "<<endl;
    cout<<"1. Do you want to input points? "<<endl;
    cout<<"2. Use data set already given? "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"No of samples ? ";cin>>n;
            cout<<"enter all sample points: "<<endl;
            for(i=0;i<n;i++)
            cin>>x[i]>>f[i];
            while (ch == 'y')
            {
                cout<<endl<<"Enter x  : ";cin>>p;
                yp = spline(x, f, p, n);
                cout<<"Interpolated point is : "<<yp<<endl;
                cout<<"Do you want to get more points? "<<"y/n"<<endl;
                cin>>ch;
            }
            return 0;
        case 2:
            float x[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            float f[] = {0,2,7,12,22,35,48,53,67,90,120,87,62,35,23,18,15,9,3,1,0};
            int length;
            length = sizeof(x) / sizeof(x[0]); // Calculates the length of the array
            cout << "The given data is..."<<endl;
            cout << "X" <<"\t" <<"Y"<<endl;
            for (i = 0; i<21;i++)
                {
                    cout << x[i]<<"\t"<<f[i]<<endl;
                }
            for (i=0;i<21;i++)
                {
                    k[i] = x[i]+0.33;
                }
            for(i=0;i<20;i++)
                {
                    for(j=0;j<21;j++)
                    {
                        r[i][j] = spline(x,f,k[i],j+1);
                    }
                    cout<<"Value of f(x) at x = "<<k[i]<<" using "<<"21"<<" points is : "<<r[i][20]<<" m/s"<<endl;
                }
                
            // Writing the file
            
                ofstream Myfile("/Users/saurabh/Desktop/Cubic_Spline.csv");
                for(i=0;i<20;i++)
                {
                    Myfile << k[i]<<" ";
                    for(j=0;j<21;j++)
                    {
                        Myfile << r[i][j]<<" ";
                    }
                    Myfile << endl;
                }
                Myfile.close();
            return 0;
    }
    return 0;
}
