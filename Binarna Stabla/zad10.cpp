int suma2(struct cvor*& korijen,int d){
    if(korijen==NULL)
        return 0;

    queue<pair<cvor*,int>> red;
    red.push(make_pair(korijen,1));
    int sum1=0;
    int sum2=0;
    while(!red.empty()){
        pair<cvor*,int> tren=red.front();
        red.pop();
        if(tren.second==d){
            if(tren.first->vrijednost % 2 == 0)
                sum1+=tren.first->vrijednost;
            else
                sum2+=tren.first->vrijednost;
        }
        if(tren.first->lijevi != NULL)
            red.push(make_pair(tren.first->lijevi,tren.second+1));

        if(tren.first->desni != NULL)
            red.push(make_pair(tren.first->desni,tren.second+1));

    }

    return sum1-sum2;
}
