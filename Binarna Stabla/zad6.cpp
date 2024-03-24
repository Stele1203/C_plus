void izbrisiSveizReda(queue<cvor*> &red){

    while (!red.empty()){
        red.pop();
    }
}


void najvecaDubina(struct cvor* korijen){
    if(korijen==NULL)
        return;

    queue<pair<cvor*,int>> red;
    queue<cvor*> pomocni;
    red.push(make_pair(korijen,1));
    int najDubljaDubina=0;

    while (!red.empty()){
        pair<cvor*,int> trenutni=red.front();
        red.pop();

        cvor* trenutniCvor= trenutni.first;
        int trenutniNivo=trenutni.second;

        if(trenutniNivo> najDubljaDubina){
            najDubljaDubina=trenutniNivo;
            izbrisiSveizReda(pomocni);
        }
        if(trenutniNivo==najDubljaDubina)
            pomocni.push(trenutniCvor);


        if(trenutniCvor->lijevi != NULL) {
            red.push(make_pair(trenutniCvor->lijevi, trenutniNivo + 1));
        }
        if(trenutniCvor->desni != NULL) {
            red.push(make_pair(trenutniCvor->desni, trenutniNivo + 1));

        }
    }

    while (!pomocni.empty()){
        cvor* tren=pomocni.front();
        pomocni.pop();
        cout<<tren->vrijednost<<" ";
    }
}
