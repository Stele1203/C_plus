#include <iostream>
#include <string>
using namespace std;

struct cvor{
    int vrijednost;
    int brojac;
    struct cvor* sledeci;
};


void dodajCvor(struct cvor*& glava,int vrijednost){

    struct cvor* tmp=glava;
    while(tmp != NULL){
        if(tmp->vrijednost==vrijednost){
            tmp->brojac=tmp->brojac+1;
            return;
        }
        tmp=tmp->sledeci;
    }

    struct cvor* preth=NULL;
    struct cvor* novi= new struct cvor;
    novi->vrijednost=vrijednost;
    novi->brojac=1;
    tmp=glava;
    preth=NULL;
    bool pronasao=false;
    while(tmp->sledeci != NULL){
        if(vrijednost<tmp->vrijednost){
            if(preth == NULL){
                novi->sledeci=glava;
                glava=novi;
                pronasao=true;
                return;
            }
            preth->sledeci=novi;
            novi->sledeci=tmp;
            pronasao= true;

        }
        preth=tmp;
        tmp=tmp->sledeci;


    }
    if(pronasao==false) {
        novi->sledeci = NULL;
        tmp->sledeci = novi;
    }
}

void stampajListu(struct cvor*& glava){
    struct cvor* tmp=glava;
    while(tmp != NULL){
        for(int i=0;i<tmp->brojac;i++){
            cout<<tmp->vrijednost<<" ";
        }
        tmp=tmp->sledeci;
    }
    cout<<endl;

}

void obrisiCvor(struct cvor*& glava, int v){

    struct cvor* tmp=glava;
    while(tmp != NULL){
        if(tmp->vrijednost==v && tmp->brojac>1){
            tmp->brojac--;
            return;
        }
        tmp=tmp->sledeci;
    }

    tmp=glava;
    struct cvor* preth=NULL;
    while(tmp != NULL){
        if(tmp->vrijednost==v){
            if(preth==NULL){
                glava=glava->sledeci;
                delete tmp;
                return;
            }else{
                preth->sledeci=tmp->sledeci;
            delete tmp;
            return;
            }

        }
        preth=tmp;
        if(tmp->sledeci!=NULL){
            tmp=tmp->sledeci;
        }
    }
}

int main() {

    struct cvor* c1=new struct cvor;
    struct cvor* c2=new struct cvor;
    struct cvor* c3=new struct cvor;
    struct cvor* c4=new struct cvor;
    c1->vrijednost=1;
    c1->brojac=1;
    c2->vrijednost=2;
    c2->brojac=1;
    c3->vrijednost=3;
    c3->brojac=5;
    c4->vrijednost=4;
    c4->brojac=4;

    c1->sledeci=c2;
    c2->sledeci=c3;
    c3->sledeci=c4;
    c4->sledeci=NULL;

    struct cvor* glava=c1;
    stampajListu(glava);
    dodajCvor(glava,9);
    stampajListu(glava);
    obrisiCvor(glava,9);
    stampajListu(glava);

    return 0;
}
