import ctypes
import time

class ENCODER:
    def __init__(self, time):
        self.time = time

sacrificio = 0

#qui si richiedera tramite il codic ec la leetturea dell'orario 
try:
    tempo_C = ctypes.WinDLL("C:\\Users\\gianl\\Desktop\\c e python\\seed_generator.dll")
except OSError as f:
    print(f"ci sta un errore{f}")

get_seme = tempo_C.seed_tempo
get_seme.restype = ctypes.c_int

tot = 0

while sacrificio < 5:

    c = get_seme()
    print(c)
    d = str(c)

    primo = int(d[0])
    secondo =  int(d[1])
    terzo = int(d[2])

    r = primo+secondo+terzo

    if r >= 10:
        print("deduco che ha 2 cifre")
        w = str(r)

        primoprimo = int(w[0])
        secondosecondo = int(w[1])

        totale = primoprimo + secondosecondo

        tot = totale
         

    else:
        print("deduci che ha una cifra")
        
    print(r)
    input("")
    
    #time.sleep(c/100)

    if r == 1 or tot == 1:
        print("1")
        sacrificio = sacrificio +1

        #concetto   ASRL

    elif r == 2 or tot == 2:
        print("2")
        sacrificio += 1

        #xor
    elif r == 3 or tot == 3:
        print("3")
        sacrificio += 1

        #porta and con xor
    elif r == 4 or tot == 4:
        print("4")
        sacrificio += 1

        # esmepio del AES ROUND  A blocchi
    elif r == 5 or tot == 5:
        print("5")
        sacrificio += 1

        #miscuglio di porte ologiche

    elif r == 6 or tot == 6:
        print("6")
        sacrificio += 1

        # altro di crittografia

    elif r == 7 or tot == 7: 
        print("7")
        sacrificio +=1

        #altro di crittografia

    elif r == 8 or tot == 8:
        print("8")
        sacrificio +=1

        #altro di critografia

    elif r == 9 or tot == 9:
        print("9")
        sacrificio += 1

        #altro di crittografia

    else:
        print("0")

        #altro di crittoggrafia
        
    
print(sacrificio)

