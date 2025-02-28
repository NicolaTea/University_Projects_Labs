def w_forward(pen):
    pen.forward(10)


def s_backward(pen):
    pen.backward(10)


def a_left(pen):
    pen.left(45)


def d_right(pen):
    pen.right(45)


def f_up(pen):
    pen.penup()


def g_down(pen):
    pen.pendown()


def draw_letter(dictionar, text, pen):  # deseneaza litera

    for i in range(len(text)):
        letter = text[i]

        if letter in dictionar:

            value = dictionar.get(letter)  # ia valoarea din dictionar a literei

            for j in range(len(value)):  # muta turtle dupa instructiuni

                if value[j] == 'w':
                    w_forward(pen)

                elif value[j] == 's':
                    s_backward(pen)

                elif value[j] == 'a':
                    a_left(pen)

                elif value[j] == 'd':
                    d_right(pen)

                elif value[j] == 'f':
                    f_up(pen)

                elif value[j] == 'g':
                    g_down(pen)

        else:
            pen.reset()
            return "Dieses Symbol existiert nicht im Wörterbuch."
    return ""


def make_string(symbol_input, pen):  # misca turtle cand ii zicem de noul caracter

    if symbol_input == 'w':
        w_forward(pen)
        return 1

    elif symbol_input == 's':
        s_backward(pen)
        return 1

    elif symbol_input == 'a':
        a_left(pen)
        return 1

    elif symbol_input == 'd':
        d_right(pen)
        return 1

    elif symbol_input == 'f':
        f_up(pen)
        return 1

    elif symbol_input == 'g':
        g_down(pen)
        return 1

    elif symbol_input == '':
        return 1

    else:
        return 0


def key_check(symbol, dictionar):  # daca key e deja in dictionar

    if symbol in dictionar.keys():
        return 0
    return 1


def symbol_check(symbol_input, dictionar):
    if symbol_input in dictionar.values():  # daca simbolul e deja in dictionar returnam 0
        return 0
    return 1


def nehme_symbol(dictionar):  # baga noul caracter in memorie

    try:
        with open("symbol.txt", 'r') as f:
            for line in f:
                l = []
                l = line.split()
                v1 = key_check(l[0], dictionar)  # verifica daca pe linia citita din symbol.txt exista pe prima pozitie un singur caracter
                v2 = symbol_check(l[1], dictionar)  # vf daca pe a doua pozitie sunt litere

                if v1 and v2:  # daca ambele sunt true
                    dictionar[l[0]] = l[1]  # creeaza key si value in memorie

        return "Alle Symbole von symbol.txt sind untergeladen."

    except IndexError:

        return "Es gibt keine Symbolen in der symbol.txt Datei."


def symbol_bauen():  # verifica daca este un singur caracter ca nume

    ok = 0
    while not ok:

        symbol = input("Bitte schreib ein einziges Charakter Name für dein Symbol: ")

        if not len(symbol) == 1:

            print("Symbol nicht akzeptiert. Bitte schreib nur ein einziges Charakter.")

        else:

            ok = 1

    return symbol


def symbol_input_bauen(pen):  # daca a reusit sa deseneze

    ok = 0
    l = ""
    while not ok:

        symbol_input = input("Schreib die Anweisungen für dein Symbol: ")

        if make_string(symbol_input, pen):
            l += symbol_input  # adaug instructiunile

        else:

            print("Befehle zurückgebracht")
            l = ""
            pen.reset()

        if symbol_input == "" and l != "":
            ok = 1

    return l


def key_symbol_pass(key_pass, symbol_pass, symbol, symbol_input):
    if (key_pass == 0 or symbol_pass == 0):  # verifica daca am introdus un simbol deja existent in dictionar

        l = []
        l.append("Die Folgende Sachen sind schon im Symbol-Wörterbuch:")

        if not key_pass:
            l.append("Symbol")

        if not symbol_pass:
            l.append("Symbol Anweisungen")

        l.append("Symbol Aufbau gestoppt")
        result = '\n'.join(l)

        return result

    else:

        save = input("Möchtest du dieses Symbol speichern? (Ja oder nein): ")  # salveaza in fisierul meu noul caracter

        if save == "Ja":
            with open("symbol.txt", 'a') as f:
                f.write(symbol)
                f.write(" ")
                f.write(symbol_input)
                f.write("\n")
            return "Symbol gespeichert"

        return "Symbol nicht geschpeichert"