//
//  lox.cpp
//  jLox
//
//  Created by Samuel Ollason on 20/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "lox.h"

using namespace std;

void Lox::runFile(string path) {
    cout << "run file " + path << endl;
    ifstream myfile (path);
    
    // opening file
    
    if (myfile.is_open())
    {
//          while (getline (myfile,line))
//          {
//            cout << line << '\n';
//          }
      myfile.close();
    }

    else cout << "Unable to open file";
//        run(myFile);
}
    
void Lox::runPrompt() {
    
    for(;;){
        cout << "> " << endl;
//            run(reader.readLine());
    }

}

void run(string source) {
//    Scanner scanner = new Scanner(source);
//    vector<Token> tokens = scanner.scanTokens();
//
//    // For now, just print the tokens.
//    for(auto t: tokens) {
//        cout << t << endl;
//    }
}

void Lox::error(int line, string message) {
    report(line, "", message);
}

void Lox::report(int line, string where, string message) {
    cout << "[line " + std::to_string(line) + "] Error" + where + ": " + message;
    hadError_ =  true;
}
