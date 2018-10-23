#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Shader.h"
#include "stb_image.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

class Model {
public:
	// Functions
	Model(char *path);
	void Draw(Shader shader);
	// Model data
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
private:
	// Functions
	void loadModel(std::string const &path);
	void processNode(aiNode *node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);
};

#endif