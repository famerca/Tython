/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "token.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_STRING = 3,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_NOT = 4,                  /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_AND = 5,                  /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 6,                   /* TOKEN_OR  */
  YYSYMBOL_TOKEN_BREAK = 7,                /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_IN = 8,                   /* TOKEN_IN  */
  YYSYMBOL_TOKEN_ASSIGN = 9,               /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_IDENTIFIER = 10,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_LPAREN = 11,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 12,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_ARROW = 13,               /* TOKEN_ARROW  */
  YYSYMBOL_TOKEN_COMPARE = 14,             /* TOKEN_COMPARE  */
  YYSYMBOL_TOKEN_DIFFERENT = 15,           /* TOKEN_DIFFERENT  */
  YYSYMBOL_TOKEN_IF = 16,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 17,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_FOR = 18,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_WHILE = 19,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_FUNC_DEF = 20,            /* TOKEN_FUNC_DEF  */
  YYSYMBOL_TOKEN_RETURN = 21,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_GREATER = 22,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_LESS = 23,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 24,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 25,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_COMMA = 26,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_LINEBREAK = 27,           /* TOKEN_LINEBREAK  */
  YYSYMBOL_TOKEN_PLUS = 28,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 29,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLY = 30,            /* TOKEN_MULTIPLY  */
  YYSYMBOL_TOKEN_INDENT = 31,              /* TOKEN_INDENT  */
  YYSYMBOL_TOKEN_DEDENT = 32,              /* TOKEN_DEDENT  */
  YYSYMBOL_TOKEN_DIVIDE = 33,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_NUMBER = 34,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_COLON = 35,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_TYPE = 36,                /* TOKEN_TYPE  */
  YYSYMBOL_UMINUS = 37,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_start = 39,                     /* start  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_block = 41,                     /* block  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_stmt_if = 44,                   /* stmt_if  */
  YYSYMBOL_stmt_else = 45,                 /* stmt_else  */
  YYSYMBOL_stmt_for = 46,                  /* stmt_for  */
  YYSYMBOL_stmt_while = 47,                /* stmt_while  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_assignment = 49,                /* assignment  */
  YYSYMBOL_definition = 50,                /* definition  */
  YYSYMBOL_parameters = 51,                /* parameters  */
  YYSYMBOL_parameter = 52,                 /* parameter  */
  YYSYMBOL_arguments = 53,                 /* arguments  */
  YYSYMBOL_function_call = 54,             /* function_call  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_term = 56                       /* term  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 12 "parser.bison"

#include <stdio.h>
#include "ast.hpp"
#define YYDEBUG 1

extern int yylex();
int yyerror(const char*);

Ast* ast = NULL;



#line 172 "parser.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    63,    72,    76,    83,    87,    91,   104,
     107,   110,   113,   116,   119,   122,   123,   124,   125,   129,
     137,   138,   141,   148,   155,   159,   165,   171,   176,   184,
     189,   196,   199,   205,   210,   217,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   257,   260,   263,
     266,   269,   272,   278,   281,   284
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_STRING",
  "TOKEN_NOT", "TOKEN_AND", "TOKEN_OR", "TOKEN_BREAK", "TOKEN_IN",
  "TOKEN_ASSIGN", "TOKEN_IDENTIFIER", "TOKEN_LPAREN", "TOKEN_RPAREN",
  "TOKEN_ARROW", "TOKEN_COMPARE", "TOKEN_DIFFERENT", "TOKEN_IF",
  "TOKEN_ELSE", "TOKEN_FOR", "TOKEN_WHILE", "TOKEN_FUNC_DEF",
  "TOKEN_RETURN", "TOKEN_GREATER", "TOKEN_LESS", "TOKEN_LESS_EQUAL",
  "TOKEN_GREATER_EQUAL", "TOKEN_COMMA", "TOKEN_LINEBREAK", "TOKEN_PLUS",
  "TOKEN_MINUS", "TOKEN_MULTIPLY", "TOKEN_INDENT", "TOKEN_DEDENT",
  "TOKEN_DIVIDE", "TOKEN_NUMBER", "TOKEN_COLON", "TOKEN_TYPE", "UMINUS",
  "$accept", "start", "program", "block", "statement_list", "statement",
  "stmt_if", "stmt_else", "stmt_for", "stmt_while", "declaration",
  "assignment", "definition", "parameters", "parameter", "arguments",
  "function_call", "expression", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      50,   -40,    72,   -40,     1,    72,    72,    -9,    72,     7,
      72,    72,   -40,    11,   -40,    -8,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   170,   -40,    20,   182,    72,    72,
      15,   158,    75,    26,   106,    41,   170,   -40,   -40,    50,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,   170,   -10,   170,    28,   -40,    27,    72,    27,
      52,   -40,   182,     0,   194,   194,   194,   194,   194,   194,
       2,     2,   -40,   -40,   -40,    72,    72,    50,    46,   132,
     -40,    32,    -5,   -40,   170,   170,   -14,    37,   -40,    27,
      42,    51,    52,    58,    27,   -40,   -40,    55,    27,   -40,
     -40,   -40,    53,   -40,    27,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    54,     0,    16,    55,     0,     0,     0,     0,     0,
      17,     0,    53,     0,     2,     3,     6,     9,    10,    11,
      12,    13,    14,    51,    18,    52,    55,    49,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    50,     1,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    34,    25,    36,     0,     0,     0,
       0,     7,    43,    44,    37,    38,    41,    39,    40,    42,
      45,    46,    47,    48,    35,     0,     0,     0,    21,     0,
      23,    32,     0,    30,    33,    24,     0,     0,    19,     0,
       0,     0,     0,     4,     0,    22,    31,     0,     0,    29,
       5,    20,     0,    27,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -39,    10,    38,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,     3,   -40,   -40,    -2,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    14,    78,    15,    16,    17,    88,    18,    19,
      20,    21,    22,    82,    83,    53,    23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    33,    74,    31,    32,    40,    34,    91,    36,    37,
      28,    38,    29,    39,    42,    43,    75,    35,    93,    39,
      80,    92,    44,    45,    46,    47,    52,    54,    48,    49,
      50,    29,    50,    51,    58,    51,    30,    76,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      95,    55,    60,     1,     2,   101,    79,     3,    77,   103,
       4,     5,    81,    87,    97,   105,     6,    90,     7,     8,
       9,    10,    94,    84,    85,     1,     2,    61,    96,    11,
      40,    41,    26,     5,    12,   100,    98,    86,   104,    42,
      43,   102,     0,     0,     0,    99,     0,    44,    45,    46,
      47,    11,     0,    48,    49,    50,    12,     0,    51,     0,
      57,    40,    41,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,     0,     0,     0,     0,     0,    44,    45,
      46,    47,     0,     0,    48,    49,    50,    40,    41,    51,
       0,    59,     0,     0,     0,     0,    42,    43,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,     0,     0,
      48,    49,    50,    40,    41,    51,     0,    89,     0,     0,
      56,     0,    42,    43,     0,    40,    41,     0,     0,     0,
      44,    45,    46,    47,    42,    43,    48,    49,    50,     0,
       0,    51,    44,    45,    46,    47,    42,    43,    48,    49,
      50,     0,     0,    51,    44,    45,    46,    47,    -1,    -1,
      48,    49,    50,     0,     0,    51,    -1,    -1,    -1,    -1,
       0,     0,    48,    49,    50,     0,     0,    51
};

static const yytype_int8 yycheck[] =
{
       2,    10,    12,     5,     6,     5,     8,    12,    10,    11,
       9,     0,    11,    27,    14,    15,    26,    10,    32,    27,
      59,    26,    22,    23,    24,    25,    28,    29,    28,    29,
      30,    11,    30,    33,     8,    33,    35,     9,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      89,    36,    11,     3,     4,    94,    58,     7,    31,    98,
      10,    11,    10,    17,    13,   104,    16,    35,    18,    19,
      20,    21,    35,    75,    76,     3,     4,    39,    36,    29,
       5,     6,    10,    11,    34,    27,    35,    77,    35,    14,
      15,    36,    -1,    -1,    -1,    92,    -1,    22,    23,    24,
      25,    29,    -1,    28,    29,    30,    34,    -1,    33,    -1,
      35,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,     5,     6,    33,
      -1,    35,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,     5,     6,    33,    -1,    35,    -1,    -1,
      12,    -1,    14,    15,    -1,     5,     6,    -1,    -1,    -1,
      22,    23,    24,    25,    14,    15,    28,    29,    30,    -1,
      -1,    33,    22,    23,    24,    25,    14,    15,    28,    29,
      30,    -1,    -1,    33,    22,    23,    24,    25,    14,    15,
      28,    29,    30,    -1,    -1,    33,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     7,    10,    11,    16,    18,    19,    20,
      21,    29,    34,    39,    40,    42,    43,    44,    46,    47,
      48,    49,    50,    54,    55,    56,    10,    55,     9,    11,
      35,    55,    55,    10,    55,    10,    55,    55,     0,    27,
       5,     6,    14,    15,    22,    23,    24,    25,    28,    29,
      30,    33,    55,    53,    55,    36,    12,    35,     8,    35,
      11,    43,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    12,    26,     9,    31,    41,    55,
      41,    10,    51,    52,    55,    55,    42,    17,    45,    35,
      35,    12,    26,    32,    35,    41,    36,    13,    35,    52,
      27,    41,    36,    41,    35,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    41,    41,    42,    42,    42,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      45,    45,    46,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     5,
       3,     0,     6,     4,     5,     3,     3,     7,     9,     3,
       1,     3,     1,     3,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: program  */
#line 56 "parser.bison"
            {
        ast = (yyvsp[0].astNode);
        YYACCEPT;
    }
#line 1222 "parser.c"
    break;

  case 3: /* program: statement_list  */
#line 63 "parser.bison"
                   {
        (yyval.astNode) = new Ast("Root");
        (yyval.astNode)->addChild((yyvsp[0].astNode));

    }
#line 1232 "parser.c"
    break;

  case 4: /* block: TOKEN_INDENT statement_list TOKEN_DEDENT  */
#line 72 "parser.bison"
                                            {
        (yyval.astNode) = new Ast("Block");
        (yyval.astNode)->addChild((yyvsp[-1].astNode));
    }
#line 1241 "parser.c"
    break;

  case 5: /* block: TOKEN_INDENT statement_list TOKEN_DEDENT TOKEN_LINEBREAK  */
#line 76 "parser.bison"
                                                               {
        (yyval.astNode) = (yyvsp[-2].astNode);
    }
#line 1249 "parser.c"
    break;

  case 6: /* statement_list: statement  */
#line 83 "parser.bison"
             {
        (yyval.astNode) = new Ast("Statements");
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1258 "parser.c"
    break;

  case 7: /* statement_list: statement_list TOKEN_LINEBREAK statement  */
#line 87 "parser.bison"
                                              {
        (yyvsp[-2].astNode)->addChild((yyvsp[0].astNode));
        (yyval.astNode) = (yyvsp[-2].astNode);
    }
#line 1267 "parser.c"
    break;

  case 8: /* statement_list: statement_list TOKEN_LINEBREAK  */
#line 91 "parser.bison"
                                    {
        (yyval.astNode) = (yyvsp[-1].astNode); 
    }
#line 1275 "parser.c"
    break;

  case 9: /* statement: stmt_if  */
#line 104 "parser.bison"
            {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1283 "parser.c"
    break;

  case 10: /* statement: stmt_for  */
#line 107 "parser.bison"
               {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1291 "parser.c"
    break;

  case 11: /* statement: stmt_while  */
#line 110 "parser.bison"
                 {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1299 "parser.c"
    break;

  case 12: /* statement: declaration  */
#line 113 "parser.bison"
                  {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1307 "parser.c"
    break;

  case 13: /* statement: assignment  */
#line 116 "parser.bison"
                {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1315 "parser.c"
    break;

  case 14: /* statement: definition  */
#line 119 "parser.bison"
                {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1323 "parser.c"
    break;

  case 19: /* stmt_if: TOKEN_IF expression TOKEN_COLON block stmt_else  */
#line 129 "parser.bison"
                                                    { 
        (yyval.astNode) = new Statement((yyvsp[0].astNode) ? "If Else" : "If");
        (yyval.astNode)->addChild((yyvsp[-3].astNode));
        (yyval.astNode)->addChild((yyvsp[-1].astNode));
        if ((yyvsp[0].astNode)) (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1334 "parser.c"
    break;

  case 20: /* stmt_else: TOKEN_ELSE TOKEN_COLON block  */
#line 137 "parser.bison"
                                 { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1340 "parser.c"
    break;

  case 21: /* stmt_else: %empty  */
#line 138 "parser.bison"
             { (yyval.astNode) = nullptr; }
#line 1346 "parser.c"
    break;

  case 22: /* stmt_for: TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN expression TOKEN_COLON block  */
#line 141 "parser.bison"
                                                                    {
        (yyval.astNode) = new Ast("For ");
        (yyval.astNode)->addChild((yyvsp[-2].astNode));
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1356 "parser.c"
    break;

  case 23: /* stmt_while: TOKEN_WHILE expression TOKEN_COLON block  */
#line 148 "parser.bison"
                                            {
        (yyval.astNode) = new Ast("While");
        (yyval.astNode)->addChild((yyvsp[-2].astNode));
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1366 "parser.c"
    break;

  case 24: /* declaration: TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE TOKEN_ASSIGN expression  */
#line 155 "parser.bison"
                                                                   {
        (yyval.astNode) = new Declaration("", "");
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1375 "parser.c"
    break;

  case 25: /* declaration: TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE  */
#line 159 "parser.bison"
                                             {
        (yyval.astNode) = new Declaration("", "");
    }
#line 1383 "parser.c"
    break;

  case 26: /* assignment: TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 165 "parser.bison"
                                            {
        (yyval.astNode) = new Ast("Statement Assignment");
    }
#line 1391 "parser.c"
    break;

  case 27: /* definition: TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_COLON block  */
#line 171 "parser.bison"
                                                                                          {
        (yyval.astNode) = new Ast("Function Definition");
        (yyval.astNode)->addChild((yyvsp[-3].astNode));
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1401 "parser.c"
    break;

  case 28: /* definition: TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_ARROW TOKEN_TYPE TOKEN_COLON block  */
#line 176 "parser.bison"
                                                                                                                   {
        (yyval.astNode) = new Ast("Function Definition Typed");
        (yyval.astNode)->addChild((yyvsp[-5].astNode));
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1411 "parser.c"
    break;

  case 29: /* parameters: parameters TOKEN_COMMA parameter  */
#line 185 "parser.bison"
    {
        (yyvsp[-2].astNode)->addChild((yyvsp[0].astNode));
        (yyval.astNode) = (yyvsp[-2].astNode);
    }
#line 1420 "parser.c"
    break;

  case 30: /* parameters: parameter  */
#line 189 "parser.bison"
               {
        (yyval.astNode) = new Ast("Parameters");
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1429 "parser.c"
    break;

  case 31: /* parameter: TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE  */
#line 196 "parser.bison"
                                             {
        (yyval.astNode) = new Ast("Parameter Typed");
      }
#line 1437 "parser.c"
    break;

  case 32: /* parameter: TOKEN_IDENTIFIER  */
#line 199 "parser.bison"
                      {
        (yyval.astNode) = new Ast("Parameter");
    }
#line 1445 "parser.c"
    break;

  case 33: /* arguments: arguments TOKEN_COMMA expression  */
#line 206 "parser.bison"
    {
        (yyvsp[-2].astNode)->addChild((yyvsp[0].astNode));
        (yyval.astNode) = (yyvsp[-2].astNode);
    }
#line 1454 "parser.c"
    break;

  case 34: /* arguments: expression  */
#line 210 "parser.bison"
                {
        (yyval.astNode) = new Ast("Arguments");
        (yyval.astNode)->addChild((yyvsp[0].astNode));
    }
#line 1463 "parser.c"
    break;

  case 35: /* function_call: TOKEN_IDENTIFIER TOKEN_LPAREN arguments TOKEN_RPAREN  */
#line 217 "parser.bison"
                                                         {
        (yyval.astNode) = new Ast("Function Call");
        (yyval.astNode)->addChild((yyvsp[-1].astNode));
    }
#line 1472 "parser.c"
    break;

  case 36: /* expression: TOKEN_LPAREN expression TOKEN_RPAREN  */
#line 224 "parser.bison"
                                         {
        (yyval.astNode) = (yyvsp[-1].astNode);
    }
#line 1480 "parser.c"
    break;

  case 37: /* expression: expression TOKEN_COMPARE expression  */
#line 227 "parser.bison"
                                         {
        (yyval.astNode) = new Ast("Compare");
    }
#line 1488 "parser.c"
    break;

  case 38: /* expression: expression TOKEN_DIFFERENT expression  */
#line 230 "parser.bison"
                                           {
        (yyval.astNode) = new Ast("Different");
    }
#line 1496 "parser.c"
    break;

  case 39: /* expression: expression TOKEN_LESS expression  */
#line 233 "parser.bison"
                                      {
        (yyval.astNode) = new Ast("Less");
    }
#line 1504 "parser.c"
    break;

  case 40: /* expression: expression TOKEN_LESS_EQUAL expression  */
#line 236 "parser.bison"
                                            {
        (yyval.astNode) = new Ast("LessEqual");
    }
#line 1512 "parser.c"
    break;

  case 41: /* expression: expression TOKEN_GREATER expression  */
#line 239 "parser.bison"
                                         {
        (yyval.astNode) = new Ast("Greater");
    }
#line 1520 "parser.c"
    break;

  case 42: /* expression: expression TOKEN_GREATER_EQUAL expression  */
#line 242 "parser.bison"
                                               {
        (yyval.astNode) = new Ast("GreaterEqual");
    }
#line 1528 "parser.c"
    break;

  case 43: /* expression: expression TOKEN_AND expression  */
#line 245 "parser.bison"
                                     {
         (yyval.astNode) = new Ast("And");
    }
#line 1536 "parser.c"
    break;

  case 44: /* expression: expression TOKEN_OR expression  */
#line 248 "parser.bison"
                                     {
          (yyval.astNode) = new Ast("Or");
    }
#line 1544 "parser.c"
    break;

  case 45: /* expression: expression TOKEN_PLUS expression  */
#line 251 "parser.bison"
                                      {
        (yyval.astNode) = new Ast("Plus");
    }
#line 1552 "parser.c"
    break;

  case 46: /* expression: expression TOKEN_MINUS expression  */
#line 254 "parser.bison"
                                       {
        (yyval.astNode) = new Ast("Minus");
    }
#line 1560 "parser.c"
    break;

  case 47: /* expression: expression TOKEN_MULTIPLY expression  */
#line 257 "parser.bison"
                                          {
        (yyval.astNode) = new Ast("Multiply");
    }
#line 1568 "parser.c"
    break;

  case 48: /* expression: expression TOKEN_DIVIDE expression  */
#line 260 "parser.bison"
                                        {
        (yyval.astNode) = new Ast("Divide");
    }
#line 1576 "parser.c"
    break;

  case 49: /* expression: TOKEN_NOT expression  */
#line 263 "parser.bison"
                           {
        (yyval.astNode) = new Expression("", "");
    }
#line 1584 "parser.c"
    break;

  case 50: /* expression: TOKEN_MINUS expression  */
#line 266 "parser.bison"
                                          {
        (yyval.astNode) = new Expression("", "");
    }
#line 1592 "parser.c"
    break;

  case 51: /* expression: function_call  */
#line 269 "parser.bison"
                    {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1600 "parser.c"
    break;

  case 52: /* expression: term  */
#line 272 "parser.bison"
           {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1608 "parser.c"
    break;

  case 53: /* term: TOKEN_NUMBER  */
#line 278 "parser.bison"
                 {
        (yyval.astNode) = new Ast("Number");
    }
#line 1616 "parser.c"
    break;

  case 54: /* term: TOKEN_STRING  */
#line 281 "parser.bison"
                   {
        (yyval.astNode) = new Ast("String");
    }
#line 1624 "parser.c"
    break;

  case 55: /* term: TOKEN_IDENTIFIER  */
#line 284 "parser.bison"
                       {
        (yyval.astNode) = new Ast("Identifier");
    }
#line 1632 "parser.c"
    break;


#line 1636 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 289 "parser.bison"




int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}
