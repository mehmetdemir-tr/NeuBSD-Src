int isalnum(int ch) {
    if ( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') ) return 1;
    return 0;
} 
int isalpha(int ch) {
    if ( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ) return 1;
    return 0;
}
int islower(int ch) {
    if ( (ch >= 'a' && ch <= 'z') ) return 1;
    return 0;
}
int isupper(int ch) {
    if ( (ch >= 'A' && ch <= 'Z') ) return 1;
    return 0;
}
int isdigit(int ch) {
    if ( (ch >= '0' && ch <= '9') ) return 1;
    return 0;
}
int isxdigit(int ch) {
    if ( (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f') || (ch >= '0' && ch <= '9') ) return 1;
    return 0;
} 
int iscntrl(int ch) {
    if ( (ch >= 0x00 && ch <= 0x1f) || ch == 0x7f ) return 1;
    return 0;
}
int isgraph(int ch) {
    if ( (ch >= 33 && ch <= 126) ) return 1;
    return 0;
}
int isspace(int ch) {
    if ( ch == 0x20 || ch == 0x0c || ch == 0x0a || ch == 0x0d || ch == 0x09 || ch == 0x0b ) return 1;
    return 0;
}
int isblank(int ch) {
    if ( ch == 0x20 || ch == 0x09 ) return 1;
    return 0;
}
int isprint(int ch) {
    if ( (ch >= 32 && ch <= 126) ) return 1;
    return 0;
}
int ispunct(int ch) {
    if ( (ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126) ) return 1;
    return 0;
}
int tolower(int ch) {
    if (isupper(ch)) return (int)ch + 32;
    return ch;
}
int toupper(int ch) {
    if (islower(ch)) return (int)ch - 32;
    return ch;
}