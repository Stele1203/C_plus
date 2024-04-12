/*Napisati program koji provjerava da li je dati neusmjereni graf povezan. */

bool grafPovezan(graf graf){
    vector<bool>posjecen(graf.size(),false);

    dfs(0,graf,posjecen);

    for(int i=0;i<graf.size();i++){
        if(!posjecen[i])
            return false;
    }

    return true;
}
