#include <iostream>
#define MAX 10

using namespace std;

class Turnuri
{
private:
    int coloane[3][MAX]; // Matrice pentru stocarea discurilor pe cele 3 coloane
    int pozitie[3];      // Matrice pentru stocarea pozitiei curente a varfurilor coloanelor

public:
    Turnuri(int nrDiscuri);

    void afiseazaStare(int nrDiscuri); // Functie pentru afisarea starii curente a turnurilor

    void mutaDisc(int disc, int from, int to); // Functie pentru mutarea unui disc intre coloane

    void hanoi(int n, int from, int to, int aux); // Functie recursiva pentru rezolvarea problemei turnurile hanoi
};

Turnuri::Turnuri(int nrDiscuri)
{
    // Initializarea starii initiale a turnurilor cu discuri de dimensiuni diferite
    for (int i = 0; i < nrDiscuri; ++i)
    {
        coloane[0][i] = nrDiscuri - i;
    }
    pozitie[0] = nrDiscuri;
    pozitie[1] = pozitie[2] = 0;
}

void Turnuri::afiseazaStare(int nrDiscuri)
{
    for (int nivel = nrDiscuri - 1; nivel >= 0; --nivel)
    {
        for (int coloana = 0; coloana < 3; ++coloana)
        {
            if (nivel < pozitie[coloana])
            {
                int dimensiune = coloane[coloana][nivel];
                cout << dimensiune << "  ";
            }
            else
            {
                cout << "|  ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 3; ++i)
    {
        cout << "-- ";
    }
    cout << "\nA  B  C\n\n";
}

void Turnuri::mutaDisc(int disc, int from, int to)
{
    cout << "Muta discul " << disc << " de pe coloana " << char('A' + from) << " pe coloana " << char('A' + to) << ": " << endl;
    coloane[to][pozitie[to]++] = coloane[from][--pozitie[from]];
    afiseazaStare(pozitie[0] + pozitie[1] + pozitie[2]);
}

void Turnuri::hanoi(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        mutaDisc(1, from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    mutaDisc(n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int nrDiscuri;
    cout << "Introduceti numarul de discuri:";
    cin >> nrDiscuri;

    if (nrDiscuri > MAX)
    {
        cout << "Numarul de discuri depaseste numarul maxim." << endl;
        return 1;
    }

    Turnuri turnuri(nrDiscuri);
    turnuri.afiseazaStare(nrDiscuri);

    turnuri.hanoi(nrDiscuri, 0, 2, 1);
    return 0;
}
