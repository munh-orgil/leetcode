dic = {
    1: "One",
    2: "Two",
    3: "Three",
    4: "Four",
    5: "Five",
    6: "Six",
    7: "Seven",
    8: "Eight",
    9: "Nine",
    10: "Ten",
    11: "Eleven",
    12: "Twelve",
    13: "Thirteen",
    14: "Fourteen",
    15: "Fifteen",
    16: "Sixteen",
    17: "Seventeen",
    18: "Eighteen",
    19: "Nineteen",
}

tens = {
    2: "Twenty",
    3: "Thirty",
    4: "Forty",
    5: "Fifty",
    6: "Sixty",
    7: "Seventy",
    8: "Eighty",
    9: "Ninety",
}

def toName(num):
    ret = ""
    a = num // 100
    b = num // 10 % 10
    c = num % 10
    if a > 0:
        ret = dic[a] + " Hundred"

    if a > 0 and (b > 0 or c > 0):
        ret += " "
    
    if b > 1:
        ret += tens[b]
        if c > 0:
            ret += " " + dic[c]
    else:
        if b * 10 + c > 0:
            ret += dic[b * 10 + c]

    return ret
        
triples = {
    1: "Thousand",
    2: "Million",
    3: "Billion",
    4: "Trillion",
}

t = int(input())

while t > 0:
    n = int(input())
    if n == 0:
        print('Zero')
        t -= 1
        continue
    idx = 0
    res = []
    while n > 0:
        name = toName(n % 1000)
        if idx > 0 and name != "":
            name = name + " " + triples[idx]
        
        if name != "":
            res.append(name)
            
        idx = idx + 1
        n = n // 1000

    res.reverse()
    print(' '.join(res))
    t -= 1