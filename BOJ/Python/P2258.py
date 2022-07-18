import operator
a,b = input().split()
a,b,lists = int(a), int(b), []
for i in range(a):
    weight, price = input().split()
    weight,price = int(weight), int(price)
    lists.append((price,weight))
s_ = sorted(lists, key=lambda x : (x[0], -x[1]))
bought, answer, now_price, nujeok, nujeok_num = 0, -1, 0, 0, 0
for i in range(len(s_)):
    won, kg = s_[i]
    if i == len(s_) - 1:
        if won != now_price:
            bought += nujeok
        else:
            nujeok += kg
            nujeok_num += 1
    else:
        if won != now_price:
            now_price = won
            bought += nujeok
            nujeok = kg
            nujeok_num = 1
        elif won == now_price:
            nujeok += kg
            nujeok_num += 1
    # 거르는 부분
    if bought + kg >= b:
        if answer == -1:
            answer = won
        elif answer != -1 and answer > won:
            answer = won
    else:
        if bought + nujeok >= b:
            if answer == -1:
                answer = won * nujeok_num
            elif answer != -1 and answer > won * nujeok_num:
                answer = won * nujeok_num

print(answer)

