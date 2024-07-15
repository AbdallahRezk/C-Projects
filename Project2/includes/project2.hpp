#ifndef _PEOJECT2_
#define _PROJECT2_

#include <string>
using namespace std;
////*******************************************************************///
///////////////////////MAX FUNCTION/////////////////////////////////////
 //////////////////used for one variable////////////////////////////////
namespace lib{
auto max(const int & T){  
   return T;
}

/////////////////////////
/////////////////////////used For 2 variables/////////////////////////////
template <typename T,typename U>

auto max(const T& a,const U& b){  
    auto r = (a > b) ? a : b;
    return r;
}
////////////////////used for more than 2 variables////////////////////////////////
template <typename T,typename U,typename ...TS>   //template packing
auto max(const T&a,const U&b,const TS&... c){
    auto r = (a > b) ? a : b;
    if constexpr ( sizeof...(TS) > 0 ){
        return max(r,c ...);         ////un-pack
    }
    return r;

    }

  ///  ********************MIN FUNCTION/////////////////////////////////////////////
  ///////////////////////MIN FUNCTION/////////////////////////////////////
 //////////////////used for one variable////////////////////////////////

auto min(const int & T){  
   return T;
}

/////////////////////////
/////////////////////////used For 2 variables/////////////////////////////
template <typename T,typename U>

auto min(const T& a,const U& b){  
    auto r = (a < b) ? a : b;
    return r;
}
////////////////////used for more than 2 variables////////////////////////////////
template <typename T,typename U,typename ...TS>   //template packing
auto min(const T&a,const U&b,const TS&... c){
    auto r = (a < b) ? a : b;
    if constexpr ( sizeof...(TS) > 0 ){
        return min(r,c ...);         ////un-pack
    }
    return r;

    }

///  ********************SUb FUNCTION///////////////////////////////////
//////////////////////SUB FUNCTION/////////////////////////////////////
//////////////////used for one variable////////////////////////////////
auto sub(const int & T){  
   return T;
}
/////////////////////////
/////////////////////////used For 2 variables/////////////////////////////

template <typename T,typename U>

auto sub(const T& a,const U& b){  
    auto r = a-b;
    return r;
}   

template <typename T,typename U,typename ...TS>   //template packing

auto sub(const T&a,const U&b,const TS&... c){
    auto r = a-b;
    if constexpr ( sizeof...(TS) > 0 ){
        return sub(r,c ...);         ////un-pack
    }
    return r;

    }

}



#endif 