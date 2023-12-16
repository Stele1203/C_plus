#include <iostream>
#include <string>
using namespace std;
//Napisati funkciju dodajKti koja nakon svakog k-tog (k>0) elementa u listi dodaje čvor
//sa vrijednošću v (k i v su parametri ove funkcije). Na primjer, ukoliko je data lista 1-
//>2->3->4->5, k=2 i v=0, rezultujuća lista treba da izgleda ovako: 1->2->0->3->4->0-
//>5.
struct cvor{
    int vrijednost;
    struct cvor* sledeci;
};
void print(struct cvor*& glava){
    struct cvor* tmp=glava;
    while(tmp != NULL){
        cout<<tmp->vrijednost<<" ";
        tmp=tmp->sledeci;
    }
}

void dodajKti(struct cvor*& glava,int k,int v){
    struct cvor* novi=new struct cvor;
    novi->vrijednost=v;
    struct cvor* tmp=glava;
    struct cvor* preth=NULL;

    int i=1;
    while(tmp != NULL){

        if(k==i){
                struct cvor* p= tmp->sledeci;
                novi->sledeci = p;
                tmp->sledeci = novi;
                break;
        }
        preth=tmp;
        tmp=tmp->sledeci;
        i++;

    }
    if (tmp == NULL && k == i) {
        preth->sledeci = novi;
        novi->sledeci=NULL;
    }


}


int main() {

    struct cvor* c1=new struct cvor;
    struct cvor* c2=new struct cvor;
    struct cvor* c3=new struct cvor;
    struct cvor* c4=new struct cvor;
    struct cvor* c5=new struct cvor;
    c1->vrijednost=23;
    c2->vrijednost=2;
    c3->vrijednost=54;
    c4->vrijednost=22;
    c5->vrijednost=32;

    c1->sledeci=c2;
    c2->sledeci=c3;
    c3->sledeci=c4;
    c4->sledeci=c5;
    c5->sledeci=NULL;

    struct cvor* glava=c1;
    print(glava);
    cout<<endl;
    dodajKti(glava,1,1312);
    print(glava);

    return 0;
}
