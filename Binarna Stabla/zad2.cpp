int visina(struct cvor* korijen){
    if(korijen==NULL){
        return 0;
    }

    int h1= visina(korijen->lijevi);
    int h2= visina(korijen->desni);
    if(h1>h2){
        return h1+1;
    }else{
        return h2+1;
    }
}
