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
/*
 *Class to read in mesh descriptions from a file of the following format.
 * <Name> M vecN
 * <MxN whitespace separated values>
 * 
 * index X
 * <X whitespace separated values>
 * 
 * drawmode <mode>
 */

#ifndef MM_MESH_H
#define MM_MESH_H
#include <string>
#include <vector>
#include <map>
#include "framework.h"
namespace mm
{
	class Mesh
	{
	public:
// 		Mesh(std::string dataf,std::string vsf,std::string fsf);//File names
// 		Mesh(std::string dataf,mm::Program* prog_);
		virtual void draw()=0;
		virtual mm::Program* getProgram()=0;
// 		{
// 			return prog;
// 		}
// 		virtual ~Mesh()=0;
	private:
// 		mm::Program* prog;
// 		GLuint vao;
// 		std::map<std::string,GLuint> vbomap;
// 		GLenum drawmode;
// 		int isize;
	};
}

#endif // MESH_H
