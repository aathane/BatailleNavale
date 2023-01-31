
void inventory(int *artillerie, int *bombes, int *tactique, int *simple, char niveau) {

    // On attribue un nombre de missiles de chaque type selon la difficulté

    if (niveau == '1') {
        *artillerie = 10;
        *bombes = 10;
        *tactique = 10;
        *simple = 10;
    }
    if (niveau == '2') {
        *artillerie = 3;
        *bombes = 5;
        *tactique = 5;
        *simple = 10;
    }
    if (niveau == '3') {
        *artillerie = 5;
        *bombes = 2;
        *tactique = 5;
        *simple = 9;
    }
}