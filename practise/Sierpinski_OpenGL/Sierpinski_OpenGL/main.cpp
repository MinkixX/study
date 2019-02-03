#include<stdio.h>
#include<GLEW/glew.h>
#include<GLFW/glfw3.h>
#include<malloc.h>
#include<string.h>
#include <windows.h>

#include"algorithm.h"


static unsigned int CompileShader(unsigned int type, const char* source)
{
	unsigned int id = glCreateShader(type);

	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)malloc(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		printf("Failed to compile %s shader:\n%s\n",
			type == GL_VERTEX_SHADER ? "vertex" : "fragment", message);

		glDeleteShader(id);

		free(message);
		return 0;
	}

	return id;
}


static unsigned int CreateShader(const char* vertexShader, const char* fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}


struct ShaderStrings
{
	char vertex[1024];
	char fragment[1024];
} typedef ShaderStrings;

static ShaderStrings ParseShader(const char* path)
{
	enum ShaderType {
		NONE,
		VERTEX,
		FRAGMENT
	};
	ShaderType type = NONE;

	ShaderStrings shaderStrings =
	{
		"\0",
		"\0"
	};

	FILE* fp;
	char buff[256];

	fopen_s(&fp, path, "r");

	while (!feof(fp))
	{
		fgets(buff, 256, fp);

		if (strstr(buff, "#shader") != NULL) {
			if (strstr(buff, "vertex") != NULL)
				type = VERTEX;
			else if (strstr(buff, "fragment") != NULL)
				type = FRAGMENT;
			else
				type = NONE;
		}
		else
		{
			if (type == VERTEX)
				strcat_s(shaderStrings.vertex, sizeof(buff) / sizeof(char), buff);
			else if (type == FRAGMENT)
				strcat_s(shaderStrings.fragment, sizeof(buff) / sizeof(char), buff);
		}
	}


	fclose(fp);

	return shaderStrings;
}


int main(void)
{
	unsigned int recursions;

	printf("recursion count: ");
	scanf_s("%u", &recursions, 1);

	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1024, 768, "Sierpinski-Triangle", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* enable VSync */
	//glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		return -1;

	printf("%s", glGetString(GL_VERSION));

	/* Initialize a graphics buffer*/
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	//glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions, GL_STATIC_DRAW);

	/* Specify vertex attributes*/
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	ShaderStrings shaderstrings = ParseShader("basic.shader");

	unsigned int shader = CreateShader(shaderstrings.vertex, shaderstrings.fragment);
	glUseProgram(shader);

	float positions[6] = {
		 0.0f,  1.0f,
		 1.0f, -1.0f,
		-1.0f, -1.0f
	};

 	SierpinskiTriangle triangle = setupTriangle(positions, sizeof(positions)/sizeof(float));

	printf("\n\nSTEP: %u\n", triangle.step);

	for (unsigned int i = 0; i < triangle.count; i += 2)
		printf("\n%f, %f", triangle.positions[i], triangle.positions[i + 1]);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		while (triangle.step <= recursions)
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			glBufferData(GL_ARRAY_BUFFER, triangle.count * sizeof(float), triangle.positions, GL_DYNAMIC_DRAW);
			glDrawArrays(GL_TRIANGLES, 0, triangle.count / 2);

			triangle = sierpinski(&triangle);

			printf("\n\nSTEP: %i\n", triangle.step);

			for (unsigned int i = 0; i < triangle.count; i += 2)
				printf("\n%f, %f", triangle.positions[i], triangle.positions[i + 1]);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);
		}

		/* Poll for and process events */
		glfwPollEvents();

		Sleep(1);
	}

	free(triangle.positions);

	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}