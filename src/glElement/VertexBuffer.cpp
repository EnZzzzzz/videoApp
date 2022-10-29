#include "VertexBuffer.h"

#include "glCheck.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    :layout(VertexBufferLayout())
{
    m_Size = (int)size;
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID ));
}

void VertexBuffer::bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

int VertexBuffer::GetCount()
{
    return (int)m_Size / layout.GetStride();
}