int minKanap(vector<int>& kanapi){
    int ukupnaCijena=0;

    priority_queue<int,vector<int>,greater<int>>heap(kanapi.begin(),kanapi.end());

    while(heap.size()>1){
        int prviKanap=heap.top();
        heap.pop();
        int drugiKanap=heap.top();
        heap.pop();

        int suma=prviKanap+drugiKanap;
        ukupnaCijena+=suma;
        heap.push(suma);
    }
    return ukupnaCijena;
}
