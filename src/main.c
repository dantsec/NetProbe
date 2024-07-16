#include <stdlib.h>

#include "./include/utils.h"
#include "./include/dns.h"

/**
 * @brief Main function that executes the DNS lookup program.
 *
 * This main function checks if there are enough command-line arguments. If there are 
 * not at least two arguments, it displays the program's usage mode and exits with 
 * error code 1. Otherwise, it initializes a `dnsdata_v` structure to store the DNS 
 * lookup results. It then calls the `nslookup` function to perform the DNS lookup 
 * based on the provided arguments. After the lookup, it calls the `nslookup_dump` 
 * function to display the found results on the standard output. If there are DNS 
 * data stored in the `dnsV` structure, it frees the allocated memory. Finally, it 
 * returns 0 to indicate successful execution of the program.
 *
 * @param argc Number of arguments passed to the program.
 * @param argv Array of strings containing arguments passed to the program, where:
 *             - `argv[0]` is the program name.
 *             - `argv[1]` is the target domain for DNS lookup.
 *             - `argv[2]` (optional) is the filename of the keyword list file.
 * 
 * @return Returns 0 if the program executed successfully, otherwise returns an error code.
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
        exit(1);
    }

    // Structure to store DNS lookup results
    dnsdata_v dnsV;

    // Perform DNS lookup based on the provided arguments
    nslookup(argc, argv, &dnsV);

    // Display the DNS lookup results
    nslookup_dump(&dnsV);

    // Free allocated memory for DNS data, if any
    if (dnsV.dnsData) {
        free(dnsV.dnsData);
    }

    return 0;
}
