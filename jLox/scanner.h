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
#include <map>
#include <string>
#include "token.h"

using namespace std;

class Scanner {
public:
    Scanner(string source) {
        // constructor
        source_ = source;
        
        keywords_["and"]     = AND;
        keywords_["class"]   = CLASS;
        keywords_["else"]    = ELSE;
        keywords_["false"]   = FALSE_;
        keywords_["for"]     = FOR;
        keywords_["fun"]     = FUN;
        keywords_["if"]      = IF;
        keywords_["nil"]     = NIL;
        keywords_["or"]      = OR;
        keywords_["print"]   = PRINT;
        keywords_["return"]  = RETURN;
        keywords_["super"]   = SUPER;
        keywords_["this"]    = THIS;
        keywords_["true"]    = TRUE_;
        keywords_["var"]     = VAR;
        keywords_["while"]   = WHILE;
    }
    
    vector<Token*> scanTokens();
    
    void scanToken();
    
    // TODO: include real number in here
    bool isAtEnd() { return current_ >= source_.length(); };
    
private:
    string source_;
    vector<Token*> tokens_;
    map<string, TokenType> keywords_;
    
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
    void identifier();
    bool isAlpha(char c);
    bool isAlphaNumeric(char c);
    void handleNumber();
};

#endif /* scanner_h */

