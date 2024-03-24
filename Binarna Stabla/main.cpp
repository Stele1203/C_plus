#include <iostream>
#include "queue"
using namespace std;

struct cvor{
    int vrijednost;
    struct cvor* lijevi;
    struct cvor* desni;
};

void dodaj(struct cvor*& korijen,int v){
    if(korijen==NULL){
        struct cvor* novi= new cvor;
        novi->vrijednost=v;
        novi->lijevi=NULL;
        novi->desni=NULL;
        korijen=novi;
        return;
    }

    if(korijen->vrijednost>v)
        dodaj(korijen->lijevi,v);
    else
        dodaj(korijen->desni,v);
}

void ispisi(struct cvor* korijen){
    if(korijen==NULL)
        return;
    cout<<korijen->vrijednost<<" ";
    ispisi(korijen->lijevi);
    ispisi(korijen->desni);
}


bool trazi(struct cvor* korijen, int v){
    if(korijen==NULL)
        return false;

    if(korijen->vrijednost == v)
        return true;

    if(trazi(korijen->lijevi,v))
        return true;
    if(trazi(korijen->desni,v))
        return true;
    return false;
}

int visinaStabla(struct cvor* korijen){
    if(korijen==0)
        return 0;
    int h1= visinaStabla(korijen->lijevi);
    int h2= visinaStabla(korijen->desni);

    if(h1>h2)
        return h1+1;
    else
        return h2+1;
}

int brojCvorova(struct cvor* korijen){
    if(korijen==NULL)
        return 0;
    int broj=1;
    broj+= brojCvorova(korijen->lijevi);
    broj+= brojCvorova(korijen->desni);
    return broj;
}

bool identicni(struct cvor* korijen1, struct cvor* korijen2){
    if(korijen1==NULL && korijen2==NULL)
        return true;
    if(korijen2==NULL)
        return false;
    if(korijen1==NULL)
        return false;

    return identicni(korijen1->lijevi,korijen2->lijevi) && identicni(korijen1->desni,korijen2->desni);
}

void listovi(struct cvor* korijen){
    if(korijen==NULL)
        return;

    if(korijen->lijevi==NULL && korijen->desni==NULL)
        cout<<korijen->vrijednost<<" ";

    listovi(korijen->lijevi);
    listovi(korijen->desni);
}


void dvaSina(struct cvor* korijen){
    if(korijen==NULL)
        return;

    if(korijen->lijevi!=NULL && korijen->desni!=NULL)
        cout<<korijen->vrijednost<<" ";

    dvaSina(korijen->lijevi);
    dvaSina(korijen->desni);
}

int prebroj(struct cvor* korijen) {
    if (korijen==NULL)
        return 0;

    int broj = 0;


    if(korijen->desni==NULL && korijen->lijevi==NULL)
        return 0;

    if (korijen->lijevi==NULL)
        return 0;

    if(korijen->desni==NULL)
        return 0;

    if((korijen->vrijednost % 2 == korijen->desni->vrijednost % 2 ) && (korijen->vrijednost % 2 == korijen->lijevi->vrijednost % 2))
        broj++;

    int broj1 = prebroj(korijen->lijevi);
    int broj2 = prebroj(korijen->desni);
    broj += broj1 + broj2;
    return broj;
}


void suma1(struct cvor* korijen){

    if(korijen==NULL)
        return;

    if(korijen->lijevi==NULL && korijen->desni==NULL)
        return;

    if(korijen->lijevi==NULL){
        if(korijen->desni->vrijednost<korijen->vrijednost)
            cout<<korijen->vrijednost<<" ";
        return;
    }

    if(korijen->desni==NULL){
        if(korijen->lijevi->vrijednost<korijen->vrijednost)
            cout<<korijen->vrijednost<<" ";
        return;
    }

    if((korijen->lijevi->vrijednost + korijen->desni->vrijednost)<korijen->vrijednost)
        cout<<korijen->vrijednost<<" ";


    suma1(korijen->lijevi);
    suma1(korijen->desni);
}

bool simetricnaPomoc(struct cvor* k1, struct cvor* k2){
    if(k1==NULL && k2==NULL)
        return true;

    if(k1==NULL)
        return false;

    if(k2==NULL)
        return false;

    if(k1->vrijednost!=k2->vrijednost){
        return false;
    }

    return simetricnaPomoc(k1->lijevi,k2->desni) && simetricnaPomoc(k1->desni,k2->lijevi);
}

bool simetricna(struct cvor* korijen){

    return simetricnaPomoc(korijen->lijevi,korijen->desni);
}

bool validnoStabloPretrazivanja(struct cvor* korijen){
    if(korijen==NULL)
        return true;

    if((korijen->lijevi !=NULL && korijen->lijevi->vrijednost>korijen->vrijednost) || (korijen->desni != NULL && korijen->desni->vrijednost<korijen->vrijednost))
        return false;

    return validnoStabloPretrazivanja(korijen->lijevi) && validnoStabloPretrazivanja(korijen->desni);
}

int najmanjaDubinaBroj(struct cvor* korijen) {
    if (korijen == NULL) {
        return 0;
    }

    int dubinaLijevo = najmanjaDubinaBroj(korijen->lijevi);
    int dubinaDesno = najmanjaDubinaBroj(korijen->desni);

    return 1 + min(dubinaLijevo, dubinaDesno);
}


struct cvor* najmanjaDubina(struct cvor* korijen, int trenDub = 0) {
    if (korijen == NULL)
        return NULL;

    if (korijen->lijevi == NULL && korijen->desni == NULL)
        return korijen;

    struct cvor* levo = najmanjaDubina(korijen->lijevi, trenDub + 1);
    if (levo != NULL)
        return levo;

    return najmanjaDubina(korijen->desni, trenDub + 1);
}

void obilazakPoNivoima(cvor* korijen) {
    if (korijen == NULL)
        return;

    queue<cvor*> red;
    red.push(korijen);

    while (!red.empty()) {
        cvor* trenutni = red.front();
        red.pop();

        cout << trenutni->vrijednost << " ";

        if (trenutni->lijevi != NULL)
            red.push(trenutni->lijevi);
        if (trenutni->desni != NULL)
            red.push(trenutni->desni);
    }
}

void izbrisiSveizReda(queue<cvor*> &red){

    while (!red.empty()){
        red.pop();
    }
}


void najvecaDubina(struct cvor* korijen){
    if(korijen==NULL)
        return;

    queue<pair<cvor*,int>> red;
    queue<cvor*> pomocni;
    red.push(make_pair(korijen,1));
    int najDubljaDubina=0;

    while (!red.empty()){
        pair<cvor*,int> trenutni=red.front();
        red.pop();

        cvor* trenutniCvor= trenutni.first;
        int trenutniNivo=trenutni.second;

        if(trenutniNivo> najDubljaDubina){
            najDubljaDubina=trenutniNivo;
            izbrisiSveizReda(pomocni);
        }
        if(trenutniNivo==najDubljaDubina)
            pomocni.push(trenutniCvor);


        if(trenutniCvor->lijevi != NULL) {
            red.push(make_pair(trenutniCvor->lijevi, trenutniNivo + 1));
        }
        if(trenutniCvor->desni != NULL) {
            red.push(make_pair(trenutniCvor->desni, trenutniNivo + 1));

        }
    }

    while (!pomocni.empty()){
        cvor* tren=pomocni.front();
        pomocni.pop();
        cout<<tren->vrijednost<<" ";
    }
}

int suma2(struct cvor*& korijen,int d){
    if(korijen==NULL)
        return 0;

    queue<pair<cvor*,int>> red;
    red.push(make_pair(korijen,1));
    int sum1=0;
    int sum2=0;
    while(!red.empty()){
        pair<cvor*,int> tren=red.front();
        red.pop();
        if(tren.second==d){
            if(tren.first->vrijednost % 2 == 0)
                sum1+=tren.first->vrijednost;
            else
                sum2+=tren.first->vrijednost;
        }
        if(tren.first->lijevi != NULL)
            red.push(make_pair(tren.first->lijevi,tren.second+1));

        if(tren.first->desni != NULL)
            red.push(make_pair(tren.first->desni,tren.second+1));

    }

    return sum1-sum2;
}
int main() {
    struct cvor* korijen=NULL;
    dodaj(korijen,15);
    dodaj(korijen,7);
    dodaj(korijen,20);
    dodaj(korijen,3);
    dodaj(korijen,14);
    dodaj(korijen,17);
    dodaj(korijen,23);
    dodaj(korijen,10);
    dodaj(korijen,14);

    struct cvor* korijen2=NULL;
    dodaj(korijen2,15);
    dodaj(korijen2,7);
    dodaj(korijen2,21);
    dodaj(korijen2,3);
    dodaj(korijen2,12);
    dodaj(korijen2,17);
    dodaj(korijen2,11);
    dodaj(korijen2,14);

    ispisi(korijen);
    cout<<endl;
    if(trazi(korijen,2))
        cout<<"da";
    else
        cout<<"ne";

    cout<<endl<<visinaStabla(korijen);
    cout<<endl<<brojCvorova(korijen);

    cout<<endl;
    cout<<identicni(korijen,korijen2)<<endl;

    if(identicni(korijen,korijen2))
        cout<<"da";
    else
        cout<<"ne";


    cout<<endl;

    listovi(korijen);
    cout<<endl;

    dvaSina(korijen);
    cout<<endl;

    struct cvor*  c1 = new struct cvor;
    c1->vrijednost = 1;
    struct cvor*  c2 = new struct cvor;
    c2->vrijednost = 7;
    struct cvor*  c3 = new struct cvor;
    c3->vrijednost = 7;
    struct cvor*  c4 = new struct cvor;
    c4->vrijednost = 8;
    struct cvor*  c5 = new struct cvor;
    c5->vrijednost = 9;
    struct cvor*  c6 = new struct cvor;
    c6->vrijednost = 9;
    struct cvor*  c7 = new struct cvor;
    c7->vrijednost = 8;
    struct cvor*  c8 = new struct cvor;
    c8->vrijednost = 10;
    struct cvor*  c9 = new struct cvor;
    c9->vrijednost = 11;
    struct cvor*  c10 = new struct cvor;
    c10->vrijednost = 11;
    struct cvor*  c11 = new struct cvor;
    c11->vrijednost = 10;

    c1->lijevi=c2;
    c1->desni=c3;
    c2->lijevi=c4;
    c2->desni=c5;
    c5->lijevi=c8;
    c5->desni=c9;
    c8->lijevi=NULL;
    c8->desni=NULL;
    c9->lijevi=NULL;
    c9->desni=NULL;
    c3->lijevi=c6;
    c3->desni=c7;
    c7->lijevi=NULL;
    c7->desni=NULL;
    c6->lijevi=c10;
    c6->desni=c11;
    c10->lijevi=NULL;
    c10->desni=NULL;
    c11->lijevi=NULL;
    c11->desni=NULL;
    c4->lijevi=NULL;
    c4->desni=NULL;

    cout<<prebroj(korijen)<<endl<<"Suma"<<endl;
    //korijen = c1;

    suma1(korijen);
    cout<<endl;
    if(simetricna(korijen)){
        cout<<"Simentricna";
    }else{
        cout<<"Nije simetricna";
    }

    cout<<endl;
    if(validnoStabloPretrazivanja(korijen)){
        cout<<"Validno";
    }else{
        cout<<"Nije validno";
    }

    //cout<<endl<<najmanjaDubinaBroj(korijen);
    cout<<endl<<najmanjaDubina(korijen)->vrijednost;

    cout<<endl;
    obilazakPoNivoima(korijen);
    cout<<endl;
    najvecaDubina(korijen);
    cout<<endl;
    cout<<suma2(korijen,3);
    return 0;
}
