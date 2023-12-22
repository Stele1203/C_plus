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
