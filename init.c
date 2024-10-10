#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initPython() {
    char venvName[100];
    printf("Please enter the virtual environment name: ");
    scanf("%s", venvName);
    char command[150];
    sprintf(command, "python -m venv %s", venvName);
    system(command);
    printf("Python virtual environment '%s' has been created.\n", venvName);
}

void initJavaScript() {
    system("npm init -y");
    printf("npm project has been initialized.\n");
}

void initGo() {
    char goName[100];
    printf("Please enter the Go application name: ");
    scanf("%s", goName);
    char command[150];
    sprintf(command, "go mod init %s", goName);
    system(command);
    printf("Go module '%s' has been initialized.\n", goName);
}

void installPython() {
    char packageName[100];
    printf("Please enter the package name: ");
    scanf("%s", packageName);
    char command[150];
    sprintf(command, "pip install %s", packageName);
    system(command);
    printf("Python package '%s' has been installed.\n", packageName);
}

void installJavaScript() {
    char packageName[100];
    printf("Please enter the package name: ");
    scanf("%s", packageName);
    char command[150];
    sprintf(command, "npm install %s", packageName);
    system(command);
    printf("JavaScript package '%s' has been installed.\n", packageName);
}

void installGo() {
    char packageName[100];
    printf("Please enter the package name: ");
    scanf("%s", packageName);
    char command[150];
    sprintf(command, "go get %s", packageName);
    system(command);
    printf("Go package '%s' has been installed.\n", packageName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <mode> <language>\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *language = argv[2];

    if (strcmp(mode, "init") == 0) {
        if (strcmp(language, "py") == 0) {
            initPython();
        } else if (strcmp(language, "js") == 0) {
            initJavaScript();
        } else if (strcmp(language, "go") == 0) {
            initGo();
        } else {
            printf("Unsupported language: %s\n", language);
        }
    } else if (strcmp(mode, "install") == 0) {
        if (strcmp(language, "py") == 0) {
            installPython();
        } else if (strcmp(language, "js") == 0) {
            installJavaScript();
        } else if (strcmp(language, "go") == 0) {
            installGo();
        } else {
            printf("Unsupported language: %s\n", language);
        }
    } else {
        printf("Please provide a valid mode (init or install) and language (py, js, or go).\n");
    }

    return 0;
}
