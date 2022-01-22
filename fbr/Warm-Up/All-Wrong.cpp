string getWrongAnswers(int N, string C) {
    for (char &c : C) {
        if (c == 'A') c = 'B';
        else          c = 'A';
    }
    return C;
}n
