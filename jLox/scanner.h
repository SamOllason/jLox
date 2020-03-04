//
//  scanner.h
//  jLox
//
//  Created by Samuel Ollason on 20/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#ifndef scanner_h
#define scanner_h
#include <vector>
#include <string>
#include "token.h"

using namespace std;

class Scanner {
public:
    Scanner(string source) {
        // constructor
        this->source_ = source;
    }
    
    vector<Token*> scanTokens();
    
    void scanToken();
    
    // TODO: include real number in here
    bool isAtEnd() { return current_ != source_.length(); };
    
private:
    string source_;
    vector<Token*> tokens_;
    
    int start_ = 0; // position of first character in current lexeme
    int current_ = 0;
    int line_ = 1;
    
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, string literal, bool isNumeric);
    bool match(char expected);
    char peek();
    char peekNext();
    void handleString();
    bool isDigit(char c);
    void handleNumber();
};

#endif /* scanner_h */

