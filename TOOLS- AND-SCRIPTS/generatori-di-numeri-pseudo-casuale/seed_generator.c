#include <stdio.h>                       //richiamo libreria normali
#include <windows.h>                     //richiamo libreria per le api di window


// Funzione che genera un "seme" (seed) basato sul tempo di sistema in millisecondi.
// Viene pensata per essere richiamata da programmi esterni (es. Python via ctypes),
// quindi non serve il main: la funzione può essere esportata come DLL.

int seed_tempo(void){               // inizializzo la struttura SYSTEMTIME a zero (tutti i campi partono da 0)                   

    SYSTEMTIME tempo = {0};             // chiamo l’API di Windows che riempie la struttura "tempo" con l’ora corrente
                                       //il valore di {0} indica porta qualunque valore a 0 prima di metterlo all'interno della variabile
    GetSystemTime(&tempo);             //chiamata di systema normale di windows con richiamo al puntatore della variabile tempo
        
    int seed = tempo.wMilliseconds;    //estraggo solo la parte dei millisecondi e la salvo in "seed"

    return seed;                       // restituisco il valore (es. 374, significa 374 ms del secondo corrente)
                                        
}