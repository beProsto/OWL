#include <OWL/OWL.hpp>
#include <OWL/Main.hpp>
#include <OWL/OpenGL.hpp>
#include <OWL/Time.hpp>

#include <cmath>
#include <iostream>

#define GL_FUNC_LOAD(rettype, name, ...) \
	typedef rettype(*name##F)(__VA_ARGS__); \
	name##F name = (name##F)openGLLoadFunc(#name);

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_COMPILE_STATUS 0x8B81
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4

int main(int argc, char** argv) {
	printf("a!\n");
	OWL::OpenGLContext context;
	printf("a!\n");
	OWL::Window window;
	printf("a!\n");
	OWL::FPSLimiter fps(60);
	printf("a!\n");
	OWL::Timer time;

	printf("a!\n");
	window.setContext(context);

	printf("a!\n");
	OWL::OpenGLLoaderFunction openGLLoadFunc = context.getLoaderFunction();

	printf("b!\n");
	// load OpenGL functions using the macro defined above (uses the OWL::GLContext's GetProcAddress function):
	GL_FUNC_LOAD(unsigned int, glCreateShader, unsigned int)
	GL_FUNC_LOAD(void, glShaderSource, unsigned int, unsigned int, const char**, unsigned int)
	GL_FUNC_LOAD(void, glCompileShader, unsigned int)
	GL_FUNC_LOAD(void, glGetShaderiv, unsigned int, unsigned int, int*)
	GL_FUNC_LOAD(void, glGetShaderInfoLog, unsigned int, unsigned int, unsigned int, char*)
	GL_FUNC_LOAD(unsigned int, glCreateProgram)
	GL_FUNC_LOAD(void, glAttachShader, unsigned int, unsigned int)
	GL_FUNC_LOAD(void, glLinkProgram, unsigned int)
	GL_FUNC_LOAD(void, glValidateProgram, unsigned int)
	GL_FUNC_LOAD(void, glDeleteShader, unsigned int)
	GL_FUNC_LOAD(void, glUseProgram, unsigned int)
	GL_FUNC_LOAD(void, glDeleteProgram, unsigned int)
	GL_FUNC_LOAD(void, glGenVertexArrays, unsigned int, unsigned int*)
	GL_FUNC_LOAD(void, glBindVertexArray, unsigned int)
	GL_FUNC_LOAD(void, glGenBuffers, unsigned int, unsigned int*)
	GL_FUNC_LOAD(void, glBindBuffer, unsigned int, unsigned int)
	GL_FUNC_LOAD(void, glDeleteVertexArrays, unsigned int, unsigned int*)
	GL_FUNC_LOAD(void, glDeleteBuffers, unsigned int, unsigned int*)
	GL_FUNC_LOAD(void, glBufferData, unsigned int, unsigned int, void*, unsigned int)
	GL_FUNC_LOAD(void, glVertexAttribPointer, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, void*)
	GL_FUNC_LOAD(void, glEnableVertexAttribArray, unsigned int)
	GL_FUNC_LOAD(void, glViewport, unsigned int, unsigned int, unsigned int, unsigned int)
	GL_FUNC_LOAD(void, glclearColor, float, float, float, float)
	GL_FUNC_LOAD(void, glclear, unsigned int)
	GL_FUNC_LOAD(int, glGetUniformLocation, unsigned int, const char*)
	GL_FUNC_LOAD(void, glUniform2f, unsigned int, float, float)
	GL_FUNC_LOAD(void, glDrawArrays, unsigned int, unsigned int, unsigned int)

	printf("c!\n");
	float t = 0.0f;

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	const char* vsc = 
	"#version 330\n\
	\n\
	layout (location = 0) in vec3 a_Position;\n\
	layout (location = 1) in vec3 a_Color;\n\
	\n\
	out vec4 v_Color;\n\
	\n\
	uniform vec2 u_Offset;\n\
	uniform vec2 u_Aspect;\n\
	\n\
	void main() {\n\
	\tgl_Position = vec4(a_Position * vec3(u_Aspect, 1.0f) + vec3(u_Offset, 0.0f), 1.0f);\n\
	\tv_Color = vec4(a_Color, 1.0f);\n\
	}\n";

	const char* fsc = 
	"#version 330\n\
	\n\
	out vec4 o_Color;\n\
	\n\
	in vec4 v_Color;\n\
	\n\
	void main() {\n\
	\to_Color = v_Color;\n\
	}\n";

	unsigned int vShaderID, fShaderID, shaderID, vbID, vaID;
	
	int  success;
	char infoLog[512];

	vShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShaderID, 1, &vsc, 0);
	glCompileShader(vShaderID);

	glGetShaderiv(vShaderID, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vShaderID, 512, 0, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShaderID, 1, &fsc, 0);
	glCompileShader(fShaderID);
	
	glGetShaderiv(fShaderID, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fShaderID, 512, 0, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vShaderID);
	glAttachShader(shaderID, fShaderID);
	glLinkProgram(shaderID);
	glValidateProgram(shaderID);

	glDeleteShader(vShaderID);
	glDeleteShader(fShaderID);

	glUseProgram(shaderID);

	glGenVertexArrays(1, &vaID);
	glBindVertexArray(vaID);

	glGenBuffers(1, &vbID);
	glBindBuffer(GL_ARRAY_BUFFER, vbID);

	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);  

	while(window.isRunning()) {
		window.pollEvents();
		fps.start();
		time.start();
		
		if(time.getDeltaTime() > 0.0f) t += time.getDeltaTime();

		if(window.keyboard.getKeyData().keyEnum == window.keyboard.M) {
			window.mouse.SetVisibility(!window.mouse.IsVisible());
		}
		if(window.keyboard.getKeyData().keyEnum == window.keyboard.F11) {
			window.setFullScreen(!window.isFullScreen());
		}
		if(window.keyboard.isKeyPressed(window.keyboard.Escape)) {
			window.close();
		}

		float sint = std::sin(t) * 0.5f + 0.5f;

		OWL::Vec2f mp = (OWL::Vec2f)window.mouse.getPosition() / (OWL::Vec2f)window.getSize() * OWL::Vec2f(2.0f) - OWL::Vec2f(1.0f);
		mp.y = -mp.y;

		glViewport(0, 0, window.getSize().x, window.getSize().y);

		glclearColor(sint, sint, sint, 1.0f);
		glclear(GL_COLOR_BUFFER_BIT);

		glUniform2f(glGetUniformLocation(shaderID, "u_Offset"), mp.x, mp.y);
		glUniform2f(glGetUniformLocation(shaderID, "u_Aspect"), 1.0f/window.getAspect(), 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		context.swapBuffers();

		fps.end();
		time.end();
	}

	glDeleteVertexArrays(1, &vaID);
	glDeleteBuffers(1, &vbID);
	glDeleteProgram(shaderID);

	return 0;
}
