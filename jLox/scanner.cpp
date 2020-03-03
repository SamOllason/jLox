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

vector<Token> Scanner::scanTokens()
{
    while(!isAtEnd()){
        // We are at beginning of next lexeme
        start_ = current_;
        scanToken();
    }
//    this->tokens_.push_back(new Token(EOF, "", null, line))
    
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
           default:
               Lox* lox = new Lox();
               // notice how we report error but keep scanning!
               lox->error(line_, "Unexpected character.");
        }
}


char Scanner::advance() {
    // consume next character in the input
    current_++;
    return source_.at(current_ - 1);
}

void Scanner::addToken(TokenType type) {
    // TODO: need a new class to represent Literal (not a string!)
    string literalToReplace = "x";
    addToken(type, literalToReplace);
}

void Scanner::addToken(TokenType type, string literal) {
    string text = source_.substr(start_, current_);
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
