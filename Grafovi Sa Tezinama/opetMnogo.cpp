#include <iostream>
#include "vector"
#include "queue"
#include "algorithm"
#include "stack"
#include "math.h"
using namespace std;

/*
6
8
0
0 1 1
1 2 4
3 4 3
4 5 4
0 3 4
1 3 2
1 4 7
2 5 3
*/


vector<vector<int>> ucitajGraf(){
    int n,m,usmjeren;
    cin>>n>>m>>usmjeren;

    vector<vector<int>>graf(n,vector<int>(n,-1000));

    for(int i=0;i<m;i++){
        int x,y,t;
        cin>>x>>y>>t;
        graf[x][y]=t;

        if(!usmjeren){
            graf[y][x]=t;
        }
    }
    return graf;
}

vector<vector<int>>ucitajBezGraf(){
    int n,m,usmjeren;
    cin>>n>>m>>usmjeren;

    vector<vector<int>>graf(n,vector<int>(n,0));

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graf[x][y]=1;
        if(!usmjeren)
            graf[y][x]=1;
    }
    return graf;
}

int najkraciPut(vector<vector<int>>& graf,int start,int kraj,vector<bool>posjecen){
    if(start==kraj){
        return 0;
    }

    posjecen[start]= true;
    int minPutanja=INT_MAX;

    for(int i=0;i<graf.size();i++){
        if(graf[start][i]>0 && !posjecen[i]){
            int putanja= najkraciPut(graf,i,kraj,posjecen);

            if(putanja != INT_MAX && putanja+graf[start][i]<minPutanja){
                minPutanja=putanja+graf[start][i];
            }
        }
    }
    posjecen[start]=false;
    return minPutanja;
}


vector<int> dijakstra(vector<vector<int>>graf,int start){
    vector<int> distanca(graf.size(),INT_MAX);
    vector<bool> posjecen(graf.size(),false);

    distanca[start]=0;

    while(true){
        int tren=-1;
        int minDis=INT_MAX;

        for(int i=0;i<graf.size();i++){
            if(!posjecen[i] && distanca[i]<minDis){
                minDis=distanca[i];
                tren=i;
            }
        }

        if(tren == -1){
            break;
        }

        posjecen[tren]=true;

        for(int i=0;i<graf.size();i++){
            if(graf[tren][i] != -1000 && !posjecen[i]){
                if(distanca[i]>distanca[tren]+graf[tren][i]){
                    distanca[i]=distanca[tren]+graf[tren][i];
                }
            }
        }
    }
    return distanca;
}

vector<vector<int>> floyd_warshall(vector<vector<int>>& graf){
    vector<vector<int>> distacna(graf.size(),vector<int>(graf.size()));

    for(int i=0;i<graf.size();i++){
        for(int j=0;i<graf.size();j++){
            if(i==j){
                distacna[i][j]=0;
            }else if (graf[i][j] != -1000){
                distacna[i][j]=graf[i][j];
            }else
                distacna[i][j]=INT_MAX;
        }
    }

    for(int k=0;k<graf.size();k++){
        for(int i=0;i<graf.size();i++){
            for(int j=0;j<graf.size();j++){
                if(distacna[i][k] != INT_MAX && distacna[k][j] != INT_MAX){
                    if(distacna[i][j]>distacna[i][k]+distacna[k][j]){
                        distacna[i][j]=distacna[i][k]+distacna[k][j];
                    }
                }
            }
        }
    }
    return distacna;
}


void dfs(vector<vector<int>>graf,int start,vector<bool>& posjecen){
    posjecen[start]= true;

    for(int i=0;i<graf.size();i++){
        if (graf[start][i]==1 && !posjecen[i]){
            dfs(graf,i,posjecen);
        }
    }
}

int racunarska_mreza(vector<vector<int>>graf){
    cout<<"aaaaaaaaaaaa";
    int brCmp=0;
    vector<bool>posjecen(graf.size(),false);
    for(int i=0;i<graf.size();i++){
        if(!posjecen[i]){
            brCmp++;
            dfs(graf,i,posjecen);
        }
    }


    return brCmp-1;

}

int numberOfTrue(vector<bool>& niz){
    int c=0;
    for(int i=0;i<niz.size();i++){
        if(niz[i]){
            c++;
            niz[i]=false;
        }
    }
    return c;
}

int prijatelji(vector<vector<int>>graf){
    vector<bool>posjece(graf.size(),false);
    int max=INT_MIN;
    int tren=0;
    for(int i=0;i<graf.size();i++){
        if(!posjece[i]){
            tren=numberOfTrue(posjece);
            if(tren>max){
                max= tren;
            }
            dfs(graf,i,posjece);
         }

        }
    tren= numberOfTrue(posjece);
    if(tren>max){
        max=tren;
    }

    return max;
}


struct stanica{
    int x,y;
};

vector<pair<int,int>>ucitajStanicu(){
    int n;
    cin>>n;
    vector<pair<int,int>>stanice(n);
    for(int i=0;i<n;i++){
        cin>>stanice[i].first>>stanice[i].second;
    }

    return stanice;
}

int obradiStanice(){

    vector<pair<int,int>>stanice=ucitajStanicu();

    vector<vector<int>>graf(stanice.size(),vector<int>(stanice.size(),0));

    for(int i=0;i<stanice.size();i++){
        for(int j=0;j<stanice.size();j++){
            if(stanice[i].first == stanice[j].first || stanice[i].second == stanice[j].second){
                graf[i][j]=1;
                graf[j][i]=1;
            }
        }
    }

    vector<bool>posjecen(graf.size(),false);
    int br=0;
    for(int i=0;i<graf.size();i++){
        if(!posjecen[i]){
            br++;
            dfs(graf,i,posjecen);
        }
    }

    return br-1;
}


vector<vector<char>>ucitajNaftna(int n,int m){
    vector<vector<char>>naftna(n,vector<char>(m));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>naftna[i][j];
        }
    }
    return naftna;
}

int dX[]={-1,1,0,0,-1,1,1,-1};
int dY[]={0,0,-1,1,1,-1,1,-1};

bool isValid(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x,int y,int n,int m,vector<vector<char>>& matrix,vector<vector<bool>>& posjecen){
    posjecen[x][y]= true;

    for(int i=0;i<8;i++){
        int newX=x+dX[i];
        int newY=y+dY[i];

        if(isValid(newX,newY,n,m) && matrix[newX][newY]=='*' && !posjecen[newX][newY]){
            dfs(newX,newY,n,m,matrix,posjecen);
        }
    }
}

int naftnaPoziv(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>naftna= ucitajNaftna(n,m);
    vector<vector<bool>>posjecen(n,vector<bool>(m,false));

    int cmp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(naftna[i][j]=='*' && !posjecen[i][j]){
                cmp++;
                dfs(i,j,n,m,naftna,posjecen);
            }
        }
    }
    return cmp;
}


vector<vector<char>> ucitajZidove(int n,int m){
    vector<vector<char>>zidovi(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>zidovi[i][j];
        }
    }
    return zidovi;
}



void dfsZidovi(int x, int y, int n, int m, vector<vector<char>>& matrix, vector<vector<bool>>& posjecen) {
    posjecen[x][y] = true;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(newX, newY, n, m) && matrix[newX][newY] == '.' && !posjecen[newX][newY]) {
                dfsZidovi(newX, newY, n, m, matrix, posjecen);
            }
        }
    }
}


int zidoviBrCmp(vector<vector<char>>& matrix,int n,int m){
    vector<vector<bool>>posjecen(n,vector<bool>(m,false));
    int cmp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='.' && !posjecen[i][j]){
              cmp++;
                dfsZidovi(i,j,n,m,matrix,posjecen);
            }
        }
    }
    return cmp;
}
void ispisiMatrix(vector<vector<char>>matrix,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}


void zidoviPoziv() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> matrix = ucitajZidove(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                matrix[i][j] = 'X'; // Postavljamo zid na trenutno polje
                if (zidoviBrCmp(matrix, n, m) == 1) { // Proveravamo povezanost
                    k--; // Smanjujemo broj preostalih zidova
                    if (k == 0) { // Ako smo postavili sve zidove, završavamo
                        ispisiMatrix(matrix, n, m);
                        return;
                    }
                } else {
                    matrix[i][j] = '.'; // Ako zid ne održava povezanost, vraćamo polje na prethodno stanje
                }
            }
        }
    }
    ispisiMatrix(matrix, n, m); // Štampamo trenutno stanje matrice
}


void dfsZaPrethodnike(vector<vector<int>>graf,int tren,int start,vector<bool>& posjecen,vector<vector<int>>&prethodni){
    posjecen[tren]=true;
    prethodni[tren][start]=1;

    for(int i=0;i<graf.size();i++){
        if(!posjecen[i] && graf[tren][i]==1){
            dfsZaPrethodnike(graf,i,start,posjecen,prethodni);
        }
    }
}


void prethodnici(vector<vector<int>>graf){
    vector<vector<int>>prethodni(graf.size(),vector<int>(graf.size(),0));

    for(int i=0;i<graf.size();i++){
        vector<bool>posjecen(graf.size(),false);
        dfsZaPrethodnike(graf,i,i,posjecen,prethodni);
    }


    for(int i=0;i<graf.size();i++){
        bool t=false;

        for(int j=0;j<graf.size();j++){
            if(prethodni[i][j]==1 && j!=i){
                cout<<j<<" ";
                t= true;
            }
        }
        if(!t){
            cout<<-1<<" ";
        }
        cout<<endl;
    }
}


void dfsZaStudente(vector<vector<int>>graf,vector<bool>& posjecen,int start,stack<int>& topoloski){
    posjecen[start]=true;

    for(int i=0;i<graf.size();i++){
        if(graf[start][i]==1 && !posjecen[i]){
            dfsZaStudente(graf,posjecen,i,topoloski);
        }
    }

    topoloski.push(start);
}

void topolosko_Sortiranje(vector<vector<int>>graf){
    vector<bool>posjecen(graf.size(),false);
    stack<int>stek;

    for(int i=0;i<graf.size();i++){
        if(!posjecen[i]){
            dfsZaStudente(graf,posjecen,i,stek);
        }
    }

    while(!stek.empty()){
        cout<<stek.top()<<" ";
        stek.pop();
    }
}

double roundUp(double num, int decimalPlaces) {
    double factor = pow(10.0, decimalPlaces);
    return ceil(num * factor) / factor;
}


int mreze(vector<vector<int>> graf){
    vector<vector<int>> distanca(graf.size(),vector<int>(graf.size()));
    for(int i=0;i<graf.size();i++){
        for(int j=0;j<graf.size();j++){
            if(i==j)
                distanca[i][j]=0;
            else if(graf[i][j] !=-1000){
                distanca[i][j]=graf[i][j];
            }else
                distanca[i][j]=INT_MAX;
        }
    }


    for (int k = 0; k < graf.size(); k++) {
        for (int i = 0; i < graf.size(); i++) {
            for (int j = 0; j < graf.size(); j++) {
                if (distanca[i][k] != INT_MAX && distanca[k][j] != INT_MAX) {
                    if (distanca[i][j] > distanca[i][k] + distanca[k][j]) {
                        distanca[i][j] = distanca[i][k] + distanca[k][j];
                    }
                }
            }
        }
    }

    int sum=0;
    int c=0;

    for(int i=0;i<distanca.size();i++){
        for(int j=0;j<distanca[0].size();j++){
            if(distanca[i][j] != INT_MAX && i != j){
                sum+=distanca[i][j];
                c++;
            }
        }
    }
    double avg=(double)(sum/c);
    cout<<avg;
    return roundUp(avg,2);
}


void dfsZaGradove(vector<vector<int>>graf,int start,vector<bool>& posjecen){
    posjecen[start]=true;

    for(int i=0;i<graf.size();i++){
        if(graf[start][i]==1 && !posjecen[i]){
            dfsZaGradove(graf,i,posjecen);
        }
    }
}
bool provjeriGradove(vector<bool> grad){
    for(int i=0;i<grad.size();i++){
        if(!grad[i])
            return false;
    }
    return true;
}

void gradovi(vector<vector<int>>graf){
    vector<int> rez;

    for(int i=0;i<graf.size();i++){
        vector<bool>posjecen(graf.size(),false);
        dfsZaGradove(graf,i,posjecen);
        if(provjeriGradove(posjecen)){
            rez.push_back(i);
        }
    }

    cout<<rez.size()<<endl;
    if(rez.size()>0){
        for(int i=0;i<rez.size();i++){
            cout<<rez[i]<<" ";
        }
    }
}
int main() {
   // vector<vector<int>>graf=ucitajBezGraf();
    /*vector<bool>posjecen(graf.size(),false);

    cout<<najkraciPut(graf,0,5,posjecen);
    cout<<endl;
    cout<<dijakstra(graf,0)[5];

    cout<<endl;*/

    //cout<<racunarska_mreza(graf);
    //cout<<prijatelji(graf);

   // cout<<obradiStanice();

  // cout<<naftnaPoziv();
  //zidoviPoziv();
   // prethodnici(ucitajBezGraf());
    //prethodnici(ucitajBezGraf());

    //topolosko_Sortiranje(ucitajBezGraf());

   //cout<<mreze(ucitajGraf());


    gradovi(ucitajBezGraf());
    return 0;
}
