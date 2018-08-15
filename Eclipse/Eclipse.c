#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

GLfloat ScreenSizeX=1366,ScreenSizeY=768;
GLfloat PI=3.14;
void *currentfont;

void sun(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9882,1.0,0.0392);
	glTranslatef(-5.0,0.0,0.0);
	glutSolidSphere(2.0,200,100);
}

void earth(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.4901,0.8117,0.6705);
	glTranslatef(15,0.0,0.0);
	glutSolidSphere(1.2,100,100);
}

void moon(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9803,0.9803,0.9803);
	glTranslatef(12.0,0.0,0.0);
	glutSolidSphere(0.3,100,100);
}

void DarkMoon(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.7294,0.7294,0.7294);
	glTranslatef(18.0,0.0,0.0);
	glutSolidSphere(0.3,100,100);
}








void delay(){
	for(int i=0;i<1000;i++)for(int j=0;j<1000;j++){}
}
void delay1(){
	for(int i=0;i<5000;i++)for(int j=0;j<1000;j++){}
}
void nameDelay(){
	for(int i=0;i<7000;i++)for(int j=0;j<1000;j++){}
}




void drawText(char a[],int n){
	char c;
	int i=0;
	float j=-7.0,k=10.0;
	for(c=a[i];i<n;i++){
		if(j>23.0){
			j++;
		}
		glRasterPos3f(j,k++,0.0);
		glutBitmapCharacter(currentfont,c);
		delay1();
		glFlush();
	}
}

void drawstring(float x,float y,float z,char *string){
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}

void setFont(void *font){
		currentfont=font;
}




void display1(){
	glClearColor(0.3529,0.3525,0.3647,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	sun();
	earth();
	DarkMoon();
	moon();

	glFlush();
	delay();
	glFlush();
}

void display2Sun(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9882,1.0,0.0392);
	glTranslatef(25.0,0.0,0.0);
	glutSolidSphere(4.0,200,100);
}

void display2Moon(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9803,0.9803,0.9803);
	glTranslatef(9.0,0.9,0.0);
	glutSolidSphere(0.9,100,100);
}

void display2Earth(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.4901,0.8117,0.6705);
	glTranslatef(0.0,0.0,0.0);
	glutSolidSphere(2.0,100,100);
}











void display2(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	display2Sun();
	display2Moon();
	display2Earth();
	glFlush();
}
void bigSun(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9882,1.0,0.0392);
	glTranslatef(-15.0,0.0,0.0);
	glutSolidSphere(7.0,200,100);
}

void bigEarth(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.4901,0.8117,0.6705);
	glTranslatef(10,0.0,0.0);
	glutSolidSphere(3.0,100,100);
}

void bigLines(){
	glLoadIdentity();
	glBegin(GL_LINES);
		glColor3f(1.0,1.0,1.0);
		//for circle
		float x=0.0,y=0.0;
		for(int i=0;i<720;i+=2.0){
			x=10.0-9.0*cos(i*PI/360);
			y=0+9.0*sin(i*PI/360);
			glVertex3f(x,y,0.0);
		}
	glEnd();
}

void bigMoon(){
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9803,0.9803,0.9803);
	glutSolidSphere(1.1,100,100);
}

void bigShadows(){

	glLoadIdentity();
	//penumbra
	glBegin(GL_POLYGON);
		glColor4f(0.0,0.0,0.0,0.3);
		glVertex3f(30.0,10.6,0.0);
		//for curving
		float x=0.0,y=0.0;
		for(int i=110;i<250;i++){
			x=9.1-1.36*cos(i*PI/180);
			y=0+3.2*sin(i*PI/180);
			glVertex3f(x,y,1.0);
		}
		glVertex3f(30,-10.6,0.0);
	glEnd();

	//umbra
	glBegin(GL_POLYGON);
		glColor4f(0.0,0.0,0.0,0.6);
		glVertex3f(30.0,1.3,0.0);
		//for curving
		for(int i=110;i<250;i++){
			x=9.1-1.36*cos(i*PI/180);
			y=0+3.2*sin(i*PI/180);
			glVertex3f(x,y,1.0);
		}
		glVertex3f(30,-1.3,0.0);
	glEnd();
}

void bigLines1(){
	//shadows
	bigShadows();

	glLineWidth(2.0);
	glColor3f(1.0,1.0,1.0);
	//short lines lower ones
	glLoadIdentity();
	glTranslatef(-9.3,4.0,0.0);
	glRotatef(-20.5,0.0,0.0,1.0);
	glTranslatef(9.3,-4.0,0.0);
	glBegin(GL_LINES);
		glVertex3f(-9.4,4.0,0.0);
		glVertex3f(35.0,4.0,0.0);
	glEnd();
	glLoadIdentity();
	glTranslatef(-9.3,-4.0,0.0);
	glRotatef(20.5,0.0,0.0,1.0);
	glTranslatef(9.3,4.0,0.0);
	glBegin(GL_LINES);
		glVertex3f(-9.4,-4.0,0.0);
		glVertex3f(35.0,-4.0,0.0);
	glEnd();

	//long lines upper ones
	glLoadIdentity();
	glTranslatef(-9.8,4.7,0.0);
	glRotatef(-4.8,0.0,0.0,1.0);
	glTranslatef(9.8,-4.7,0.0);
	glBegin(GL_LINES);
		glVertex3f(-9.8,4.7,0.0);
		glVertex3f(35.0,4.7,0.0);
	glEnd();
	glLoadIdentity();
	glTranslatef(-9.8,-4.7,0.0);
	glRotatef(4.8,0.0,0.0,1.0);
	glTranslatef(9.8,4.7,0.0);
	glBegin(GL_LINES);
		glVertex3f(-9.8,-4.7,0.0);
		glVertex3f(35.0,-4.7,0.0);
	glEnd();

	//total lunar eclipse
	glLoadIdentity();
	glColor3f(0.8235,0.027,0.549);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(23.5,-7.1,0.0,"TOTAL");
	drawstring(23.5,-7.8,0.0,"LUNAR ECLIPSE");
}




void display5(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	bigSun();
	bigEarth();
	bigLines();
	glFlush();
}

void display4Sun(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9882,1.0,0.0392);
	glTranslatef(10,0.0,0.0);
	glutSolidSphere(2.0,100,100);

	glLoadIdentity();
	glLineWidth(4.0);
	glBegin(GL_LINE_STRIP);
		//for circle
		float x=0.0,y=0.0;
		for(int i=0;i<720;i+=1.0){
			x=10.0-2.5*cos(i*PI/360);
			y=0+2.5*sin(i*PI/360);
			glVertex3f(x,y,0.0);
		}
	glEnd();
}

void display4Earth(){
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.4901,0.8117,0.6705);
	glutSolidSphere(1.2,100,100);
	glBegin(GL_LINES);
		glColor3f(1.0,1.0,1.0);
		//for circle
		float x=0.0,y=0.0;
		for(int i=0;i<720;i+=3.0){
			x=0-2.5*cos(i*PI/360);
			y=0+2.5*sin(i*PI/360);
			glVertex3f(x,y,0.0);
		}
	glEnd();
}

void display4Moon(){
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9803,0.9803,0.9803);
	glutSolidSphere(0.3,100,100);
}

void node(){
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.8235,0.027,0.549);
	glutSolidSphere(0.3,100,100);
}

void  nodeswithline(){
	//nodes
	glRotatef(30.0,0.0,0.0,1.0);
	glTranslatef(-2.5,0.0,0.0);
	//line between nodes
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(5.0,0.0,0.0);
	glEnd();
	node();
	glTranslatef(5.0,0.0,0.0);
	node();
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(0.5,0.0,0.0,"NODES");
}

void display4EarthAnimate(){
	display4Earth();
	nodeswithline();
}

void zoomSun(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9882,1.0,0.0392);
	glTranslatef(5.0,-3.0,0.0);
	glutSolidSphere(3.0,100,100);
	glLoadIdentity();
	glLineWidth(4.0);
	glBegin(GL_LINE_STRIP);
		//for circle
		float x=0.0,y=0.0;
		for(int i=0;i<720;i+=1.0){
			x=5.0-3.5*cos(i*PI/360);
			y=-3.0+3.5*sin(i*PI/360);
			glVertex3f(x,y,0.0);
		}
	glEnd();
	glLineWidth(2.0);
	glLoadIdentity();
	glBegin(GL_LINES);
		glColor3f(1.0,1.0,1.0);
		//for circle
		for(int i=0;i<720;i+=2.0){
			x=5.0-13.0*cos(i*PI/360);
			y=-3.0+13.0*sin(i*PI/360);
			glVertex3f(x,y,0.0);
		}
	glEnd();
}

void zoomEarth(){
	//line between sun and earth
	glLoadIdentity();
	glLineWidth(4.0);
	glColor3f(0.9882,1.0,0.0392);
	glBegin(GL_LINES);
		glVertex3f(5.0,-3.0,0.0);
		glVertex3f(15.0,5.0,0.0);
	glEnd();
	glLineWidth(1.0);
	float x=0.0,y=0.0;
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.4901,0.8117,0.6705);
	glTranslatef(15,5.0,0.0);
	glutSolidSphere(1.7,100,100);
	glLineWidth(2.0);
	glLoadIdentity();
	glBegin(GL_LINES);
		glColor3f(1.0,1.0,1.0);
		//for circle
		for(int i=0;i<720;i+=2.0){
			x=15.0-3.0*cos(i*PI/360);
			y=5.0+3.0*sin(i*PI/360);
			glVertex3f(x,y,0.0);
		}
	glEnd();

	//Line between nodes
	glLineWidth(2.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(12.7,3.2,0.0);
		glVertex3f(17.3,6.8,0.0);
	glEnd();

	glColor3f(0.8235,0.027,0.549);
	//node 1
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glTranslatef(12.65,3.15,0.0);
	glutSolidSphere(.4,100,100);
	//node 2
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glTranslatef(17.35,6.85,0.0);
	glutSolidSphere(.4,100,100);
}

void zoomSmallMoon(){
	glColor3f(0.9803,0.9803,0.9803);
	glBindTexture(GL_TEXTURE_2D,8);
	glutSolidSphere(.4,100,100);
}

void zoomMoon(){
	//solar eclipse
	float x=0.0,y=0.0;
	for(int i=0;i<438;i+=2.0){
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		zoomSun();
		zoomEarth();
		glLoadIdentity();
		x=15.0+3.0*cos(i*PI/360);
		y=5.0+3.0*sin(i*PI/360);
		glTranslatef(x,y,0.0);
		zoomSmallMoon();
		glFlush();
		nameDelay();
	}
	nameDelay();
	glLoadIdentity();
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(6.0,5.0,0.0,"SOLAR ECLIPSE");
	glLoadIdentity();
	glColor4f(0.0,0.0,0.0,0.5);
	glBindTexture(GL_TEXTURE_2D,8);
	glTranslatef(14.5,4.6,0.0);
	glutSolidSphere(.4,100,100);
	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(14.2,4.7,0.0);
		glVertex3f(10.5,5.2,0.0);
	glEnd();
	glFlush();
	for(int s=0;s<40;s++)nameDelay();

	//lunar elipse
	for(int i=438;i<798;i+=2.0){
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		zoomSun();
		zoomEarth();
		glLoadIdentity();
		x=15.0+3.0*cos(i*PI/360);
		y=5.0+3.0*sin(i*PI/360);
		glTranslatef(x,y,0.0);
		zoomSmallMoon();
		glFlush();
		nameDelay();
	}
	nameDelay();
	glLoadIdentity();
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(20,5.0,0.0,"LUNAR ECLIPSE");
	glLoadIdentity();
	glColor4f(0.0,0.0,0.0,0.5);
	glBindTexture(GL_TEXTURE_2D,8);
	glTranslatef(17.35,6.85,0.0);
	glutSolidSphere(.4,100,100);
	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(17.35,6.9,0.0);
		glVertex3f(19.5,5.2,0.0);
	glEnd();
	glFlush();
	for(int s=0;s<100;s++)nameDelay();
}

void display4Animation(){
	float x,y;
	for(int i=180,j=-90;i<420;i+=2.0,j+=1.0){
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		display4Sun();
		glLineWidth(2.0);
		bigLines();
		x=10.0-9.0*cos(i*PI/360);
		y=0-9.0*sin(i*PI/360);
		glTranslatef(x,y,0.0);
		display4EarthAnimate();
		glLoadIdentity();
		glLineWidth(3.0);
		glColor3f(0.9882,1.0,0.0392);
		glTranslatef(10,0.0,0.0);
		glRotatef(j,0.0,0.0,1.0);
		glTranslatef(-10.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex3f(10.0,0.0,0.0);
			glVertex3f(19.0,0.0,0.0);
		glEnd();
		glFlush();
		nameDelay();
	}
	nameDelay();
	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(20.0,1.5,0.0,"LINED UP WITH THE SUN");
	glFlush();
	for(int s=0;s<100;s++)nameDelay();

	//zooming
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	zoomMoon();
}

void display4(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	display4Animation();
}
void  display3Earth(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.4901,0.8117,0.6705);
	glTranslatef(15,0.0,0.0);
	glutSolidSphere(1.2,100,100);
}

void display3Sun(){
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D,8);
	glColor3f(0.9882,1.0,0.0392);
	glTranslatef(0.0,3.0,0.0);
	glutSolidSphere(1.2,200,100);
}

void surfaces(){
	glLoadIdentity();
	glColor4f(0.5,0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex3f(0.0,3.0,0.0);
		glVertex3f(20.0,3.0,0.0);
		glVertex3f(25,-4.0,0.0);
		glVertex3f(-5.0,-4.0,0.0);
	glEnd();
	glTranslatef(5.0,3.0,0.0);
	glRotatef(30,0.0,0.0,1.0);
	glTranslatef(-5.0,-3.0,0.0);
	glColor4f(1.0,1.0,1.0,0.5);
	glBegin(GL_POLYGON);
		glVertex3f(5.0,3.0,0.0);
		glVertex3f(15.0,3.0,0.0);
		glVertex3f(20,-4.0,0.0);
		glVertex3f(0.0,-4.0,0.0);
	glEnd();
}

void display3Moon(){
	display3Sun();
	surfaces();
}

void display3(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	display3Moon();
}

void text1(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(0.0,0.0,0.0,"A SOLAR ECLIPSE HAPPENS WHEN THE MOON'S SHADOW FALLS ON THE EARTH.");
	drawstring(-1.0,-1.0,0.0,"THE LUNAR ECLIPSE IS THE OPPOSITE,WHEN THE EARTH'S SHADOW FALLS ON THE MOON.");
	glFlush();
	for(int i=0;i<10;i++)nameDelay();
}



void text3(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glColor3f(1.0,1.0,1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);

	glFlush();
}

void text4(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);

	glFlush();
}

void text5(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(8.0,0.0,0.0,"THANK YOU");
	glFlush();
}

void display(){
	text1();
	display1();
	display2();
	text3();
	display4();
	//display3();
	text4();
	display5();
	text5();
	glFlush();
}

void splashScreen(){
	for(int i=0;i<30;i++){
		glTranslatef((float)rand()/((float)(RAND_MAX)/30.0),(float)rand()/((float)(RAND_MAX)/20.0),0);
		glColor4f((float)rand()/(float)(RAND_MAX),(float)rand()/(float)(RAND_MAX),(float)rand()/(float)(RAND_MAX),0.4);
		glBegin(GL_POLYGON);
			glVertex3f(-1.0,-1.0,0.0);
			glVertex3f(-1.0,1.0,0.0);
			glVertex3f(1.0,1.0,0.0);
			glVertex3f(1.0,-1.0,0.0);
		glEnd();
		glFlush();
		delay1();
	}
	for(int i=0;i<300;i++)nameDelay();
}

void details(){
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(.1111,.1111,.1111,1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(5.0,7.0,0.0,"Daffodil International University");
	drawstring(1.0,6.0,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	drawstring(6.0,4.0,0.0,"A MINI PROJECT ON");
	drawstring(3.0,3.0,0.0,"Eclipse ");
	drawstring(-2.0,-2.0,0.0,"BY ");
	drawstring(-4.0,-3.0,0.0,"MD. Rakin Ahmed");
	drawstring(-4.0,-4.0,0.0,"ID : 151-15-5260");
	drawstring(19.0,-2.0,0.0,"Submitted to. ");
	drawstring(16.0,-3.0,0.0,"Annita Tahsin Pryoti");
	drawstring(16.0,-4.0,0.0,"Lecturer- Daffodil International University");
	glFlush();
	for(int i=0;i<10;i++)nameDelay();
}

void mydisplay(){
	//splashScreen();
	details();
	display();
}

void reshape(int w,int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0,30.0,-10.0,10.0,-10.0,10.0);
	float ratio1=(float)w/(float)h,ratio2=(float)h/(float)w;
	/*if(w>h)
		glOrtho(-1.0,3.0*ratio1,-1.0,1.0*ratio1,-1.0,1.0);
	else
		glOrtho(-1.0,3.0*ratio2,-1.0,1.0*ratio2,-1.0,1.0);*/
	/*if(w>h)
		glOrtho(0,ScreenSizeX*((float)w/(float)h),0,ScreenSizeY*((float)w/(float)h),-10,10);
	else
		glOrtho(0,ScreenSizeX*((float)h/(float)w),0,ScreenSizeY*((float)h/(float)w),-10,10);*/
	glMatrixMode(GL_MODELVIEW);
}

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0,30.0,-10.0,10.0,-10.0,10.0);
}

void menuOption(int id){
	if(id==1) display();
	if(id==2) exit(0);
}

int main(){
	//glutPositionWindow(0,0);
	glutInitWindowSize(1366,683);
	//glutInitDisplayMode(GLUT_SINGLE|GL_RGB|GL_DEPTH);
	glutCreateWindow("Mini Project");
	init();
	glutDisplayFunc(mydisplay);
	glutReshapeFunc(reshape);
	int menuOptions=glutCreateMenu(menuOption);
	glutAddMenuEntry("Replay",1);
	glutAddMenuEntry("Exit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	//glEnable(GL_DEPTH_TEST);
	glClearColor(0.3529,0.3525,0.3647,1);
	glutMainLoop();
}
