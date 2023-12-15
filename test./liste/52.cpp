#include <iostream>
#include <string>
using namespace std;
// Napisati funkciju nadjiSredinu koja vraća vrijednost čvora na sredini liste. Na primjer,
//ako je data lista: 2->35->19->5->6, funkcija treba da vrati 19. Pokušati implementaciju
//bez izračunavanja dužine liste i brise je iz cvora
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

void nadjiSredini(struct cvor*& glava){
    struct cvor* spori=glava;
    struct cvor* brzi=glava;
    struct cvor* preth=NULL;

    while((brzi != NULL) && (brzi->sledeci != NULL)){
        preth=spori;
        spori=spori->sledeci;
        brzi=brzi->sledeci->sledeci;
    }
    preth->sledeci=spori->sledeci;
    delete spori;



}

int main() {

    struct cvor* c1=new struct cvor;
    struct cvor* c2=new struct cvor;
    struct cvor* c3=new struct cvor;
    struct cvor* c4=new struct cvor;
    struct cvor* c5=new struct cvor;
    c1->vrijednost=1;
    c2->vrijednost=2;
    c3->vrijednost=3;
    c4->vrijednost=4;
    c5->vrijednost=4;

    c1->sledeci=c2;
    c2->sledeci=c3;
    c3->sledeci=c4;
    c4->sledeci=c5;
    c5->sledeci=NULL;

    struct cvor* glava=c1;
    print(glava);
    cout<<endl;
    nadjiSredini(glava);
    print(glava);

    return 0;
}
