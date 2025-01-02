#pragma once

#include <glad/glad.h>
#include "VertexBuffer.h"

class VertexArray
{
public:
    GLuint m_id;
    VertexArray();

    void link_attrib(VertexBuffer& vbo, GLuint layout, GLuint num_components,
                     GLenum type, GLsizeiptr stride, void *offset);
    void bind();
    void unbind();
    void delete_array();
};
