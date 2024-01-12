#ifndef _paras_hpp_INCLUDED
#define _paras_hpp_INCLUDED

#include <string>
#include <cstring>
#include <unordered_map>
#include "header.h"

//        name,               type,  short-name, must-need, default, low, high, comments
#define PARAS \
    PARA( cutoff            ,   double   , '\0' ,  false , 5000  , 0  , 1e8    , "Cutoff time") \
    PARA( nThreads          ,   int      , '\0' ,  false , 32    , 1  , 128    , "Thread number") \
    PARA( pool_size         ,   int      , '\0' ,  false , 7     , 0  , 100    , "size of solution pool") \
    PARA( feas_prop         ,   int      , '\0' ,  false , 50    , 0  , 100    , "The probability of choosing the feasiable sol when sharing") \
    PARA( pert_prop         ,   int      , '\0' ,  false , 25    , 0  , 100    , "The probability of child sol perturbation when sharing") \
    PARA( config_prop       ,   int      , '\0' ,  false , 75    , 0  , 100    , "The probability of choosing the picked config when sharing") \
    PARA( sharingPeriod     ,   int      , '\0' ,  false , 2000 , -3 , 1e11   , "Max no improve steps to share") \
    PARA( punish            ,   double   , '\0' ,  false , 0.0001, 0  , 1      , "the punish coeff to pool solution") \
    PARA( polarityNum       ,   int      , '\0' ,  false , 32    , 0  , 32     , "the number of thread to bias") \
    PARA( polarityProp      ,   int      , '\0' ,  false , 50    , 0  , 100    , "the probability of variable to bias") \
    PARA( rankpara          ,   int      , '\0' ,  false , 20    , 0  , 100    , "rankpara")  \
    PARA( seed              ,   int      , '\0' ,  false , 0     , 0  , 1000000, "random seed")  \
    PARA( PrintSol          ,   int      , '\0' ,  false , 0     , 0  , 1      , "print best found solution or not")

//            name,   short-name, must-need, default, comments
#define STR_PARAS \
    STR_PARA( instance   , 'i'   ,  true    , "" , ".mps format instance")
    
struct paras 
{
#define PARA(N, T, S, M, D, L, H, C) \
    T N = D;
    PARAS 
#undef PARA

#define STR_PARA(N, S, M, D, C) \
    std::string N = D;
    STR_PARAS
#undef STR_PARA

void parse_args(int argc, char *argv[]);
void print_change();
Integer identify_opt(const char *file);
};

#define INIT_ARGS __global_paras.parse_args(argc, argv);

extern paras __global_paras;

#define OPT(N) (__global_paras.N)

#endif