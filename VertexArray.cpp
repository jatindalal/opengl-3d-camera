#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

void VertexArray::link_attrib(VertexBuffer& vbo, GLuint layout,
                              GLuint num_components, GLenum type,
                              GLsizeiptr stride, void *offset)
{
    vbo.bind();

    glVertexAttribPointer(layout, num_components, type, GL_FALSE, stride, offset);
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
