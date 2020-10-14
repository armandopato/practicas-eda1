def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
    
    if left:
        result.extend(left[left_idx:])
    if right:
        result.extend(right[right_idx:])
    
    return result

def merge_sort(m):
    if len(m) <= 1:
        return m
    
    middle = len(m) // 2
    left = m[:middle]
    right = m[middle:]
    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))

lista1 = [4, 12, 87, 1, 32, 54, 36, 78, 90, 7]
print(merge_sort(lista1))