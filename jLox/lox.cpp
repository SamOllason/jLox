//
//  lox.cpp
//  jLox
//
//  Created by Samuel Ollason on 20/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "lox.h"
#include "scanner.h"
#include "token.h"

using namespace std;

void Lox::runFile(string path) {
    string line;
    ifstream loxScript;
    loxScript.open(path);

    if (loxScript.is_open())
    {
//      while (getline (loxScript,line))
//      {
//        cout << line << '\n';
//      }
        
        // use an iterator to read entire contents of file
        std::string content((std::istreambuf_iterator<char>(loxScript))
                            ,(std::istreambuf_iterator<char>()));
        
        run(content);
        loxScript.close();
    } else {
        cout << "Unable to open file";
    }
}
    
void Lox::runPrompt() {
    cout << "> ";

    for(;;){
        string line;
        getline(cin, line);
        run(line);
    }
}

void Lox::run(string source) {
    Scanner* scanner = new Scanner(source);
    vector<Token*> tokens = scanner->scanTokens();

    // For now, just print the tokens.
    for(auto t: tokens) {
        cout << t->toString() << endl;
    }
}

void Lox::error(int line, string message) {
    report(line, "", message);
}

void Lox::report(int line, string where, string message) {
    cout << "[line " + to_string(line) + "] Error" + where + ": " + message;
    hadError_ =  true;
}
