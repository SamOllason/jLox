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
    Token(TokenType type, string lexeme, string literal, int line) {
    // constructor
        this->type_ = type;
        this->lexeme_ = lexeme;
        this->literal_ = literal;
        this->line_ = line;
   };

    string toString() {
        return type_ + " " + lexeme_ + " " + literal_;
    }

private:

    TokenType type_;
    string lexeme_;
    string literal_;
    int line_;
};


#endif /* token_h */
