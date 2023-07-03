#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>
// gcc block.c -o block $(pkg-config --cflags --libs gtk+-3.0)

bool time_to_close = true;
int width, height;

FILE* clean_and_open_log_file() {
    FILE* file = fopen("logs.txt", "w");
    if (file != NULL) {
        fclose(file);
        file = fopen("logs.txt", "a");
    }
    return file;
}

void writeLog(FILE* file, const char* message) {
    if (file != NULL) {
        fprintf(file, "%s\n", message);
        fflush(file);
    }
}

void window_close_callback(GLFWwindow* window)
{
    if (!time_to_close)
        glfwSetWindowShouldClose(window, GLFW_FALSE);
}

void render(GLFWwindow* window)
{      
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Perform additional rendering here...
    // Set up an orthographic projection matrix to match the window dimensions
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    
    // Set the modelview matrix as the identity matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Calculate the center position of the square
    float squareSize = 100.0f; // Adjust this value as desired
    float squareHalfSize = squareSize / 2.0f;
    float squareX = (width - squareSize) / 2.0f;
    float squareY = (height - squareSize) / 2.0f;
    
    // Render the square
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f); // Set the color of the square (red in this case)
    glVertex2f(squareX, squareY);
    glVertex2f(squareX + squareSize, squareY);
    glVertex2f(squareX + squareSize, squareY + squareSize);
    glVertex2f(squareX, squareY + squareSize);
    glEnd();
}

int main(int argc, char *argv[])
{
    FILE* logFile = clean_and_open_log_file();
    writeLog(logFile, "🧊 Logs for Block, a minecraft clone 🧊");

    printf("Initializing glfw\n");
    writeLog(logFile, "Initializing GLFW");
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    printf("Creating window\n");
    writeLog(logFile, "Creating Window");
    GLFWwindow* window = glfwCreateWindow(1080, 600, "Block", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    printf("Setting window callback\n");
    writeLog(logFile, "Setting Window Callback");
    glfwSetWindowCloseCallback(window, window_close_callback);
    glfwMakeContextCurrent(window);
    
    printf("Initialize window color\n");
    writeLog(logFile, "Initialize window color");
    // Set background color (sky blue)
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);


    while (!glfwWindowShouldClose(window))
    {   
        // Render the frames
        render(window);
    
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    fclose(logFile);
    glfwDestroyWindow(window);
    return EXIT_SUCCESS;
}

// const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
// GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "My Title", glfwGetPrimaryMonitor(), NULL);
// GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", glfwGetPrimaryMonitor(), NULL);
