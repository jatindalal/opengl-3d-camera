#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    unsigned int m_id;
    Shader(const char* vertex_file, const char* fragment_file);

    void activate();
    void delete_shader();
    static std::string get_file_contents(const char* filename);
};
