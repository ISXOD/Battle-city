#pragma once
#include <string>
#include <memory>
#include <map>

namespace Renderer {
	class ShaderProgram;
}

class ResourceManager {
public:
	ResourceManager(const std::string& executablePath);

	~ResourceManager() = default;


	ResourceManager(const ResourceManager&) = delete;

	ResourceManager& operator=(const ResourceManager&) = delete;

	ResourceManager& operator=(ResourceManager&&) = delete;

	ResourceManager(ResourceManager&&) = delete;


	std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);

	std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

	void loadRexture(const std::string& textureName, const std::string& texturePath);

private:
	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;

	std::string getFileString(const std::string& relativeFilePath) const;

	ShaderProgramsMap m_ShaderPrograms;

	std::string m_path;
};