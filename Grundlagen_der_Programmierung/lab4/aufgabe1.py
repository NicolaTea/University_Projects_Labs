import turtle
from auf1 import *


def symbol_menu():
    return """
    Turtle paint v1.0

    0. Programm beenden
    1. Textnachricht zeichnen
    2. Neues Symbol hinzufügen
    3. Stift reset

"""


def anweisungen_menu():
    return """
    w - der Stift bewegt sich 10 Pixel vorwärts
    s - der Stift bewegt sich 10 Pixel rückwärts
    d - der Stift dreht sich um 45 Grad nach rechts
    a - der Stift dreht sich um 45 Grad nach links
    f - hebt den Stift nach oben (Zeichnen stoppt)
    g - legt den Stift wieder ab (Zeichnen wird fortgesetzt)
    ENTER - stoppt den Befehl-akzeptierung
    """


def menu_auf1():

    t = turtle.Pen()

    dict = {
        'a': "aawwddwddwddwsaawaafwg",
        'b': "waaawsawddwdddwsaawsawddwdddwsafwwaawg",
        'c': "wsaawwddwddfwwaawg",
        'd': "awsawwdddwsafwddwgdwsddwsaaafwaawg",
        'e': "wsaawddwsaawddwddfwwaawg",
        'f': "aawddwsaawddwddfwwaawg",
        'g': "waawaawaawssaawddfwwaawg",
        'h': "aawwsddwaawssddfwg",
        'i': "aawwssddfwg",
        'j': "waawwssddfwg",
        'k': "aawwddfwdddgwsdfwaawgaaawsddwsdwaafwaaagwsdddfwg",
        'l': "aawwssddwfwg",
        'm': "aawwdddwaawdddwwaafwg",
        'n': "aawdddwsaaawddfwgddwwdddwsdddfwg",
        'o': "waawwaawaawwaawfwg",
        'p': "aawwddwddwddwaawaafwwg",
        'q': "waaawsdwwaawaawwaawfwg",
        'r': "aawwddwddwddwaaawsdwaafwaaagwsdddfwg",
        's': "waawaawddwddwfddwwaawg",
        't': "fwaagwwaawsswaawwaafwwg",
        'u': "aawwssddwaawwssddfwg",
        'v': "aawwssdwsdfwaawgwsaaawsafwaawg",
        'w': "aawwssdwddwaaawwssddfwg",
        'x': "awsafwwdddgwsfawwdddgwsafwwdddgwsafwddwgdwsddwsddwsddwsdfsddwwg",
        'y': "fwaagwawsddwsafwaawaaagwsafwwdddgwsfawwaawg",
        'z': "awsdwwsaafwaaagwsddddwsafwaagwssawsfawwaawg",
        '.': "waawaawaawaawfwg",
        '!': "waawaawsddfwgwwaawaawwaawsddfwgwaawfwg",
        '?': "waawaawaawaawaawfwdgwsaaawdddwsafwwdddgwsawdwsdfwdgwsddwsafsdgwsaawsafwwwaawg",
        ' ': "fwwg"
    }

    while True:

        print(symbol_menu())

        try:
            option = int(input("Was möchtest du machen?: "))
        except ValueError:
            turtle.bye()
            return ("Integer-Eingabe erwartet")

        t.reset()

        if not (option == 0 or option == 1 or option == 2 or option == 3):
            turtle.bye()
            return ("Input nicht akzeptiert\n")

        elif not option:
            turtle.bye()
            return ("Turtle paint v1.0 beendet")

        elif option == 1:

            print(nehme_symbol(dict))
            text = input("Schreib was hier: ")
            print(draw_letter(dict, text, t))

        elif option == 2:

            print(nehme_symbol(dict))

            while True:
                text = ""
                symbol = symbol_bauen()
                print(anweisungen_menu())
                symbol_input = symbol_input_bauen(t)

                key_pass = key_check(symbol, dict)
                symbol_pass = symbol_check(symbol_input, dict)

                print(key_symbol_pass(key_pass, symbol_pass, symbol, symbol_input))
                break

        elif option == 3:

            print("Stift ist reset")
            t.reset()