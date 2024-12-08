#include <iostream>
#include <string>

//Función para obtener la primera vocal interna de una cadena de texto  
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return c;
        }
    }
    return 'X'; // Si no se encuentra ninguna vocal interna, se usa la 'X'
}

//Función principal para calcular RFC 
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento) {
    std::string rfc;
    
    // Se obtiene la letra inicial y la primera vocal interna del apellido paterno     
    char letraInicial = apellidoPaterno[0];
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    // Se obtiene la letra inicial del apellido materno o se usa una 'X' si no la tiene 
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    // Se obtiene la letra inicial del nombre
    char inicialNombre = nombre[0];

    // Se obtienen los dos últimos dígitos del año de nacimiento 
    std::string anio = fechaNacimiento.substr(2, 2);

    // Se obtiene el mes y el día de nacimiento
    std::string mes = fechaNacimiento.substr(5, 2);
    std::string dia = fechaNacimiento.substr(8, 2);

    // Se construye el RFC
    rfc = letraInicial;
    rfc += primeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;
    
    return rfc; // Retornar el RFC
}
    
int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
     
    std::cout << "Ingrese su nombre: "; 
    std::getline(std::cin, nombre);
     
    std::cout << "Ingrese el apellido paterno: "; 
    std::getline(std::cin, apellidoPaterno);
     
    std::cout << "Ingrese el apellido materno: (si no tiene, pulse Enter) "; 
    std::getline(std::cin, apellidoMaterno);
     
    std::cout << "Ingrese su fecha de nacimiento (YYYY/MM/DD): "; 
    std::getline(std::cin, fechaNacimiento);
    
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
     
    std::cout << "RFC: " << rfc << std::endl;
     
    return 0;
}
