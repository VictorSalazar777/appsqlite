//
//  DatosPersonalesEntry.hpp
//  sqlite1
//
//  Created by manuel on 7/27/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef DatosPersonalesEntry_hpp
#define DatosPersonalesEntry_hpp

#include <string>

using namespace std;

struct DatosPersonalesEntry {
    long long id;
    string nombres;
    string apellidos;
    string dni;
    double fecha_de_inscripcion;
    string fecha_de_inscripcion_iso8601_string;
};

#endif /* DatosPersonalesEntry_hpp */
