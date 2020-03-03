//
//  lox.h
//  jLox
//
//  Created by Samuel Ollason on 19/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#ifndef lox_h
#define lox_h

using namespace std;

class Lox {
public:
    Lox() {
        // constructor
    }
    
    void runFile(string path);
    void runPrompt();
    void error(int line, string message);
    void report(int line, string where, string message);
    
    
private:

    bool hadError_ =  false;

};

#endif /* lox_h */
