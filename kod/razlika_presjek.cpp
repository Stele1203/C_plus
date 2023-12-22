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
