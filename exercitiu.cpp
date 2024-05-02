#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_FILME = 50;
const int MAX_TITLU = 100;
const int MAX_REGIZOR = 50;

// Structura pentru filme
struct Film {
    char titlu[MAX_TITLU];
    char regizor[MAX_REGIZOR];
    int an;
    float rating;
    double incasari; // Am modificat tipul pentru incasari
    char gen[MAX_REGIZOR];
    char actori[MAX_REGIZOR];
};

// Functie pentru afisarea meniului
void afisareMeniu() {
    cout << "\n1. Afisare toate filmele";
    cout << "\n2. Adaugare film nou";
    cout << "\n3. Calculare suma ratingurilor";
    cout << "\n4. Cautare dupa titlu";
    cout << "\n5. Sortare dupa an";
    cout << "\n6. Sortare dupa incasari";
    cout << "\n7. Cautare dupa gen de film";
    cout << "\n8. Cautare dupa actori";
    cout << "\n9. Sortare dupa rating";
    cout << "\n10. Stergere film";
    cout << "\n11. Iesire\n";
}

// Functie pentru afisarea unui film
void afisareFilm(const Film& film) {
    cout << "Titlu: " << film.titlu << endl;
    cout << "Regizor: " << film.regizor << endl;
    cout << "An: " << film.an << endl;
    cout << "Rating: " << film.rating << endl;
    cout << "Incasari: " << film.incasari << " $" << endl;
    cout << "Gen: " << film.gen << endl;
    cout << "Actori: " << film.actori << endl;
    cout << "-----------------------------\n";
}

// Functie pentru adaugarea unui film nou
void adaugareFilm(Film filme[], int& numarFilme) {
    if (numarFilme >= MAX_FILME) {
        cout << "Nu mai este spatiu pentru adaugare de filme!\n";
        return;
    }

    cout << "\nIntroduceti titlul filmului: ";
    cin.ignore();
    cin.getline(filme[numarFilme].titlu, MAX_TITLU);
    cout << "Introduceti numele regizorului: ";
    cin.getline(filme[numarFilme].regizor, MAX_REGIZOR);
    cout << "Introduceti anul: ";
    cin >> filme[numarFilme].an;
    cout << "Introduceti ratingul: ";
    cin >> filme[numarFilme].rating;
    cout << "Introduceti incasarile: ";
    cin >> filme[numarFilme].incasari;
    cout << "Introduceti genul de film: ";
    cin.ignore();
    cin.getline(filme[numarFilme].gen, MAX_REGIZOR);
    cout << "Introduceti actorii: ";
    cin.getline(filme[numarFilme].actori, MAX_REGIZOR);

    numarFilme++;
    cout << "Film adaugat cu succes!\n";
}


// Functie pentru sortarea filmelor dupa incasari
void sortareDupaIncasari(Film filme[], int numarFilme) {
    sort(filme, filme + numarFilme, [](const Film& a, const Film& b) {
        return a.incasari > b.incasari;
    });
}

// Functie pentru sortarea filmelor dupa rating
void sortareDupaRating(Film filme[], int numarFilme) {
    sort(filme, filme + numarFilme, [](const Film& a, const Film& b) {
        return a.rating > b.rating;
    });
}

// Functie pentru calcularea sumei ratingurilor
float calculareSumaRatingurilor(Film filme[], int numarFilme) {
    float suma = 0;
    for (int i = 0; i < numarFilme; ++i) {
        suma += filme[i].rating;
    }
    return suma;
}

// Functie pentru cautarea filmelor dupa titlu
void cautareDupaTitlu(Film filme[], int numarFilme, const char* titluCautat) {
    bool gasit = false;
    for (int i = 0; i < numarFilme; ++i) {
        if (strcmp(filme[i].titlu, titluCautat) == 0) {
            afisareFilm(filme[i]);
            gasit = true;
        }
    }
    if (!gasit) {
        cout << "Nu s-a gasit niciun film cu titlul \"" << titluCautat << "\".\n";
    }
}

// Functie pentru cautarea filmelor dupa gen
void cautareDupaGen(Film filme[], int numarFilme, const char* genCautat) {
    bool gasit = false;
    for (int i = 0; i < numarFilme; ++i) {
        if (strcmp(filme[i].gen, genCautat) == 0) {
            afisareFilm(filme[i]);
            gasit = true;
        }
    }
    if (!gasit) {
        cout << "Nu s-a gasit niciun film cu genul \"" << genCautat << "\".\n";
    }
}

// Functie pentru cautarea filmelor dupa actori
void cautareDupaActori(Film filme[], int numarFilme, const char* actoriCautati) {
    bool gasit = false;
    for (int i = 0; i < numarFilme; ++i) {
        if (strstr(filme[i].actori, actoriCautati) != nullptr) {
            afisareFilm(filme[i]);
            gasit = true;
        }
    }
    if (!gasit) {
        cout << "Nu s-a gasit niciun film cu actorii \"" << actoriCautati << "\".\n";
    }
}

// Functie pentru stergerea unui film
void stergereFilm(Film filme[], int& numarFilme, int index) {
    if (index < 0 || index >= numarFilme) {
        cout << "Indexul filmului de sters este invalid.\n";
        return;
    }

    for (int i = index; i < numarFilme - 1; ++i) {
        filme[i] = filme[i + 1];
    }
    numarFilme--;
    cout << "Filmul a fost sters cu succes!\n";
}

// Functie pentru sortarea filmelor dupa an
void sortareDupaAn(Film filme[], int numarFilme) {
    sort(filme, filme + numarFilme, [](const Film& a, const Film& b) {
        return a.an < b.an; // Sortare crescatoare dupa an
    });
}


int main() {
    Film filme[MAX_FILME];
    int numarFilme = 0;

    // INCEPTION
    strcpy(filme[numarFilme].titlu, "Inception");
    strcpy(filme[numarFilme].regizor, "Christopher Nolan");
    filme[numarFilme].an = 2010;
    filme[numarFilme].rating = 8.8;
    filme[numarFilme].incasari = 828.3;
    strcpy(filme[numarFilme].gen, "Actiune, SF");
    strcpy(filme[numarFilme].actori, "Leonardo DiCaprio, Joseph Gordon-Levitt, Ellen Page");
    numarFilme++;


    //GODFATHER
    strcpy(filme[numarFilme].titlu, "The Godfather");
    strcpy(filme[numarFilme].regizor, "Francis Ford Coppola");
    filme[numarFilme].an = 1972;
    filme[numarFilme].rating = 9.2;
    filme[numarFilme].incasari = 245.1;
    strcpy(filme[numarFilme].gen, "Crima, Drama");
    strcpy(filme[numarFilme].actori, "Marlon Brando, Al Pacino, James Caan");
    numarFilme++;

    // FAST AND FURIOUS 1
    strcpy(filme[numarFilme].titlu, "Fast and Furious");
    strcpy(filme[numarFilme].regizor, "Rob Cohen");
    filme[numarFilme].an = 2001;
    filme[numarFilme].rating = 6.8;
    filme[numarFilme].incasari = 207.3;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Paul Walker, Michelle Rodriguez");
    numarFilme++;

    //FAST AND FURIOUS 2
    strcpy(filme[numarFilme].titlu, "2 Fast 2 Furious");
    strcpy(filme[numarFilme].regizor, "John Singleton");
    filme[numarFilme].an = 2003;
    filme[numarFilme].rating = 5.9;
    filme[numarFilme].incasari = 236.4;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Paul Walker, Tyrese Gibson, Cole Hauser");
    numarFilme++;

    //FAST AND FURIOUS 3
    strcpy(filme[numarFilme].titlu, "The Fast and the Furious: Tokyo Drift");
    strcpy(filme[numarFilme].regizor, "Justin Lin");
    filme[numarFilme].an = 2006;
    filme[numarFilme].rating = 6.0;
    filme[numarFilme].incasari = 158.5;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Lucas Black, Zachery Ty Bryan, Shad Moss");
    numarFilme++;

    //FAST AND FURIOUS 4
    strcpy(filme[numarFilme].titlu, "Fast & Furious");
    strcpy(filme[numarFilme].regizor, "Justin Lin");
    filme[numarFilme].an = 2009;
    filme[numarFilme].rating = 6.6;
    filme[numarFilme].incasari = 363.2;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Paul Walker, Michelle Rodriguez");
    numarFilme++;

    //FAST AND FURIOUS 5
    strcpy(filme[numarFilme].titlu, "Fast Five");
    strcpy(filme[numarFilme].regizor, "Justin Lin");
    filme[numarFilme].an = 2011;
    filme[numarFilme].rating = 7.3;
    filme[numarFilme].incasari = 626.1;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Paul Walker, Dwayne Johnson");
    numarFilme++;

    //FAST AND FURIOUS 6
    strcpy(filme[numarFilme].titlu, "Fast & Furious 6");
    strcpy(filme[numarFilme].regizor, "Justin Lin");
    filme[numarFilme].an = 2013;
    filme[numarFilme].rating = 7.1;
    filme[numarFilme].incasari = 788.7;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Paul Walker, Dwayne Johnson");
    numarFilme++;

    //FAST AND FURIOUS 7
    strcpy(filme[numarFilme].titlu, "Furious 7");
    strcpy(filme[numarFilme].regizor, "James Wan");
    filme[numarFilme].an = 2015;
    filme[numarFilme].rating = 7.1;
    filme[numarFilme].incasari = 1.516;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Paul Walker, Dwayne Johnson");
    numarFilme++;

    //FAST AND FURIOUS 8
    strcpy(filme[numarFilme].titlu, "The Fate of the Furious");
    strcpy(filme[numarFilme].regizor, "F. Gary Gray");
    filme[numarFilme].an = 2017;
    filme[numarFilme].rating = 6.7;
    filme[numarFilme].incasari = 1.236;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Jason Statham, Dwayne Johnson");
    numarFilme++;

    //FAST AND FURIOUS 9
    strcpy(filme[numarFilme].titlu, "F9");
    strcpy(filme[numarFilme].regizor, "Justin Lin");
    filme[numarFilme].an = 2021;
    filme[numarFilme].rating = 5.2;
    filme[numarFilme].incasari = 726.3;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Vin Diesel, Michelle Rodriguez, Jordana Brewster");
    numarFilme++;

    //THE DARK KNIGHT
    strcpy(filme[numarFilme].titlu, "The Dark Knight");
    strcpy(filme[numarFilme].regizor, "Christopher Nolan");
    filme[numarFilme].an = 2008;
    filme[numarFilme].rating = 9.0;
    filme[numarFilme].incasari = 1.005;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Christian Bale, Heath Ledger, Aaron Eckhart");
    numarFilme++;

    //THE DARK KNIGHT RISES
    strcpy(filme[numarFilme].titlu, "The Dark Knight Rises");
    strcpy(filme[numarFilme].regizor, "Christopher Nolan");
    filme[numarFilme].an = 2012;
    filme[numarFilme].rating = 8.4;
    filme[numarFilme].incasari = 1.081;
    strcpy(filme[numarFilme].gen, "Actiune, Crima");
    strcpy(filme[numarFilme].actori, "Christian Bale, Tom Hardy, Anne Hathaway");
    numarFilme++;

    //THE GODFATHER 2
    strcpy(filme[numarFilme].titlu, "The Godfather: Part II");
    strcpy(filme[numarFilme].regizor, "Francis Ford Coppola");
    filme[numarFilme].an = 1974;
    filme[numarFilme].rating = 9.0;
    filme[numarFilme].incasari = 57.3;
    strcpy(filme[numarFilme].gen, "Crima, Drama");
    strcpy(filme[numarFilme].actori, "Al Pacino, Robert De Niro, Robert Duvall");
    numarFilme++;

    //THE GODFATHER 3
    strcpy(filme[numarFilme].titlu, "The Godfather: Part III");
    strcpy(filme[numarFilme].regizor, "Francis Ford Coppola");
    filme[numarFilme].an = 1990;
    filme[numarFilme].rating = 7.6;
    filme[numarFilme].incasari = 136.8;
    strcpy(filme[numarFilme].gen, "Crima, Drama");
    strcpy(filme[numarFilme].actori, "Al Pacino, Diane Keaton, Andy Garcia");
    numarFilme++;

    //THE GODFATHER 4
    strcpy(filme[numarFilme].titlu, "The Godfather: Part IV");
    strcpy(filme[numarFilme].regizor, "Francis Ford Coppola");
    filme[numarFilme].an = 2022;
    filme[numarFilme].rating = 8.0;
    filme[numarFilme].incasari = 0;
    strcpy(filme[numarFilme].gen, "Crima, Drama");
    numarFilme++;

    //AVENGERS
    strcpy(filme[numarFilme].titlu, "The Avengers");
    strcpy(filme[numarFilme].regizor, "Joss Whedon");
    filme[numarFilme].an = 2012;
    filme[numarFilme].rating = 8.0;
    filme[numarFilme].incasari = 1.519;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Robert Downey Jr., Chris Evans, Scarlett Johansson");
    numarFilme++;

    //AVENGERS 2
    strcpy(filme[numarFilme].titlu, "Avengers: Age of Ultron");
    strcpy(filme[numarFilme].regizor, "Joss Whedon");
    filme[numarFilme].an = 2015;
    filme[numarFilme].rating = 7.3;
    filme[numarFilme].incasari = 1.402;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Robert Downey Jr., Chris Evans, Mark Ruffalo");
    numarFilme++;

    //AVENGERS 3
    strcpy(filme[numarFilme].titlu, "Avengers: Infinity War");
    strcpy(filme[numarFilme].regizor, "Anthony Russo, Joe Russo");
    filme[numarFilme].an = 2018;
    filme[numarFilme].rating = 8.4;
    filme[numarFilme].incasari = 2.048;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Robert Downey Jr., Chris Hemsworth, Mark Ruffalo");
    numarFilme++;

    //AVENGERS 4
    strcpy(filme[numarFilme].titlu, "Avengers: Endgame");
    strcpy(filme[numarFilme].regizor, "Anthony Russo, Joe Russo");
    filme[numarFilme].an = 2019;
    filme[numarFilme].rating = 8.4;
    filme[numarFilme].incasari = 2.798;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Robert Downey Jr., Chris Evans, Mark Ruffalo");
    numarFilme++;

    //THE SHAWSHANK REDEMPTION
    strcpy(filme[numarFilme].titlu, "The Shawshank Redemption");
    strcpy(filme[numarFilme].regizor, "Frank Darabont");
    filme[numarFilme].an = 1994;
    filme[numarFilme].rating = 9.3;
    filme[numarFilme].incasari = 28.3;
    strcpy(filme[numarFilme].gen, "Drama");
    strcpy(filme[numarFilme].actori, "Tim Robbins, Morgan Freeman, Bob Gunton");
    numarFilme++;

    //AVATAR
    strcpy(filme[numarFilme].titlu, "Avatar");
    strcpy(filme[numarFilme].regizor, "James Cameron");
    filme[numarFilme].an = 2009;
    filme[numarFilme].rating = 7.8;
    filme[numarFilme].incasari = 2.923;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Sam Worthington, Zoe Saldana, Sigourney Weaver");
    numarFilme++;

    //THE LORD OF THE RINGS
    strcpy(filme[numarFilme].titlu, "The Lord of the Rings: The Return of the King");
    strcpy(filme[numarFilme].regizor, "Peter Jackson");
    filme[numarFilme].an = 2003;
    filme[numarFilme].rating = 8.9;
    filme[numarFilme].incasari = 1.142;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Elijah Wood, Viggo Mortensen, Ian McKellen");
    numarFilme++;

    //THE LORD OF THE RINGS 2
    strcpy(filme[numarFilme].titlu, "The Lord of the Rings: The Two Towers");
    strcpy(filme[numarFilme].regizor, "Peter Jackson");
    filme[numarFilme].an = 2002;
    filme[numarFilme].rating = 8.7;
    filme[numarFilme].incasari = 0.947;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Elijah Wood, Ian McKellen, Viggo Mortensen");
    numarFilme++;

    //THE LORD OF THE RINGS 3
    strcpy(filme[numarFilme].titlu, "The Lord of the Rings: The Fellowship of the Ring");
    strcpy(filme[numarFilme].regizor, "Peter Jackson");
    filme[numarFilme].an = 2001;
    filme[numarFilme].rating = 8.8;
    filme[numarFilme].incasari = 0.887;
    strcpy(filme[numarFilme].gen, "Actiune, Aventura");
    strcpy(filme[numarFilme].actori, "Elijah Wood, Ian McKellen, Orlando Bloom");
    numarFilme++;

    //THE HOBBIT
    strcpy(filme[numarFilme].titlu, "The Hobbit: An Unexpected Journey");
    strcpy(filme[numarFilme].regizor, "Peter Jackson");
    filme[numarFilme].an = 2012;
    filme[numarFilme].rating = 7.8;
    filme[numarFilme].incasari = 1.017;
    strcpy(filme[numarFilme].gen, "Aventura, Familie");
    strcpy(filme[numarFilme].actori, "Martin Freeman, Ian McKellen, Richard Armitage");
    numarFilme++;

    //THE HOBBIT 2
    strcpy(filme[numarFilme].titlu, "The Hobbit: The Desolation of Smaug");
    strcpy(filme[numarFilme].regizor, "Peter Jackson");
    filme[numarFilme].an = 2013;
    filme[numarFilme].rating = 7.8;
    filme[numarFilme].incasari = 0.958;
    strcpy(filme[numarFilme].gen, "Aventura, Familie");
    strcpy(filme[numarFilme].actori, "Martin Freeman, Ian McKellen, Richard Armitage");
    numarFilme++;

    //THE HOBBIT 3
    strcpy(filme[numarFilme].titlu, "The Hobbit: The Battle of the Five Armies");
    strcpy(filme[numarFilme].regizor, "Peter Jackson");
    filme[numarFilme].an = 2014;
    filme[numarFilme].rating = 7.4;
    filme[numarFilme].incasari = 0.956;
    strcpy(filme[numarFilme].gen, "Aventura, Familie");
    strcpy(filme[numarFilme].actori, "Martin Freeman, Ian McKellen, Richard Armitage");
    numarFilme++;

    //THE MATRIX
    strcpy(filme[numarFilme].titlu, "The Matrix");
    strcpy(filme[numarFilme].regizor, "Lana Wachowski, Lilly Wachowski");
    filme[numarFilme].an = 1999;
    filme[numarFilme].rating = 8.7;
    filme[numarFilme].incasari = 0.463;
    strcpy(filme[numarFilme].gen, "Actiune, SF");
    strcpy(filme[numarFilme].actori, "Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss");
    numarFilme++;

    //THE MATRIX 2
    strcpy(filme[numarFilme].titlu, "The Matrix Reloaded");
    strcpy(filme[numarFilme].regizor, "Lana Wachowski, Lilly Wachowski");
    filme[numarFilme].an = 2003;
    filme[numarFilme].rating = 7.2;
    filme[numarFilme].incasari = 0.742;
    strcpy(filme[numarFilme].gen, "Actiune, SF");
    strcpy(filme[numarFilme].actori, "Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss");
    numarFilme++;

    //THE MATRIX 3
    strcpy(filme[numarFilme].titlu, "The Matrix Revolutions");
    strcpy(filme[numarFilme].regizor, "Lana Wachowski, Lilly Wachowski");
    filme[numarFilme].an = 2003;
    filme[numarFilme].rating = 6.8;
    filme[numarFilme].incasari = 0.427;
    strcpy(filme[numarFilme].gen, "Actiune, SF");
    strcpy(filme[numarFilme].actori, "Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss");
    numarFilme++;
    
    //printf("%d\n", numarFilme); Pentru a verifica daca s-au adaugat toate filmele

    int optiune;
    do {
        afisareMeniu();
        cout << "\nIntroduceti optiunea dorita: ";
        cin >> optiune;

        switch(optiune) {
            case 1:
                cout << "\nToate filmele:\n";
                for (int i = 0; i < numarFilme; ++i) {
                    afisareFilm(filme[i]);
                }
                break;
            case 2:
                adaugareFilm(filme, numarFilme);
                break;
            case 3:
                // Calcularea sumei ratingurilor
                cout << "Suma ratingurilor este: " << calculareSumaRatingurilor(filme, numarFilme) << endl;
                break;
            case 4:
                // Cautarea dupa titlu
                char titluCautat[MAX_TITLU];
                cout << "Introduceti titlul filmului cautat: ";
                cin.ignore();
                cin.getline(titluCautat, MAX_TITLU);
                cautareDupaTitlu(filme, numarFilme, titluCautat);
                break;
            case 5:
                // Sortare dupa an
                sortareDupaAn(filme, numarFilme);
                cout << "Filme sortate dupa an:\n";
                for (int i = 0; i < numarFilme; ++i) {
                    afisareFilm(filme[i]);
                }
                break;
            case 6:
                // Sortare dupa incasari
                sortareDupaIncasari(filme, numarFilme);
                cout << "Filme sortate dupa incasari:\n";
                for (int i = 0; i < numarFilme; ++i) {
                    afisareFilm(filme[i]);
                }
                break;
            case 7:
                // Cautare dupa gen de film
                char genCautat[MAX_REGIZOR];
                cout << "Introduceti genul de film cautat: ";
                cin.ignore();
                cin.getline(genCautat, MAX_REGIZOR);
                cautareDupaGen(filme, numarFilme, genCautat);
                break;
            case 8:
                // Cautare dupa actori
                char actoriCautati[MAX_REGIZOR];
                cout << "Introduceti actorii cautati: ";
                cin.ignore();
                cin.getline(actoriCautati, MAX_REGIZOR);
                cautareDupaActori(filme, numarFilme, actoriCautati);
                break;
            case 9:
                // Sortare dupa rating
                sortareDupaRating(filme, numarFilme);
                cout << "Filme sortate dupa rating:\n";
                for (int i = 0; i < numarFilme; ++i) {
                    afisareFilm(filme[i]);
                }
                break;
            case 10:
                // Stergere film
                int index;
                cout << "Introduceti indexul filmului de sters: ";
                cin >> index;
                stergereFilm(filme, numarFilme, index);
                break;
            case 11:
                cout << "La revedere!\n";
                break;
            default:
                cout << "Optiune invalida! Va rugam sa alegeti o optiune valida.\n";
        }
    } while (optiune != 11);

    return 0;
}
