def avg(scores) :
    scores_sum = 0
    for score in scores :
        scores_sum += score
    return scores_sum / len(scores)

def highest(scores) :
    highest_score = scores[0]
    for score in scores :
        if highest_score < score :
            highest_score = score
    return highest_score

def lowest(scores) :
    lowest_score = scores[0]
    for score in scores :
        if lowest_score > score :
            lowest_score = score
    return lowest_score

def get_input(scores) :
    ipt = int(input("1. 평균 2. 최고점 3. 최저점 : "))
    if ipt == 1 :
        print("평균 점수 :", avg(scores))
    elif ipt == 2 :
        print("최고 점수 :", highest(scores))
    elif ipt == 3 :
        print("최저 점수 :", lowest(scores))

scores = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0]
print("학생들의 점수는 [100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0] 입니다.")
get_input(scores)
