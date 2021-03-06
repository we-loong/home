// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
using namespace std;

// TODO: 在此处引用程序需要的其他头文件

#include "Common/glad.h"
#include "Common/TypeDef.h"
#include "Common/CommonHelp.h"
#include "Common/CFileManage.h"
#include "Common/CResourceImg.h"
#include "Common/CShader.h"
#include "Common/CCamera.h"

#include "glfw/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

extern GLFWwindow* g_pWindow;
extern CCamera g_MainCamera;
extern float g_DeltaTime;
extern float g_LastFrame;

#define CurMainFunction main3
#define CurSleepTime 15
#define g_nWindowWidth 800
#define g_nWindowHeight 600
#define g_szWindowTitle "LearnOpenGL"
#define RES_ROOT_DIR "./../../res/"

int main1(int argc, char* argv[]);
int main2(int argc, char* argv[]);
int main3(int argc, char* argv[]);

void FrameBufferSizeCallback(GLFWwindow* pWin, int nWidth, int nHeight);
void processInput(GLFWwindow* pWindow);
void MouseCallback(GLFWwindow* pWindow, double xPos, double yPos);
void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
uint32 loadTexture( const char *path );

#define MainWhileStart while(!glfwWindowShouldClose(g_pWindow)) \
	{ \
		float currentFrame = (float)glfwGetTime(); \
		g_DeltaTime = currentFrame - g_LastFrame; \
		g_LastFrame = currentFrame; \
		processInput(g_pWindow); \
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); \
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

#define MainWhileEnd glfwSwapBuffers( g_pWindow ); \
	glfwPollEvents(); \
	Sleep( CurSleepTime ); \
	}
