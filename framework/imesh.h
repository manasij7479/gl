#ifndef MM_IMESH_H
#define MM_IMESH_H
#include <vector>
#include <array>
#include<map>
namespace mm
{
	
	template<typename T,int Dim,typename U,int Fsize>
	class IMesh
	{
	public:
		IMesh(const std::vector<std::string>& channels);
		void addVertexData(const std::string& channel,const std::array<T,Dim>& vert)
		{
			vertices[channel].push_back(vert);
		};
		void addFace(const std::array<U,Fsize>& face)
		{
			faces.push_back(face);
		};
	private:
		typedef VertexData std::vector<std::array<T,Dim>>;
		std::map<std::string,VertexData> vertices;
		std::vector<std::array<U,Fsize>> faces;
	};
	typedef Imesh<float,3,uint,3> IndexedTriangleMesh;
	
	
}

#endif