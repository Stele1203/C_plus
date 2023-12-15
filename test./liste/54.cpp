#include <iostream>
#include <string>
using namespace std;
// 54. Napisati funkciju prviVeci koja za svaki element u jednostruko ulančanoj listi štampa
//prvi veći element u nastavku liste. Ukoliko u nastavku, za dati element odštampati
//nulu. Na primjer, ako je data lista 15->24->10->22->36, funkcija treba da odštampa
//24 36 22 36 0.
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

void prviVeci(struct cvor*& glava){

    struct cvor* tmp=glava;
    while(tmp != NULL){
        struct cvor* tmp2=tmp;
        while(tmp2 != NULL){
            if(tmp2->vrijednost>tmp->vrijednost){
                cout<<tmp2->vrijednost<<" ";
                break;
            }else if(tmp2->sledeci == NULL){
                cout<<"0 ";
            }
            tmp2=tmp2->sledeci;
        }
        tmp=tmp->sledeci;
    }

}
int main() {

    struct cvor* c1=new struct cvor;
    struct cvor* c2=new struct cvor;
    struct cvor* c3=new struct cvor;
    struct cvor* c4=new struct cvor;
    struct cvor* c5=new struct cvor;
    c1->vrijednost=15;
    c2->vrijednost=24;
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
    prviVeci(glava);

    return 0;
}
