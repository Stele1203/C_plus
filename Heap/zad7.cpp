int kTiElement(priority_queue<int,vector<int>,less<int>> hip,int k){
    if(k>hip.size()){
        cout<<"Vece k od velicine";
        exit(1);
    }
    for(int i=0;i<k-1;i++){
        hip.pop();
    }
    return hip.top();
}

void qTiBroj(){
    string unos;
    priority_queue<int,vector<int>,less<int>>hip;
    cin>>unos;
    int k=1;

    while(unos != "0"){
        if(unos=="K"){
            cin>>unos;
            k= stoi(unos);
        }else if(unos=="Q"){
            cout<<kTiElement(hip,k);
        }else{
            hip.push(stoi(unos));
        }
        cin>>unos;
    }

}
