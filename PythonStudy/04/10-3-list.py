a = ["고양이", "멍멍이"]
b = ["야옹이", "원숭이"]
c = a+b
d = [1] *5
e = [[1]] * 5
f = [1,2,3] *3
g = ["홍길동", [1]] *3
print(c)
print(d)
print(e)
print(f)
print(g)

A = [1,2,3]
B = [1,2,3]
C = [4,5,6]
A.append(C) # A = [1,2,3,[4,5,6]]
B.extend(C) # B = [1,2,3,4,5,6]
print(f"append 결과: {A}")
print(f"extend 결과: {B}")
