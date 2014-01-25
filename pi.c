//
//  main.cpp
//  pi
//
//  Created by Peter Olsen on 12/11/13.
//  Copyright (c) 2013 Peter Olsen. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <gmpxx.h>

const int DEFAULT_DIGITS = 1000;

void
exitWithUsage() {
    std::cout << "usage: pi <number-of-digits>\n";
    exit(EXIT_FAILURE);
}

int
digitsFromCommandLine(int argc, const char *argv[]) {
    if (argc > 2 || (argc > 1 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))) {
        exitWithUsage();
    }
    if (argc > 1)
        return atoi(argv[1]);
    else
        return DEFAULT_DIGITS;
}

mpz_class
arccot(int x, mpz_class unity) {
    mpz_class sum = 0;
    mpz_class divisor = unity / x;
    int coefficient = 1;
    mpz_class factor = divisor;
    while (factor != 0) {
        sum += factor;
        coefficient += 2;
        divisor *= -1;
        divisor /= x * x;
        factor = divisor / coefficient;
    }
    return sum;
}

mpz_class
pi(int digits) {
    mpz_class unity;
    mpz_ui_pow_ui(unity.get_mpz_t(), 10, digits + 10);
    mpz_class pi = 4 * (4 * arccot(5, unity) - arccot(239, unity));
    return pi / pow(10, 10);
}

int
main(int argc, const char * argv[])
{
    int digits = digitsFromCommandLine(argc, argv);
    std::string result = pi(digits).get_str();
    std::cout << "3." << result.substr(1) << std::endl;
}
