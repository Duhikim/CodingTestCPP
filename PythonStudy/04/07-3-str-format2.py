name = "홍길동"
age = 30
num = 10000
a = "제 이름은 {} 이며, 나이는 {} 입니다. " .format(name, age)
b = "제 이름은 {1} 이며, 나이는 {0} 입니다." .format(age, name)
c = "{:=<30}".format(name)
d = "{:>30}".format(name)
e = "{:*>30}".format(name)
f = "{:^30}".format(name)
g = "{:,}".format(num)
h = "{:<^50}".format(name)
print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)
print(h)