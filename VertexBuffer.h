#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:
    GLuint m_id;
    VertexBuffer(GLfloat *vertices, GLsizeiptr size);

    void bind();
    void unbind();
    void delete_buffer();
};
