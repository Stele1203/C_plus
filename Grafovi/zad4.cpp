/*Napisati program koji provjerava da li u datom neusmjerenom grafu postoji ciklus
dužine > 2.   */


bool dfsSaPreth(int start, graf& graf, int preth, vector<bool>& posjecen) {
    posjecen[start] = true;

    for (int i = 0; i < graf.size(); i++) {
        if (graf[start][i] == 1) {
            if (!posjecen[i]) {
                if (dfsSaPreth(i, graf, start, posjecen)) {
                    return true;
                }
            } else if (i != preth) {
                return true;
            }
        }
    }
    return false;
}


bool postojiCiklus(vector<vector<int>>& graf) {
    int broj_cvorova = graf.size();
    vector<bool> posjecen(broj_cvorova, false);

    for (int i = 0; i < broj_cvorova; i++) {
        if (!posjecen[i]) {
            if (dfsSaPreth(i, graf, -1, posjecen)) {
                return true;
            }
        }
    }

    return false;
}
