name = []
name.append("홍길동")
name.append("이순신")
print(name)
name.insert(0, "이세종")
print(name)
name.remove('이순신')
print(name)
del name[0]
print(name)
a = name.pop(0)
print(a, type(a))
print(name, type(name))
