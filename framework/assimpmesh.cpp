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

#include <assimp/Importer.hpp> // C++ importer interface
#include <assimp/scene.h> // Output data structure
#include <assimp/postprocess.h> // Post processing flags
#include "assimpmesh.h"
#include<stdexcept>
namespace mm
{
	AssimpMesh::AssimpMesh(const std::string& dataf, Program* prog_)
	{
		prog=prog_;
		Assimp::Importer importer;
		scene = importer.ReadFile(dataf,
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_JoinIdenticalVertices |
			aiProcess_SortByPType|
			aiProcess_GenNormals );
		if(!scene)
			throw(std::runtime_error("Loading "+dataf+" failed: "+importer.GetErrorString()));
		
		if(!scene->HasMeshes())
			throw(std::runtime_error("Mesh not found in file: "+ dataf));
		
		mesh = scene->mMeshes[scene->mRootNode->mChildren[0]->mMeshes[0]];
		
		if(!mesh->HasFaces() || !mesh->HasNormals())
			throw(std::runtime_error("Mesh doesn't have Indices or Vertex Normals"));
		
		glUseProgram(prog->getHandle());
		glGenVertexArrays(1,&vao);
		glBindVertexArray(vao);
		
		GLfloat* vertices,*normals;
		vertices = new GLfloat[3*mesh->mNumVertices];
		normals = new GLfloat[3*mesh->mNumVertices];
		GLuint* indices = new GLuint[3*mesh->mNumFaces];
		
		for(uint i=0;i<mesh->mNumVertices;++i)
		{
			auto v = mesh->mVertices[i];
			auto n = mesh->mNormals[i];
// 			std::cout<<"v: "<<v.x<<' '<<v.y<<' '<<v.z<<" n: "<<n.x<<' '<<n.y<<' '<<n.z<<std::endl;
			vertices[3*i+0]=v.x;vertices[3*i+1]=v.y;vertices[3*i+2]=v.z;
			normals[3*i+0]=n.x;normals[3*i+1]=n.y;normals[3*i+2]=n.z;
		}
		for(uint i=0;i<mesh->mNumFaces;++i)
		{
			auto f = mesh->mFaces[i];
// 			std::cout<<f.mIndices[0]<<' '<<f.mIndices[1]<<' '<<f.mIndices[2]<<' '<<std::endl;
			indices[3*i+0]=f.mIndices[0];
			indices[3*i+1]=f.mIndices[1];
			indices[3*i+2]=f.mIndices[2];
		}
		GLuint vbo[2],ibo;
		GLint loc;
		glGenBuffers(2,vbo);
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo[0]);
		glBufferData(GL_ARRAY_BUFFER,3*mesh->mNumVertices*sizeof(GLfloat),vertices,GL_STATIC_DRAW);
		loc = glGetAttribLocation(prog->getHandle(),"pos");
		glVertexAttribPointer(loc,3,GL_FLOAT,GL_FALSE,0,0);
		glEnableVertexAttribArray(loc);
		vbomap["pos"]=vbo[0];
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo[1]);
		glBufferData(GL_ARRAY_BUFFER,3*mesh->mNumVertices*sizeof(GLfloat),normals,GL_STATIC_DRAW);
		loc = glGetAttribLocation(prog->getHandle(),"norm");
		glVertexAttribPointer(loc,3,GL_FLOAT,GL_TRUE,0,0);
		glEnableVertexAttribArray(loc);
		vbomap["norm"]=vbo[1];
		
		isize=3*mesh->mNumFaces;
		glGenBuffers(1,&ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,isize*sizeof(GLuint),indices,GL_STATIC_DRAW);
		vbomap["index"]=ibo;
		
		delete[] vertices;
		delete[] normals;
		delete[] indices;

	}
	AssimpMesh::AssimpMesh(std::string dataf, std::string vsf,const  std::string fsf):
	AssimpMesh
	(
		dataf,
		new mm::Program
		(
			{
				mm::Shader(GL_VERTEX_SHADER,vsf),
				mm::Shader(GL_FRAGMENT_SHADER,fsf)
			}
		)
	)
	{
	}
	
	void AssimpMesh::draw()
	{
// 		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(prog->getHandle());
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES,isize,GL_UNSIGNED_INT,0);
		glBindVertexArray(0);
		glUseProgram(0);
	}

}