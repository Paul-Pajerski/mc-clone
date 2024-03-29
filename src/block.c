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

// Width, height and aspect ratio of the window
int width, height;
float aspectRatio = 0.0f;

// Camera variables
float cameraYaw = 0.0f;   // Yaw angle of the camera
float cameraPitch = 0.0f; // Pitch angle of the camera
float cameraDistance = 10.0f; // Distance of the camera from the cube
float lastMouseX = 0.0f; // Mouse position X
float lastMouseY = 0.0f; // Mouse position Y
float yawRadians = 0.0f; // Yaw in rads for the mouse pos
float pitchRadians = 0.0f; // Pitch in rads for the mouse pos
float mouseDeltaX; // Difference between the mouse position and the Xpos
float mouseDeltaY; // Difference between the mouse position and the Ypos
float cameraDirX = 0.0f; // Camera direction X
float cameraDirY = 0.0f; // Camera direction Y
float cameraDirZ = 0.0f; // Camera direction Z
float cameraLength = 0.0f; // Camera length from target, normalized
float forwardX = 0.0f; // Normalized forward X vector for target
float forwardY = 0.0f; // Normalized forward Y vector for target
float forwardZ = 0.0f; // Normalized forward Z vector for target
float forwardLength = 0.0f; // Camera forward length
float sensitivity = 0.008f; // Camera angle sensitivity
float currentCameraPositionX = -5.0f; // Current X coord for camera
float currentCameraPositionY = 0.0f; // Current Y coord for camera
float currentCameraPositionZ = 0.0f; // Current Z coord for camera

// Glu Look At vars
float upX = 0.0f; // X up vector
float upY = 1.0f; // Change to -1.0f to flip the orientation (default is Y)
float upZ = 0.0f; // X up vector

// Movement key vars
float movementSpeed = 0.004f; // Ingame movement speed

// Various booleans for what keys are being held down
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
    // Calculate the mouse movement
    mouseDeltaX = xpos - lastMouseX;
    mouseDeltaY= ypos - lastMouseY;

    // Update the last mouse position
    lastMouseX = xpos;
    lastMouseY = ypos;

    // Update the camera angles based on mouse movement
    cameraYaw += mouseDeltaX * sensitivity;
    cameraPitch -= mouseDeltaY * sensitivity; // Invert the pitch calculation

    // Clamp the camera pitch to avoid flipping
    if (cameraPitch > 89.0f)
        cameraPitch = 89.0f;
    if (cameraPitch < -89.0f)
        cameraPitch = -89.0f;

    // Convert camera angles to radians
    yawRadians = cameraYaw * pi_val / 180.0f;
    pitchRadians = cameraPitch * pi_val / 180.0f;

    // Calculate the camera direction
    cameraDirX = cos(yawRadians) * cos(pitchRadians);
    cameraDirY = sin(pitchRadians);
    cameraDirZ = sin(yawRadians) * cos(pitchRadians);

    // Normalize the camera direction
    cameraLength = sqrt(cameraDirX * cameraDirX + cameraDirY * cameraDirY + cameraDirZ * cameraDirZ);
    cameraDirX /= cameraLength;
    cameraDirY /= cameraLength;
    cameraDirZ /= cameraLength;
}

void updateCameraPosition()
{
    // Calculate the camera's forward vector
    forwardX = cameraDirX;
    forwardY = 0.0f;
    forwardZ = cameraDirZ;

    // Normalize the forward vector
    forwardLength = sqrt(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);
    forwardX /= forwardLength;
    forwardY /= forwardLength;
    forwardZ /= forwardLength;
    
    // Update camera position based on key inputs
    if (keyHeldW) {
        currentCameraPositionX += forwardX * movementSpeed;
        currentCameraPositionZ += forwardZ * movementSpeed;
    }

    if (keyHeldS) {
        currentCameraPositionX -= forwardX * movementSpeed;
        currentCameraPositionZ -= forwardZ * movementSpeed;
    }

    if (keyHeldA) {
        currentCameraPositionX += forwardZ * movementSpeed;
        currentCameraPositionZ -= forwardX * movementSpeed;
    }

    if (keyHeldD) {
        currentCameraPositionX -= forwardZ * movementSpeed;
        currentCameraPositionZ += forwardX * movementSpeed;
    }

    if (keyHeldSpace)
        currentCameraPositionY += movementSpeed;
    if (keyHeldShift)
        currentCameraPositionY -= movementSpeed;
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
    aspectRatio = (float)width / (float)height;
    // The aspect ratio shouldn't be calculated in the render loop
    // instead only calcuate at the start of the game
    // and only update it when the user changes the window size

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
    
    // Set the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    updateCameraPosition();

    gluLookAt(currentCameraPositionX, currentCameraPositionY, currentCameraPositionZ,
             currentCameraPositionX + cameraDirX, currentCameraPositionY + cameraDirY, currentCameraPositionZ + cameraDirZ,
            upX, upY, upZ);

    
    // Translate the cube based on its position
    // This should probably be removed and changed to update the 
    // Camera (via glu look at). I believe the way to do this
    // is by mapping cubePositionX, cubePositionY, cubePositionZ >> cameraPositionX, cameraPositionY, cameraPositionZ 
    // where instead of editing the cubes position as done below
    // you edit the cameras position. This would allow for dynamic movement
    // in the mouses direction
    // glTranslatef(cubePositionX, cubePositionY, cubePositionZ);
    
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

    // Set background color (sky blue)
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);

    // This call is necessary to prevent the mouse from snapping
    // the first time a movement is made. It's technically a hack
    // but I could not find a better way to do this since editing
    // the starting coordinates of the camera view seemed to ruin
    // everything
    mouseMoveCallback(window, 0.0f, 0.0f);
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
    GLFWwindow* window = glfwCreateWindow(1200, 800, "Cube Movement", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    initialize_context_and_callbacks(window);
    printf("Initialize window color\n");
    writeLog(logFile, "Initialize window color");
    
    while (!glfwWindowShouldClose(window))
    {
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        render(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return exit_block(logFile, window);
}
