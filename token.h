/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.bison"

    #include "ast.hpp"
    #include <string>

#line 54 "token.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_STRING = 258,            /* TOKEN_STRING  */
    TOKEN_NOT = 259,               /* TOKEN_NOT  */
    TOKEN_AND = 260,               /* TOKEN_AND  */
    TOKEN_OR = 261,                /* TOKEN_OR  */
    TOKEN_BREAK = 262,             /* TOKEN_BREAK  */
    TOKEN_IN = 263,                /* TOKEN_IN  */
    TOKEN_ASSIGN = 264,            /* TOKEN_ASSIGN  */
    TOKEN_IDENTIFIER = 265,        /* TOKEN_IDENTIFIER  */
    TOKEN_LPAREN = 266,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 267,            /* TOKEN_RPAREN  */
    TOKEN_ARROW = 268,             /* TOKEN_ARROW  */
    TOKEN_COMPARE = 269,           /* TOKEN_COMPARE  */
    TOKEN_DIFFERENT = 270,         /* TOKEN_DIFFERENT  */
    TOKEN_IF = 271,                /* TOKEN_IF  */
    TOKEN_ELSE = 272,              /* TOKEN_ELSE  */
    TOKEN_FOR = 273,               /* TOKEN_FOR  */
    TOKEN_WHILE = 274,             /* TOKEN_WHILE  */
    TOKEN_FUNC_DEF = 275,          /* TOKEN_FUNC_DEF  */
    TOKEN_RETURN = 276,            /* TOKEN_RETURN  */
    TOKEN_GREATER = 277,           /* TOKEN_GREATER  */
    TOKEN_LESS = 278,              /* TOKEN_LESS  */
    TOKEN_LESS_EQUAL = 279,        /* TOKEN_LESS_EQUAL  */
    TOKEN_GREATER_EQUAL = 280,     /* TOKEN_GREATER_EQUAL  */
    TOKEN_COMMA = 281,             /* TOKEN_COMMA  */
    TOKEN_LINEBREAK = 282,         /* TOKEN_LINEBREAK  */
    TOKEN_PLUS = 283,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 284,             /* TOKEN_MINUS  */
    TOKEN_MULTIPLY = 285,          /* TOKEN_MULTIPLY  */
    TOKEN_INDENT = 286,            /* TOKEN_INDENT  */
    TOKEN_DEDENT = 287,            /* TOKEN_DEDENT  */
    TOKEN_DIVIDE = 288,            /* TOKEN_DIVIDE  */
    TOKEN_NUMBER = 289,            /* TOKEN_NUMBER  */
    TOKEN_COLON = 290,             /* TOKEN_COLON  */
    TOKEN_TYPE = 291,              /* TOKEN_TYPE  */
    UMINUS = 292                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 6 "parser.bison"


    Ast* astNode;
    

#line 114 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
