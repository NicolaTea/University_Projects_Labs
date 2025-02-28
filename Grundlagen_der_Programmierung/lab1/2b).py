def langste_Teilfolge_primzahlen_ubrig(nums):
    if not nums:
        return []

    # initializam indexul si lungimea celui mai lung Teilfolge
    max_length = 1
    max_index = 0

    # initializam lungimea si indexul Teilfolge actual
    current_length = 1
    current_index = 0

    for i in range(1, len(nums)):  #trecem prin tot vectorul
        if nums[i] > nums[i - 1] == 1:
            current_length += 1
            if current_length > max_length: #devine maxim
                max_length = current_length
                max_index = current_index
        else:
            current_length = 1
            current_index = i


    l_t = nums[max_index:max_index + max_length] #de la indexul maxim pana la

    return l_t


nums = [2,5, 7, 3, 8, 11, 15,13]
result = langste_Teilfolge_primzahlen_ubrig(nums)
print(result)