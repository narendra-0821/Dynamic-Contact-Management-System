#ifndef CONTACT_H
#define CONTACT_H

struct CONTACT
{
    char *name;
    char *contactNo;
    char *emailId;
};

extern int cnt;

struct CONTACT *input(struct CONTACT *p);
void print(struct CONTACT *p);
void find(struct CONTACT *p);
void *sort(struct CONTACT *p);
struct CONTACT *delete(struct CONTACT *p);

#endif
