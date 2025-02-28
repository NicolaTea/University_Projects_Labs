import random

def lesen_zeichen(filename):
    zeichen={}
    f=open(filename,'r')
    lines=f.read().split('\n\n')
    for line in lines:
        if line: #dacă linia nu este goală
            lines_in=line.split('\n',1)  #dacă linia nu este goală, aceasta este împărțită în două părți
            name=lines_in[0]
            zchn=lines_in[1] if len(lines_in) >1 else '' #dacă lista are mai mult de un element, altfel zchn primește un șir gol
            zeichen[name]= zchn
    return zeichen

def anzeigen_zeichen(zeichen):
    print(zeichen)


def spiel_stein_papier_schere():

    zeichen=lesen_zeichen('game.txt')
    choices= list(zeichen.keys())
    to_win=[('Stein','Schere'),('Schere','Papier'),('Papier','Stein')]
    player=0
    computer=0
    runden_limit=3
    runden_count=0


    while runden_count<runden_limit:
        ch_cmp=random.choice(choices)
        print('Bitte ein Zeichen wählen: Stein,Schere oder Papier')
        ch_ply=input('Dein Wahl: ').capitalize()
        runden_count+=1

        while ch_ply not in choices:
            print('Bitte noch einmal richtig wählen')
            ch_ply=input('Stein, Schere oder Papier: ').capitalize()
        print('Computer choice: ')
        anzeigen_zeichen(zeichen[ch_cmp])
        print('Spieler choice: ')
        anzeigen_zeichen(zeichen[ch_ply])
        if ch_ply==ch_cmp:
            print('Remise!')
        elif (ch_ply,ch_cmp) in to_win:
            print('Du gewinnst diese Runde :)')
            player+=1
        else:
            print('Computer gewinnt diese Runde :(')
            computer+=1


    if player > computer:
         print("Bravooo...du gewinnst das Spiel!")
    elif player < computer:
         print("Offff....Computer gewinnt das Spiel.")
    else:
         print("Remise!")




spiel_stein_papier_schere()
def play_again():

    response = input("Möchtest du noch einmal spielen? (ja oder nein): ")
    response = response.upper()

    if response == "JA":
        return True
    else:
        return False

while play_again():
    spiel_stein_papier_schere()
