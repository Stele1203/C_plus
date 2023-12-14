#include <iostream>
#include<list>
using namespace std;

struct cvor{
    int vrijednost;
    struct cvor* sledeci;
};


void stampajListu(struct cvor* glava){
    struct cvor* temp=glava;
    while(temp != NULL){
        cout<<temp->vrijednost<<" ";
        temp=temp->sledeci;
    }
}

void dodajNaPocetak(struct cvor*& glava, int vrijednost){
    struct cvor* novi= new struct cvor;
    novi->vrijednost=vrijednost;
    novi->sledeci=glava;
    glava=novi;
}


void dodajNaKraj(struct cvor*& glava, int vrijednost){
    struct cvor* novi= new struct cvor;
    novi->vrijednost=vrijednost;
    novi->sledeci=NULL;
    if(glava==NULL){
        glava=novi;
        return;
    }

    struct cvor* tmp= glava;
    //tmp=glava;
    while (tmp->sledeci != NULL){
        tmp=tmp->sledeci;
    }
    tmp->sledeci=novi;
}


void procitajElement(struct cvor*& glava,int i){
    struct cvor* tmp=glava;
    for(int j=1;j<i;j++){
        tmp=tmp->sledeci;
    }
    cout<<endl<<tmp->vrijednost<<endl;
}

void dodajNaPoziciju(struct cvor*& glava,int pozicija,int vrijednost){

    struct cvor* novi=new struct cvor;
    novi->vrijednost=vrijednost;
    if(pozicija==0 || glava==NULL){
        glava=novi;
        glava->sledeci=NULL;
    }


    struct cvor* tmp=glava;
    struct cvor* preth=new struct cvor;
    for(int i=1;i<pozicija;i++){
        preth=tmp;
        tmp=tmp->sledeci;
    }
    preth->sledeci=novi;
    novi->sledeci=tmp;

}

void obrisiGlava(struct cvor*& glava){
    struct cvor* tmp=glava;
    glava=glava->sledeci;
    delete tmp;
}


void obrisiOdredjenuVrijednost(struct cvor*& glava, int broj){

    struct cvor* tmp=glava;
    struct cvor* preth=new struct cvor;
    if(broj==1 || glava != NULL){
        glava=glava->sledeci;
    }
    for(int i=1;i<broj;i++){
        preth=tmp;
        tmp=tmp->sledeci;
    }
    preth->sledeci=tmp->sledeci;
    delete tmp;
}

void obrisi_Vrijednost(struct cvor*& glava,int vrijednost){
    if(glava==NULL){
        return;
    }
    struct cvor* preth= new struct cvor;
    preth=NULL;
    struct cvor* tmp=glava;
    while(tmp->sledeci != NULL && tmp->vrijednost != vrijednost){
        preth=tmp;
        tmp=tmp->sledeci;
    }

    if(tmp==NULL)
        return;

    if(preth==NULL){
        glava = glava->sledeci;
        delete tmp;
    }else{
        preth->sledeci = tmp->sledeci;
        delete tmp;
    }
}


void obrisiSvakoPojavljivanje(struct cvor*& glava,int v){

    struct cvor* tmp= glava;
    struct cvor* preth=NULL;

    while(tmp !=NULL){

        if(tmp->vrijednost==v){
            if(preth==NULL){
                glava=glava->sledeci;
                delete tmp;
            }else{
                preth->sledeci=tmp->sledeci;
                delete tmp;
                tmp=preth->sledeci;
            }
        }else{
            preth=tmp;
            tmp=tmp->sledeci;
        }

    }

}


int main() {
    struct cvor* c1= new struct cvor;
    c1->vrijednost=5;
    struct cvor* c2=new struct cvor;
    c2->vrijednost=6;
    c1->sledeci=c2;
    c2->sledeci=NULL;
    struct cvor* glava=c1;
    dodajNaPocetak(glava,4);
    dodajNaKraj(glava,10);
    dodajNaKraj(glava,10);
    //procitajElement(glava,1);
    dodajNaPoziciju(glava,3,112);
    //obrisiGlava(glava);
    //obrisiOdredjenuVrijednost(glava,1);
    //obrisi_Vrijednost(glava,10);
    obrisiSvakoPojavljivanje(glava,10);
    stampajListu(glava);


    return 0;
}
