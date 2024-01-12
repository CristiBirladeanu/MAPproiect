# Documentație Proiect Sincretic: Turnurile Hanoi
Implementarea soluției pentru problema Turnurilor Hanoi în limbajul de programare C++
## Descriere:
Se dau trei tije A, B, C și N discuri de diametre diferite, stivuite inițial pe tija A în ordinea descrescătoare a diametrelor, formând un con. Să se determine secvența de mutări ale discurilor de pe tija inițială A către tija finală C, folosind B ca tijă intermediară, având în vedere următoarele restricții:
- la fiecare mișcare se va muta un singur disc
- un disc se poate plasa doar asupra unui disc mai mare ca diametru.

## Structura program:
Avem o clasă principală, `Turnuri`, care conține funcții pentru gestionarea și rezolvarea problemei.

### Clasa `Turnuri`

#### Variabile private
- `coloane[3][MAX]`: Matrice pentru stocarea discurilor pe cele 3 coloane.
- `pozitie[3]`: Vector pentru stocarea poziției curente a vârfurilor coloanelor.

#### Metode publice
- `Turnuri(int nrDiscuri)`: Constructorul clasei, inițializează starea turnurilor cu un număr dat de discuri.
- `afiseazaStare(int nrDiscuri)`: Afișează starea curentă a turnurilor.
- `mutaDisc(int disc, int from, int to)`: Mută un disc de pe o coloană pe alta și afișează starea rezultată.
- `hanoi(int n, int from, int to, int aux)`: Implementarea algoritmului Turnurilor Hanoi.

### Funcția `main()`
- Solicită utilizatorului să introducă numărul de discuri și verifică dacă este mai mic sau egal cu `MAX`.
- Creează un obiect de tip `Turnuri` cu numărul de discuri introdus.
- Afișează starea inițială a turnurilor.
- Aplică algoritmul Turnurilor Hanoi recursiv pentru a muta discurile pe coloanele dorite.


## Exemplu de Utilizare:
```plaintext
Introduceti numarul de discuri: 3
3  |  |  
2  |  |  
1  |  |  
-- -- -- 
A  B  C

// (Afișare pas cu pas)

Muta discul 1 de pe coloana A pe coloana C: 
|  |  |  
2  |  |  
3  |  1  
-- -- -- 
A  B  C

...

Muta discul 1 de pe coloana A pe coloana C:
|  |  1
|  |  2
|  |  3
-- -- --
A  B  C
```

## Utilizarea programului cu Docker
### Construirea și rularea într-un container Docker
- Construim imaginea docker:
```docker -build -t cristibirladeanu/turnhanoi .```
- Autentificarea in docker hub:
```docker login```
- Rularea in container Docker:
```docker run -it --rm cristibirladeanu/turnhanoi```

#### Conținutul Dockerfile
```plaintext
FROM gcc:latest
WORKDIR /app
COPY . /app
RUN gcc -o myapp TurnHanoi.cpp -lstdc++
CMD ["./myapp"]
```
## Concluzie

Proiectul oferă o implementare eficientă și clară a algoritmului Turnurilor Hanoi în limbajul C++. Utilizatorul poate urmări pas cu pas mutările discelor și evoluția stării turnurilor, oferind astfel o experiență interactivă. Rezolvarea acestei probleme ilustrează utilizarea recursivității și manipularea matricelor în programare.
