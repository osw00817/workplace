num = 210

print(bin(num)) 
print(oct(num)) 
print(hex(num))
print(int(bin(num),2))
print(int(oct(num),8))
print(int(hex(num),16))

print(ord('0'))

## 48~57
## 65~
## 97~

abc = [ord(char) for char in "HUNBAE"]

for x in abc:
    print(chr(x))

def is_palindrome(s):
    print(s)
    if len(s) <= 1:  # 문자열 길이가 1 이하라면 팰린드롬
        return True
    if s[0] != s[-1]:  # 첫 문자와 마지막 문자가 다르면 팰린드롬이 아님
        return False
    return is_palindrome(s[1:-1])  # 재귀적으로 나머지 문자열 검사

# 테스트
print(is_palindrome("radar"))  # True
print(is_palindrome("hello"))  # False

def test(s):
    print(s)
    if(len(s) <= 1):
        return True
    if s[0] != s[-1]:
        return False
    return test(s[1:-1])

def test(s):
    stack = []
    pair = {')':'(','}':'{',']':'['}

    for char in s:
        if char in '([{':
            stack.append(char)
        elif char in ')]}':
            if not stack or stack[-1] != pair[char]:
                return False
            stack.pop()
    return not stack

print(test("(())"))