bool balansirano(struct cvor* korijen){
    if(korijen== NULL)
        return true;

    if(abs(visinaRek(korijen->lijevi)-visinaRek(korijen->desni)) >1)
        return false;

    return balansirano(korijen->lijevi) && balansirano(korijen->desni);
}
