#include <stdio.h>
#include <sys/stat.h>
void displayPermissions(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file status");
        return;
    }
    printf("File Permissions for %s:\n", filename);
    printf("Owner: %c%c%c\n", (fileStat.st_mode & S_IRUSR) ? 'r' : '-', (fileStat.st_mode & S_IWUSR) ? 'w' : '-', (fileStat.st_mode & S_IXUSR) ? 'x' : '-');
    printf("Group: %c%c%c\n", (fileStat.st_mode & S_IRGRP) ? 'r' : '-', (fileStat.st_mode & S_IWGRP) ? 'w' : '-', (fileStat.st_mode & S_IXGRP) ? 'x' : '-');
    printf("Others: %c%c%c\n", (fileStat.st_mode & S_IROTH) ? 'r' : '-', (fileStat.st_mode & S_IWOTH) ? 'w' : '-', (fileStat.st_mode & S_IXOTH) ? 'x' : '-');
}
void setPermissions(const char *filename, mode_t permissions) {
    if (chmod(filename, permissions) == -1) {
        perror("Error setting file permissions");
        return;
    }
    printf("Permissions for %s set successfully.\n", filename);
}
int main() {
    const char *filename = "example.txt";
    mode_t newPermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; 

    setPermissions(filename, newPermissions);
    displayPermissions(filename);

    return 0;
}

