//
//  main.cpp
//  jLox
//
//  Created by Samuel Ollason on 18/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "lox.h"


int main(int argc, const char* argv[]) {
    // insert code here...
    
//    for(int i = 0; i < argc; i++){
//        std::cout << argv[i] << std::endl;
//    }
    
    
    if (argc > 2) {
    
        std::cout << "Usage: jlox [script]";
        exit(64);
    } else if (argc == 2) {
        
        Lox* lox = new Lox();
        lox->runFile(argv[1]);
        
//      runFile(args[0]);
    } else {
        Lox* lox = new Lox();
        lox->runPrompt();
    }
    
    return 0;
    
    
//    Test1* testPtr = new Test1("my-test-loxer");
//    testPtr->Speak();
    
    return 0;
}
