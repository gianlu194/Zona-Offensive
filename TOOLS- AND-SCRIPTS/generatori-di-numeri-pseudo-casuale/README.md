# Seed Random Generator (C + Python)

Questo progetto combina C e Python per creare un generatore di numeri pseudo-casuali basato sul tempo di esecuzione. La DLL scritta in C utilizza `time()` per estrarre un seed ogni volta che viene chiamata, mentre il programma Python interagisce con la DLL tramite `ctypes`, elabora il valore ricevuto e lo converte in una sequenza numerica interpretata in base a una logica personalizzata.

Il flusso è semplice: la DLL genera un numero variabile basato sull’orario corrente, Python ne estrae le prime tre cifre, le somma per ottenere un valore `r`, e se questo valore supera le due cifre viene risommato per ottenere un valore unico. Il risultato finale viene mappato su categorie numeriche da 1 a 9, utili per esercitazioni su logiche di stato, crittografia base o algoritmi sperimentali.

Il progetto serve per allenarmi a: usare DLL compilate in C, integrare `ctypes` in Python, capire il comportamento dei generatori pseudo-casuali basati sul tempo, e manipolare numeri casuali con trasformazioni matematiche semplici.  
Non è un generatore crittograficamente sicuro, ma uno strumento didattico per sperimentare interazione tra linguaggi e concetti di randomness.

**Struttura del progetto:**  
- `seed_generator.c` → codifica il seed basato sul tempo  
- `seed_generator.dll` → libreria caricata da Python  
- `generatore di numeri.py` → script che richiama la DLL ed elabora i valori  
- `README.md` → documentazione del progetto

**Esecuzione:**  
Compilare la DLL con `gcc -shared -o seed_generator.dll seed_generator.c`, poi eseguire lo script Python assicurandosi che la DLL si trovi nel percorso corretto.

Questo progetto è una piccola palestra personale per comprendere come strumenti diversi possono lavorare insieme nel generare, trasformare e interpretare numeri pseudo-casuali.
