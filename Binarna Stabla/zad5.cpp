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
