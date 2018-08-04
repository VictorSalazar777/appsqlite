//
//  ClienteEntry.h
//  sqlite2
//
//  Created by manuel on 8/4/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef ClienteEntry_h
#define ClienteEntry_h

#include <iostream>

using namespace std;

struct ClienteEntry {
    long long id;
    string nombres;
    string apellidos;
    string dni;
    void print(){
        cout << "id: " << id << ", nombres: " << nombres << ", apellidos: " << apellidos << ", dni: " << dni << endl;
    };
};

#endif /* ClienteEntry_h */
