//
//  tokenType.h
//  jLox
//
//  Created by Samuel Ollason on 20/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#ifndef tokenType_h
#define tokenType_h

enum TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE_, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE_, VAR, WHILE,

  EOF_
};

#endif /* tokenType_h */
