def bishopDiagonal(bishop1, bishop2):
    sort = sorted([bishop1,bishop2])
    bishop1 = sort[0]
    bishop2 = sort[1]
    if abs(int(bishop1[1])-int(bishop2[1]))!=ord(bishop2[0])-ord(bishop1[0]):
        return sort
    
    if bishop1[1]<bishop2[1]:
        while "a"<bishop1[0] and "1"<bishop1[1]:
            bishop1 = chr(ord(bishop1[0])-1)+str(int(bishop1[1])-1)
        while bishop2[0]<"h" and bishop2[1]<"8":
            bishop2 = chr(ord(bishop2[0])+1)+str(int(bishop2[1])+1)
        return sorted([bishop1,bishop2])
    
    if bishop1[1]>bishop2[1]:
        while "a"<bishop1[0] and bishop1[1]<"8":
            bishop1 = chr(ord(bishop1[0])-1)+str(int(bishop1[1])+1)
        while bishop2[0]<"h" and "1"<bishop2[1]:
            bishop2 = chr(ord(bishop2[0])+1)+str(int(bishop2[1])-1)
        return sorted([bishop1,bishop2])