/* Dat je neusmjeren povezan graf sa N čvorova i M grana. Napisati program koji štampa
K čvorova (K<N) koji se mogu ukloniti iz grafa a da on ostane povezan. */

bool test2(vector<vector<int>> graf,int k,int stari){

    for(int i=0;i<graf.size();i++){
        graf[i][k]=0;
        graf[k][i]=0;
    }
    if(stari >= brojKomponenti(graf)-1)
        return true;
    return false;
}


void moguSeUkloniGrane(graf graf){
    for(int i=0;i<graf.size();i++){
        if(test2(graf,i, brojKomponenti(graf))){
            cout<<i<<" ";
        }
    }
}
