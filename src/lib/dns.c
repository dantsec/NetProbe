#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../include/dns.h"
#include "../include/utils.h"
#include "../include/constants.h"

/**
 * @brief Performs a DNS lookup for a given hostname suffix.
 *
 * This function performs a DNS lookup by iterating through a list of keywords 
 * provided by a text file or using a default file if not specified. For each 
 * keyword, it concatenates it with the argument `argv[1]` and attempts to resolve 
 * the resulting hostname using `gethostbyname`. Successful results are stored in 
 * a `dnsdata_v` data structure.
 *
 * @param argc Number of arguments passed to the program.
 * @param argv Array of strings containing arguments passed to the program, where:
 *             - `argv[1]` is the suffix to be concatenated with each keyword.
 *             - `argv[2]` (optional) is the filename of the keyword list file.
 * @param dnsV Pointer to `dnsdata_v` structure where DNS lookup results will be stored.
 */
void nslookup(const int argc, char *argv[], dnsdata_v *dnsV) {
    struct hostent *host;
    char *result;
    char txt[WORDLEN];
    FILE *wordlist;

    bool matched = false;
    size_t hostId = 0;

    wordlist = (argc < 3)
        ? fopen(DEFAULT_WORLDLIST, "r")
        : fopen(argv[2], "r");
    
    if (!wordlist) {
        fprintf(
            stderr,
            "[ERROR] - Opening the file: %s\n",
            (argc < 3) ? DEFAULT_WORLDLIST : argv[2]
        );
        
        exit(1);
    }

    dnsV->dnsData = (dnsdata_t *) calloc(countFileLines(wordlist), sizeof(dnsdata_t));

    while (fscanf(wordlist, "%s", &txt) != EOF) {
        result = (char *) strcat(txt, argv[1]);
        host = gethostbyname(result);

        if (!host) {
            continue;
        } else {
            strncpy(dnsV->dnsData[hostId].host, result, HOSTLEN);
            
            dnsV->dnsData[hostId].host_addr = inet_ntoa(*((struct in_addr *)(host->h_addr_list[0])));

            matched = true;
            
            hostId++;
        }
    }

    if (!matched) {
        free(dnsV->dnsData);
        dnsV->dnsData = NULL;
    }

    dnsV->size = hostId;
}

/**
 * @brief Displays DNS lookup results stored in a `dnsdata_v` structure.
 *
 * This function iterates through the data stored in `dnsV->dnsData` and prints 
 * the information of each found host, including the host name and associated IP address.
 *
 * @param dnsV Pointer to `dnsdata_v` structure containing DNS lookup data to be displayed.
 */
void nslookup_dump(dnsdata_v *dnsV) {
    dnsdata_t *hostInfo;

    if (!dnsV->dnsData) {
        fprintf(stderr, "[WARN] - Got nothing [!!]\n");
        return;
    }

    size_t hostId;

    for (hostId = 0; hostId < dnsV->size; hostId++) {
        hostInfo = &(dnsV->dnsData[hostId]);
        
        printf("╔═══════════════════════[ HOST FOUND ]═══════════════════════╗\n");
        printf("║ Host : %-49s ║\n", hostInfo->host);
        printf("║ IP   : %-49s ║\n", hostInfo->host_addr);
        printf("╚════════════════════════════════════════════════════════════╝\n");
    }
}
