#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include<math.h>

using namespace sf;
using namespace std;

void DrawAxes()
{
	//AXES

	
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	glVertex3f(-10, 0,0);
	glVertex3f(10, 0,0);

	glEnd();


	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	glVertex3f(0, -10,0);
	glVertex3f(0, 10,0);

	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	glVertex3f(0, 0,-10);
	glVertex3f(0, 0,10);
	
	glEnd();
}

int main()
{
	sf::Window window(sf::VideoMode(500, 500), "Opengl ");
	window.setVerticalSyncEnabled(true);
	glClearColor(0.9f, 0.9f, 0.9f, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	glViewport(0, 0, 500, 500);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glShadeModel(GL_FLAT);
	glEnable(GL_CULL_FACE);

	GLfloat vertexArray[12][3] = {};
	for (int i = 0; i < 5; i++)
	{
		vertexArray[i][0] = 8 * cos(i * 2 * 3.14 / 5);
		vertexArray[i][1] = 8 * sin(i * 2 * 3.14 / 5);
		vertexArray[i + 5][0] = 4 * cos(i * 2 * 3.14 / 5 + 3.14 / 5);
		vertexArray[i + 5][1] = 4 * sin(i * 2 * 3.14 / 5 + 3.14 / 5);
	}
	vertexArray[10][2] = 5;
	vertexArray[11][2] = -5;
		


	
	
	GLfloat colorArray[11][3] = {
			{ 1 , 0   , 0 } ,
			{ 1 , 0   , 0 } ,
			{ 1 , 0   , 0 } ,
			{ 1 , 0   , 0 } ,
			{ 1 , 0   , 0 } ,

			{ 1 , 0.6 , 0 } ,
			{ 1 , 0.6 , 0 } ,
			{ 1 , 0.6 , 0 } ,
			{ 1 , 0.6 , 0 } ,
			{ 1 , 0.6 , 0 } ,

			{ 1 , 1 , 0	  } ,
	};

	//glVertexPointer(3, GL_FLOAT, 0, vertexArray);
	//glColorPointer(3, GL_FLOAT, 0, colorArray);


	

	//GLubyte triangleIndexArray[3] = { 0,1,2 };
	//GLubyte quadIndexArray[4] = { 0,2,3,4 };
	GLubyte lineIndexArray[10] = { 0,5,1,6,2,7,3,8,4,9 };
	GLubyte simplestarIndexArray[5] = {0,2,4,1,3 };
	
	GLubyte triangleIndexArray[10][3] = {};

	for (int i = 0; i < 5; i++)
	{
		triangleIndexArray[ i][0] = 10;
		triangleIndexArray[ i][1] = i;
		triangleIndexArray[ i][2] = (i + 5)%10;

		triangleIndexArray[i+5][0] = 10;
		triangleIndexArray[i+5][1] = (i+5);
		triangleIndexArray[i+5][2] = (i + 1) % 5;
	}

	GLubyte triangle2IndexArray[10][3] = {};

	for (int i = 0; i < 5; i++)
	{
		triangle2IndexArray[i][0] = 11;
		triangle2IndexArray[i][2] = i;
		triangle2IndexArray[i][1] = (i + 5) % 11;
				
		triangle2IndexArray[i + 5][0] = 11;
		triangle2IndexArray[i + 5][2] = (i + 5);
		triangle2IndexArray[i + 5][1] = (i + 1) % 5;
	}
	GLfloat cubecolorArray[8][3] = {
			{ 1 , 0  , 0 } ,
			{ 0 , 0  , 0 } ,
			{ 1 , 0  , 0 } ,
			{ 1 , 0  , 0 } ,
			{ 1 , 0  , 0 } ,

			{ 1 , 0.6 , 0 } ,
			{ 1 , 0.6 , 0 } ,
			{ 1 , 0.6 , 0 } ,
	};

	GLfloat cubevertexArray[8][3] = {
			0,0,0,
			1,0,0,
			1,1,0,
			0,1,0,
			0,0,5,
			1,0,5,
			1,1,5,
			0,1,5,
			
	};

	
	GLubyte cubeIndexArray[6][4] = {
		0,3,2,1,
		4,5,6,7,
		1,5,4,0,
		1,2,6,5,
		0,4,7,3,
		2,3,7,6,

	};
	GLfloat prismvertexArray[6][3] = {
		0,0,0,
		1,1,0,
		0,2,0,
		0,0,5,
		1,1,5,
		0,2,5,
	};
	GLubyte prismIndexArray[8][3] = {
		0,2,1,
		4,5,3,
		1,2,5,
		1,5,4,
		3,2,0,// черный 
		3,5,2,
		0,1,4,//что-то
		0,4,3,

	};
	GLfloat prismcolorArray[8][3] = {
			{ 0 , 0 , 0 } ,
			{ 0 , 1 , 0 } ,
			{ 0 , 0 , 1 } ,
			{ 1 , 1 , 0 } ,
			{ 1 , 0 , 0.6 } ,

			{ 1 , 0 , 0 } ,
			{ 1 , 0.5 , 0 } ,
			{ 1 , 0 , 0.5 } ,
	};




	

	int rotation[3] = {};
	
	bool type ;

	while (window.isOpen())
	{
		sf::Event event;
		glClear(GL_COLOR_BUFFER_BIT);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::Resized)
				glViewport(0, 0, event.size.width, event.size.height);
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A)
					//glRotated(1, 0, 1,0);
					rotation[1] += 5;
				if (event.key.code == sf::Keyboard::D)
					//glRotated(-1, 0, 1, 0);
					rotation[1] -= 5;
				if (event.key.code == sf::Keyboard::W)
					//glRotated(1, 1, 0, 0);
					rotation[0] += 5;
				if (event.key.code == sf::Keyboard::S)
					//glRotated(-1, 1, 0, 0);
					rotation[0] -= 5;
				if (event.key.code == sf::Keyboard::Numpad6)
					glTranslatef(0.5, 0, 0);
				if (event.key.code == sf::Keyboard::Numpad4)
					glTranslatef(-0.5, 0, 0);
				if (event.key.code == sf::Keyboard::Numpad8)
					glTranslatef(0, 0.5, 0);
				if (event.key.code == sf::Keyboard::Numpad2)
					glTranslatef(0, -0.5, 0);
				if (event.key.code == sf::Keyboard::X)
					glRotated(5, 1, 0, 0);
				if (event.key.code == sf::Keyboard::Y)
					glRotated(5, 0, 1, 0);
				if (event.key.code == sf::Keyboard::Z)
					glRotated(5, 0, 0, 1);
				if (event.key.code == sf::Keyboard::B)
					glScalef(1.1, 1.1, 1.1);
				if (event.key.code == sf::Keyboard::N)//заметим,что  N похожа S
					glScalef(0.9, 0.9, 0.9);
				if (event.key.code == sf::Keyboard::F1)

					type = 0;
				if (event.key.code == sf::Keyboard::F2)

					type = 1;
				
			}
			
			
		}
		glClear(GL_COLOR_BUFFER_BIT);
		/*
		glVertexPointer(3, GL_FLOAT, 0, cubevertexArray);
		glColorPointer(3, GL_FLOAT, 0, cubecolorArray);
		glPushMatrix();


		glTranslatef(8, 8, 8);
		glRotatef(rotation[0], 1, 0, 0);
		glRotatef(rotation[1], 0, 1, 0);
		glRotatef(rotation[2], 0, 0, 1);
		
		//glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_BYTE,triangleIndexArray);
		//glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_BYTE, triangle2IndexArray);
		//glDrawElements(GL_LINE_LOOP, 10, GL_UNSIGNED_BYTE, simplestarIndexArray);
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE,cubeIndexArray);
		glPopMatrix();
		*/

		//float x, y;
		//
		//float cnt = 30;
		//float l = 8.1;
		//float a = 3.14 * 2 / cnt;
		//
		//glBegin(GL_LINE_STRIP);
		//glColor3f(1, 0, 0);
		////glVertex2f(0, 0);
		//for (int i = -1; i < cnt; i++)
		//{
		//	x = sin(a * i) * l;
		//	y = cos(a * i) * l;
		//	glVertex2f(x, y);
		//}
		//
		//glEnd();
		
		/*

		glPushMatrix();


		
		glRotatef(rotation[0], 1, 0, 0);
		glRotatef(rotation[1], 0, 1, 0);
		glRotatef(rotation[2], 0, 0, 1);
		glVertexPointer(3, GL_FLOAT, 0, vertexArray);
		glColorPointer(3, GL_FLOAT, 0, colorArray);
		glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_BYTE,triangleIndexArray);
		glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_BYTE, triangle2IndexArray);


		glPopMatrix();
		*/
		glPushMatrix();



		//glBegin(GL_POINT)
		
		glClear(GL_COLOR_BUFFER_BIT);

		//glPointSize(10);

		glRotatef(rotation[0], 1, 0, 0);
		glRotatef(rotation[1], 0, 1, 0);
		glRotatef(rotation[2], 0, 0, 1);
		glVertexPointer(3, GL_FLOAT, 0, prismvertexArray);
		glColorPointer(3, GL_FLOAT, 0, prismcolorArray);
		glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_BYTE, prismIndexArray);
		//glDrawElements(GL_POINTS, 24, GL_UNSIGNED_BYTE, prismIndexArray);
		

		glPopMatrix();
		

		glPushMatrix();
		glTranslatef(8, 8, 8);

		glRotatef(rotation[0], 1, 0, 0);
		glRotatef(rotation[1], 0, 1, 0);
		glRotatef(rotation[2], 0, 0, 1);

		glVertexPointer(3, GL_FLOAT, 0, cubevertexArray);
		glColorPointer(3, GL_FLOAT, 0, cubecolorArray);
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndexArray);
		glPopMatrix();
		
		//DrawAxes();

		window.display();
	}

	return 0;
}






/*




#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
using namespace sf;
using namespace std;

void DrawAxes()
{
	//AXES


	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	glVertex3f(-10, 0, 0);
	glVertex3f(10, 0, 0);

	glEnd();


	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	glVertex3f(0, -10, 0);
	glVertex3f(0, 10, 0);

	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	glVertex3f(0, 0, -10);
	glVertex3f(0, 0, 10);

	glEnd();
}

int main()
{
	sf::Window window(sf::VideoMode(500, 500), "Opengl ");
	window.setVerticalSyncEnabled(true);
	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	glViewport(0, 0, 500, 500);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glShadeModel(GL_FLAT);

	

	GLfloat vertexArray[5][2] = {
					{-1 , 6, } ,
					{ 1 , 6 ,} ,
					{ 1 , -6, } ,            
					{ -1 , -6 ,} ,
					{ -8 , 0, } ,
	};
	GLfloat colorArray[5][3] = {
			{ 1 , 0 , 0 } ,
			{ 0 , 1 , 0} ,
			{ 0 , 0 , 1 } ,
			{ 1 , 1 , 0 } ,
			{ 0 , 1 , 1 } ,
	};

	glVertexPointer(2, GL_FLOAT, 0, vertexArray);
	glColorPointer(3, GL_FLOAT, 0, colorArray);

	GLubyte triangleIndexArray[3] = { 0,1,2 };
	GLubyte quadIndexArray[4] = { 0,2,3,4 };
	GLubyte lineIndexArray[5] = { 0,1,2,3,4 };

	GLubyte triangle2IndexArray[3][3] = {
		4,0,1,
		4,1,2,
		4,2,3,
	};

	bool type;

	while (window.isOpen())
	{
		sf::Event event;
		glClear(GL_COLOR_BUFFER_BIT);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::Resized)
				glViewport(0, 0, event.size.width, event.size.height);
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A)
					glRotated(1, 0, 1, 0);
				if (event.key.code == sf::Keyboard::D)
					glRotated(-1, 0, 1, 0);
				if (event.key.code == sf::Keyboard::W)
					glRotated(1, 1, 0, 0);
				if (event.key.code == sf::Keyboard::S)
					glRotated(-1, 1, 0, 0);
				if (event.key.code == sf::Keyboard::Numpad6)
					glTranslatef(0.5, 0, 0);
				if (event.key.code == sf::Keyboard::Numpad4)
					glTranslatef(-0.5, 0, 0);
				if (event.key.code == sf::Keyboard::Numpad8)
					glTranslatef(0, 0.5, 0);
				if (event.key.code == sf::Keyboard::Numpad2)
					glTranslatef(0, -0.5, 0);
				if (event.key.code == sf::Keyboard::X)
					glRotated(5, 1, 0, 0);
				if (event.key.code == sf::Keyboard::Y)
					glRotated(5, 0, 1, 0);
				if (event.key.code == sf::Keyboard::Z)
					glRotated(5, 0, 0, 1);
				if (event.key.code == sf::Keyboard::B)
					glScalef(1.1, 1.1, 1);
				if (event.key.code == sf::Keyboard::N)//заметим,что  N похожа S
					glScalef(0.9, 0.9, 1);
				if (event.key.code == sf::Keyboard::F1)

					type = 0;
				if (event.key.code == sf::Keyboard::F2)

					type = 1;

			}


		}
		glClear(GL_COLOR_BUFFER_BIT);

		
		if (type)
		
			glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_BYTE, triangle2IndexArray);//для 1 задания
		
		else
			glDrawElements(GL_LINE_LOOP, 5, GL_UNSIGNED_BYTE, lineIndexArray);






		//glClear(GL_COLOR_BUFFER_BIT);
		//glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_BYTE,triangleIndexArray);

		//glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, quadIndexArray);

		//glDrawElements(GL_LINE_LOOP, 5, GL_UNSIGNED_BYTE, lineIndexArray);

		//glDrawElements(GL_TRIANGLES,9,GL_UNSIGNED_BYTE,triangle2IndexArray);


		//DrawAxes();

		window.display();
	}

	return 0;
}
*/