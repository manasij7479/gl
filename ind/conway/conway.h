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
		Grid(int sizex,int sizey):sx(sizex),sy(sizey)
		{
			std::srand(std::time(nullptr));
			std::vector<int> row;
			for(int i=0;i<sx;++i)
			{
				for(int j=0;j<sy;++j)
				{
					row.push_back(0);
				}
				data.push_back(row);
			}
		}
		void round(int& x,int& y)
		{
			if(x<0)
				x=sx-x;
			if(y<0)
				y=sy-y;
			if(x>=sx)
				x=x-sx;
			if(y>=sy)
				y=y-sy;
			if(!(x>=0 && y>=0 && x<sx && y<sy))
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
		void fill_random(int x)
		{
			for(int n=0;n<x;++n)
			{
				int i=rand()%sx;
				int j=rand()%sy;
				set(i,j);
			}
		}
		void update()
		{
			Grid* g = new Grid(sx,sy);
			for(int i=0;i<sx;++i)
			{
				for(int j=0;j<sy;++j)
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
		int sx,sy;
		std::vector<std::vector<int>> data;
	};
}
#endif