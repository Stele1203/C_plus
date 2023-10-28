#include <iostream>
#include <climits>
using namespace std;


void complexNumber(double* a, double* b, int n){

    double real=a[0];
    double im=b[0];

    for(int i=1;i<n;i++){
        double real_tmp=real;
        double im_tmp=im;
       // cout<<"Realni dio "<<real<<" Imagniarni dio "<<im<<endl;
        real=real*a[i]-im*b[i];
        im=real_tmp*b[i]+im_tmp*a[i];
    }

    cout<<"Realni dio "<<real<<" Imagniarni dio "<<im;


}



int main() {

    int n;

    cin>>n;
    cout<<"Unesi elemente matrica a"<<endl;
    double* a= new double[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Unesi elemente matrice b"<<endl;
    double* b= new double[n];

    for(int i=0;i<n;i++){
        cin>>b[i];
    }



    complexNumber(a,b,n);


    return 0;
}
