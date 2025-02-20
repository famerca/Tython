#pragma once

typedef enum
{
  TOKEN_EOF = 0,
  TOKEN_STRING = 258,
  TOKEN_NOT = 259,
  TOKEN_AND = 260,
  TOKEN_OR = 261,
  TOKEN_TAB = 262,
  TOKEN_BICOND = 263,
  TOKEN_ASSIGN = 264,
  TOKEN_IDENTIFIER = 265,
  TOKEN_LPAREN = 266,
  TOKEN_RPAREN = 267,
  TOKEN_ARROW = 268,
  TOKEN_COMPARE = 270,
  TOKEN_DIFFERENT = 271,
  TOKEN_PRINT = 272,
  TOKEN_IF = 273,
  TOKEN_ELSE = 274,
  TOKEN_FOR = 275,
  TOKEN_WHILE = 276,
  TOKEN_FUNC_DEF = 277,
  TOKEN_RETURN = 278,
  TOKEN_GREATER = 280,
  TOKEN_LESS = 281,
  TOKEN_LESS_EQUAL = 282,
  TOKEN_GREATER_EQUAL = 283,
  TOKEN_COMMA = 284,
}
token_t;

inline const char* token_str(token_t t)
{
  switch(t)
  {
    case TOKEN_EOF: return "<EOF>";
    case TOKEN_STRING: return "<STRING>";
    case TOKEN_ASSIGN: return "<ASSIGNMENT>";
    case TOKEN_IDENTIFIER: return "<IDENTIFIER>";
    case TOKEN_LPAREN: return "<L_PAREN>";
    case TOKEN_RPAREN: return "<R_PAREN>";
    case TOKEN_ARROW: return "<ARROW>";
    case TOKEN_COMPARE: return "<COMPARE>";
    case TOKEN_DIFFERENT: return "<DIFFERENT>";
    case TOKEN_TAB: return "<TAB>";
    case TOKEN_PRINT: return "<PRINT>";
    case TOKEN_IF: return "<IF>";
    case TOKEN_BICOND: return "<BICOND>";
    case TOKEN_ELSE: return "<ELSE>";
    case TOKEN_FOR: return "<FOR>";
    case TOKEN_WHILE: return "<WHILE>";
    case TOKEN_FUNC_DEF: return "<FUNC_DEF>";
    case TOKEN_RETURN: return "<RETURN>";
    case TOKEN_GREATER: return "<GREATER>";
    case TOKEN_LESS: return "<LESS>";
    case TOKEN_LESS_EQUAL: return "<LESS_EQUAL>";
    case TOKEN_GREATER_EQUAL: return "<GREATER_EQUAL>";
    case TOKEN_COMMA: return "<COMMA>";
    

 
    default: return "<UNKNOWN>";
  }
}