a,b = input().split()
_food,_mouth, answer = int(a), int(b), 0

def case_food_is_more(mouth, food):
    global answer
    if food % mouth == 0:
        return
    else: # 나눠떨어지지 않을 때?
        left_food = food - (food // mouth) * mouth
        case_mouth_is_more(mouth, left_food)

def case_mouth_is_more(mouth, food):
    global answer
    if mouth % food == 0:
        pieces = mouth // food
        answer += (pieces - 1) * food
        return
    else: # 나눠떨어지지 않을 때?
        cut = mouth // food
        answer += (cut * food)
        left_mouth = mouth - (cut * food)
        if food % left_mouth != 0:
            case_food_is_more(left_mouth, food)

# main
if _food > _mouth:
    case_food_is_more(_mouth, _food)
elif _food < _mouth:
    case_mouth_is_more(_mouth, _food)
print(answer)