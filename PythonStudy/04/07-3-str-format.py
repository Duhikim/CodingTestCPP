age = 30
weight = 13.5
number = 125
name = "홍길동"

a = "제 성은 %c 입니다." %name[0]
b = "제 이름은 %s 입니다." %name[1:]
c = "제 나이는 %d 입니다." %age
d = "몸무게는 %f kg 입니다." %weight
e = "십진수 %d는 8진수로 %o 입니다." % (number, number)
f = "십진수 %d는 16진수로는 %x 입니다." %(number, number)

print(a)
print(b)
print(c)
print(d)
print(e)
print(f)

g = 1234
h = 10.5
i = "변수 g의 값은 {} 이고 변수 h의 값은 {} 입니다." .format(g, h)
print(i)

j = "   {}  ".format("안녕")
print(j)