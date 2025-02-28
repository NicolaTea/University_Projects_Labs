numbers = ["11", "22", "33", "11", "44", "22","33","34","43"]
def anzahl_symmetrischen_Paaren(numbers):
    symmetrical_count = 0
    seen = set() # set-o colectie de elemente..stocam intr-o variabila

    for number in numbers:
        reversed_number = number[::-1]  # numerele de la sfarsit la inceput
        if reversed_number in seen:
            symmetrical_count += 1
        seen.add(number)  #adaugam numerele

    return symmetrical_count


symmetrical_count = anzahl_symmetrischen_Paaren(numbers)
print(symmetrical_count)