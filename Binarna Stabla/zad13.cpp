bool validnoStabloPretrazivanja(struct cvor* korijen){
    if(korijen==NULL)
        return true;

    if((korijen->lijevi !=NULL && korijen->lijevi->vrijednost>korijen->vrijednost) || (korijen->desni != NULL && korijen->desni->vrijednost<korijen->vrijednost))
        return false;

    return validnoStabloPretrazivanja(korijen->lijevi) && validnoStabloPretrazivanja(korijen->desni);
}
