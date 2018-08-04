//
//  ClienteEntry.hpp
//  sqlite1
//
//  Created by manuel on 7/27/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef ClienteEntry_hpp
#define ClienteEntry_hpp

#include <string>

using namespace std;

struct ClienteEntry {
    long id;
    string nombres;
    string apellidos;
    string dni;
    double fecha_de_inscripcion;
    string fecha_de_inscripcion_iso8601_string;
};

#endif /* ClienteEntry_hpp */
