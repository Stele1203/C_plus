#include <iostream>
#include<list>
using namespace std;
//U programskom jeziku C++ kreirati zapis koji predstavlja čvor jednostruko ulančane 
//liste cijelih brojeva. Čvor sadrži jedno cjelobrojno polje i pokazivač na sljedeći čvor u 
//listi. Napisati sljedeće funkcije: 
// stampajListu, koja u jednom redu štampa vrijednosti svih čvorova u listi. 
// dodajCvor, koja za argumente ima pokazivač na prvi čvor liste i dva cijela broja 
//P i V, i koja u listu dodaje novi čvor sa vrijednošću V na poziciju P. Pozicije 
//čvorova u listi su indeksirane od nule. Na primjer, ako je P=0, novi čvor se 
//dodaje na početak liste. Ako je vrijednost P veća od ukupnog broja čvorova u 
//listi, novi čvor se dodaje na kraj liste. 
// obrisiCvor, koja za argumente ima pokazivač na prvi čvor liste i cijeli broj P, i 
//koja iz liste briše čvor koji se nalazi na poziciji P. Pozicije su indeksirane od 
//nule. Na primjer, ako je P=0, funkcija treba obriše glavu liste. Ako je vrijednost 
//P veća od ukupnog broja čvorova u listi, ne vršiti brisanje. 
struct cvor{
    int vrijednost;
    struct cvor* sledeci;
};

void stampajListu(struct cvor*& glava){
    struct cvor* tmp=glava;
    while(tmp != NULL){
        cout<<tmp->vrijednost<<" ";
        tmp=tmp->sledeci;
    }
    cout<<endl;
}

void dodajCvor(struct cvor*& glava, int p, int v){

    struct cvor* tmp=glava;
    struct cvor* novi=new struct cvor;
    struct cvor* preth=NULL;
    novi->vrijednost=v;
    if(tmp==NULL){
        tmp=novi;
        tmp->sledeci=NULL;
        return;
    }


    int i=0;
    while(tmp != NULL){
        if(i==p){
           // cout<<endl<<i<<" ";
            preth->sledeci=novi;
            novi->sledeci=tmp;
            return;
           // novi->sledeci=tmp;
        }else{
            preth=tmp;
            tmp=tmp->sledeci;
        }
        i++;
    }
    //cout<<i<<endl;
    if(i<p){
    tmp->sledeci=novi;
    novi->sledeci=NULL;}

}

void obrisiCvor(struct cvor*& glava,int p){
    if(glava == NULL){
        return;
    }

    if (p == 0) {
        struct cvor* stari = glava;
        glava = glava->sledeci;
        delete stari;
        return;
    }

    struct cvor* tmp=glava;
    struct cvor* preth=NULL;
    //preth->sledeci=glava;
    int i=0;
    while(tmp != NULL){
        if(i==p) {
            preth->sledeci = tmp->sledeci;
            delete tmp;
            return;
        }
        preth=tmp;
        tmp=tmp->sledeci;

        i++;
    }


}


int main() {

    struct cvor* c1=new struct cvor;
    struct cvor* c2=new struct cvor;
    struct cvor* c3=new struct cvor;
    struct cvor* c4=new struct cvor;
    c1->sledeci=c2;
    c2->sledeci=c3;
    c3->sledeci=c4;
    c4->sledeci=NULL;
    c1->vrijednost=1;
    c2->vrijednost=11;
    c3->vrijednost=2;
    c4->vrijednost=132;

    struct cvor* glava= c1;
    dodajCvor(glava,1,1312);
    stampajListu(glava);
    obrisiCvor(glava,3);
    stampajListu(glava);



    return 0;
}
