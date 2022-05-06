INT_LIT = 10
IDENT_ = 11
ASSIGN_OP = 20
ADD_OP = 21
SUB_OP = 22
MULT_OP = 23
DIV_OP = 24
LEFT_PAREN = 25
RIGHT_PAREN = 26


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
  

