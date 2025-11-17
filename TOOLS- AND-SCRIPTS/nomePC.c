#include <stdio.h>
#include <winsock2.h>



// --- Lettura del nome del computer dal Registro di Windows ---
    HKEY hKeynomecomputer = NULL;   // handle (puntatore) alla chiave del registro
    char nome_computer_buffer[100];  // buffer dove verrà salvato il nome del computer
    DWORD dwNameSize = 100;    // dimensione del buffer (in byte)


    // Apro la chiave del registro che contiene il nome del computer
    // Percorso: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ComputerName\ComputerName
    
    long errorenomecomputer = RegOpenKeyExA(                          
    HKEY_LOCAL_MACHINE,                                               // radice principale del registro
    "SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ComputerName", // percorso completo della chiave
    0,                                                                // opzioni (0 = default)
    KEY_READ,                                                         // accesso in sola lettura
    &hKeynomecomputer                                                 // indirizzo dove salvare l'handle
    );

    // Se la chiave è stata aperta con successo
    if (errorenomecomputer == ERROR_SUCCESS){
        long risultato = RegQueryValueExA(
            hKeynomecomputer,    // handle alla chiave aperta
            "ComputerName",     // nome del valore che voglio leggere
            NULL,               // riservato (sempre NULL)
            NULL,               // tipo del valore (non serve qui)
            nome_computer_buffer,   // buffer dove salvare i dati letti
            &dwNameSize           // dimensione del buffer (in/out)
        );   

        // Chiudo la chiave del registro per liberare la memoria
        RegCloseKey(hKeynomecomputer);


        // Se la lettura è riuscita, stampo il nome del computer
        if (risultato == ERROR_SUCCESS) {
            printf("Nome del computer: %s\n", nome_computer_buffer);
        } else {
            printf("Errore nella lettura del valore ComputerName.\n");
        }

    }else {
        // Se non riesco ad aprire la chiave
        printf("Errore: impossibile aprire la chiave del registro.\n");
    };
