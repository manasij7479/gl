#ifndef MM_CONWAY_H
#define MM_CONWAY_H
#include<vector>
#include<ctime>
#include<cstdlib>
#include<iostream>
namespace mm
{
	class Grid
	{
	public:
		Grid(int sizex,int sizey)
		:sizeX(sizex),sizeY(sizey)
		{
			std::srand(std::time(nullptr));
			std::vector<int> row;
			for(int i=0;i<sizeX;++i)
			{
				for(int j=0;j<sizeY;++j)
				{
					row.push_back(0);
				}
				data.push_back(row);
			}
		}
		int& getX()
		{
			return sizeX;
		}
		int& getY()
		{
			return sizeY;
		}
		void round(int& x,int& y)
		{
			if((x>=0 && y>=0 && x<sizeX && y<sizeY))
				return;
			if(x<0)
				x=sizeX-x;
			if(y<0)
				y=sizeY-y;
			if(x>=sizeX)
				x=x-sizeX;
			if(y>=sizeY)
				y=y-sizeY;
			if(!(x>=0 && y>=0 && x<sizeX && y<sizeY))
				round(x,y);
			
		}
		int at(int x,int y)
		{
			round(x,y);
			return data[x][y];			
		}
		void set(int x,int y)
		{
			round(x,y);
			data[x][y]=1;
		}
		void reset(int x,int y)
		{
			round(x,y);
			data[x][y]=0;
		}
		void toggle(int x,int y)
		{
			round(x,y);
			data[x][y]=!data[x][y];
		}
		void fill_random(int x)
		{
			for(int n=0;n<x;++n)
			{
				int i=rand()%sizeX;
				int j=rand()%sizeY;
				set(i,j);
			}
		}
		void update()
		{
			Grid* g = new Grid(sizeX,sizeY);
			for(int i=0;i<sizeX;++i)
			{
				for(int j=0;j<sizeY;++j)
				{
					int n=
					at(i-1,j-1)+
					at(i-1,j-0)+
					at(i-1,j+1)+
					at(i-0,j-1)+
					at(i-0,j+1)+
					at(i+1,j-1)+
					at(i+1,j-0)+
					at(i+1,j+1);
					
					int alive = at(i,j);
					
					if(alive)
					{
						if(n<2)
						{}
						if(n==2||n==3)
							g->set(i,j);
						if(n>3)
						{}
					}
					else
					{
						if(n==3)
							g->set(i,j);
					}
					
				}
			}
			std::swap(data,g->data);
			delete g;
		}
	private:
		int sizeX,sizeY;
// 		float scaleX,scaleY;
		std::vector<std::vector<int>> data;
	};
}
#endif