def langste_Teilfolge(nums):
    if not nums:
        return []

    # initializam indexul si lungimea celui mai lung Teilfolge
    max_length = 1
    max_index = 0

    # initializam lungimea si indexul Teilfolge actual
    current_length = 1
    current_index = 0

    for i in range(1, len(nums)):  #trecem prin tot vectorul
        if nums[i] > nums[i - 1]:
            current_length += 1
            if current_length > max_length: #devine maxim
                max_length = current_length
                max_index = current_index
        else:
            current_length = 1
            current_index = i


    langste_teilfolge1 = nums[max_index:max_index + max_length] #de la indexul maxim pana la

    return langste_teilfolge1


nums = [1, 3, 4, 2, 3, 4, 7, 8, 6, 3, 5, 6, 8]
result = langste_Teilfolge(nums)
print(result)