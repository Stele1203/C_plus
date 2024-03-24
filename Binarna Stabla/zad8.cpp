void dvaSina(struct cvor* korijen){
    if(korijen==NULL)
        return;

    if(korijen->lijevi!=NULL && korijen->desni!=NULL)
        cout<<korijen->vrijednost<<" ";

    dvaSina(korijen->lijevi);
    dvaSina(korijen->desni);
}
