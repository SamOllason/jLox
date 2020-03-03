//
//  test1.h
//  jLox
//
//  Created by Samuel Ollason on 19/02/2020.
//  Copyright © 2020 Samuel Ollason. All rights reserved.
//

#ifndef test1_h
#define test1_h

using namespace std;

class Test1 {
public:
    Test1(string name) {
        // constructor
        privateName = name;
    }
    
    void Speak(){
        std::cout << "My name is " + this->privateName << endl;
    };   
    
private:
    std::string privateName;
    
};

#endif /* test1_h */
