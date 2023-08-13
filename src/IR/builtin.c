// enable bool type
#define bool _Bool
// libc function
int printf(const char* pattern, ...);
int sprintf(char *dest, const char *pattern, ...);
int scanf(const char* pattern, ...);
int sscanf(const char *src, const char *pattern, ...);
unsigned strlen(const char *str);
int strcmp(const char *s1, const char *s2);
void *memcpy(void *dest, const void *src, int n);
void *malloc(unsigned n);

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

char *getString() {
	char *buffer = malloc(4096);
	scanf("%s", buffer);
	return buffer;
}

int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

char *toString(int i) {
	char *buffer = malloc(16);
	sprintf(buffer, "%d", i);
	return buffer;
}

int string_length(char *this_) {
	return strlen(this_);
}

char *string_substring(char *this_, int left, int right) {
	int length = right - left;
	char *buffer = malloc(length + 1);
	memcpy(buffer, this_ + left, length);
	buffer[length] = '\0';
	return buffer;
}

int string_parseInt(char *this_) {
	int n;
	sscanf(this_, "%d", &n);
	return n;
}

int string_ord(char *this_, int pos) {
	return this_[pos];
}

// < 
bool string_less(char *this_, char *other) {
	return strcmp(this_, other) < 0;
}

// <=
bool string_lessEq(char *this_, char *other) {
	return strcmp(this_, other) <= 0;
}

// >
bool string_greater(char *this_, char *other) {
	return strcmp(this_, other) > 0;
}

// >=
bool string_greaterEq(char *this_, char *other) {
	return strcmp(this_, other) >= 0;
}

// ==
bool string_equals(char *this_, char *other) {
	return strcmp(this_, other) == 0;
}

// !=
bool string_notEquals(char *this_, char *other) {
	return strcmp(this_, other) != 0;
}

// +
char *string_concat(char *this_, char *other) {
	int length = strlen(this_) + strlen(other);
	char *buffer = malloc(length + 1);
	memcpy(buffer, this_, strlen(this_));
	memcpy(buffer + strlen(this_), other, strlen(other));
	buffer[length] = '\0';
	return buffer;
}

