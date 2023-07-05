#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#define pi_val 3.14159265358979323846

float cubeSize = 1.0f;          // Size of the cube
float cubePositionX = 0.0f;     // X position of the cube
float cubePositionY = 0.0f;     // Y position of the cube
float cubePositionZ = -5.0f;    // Z position of the cube

bool keyHeldW = false;
bool keyHeldA = false;
bool keyHeldS = false;
bool keyHeldD = false;
bool keyHeldSpace = false;
bool keyHeldShift = false;

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

int exit_block(FILE* logFile, GLFWwindow* window) {
    fclose(logFile);
    glfwDestroyWindow(window);
    return EXIT_SUCCESS;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Adjust the cube position based on key presses
    float movementSpeed = 0.1f;
    
    if (key == GLFW_KEY_W)
    {
        if (action == GLFW_PRESS)
            keyHeldW = true;
        else if (action == GLFW_RELEASE)
            keyHeldW = false;
    }
    else if (key == GLFW_KEY_A)
    {
        if (action == GLFW_PRESS)
            keyHeldA = true;
        else if (action == GLFW_RELEASE)
            keyHeldA = false;
    }
    else if (key == GLFW_KEY_S)
    {
        if (action == GLFW_PRESS)
            keyHeldS = true;
        else if (action == GLFW_RELEASE)
            keyHeldS = false;
    }
    else if (key == GLFW_KEY_D)
    {
        if (action == GLFW_PRESS)
            keyHeldD = true;
        else if (action == GLFW_RELEASE)
            keyHeldD = false;
    }
    else if (key == GLFW_KEY_SPACE)
    {
        if (action == GLFW_PRESS)
            keyHeldSpace = true;
        else if (action == GLFW_RELEASE)
            keyHeldSpace = false;
    }
    else if (key == GLFW_KEY_LEFT_SHIFT)
    {
        if (action == GLFW_PRESS)
            keyHeldShift = true;
        else if (action == GLFW_RELEASE)
            keyHeldShift = false;
    }
    else if (key == GLFW_KEY_ESCAPE)
        exit(EXIT_SUCCESS);
}

void updateCubePosition(float deltaTime)
{
    float movementSpeed = 4.0f;
    
    if (keyHeldW)
        cubePositionZ += movementSpeed * deltaTime;
    if (keyHeldS)
        cubePositionZ -= movementSpeed * deltaTime;
    if (keyHeldD)
        cubePositionX -= movementSpeed * deltaTime;
    if (keyHeldA)
        cubePositionX += movementSpeed * deltaTime;
    if (keyHeldShift)
        cubePositionY += movementSpeed * deltaTime;
    if (keyHeldSpace)
        cubePositionY -= movementSpeed * deltaTime;
}

void render(GLFWwindow* window)
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    float aspectRatio = (float)width / (float)height;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
    
    // Set the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 0.0f,  // Camera position
              0.0f, 0.0f, -1.0f, // Target position
              0.0f, 1.0f, 0.0f); // Up vector
    
    // Translate the cube based on its position
    glTranslatef(cubePositionX, cubePositionY, cubePositionZ);
    
    // Render the cube
    glBegin(GL_QUADS);
    
    // Front face
    // glColor3f(1.0f, 0.0f, 0.0f); // Red

    // cube color
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-left
    glVertex3f(cubeSize, -cubeSize, cubeSize);   // Bottom-right
    glVertex3f(cubeSize, cubeSize, cubeSize);    // Top-right
    glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-left
    
    // Back face
    // glColor3f(0.0f, 1.0f, 0.0f); // Green
    // glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
    glVertex3f(cubeSize, -cubeSize, -cubeSize);  // Bottom-right
    glVertex3f(cubeSize, cubeSize, -cubeSize);   // Top-right
    glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
    // Left face
    // glColor3f(0.0f, 0.0f, 1.0f); // Blue
    //glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
    glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-right
    glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-right
    glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
    // Right face
    // glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    //glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(cubeSize, -cubeSize, -cubeSize); // Bottom-left
    glVertex3f(cubeSize, -cubeSize, cubeSize);  // Bottom-right
    glVertex3f(cubeSize, cubeSize, cubeSize);   // Top-right
    glVertex3f(cubeSize, cubeSize, -cubeSize);  // Top-left
    
    // Top face
    // glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    //glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-cubeSize, cubeSize, cubeSize);    // Bottom-left
    glVertex3f(cubeSize, cubeSize, cubeSize);     // Bottom-right
    glVertex3f(cubeSize, cubeSize, -cubeSize);    // Top-right
    glVertex3f(-cubeSize, cubeSize, -cubeSize);   // Top-left
    
    // Bottom face
    //glColor3f(0.0f, 1.0f, 1.0f); // Cyan 
    //glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-cubeSize, -cubeSize, cubeSize);   // Bottom-left
    glVertex3f(cubeSize, -cubeSize, cubeSize);    // Bottom-right
    glVertex3f(cubeSize, -cubeSize, -cubeSize);   // Top-right
    glVertex3f(-cubeSize, -cubeSize, -cubeSize);  // Top-left
    
    glEnd();
    
    glfwSwapBuffers(window);
}

int main()
{

    FILE* logFile = clean_and_open_log_file();
    writeLog(logFile, "🧊 Logs for Block, a minecraft clone 🧊");

    printf("Initializing glfw\n");
    writeLog(logFile, "Initializing GLFW");
    if (!glfwInit())
        return -1;
    
    printf("Creating window\n");
    writeLog(logFile, "Creating Window");
    GLFWwindow* window = glfwCreateWindow(800, 600, "Cube Movement", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
         
    glfwMakeContextCurrent(window);
    
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    
    // Set the key callback function
    glfwSetKeyCallback(window, keyCallback);

    printf("Initialize window color\n");
    writeLog(logFile, "Initialize window color");
    // Set background color (sky blue)
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    
    double previousTime = glfwGetTime();
    
    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        float deltaTime = (float)(currentTime - previousTime);
        
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        
        updateCubePosition(deltaTime);
        
        render(window);
        
        glfwPollEvents();
        
        previousTime = currentTime;
    }
    
    glfwTerminate();
    return exit_block(logFile, window);
}
