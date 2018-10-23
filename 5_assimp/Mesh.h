#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Shader.h"

#include <string>
#include <vector>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
};

class Mesh {
public:
	// Mesh Data 
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;
	// Functions
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indecies, std::vector<Texture> textures);
	void Draw(Shader shader);
private:
	// Render data
	unsigned int VAO, VBO, EBO;
	// Functions
	void setupMesh();
};
#endif