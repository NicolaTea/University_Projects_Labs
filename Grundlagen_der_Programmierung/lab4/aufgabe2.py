def ersatzwort(filename, word, word_er):

    f=open(filename,'r')
    text=f.read()
    er_text=text.replace(word, word_er)
    count_er=text.count(word)
    if count_er>0:
        f=open(filename,'w')
        f.write(er_text)
        print(f"Ersetzte '{word}' durch '{word_er}' an {count_er} Stellen.")
    else:
         print(f"Das Wort '{word}' wurde nicht gefunden.")
    f.close()

file=input('Deine datei: ')
ersetz_wort=input('Wort zu ersetzen: ')
er_file=input('Ersatzwort: ')
ersatzwort(file,ersetz_wort,er_file)