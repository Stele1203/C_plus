double nadjiSredinuHeapa(priority_queue<int,vector<int>,greater<int>>a){
    vector<double> el;

    while(!a.empty()){
        el.push_back(a.top());
        a.pop();
    }

    int n = el.size();
    if (n % 2 == 0) {
        return (el[n / 2] + el[n / 2 - 1]) / 2;
    } else {
        return el[n / 2];
    }
}


void medijana(){
    string unos;
    priority_queue<int,vector<int>,greater<int>>hip;
    cin>>unos;

    while(unos !="0"){
        if(unos=="M"){
            cout<<endl<<nadjiSredinuHeapa(hip);
        }else{
            hip.push(stoi(unos));
        }
        cin>>unos;
    }

}
