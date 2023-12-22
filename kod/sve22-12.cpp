#include <iostream>
//#include <vector>
#include <cstdlib>
using namespace std;



void ucitajNiz(int* a,int n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}


void ispisiNiz(int* a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void sortirajNiz(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}


void parnihVecihOdK(int* a, int n, int k){
    int brojac=0;
    for(int i=0;i<n;i++){
        if(a[i]>k && a[i]%2==0){
            brojac++;
        }
    }
    cout<<brojac;
}

void parniNeparni(int* a, int n){
    int* parni= nullptr;
    int* neparni=nullptr;
    int parniBr=0;
    int neparniBr=0;

    for(int i=0;i<n;i++){
        if(a[i] % 2 ==0){
            int* temp= new int[parniBr+1];
            for(int j=0; j<parniBr;j++){
                temp[j]=parni[j];
            }
            temp[parniBr]=a[i];
            delete[] parni;
            parni=temp;
            parniBr++;

        }else{
            int* temp= new int[neparniBr+1];
            for(int j=0; j<neparniBr;j++){
                temp[j]=neparni[j];
            }
            temp[neparniBr]=a[i];
            delete[] neparni;
            neparni=temp;
            neparniBr++;
        }
    }

    ispisiNiz(parni,parniBr);
    cout<<"\n";
    ispisiNiz(neparni,neparniBr);


}


void duplira(int* a, int* b, int n){
    int j=0;
    for(int i=0;i<n;i++){
        b[j]=a[i];
        j++;
        b[j]=a[i];
        j++;
    }
}

void pomjeranjeParnih(int* a, int n) {
   for(int i=0;i<n;i++){
       if(a[i] % 2 == 0){
           continue;
       }
       for(int j=i+1;j<n;j++){
           if(a[j]%2==0){
               int tmp=a[j];
               a[j]=a[i];
               a[i]=tmp;
               break;
           }
       }
   }
}


bool duplikati(int* a, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                return false;
            }
        }
    }
    return true;
}
//1,2,3,4,5
//1,2,3,4,5,6
void popuniBool(bool* a,int n){
    for(int i=0;i<n;i++){
        a[i]=false;
    }
}

void pojavljujeSe(int*a, bool* b,int n){

    for(int i=0;i<n;i++){
        b[a[i]-1]=true;
    }

    for(int i=0;i<n;i++){
        if(b[i]==false){
            cout<<"Ne pojavljuje se "<<i+1<<endl;
        }
    }
}

void unija(int* a, int* b,int n,int m){

    int* unija= new int[n];

    for(int i=0;i<n;i++){
        unija[i]=a[i];
    }
    int brojac=n;
    bool el=false;
    for(int i=0;i<m;i++){
        el=false;
        for(int j=0;j<n;j++){
            if(b[i]==a[j]){
                el=true;
                break;
            }
        }
        if(!el){
            int* tmp= new int[brojac+1];
            for(int j=0;j<brojac;j++){
                tmp[j]=unija[j];
            }
            tmp[brojac]=b[i];
            delete[] unija;
            unija=tmp;
            brojac++;
        }
    }

    for(int i=0;i<brojac;i++){
        cout<<unija[i]<<" ";
    }
    cout<<endl;

}


void presjek(int* a,int* b,int n,int m){
    int* presek= new int[0];
    int brojac=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                int* tmp=new int[brojac+1];
                for(int k=0;k<brojac;k++){
                    tmp[k]=presek[k];
                }
                tmp[brojac]=a[i];
                delete[] presek;
                presek=tmp;
                brojac++;
                break;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<presek[i]<<" ";
    }
}


void razlika(int* a, int* b, int n,int m){

    bool value;
    int brojac=0;
    int* razlika= new int[0];
    for(int i=0;i<n;i++){
        value=false;
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                value= true;
                break;
            }
        }
        if(!value){
            int* tmp=new int[brojac+1];
            for(int j=0;j<brojac;j++){
                tmp[j]=razlika[j];
            }
            tmp[brojac]=a[i];
            delete[] razlika;
            razlika=tmp;
            brojac++;
        }

    }
    cout<<endl;
    ispisiNiz(razlika,brojac);
}


void sumaPrijePosle(int* a,int n){
    int sum_prije=0;
    int sum_posle=0;
    int k=n;
    int index=0;
    while(k>0){
        sum_prije=0;
        sum_posle=0;
        for(int i=0;i<index;i++){
            sum_prije+=a[i];
        }
        for(int i=index+1;i<n;i++){
            sum_posle+=a[i];
        }
        if(index==3){
           // cout<<index<<" "<<sum_posle<<" "<<sum_prije<<endl;
        }
        if(sum_posle==sum_prije){
            cout<<index<<" "<<sum_posle<<" "<<sum_prije<<endl;
        }
        index++;
        k--;
    }

}


void maxSumPodniza(int* a, int n) {
    int prvi = 0;
    int drugi = 0;
    int maxSum = a[0];
    int trenSum = a[0];

    for (int i = 1; i < n; i++) {
        if (trenSum + a[i] > a[i]) {
            trenSum += a[i];
        } else {
            trenSum = a[i];
            prvi = i;
        }

        if (trenSum > maxSum) {
            maxSum = trenSum;
            drugi = i;
        }
    }

    cout << "Maksimalni podniz s maksimalnom sumom: ";
    for (int i = prvi; i <= drugi; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


void sortirajParneNeparne(int* a, int n){

    bool parni;
    bool neparni;
    for(int i=0;i<n;i++){
        parni=false;
        neparni=false;
        if(a[i]% 2==0){
            parni=true;
        }else{
            neparni=true;
        }
        for(int j=i+1;j<n;j++){
            if(a[j]%2==0 && parni){
                if(a[i]>a[j]){
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }else if(a[j]%2==1 && neparni){
                if(a[i]<a[j]){
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }
        }
    }
}





void najvece_dvije_cifre(int* a, int n){
    sortirajNiz(a,n);
    int prvi=0;
    int drugi=0;
    for(int i=0;i<n;i++){
        if(i % 2 == 0){
            prvi*=10;
            prvi+=a[i];
        }else{
            drugi*=10;
            drugi+=a[i];
        }
    }
    cout<<prvi<<"+"<<drugi<<"="<<drugi+prvi;
}



void talasasti(int* a, int n){
    sortirajNiz(a,n);

    for(int i=0;i<n-1;i=i+2){
        int tmp=a[i];
        a[i]=a[i+1];
        a[i+1]=tmp;
    }
    ispisiNiz(a,n);
}


void susjedni(int* a, int n){
    bool mrk=true;
    for(int i=0;i<n-1;i=i+2){
        if(mrk){
            if(a[i+1] == a[i]){
                int brojac=1;
                test:
                if(a[i] != a[n-i-brojac]){
                    int tmp=a[i];
                    a[i]=a[n-i-brojac];
                    a[n-i-brojac]=tmp;
                }else{
                    brojac++;
                    if(brojac==n){
                        exit(1);
                    }
                    goto test;
                }
            }
        }
    }
    ispisiNiz(a,n);
}
int main() {

    int n;

    cin>>n;
    int* a= new int[n];
    //int* b= new int[n+3];
    //bool* b= new bool[n];
    ucitajNiz(a,n);
   // cout<<endl<<"Unesi b"<<endl;
    //ucitajNiz(b,n+3);
    //cout<<"\n";
   // sortirajNiz(a,n);
    //parnihVecihOdK(a,n,3);
    //ispisiNiz(a,n);
    //parniNeparni(a,n);
   // duplira(a,b,n);
    //pomjeranjeParnih(a,n);
    //popuniBool(b,n);
   // pojavljujeSe(a,b,n);
    //ispisiNiz(a,n);
    //unija(a,b,n,n+3);
    //presjek(a,b,n,n+3);
   // razlika(a,b,n,n+3);
    //sumaPrijePosle(a,n);
    //maxSumPodniza(a,n);
    //sortirajParneNeparne(a,n);
    //cout<<endl;
    //ispisiNiz(a,n);
    cout<<endl;
    //najvece_dvije_cifre(a,n);
    ///ispisiNiz(a,n);
    //talasasti(a,n);
    susjedni(a,n);
    return 0;
}
