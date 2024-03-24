void listovi(struct cvor* korijen){
    if(korijen==NULL)
        return;

    if(korijen->lijevi==NULL && korijen->desni==NULL)
        cout<<korijen->vrijednost<<" ";

    listovi(korijen->lijevi);
    listovi(korijen->desni);
}
