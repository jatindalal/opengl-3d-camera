#pragma once

#include <glad/glad.h>

class ElementBuffer
{
public:
    GLuint m_id;
    ElementBuffer(GLuint *indices, GLsizeiptr size);

    void bind();
    void unbind();
    void delete_buffer();
};
