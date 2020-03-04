//
//  token.h
//  jLox
//
//  Created by Samuel Ollason on 20/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#ifndef token_h
#define token_h

#include <stdlib.h>
#include <string>
#include "tokenType.h"

using namespace std;

class Token {
public:
    // todo: change literal to a Literal object?
    Token(TokenType type, string lexeme, string literal, bool isNumeric, int line) {
    // constructor
        type_ = type;
        lexeme_ = lexeme;
        literal_ = literal;
        isNumeric_ = isNumeric;
        line_ = line;
   };

private:
    TokenType type_;
    string lexeme_;
    string literal_;
    bool isNumeric_;
    int line_;
};


#endif /* token_h */
