#include <stdio.h>

#ifndef DNS_H
#define DNS_H

typedef struct _dns_data_t {
    char host[128];
    char *host_addr;
} dnsdata_t;

typedef struct _dnsdata_v {
    dnsdata_t *dnsData;
    size_t size;
} dnsdata_v;

void nslookup(const int, char **, dnsdata_v *);
void splash(void);
void nslookup_dump(dnsdata_v *);

#endif // DNS_H
