
# Token Codes #

INT_LIT = 10
IDENT_ = 11
ASSIGN_OP = 20
ADD_OP = 21
SUB_OP = 22
MULT_OP = 23
DIV_OP = 24
LEFT_PAREN = 25
RIGHT_PAREN = 26


op = input("Ingresa la operacion -> ")
tam = len(op)


def verificador(element):
  if element == "(":
      return LEFT_PAREN
  elif element == ")":
       return RIGHT_PAREN
  elif element == "+":
       return ADD_OP
  elif element == "-":
       return SUB_OP
  elif element == "*":
       return MULT_OP
  elif element == "/":
       return DIV_OP
  elif element == "=":
       return ASSIGN_OP
  else:
       return 0


def analise(op,tam):
  var=" "
  var1=" "
  i=0
  temp1=0
  temp2=0

  while (i<tam):
    #print(op[i])
    #print ("i ",i)

    
    temporal=verificador(op[i])
    if temporal != 0:
      print(temporal, "Next lexeme is ", op[i])
      i+=1
      continue


    if temporal == 0:
      for j in range (i,tam):
        x=ord(op[i])
        #print("x",x)
        if x == 32:
          i+=1
          continue          
        if x>=97 and x<=122:
          var=var+op[i]
          temporal = 1
          i = i + 1
          temp1=1
          temp2=0
          #print("again", op[j])
        if x>=48 and x<=57:
          var1=var1+op[i]
          temporal = 1
          i = i + 1
          temp1=0
          temp2=1
        
      if temp1 == 1:
        print(IDENT_, "Next lexeme is ",var)
        var=""
        temp1=0
        temp2=0
      if temp2 == 1:
        print(INT_LIT, "Next lexeme is ",var1)
        var1=""
        temp1=0
        temp2=0



def factor():
  print("Enter <term>")
  if (nexToken ==IDENT_ or nexToken ==INT_LIT):
    lex()
  else:
    if (nextToken == LEFT_PAREN):
      lex()
      expr()
      if (nextToken == RIGHT_PAREN):
        lex()
      else:
        error()

def term():
  print("Enter <term>")
  term()
  while (nexToken == MULT_OP or nexToken == DIV_OP):
      lex()
      term()
    
  print("Exit <expr>")

  
def expr():
    print("Enter <expr>")
    term()

    while (nexToken == ADD_OP or nexToken == SUB_OP):
      lex()
      term()
    print("Exit <expr>")
  

    
analise(op,tam)
