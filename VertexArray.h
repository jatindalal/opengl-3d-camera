#pragma once

#include <glad/glad.h>
#include "VertexBuffer.h"

class VertexArray
{
public:
    GLuint m_id;
    VertexArray();

    void link_vertex_buffer(VertexBuffer& vbo, GLuint layout);
    void bind();
    void unbind();
    void delete_array();
};
