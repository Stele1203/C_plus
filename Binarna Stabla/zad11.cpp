bool simetricnaPomoc(struct cvor* k1, struct cvor* k2){
    if(k1==NULL && k2==NULL)
        return true;

    if(k1==NULL)
        return false;

    if(k2==NULL)
        return false;

    if(k1->vrijednost!=k2->vrijednost){
        return false;
    }

    return simetricnaPomoc(k1->lijevi,k2->desni) && simetricnaPomoc(k1->desni,k2->lijevi);
}

bool simetricna(struct cvor* korijen){

    return simetricnaPomoc(korijen->lijevi,korijen->desni);
}
