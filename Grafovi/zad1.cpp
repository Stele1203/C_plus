//Napisati program koji štampa sve artikulacione čvorove u datom neusmjerenom grafu.

bool test(vector<vector<int>> graf,int k,int stari){

    for(int i=0;i<graf.size();i++){
        graf[i][k]=0;
        graf[k][i]=0;
    }
    if(stari< brojKomponenti(graf)-1)
        return true;
    return false;
}



void nekiCvorNaA(vector<vector<int>>graf){
    int brojK= brojKomponenti(graf);
    for(int i=0;i<graf.size();i++){
        if(test(graf,i,brojK)){
            cout<<i<<" ";
        }
    }
}
