#include <iostream>
#include <vector>
#include <climits> // INT_MAX
#include "cfloat"
#include "queue"
#include "math.h"
using namespace std;

vector<vector<int>> ucitajGraf() {
    int n, m, usmjeren;
    cin >> n >> m >> usmjeren;
    vector<vector<int>> graf(n, vector<int>(n, -1000));
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        graf[x][y] = t;

        if (!usmjeren) {
            graf[y][x] = t;
        }
    }
    return graf;
}

vector<vector<double>> ucitajGrafDouble() {
    int n, m, usmjeren;
    cin >> n >> m >> usmjeren;
    vector<vector<double>> graf(n, vector<double>(n, -1000));
    for (int i = 0; i < m; i++) {
        int x, y;
        double t;
        cin >> x >> y >> t;
        graf[x][y] = t;

        if (!usmjeren) {
            graf[y][x] = t;
        }
    }
    return graf;
}

vector<int> dijakstra(vector<vector<int>>& graf, int start) {
    vector<int> distanca(graf.size(), INT_MAX);
    vector<bool> posjecen(graf.size(), false);

    distanca[start] = 0;

    while (true) {
        int tren = -1;
        int min = INT_MAX;

        for (int i = 0; i < graf.size(); i++) {
            if (!posjecen[i] && distanca[i] < min) {
                min = distanca[i];
                tren = i;
            }
        }

        if (tren == -1) {
            break;
        }

        posjecen[tren] = true;
        for (int i = 0; i < graf.size(); i++) {
            if (graf[tren][i] != INT_MAX && !posjecen[i]) {
                if (distanca[i] > distanca[tren] + graf[tren][i]) {
                    distanca[i] = distanca[tren] + graf[tren][i];
                }
            }
        }
    }
    return distanca;
}

int racunari(vector<vector<int>> graf, int start) {
    vector<int> d = dijakstra(graf, start);
    int max = 0;
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
        if (d[i] == -1000) {
            return -1;
        } else if (d[i] > max) {
            max = d[i];
        }
    }
    cout << endl;
    return max;
}


vector<vector<int>>floyd_warshall(vector<vector<int>>&graf){
    vector<vector<int>>distanca(graf.size(),vector<int>(graf.size()));

    for(int i=0;i<graf.size();i++){
        for(int j=0;j<graf.size();j++){
            if(i==j)
                distanca[i][j]=0;
            else if(graf[i][j] != -1000)
                distanca[i][j]=graf[i][j];
            else
                distanca[i][j]=INT_MAX;
        }
    }

    for(int k=0;k<graf.size();k++){
        for(int i=0;i<graf.size();i++){
            for(int j=0;j<graf.size();j++){
                if(distanca[i][k] != INT_MAX && distanca[k][j] != INT_MAX){
                    if(distanca[i][j]>distanca[i][k]+distanca[k][j]){
                        distanca[i][j]=distanca[i][k]+distanca[k][j];
                    }
                }
            }
        }
    }
    return distanca;
}


int gradoviSaDistancom(vector<vector<int>>graf,int d){
    vector<vector<int>>gradovi= floyd_warshall(graf);
    int min=INT_MAX;
    int minIndex=INT_MAX;
    for(int i=0;i<gradovi.size();i++){
        int trenMin=0;
        for(int j=0;j<gradovi[0].size();j++){
            if(gradovi[i][j]<=4){
                trenMin++;
            }
        }
        if(trenMin<min){
            minIndex=i;
            min=trenMin;
        }
    }

    return minIndex;
}


/*vector<double> dijakstraZad17(vector<vector<double>>graf,int start,vector<int>& prethodni){

    vector<double>distanca(graf.size(),-100);
    vector<bool>posjecen(graf.size(),false);
    distanca[start]=1.0;

    while (true){
        int tren=-1;
        double max=-100;

        for(int i=0;i<graf.size();i++){
            if(distanca[i]>max && !posjecen[i]){
                tren=i;
                max=distanca[i];
            }
        }

        if(tren == -1 )
            break;

        posjecen[tren]=true;

        for(int i=0;i<graf.size();i++){
            if(!posjecen[i] && graf[tren][i] != -1000){
                if(distanca[i]<graf[tren][i]*distanca[tren]){
                    prethodni[i]=tren;
                    distanca[i]=graf[tren][i]*distanca[tren];
                }
            }
        }

    }
    return distanca;
}

void ispisiPutanj(vector<int> prethodni,int start,int kraj){
    if(kraj==start){
        cout<<start<<" ";
        return;
    }
    ispisiPutanj(prethodni,start,prethodni[kraj]);
}*/


float zad7(int start,int kraj,vector<vector<double>>graf,vector<bool>& posjecen,vector<int>& prethodni){
    if(start==kraj){
        return 1;
    }
    float max_vjv=-1;
    posjecen[start]=true;
    prethodni[start]=-1;

    for(int i=0;i<graf.size();i++){
        if(graf[start][i]>0 && !posjecen[i]){
            float tren= zad7(i,kraj,graf,posjecen,prethodni);
            if(tren*graf[start][i]>max_vjv){
                max_vjv=tren*graf[start][i];
                prethodni[start]=i;
            }
        }
    }
    posjecen[start]=false;
    return max_vjv;
}


void zad12Poziv(vector<vector<double>>graf,int start,int kraj){
    vector<int>prethodni(graf.size(),-1);
    vector<bool>posjecen(graf.size(),false);
    cout<<zad7(start,kraj,graf,posjecen,prethodni)<<endl;
    int p=start;
    cout<<start<<" ";
    while (prethodni[p] != -1){
        cout<<prethodni[p]<<" ";
        p=prethodni[p];
    }
    cout<<endl;
}

void pronadjiPoslednjiCvor(vector<vector<int>>graf ,int tren,int& kraj, vector<bool>&posjecen){
    posjecen[tren]=true;
    kraj=tren;
    int minCijena=0;
    for(int i=0;i<graf.size();i++){

    }
}


vector<int> topologicalSort(vector<vector<int>>& adj_matrix, int N) {
    vector<int> in_degree(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj_matrix[i][j] != INT_MAX) {
                in_degree[j]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> sorted_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sorted_order.push_back(u);

        for (int v = 0; v < N; v++) {
            if (adj_matrix[u][v] != INT_MAX) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    // Check for cycles (if sort fails, return empty vector)
    if (sorted_order.size() != N) {
        return vector<int>();
    }

    return sorted_order;
}

int minCostHierarchy(vector<vector<int>>& adj_matrix, int N) {
    // Perform Topological Sort
    vector<int> sorted_order = topologicalSort(adj_matrix, N);

    // Check for cycles
    if (sorted_order.empty()) {
        return -1;
    }

    int min_cost = 0;
    // Iterate through employees in sorted order
    for (int i : sorted_order) {
        // Iterate through possible subordinates
        for (int j = 0; j < N; j++) {
            if (adj_matrix[i][j] != INT_MAX) {
                min_cost += adj_matrix[i][j];
            }
        }
    }

    return min_cost;
}


struct offer{
    int x,y,c;
};

struct compareOffers{
    bool operator()(offer& o1, offer& o2){
        return o1.c>o2.c;
    }
};

int find_boss(int x,vector<int> supervisor){
    if(x==supervisor[x]){
        return x;
    }

    return find_boss(supervisor[x],supervisor);
}

int hierarchy(){
    int n,m;

    cin>>n>>m;

    priority_queue<struct offer,vector<struct offer>,compareOffers>offers;

    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        offers.push({x,y,c});
    }

    vector<int> supervisor(n);
    for(int i=0;i<n;i++){
        supervisor[i]=i;
    }

    int sum=0;

    while (!offers.empty()){
        struct offer temp=offers.top();
        offers.pop();

        if(supervisor[temp.y]==temp.y && find_boss(temp.x,supervisor) != temp.y){
            supervisor[temp.y]=temp.x;
            sum +=temp.c;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
       // cout<<supervisor[i]<<" ";
        if(supervisor[i]==i){
            cnt++;
        }
    }

    if(cnt>1)
        return -1;

    return sum;
}


///20. zad

struct Tacka{
    int x,y;
};

int getLength(int i,int j,vector<struct Tacka>& tacke){
    return abs(tacke[i].x-tacke[j].x)+ abs(tacke[i].y-tacke[j].y);
}

struct bridge{
    int tacka1;
    int tacka2;
    int length;
};


int find_root(int x,vector<int>parents){
    if(parents[x]==x)
        return x;

    int root= find_root(parents[x],parents);
    parents[x]=root;
    return root;
}

void unite(int x,int y,vector<int>&parents,vector<int>&ranks){
    int rx= find_root(x,parents);
    int ry= find_root(y,parents);

    if(ranks[rx]<ranks[ry]){
        parents[rx]=ry;
    }else if(ranks[rx]>ranks[ry]){
        parents[ry]=rx;
    }else{
        parents[rx]=ry;
        ranks[rx]++;
    }
}


struct compareBridge{
    bool operator()(bridge& b1,bridge& b2){
        return b1.length>b2.length;
    }
};

int poveziTacke(){
    int n;
    cin>>n;
    vector<int>parents(n);
    vector<int>ranks(n);
    vector<struct Tacka>tacke;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        parents[i]=i;
        ranks[i]=0;
        tacke.push_back({x,y});
    }

    priority_queue<struct bridge,vector<struct bridge>,compareBridge>pq;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({i,j, getLength(i,j,tacke)});
        }
    }

    int s=0;

    while (!pq.empty()){
        struct bridge tmp=pq.top();
        pq.pop();

        if(find_root(tmp.tacka1,parents) != find_root(tmp.tacka2,parents)){
            unite(tmp.tacka1,tmp.tacka2,parents,ranks);
            s+=tmp.length;
        }
    }

    return s;
}

////zad4
struct zgrada{
    int x,y;
};

struct kabl{
    int z1,z2;
    float d;
};

struct compareKabl{
    bool operator()(kabl& k1, kabl& k2){
        return k1.d>k2.d;
    }
};

float getDistanca(int i,int j,vector<struct zgrada>& zgrade){
    return sqrt((zgrade[i].x-zgrade[j].x)*(zgrade[i].x-zgrade[j].x)+(zgrade[i].y-zgrade[j].y)*(zgrade[i].y-zgrade[j].y));
}


float zgrada_kabl(){
    int n,k;
    cin>>n>>k;

    vector<struct zgrada>zgrade;
    vector<int>parent(n);
    vector<int>rank(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        zgrade.push_back({x,y});
        parent[i]=i;
        rank[i]=0;
    }

    int m;
    cin>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        unite(x,y,parent,rank);
    }

    priority_queue<struct kabl,vector<struct kabl>,compareKabl>pq;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({i,j, getDistanca(i,j,zgrade)});
        }
    }

    float s=0;

    while(!pq.empty()){
        struct kabl k= pq.top();
        pq.pop();

        if(find_root(k.z1,parent) != find_root(k.z2,parent)){
            unite(k.z1,k.z2,parent,rank);
            s+=k.d;
        }
    }
    return round(k*s*100)/100;
}

///zad21

struct village{
    int x,y,imaVodu;
};

struct poveziSelo{
    int v1,v2;
    float c;
};

struct compareSelo{
    bool operator()(poveziSelo& p1, poveziSelo& p2){
        return p1.c>p2.c;
    }
};

float get_selo_leng(int i,int j,vector<struct village>& sela){
    return sqrt(pow(sela[i].x-sela[j].y,2)+pow(sela[i].y-sela[j].y,2));
}

float vodovod(){
    int n,k;
    cin>>n>>k;
    int seloSaVodom=-1;
    vector<int> parent(n);
    vector<int> rank(n);

    vector<struct village>sela;

    for(int i=0;i<n;i++){
        int x,y,t;
        cin>>x>>y>>t;
        sela.push_back({x,y,t});
        if(t==1)
            seloSaVodom=i;

        parent[i]=i;
        rank[i]=0;
    }

    priority_queue<struct poveziSelo,vector<struct poveziSelo>,compareSelo>pq;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push({i,j, get_selo_leng(i,j,sela)});
        }
        if(sela[i].imaVodu){
            unite(i,seloSaVodom,parent,rank);
        }
    }
    float sum=0;
    while (!pq.empty()){
        struct poveziSelo p =pq.top();
        pq.pop();
        if(find_root(p.v1,parent) != find_root(p.v2,parent)){
            unite(p.v1,p.v2,parent,rank);
            sum+=p.c;
        }
    }

    return round(sum*k*100)/100;
}
int main() {
    /*vector<vector<int>> graf = ucitajGraf();

    *//*int rezultat = racunari(graf, 0);
    cout << "Maksimalna udaljenost: " << rezultat << endl;
     *//*
    *//*int d;
    cout<<"Unesi distancu"<<endl;
    cin>>d;
    cout<<endl<<gradoviSaDistancom(graf,d);*//*

    //zad17(graf,0,2);

   // zad12Poziv(graf,0,2);

   int min_cost= minCostHierarchy(graf,graf.size());
   cout<<min_cost;*/

   // cout<<hierarchy();

  // cout<<poveziTacke();

  //cout<<zgrada_kabl();

  cout<<vodovod();
    return 0;
}
