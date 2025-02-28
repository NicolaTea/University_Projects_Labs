def langste_abnehmende_teilfolge(numbers):
    if not numbers:
        return []
    max_length=0
    max_teilfolge=[numbers[0]]
    current_length=0
    current_teilfolge=[numbers[0]]
    for i in range(1,len(numbers)):
        if numbers[i]<current_teilfolge[-1]:
            current_teilfolge.append(numbers[i])
        else:
            if current_length>max_length:
                max_length=current_length
            current_teilfolge=[numbers[i]]
    if current_length>max_length:
        max_teilfolge=current_teilfolge
    return max_teilfolge
num = [5, 4, 3, 7, 2, 1, 6, 8, 0, 9]
result = langste_abnehmende_teilfolge(num)
print("Die am längsten abnehmende aufeinanderfolgende Teilfolge:", result)