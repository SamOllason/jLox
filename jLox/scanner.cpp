//
//  scanner.cpp
//  jLox
//
//  Created by Samuel Ollason on 20/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#include "Scanner.h"
#include "token.h"
#include <vector>
#include "lox.h"

vector<Token*> Scanner::scanTokens()
{
    while(!isAtEnd()){
        // We are at beginning of next lexeme
        start_ = current_;
        scanToken();
    }
    
    Token* t = new Token(EOF_, "", "", false, line_);
    
    tokens_.push_back(t);
    
    return tokens_;
}

void Scanner::scanToken()
{
    char c = advance();
    switch (c) {
        case '(': addToken(LEFT_PAREN); break;
        case ')': addToken(RIGHT_PAREN); break;
        case '{': addToken(LEFT_BRACE); break;
        case '}': addToken(RIGHT_BRACE); break;
        case ',': addToken(COMMA); break;
        case '.': addToken(DOT); break;
        case '-': addToken(MINUS); break;
        case '+': addToken(PLUS); break;
        case ';': addToken(SEMICOLON); break;
        case '*': addToken(STAR); break;
            
            // two character lexemes
        case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
        case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
        case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
        case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
        case '/' : {
            if(match('/')) {
                // if here then next char is also a slash, so we know that
                // this is a comment (comments end at end of line).
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                // if here then slash was not for a comment but a divide
                addToken(SLASH); break;
            }
        }
            
            // ignore whitespace - start off new lexeme after whitespace char
        case ' ':
        case '\r':
        case '\t':
            // Ignore whitespace.
            break;
            
        case '\n':
            line_++;
            break;
            
        case '"': handleString(); break;
            
        default:
            if(isDigit(c)){
                handleNumber();
            } else if(isAlpha(c)) {
                
            }
            else {
                Lox* lox = new Lox();
                // notice how we report error but keep scanning!
                lox->error(line_, "Unexpected character.");
            }
    }
}


char Scanner::advance() {
    // consume next character in the input
    current_++;
    return source_.at(current_ - 1);
}

void Scanner::addToken(TokenType type) {
    // TODO: need a new class to represent Literal (not a string!)
    string literal = "";
    bool isNumeric = false;
    addToken(type, literal, isNumeric);
}

void Scanner::addToken(TokenType type, string literal, bool isNumeric) {
    string text = source_.substr(start_, current_);
    Token* t = new Token(type, text, literal, isNumeric, line_);
    tokens_.push_back(t);
}

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source_.at(current_) != expected) return false;
    
    current_++;
    return true;
}

char Scanner::peek() {
    // lookahead a single character. Return the next character,
    // unless at the end of a line
    if (isAtEnd()) return '\0';
    return source_.at(current_);
}

char Scanner::peekNext() {
    // return character after next character
    if (current_ + 1 >= source_.length()) return '\0';
    return source_.at(current_ + 1);
}

void Scanner::handleString() {
    
    while(peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line_++;
        advance();
    }
    
    // handle unterminated strings
    if(isAtEnd()) {
        // at end of file so handle error
        Lox* lox = new Lox();
        lox->error(line_, "Unterminated string");
    }
    
    // consume the closing '"'
    advance();
    
    bool isNumeric = false;
    addToken(STRING, source_.substr(start_, current_ - 1), isNumeric);
}

bool Scanner::isDigit(char c) {
    return (int)c >= 0 && (int)c <= 9;
}

void Scanner::identifier() {
    while(isAlphaNumeric(peek())) advance();
    
    // See if the identifier is a reserved word.
    string text    = source_.substr(start_, current_);
    
    TokenType type = keywords_.find(text) == keywords_.end() ? IDENTIFIER : keywords_.at(text);
    
    addToken(type);
}

bool Scanner::isAlpha(char c) {
    return
    (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') ||
    c == '_';
}

bool Scanner::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}

void Scanner::handleNumber() {
    while(isDigit(peek())){
        advance();
    }
    
    // check for number after a decimal
    // Note: we do not allow trailing decimal points!
    if(peek() == '.' && isDigit(peekNext())){
        
        // consume the "."
        advance();
        
        // consume digits representing decimal places
        while(isDigit(peek())){
            advance();
        }
    }
    
    bool isNumeric = true;
    addToken(NUMBER, source_.substr(start_, current_), isNumeric);
}
