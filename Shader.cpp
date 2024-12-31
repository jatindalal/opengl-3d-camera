#include "Shader.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

Shader::Shader(const char* vertex_file, const char* fragment_file)
{
    std::string vertex_code = Shader::get_file_contents(vertex_file);
    auto vertex_shader_source = vertex_code.c_str();

    std::string fragment_code = Shader::get_file_contents(fragment_file);
    auto fragment_shader_source = fragment_code.c_str();
    
    auto vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
    glCompileShader(vertex_shader);

    auto fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
    glCompileShader(fragment_shader);

    m_id = glCreateProgram();
    glAttachShader(m_id, vertex_shader);
    glAttachShader(m_id, fragment_shader);
    glLinkProgram(m_id);
    
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

std::string Shader::get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw std::runtime_error("Couldn't get file contents!");
}

void Shader::activate()
{
    glUseProgram(m_id);
}

void Shader::delete_shader()
{
    glDeleteProgram(m_id);
}

