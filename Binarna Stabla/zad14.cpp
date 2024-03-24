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
