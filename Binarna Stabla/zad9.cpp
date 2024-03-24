void suma1(struct cvor* korijen){

    if(korijen==NULL)
        return;

    if(korijen->lijevi==NULL && korijen->desni==NULL)
        return;

    if(korijen->lijevi==NULL){
        if(korijen->desni->vrijednost<korijen->vrijednost)
            cout<<korijen->vrijednost<<" ";
        return;
    }

    if(korijen->desni==NULL){
        if(korijen->lijevi->vrijednost<korijen->vrijednost)
            cout<<korijen->vrijednost<<" ";
        return;
    }

    if((korijen->lijevi->vrijednost + korijen->desni->vrijednost)<korijen->vrijednost)
        cout<<korijen->vrijednost<<" ";


    suma1(korijen->lijevi);
    suma1(korijen->desni);
}
