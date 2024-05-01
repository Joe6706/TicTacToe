#pragma once

#include <Windows.h>;
#include <gl/glew.h>;
#include <GLFW/glfw3.h>;
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_NATIVE_INCLUDE_NONE
#include <GLFW/glfw3native.h>;
#include <Math.h>;
void drawX(float starting_x, float starting_y);
void drawO(float cx, float cy, float r, int num_segments);
