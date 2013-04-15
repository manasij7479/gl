/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  Manasij Mukherjee <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef ASSIMPMESH_H
#define ASSIMPMESH_H
#include<map>
// #include <assimp/Importer.hpp> // C++ importer interface
#include <assimp/scene.h> // Output data structure
// #include <assimp/postprocess.h> // Post processing flags
#include "mesh.h"
namespace mm
{
	class AssimpMesh:public Mesh
	{
	public:
		AssimpMesh(std::string dataf,std::string vsf,std::string fsf);
		AssimpMesh(const std::string& dataf,Program* prog_);
		void draw();
		mm::Program* getProgram(){return prog;};
		~AssimpMesh(){delete prog;}
	private:
		mm::Program* prog;
		const aiScene* scene;
		const aiMesh* mesh;
		GLuint vao;
		std::map<std::string,GLuint> vbomap;
		int isize;
	};
}
#endif // ASSIMPMESH_H
