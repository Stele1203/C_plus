vector<pair<cvor*, int>> dfsNajmanjaDubina(struct cvor* korijen,int dubina){
    vector<pair<cvor*,int>> niz;
    if(korijen== NULL) {
        return niz;
    }
    if(korijen->lijevi == NULL && korijen->desni == NULL){
        niz.push_back(make_pair(korijen, dubina));
        return niz;
    }

    vector<pair<cvor*,int>> lijevi= dfsNajmanjaDubina(korijen->lijevi,dubina+1);
    vector<pair<cvor*,int>> desni= dfsNajmanjaDubina(korijen->desni,dubina+1);

    niz.insert(niz.end(),lijevi.begin(),lijevi.end());
    niz.insert(niz.end(),desni.begin(),desni.end());

    return niz;

}

bool komparator(const pair<cvor*, int>& a, const pair<cvor*, int>& b) {
    if(a.second != b.second)
        return a.second<b.second;
    else
        return a.first->vrijednost>b.first->vrijednost;
}

struct cvor* listNajmanjaDubina(struct cvor* korijen){
    vector<pair<cvor*,int>> niz=dfsNajmanjaDubina(korijen,0);
    sort(niz.begin(),niz.end(), komparator);

    return niz[0].first;
}
