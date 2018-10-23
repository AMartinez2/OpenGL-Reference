#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

class Model {
public:
	// Functions
	Model(char *path);
	void Draw(Shader shader);
private:
	// Model data
	std::vector<Mesh> meshes;
	std::string directory;
	// Functions
	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

#endif