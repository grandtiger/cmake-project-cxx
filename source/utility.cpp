/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 CMake project...

 Copyright (c) 2018 Micheal Brockus
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "utility.hpp"

using namespace std;


const inline bool itsTrue(const bool expresion){
    return ((expresion)? ( true ) : ( false ) );
}//end of function itsTrue



const inline bool itsFalse(const bool expresion){
    return ((!expresion)? ( true ) : ( false ) );
}//end of function itsFalse



const inline bool notTrue(const bool expresion){
    return ((!expresion)? ( true ) : ( false ) );
}//end of function notTrue



const inline bool notFalse(const bool expresion){
    return ((expresion)? ( true ) : ( false ) );
}//end of function notFalse



const int didReturnSuccess(void){
    return (EXIT_SUCCESS);
}//end of function didReturnSuccess



const int didReturnFailure(void){
    return (EXIT_FAILURE);
}//end of function didReturnFailure
