void sirina(struct cvor* korijen){
    if(korijen == NULL)
        return;

    queue<pair<int,cvor*>> red;
    red.push(make_pair(1,korijen));
    vector<int>test(visinaRek(korijen),0);
    test[0]++;
    while(!red.empty()){
        auto tmp=red.front();
        red.pop();

        if(tmp.second->lijevi != NULL){
            red.push(make_pair(tmp.first+1,tmp.second->lijevi));
            test[tmp.first]++;
        }

        if(tmp.second->desni != NULL){
            red.push(make_pair(tmp.first+1,tmp.second->desni));
            test[tmp.first]++;
        }
    }

    int max=0;

    for(int i=0;i<test.size();i++){
        if(test[max]<test[i])
            max=i;
    }

    cout<<"Najvise el ima na nivou "<<max+1<<endl;

}
