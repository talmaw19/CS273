""" part 1 """
strings = ['Some string','Art','Music','Artificial Intelligence']

print [x.lower() for x in strings if length(x) > 5]

newStrings = ([x.lower() if length(x) > 5 else x.upper() for x in strings])


print (newStrings)
