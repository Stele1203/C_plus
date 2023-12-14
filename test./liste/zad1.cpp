#include <iostream>
#include<list>
using namespace std;

struct cvor{
    int vrijednost;
    struct cvor* sledeci;
};


void dodajNaKraj(struct cvor* glava,int v){
    struct cvor* novi=new struct cvor;
    novi->vrijednost=v;
    if(glava==NULL){
        glava=novi;
        glava->sledeci=NULL;
    }

    struct cvor* tmp= glava;

    while(tmp->sledeci != NULL){
        tmp=tmp->sledeci;
    }
    tmp->sledeci=novi;
    novi->sledeci=NULL;
}



void stampajListu(struct cvor* glava){
    struct cvor* temp=glava;
    while(temp != NULL){
        cout<<temp->vrijednost<<" ";
        temp=temp->sledeci;
    }
}


void umetni(struct cvor*& glava){

    struct cvor* tmp=glava;

    while((tmp !=NULL) && (tmp->sledeci != NULL)){
        struct cvor* novi= new struct cvor;
        novi->vrijednost=tmp->sledeci->vrijednost-tmp->vrijednost;
        novi->sledeci=tmp->sledeci;
        tmp->sledeci=novi;
        tmp=novi->sledeci;
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
    dodajNaKraj(glava,4);
    dodajNaKraj(glava,10);
    umetni(glava);
    stampajListu(glava);

    return 0;
}
