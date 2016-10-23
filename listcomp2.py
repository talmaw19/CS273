""" part 1 """
numbers = [1,2,3,4,5,6]
oddNumbers = [x for x in nums for x % 2 == 1 ]
if oddNumber > 5:
   print oddNumbers.lower() ''' shows the lower case of each string that is less than 5''''
else:
   print oddnumbers 
oddNumsPlus1 =[x+1 for x in numbers if x % 2 = 1]
if oddNumbers > 5: 
   print oddNumbers.lower()
else:
   print oddNumbers 
  
'''"part 2 "'''
strings = ['Some string','Art','Music','Artificial Intelligence']

print [x.lower() for x in strings if length(x) > 5] 

newStrings = ([x.lower() if length(x) > 5 else x.upper() for x in strings])

print (newStrings) 
