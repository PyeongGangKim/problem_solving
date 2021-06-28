plusMinus = [1,-1]
stack = []
result = 0
def check(target):
    global stack
    temp = 0
    for i in stack:
        temp += i
    if temp == target:
        return True
    else:
        return False
def dfs(cnt, numbers, target):
    global stack
    global result
    global plusMinus
    if cnt == len(numbers):
        if check(target):
            result += 1
    else:
        for i in plusMinus:
            stack.append(i* numbers[cnt])
            dfs(cnt + 1, numbers, target)
            stack.pop()
            
def solution(numbers, target):
    dfs(0,numbers, target)
    global result
    answer = result
    return answer