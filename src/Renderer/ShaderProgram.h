#pragma once
#include <string>
#include <glad/glad.h>

namespace Renderer {
	class ShaderProgram{
	public:
		ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;

		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;

		~ShaderProgram();
		bool isCompiled() const { return m_isCompiled; }
		void use() const;

	private:
		bool m_isCompiled = false;
		bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
		GLuint m_ID = 0;
	};
}
