a = (1,2,3)
b = tuple((4,5,6))
c = tuple([7,8,9])
d = (1,)
e = (1)
f = "홍길동", "이순신", "강감찬"
name1, name2, name3 = f

print(f"a:{a} , tupe:{type(a)}")
print(f"a:{b} , tupe:{type(b)}")
print(f"a:{c} , tupe:{type(c)}")
print(f"a:{d} , tupe:{type(d)}")
print(f"a:{e} , tupe:{type(e)}")
print(f"a:{f} , tupe:{type(f)}")
print(f"name1 : {name1}, name2 : {name2}, name3 : {name3}")