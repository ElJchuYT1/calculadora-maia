#include <stdio.h>

// Función para convertir Fecha Gregoriana a Día Juliano (JD)
long gregorian_to_julian(int day, int month, int year) {
    if (month <= 2) {
        year--;
        month += 12;
    }
    long a = year / 100;
    long b = a / 4;
    long c = 2 - a + b;
    long e = 365.25 * (year + 4716);
    long f = 30.6001 * (month + 1);
    
    return c + day + e + f - 1524.5;
}

// Función para convertir el Día Juliano (JD) a Fecha Gregoriana
void julian_to_gregorian(long jd, int *day, int *month, int *year) {
    long l = jd + 68569;
    long n = (4 * l) / 146097;
    l = l - (146097 * n + 3) / 4;
    long i = (4000 * (l + 1)) / 1461001;
    l = l - (1461 * i) / 4 + 31;
    long j = (80 * l) / 2447;
    
    *day = l - (2447 * j) / 80;
    l = j / 11;
    *month = j + 2 - (12 * l);
    *year = 100 * (n - 49) + i + l;
}

void convertir_gregorian_a_maya() {
    int day, month, year;
    
    printf("\n--- Conversor de Calendario Gregoriano a Cuenta Larga Maya ---\n");
    printf("Ingrese la fecha moderna en formato (Dia Mes Ano) separados por espacios: ");
    
    if (scanf("%d %d %d", &day, &month, &year) != 3) {
        printf("Error al leer los datos de entrada.\n");
        return;
    }

    long julian_day = gregorian_to_julian(day, month, year);
    long maya_days = julian_day - 584282L;

    if (maya_days < 0) {
        printf("Error: La fecha ingresada es anterior a la creacion Maya (11/08/-3114).\n");
        return;
    }

    long remaining = maya_days;
    long baktun = remaining / 144000L;
    remaining %= 144000L;
    long katun = remaining / 7200L;
    remaining %= 7200L;
    long tun = remaining / 360L;
    remaining %= 360L;
    long uinal = remaining / 20L;
    long kin = remaining % 20L;

    printf("\n[Resultado]\n");
    printf("Dia Juliano calculado (JD): %ld\n", julian_day);
    printf("Total de Dias Maya: %ld\n", maya_days);
    printf("Fecha Equivalente Cuenta Larga: %ld.%ld.%ld.%ld.%ld\n", baktun, katun, tun, uinal, kin);
}

void convertir_maya_a_gregorian() {
    int baktun, katun, tun, uinal, kin;
    int d, m, y;

    printf("\n--- Conversor de Cuenta Larga Maya a Calendario Gregoriano ---\n");
    printf("Ingrese la fecha en formato (Baktun Katun Tun Uinal Kin) separados por espacios: ");
    
    if (scanf("%d %d %d %d %d", &baktun, &katun, &tun, &uinal, &kin) != 5) {
        printf("Error al leer los datos de entrada.\n");
        return;
    }

    long maya_days = (baktun * 144000L) + 
                     (katun * 7200L) + 
                     (tun * 360L) + 
                     (uinal * 20L) + 
                     (kin * 1L);

    long julian_day = maya_days + 584283L;
    julian_to_gregorian(julian_day, &d, &m, &y);

    printf("\n[Resultado]\n");
    printf("Total de Dias Maya: %ld\n", maya_days);
    printf("Dia Juliano (JD): %ld\n", julian_day);
    printf("Fecha Equivalente Gregoriana: %02d/%02d/%d\n", d, m, y);
}

int main() {
    int opcion;

    printf("===========================================\n");
    printf("    SISTEMA DE CONVERSION CALENDARICA\n");
    printf("===========================================\n");
    printf("1. Calendario Gregoriano -> Cuenta Larga Maya\n");
    printf("2. Cuenta Larga Maya -> Calendario Gregoriano\n");
    printf("Seleccione una opcion (1 o 2): ");

    if (scanf("%d", &opcion) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    switch (opcion) {
        case 1:
            convertir_gregorian_a_maya();
            break;
        case 2:
            convertir_maya_a_gregorian();
            break;
        default:
            printf("Opcion no valida. Por favor, ejecute el programa nuevamente.\n");
            break;
    }

    return 0;
}