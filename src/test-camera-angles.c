// Some code working on getting camera angles correct

// void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
// {
//     // Calculate the mouse movement
//     float deltaX = xpos - lastMouseX;
//     float deltaY = ypos - lastMouseY;

//     // Update the last mouse position
//     lastMouseX = xpos;
//     lastMouseY = ypos;

//     // Update the camera angles based on mouse movement
//     const float sensitivity = 0.01f; // Adjust sensitivity here
//     cameraYaw += deltaX * sensitivity;
//     cameraPitch -= deltaY * sensitivity; // Invert the pitch calculation

//     // Clamp the camera pitch to avoid flipping
//     if (cameraPitch > 89.0f)
//         cameraPitch = 89.0f;
//     if (cameraPitch < -89.0f)
//         cameraPitch = -89.0f;

//     // Convert camera angles to radians
//     float yawRadians = cameraYaw * 3.14159f / 180.0f;
//     float pitchRadians = cameraPitch * 3.14159f / 180.0f;

//     // Calculate the camera direction
//     float dirX = cos(yawRadians) * cos(pitchRadians);
//     float dirY = sin(pitchRadians);
//     float dirZ = sin(yawRadians) * cos(pitchRadians);

//     // Normalize the camera direction
//     float length = sqrt(dirX * dirX + dirY * dirY + dirZ * dirZ);
//     dirX /= length;
//     dirY /= length;
//     dirZ /= length;

//     // Calculate the camera target position based on initial camera position and direction
//     cameraTargetX = initialCameraPositionX + dirX;
//     cameraTargetY = initialCameraPositionY + dirY;
//     cameraTargetZ = initialCameraPositionZ + dirZ;
// }

// // Camera variables
// float cameraYaw = 0.0f;   // Yaw angle of the camera
// float cameraPitch = 0.0f; // Pitch angle of the camera
// float cameraDistance = 5.0f; // Distance of the camera from the cube

// // Cube variables
// float cubeSize = 1.0f;
// float cubePositionX = 0.0f;
// float cubePositionY = 0.0f;
// float cubePositionZ = 0.0f;

// // Mouse variables
// float lastMouseX = 0.0f;
// float lastMouseY = 0.0f;
// bool firstMouse = true;

// bool keyHeldW = false;
// bool keyHeldA = false;
// bool keyHeldS = false;
// bool keyHeldD = false;
// bool keyHeldSpace = false;
// bool keyHeldShift = false;

// void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
// {
//     // Calculate the mouse movement
//     float deltaX = xpos - lastMouseX;
//     float deltaY = ypos - lastMouseY;
    
//     // Update the last mouse position
//     lastMouseX = xpos;
//     lastMouseY = ypos;
    
//     // Update the camera angles based on mouse movement
//     const float sensitivity = 0.1f;
//     cameraYaw += deltaX * sensitivity;
//     cameraPitch += deltaY * sensitivity;
    
//     // Clamp the camera pitch to avoid flipping
//     if (cameraPitch > 89.0f)
//         cameraPitch = 89.0f;
//     if (cameraPitch < -89.0f)
//         cameraPitch = -89.0f;
// }

// void updateCubePosition(float deltaTime)
// {
//     float movementSpeed = 4.0f;
    
//     if (keyHeldW)
//         cubePositionZ += movementSpeed * deltaTime;
//     if (keyHeldS)
//         cubePositionZ -= movementSpeed * deltaTime;
//     if (keyHeldD)
//         cubePositionX -= movementSpeed * deltaTime;
//     if (keyHeldA)
//         cubePositionX += movementSpeed * deltaTime;
//     if (keyHeldShift)
//         cubePositionY += movementSpeed * deltaTime;
//     if (keyHeldSpace)
//         cubePositionY -= movementSpeed * deltaTime;
// }


// void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     // Adjust the cube position based on key presses
//     float movementSpeed = 0.1f;
    
//     if (key == GLFW_KEY_W)
//     {
//         if (action == GLFW_PRESS)
//             keyHeldW = true;
//         else if (action == GLFW_RELEASE)
//             keyHeldW = false;
//     }
//     else if (key == GLFW_KEY_A)
//     {
//         if (action == GLFW_PRESS)
//             keyHeldA = true;
//         else if (action == GLFW_RELEASE)
//             keyHeldA = false;
//     }
//     else if (key == GLFW_KEY_S)
//     {
//         if (action == GLFW_PRESS)
//             keyHeldS = true;
//         else if (action == GLFW_RELEASE)
//             keyHeldS = false;
//     }
//     else if (key == GLFW_KEY_D)
//     {
//         if (action == GLFW_PRESS)
//             keyHeldD = true;
//         else if (action == GLFW_RELEASE)
//             keyHeldD = false;
//     }
//     else if (key == GLFW_KEY_SPACE)
//     {
//         if (action == GLFW_PRESS)
//             keyHeldSpace = true;
//         else if (action == GLFW_RELEASE)
//             keyHeldSpace = false;
//     }
//     else if (key == GLFW_KEY_LEFT_SHIFT)
//     {
//         if (action == GLFW_PRESS)
//             keyHeldShift = true;
//         else if (action == GLFW_RELEASE)
//             keyHeldShift = false;
//     }
//     else if (key == GLFW_KEY_ESCAPE)
//         exit(1);
// }


// // void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
// // {
// //     // Adjust the cube position based on key presses
// //     float movementSpeed = 0.1f;
    
// //     if (key == GLFW_KEY_W && action == GLFW_PRESS)
// //         cubePositionZ -= movementSpeed;
// //     else if (key == GLFW_KEY_S && action == GLFW_PRESS)
// //         cubePositionZ += movementSpeed;
// //     else if (key == GLFW_KEY_D && action == GLFW_PRESS)
// //         cubePositionX += movementSpeed;
// //     else if (key == GLFW_KEY_A && action == GLFW_PRESS)
// //         cubePositionX -= movementSpeed;
// //     else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
// //         cubePositionY += movementSpeed;
// //     else if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS)
// //         cubePositionY -= movementSpeed;
// //     else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
// //        exit(1);
// // }

// void render(GLFWwindow* window)
// {
//     int width, height;
//     glfwGetFramebufferSize(window, &width, &height);
//     float aspectRatio = (float)width / (float)height;
    
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
//     // Set up the projection matrix
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
    
//     // Set the modelview matrix
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
    
//     // Apply camera transformations
//     gluLookAt(0.0f, 0.0f, 0.0f,
//               sinf(cameraYaw * (float)pi_val / 180.0f) * cosf(cameraPitch * (float)pi_val / 180.0f) * cameraDistance,
//               sinf(cameraPitch * (float)pi_val / 180.0f) * cameraDistance,
//               cosf(cameraYaw * (float)pi_val / 180.0f) * cosf(cameraPitch * (float)pi_val / 180.0f) * cameraDistance,
//               0.0f, 1.0f, 0.0f);
    
//     // Translate the cube based on its position
//     glTranslatef(cubePositionX, cubePositionY, cubePositionZ);
    
//     // Render the cube
//     glBegin(GL_QUADS);
    
//     // Front face
//     glColor3f(1.0f, 0.0f, 0.0f); // Red
//     glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, cubeSize);   // Bottom-right
//     glVertex3f(cubeSize, cubeSize, cubeSize);    // Top-right
//     glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-left
    
//     // Back face
//     glColor3f(0.0f, 1.0f, 0.0f); // Green
//     glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, -cubeSize);  // Bottom-right
//     glVertex3f(cubeSize, cubeSize, -cubeSize);   // Top-right
//     glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
//     // Left face
//     glColor3f(0.0f, 0.0f, 1.0f); // Blue
//     glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
//     glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-right
//     glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-right
//     glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
//     // Right face
//     glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//     glVertex3f(cubeSize, -cubeSize, -cubeSize); // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, cubeSize);  // Bottom-right
//     glVertex3f(cubeSize, cubeSize, cubeSize);   // Top-right
//     glVertex3f(cubeSize, cubeSize, -cubeSize);  // Top-left
    
//     // Top face
//     glColor3f(1.0f, 0.0f, 1.0f); // Magenta
//     glVertex3f(-cubeSize, cubeSize, cubeSize);    // Bottom-left
//     glVertex3f(cubeSize, cubeSize, cubeSize);     // Bottom-right
//     glVertex3f(cubeSize, cubeSize, -cubeSize);    // Top-right
//     glVertex3f(-cubeSize, cubeSize, -cubeSize);   // Top-left
    
//     // Bottom face
//     glColor3f(0.0f, 1.0f, 1.0f); // Cyan
//     glVertex3f(-cubeSize, -cubeSize, cubeSize);   // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, cubeSize);    // Bottom-right
//     glVertex3f(cubeSize, -cubeSize, -cubeSize);   // Top-right
//     glVertex3f(-cubeSize, -cubeSize, -cubeSize);  // Top-left
    
//     glEnd();
    
//     glfwSwapBuffers(window);
// }

// int main()
// {
//     // Initialize GLFW and create a window
//     if (!glfwInit())
//         return -1;
    
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Cube Movement", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
    
//     glfwMakeContextCurrent(window);
    
//     // Enable depth testing
//     glEnable(GL_DEPTH_TEST);
    
//     // Set the key callback function
//     glfwSetKeyCallback(window, keyCallback);
    
//     // Set the mouse movement callback function
//     glfwSetCursorPosCallback(window, mouseMoveCallback);
    
//     // Hide the cursor and capture its movement
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//     double previousTime = glfwGetTime();
//     while (!glfwWindowShouldClose(window))
//     {
//         double currentTime = glfwGetTime();
//         float deltaTime = (float)(currentTime - previousTime);
        
// //         int width, height;
// //         glfwGetFramebufferSize(window, &width, &height);
// //         glViewport(0, 0, width, height);
        
//         updateCubePosition(deltaTime);
//         int width, height;
//         glfwGetFramebufferSize(window, &width, &height);
//         glViewport(0, 0, width, height);
        
//         render(window);
        
//         glfwPollEvents();
//     }
    
//     glfwTerminate();
    
//     return 0;
// }




// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdbool.h>
// #include <GLFW/glfw3.h>
// #include "controls.h"
// #include <GL/GL.h>
// #include <GL/glut.h>
// #include<GL/gl.h>

// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GLFW/glfw3.h>

// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GLFW/glfw3.h>

// float cubeSize = 1.0f;          // Size of the cube
// float cubePositionX = 0.0f;     // X position of the cube
// float cubePositionY = 0.0f;     // Y position of the cube
// float cubePositionZ = -5.0f;    // Z position of the cube

// void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     // Adjust the cube position based on key presses
//     float movementSpeed = 0.1f;
    
//     if (key == GLFW_KEY_W && action == GLFW_PRESS)
//         cubePositionZ += movementSpeed;
//     else if (key == GLFW_KEY_S && action == GLFW_PRESS)
//         cubePositionZ -= movementSpeed;
//     else if (key == GLFW_KEY_D && action == GLFW_PRESS)
//         cubePositionX -= movementSpeed;
//     else if (key == GLFW_KEY_A && action == GLFW_PRESS)
//         cubePositionX += movementSpeed;
//     else if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS)
//         cubePositionY += movementSpeed;
//     else if (key == GLFW_KEY_SPACE  && action == GLFW_PRESS)
//         cubePositionY -= movementSpeed;
// }

// void render(GLFWwindow* window)
// {
//     int width, height;
//     glfwGetFramebufferSize(window, &width, &height);
//     float aspectRatio = (float)width / (float)height;
    
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
//     // Set up the projection matrix
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
    
//     // Set the modelview matrix
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
//     gluLookAt(0.0f, 0.0f, 0.0f,  // Camera position
//               0.0f, 0.0f, -1.0f, // Target position
//               0.0f, 1.0f, 0.0f); // Up vector
    
//     // Translate the cube based on its position
//     glTranslatef(cubePositionX, cubePositionY, cubePositionZ);
    
//     // Render the cube
//     glBegin(GL_QUADS);
    
//     // Front face
//     glColor3f(1.0f, 0.0f, 0.0f); // Red
//     glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, cubeSize);   // Bottom-right
//     glVertex3f(cubeSize, cubeSize, cubeSize);    // Top-right
//     glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-left
    
//     // Back face
//     glColor3f(0.0f, 1.0f, 0.0f); // Green
//     glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, -cubeSize);  // Bottom-right
//     glVertex3f(cubeSize, cubeSize, -cubeSize);   // Top-right
//     glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
//     // Left face
//     glColor3f(0.0f, 0.0f, 1.0f); // Blue
//     glVertex3f(-cubeSize, -cubeSize, -cubeSize); // Bottom-left
//     glVertex3f(-cubeSize, -cubeSize, cubeSize);  // Bottom-right
//     glVertex3f(-cubeSize, cubeSize, cubeSize);   // Top-right
//     glVertex3f(-cubeSize, cubeSize, -cubeSize);  // Top-left
    
//     // Right face
//     glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//     glVertex3f(cubeSize, -cubeSize, -cubeSize); // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, cubeSize);  // Bottom-right
//     glVertex3f(cubeSize, cubeSize, cubeSize);   // Top-right
//     glVertex3f(cubeSize, cubeSize, -cubeSize);  // Top-left
    
//     // Top face
//     glColor3f(1.0f, 0.0f, 1.0f); // Magenta
//     glVertex3f(-cubeSize, cubeSize, cubeSize);    // Bottom-left
//     glVertex3f(cubeSize, cubeSize, cubeSize);     // Bottom-right
//     glVertex3f(cubeSize, cubeSize, -cubeSize);    // Top-right
//     glVertex3f(-cubeSize, cubeSize, -cubeSize);   // Top-left
    
//     // Bottom face
//     glColor3f(0.0f, 1.0f, 1.0f); // Cyan
//     glVertex3f(-cubeSize, -cubeSize, cubeSize);   // Bottom-left
//     glVertex3f(cubeSize, -cubeSize, cubeSize);    // Bottom-right
//     glVertex3f(cubeSize, -cubeSize, -cubeSize);   // Top-right
//     glVertex3f(-cubeSize, -cubeSize, -cubeSize);  // Top-left
    
//     glEnd();
    
//     glfwSwapBuffers(window);
// }

// int main()
// {
//     // Initialize GLFW and create a window
//     if (!glfwInit())
//         return -1;
    
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Cube Movement", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
    
//     glfwMakeContextCurrent(window);
    
//     // Enable depth testing
//     glEnable(GL_DEPTH_TEST);
    
//     // Set the key callback function
//     glfwSetKeyCallback(window, keyCallback);
    
//     while (!glfwWindowShouldClose(window))
//     {
//         int width, height;
//         glfwGetFramebufferSize(window, &width, &height);
//         glViewport(0, 0, width, height);
        
//         render(window);
        
//         glfwPollEvents();
//     }
    
//     glfwTerminate();
    
//     return 0;
// }


// float angle = 0.0f;         // Angle of rotation
// float rotationSpeed = 0.1f; // Speed of rotation

// void render(GLFWwindow* window)
// {
//     int width, height;
//     glfwGetFramebufferSize(window, &width, &height);
//     float aspectRatio = (float)width / (float)height;
    
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
//     // Set up the projection matrix
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(75.0f, aspectRatio, 0.1f, 100.0f);
    
//     // Set the modelview matrix
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
//     gluLookAt(0.0f, 0.0f, 5.0f,  // Camera position
//               0.0f, 0.0f, 0.0f,  // Target position
//               0.0f, 1.0f, 0.0f); // Up vector
    
//     // Rotate the cube
//     glRotatef(angle, 10.0f, 15.0f, 20.0f);
    
//     // Render the cube
//     glBegin(GL_QUADS);
    
//     // Front face
//     glColor3f(1.0f, 0.0f, 0.0f); // Red
//     glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left
//     glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom-right
//     glVertex3f(1.0f, 1.0f, 1.0f);   // Top-right
//     glVertex3f(-1.0f, 1.0f, 1.0f);  // Top-left
    
//     // Back face
//     glColor3f(0.0f, 1.0f, 0.0f); // Green
//     glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
//     glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom-right
//     glVertex3f(1.0f, 1.0f, -1.0f);   // Top-right
//     glVertex3f(-1.0f, 1.0f, -1.0f);  // Top-left
    
//     // Left face
//     glColor3f(0.0f, 0.0f, 1.0f); // Blue
//     glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-left
//     glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom-right
//     glVertex3f(-1.0f, 1.0f, 1.0f);   // Top-right
//     glVertex3f(-1.0f, 1.0f, -1.0f);  // Top-left
    
//     // Right face
//     glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//     glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-left
//     glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom-right
//     glVertex3f(1.0f, 1.0f, 1.0f);   // Top-right
//     glVertex3f(1.0f, 1.0f, -1.0f);  // Top-left
    
//     // Top face
//     glColor3f(1.0f, 0.0f, 1.0f); // Magenta
//     glVertex3f(-1.0f, 1.0f, 1.0f);   // Bottom-left
//     glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom-right
//     glVertex3f(1.0f, 1.0f, -1.0f);   // Top-right
//     glVertex3f(-1.0f, 1.0f, -1.0f);  // Top-left
    
//     // Bottom face
//     glColor3f(0.0f, 1.0f, 1.0f); // Cyan
//     glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom-left
//     glVertex3f(1.0f, -1.0f, 1.0f);   // Bottom-right
//     glVertex3f(1.0f, -1.0f, -1.0f);  // Top-right
//     glVertex3f(-1.0f, -1.0f, -1.0f); // Top-left
    
//     glEnd();
    
//     // Increase the rotation angle for the next frame
//     // angle += rotationSpeed;
    
//     glfwSwapBuffers(window);
// }

// int main()
// {
//     // Initialize GLFW and create a window
//     if (!glfwInit())
//         return -1;
    
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Cube Rotation", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
    
//     glfwMakeContextCurrent(window);
    
//     // Enable depth testing
//     glEnable(GL_DEPTH_TEST);
    
//     while (!glfwWindowShouldClose(window))
//     {
//         int width, height;
//         glfwGetFramebufferSize(window, &width, &height);
//         glViewport(0, 0, width, height);
        
//         render(window);
        
//         glfwPollEvents();
//     }
    
//     glfwTerminate();
    
//     return 0;
// }



// gcc block.c -o block $(pkg-config --cflags --libs gtk+-3.0)

// bool time_to_close = true;
// int width, height;
// int scalarX, scalarY;
// int squareX = 100;
// int squareY = 100;
// int keyPressed = -1;

// FILE* clean_and_open_log_file() {
//     FILE* file = fopen("logs.txt", "w");
//     if (file != NULL) {
//         fclose(file);
//         file = fopen("logs.txt", "a");
//     }
//     return file;
// }

// void writeLog(FILE* file, const char* message) {
//     if (file != NULL) {
//         fprintf(file, "%s\n", message);
//         fflush(file);
//     }
// }

// void window_close_callback(GLFWwindow* window)
// {
//     if (!time_to_close)
//         glfwSetWindowShouldClose(window, GLFW_FALSE);
// }

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (action == GLFW_PRESS)
//     {   
//         keyPressed = key;

//         // W = 87
//         // A = 65
//         // S = 83
//         // D = 68
//         // spacebar = 32
//         // shift = 340
//         // Escape = 256
//     }
//     else if (action == GLFW_RELEASE)
//     {
//         // printf("Key released: ");
//         // print_key(key);
//         keyPressed = -1;
//     }
// }

// void movement(int key) {
//     scalarY = 0;
//     scalarX = 0;
//     if (key == 87) {
//         // printf("%s", "Move Forward");
//         scalarY+=1;
//     }

//     if (key == 83) {
//         // printf("%s", "Move Backwards");
//         scalarY-=1;
//     }

//     if (key == 65) {
//         // printf("%s", "Move Left");
//         scalarX-=1;
//     }

//     if (key == 68) {
//         // printf("%s", "Move Right");
//         scalarX+=1;
//     }

//     if (key == 32) {
//         printf("%s", "Spacebar");
//     }

//     if (key == 340) {
//         printf("%s", "Shift");
//     }

//     if (key == 256) {
//         printf("%s", "Escape key");
//     }
// }
//     // printf("X %d and Y %d \n", scalarX, scalarY);

// void render(GLFWwindow* window)
// {      
//     glClear(GL_COLOR_BUFFER_BIT);
    
//     // Perform additional rendering here...
//     // Set up an orthographic projection matrix to match the window dimensions
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(0, width, 0, height, -1, 1);
    
//     // Set the modelview matrix as the identity matrix
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
    
//     // Calculate the center position of the square
//     float squareSize = 100.0f; // Adjust this value as desired
//     float squareHalfSize = squareSize / 2.0f;
//     // float squareX = (width - squareSize) / 2.0f;
//     // float squareY = (height - squareSize) / 2.0f;

//     // 1080, 600
//     if (squareX >= 1080 && squareX <= 0);
//         squareX += scalarX;
    
//     if (squareY <= height);
//         squareY += scalarY;
    
//     // Render the square
//     glBegin(GL_QUADS);
//     glColor3f(0.5f, 0.5f, 0.5f); // Set the color of the square (grey in this case)

//     glVertex2f(squareX, squareY);
//     glVertex2f(squareX + squareSize, squareY);
//     glVertex2f(squareX + squareSize, squareY + squareSize);
//     glVertex2f(squareX, squareY + squareSize);
//     glEnd();
//     // printf("%d %d", squareX, squareY);

//     scalarX = 0;
//     scalarY = 0;


// }

// int main(int argc, char *argv[])
// {
//     FILE* logFile = clean_and_open_log_file();
//     writeLog(logFile, "🧊 Logs for Block, a minecraft clone 🧊");

//     printf("Initializing glfw\n");
//     writeLog(logFile, "Initializing GLFW");
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     printf("Creating window\n");
//     writeLog(logFile, "Creating Window");
//     GLFWwindow* window = glfwCreateWindow(1080, 600, "Block", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     printf("Setting window callback\n");
//     writeLog(logFile, "Setting Window Callback");
//     // Set window close callback
//     glfwSetWindowCloseCallback(window, window_close_callback);

//     // Set up key callback
//     glfwSetKeyCallback(window, key_callback);
//     glfwMakeContextCurrent(window);
    
//     printf("Initialize window color\n");
//     writeLog(logFile, "Initialize window color");
//     // Set background color (sky blue)
//     glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    
//     glfwGetFramebufferSize(window, &width, &height);
//     glViewport(0, 0, width, height);



//     while (!glfwWindowShouldClose(window))
//     {   
//         // Render the frames

//         // if (keyPressed != -1)
//         // {
//         //     print_key(keyPressed);
//         //     // printf("You are holding down key: %d\n", keyPressed);
//         // }
//         movement(keyPressed);
//         render(window);
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     fclose(logFile);
//     glfwDestroyWindow(window);
//     return EXIT_SUCCESS;
// }








// // const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
// // GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "My Title", glfwGetPrimaryMonitor(), NULL);
// // GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", glfwGetPrimaryMonitor(), NULL);


// #include <windows.h> 
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>
// #include <GLFW/glfw3.h>
// #include <GL/GL.h>
// #include <GL/glut.h>
// #include<GL/gl.h>


// bool time_to_close = true;
// int width, height;
// float cubeZ = -5.0f;
// float cubeX = -5.0f;
// float cameraY = 0.0f;
// int keyPressed = -1;

// void window_close_callback(GLFWwindow* window)
// {
//     if (!time_to_close)
//         glfwSetWindowShouldClose(window, GLFW_FALSE);
// }

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (action == GLFW_PRESS)
//     {
//         keyPressed = key;
//     }
//     else if (action == GLFW_RELEASE)
//     {
//         keyPressed = -1;
//     }
// }

// void movement(int key)
// {
//     if (key == GLFW_KEY_W)
//     {
//         cubeZ += 0.1f;
//     }

//     if (key == GLFW_KEY_S)
//     {
//         cubeZ -= 0.1f;
//     }

//     if (key == GLFW_KEY_A)
//     {
//         cubeX -= 0.1f;
//     }

//     if (key == GLFW_KEY_D)
//     {
//         cubeX += 0.1f;
//     }

//     if (key == GLFW_KEY_SPACE)
//     {
//         cameraY += 0.1f;
//     }

//     if (key == GLFW_KEY_LEFT_SHIFT)
//     {
//         cameraY -= 0.1f;
//     }
// }

// void render(GLFWwindow* window)
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, -10.0, 10.0);

//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
//     gluLookAt(0.0f, cameraY, 0.0f, 0.0f, cameraY, -1.0f, 0.0f, 1.0f, 0.0f);

//     glTranslatef(0.0f, 0.0f, cubeZ);

//     // Render the cube
//     glBegin(GL_QUADS);
//     // Front face
//     glColor3f(1.0f, 0.0f, 0.0f);
//     glVertex3f(-0.5f, -0.5f, 0.5f);
//     glVertex3f(0.5f, -0.5f, 0.5f);
//     glVertex3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, 0.5f);
//     // Back face
//     glColor3f(0.0f, 1.0f, 0.0f);
//     glVertex3f(-0.5f, -0.5f, -0.5f);
//     glVertex3f(-0.5f, 0.5f, -0.5f);
//     glVertex3f(0.5f, 0.5f, -0.5f);
//     glVertex3f(0.5f, -0.5f, -0.5f);
//     // Left face
//     glColor3f(0.0f, 0.0f, 1.0f);
//     glVertex3f(-0.5f, -0.5f, -0.5f);
//     glVertex3f(-0.5f, -0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, -0.5f);
//     // Right face
//     glColor3f(1.0f, 1.0f, 0.0f);
//     glVertex3f(0.5f, -0.5f, -0.5f);
//     glVertex3f(0.5f, 0.5f, -0.5f);
//     glVertex3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, -0.5f, 0.5f);
//     // Top face
//     glColor3f(0.0f, 1.0f, 1.0f);
//     glVertex3f(-0.5f, 0.5f, -0.5f);
//     glVertex3f(-0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, 0.5f, -0.5f);
//     // Bottom face
//     glColor3f(1.0f, 0.0f, 1.0f);
//     glVertex3f(-0.5f, -0.5f, -0.5f);
//     glVertex3f(0.5f, -0.5f, -0.5f);
//     glVertex3f(0.5f, -0.5f, 0.5f);
//     glVertex3f(-0.5f, -0.5f, 0.5f);
//     glEnd();
// }

// int main(int argc, char* argv[])
// {
//     printf("Initializing GLFW\n");
//     if (!glfwInit())
//     {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     printf("Creating window\n");
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Block", NULL, NULL);
//     if (!window)
//     {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     printf("Setting window callback\n");
//     glfwSetWindowCloseCallback(window, window_close_callback);

//     glfwSetKeyCallback(window, key_callback);
//     glfwMakeContextCurrent(window);

//     printf("Initialize OpenGL\n");
//     glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
//     glEnable(GL_DEPTH_TEST);

//     glfwGetFramebufferSize(window, &width, &height);
//     glViewport(0, 0, width, height);

//     while (!glfwWindowShouldClose(window))
//     {
//         movement(keyPressed);
//         render(window);

//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return EXIT_SUCCESS;
// }

// #include <windows.h> 
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>
// #include <GLFW/glfw3.h>
// // #include <GL/GL.h>
// // #include <GL/glut.h>
// // #include<GL/gl.h>

// #include <GL/gl.h>
// #include <GL/GLU.h>
// #include <GL/glut.h>

// bool time_to_close = true;
// int width, height;
// float cubeX = 0.0f;
// float cubeY = 0.0f;
// float cubeZ = -5.0f;
// float cameraX = 0.0f;
// float cameraY = 0.0f;
// float cameraZ = 0.0f;
// int keyPressed = -1;

// void window_close_callback(GLFWwindow* window)
// {
//     if (!time_to_close)
//         glfwSetWindowShouldClose(window, GLFW_FALSE);
// }

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     if (action == GLFW_PRESS)
//     {
//         keyPressed = key;
//     }
//     else if (action == GLFW_RELEASE)
//     {
//         keyPressed = -1;
//     }
// }

// void movement(int key)
// {
//     if (key == GLFW_KEY_W)
//     {
//         cubeZ += 0.1f;
//     }

//     if (key == GLFW_KEY_S)
//     {
//         cubeZ -= 0.1f;
//     }

//     if (key == GLFW_KEY_A)
//     {
//         cubeX -= 0.1f;
//     }

//     if (key == GLFW_KEY_D)
//     {
//         cubeX += 0.1f;
//     }

//     if (key == GLFW_KEY_SPACE)
//     {
//         cameraY += 0.1f;
//     }

//     if (key == GLFW_KEY_LEFT_SHIFT)
//     {
//         cameraY -= 0.1f;
//     }
// }

// void render(GLFWwindow* window)
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, -10.0, 10.0);

//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
//     gluLookAt(cameraX, cameraY, cameraZ, cameraX, cameraY, cameraZ - 1.0f, 0.0f, 1.0f, 0.0f);

//     glTranslatef(cubeX, cubeY, cubeZ);

//     // Render the cube
//     glBegin(GL_QUADS);
//     // Front face
//     glColor3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, -0.5f, 0.5f);
//     glVertex3f(0.5f, -0.5f, 0.5f);
//     glVertex3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, 0.5f);
//     // Back face
//     glColor3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, -0.5f, -0.5f);
//     glVertex3f(-0.5f, 0.5f, -0.5f);
//     glVertex3f(0.5f, 0.5f, -0.5f);
//     glVertex3f(0.5f, -0.5f, -0.5f);
//     // Left face
//     glColor3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, -0.5f, -0.5f);
//     glVertex3f(-0.5f, -0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, -0.5f);
//     // Right face
//     glColor3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, -0.5f, -0.5f);
//     glVertex3f(0.5f, 0.5f, -0.5f);
//     glVertex3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, -0.5f, 0.5f);
//     // Top face
//     glColor3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, 0.5f, -0.5f);
//     glVertex3f(-0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(0.5f, 0.5f, -0.5f);
//     // Bottom face
//     glColor3f(0.5f, 0.5f, 0.5f);
//     glVertex3f(-0.5f, -0.5f, -0.5f);
//     glVertex3f(0.5f, -0.5f, -0.5f);
//     glVertex3f(0.5f, -0.5f, 0.5f);
//     glVertex3f(-0.5f, -0.5f, 0.5f);
//     glEnd();
// }

// int main(int argc, char* argv[])
// {
//     printf("Initializing GLFW\n");
//     if (!glfwInit())
//     {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     printf("Creating window\n");
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Block", NULL, NULL);
//     if (!window)
//     {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     printf("Setting window callback\n");
//     glfwSetWindowCloseCallback(window, window_close_callback);

//     glfwSetKeyCallback(window, key_callback);
//     glfwMakeContextCurrent(window);

//     printf("Initialize OpenGL\n");
//     glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
//     glEnable(GL_DEPTH_TEST);

//     glfwGetFramebufferSize(window, &width, &height);
//     glViewport(0, 0, width, height);

//     while (!glfwWindowShouldClose(window))
//     {   
//         movement(keyPressed);
//         render(window);

//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return EXIT_SUCCESS;
// }

// void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
// {
//     // Calculate the mouse movement
//     float deltaX = xpos - lastMouseX;
//     float deltaY = ypos - lastMouseY;

//     // Update the last mouse position
//     lastMouseX = xpos;
//     lastMouseY = ypos;

//     // Update the camera angles based on mouse movement
//     const float sensitivity = 0.01f; // Adjust sensitivity here
//     cameraYaw += deltaX * sensitivity;
//     cameraPitch -= deltaY * sensitivity; // Invert the pitch calculation

//     // Clamp the camera pitch to avoid flipping
//     if (cameraPitch > 89.0f)
//         cameraPitch = 89.0f;
//     if (cameraPitch < -89.0f)
//         cameraPitch = -89.0f;

//     // Convert camera angles to radians
//     float yawRadians = cameraYaw * 3.14159f / 180.0f;
//     float pitchRadians = cameraPitch * 3.14159f / 180.0f;

//     // Calculate the camera direction
//     float dirX = cos(yawRadians) * cos(pitchRadians);
//     float dirY = sin(pitchRadians);
//     float dirZ = sin(yawRadians) * cos(pitchRadians);

//     // Normalize the camera direction
//     float length = sqrt(dirX * dirX + dirY * dirY + dirZ * dirZ);
//     dirX /= length;
//     dirY /= length;
//     dirZ /= length;

//     // Calculate the camera target position based on initial camera position and direction
//     cameraTargetX = initialCameraPositionX + dirX;
//     cameraTargetY = initialCameraPositionY + dirY;
//     cameraTargetZ = initialCameraPositionZ + dirZ;
// }
