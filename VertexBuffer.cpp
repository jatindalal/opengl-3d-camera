#include "VertexBuffer.h"
#include "Shader.h"


VertexBuffer::VertexBuffer(GLfloat* vertices, GLsizeiptr size)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::delete_buffer()
{
    glDeleteBuffers(1, &m_id);
}
