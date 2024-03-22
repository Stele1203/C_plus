int brojCvorova(struct cvor* korijen){
    if(korijen==NULL){
        return 0;
    }
    int broj=1;
    broj+= brojCvorova(korijen->lijevi);
    broj+= brojCvorova(korijen->desni);
    return broj;

}
