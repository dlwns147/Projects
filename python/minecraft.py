col,row=map(int, input().split()) #col=가로, row=세로
matrix = []
for i in range(row):
    matrix.append(list(input()))

for i in range(0,row) :
    for j in range(0,col):
        if matrix[i][j] == '.':
            num=0
            if j>0 and matrix[i][j-1]=='*':
                num+=1
            
            if j<col-1 and matrix[i][j+1]=='*':
                num+=1

            if i>0 and matrix[i-1][j]=='*':
                num+=1
                
            if i<row-1 and matrix[i+1][j]=='*':
                num+=1
                
            if j>0 and i>0 and matrix[i-1][j-1]=='*':
                num+=1

            if j<col-1 and i>0 and matrix[i-1][j+1]=='*':
                num+=1

            if j>0 and i<row-1 and matrix[i+1][j-1]=='*':
                num+=1

            if j<col-1 and i<row-1 and matrix[i+1][j+1]=='*':
                num+=1

            print(num,end='')
                
        else :
            print('*',end='')
    print()
