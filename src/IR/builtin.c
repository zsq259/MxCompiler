// enable bool type
#define bool _Bool
// libc function
int printf(const char* pattern, ...);
int scanf(const char* pattern, ...);

void print(char *str) {
    printf("%s", str);
}

void println(char *str) {
    printf("%s\n", str);
}

void printInt(int n) {
    printf("%d", n);
}

void printlnInt(int n) {
    printf("%d\n", n);
}

int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}