student_grade=[100, 50, 30, 40, 20, 98, 97, 61, 54, 28, 31, 47, 68, 82]
cut = 50
for i in range(len(student_grade)) :
    if student_grade[i] >= cut :
        print(i, "번째 학생 통과.")
    else :
        print(i, "번째 학생 불합격.")
