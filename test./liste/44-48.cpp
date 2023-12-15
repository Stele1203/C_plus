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

//44. Napisati funkciju umetni1 koja između svaka dva elementa u jednostruko ulančanoj
//listi umeće element koji predstavlja njihovu razliku.
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

//45. Napisati funkciju umetni2 koja modifikuje datu jednostruko ulančanu listu tako što iza
//svakog elementa djeljivog sa k dodaje -1.
void umetni2(struct cvor*& glava, int k){

    if(glava==NULL){
        return;
    }



    struct cvor* tmp=glava;
    struct cvor* preth=NULL;
    while (tmp != NULL){
        if(tmp->vrijednost % k == 0){
            struct cvor* novi=new struct cvor;
            novi->vrijednost=-1;
            preth->sledeci=novi;
            novi->sledeci=tmp;
            preth=tmp;
            tmp=tmp->sledeci;
        }else{
            preth=tmp;
            tmp=tmp->sledeci;
        }
    }

}
//46. Napisati funkciju dodajNulu koja nakon svakog čvora u jednostruko ulančanoj listi čija
//vrijednost veća od a, a manja od b dodaje čvor sa vrijednošću 0 (a i b su parametri
//ove funkcije).
void dodajNulu(struct cvor*& glava, int a, int b) {

    struct cvor* tmp=glava;

    while(tmp != NULL){

        if(tmp->vrijednost>a && tmp->vrijednost<b){
            struct cvor* novi=new struct cvor;
            novi->vrijednost=0;
            novi->sledeci=tmp->sledeci;
            tmp->sledeci=novi;
            tmp=novi->sledeci;
        }else{
            tmp=tmp->sledeci;
        }

    }

}
//47. Napisati funkciju brisi koja iz jednostruko ulančane liste brise sve čvorove čija je
//vrijednost veća od a, a manja od b (a i b su parametri ove funkcije).
void izbrisiAiB(struct cvor*& glava, int a, int b) {
    struct cvor* tmp=glava;
    struct cvor* preth=NULL;

    while(tmp != NULL){

        if(tmp->vrijednost>a && tmp->vrijednost<b){
            if(preth==NULL){
                tmp=tmp->sledeci;
            }else{
                preth->sledeci=tmp->sledeci;
            }
            delete tmp;
            tmp=preth->sledeci;

        }else{
            preth=tmp;
            tmp=preth->sledeci;
        }

    }

}

// Napisati funkciju brisiSledbenika koja iz date liste briše sljedbenika prvog čvora sa
//zadatom vrijednošću.
void brisiSledbenika(struct cvor*& glava,int v){

    struct cvor* tmp=glava;

    while(tmp->vrijednost != v){
        tmp=tmp->sledeci;
    }

    if(tmp->sledeci==NULL){
        return;
    }
    tmp->sledeci=tmp->sledeci->sledeci;

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
   // umetni(glava);
   // umetni2(glava,2);
    //dodajNulu(glava,1,11);
    stampajListu(glava);
    cout<<endl;
    //izbrisiAiB(glava,5,11);
    brisiSledbenika(glava,5);
    stampajListu(glava);

    return 0;
}
