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
