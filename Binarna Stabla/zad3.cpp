bool identicni(struct cvor* korijen1, struct cvor* korijen2){
    if(korijen1==NULL && korijen2==NULL)
        return true;
    if(korijen2==NULL)
        return false;
    if(korijen1==NULL)
        return false;

    return identicni(korijen1->lijevi,korijen2->lijevi) && identicni(korijen1->desni,korijen2->desni);
}
