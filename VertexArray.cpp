#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

void VertexArray::link_vertex_buffer(VertexBuffer& vbo, GLuint layout)
{
    vbo.bind();

    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
}

void VertexArray::bind()
{
    glBindVertexArray(m_id);
}

void VertexArray::unbind()
{
    glBindVertexArray(0);
}

void VertexArray::delete_array()
{
    glDeleteVertexArrays(1, &m_id);
}
