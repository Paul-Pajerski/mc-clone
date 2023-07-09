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

// This is the initial position of this test cube
// this places the cube infront of us when we start
float cubeSize = 0.6f;          // Size of the cube
float cubePositionX = 0.0f;     // X position of the cube
float cubePositionY = 0.0f;     // Y position of the cube
float cubePositionZ = 0.0f;    // Z position of the cube

// This is for the mouse variables
float lastMouseX = 0.0f;
float lastMouseY = 0.0f;
float cameraYaw = 0.0f;
float cameraPitch = 0.0f;

// Global camera variables
float initialCameraPositionX = 0.0f;
float initialCameraPositionY = 0.0f;
float initialCameraPositionZ = 0.0f;
float cameraPositionX = 0.0f;
float cameraPositionY = 0.0f;
float cameraPositionZ = 0.0f;
float cameraTargetX = 0.0f;
float cameraTargetY = 0.0f;
float cameraTargetZ = -1.0f;
float upX = 0.0f;
float upY = 1.0f; // Change to -1.0f to flip the orientation
float upZ = 0.0f;

bool isInitialCameraPositionSet = false;

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


void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
{   

    if (!isInitialCameraPositionSet)
    {
        // Set the initial camera position
        initialCameraPositionX = cameraPositionX;
        initialCameraPositionY = cameraPositionY;
        initialCameraPositionZ = cameraPositionZ;
        isInitialCameraPositionSet = true;
    }

    // Calculate the mouse movement
    float deltaX = xpos - lastMouseX;
    float deltaY = ypos - lastMouseY;

    // Update the last mouse position
    lastMouseX = xpos;
    lastMouseY = ypos;

    // Update the camera angles based on mouse movement
    const float sensitivity = 0.01f; // Adjust sensitivity here
    cameraYaw += deltaX * sensitivity;
    cameraPitch -= deltaY * sensitivity; // Invert the pitch calculation

    // Clamp the camera pitch to avoid flipping
    if (cameraPitch > 89.0f)
        cameraPitch = 89.0f;
    if (cameraPitch < -89.0f)
        cameraPitch = -89.0f;

    // Convert camera angles to radians
    float yawRadians = cameraYaw * 3.14159f / 180.0f;
    float pitchRadians = cameraPitch * 3.14159f / 180.0f;

    // Calculate the camera direction
    float dirX = cos(yawRadians) * cos(pitchRadians);
    float dirY = sin(pitchRadians);
    float dirZ = sin(yawRadians) * cos(pitchRadians);

    // Normalize the camera direction
    float length = sqrt(dirX * dirX + dirY * dirY + dirZ * dirZ);
    dirX /= length;
    dirY /= length;
    dirZ /= length;

    // The camera "snaps" when the mouse is first touched
    // Not currently sure how to address this but I suspect
    // that it's the calculations below for target x y and z
    // not smoothly occuring after the mouse is first touched

    // Calculate the camera target position based on initial camera position and direction
    float distance = 1.0f; // Adjust the distance from the initial camera position
    cameraTargetX = initialCameraPositionX + dirX * distance;
    cameraTargetY = initialCameraPositionY + dirY * distance;
    cameraTargetZ = initialCameraPositionZ + dirZ * distance;
}

// TODO, update this method to be "update camera position"
// since we don't want to be moving the cubes and instead
// moving the camera around the cubes. This is far more efficient
void updateCubePosition(float deltaTime)
{
    float movementSpeed = 4.0f;
    
    // This needs to be changed to move the cameras position
    // It's too costly to move every single cube every single time
    // the frame is rendered. Plus it's much easier to implement
    // camera based movement
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

// This method should eventually have parameters to
// color the cube correct and give it a correct design
// based on the cube. Eventually cubes should probably
// be objects if they need to contain data. If they don't
// they might be able to stay as just renders. And then
// for breaking the block, the breaking animation is layed
// over the face of the block the player is looking at.
// Raytracing will need to be implemented into this eventually
// in order to track which cube the player is looking at for placing
// and destroying
void create_cube()
{
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
    glColor3f(0.56f, 0.56f, 0.56f);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
    glVertex3f(cubeSize, -cubeSize, -cubeSize);  // Bottom-right
    glVertex3f(cubeSize, cubeSize, -cubeSize);   // Top-right
    glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
    // Left face
    // glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
    glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-right
    glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-right
    glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
    // Right face
    // glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(cubeSize, -cubeSize, -cubeSize); // Bottom-left
    glVertex3f(cubeSize, -cubeSize, cubeSize);  // Bottom-right
    glVertex3f(cubeSize, cubeSize, cubeSize);   // Top-right
    glVertex3f(cubeSize, cubeSize, -cubeSize);  // Top-left
    
    // Top face
    // glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-cubeSize, cubeSize, cubeSize);    // Bottom-left
    glVertex3f(cubeSize, cubeSize, cubeSize);     // Bottom-right
    glVertex3f(cubeSize, cubeSize, -cubeSize);    // Top-right
    glVertex3f(-cubeSize, cubeSize, -cubeSize);   // Top-left
    
    // Bottom face
    //glColor3f(0.0f, 1.0f, 1.0f); // Cyan 
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-cubeSize, -cubeSize, cubeSize);   // Bottom-left
    glVertex3f(cubeSize, -cubeSize, cubeSize);    // Bottom-right
    glVertex3f(cubeSize, -cubeSize, -cubeSize);   // Top-right
    glVertex3f(-cubeSize, -cubeSize, -cubeSize);  // Top-left
    
    glEnd();
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
    gluLookAt(cameraPositionX, cameraPositionY, cameraPositionZ,
              cameraTargetX, cameraTargetY, cameraTargetZ,
              upX, upY, upZ);

    // printf("%d %d %d\n", cameraTargetX, cameraTargetY, cameraTargetZ);
    
    // Translate the cube based on its position
    // This should probably be removed and changed to update the 
    // Camera (via glu look at). I believe the way to do this
    // is by mapping cubePositionX, cubePositionY, cubePositionZ >> cameraPositionX, cameraPositionY, cameraPositionZ 
    // where instead of editing the cubes position as done below
    // you edit the cameras position. This would allow for dynamic movement
    // in the mouses direction
    glTranslatef(cubePositionX, cubePositionY, cubePositionZ);
    
    // This should eventually be expanded on to render multiple cubes
    // Use 3d space and cube offset to do this. Iterate through the cubes
    // and generate them. Right now we won't worry about optimizations like
    // cube meshes and just make sure we can get cubes generating without too much overhead
    create_cube();    
    glfwSwapBuffers(window);
}

void initialize_context_and_callbacks(GLFWwindow* window)
{
    // Set current context to the window
    glfwMakeContextCurrent(window);
    
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    
    // Set the key callback function
    glfwSetKeyCallback(window, keyCallback);

    // Set the mouse movement callback function
    glfwSetCursorPosCallback(window, mouseMoveCallback);
    
    // Use Cursor and hide it
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
    
    initialize_context_and_callbacks(window);
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
