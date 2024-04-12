
/*5. Dat je usmjeren acikličan graf sa N čvorova i M grana. Napisati program koji za svaki
čvor grafa štampa njegove pretke. Ako čvor nema predaka, štampati -1. Čvor A je
predak čvora B, ukoliko se iz čvora A može doći do čvora B nizom grana. */
void dfsSaSteckom(graf graf,int start,stack<int>& niz,vector<bool>&posjecen){
    posjecen[start]= true;

    for(int i=0;i<graf.size();i++){
        if(!posjecen[i] && graf[i][start]==1){
            niz.push(i);
            dfsSaSteckom(graf,i,niz,posjecen);
        }
    }
}

void ispisiNiz(stack<int>stek){
    while(!stek.empty()) {
        cout << stek.top() << " ";
        stek.pop();
    }
    cout<<endl;
}

void predaciGrafa(graf graf){

    for(int i=0;i<graf.size();i++){
        vector<bool>posjecen(graf.size(),false);
        stack<int> stek;
        dfsSaSteckom(graf,i,stek,posjecen);
        ispisiNiz(stek);
    }
}
