#include <iostream>
#include<cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<vector>
#define PI          3.141516
#include<math.h>
using namespace std ;

GLint time = 1;
GLboolean light = false;
GLboolean rive = false;
GLfloat position = 0.0f;
GLfloat busposition = -0.5f;
GLfloat carposition = 0.0f;
GLfloat carposition2 = -0.99f;
GLfloat plane_position = 0.0f;
GLfloat plane_speed = 0.010f;
GLfloat RoadHumanNearEscPosition = 0.0f;
GLfloat EscHumanPositionX = 0.0f;
GLfloat EscHumanPositionY = 0.0f;
GLfloat speed = 0.050f;
GLfloat busspeed = 0.02f;
GLfloat cloudespeed = 0.015f;
GLfloat cloudposition =-0.5f;
GLfloat carspeed = 0.02f;
GLfloat carSmokeSpeed = 0.008f;
GLfloat RoadHumanRightmostSpeed = 0.006f;
GLfloat RoadHumanNearEscSpeed = 0.002f;
GLfloat positions = 0.0f;
GLfloat speeds = 0.02f;
GLfloat positionb = 0.0f;
GLfloat speedb = 0.001f;
GLfloat positionship = 0.0f;
GLfloat positionboat = 0.0f;
GLfloat speedboat = 0.04f;
GLfloat playerspeed = 0.006f;
GLfloat playerpos = 0.05f;
GLfloat footballx = 0.0f;
GLfloat footbally = 0.0f;
GLfloat footballs = 0.02f;
GLfloat fanrotate = 0.0f;
GLfloat slrortate = 0.0f, slfactor = 3.0f;

//Hridoy suru
void update(int value)
{
    ///sun
    if(positions <-1.0)
        positions = 1.0f;

    positions -= speeds;

    ///train
    if (position < -2.0f)
        position = 2.0f;

    position -= speed;
///ship
    if (positionb < -2.0)
        positionb = 2.0f;

    positionb -= speedb;

///boat
    if (positionboat < -2.0)
        positionboat = 2.0f;

    positionboat -= speedboat;


    ///plane
    if(plane_position >+1.0)
        plane_position = -1.0f;
    plane_position += plane_speed;




    ///bus
    if (busposition < -1.4)

        busposition = 1.4f;

    if ( busposition < 0.0-0.5 && busposition >-0.0-0.5 )
    {
        busposition -= 0.001;
    }

    else
        busposition -= busspeed;

///car 1
    if (carposition > 1.4)
        carposition = -1.4f;
    carposition += carspeed;
///Car 2
    if (carposition2 > 1.4)
        carposition2 = -1.4f;

    carposition2 += carspeed;

    ///cloud
    if (cloudposition > 1.4)
        cloudposition = -1.4f;
    cloudposition += cloudespeed;
    ///players
    if(playerpos > 0.05f || playerpos < -0.05)
    {
        playerspeed *= -1;
    }
    playerpos += playerspeed;

///Football
    if(footballx > 0.4f || footballx < 0.0f)
    {
        footballs *= -1;
    }
    footballx += footballs;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}


void sky() //e
{
    glBegin(GL_POLYGON);
    glColor3ub(133,186,228);
    glVertex2f(-1.00f,1.00f);
    glVertex2f(1.00f,1.00f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(-1.00f,0.765f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(166,204,236);;
    glVertex2f(-1.00f,0.765f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(-1.00f,0.635185f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(190,218,241);
    glVertex2f(-1.00f,0.635185f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(-1.00f,0.468518f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(208,228,244);
    glVertex2f(-1.00f,0.468518f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(0.996875f,0.157407f);
    glVertex2f(-0.996875f,0.157407f);
    glEnd();
}

void sun1()//e
{
    glPushMatrix();
    glTranslatef(0.0f,positions, 0.0f);


    GLfloat x=-0.772917f;
    GLfloat y=0.859259f;
    GLfloat radius =.145f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub (255,201,55);
    glVertex2f(x, y); // center of circle
    for(int q= 0; q<= triangleAmount; q++)
    {
        glVertex2f( x + (radius * cos(q *  twicePi / triangleAmount)),
                    y + (radius * sin(q * twicePi / triangleAmount)) );
    }
    glEnd();




    glPopMatrix();
}
void sun2()//e
{
    glPushMatrix();
    glTranslatef(0.0f,positions, 0.0f);


    GLfloat x=-0.772917f;
    GLfloat y=0.859259f;
    GLfloat radius =.14f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub (251,447,208);
    glVertex2f(x, y); // center of circle
    for(int q= 0; q<= triangleAmount; q++)
    {
        glVertex2f( x + (radius * cos(q *  twicePi / triangleAmount)),
                    y + (radius * sin(q * twicePi / triangleAmount)) );
    }
    glEnd();




    glPopMatrix();
}


//plane
void plane()//e
{
    glPushMatrix();

    glTranslated(0.0,0.65,0.0);
    glScaled(1.,2,0.0);
    glTranslatef(plane_position,0.0,0.0);
    glBegin(GL_POLYGON);           //Airplane
    glColor3f(0.80f, 0.90f, 0.70f);
    glVertex2f(0.0,.03);
    glVertex2f(0.0,.055);
    glVertex2f(.135,.055);
    glVertex2f(.1350,.03);
    glEnd();




    glBegin(GL_POLYGON);  // upper triangle
    glColor3f(1.0,.0,1.0);
    glVertex2f(.135,.055);
    glVertex2f(.15,.05);
    glVertex2f(.155,.045);
    glVertex2f(.16,.04);
    glVertex2f(.135,.04);
    glEnd();

    glBegin(GL_POLYGON);//lower triangle
    glColor3f(.60,0.0,0.0);
    glVertex2f(.1350,.0400);
    glVertex2f(.1600,.0400);
    glVertex2f(.1600,.0370);
    glVertex2f(.1450,.0300);
    glVertex2f(.1350,.0300);
    glEnd();

    glBegin(GL_POLYGON);//back wing
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,.0550);
    glVertex2f(0.0,.0800);
    glVertex2f(.0100,.0800);
    glVertex2f(.0400,.0550);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);//up wing
    glVertex2f(.0650,.0550);
    glVertex2f(.0500,.0700);
    glVertex2f(.0750,.0700);
    glVertex2f(.0900,.0550);
    glEnd();

    glBegin(GL_POLYGON);//down wing
    glColor3f(1.0,0.0,0.0);
    glVertex2f(.0700,.0400);
    glVertex2f(.1000,.0400);
    glVertex2f(.0800,.0150);
    glVertex2f(.0500,.0150);

    glEnd();

    glPopMatrix();
}
//plane


void river() //hridoy
{
    glBegin(GL_POLYGON);
    glColor3ub(37, 51, 77);
    if(!rive)
    {
        glColor3ub(54, 107, 151);
    }
    glVertex2f(-1.0f, 0.50f);
    glVertex2f(1.0f, 0.62f);
    glVertex2f(1.0f, 0.075f);
    glVertex2f(-1.0f, -0.15f);
    glEnd();
}


void moon()//e
{

    glPushMatrix();
    glTranslatef(0.0f,positions, 0.0f);
    GLfloat x = -0.88;
    GLfloat y = 0.8;
    GLfloat radius = 0.12   ;
    int triangleAmount = 200;
    GLfloat twicePi = 2.0f * PI;
    glColor3ub(193, 209, 224);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
}


void building5()//z
{
    glBegin(GL_POLYGON);                  /// Building 5
    glColor3ub(223, 223, 223);
    glVertex2f(-0.31f, 0.60f);
    glVertex2f(0.02f, 0.6f);
    glVertex2f(0.03f, -0.60f);
    glVertex2f(-0.31f, -0.60f);
    glEnd();




    //window 1
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.28f, 0.48f);
    glVertex2f(-0.16f, 0.48f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.28f, 0.34f);
    glEnd();

    //window 2
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.14f, 0.48f);
    glVertex2f(-0.02f, 0.48f);
    glVertex2f(-0.02f, 0.34f);
    glVertex2f(-0.14f, 0.34f);
    glEnd();

    //window 3
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.28f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glVertex2f(-0.16f, 0.12f);
    glVertex2f(-0.28f, 0.12f);
    glEnd();

    //window 4
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.14f, 0.26f);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.12f);
    glVertex2f(-0.14f, 0.12f);
    glEnd();

    //window 5
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.28f, 0.04f);
    glVertex2f(-0.16f, 0.04f);
    glVertex2f(-0.16f, -0.10f);
    glVertex2f(-0.28f, -0.10f);
    glEnd();
    //window 6
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.14f, 0.04f);
    glVertex2f(-0.02f, 0.04f);
    glVertex2f(-0.02f, -0.10f);
    glVertex2f(-0.14f, -0.10f);
    glEnd();

    //window 7
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.28f, -0.18f);
    glVertex2f(-0.16f, -0.18f);
    glVertex2f(-0.16f, -0.32f);
    glVertex2f(-0.28f, -0.32f);
    glEnd();

    //window 8
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.14f, -0.18f);
    glVertex2f(-0.02f, -0.18f);
    glVertex2f(-0.02f, -0.32f);
    glVertex2f(-0.14f, -0.32f);
    glEnd();

    //DOOR
    glBegin(GL_POLYGON);
    glColor3ub(89, 29, 0);                 //
    glVertex2f(-0.22f, -0.39f);
    glVertex2f(-0.04f, -0.39f);
    glVertex2f(-0.04f, -0.53f);
    glVertex2f(-0.22f, -0.53f);
    glEnd();
}


void building4()//z
{
    //Building 4 Main body
    //building
    glBegin(GL_POLYGON);
    glColor3ub(80,82, 69); // big
    glVertex2f(-0.0666667f,0.485185f);
    glVertex2f(0.178125f,0.483333f);
    glVertex2f(0.177083f,-0.411111f);
    glVertex2f(-0.0677083f,-0.412963f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,82, 69); // buildingg border problem
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.0760417f,0.542593f);
    glVertex2f(0.185417f,0.542593f);
    glVertex2f(0.186458f,0.483333f);
    glVertex2f(-0.0760417f,0.483333f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square1
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.053125f,0.444444f);
    glVertex2f(0.00416667f,0.444444f);
    glVertex2f(0.00416667f,0.35f);
    glVertex2f(-0.053125f,0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square2
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.0260417f,0.442593f);
    glVertex2f(0.0833333f,0.442593f);
    glVertex2f(0.0833333f,0.35f);
    glVertex2f(0.0260417f,0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square3
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.101042f,0.444444f);
    glVertex2f(0.158333f,0.444444f);
    glVertex2f(0.158333f,0.35f);
    glVertex2f(0.101042f,0.35f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square4
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.053125f,0.312963f);
    glVertex2f(0.00520833f,0.314815f);
    glVertex2f(0.00520833f,0.22037f);
    glVertex2f(-0.0520833f,0.218519f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square5
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.0260417f,0.312963f);
    glVertex2f(0.0833333f,0.312963f);
    glVertex2f(0.0833333f,0.22037f);
    glVertex2f(0.0260417f,0.218519f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square6
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.101042f,0.312963f);
    glVertex2f(0.158333f,0.312963f);
    glVertex2f(0.159375f,0.22037f);
    glVertex2f(0.101042f,0.22037f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square7
    glVertex2f(-0.053125f,0.174074f);
    glVertex2f(0.003125f,0.172222f);
    glVertex2f(0.00416667f,0.0814815f);
    glVertex2f(-0.053125f,0.0814815f);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square8
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.0260417f,0.174074f);
    glVertex2f(0.0833333f,0.172222f);
    glVertex2f(0.0833333f,0.0814815f);
    glVertex2f(0.0260417f,0.0814815f);


    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square9
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.102083f,0.172222f);
    glVertex2f(0.157292f,0.172222f);
    glVertex2f(0.158333f,0.0814815f);
    glVertex2f(0.102083f,0.0814815f);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square10
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.0510417f,0.0407407f);
    glVertex2f(0.00416667f,0.0407407f);
    glVertex2f(0.00416667f,-0.0481481f);
    glVertex2f(-0.0510417f,-0.0481481f);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square13
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.0510417f,-0.0981481f);
    glVertex2f(0.00416667f,-0.0981481f);

    glVertex2f(0.00520833f,-0.187037f);
    glVertex2f(-0.0510417f,-0.188889f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square14
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.0270833f,-0.0962963f);
    glVertex2f(0.0833333f,-0.0962963f);

    glVertex2f(0.0833333f,-0.187037f);
    glVertex2f(0.0270833f,-0.187037f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square15
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.102083f,-0.0962963f);
    glVertex2f(0.159375f,-0.0962963f);
    glVertex2f(0.159375f,-0.187037f);
    glVertex2f(0.102083f,-0.188889f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // square16
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(-0.0520833f,-0.235185f);
    glVertex2f(0.00520833f,-0.235185f);
    glVertex2f(0.00520833f,-0.327778f);
    glVertex2f(-0.0520833f,-0.327778f);
    glEnd();





    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(11,11,4);
    glVertex2f(0.0125f,-0.407407f);
    glVertex2f(0.0885417f,-0.409259f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(11,11,4);
    glVertex2f(0.0885417f,-0.409259f);
    glVertex2f(0.0895833f,-0.264815f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(11,11,4);
    glVertex2f(0.0895833f,-0.264815f);
    glVertex2f(0.0104167f,-0.264815f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(11,11,4);
    glVertex2f(0.0104167f,-0.264815f);
    glVertex2f(0.0114583f,-0.407407f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(11,11,4);
    glVertex2f(0.05f,-0.268519f);
    glVertex2f(0.05f,-0.405556f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(161,207,230); // 18
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.101042f,-0.235185f);
    glVertex2f(0.158333f,-0.235185f);
    glVertex2f(0.158333f,-0.32963f);
    glVertex2f(0.101042f,-0.32963f);

    glEnd();

}

void building3()//z
{
    glBegin(GL_POLYGON);                    //
    glColor3ub(164, 164, 164);
    glVertex2f(0.40f, 0.56f);
    glVertex2f(0.59f, 0.56f);
    glVertex2f(0.59f, -0.59f);
    glVertex2f(0.40f, -0.59f);
    glEnd();

    //windows 1
    glBegin(GL_POLYGON);                    //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.45f, 0.42f);
    glVertex2f(0.53f, 0.42f);
    glVertex2f(0.53f, 0.33f);
    glVertex2f(0.45, 0.33f);
    glEnd();

    //windows 2
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.45f, 0.22f);
    glVertex2f(0.53f, 0.22f);
    glVertex2f(0.53f, 0.13f);
    glVertex2f(0.45f, 0.13f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.45f, 0.02f);
    glVertex2f(0.53f, 0.02f);
    glVertex2f(0.53f, -0.08f);
    glVertex2f(0.45f, -0.08f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.45f, -0.18f);
    glVertex2f(0.53f, -0.18f);
    glVertex2f(0.53f, -0.27f);
    glVertex2f(0.45f, -0.27f);
    glEnd();

    //windows 4
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.45f, -0.38f);
    glVertex2f(0.53f, -0.38f);
    glVertex2f(0.53f, -0.47f);
    glVertex2f(0.45f, -0.47f);
    glEnd();
}

void building2()//z
{
    glBegin(GL_POLYGON);                //
    glColor3ub(223, 223, 223);
    glVertex2f(0.55f, 0.88f);
    glVertex2f(0.82f, 0.88f);
    glVertex2f(0.82f, -0.59f);
    glVertex2f(0.55f, -0.59f);
    glEnd();

    //windows 1
    glBegin(GL_POLYGON);                //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.58f, 0.68f);
    glVertex2f(0.66f, 0.68f);
    glVertex2f(0.66f, 0.55f);
    glVertex2f(0.58f, 0.55f);
    glEnd();

    //windows 2
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.70f, 0.68f);
    glVertex2f(0.78f, 0.68f);
    glVertex2f(0.78f, 0.55f);
    glVertex2f(0.70f, 0.55f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.58f, 0.48f);
    glVertex2f(0.66f, 0.48f);
    glVertex2f(0.66f, 0.35f);
    glVertex2f(0.58f, 0.35f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.70f, 0.48f);
    glVertex2f(0.78f, 0.48f);
    glVertex2f(0.78f, 0.35f);
    glVertex2f(0.70f, 0.35f);
    glEnd();

    //windows 5

    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.58f, 0.28f);
    glVertex2f(0.66f, 0.28f);
    glVertex2f(0.66f, 0.15f);
    glVertex2f(0.58f, 0.15f);
    glEnd();

    //windows 6
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.70f, 0.28f);
    glVertex2f(0.78f, 0.28f);
    glVertex2f(0.78f, 0.15f);
    glVertex2f(0.70f, 0.15f);
    glEnd();

    //windows 7
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.58f, 0.08f);
    glVertex2f(0.66f, 0.08f);
    glVertex2f(0.66f, -0.05f);
    glVertex2f(0.58f, -0.05f);
    glEnd();
    //windows 8
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.70f, 0.08f);
    glVertex2f(0.78f, 0.08f);
    glVertex2f(0.78f, -0.05f);
    glVertex2f(0.70f, -0.05f);
    glEnd();

    //windows 7
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.58f, -0.12f);
    glVertex2f(0.66f, -0.12f);
    glVertex2f(0.66f, -0.25f);
    glVertex2f(0.58f, -0.25f);
    glEnd();
    //windows 8
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.70f, -0.12f);
    glVertex2f(0.78f, -0.12f);
    glVertex2f(0.78f, -0.25f);
    glVertex2f(0.70f, -0.25f);
    glEnd();
    //windows 9
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.58f, -0.32f);
    glVertex2f(0.66f, -0.32f);
    glVertex2f(0.66f, -0.45f);
    glVertex2f(0.58f, -0.45f);
    glEnd();
    //windows 10
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.70f, -0.32f);
    glVertex2f(0.78f, -0.32f);
    glVertex2f(0.78f, -0.45f);
    glVertex2f(0.70f, -0.45f);
    glEnd();
}

void building1()//z
{
    glBegin(GL_POLYGON);
    glColor3ub(193, 193, 193);         //
    glVertex2f(0.82f, 0.69f);
    glVertex2f(0.92f, 0.69f);
    glVertex2f(0.92f, -0.59f);
    glVertex2f(0.82f, -0.59f);
    glEnd();
    //windows 1
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.84f, 0.59f);
    glVertex2f(0.90f, 0.59f);
    glVertex2f(0.90f, 0.47f);
    glVertex2f(0.84f, 0.47f);
    glEnd();

    //windows 2
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.84f, 0.39f);
    glVertex2f(0.90f, 0.39f);
    glVertex2f(0.90f, 0.27f);
    glVertex2f(0.84f, 0.27f);
    glEnd();
    //windows 2
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.84f, 0.19f);
    glVertex2f(0.90f, 0.19f);
    glVertex2f(0.90f, 0.07f);
    glVertex2f(0.84f, 0.07f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.84f, -0.01f);
    glVertex2f(0.90f, 0.01f);
    glVertex2f(0.90f, -0.13f);
    glVertex2f(0.84f, -0.13f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //
    glColor3ub(255, 255, 153);
    if(!light)
    {
        glColor3ub(140, 198, 255);
    }
    glVertex2f(0.84f, -0.21f);
    glVertex2f(0.90f, -0.21f);
    glVertex2f(0.90f, -0.33f);
    glVertex2f(0.84f, -0.33f);
    glEnd();
}


void bakery()//m
{
    glBegin(GL_POLYGON); ///bakery floor roof
    glColor3ub(255, 226, 160);
    glVertex2f(-0.89375f,-0.244444f);
    glVertex2f(-0.708333f,-0.244444f);
    glVertex2f(-0.708333f,-0.259259f);
    glVertex2f(-0.89375f,-0.259259f);
    glEnd();
    glBegin(GL_POLYGON); ///bakery floor roof
    glColor3ub(255, 211, 108);
    glVertex2f(-0.89375f,-0.259259f);
    glVertex2f(-0.708333f,-0.259259f);
    glVertex2f(-0.716667f,-0.268519f);
    glVertex2f(-0.882292f,-0.268519f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery shop
    glColor3ub(250, 179, 91);
    glVertex2f(-0.882292f,-0.268519f);
    glVertex2f(-0.716667f,-0.268519f);
    glVertex2f(-0.716667f,-0.468518f);
    glVertex2f(-0.882292f,-0.468518f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery floor bound
    glColor3ub(141, 72, 30);
    glVertex2f(-0.889583f,-0.427778f);
    glVertex2f(-0.714583f,-0.427778f);
    glVertex2f(-0.714583f,-0.49163f);
    glVertex2f(-0.889583f,-0.49163f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery window
    glColor3ub(193, 241,251);
    glVertex2f(-0.876042f,-0.324074f);
    glVertex2f(-0.779167f,-0.324074f);
    glVertex2f(-0.779167f,-0.412963f);
    glVertex2f(-0.876042f,-0.412963f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery window shade
    glColor3ub(238, 94,31);
    glVertex2f(-0.876042f,-0.298148f);
    glVertex2f(-0.778125f,-0.298148f);
    glVertex2f(-0.772917f,-0.333333f);
    glVertex2f(-0.880208f,-0.333333f);
    glEnd();

    glLineWidth(3.5);///bakery window bar
    glBegin(GL_LINES);
    glColor3ub(87,109,120);
    glVertex2f(-0.873958f,-0.359259f);
    glVertex2f(-0.78125f,-0.359259f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(87,109,120);
    glVertex2f(-0.873958f,-0.381481f);
    glVertex2f(-0.78125f,-0.381481f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery door
    glColor3ub(238, 94,31);
    glVertex2f(-0.766667f,-0.327778f);
    glVertex2f(-0.729167f,-0.327778f);
    glVertex2f(-0.729167f,-0.461111f);
    glVertex2f(-0.766667f,-0.461111f);

    glEnd();
    glBegin(GL_POLYGON); ///bakery door window
    glColor3ub(132, 174,162);
    glVertex2f(-0.761458f,-0.342593f);
    glVertex2f(-0.734375f,-0.342593f);
    glVertex2f(-0.734375f,-0.405556f);
    glVertex2f(-0.761458f,-0.405556f);

    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3ub(113,89,62);
    glVertex2f(-0.746875f,-0.342593f);
    glVertex2f(-0.746875f,-0.405556f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(113,89,62);
    glVertex2f(-0.761375f,-0.372222f);
    glVertex2f(-0.734375f,-0.372222f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3ub(250, 179, 91);
    glVertex2f(-0.759375f,-0.411111f);
    glVertex2f(-0.759375f,-0.425926f);
    glEnd();



    glBegin(GL_POLYGON); ///bakery garden
    glColor3ub(145, 157,59);
    glVertex2f(-0.878125f,-0.468518f);
    glVertex2f(-0.878125f,-0.464815f);
    glVertex2f(-0.880208f,-0.446296f);
    glVertex2f(-0.880208f,-0.446296f);
    glVertex2f(-0.871875f,-0.431481f);
    glVertex2f(-0.860417f,-0.42037f);
    glVertex2f(-0.807292f,-0.438889f);
    glVertex2f(-0.798958f,-0.425926f);
    glVertex2f(-0.779167f,-0.462963f);
    glVertex2f(-0.777083f,-0.47037f);
    glEnd();
    glBegin(GL_POLYGON); ///bakery garden tub
    glColor3ub(250, 209,153);
    glVertex2f(-0.88125f,-0.466667f);
    glVertex2f(-0.776042f,-0.466667f);
    glVertex2f(-0.776042f,-0.487037f);
    glVertex2f(-0.88125f,-0.487037f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery top
    glColor3ub(242, 162,77);
    glVertex2f(-0.883333f,-0.237037f);
    glVertex2f(-0.71875f,-0.237037f);
    glVertex2f(-0.71875f,-0.181481f);
    glVertex2f(-0.883333f,-0.181481f);
    glEnd();
}




void stationRB()//m
{
    glPushMatrix();                        ////
    glTranslatef(-0.35f, 0.0, 0.0);


    glBegin(GL_POLYGON);                    ////
    glColor3ub(200, 200, 200);
    glVertex2f(-0.3f, 0.05f);
    glVertex2f(0.8f, 0.05f);
    glVertex2f(0.8f, 0.1f);
    glVertex2f(-0.3f, 0.1f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(200, 200, 200);
    glVertex2f(0.8f, 0.15f);
    glVertex2f(-0.3f, 0.15f);
    glEnd();



    glBegin(GL_POLYGON);                    ////
    glColor3ub(10,111,125);
    glVertex2f(-0.3f, 0.55f);
    glVertex2f(0.8f, 0.55f);
    glVertex2f(0.9f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();
    glPopMatrix();
}
//hridoy sesh


//moazzen suru

void stationFP()//m
{
    glPushMatrix();
    glTranslatef(-0.35f, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.15f, 0.05f);
    glVertex2f(-0.15f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.05f, 0.05f);
    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(0.5f, 0.05f);
    glVertex2f(0.45f, 0.05f);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.5f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(0.7f, 0.05f);
    glVertex2f(0.65f, 0.05f);
    glVertex2f(0.65f, 0.4f);
    glVertex2f(0.7f, 0.4f);
    glEnd();

    glPopMatrix();
}

void train()//m
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI;
    int tringle2;
    int i;
    glPushMatrix();

    glTranslatef(position, 0.0f, 0.0f);
    p1 = -0.88f;
    q1 = 0.149f;
    r1 = 0.101f; ////Left SIDE door goal blue ta
    tringle2 = 40;
    tp2 = 2.0f * PI;




    //train

    glBegin(GL_QUADS);
    glColor3ub(206,157,80);
    glVertex2f(-0.80f,0.004f);
    glVertex2f(-0.47f,0.00185185f);
    glVertex2f(-0.47f,0.18);
    glVertex2f(-0.80f,0.18f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(206,157,80);
    glVertex2f(-0.80f,0.004f);
    glVertex2f(-0.80f,0.18f);
    glVertex2f(-0.85f,0.03f);
    glVertex2f(-0.83f,0.067f);

    glEnd();
    /*
          int i;

    	GLfloat x=0.2f; GLfloat y=0.3f; GLfloat radius =.2f;
    	int triangleAmount = 100; //# of lines used to draw circle

    	//GLfloat radius = 0.8f; //radius
    	GLfloat twicePi = 2.0f * PI;

    	glColor3f(0.0f, 1.0f, 1.0f);
    	glBegin(GL_TRIANGLE_FAN);
    		glVertex2f(x, y); // center of circle
    		for(i = 0; i <= triangleAmount;i++) {
    			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                            y + (radius * sin(i * twicePi / triangleAmount)) );
    		}
    	glEnd();
    */
    glBegin(GL_QUADS);//red line
    glColor3ub(170,33,43);
    glVertex2f(-0.83f,0.0019f);
    glVertex2f(-0.47f,0.0f);
    glVertex2f(-0.47f,0.011f);
    glVertex2f(-0.84f,0.013f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(206,157,80);
    glVertex2f(-0.84f,0.013f);
    glVertex2f(-0.811458f,0.0111111f);
    glVertex2f(-0.85f,0.03f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.844792f,0.0444444f);
    glVertex2f(-0.836458f,0.0462963f);
    glVertex2f(-0.796875f,0.168519f);
    glVertex2f(-0.803125f,0.168519f);
    glEnd();

    glLineWidth(5);
    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.821875f,0.0685185f);
    glVertex2f(-0.477083f,0.0685185f);
    glEnd();
    glLineWidth(6);
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.795833f,0.144444f);
    glVertex2f(-0.478125f,0.144444f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.814583f,0.101852f);
    glVertex2f(-0.813542f,0.0685185f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.758333f,0.103704f);
    glVertex2f(-0.758333f,0.138889f);
    glVertex2f(-0.758333f,0.138889f);
    glVertex2f(-0.801042f,0.138889f);
    glVertex2f(-0.808333f,0.116667f);
    glVertex2f(-0.813542f,0.103704f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.8125f,0.0722222f);
    glVertex2f(-0.758333f,0.0703704f);
    glVertex2f(-0.758333f,0.103704f);
    glVertex2f(-0.8125f,0.103704f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.755208f,0.0703704f);
    glVertex2f(-0.75625f,0.142593f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.753125f,0.0722222f);
    glVertex2f(-0.7f,0.0722222f);
    glVertex2f(-0.7f,0.140741f);
    glVertex2f(-0.754167f,0.140741f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.697917f,0.0722222f);
    glVertex2f(-0.697917f,0.140741f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.695833f,0.0722222f);
    glVertex2f(-0.641667f,0.0722222f);
    glVertex2f(-0.641667f,0.138889f);
    glVertex2f(-0.695833f,0.138889f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.639583f,0.0722222f);
    glVertex2f(-0.639583f,0.142593f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.638542f,0.0722222f);
    glVertex2f(-0.583333f,0.0722222f);
    glVertex2f(-0.583333f,0.138889f);
    glVertex2f(-0.638542f,0.138889f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(50,42,22);
    glVertex2f(-0.58125f,0.0703704f);
    glVertex2f(-0.58125f,0.142593f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.58125f,0.0722222f);
    glVertex2f(-0.527083f,0.0722222f);
    glVertex2f(-0.527083f,0.140741f);
    glVertex2f(-0.58125f,0.140741f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.525f,0.0685185f);
    glVertex2f(-0.525f,0.140741f);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(92,120,114);
    glVertex2f(-0.522917f,0.0722222f);
    glVertex2f(-0.478125f,0.0722222f);
    glVertex2f(-0.478125f,0.140741f);
    glVertex2f(-0.522917f,0.140741f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.476042f,0.0111111f);
    glVertex2f(-0.476042f,0.149f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.477083f,0.012963f);
    glVertex2f(-0.525f,0.012963f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.525f,0.012963f);
    glVertex2f(-0.523958f,0.062963f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(162,15,33);
    glVertex2f(-0.522917f,0.0148148f);
    glVertex2f(-0.478125f,0.0148148f);
    glVertex2f(-0.478125f,0.0648148f);
    glVertex2f(-0.522917f,0.0648148f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.501042f,0.0666667f);
    glVertex2f(-0.501042f,0.0111111f);
    glVertex2f(-0.522917f,0.0648148f);
    glEnd();
//divider


    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(98,93,84);
    glVertex2f(-0.467708f,0.0111111f);
    glVertex2f(-0.467708f,0.182f);
    glEnd();



    //2nd one


    glBegin(GL_POLYGON);
    glColor3ub(162,15,33);
    glVertex2f(-0.463542f,0.00185185f);
    glVertex2f(-0.139583f,0.00185185f);
    glVertex2f(-0.139583f,0.0111111f);
    glVertex2f(-0.463542f,0.0111111f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(206,157,80);
    glVertex2f(-0.463542f,0.0111111f);
    glVertex2f(-0.139583f,0.0111111f);
    glVertex2f(-0.139583f,0.17963f);
    glVertex2f(-0.463542f,0.177778f);

    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.459375f,0.012963f);
    glVertex2f(-0.459375f,0.15f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.14375f,0.0111111f);
    glVertex2f(-0.14375f,0.148148f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.14375f,0.0685185f);
    glVertex2f(-0.459375f,0.0685185f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.14375f,0.144444f);
    glVertex2f(-0.459375f,0.144444f);
    glEnd();



    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.459375f,0.012963f);
    glVertex2f(-0.4125f,0.012963f);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.4125f,0.012963f);
    glVertex2f(-0.4125f,0.062963f);
    glEnd();



    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.4125f,0.062963f);
    glVertex2f(-0.459375f,0.062963f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.459375f,0.062963f);
    glVertex2f(-0.459375f,0.012963f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(162,15,33);
    glVertex2f(-0.458333f,0.0166667f);
    glVertex2f(-0.4125f,0.0166667f);
    glVertex2f(-0.4125f,0.062963f);
    glVertex2f(-0.458333f,0.0611111f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.435417f,0.0148148f);
    glVertex2f(-0.435417f,0.0648148f);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.190625f,0.012963f);
    glVertex2f(-0.14375f,0.012963f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.190625f,0.012963f);
    glVertex2f(-0.190625f,0.0648148f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(162,15,33);
    glVertex2f(-0.189583f,0.0166667f);
    glVertex2f(-0.144792f,0.0166667f);
    glVertex2f(-0.144792f,0.0648148f);
    glVertex2f(-0.189583f,0.0648148f);
    glEnd();



    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.166667f,0.0148148f);
    glVertex2f(-0.166667f,0.062963f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(57,86,81);
    glVertex2f(-0.190625f,0.0722222f);
    glVertex2f(-0.145833f,0.0722222f);
    glVertex2f(-0.145833f,0.140741f);
    glVertex2f(-0.190625f,0.140741f);
    glEnd();


    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.192708f,0.0722222f);
    glVertex2f(-0.192708f,0.140741f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(57,86,81);
    glVertex2f(-0.19375f,0.0722222f);
    glVertex2f(-0.19375f,0.140741f);
    glVertex2f(-0.245833f,0.140741f);
    glVertex2f(-0.245833f,0.0722222f);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.246875f,0.0722222f);
    glVertex2f(-0.246875f,0.142593f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.302083f,0.0722222f);
    glVertex2f(-0.302083f,0.144444f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(57,86,81);
    glVertex2f(-0.301042f,0.0722222f);
    glVertex2f(-0.248958f,0.0722222f);
    glVertex2f(-0.248958f,0.140741f);
    glVertex2f(-0.301042f,0.142593f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.302083f,0.0722222f);
    glVertex2f(-0.302083f,0.144444f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.35625f,0.0722222f);
    glVertex2f(-0.35625f,0.140741f);
    glColor3ub(50,42,22);

    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(50,42,22);
    glVertex2f(-0.411458f,0.140741f);
    glVertex2f(-0.411458f,0.0722222f);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(57,86,81);
    glVertex2f(-0.458333f,0.0722222f);
    glVertex2f(-0.4125f,0.0722222f);
    glVertex2f(-0.4125f,0.140741f);
    glVertex2f(-0.458333f,0.140741f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(57,86,81);
    glVertex2f(-0.304167f,0.0722222f);
    glVertex2f(-0.304167f,0.144444f);
    glVertex2f(-0.355208f,0.140741f);
    glVertex2f(-0.355208f,0.0722222f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(57,86,81);
    glVertex2f(-0.409375f,0.0722222f);
    glVertex2f(-0.358333f,0.0722222f);
    glVertex2f(-0.358333f,0.140741f);
    glVertex2f(-0.410417f,0.140741f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(57,86,81);
    glVertex2f(-0.823958f,0.0722222f);
    glVertex2f(-0.815625f,0.0722222f);
    glVertex2f(-0.815625f,0.0981481f);
    glEnd();





    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(99,93,84);
    glVertex2f(-0.135417f,0.172222f);
    glVertex2f(-0.135417f,0.014963f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(214,165,87);
    glVertex2f(-0.13125f,0.0037037f);
    glVertex2f(0.226042f,0.0037037f);
    glVertex2f(0.183333f,0.181481f);
    glVertex2f(-0.13125f,0.17963f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(214,165,87);
    glVertex2f(0.161458f,0.0037037f);
    glVertex2f(0.230208f,0.0037037f);
    glVertex2f(0.24375f,0.0240741f);
    glVertex2f(0.24375f,0.037037f);
    glVertex2f(0.194792f,0.17963f);
    glVertex2f(0.161458f,0.17963f);
    glEnd();




    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(183,28,41);

    glVertex2f(-0.132292f,0.00555556f);
    glVertex2f(0.229167f,0.00555556f);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,28,41);
    glVertex2f(-0.127083f,0.0111111f);
    glVertex2f(-0.0802083f,0.0111111f);
    glVertex2f(-0.0802083f,0.062963f);
    glVertex2f(-0.127083f,0.062963f);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(77,16,16);


    glVertex2f(-0.127083f,0.0111111f);
    glVertex2f(-0.0802083f,0.0111111f);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(77,16,16);

    glVertex2f(-0.0802083f,0.0111111f);
    glVertex2f(-0.0791667f,0.0111111f);

    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(94,9,19);
    glVertex2f(-0.126042f,0.012963f);
    glVertex2f(-0.126042f,0.062963f);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(94,9,19);
    glVertex2f(-0.103125f,0.012963f);
    glVertex2f(-0.103125f,0.062963f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(94,9,19);
    glVertex2f(-0.126042f,0.0648148f);
    glVertex2f(-0.0791667f,0.0648148f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.127083f,0.0648148f);
    glVertex2f(-0.127083f,0.0111111f);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.0791667f,0.012963f);
    glVertex2f(-0.0791667f,0.0648148f);
    glEnd();
    glLineWidth(5);//main black line
    glBegin(GL_LINES);
    glColor3ub(0,6,3);
    glVertex2f(-0.129167f,0.0666667f);
    glVertex2f(0.228125f,0.0666667f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,6,3);
    glVertex2f(-0.128125f,0.144444f);
    glVertex2f(0.196875f,0.144444f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,6,3);
    glVertex2f(0.211458f,0.103704f);
    glVertex2f(0.211458f,0.0703704f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,6,3);
    glVertex2f(0.153125f,0.0703704f);
    glVertex2f(0.153125f,0.148148f);
    glEnd();

    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0,6,3);
    glVertex2f(-0.127083f,0.0666667f);
    glVertex2f(-0.127083f,0.15f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64,91,85);
    glVertex2f(-0.125f,0.0703704f);
    glVertex2f(0.151042f,0.0703704f);
    glVertex2f(0.151042f,0.142593f);
    glVertex2f(-0.125f,0.142593f);
    glEnd();

    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(51,74,70);
    glVertex2f(-0.102083f,0.0703704f);
    glVertex2f(-0.102083f,0.142593f);

    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(35,53,48);
    glVertex2f(-0.078125f,0.0703704f);
    glVertex2f(-0.078125f,0.142593f);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(35,53,48);
    glVertex2f(-0.0208333f,0.0703704f);
    glVertex2f(-0.0208333f,0.142593f);

    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(35,53,48);
    glVertex2f(0.0375f,0.0703704f);
    glVertex2f(0.0375f,0.142593f);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(35,53,48);
    glVertex2f(0.0947917f,0.0703704f);
    glVertex2f(0.0947917f,0.142593f);
    glEnd();


    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,4,0);
    glVertex2f(0.211458f,0.0925926f);
    glVertex2f(0.194792f,0.142593f);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(64,91,85);
    glVertex2f(0.154167f,0.0703704f);
    glVertex2f(0.210417f,0.0703704f);
    glVertex2f(0.210417f,0.0962963f);
    glVertex2f(0.194792f,0.142593f);
    glVertex2f(0.154167f,0.142593f);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,4,0);
    glVertex2f(0.236458f,0.0444444f);
    glVertex2f(0.195833f,0.164815f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(64,91,85);
    glVertex2f(0.235417f,0.0481481f);
    glVertex2f(0.240625f,0.0481481f);
    glVertex2f(0.201042f,0.164815f);
    glVertex2f(0.198958f,0.155556f);
    glEnd();


    glPopMatrix();
}
void redLights()//m
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI;
    int tringle2;
    int i;
    for(float f = 0.0f; f <= 2.0; f += 0.095)
    {
        glLineWidth(10.5);//////////////////// LIGHT BAR
        glBegin(GL_LINES);
        glColor3ub(139,0,0);
        glVertex2f(-1.0f + f,0.05f);
        glVertex2f(-1.0f + f,0.10f);
        glEnd();

        p1= -1.0f + f;
        q1= 0.10f;
        r1 = 0.015f; //// RED LIGHT circle
        tringle2=40;
        tp2 =2.0f * PI  ;
        glBegin (GL_TRIANGLE_FAN);
        glColor3ub (253,0,0);
        glVertex2f (p1,q1);
        for(i= 0; i<=tringle2; i++)
        {
            glVertex2f (
                p1+(r1*cos(i*tp2/tringle2)),
                q1+(r1*sin(i*tp2/tringle2))
            );
        }
        if(light)
        {
            p1= -1.0f + f;
            q1= 0.10f;
            r1 = 0.030f; //// RED LIGHT circle
            tringle2=40;
            tp2 =2.0f * PI  ;
            glBegin (GL_TRIANGLE_FAN);
            glColor4ub (253,0,0,100);
            glVertex2f (p1,q1);
            for(i= 0; i<=tringle2; i++)
            {
                glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                );
            }
        }
        glEnd ();
    }
}

void railline()//m
{
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79); // Rail line er first deep gray step ta
    glVertex2f(-2.0f, -0.025f);
    glVertex2f(-2.0f, 0.05f);
    glVertex2f(1.0f, 0.05f);
    glVertex2f(1.0f, -0.025f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 215, 0); // Rail line er 2nd light gray step ta
    glVertex2f(-2.0f, -0.07f);
    glVertex2f(-2.0f, -0.025f);
    glVertex2f(1.0f, -0.025f);
    glVertex2f(1.0f, -0.07f);
    glEnd();
    //////////////////////////////////  4th bridge piller  structure

    glPushMatrix();
    glTranslatef(0.4f, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller first step up to down
    glVertex2f(0.2f, -0.11f);
    glVertex2f(0.2f, -0.065f);
    glVertex2f(0.4f, -0.065f);
    glVertex2f(0.4f, -0.11f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 20, 60); // left er bridge er piller 2nd step up to down
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller 3rd step up to down
    glVertex2f(0.2f, -0.18f);
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.4f, -0.15f);
    glVertex2f(0.4f, -0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // left ar bridge er main lenth piller light gray
    glVertex2f(0.25f, -0.7f);
    glVertex2f(0.25f, -0.18f);
    glVertex2f(0.348f, -0.18f);
    glVertex2f(0.348f, -0.7f);
    glEnd();
    glPopMatrix();

}


void road()//h
{
    glBegin(GL_POLYGON); //road             //
    glColor3ub(86, 44, 44);

    glVertex2f(1.0f, -0.7f);
    glVertex2f(-2.0f, -0.7f);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///bit           //
    glColor3ub(195, 195, 195);

    glVertex2f(1.0f, -0.52f);
    glVertex2f(-2.0f, -0.52f);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glEnd();

    glLineWidth(2.5); //road track          //

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-2.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glEnd();
}


void accelerator()//m
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI;
    int tringle2    ;
    int i;                                  // human head, START
    p1=0.925f;
    q1= -0.41f;
    r1 = 0.012f;
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);               //Esc. lower square
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, -0.425f);
    glVertex2f(0.475f, -0.425f);
    glVertex2f(0.475f, -0.5f);
    glEnd();



    glBegin(GL_POLYGON);                     // Esc. angled stairway
    glColor3ub(135, 206, 250);
    glVertex2f(0.475, -0.425f);
    glVertex2f(0.2f, 0.125f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.475f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON);                     // Esc. angled stairway shadow
    glColor3ub(65, 105, 225);
    glVertex2f(0.475f, -0.5f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.46f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);                 //Esc. upper square
    glVertex2f(0.2f, 0.125f);
    glVertex2f(0.175f, 0.125f);
    glVertex2f(0.175f, 0.05f);
    glVertex2f(0.2f, 0.05f);
    glEnd();



}


void car()//h
{
    glPushMatrix();
    glTranslatef(carposition, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(64,71,71);
    glVertex2f(-0.142708f,-0.651852f);
    glVertex2f(0.1375f,-0.651852f);
    glVertex2f(0.1375f,-0.57037f);
    glVertex2f(-0.142708f,-0.57037f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(18,54,128);

    glVertex2f(0.1375f,-0.651852f);
    glVertex2f(0.173958f,-0.651852f);
    glVertex2f(0.175f,-0.594444f);
    glVertex2f(0.1375f,-0.594444f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(18,54,128);
    glVertex2f(0.1375f,-0.594444f);
    glVertex2f(0.175f,-0.594444f);
    glVertex2f(0.1375f,-0.57037f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(223,23,93);
    glVertex2f(-0.0395833f,-0.57037f);
    glVertex2f(0.0395833f,-0.57037f);
    glVertex2f(0.0395833f,-0.514815f);
    glVertex2f(-0.0395833f,-0.514815f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(223,23,93);

    glVertex2f(-0.084375f,-0.57037f);
    glVertex2f(-0.0395833f,-0.57037f);
    glVertex2f(-0.0395833f,-0.514815f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(223,23,93);
    glVertex2f(0.0395833f,-0.57037f);
    glVertex2f(0.0395833f,-0.514815f);
    glVertex2f(0.090625f,-0.57037f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(12,181,27);
    glVertex2f(-0.0354167f,-0.559259f);
    glVertex2f(-0.0166667f,-0.559259f);
    glVertex2f(-0.0166667f,-0.524074f);
    glVertex2f(-0.0354167f,-0.524074f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(12,181,27);
    glVertex2f(0.0166667f,-0.559259f);
    glVertex2f(0.0354167f,-0.559259f);
    glVertex2f(0.0354167f,-0.522222f);
    glVertex2f(0.0166667f,-0.522222f);
    glEnd();
    // Clear the color buffer (background)
    int i;

    GLfloat x=0.104167f;
    GLfloat y=-0.655556f;
    GLfloat radius =.02f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, .0f, .0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(181,176,147);
    glVertex2f(0.171875f,-0.637037f);
    glVertex2f(0.171875f,-0.648148f);
    glVertex2f(0.177083f,-0.648148f);
    glVertex2f(0.177083f,-0.637037f);

    glEnd();


    glPopMatrix();
}
///2ns tyre
void tyre2nd()//h
{
    glPushMatrix();
    glTranslatef(carposition, 0.0f, 0.0f);
    int i;

    GLfloat x=0.104167f;
    GLfloat y=-0.655556f;
    GLfloat radius =.01f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, .0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
}
void tyre()//h
{
    glPushMatrix();
    glTranslatef(carposition, 0.0f, 0.0f);

    int j;

    GLfloat p=-0.071875f;
    GLfloat q=-0.65182f;
    GLfloat Radius =.02f;
    int X= 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat TwicePi =2.0f * PI;

    glColor3f(0.0f, .0f, .0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(j= 0; j <= X; j++)
    {
        glVertex2f( p + (Radius * cos(j *  TwicePi / X)),
                    q + (Radius * sin(j * TwicePi / X)) );
    }
    glEnd();

    glPopMatrix();
}
void tyreM()//h
{
    glPushMatrix();
    glTranslatef(carposition, 0.0f, 0.0f);

    int j;

    GLfloat p=-0.071875f;
    GLfloat q=-0.65182f;
    GLfloat Radius =.01f;
    int X= 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat TwicePi =2.0f * PI;

    glColor3f(1.0f, 1.0f, .0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(j= 0; j <= X; j++)
    {
        glVertex2f( p + (Radius * cos(j *  TwicePi / X)),
                    q + (Radius * sin(j * TwicePi / X)) );
    }
    glEnd();

    glPopMatrix();
}




void car2()//h
{
    glPushMatrix();
    glTranslatef(carposition2, 0.0f, 0.0f);

    ///car
    glBegin(GL_POLYGON);
    glColor3ub(177,43,21);
    glVertex2f(-0.926042f,-0.642593f);
    glVertex2f(-0.758333f,-0.642593f);
    glVertex2f(-0.758333f,-0.568889f);
    glVertex2f(-0.926042f,-0.568889f);
    glEnd();


    glLineWidth(5);//////////////////// LIGHT BAR
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.711458f,-0.627778f);
    glVertex2f(-0.711458f,-0.577778f);
    glEnd();

    glLineWidth(5);//////////////////// LIGHT BAR
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.758333f,-0.642593f);
    glVertex2f(-0.719792f,-0.644444f);
    glEnd();
    glLineWidth(5);//////////////////// LIGHT BAR
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.719792f,-0.644444f);
    glVertex2f(-0.711458f,-0.627778f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.711458f,-0.577778f);
    glVertex2f(-0.758333f,-0.57f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(64,91,85);
    glVertex2f(-0.758333f,-0.642593f);
    glVertex2f(-0.719792f,-0.644444f);
    glVertex2f(-0.711458f,-0.627778f);
    glVertex2f(-0.711458f,-0.577778f);
    glVertex2f(-0.758333f,-0.57f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(64,91,85);
    glVertex2f(-0.901042f,-0.57f);
    glVertex2f(-0.76875f,-0.57f);
    glVertex2f(-0.8f,-0.524074f);
    glVertex2f(-0.871875f,-0.524074f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.832292f,-0.57f);
    glVertex2f(-0.832292f,-0.524074f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,212,7);
    glVertex2f(-0.86875f,-0.535f);
    glVertex2f(-0.848958f,-0.535f);
    glVertex2f(-0.848958f,-0.565f);
    glVertex2f(-0.86875f,-0.565f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(237,212,7);
    glVertex2f(-0.81875f,-0.535f);
    glVertex2f(-0.798958f,-0.535f);
    glVertex2f(-0.798958f,-0.565f);
    glVertex2f(-0.81875f,-0.565f);
    glEnd();



    int j;

    GLfloat p=-0.882292f;
    GLfloat q=-0.642593f;
    GLfloat Radius =.02f;
    int X= 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat TwicePi =2.0f * PI;

    glColor3f(.0f, .0f, .0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(j= 0; j <= X; j++)
    {
        glVertex2f( p + (Radius * cos(j *  TwicePi / X)),
                    q + (Radius * sin(j * TwicePi / X)) );
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(239,230,186);
    glVertex2f(-0.708333f,-0.627778f);
    glVertex2f(-0.704167f,-0.627778f);
    glVertex2f(-0.704167f,-0.612963f);
    glVertex2f(-0.708333f,-0.612963f);
    glEnd();
    glPopMatrix();
}
void sceondcartyre()//h
{
    glPushMatrix();
    glTranslatef(carposition2, 0.0f, 0.0f);
    int j;

    GLfloat p=-0.882292f;
    GLfloat q=-0.642593f;
    GLfloat Radius =.01f;
    int X= 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat TwicePi =2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(j= 0; j <= X; j++)
    {
        glVertex2f( p + (Radius * cos(j *  TwicePi / X)),
                    q + (Radius * sin(j * TwicePi / X)) );
    }
    glEnd();

    glPopMatrix();
}
void sceondcartyre3()//h
{
    glPushMatrix();
    glTranslatef(carposition2, 0.0f, 0.0f);
    int j;

    GLfloat p=-0.755208f;
    GLfloat q=-0.642593f;
    GLfloat Radius =.02f;
    int X= 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat TwicePi =2.0f * PI;

    glColor3f(.0f, .0f, .0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(j= 0; j <= X; j++)
    {
        glVertex2f( p + (Radius * cos(j *  TwicePi / X)),
                    q + (Radius * sin(j * TwicePi / X)) );
    }
    glEnd();

    glPopMatrix();
}
void sceondcartyre2()//h
{
    glPushMatrix();
    glTranslatef(carposition2, 0.0f, 0.0f);
    int j;

    GLfloat p=-0.755208f;
    GLfloat q=-0.642593f;
    GLfloat Radius =.01f;
    int X= 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat TwicePi =2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(j= 0; j <= X; j++)
    {
        glVertex2f( p + (Radius * cos(j *  TwicePi / X)),
                    q + (Radius * sin(j * TwicePi / X)) );
    }
    glEnd();

    glPopMatrix();
}


void busstop()//h
{
    //--------------------------------------------- Bus Stop START
    glBegin(GL_QUADS);                    // back glass
    glColor4ub(100, 149, 237, 100);
    glVertex2f(0.15f, -0.45f);
    glVertex2f(0.15f, -0.30f);
    glVertex2f(-0.05f, -0.30f);
    glVertex2f(-0.05f, -0.45f);
    glEnd();

    glLineWidth(5);                       // back borders - vertical 2
    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(0.15f, -0.5f);
    glVertex2f(0.15f, -0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(-0.05f, -0.5f);
    glVertex2f(-0.05f, -0.30f);
    glEnd();

    glBegin(GL_LINES);                // horizontal 2
    glColor3ub(105,105,105);
    glVertex2f(-0.05f, -0.45f);
    glVertex2f(0.15f, -0.45f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(-0.05f, -0.30f);
    glVertex2f(0.15f, -0.30f);
    glEnd();

    glBegin(GL_LINES);                    // middle 2
    glColor3ub(105,105,105);
    glVertex2f(0.015f, -0.45f);
    glVertex2f(0.015f, -0.30f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105,105,105);
    glVertex2f(0.085f, -0.45f);
    glVertex2f(0.085f, -0.30f);
    glEnd();

    glBegin(GL_POLYGON);                  //top cover
    glColor3ub(119, 136, 153);
    glVertex2f(0.153f, -0.30f);
    glVertex2f(0.17f, -0.25);
    glVertex2f(-0.07f, -0.25f);
    glVertex2f(-0.053f, -0.30f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);                    //bench main
    glColor3ub(255,127,80);
    glVertex2f(-0.01f, -0.47f);
    glVertex2f(0.11f, -0.47f);
    glEnd();

    glBegin(GL_LINES);                    //bench back vertical 2 grill
    glColor3ub(255,127,80);
    glVertex2f(0.015f, -0.5f);
    glVertex2f(0.015f, -0.42f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.085f, -0.5f);
    glVertex2f(0.085f, -0.42f);
    glEnd();

    glLineWidth(2);                         //bench back horizontal grills
    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.0f, -0.42f);
    glVertex2f(0.10f, -0.42f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.0f, -0.43f);
    glVertex2f(0.10f, -0.43f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.0f, -0.44f);
    glVertex2f(0.10f, -0.44f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.0f, -0.45f);
    glVertex2f(0.10f, -0.45f);
    glEnd();

    glLineWidth(3);                  // bench legs
    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.0f, -0.47f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,127,80);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, -0.47f);
    glEnd();

    glBegin(GL_LINES);                //Bus stop sign
    glColor3ub(119, 136, 153);
    glVertex2f(-0.075f, -0.5f);
    glVertex2f(-0.075f, -0.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(-0.06f, -0.4f);
    glVertex2f(-0.06f, -0.35f);
    glVertex2f(-0.09f, -0.35f);
    glVertex2f(-0.09f, -0.4f);
    glEnd();
}
//moazzen sesh

//zafir suru
void bus()//h
{
    glPushMatrix();
    glTranslatef(busposition, 0.0f, 0.0f);



    glBegin(GL_QUADS);
    glColor3ub(244,175,1);                 //Esc. upper square
    glVertex2f(-0.535417f,-0.564815f);
    glVertex2f(-0.267708f,-0.564815f);
    glVertex2f(-0.270833f,-0.401852f);
    glVertex2f(-0.523958f,-0.401852f);
    glVertex2f(-0.529167f,-0.414815f);
    glVertex2f(-0.536458f,-0.492593f);
    glEnd();

    /*glBegin(GL_QUADS);
        glColor3ub(63,67,71);
      glVertex2f(-0.536458f,-0.501852f);
       glVertex2f(-0.532292f,-0.5f);
       glVertex2f(-0.502083f,-0.477778f);
       glVertex2f(-0.501042f,-0.418519f);
       glVertex2f(-0.526042f,-0.42037f);
       glVertex2f(-0.513542f,-0.418519f);
       glVertex2f(-0.526042f,-0.427778f);
       glVertex2f(-0.530208f,-0.425926f);
        glEnd*/

    glBegin(GL_QUADS);
    glColor3ub(63,67,71);
    glVertex2f(-0.526042f,-0.418519f);
    glVertex2f(-0.501042f,-0.418519f);
    glVertex2f(-0.501042f,-0.477778f);
    glVertex2f(-0.526042f,-0.477778f);
    glEnd();
    /*glBegin(GL_TRIANGLES);
    glColor3ub(63,67,71);
    glVertex2f(-0.532292f,-0.501852f);
    glVertex2f(-0.501042f,-0.477778f);
    glVertex2f(-0.526042f,-0.477778f);
    glEnd();*/
    /*glBegin(GL_TRIANGLES);
       glColor3ub(63,67,71);
       glVertex2f(-0.536458f,-0.501852f);
    glVertex2f(-0.532292f,-0.501852f);
    glVertex2f(-0.526042f,-0.477778f);
       glEnd();*/

    /*glBegin(GL_TRIANGLES);
    glColor3ub(63,67,71);
    glVertex2f(-0.5f,-0.501852f);
    glVertex2f(-0.506593f,-0.501852f);
    glVertex2f(-0.5f,-0.501852f);
    glEnd();*/

    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.496875f,-0.475926f);
    glVertex2f(-0.476042f,-0.475926f);
    glVertex2f(-0.476042f,-0.433333f);
    glVertex2f(-0.496875f,-0.433333f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.472917f,-0.477778f);
    glVertex2f(-0.452083f,-0.477778f);
    glVertex2f(-0.452083f,-0.433333f);
    glVertex2f(-0.472917f,-0.433333f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.447917f,-0.477778f);
    glVertex2f(-0.428125f,-0.477778f);
    glVertex2f(-0.428125f,-0.433333f);
    glVertex2f(-0.447917f,-0.433333f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.423958f,-0.477778f);
    glVertex2f(-0.403125f,-0.477778f);
    glVertex2f(-0.403125f,-0.433333f);
    glVertex2f(-0.423958f,-0.433333f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.4f,-0.477778f);
    glVertex2f(-0.379167f,-0.477778f);
    glVertex2f(-0.379167f,-0.433333f);
    glVertex2f(-0.4f,-0.433333f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.376042f,-0.477778f);
    glVertex2f(-0.355208f,-0.477778f);
    glVertex2f(-0.355208f,-0.433333f);
    glVertex2f(-0.376042f,-0.433333f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.352083f,-0.477778f);
    glVertex2f(-0.33125f,-0.477778f);
    glVertex2f(-0.33125f,-0.433333f);
    glVertex2f(-0.352083f,-0.433333f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.304167f,-0.477778f);
    glVertex2f(-0.283333f,-0.477778f);
    glVertex2f(-0.283333f,-0.433333f);
    glVertex2f(-0.304167f,-0.433333f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(63,66,74);
    glVertex2f(-0.328125f,-0.477778f);
    glVertex2f(-0.30625f,-0.477778f);
    glVertex2f(-0.30625f,-0.433333f);
    glVertex2f(-0.328125f,-0.433333f);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(116,118,95);

    glVertex2f(-0.496875f,-0.448148f);
    glVertex2f(-0.282292f,-0.448148f);

    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(63,67,71);
    glVertex2f(-0.536458f,-0.501852f);
    glVertex2f(-0.532292f,-0.501852f);
    glVertex2f(-0.532292f,-0.45f);
    glEnd();

    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(116,118,95);

    glVertex2f(-0.534375f,-0.485185f);
    glVertex2f(-0.538542f,-0.485185f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);
    glVertex2f(-0.539583f,-0.485185f);
    glVertex2f(-0.539583f,-0.442593f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(237,28,36);
    glVertex2f(-0.542708f,-0.472222f);
    glVertex2f(-0.539583f,-0.47037f);
    glVertex2f(-0.539583f,-0.448148f);
    glVertex2f(-0.542708f,-0.448148f);
    glEnd();

///for door
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);

    glVertex2f(-0.539583f,-0.485185f);
    glVertex2f(-0.532292f,-0.485185f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);

    glVertex2f(-0.532292f,-0.501852f);
    glVertex2f(-0.532292f,-0.557407f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);

    glVertex2f(-0.532292f,-0.557407f);
    glVertex2f(-0.515625f,-0.557407f);

    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);

    glVertex2f(-0.515625f,-0.557407f);

    glVertex2f(-0.515625f,-0.546296f);
    glEnd();


    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);
    glVertex2f(-0.515625f,-0.546296f);
    glVertex2f(-0.502083f,-0.518519f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);
    glVertex2f(-0.502083f,-0.518519f);
    glVertex2f(-0.502083f,-0.42037f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(237,28,36);
    glVertex2f(-0.502083f,-0.42037f);
    glVertex2f(-0.529167f,-0.42037f);
    glEnd();








    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3ub(63,66,74);
    glVertex2f(-0.534375f,-0.485185f);
    glVertex2f(-0.538542f,-0.485185f);
    glEnd();



///tyre

    int i;
    GLfloat x=-0.496875f;
    GLfloat y=-0.557407f;
    GLfloat radius =.018f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;
    glColor3ub(64,71,71);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();





    glPopMatrix();
}
void bustyre1()//h
{
    glPushMatrix();
    glTranslatef(busposition, 0.0f, 0.0f);
    int i;

    GLfloat x=-0.496875f;
    GLfloat y=-0.557407f;
    GLfloat radius =.01f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius* cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

}


void bustyre2()//h
{
    glPushMatrix();
    glTranslatef(busposition, 0.0f, 0.0f);
    int i;

    GLfloat p=-0.311458f;
    GLfloat q=-0.558259f;
    GLfloat radius =.018f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(64,71,71);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p + (radius* cos(i *  twicePi / triangleAmount)),
                    q + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

}
void bustyre3()//h
{
    glPushMatrix();
    glTranslatef(busposition, 0.0f, 0.0f);
    int i;

    GLfloat p=-0.311458f;
    GLfloat q=-0.558259f;
    GLfloat radius =.01f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p,q); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p + (radius* cos(i *  twicePi / triangleAmount)),
                    q + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

}




void humany()//z
{
    //glPushMatrix();
    // glTranslatef(busposition, 0.0f, 0.0f);
    int i;

    GLfloat x=0.39375f;
    GLfloat y=-0.409259f;
    GLfloat radius =.016f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;


    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius* cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(112,128,144);         //field boundary 3
    glVertex2f(0.382292f,-0.425926f);
    glVertex2f(0.382292f,-0.475926f);
    glVertex2f(0.407292f,-0.475926f);
    glVertex2f(0.407292f,-0.425926f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(0.389583f,-0.475926f);
    glVertex2f(0.389583f,-0.498148f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(0.402083f,-0.475926f);
    glVertex2f(0.402083f,-0.498148f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(0.382292f,-0.431481f);
    glVertex2f(0.36875f,-0.440741f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(0.382292f,-0.451852f);
    glVertex2f(0.371875f,-0.461111f);
    glEnd();
//glPopMatrix();
}

void streetLights()//h
{
    int smokeXLtri = 40;
    GLfloat smokeXLp, smokeXLq, smokeXLr, smokeXLtp;

    float x =0.33125;
    for (int i = 0; i<=5; i++ )
    {
        glBegin(GL_POLYGON); ///
        glColor3ub(95, 95, 95);
        glVertex2f(0.830208-x*i, -0.7f);
        glVertex2f(0.857292f-x*i, -0.7f);
        glVertex2f(0.851042f-x*i,-0.675926f);
        glVertex2f(0.833333f-x*i,-0.675926f);
        glEnd();


        glLineWidth(4.5);
        glBegin(GL_LINES); //
        glColor3ub(95, 95, 95);
        glVertex2f(0.842708f-x*i,-0.674707f);
        glVertex2f(0.842708f-x*i,-0.414111f);
        glEnd();
        glLineWidth(2.5);

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.842708f-x*i,-0.414111f);
        glVertex2f(0.847917f-x*i,-0.381481f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.842708f-x*i,-0.414111f);
        glVertex2f(0.839583f-x*i,-0.381481f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.847917f-x*i,-0.381481f);
        glVertex2f(0.866667f-x*i,-0.381481f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.866667f-x*i,-0.381481f);
        glVertex2f(0.86875f-x*i,-0.396296f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.842708f-x*i,-0.414111f);
        glVertex2f(0.839583f-x*i,-0.381481f);
        glVertex2f(0.822917f-x*i,-0.381481f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.839583f-x*i,-0.381481f);
        glVertex2f(0.822917f-x*i,-0.381481f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.822917f-x*i,-0.381481f);
        glVertex2f(0.81875f-x*i,-0.396296f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.810417f-x*i,-0.398148f);
        glVertex2f(0.826042f-x*i,-0.398148f);
        glEnd();

        glBegin(GL_LINES); //
        glColor3ub(0, 0, 0);
        glVertex2f(0.810417f+0.052083-x*i,-0.398148f);
        glVertex2f(0.826042f+0.052083-x*i,-0.398148f);
        glEnd();


        glBegin(GL_TRIANGLE_FAN);///street light left
        glColor4ub(255, 201, 14, 200);
        smokeXLp = 0.81875f-x*i;
        smokeXLq = -0.416519f;
        smokeXLr = 0.016f;
        smokeXLtp = 2.0f * PI;


        glVertex2f(smokeXLp, smokeXLq);
        for (int c = 0; c <= smokeXLtri; c++)
        {
            glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
                       smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);///street light left
        glColor4ub(255, 201, 14, 200);
        smokeXLp = 0.81875f+0.052083-x*i;
        smokeXLq = -0.416519f;
        smokeXLr = 0.016f;
        smokeXLtp = 2.0f * PI;

        glVertex2f(smokeXLp, smokeXLq);
        for (int c = 0; c <= smokeXLtri; c++)
        {
            glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
                       smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
        }
        glEnd();

        if(light)
        {
            glBegin(GL_TRIANGLES); // right side er triangle
            glColor3ub(0,139,139);
            glColor4ub(255, 201, 14, 150);
            glVertex2f(0.763542f-x*i,-0.683333f);
            glVertex2f(0.815625f-x*i,-0.446296f);
            glVertex2f(0.871875f-x*i,-0.683333f);

            glEnd();
            glBegin(GL_TRIANGLES); // right side er triangle
            glColor3ub(0,139,139);
            glColor4ub(255, 201, 14, 150);
            glVertex2f(0.815625f-x*i,-0.683333f);
            glVertex2f(0.867708f-x*i,-0.446296f);
            glVertex2f(0.928125f-x*i,-0.683333f);
        }


        glEnd();

    }
}




void stationLight()//m
{
    glPushMatrix();
    glTranslatef(-1.71f, 0.0, 0.0);
    redLights();
    glPopMatrix();
}
void stationRoad()//m
//station pillars
{
    glPushMatrix();
    glTranslatef(-0.5f, 0.0, 0.0);
    railline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.0f, 0.0, 0.0);
    railline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5f, 0.0, 0.0);
    railline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.0f, 0.0, 0.0);
    railline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5f, 0.0, 0.0);
    railline();
    glPopMatrix();
}


void streetLights1()//h
{

    glPushMatrix();
    glTranslatef(-2.0f, 0.0, 0.0);

    streetLights();

    glPopMatrix();
}


void station()//m
{
    glPushMatrix();
    glTranslatef(0.35f, -0.4, 0.0);
    glScalef(0.75f, 0.75f, 1.0f);



    //BUILDING 5 FROM RIGHT...................
    building5();

    //Building 4 FROM RIGHT...................
    building4();

    //Building 3 FROM RIGHT...................
    building3();

    //Building 2 from right side................
    building2();

    //Building 1 from right side.
    building1();

    road();
    stationFP();
    stationRB();
    accelerator();
    train();
    stationLight();

    redLights();
    busstop();
    car();
    tyre();
    tyreM();
    tyre2nd();
    car2();
    sceondcartyre();
    sceondcartyre3();
    sceondcartyre2();
    bus();
    bustyre1();
    bustyre2();
    bustyre3();
    bakery();

    stationRoad();
    railline();
    humany();
    streetLights();
    streetLights1();
    glPopMatrix();
}




void ship()//e
{

    glPushMatrix();
    glTranslatef(-positionb,-positionb/5, 0.0f);
    glTranslatef(0.0f,0.25f, 0.0f);
    glScalef(0.75f, 0.75f, 0.0f);


    glBegin(GL_POLYGON); //lower porsion
    glColor3ub(118,49,44);
    glVertex2f(-1.0f,0.142593f);
    glVertex2f(-0.940625f,0.0537037f);
    glVertex2f(-0.704167f,0.0537037f);
    glVertex2f(-0.645833f,0.142593f);
    glEnd();

    glBegin(GL_POLYGON); //2nd lower porsion
    glColor3ub(155,103,73);
    glVertex2f(-1.0f,0.142593f);
    glVertex2f(-0.645833f,0.142593f);
    glVertex2f(-0.645833f,0.155556f);
    glVertex2f(-1.0f,0.155556f);
    glEnd();


    glBegin(GL_POLYGON); //3rd lower porsion
    glColor3ub(113,113,113);
    glVertex2f(-0.975f,0.155556f);
    glVertex2f(-0.669792f,0.155556f);
    glVertex2f(-0.669792f,0.194444f);
    glVertex2f(-0.975f,0.194444f);
    glEnd();




    glBegin(GL_POLYGON); //4th lower porsion
    glColor3ub(194,187,225);
    glVertex2f(-0.960417f,0.194444f);
    glVertex2f(-0.676042f,0.194444f);
    glVertex2f(-0.695833f,0.238889f);
    glVertex2f(-0.960417f,0.238889f);
    glEnd();


    glBegin(GL_POLYGON); //4th lower porsion
    glColor3ub(184,124,85);
    glVertex2f(-0.957292f,0.238889f);
    glVertex2f(-0.698958f,0.238889f);
    glVertex2f(-0.729167f,0.251852f);
    glVertex2f(-0.957292f,0.251852f);
    glEnd();


    glBegin(GL_POLYGON); ///1st uper part1
    glColor3ub(0,0,0);
    glVertex2f(-0.9f,0.253704f);
    glVertex2f(-0.873958f,0.253704f);
    glVertex2f(-0.873958f,0.290741f);
    glVertex2f(-0.9f,0.290741f);
    glEnd();

    glBegin(GL_POLYGON); ///1st uper part2
    glColor3ub(135,59,59);
    glVertex2f(-0.9f,0.290741f);
    glVertex2f(-0.873958f,0.290741f);
    glVertex2f(-0.873958f,0.298148f);
    glVertex2f(-0.9f,0.298148f);
    glEnd();


    glBegin(GL_POLYGON); ///2nd uper part1
    glColor3ub(0,0,0);
    glVertex2f(-0.847917f,0.253704f);
    glVertex2f(-0.822917f,0.253704f);
    glVertex2f(-0.822917f,0.290741f);
    glVertex2f(-0.847917f,0.290741f);
    glEnd();

    glBegin(GL_POLYGON); ///2nd uper part2
    glColor3ub(135,59,59);
    glVertex2f(-0.847917f,0.290741f);
    glVertex2f(-0.822917f,0.290741f);
    glVertex2f(-0.822917f,0.298148f);
    glVertex2f(-0.847917f,0.298148f);

    glEnd();


    glBegin(GL_POLYGON); ///3rd uper part1
    glColor3ub(0,0,0);
    glVertex2f(-0.796875f,0.251852f);
    glVertex2f(-0.771875f,0.251852f);
    glVertex2f(-0.771875f,0.290741f);
    glVertex2f(-0.796875f,0.290741f);
    glEnd();



    glBegin(GL_POLYGON); ///3rd uper part2
    glColor3ub(135,59,59);
    glVertex2f(-0.796875f,0.290741f);
    glVertex2f(-0.771875f,0.290741f);
    glVertex2f(-0.771875f,0.298148f);
    glVertex2f(-0.796875f,0.298148f);
    glEnd();
    glPopMatrix();
}

void Boat1()//e
{

    glPushMatrix();
    glTranslatef(positionboat, 0.0f, 0.0f);
    glScalef(0.75f, 0.75f, 1.0f);
    glBegin(GL_POLYGON); //Boat1
    glColor3ub(235,51,36);
    glVertex2f(0.191667f,0.168519f);
    glVertex2f(0.271875f,0.166667f);
    glVertex2f(0.304167f,0.244444f);
    glVertex2f(0.155208f,0.244444f);

    glEnd();



    glBegin(GL_TRIANGLES); //boat1
    glColor3ub(0,100,36);
    glVertex2f(0.21875f,0.248148f);
    glVertex2f(0.239583f,0.246296f);

    glVertex2f(0.242708f,0.314815f);
    glEnd();


    glBegin(GL_TRIANGLES); //boat1
    glColor3ub(0,100,36);
    glVertex2f(0.242708f,0.246296f);
    glVertex2f(0.282292f,0.246296f);
    glVertex2f(0.252083f,0.390741f);
    glEnd();

    glPopMatrix();


}


void mosque()//z
{
    glPushMatrix();
    glTranslatef(0.3638f, -0.301f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);

    glLineWidth(4.0);
    float x = -0.061112;


    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f);
    glVertex2f(-0.259375f,-0.405556f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112);
    glVertex2f(-0.259375f,-0.405556f+0.061112);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112+0.061112);
    glVertex2f(-0.259375f,-0.405556f+0.061112+0.061112);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112+0.061112);
    glVertex2f(-0.259375f,-0.405556f+0.061112+0.061112);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112+0.061112+0.061112);
    glVertex2f(-0.259375f,-0.405556f+0.061112+0.061112+0.061112);
    glEnd();



    glBegin(GL_QUADS);///main hall
    glColor3ub(220,197,153);
    glVertex2f(-0.536458f,-0.472222f);
    glVertex2f(-0.277083f,-0.472222f);
    glVertex2f(-0.277083f,-0.344444f);
    glVertex2f(-0.536458f,-0.344444f);
    glEnd();


    glBegin(GL_QUADS);///domed
    glColor3ub(220,197,153);
    glVertex2f(-0.511458f,-0.288889f);
    glVertex2f(-0.390625f,-0.288889f);
    glVertex2f(-0.390625f,-0.344593f);
    glVertex2f(-0.511458f,-0.344593f);
    glEnd();




    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.45f,-0.21333f);
    glVertex2f(-0.45f,-0.2f);
    glEnd();

    glBegin(GL_QUADS);///domed2
    glColor3ub(220,197,153);
    glVertex2f(-0.361458f,-0.318519f);
    glVertex2f(-0.295833f,-0.318519f);
    glVertex2f(-0.295833f,-0.342593f);
    glVertex2f(-0.361458f,-0.342593f);
    glEnd();

    glBegin(GL_QUADS);///lower ground
    glColor3ub(83,144,126);
    glVertex2f(-0.536458f,-0.464815f);
    glVertex2f(-0.275f,-0.464815f);
    glVertex2f(-0.275f,-0.474074f);
    glVertex2f(-0.536458f,-0.474074f);

    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.538542f,-0.344444f);
    glVertex2f(-0.275f,-0.344444f);
    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.491667f,-0.372222f);
    glVertex2f(-0.321875f,-0.372222f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.486458f,-0.374074f);
    glVertex2f(-0.486458f,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.486458f,-0.427778f);
    glVertex2f(-0.486458f,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.477083,-0.374074f);
    glVertex2f(-0.477083,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.477083,-0.427778f);
    glVertex2f(-0.477083,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.477083,-0.374074f);
    glVertex2f(-0.477083,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.477083,-0.427778f);
    glVertex2f(-0.477083,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.440625,-0.374074f);
    glVertex2f(-0.440625,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.440625,-0.427778f);
    glVertex2f(-0.440625,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.432292,-0.374074f);
    glVertex2f(-0.432292,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.432292,-0.427778f);
    glVertex2f(-0.432292,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.371875,-0.374074f);
    glVertex2f(-0.371875,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.371875,-0.427778f);
    glVertex2f(-0.371875,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.371875,-0.374074f);
    glVertex2f(-0.371875,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.371875,-0.427778f);
    glVertex2f(-0.371875,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.38125,-0.374074f);
    glVertex2f(-0.38125,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.38125,-0.427778f);
    glVertex2f(-0.38125,-0.455556f);
    glEnd();

    ///

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.335417,-0.374074f);
    glVertex2f(-0.335417,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.335417,-0.427778f);
    glVertex2f(-0.335417,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.327083,-0.374074f);
    glVertex2f(-0.327083,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.327083,-0.427778f);
    glVertex2f(-0.327083,-0.455556f);
    glEnd();

    glBegin(GL_QUADS); ///pillar ground
    glColor3ub(117,80,62);
    glVertex2f(-0.491667f,-0.453704f);
    glVertex2f(-0.429167f,-0.453704f);
    glVertex2f(-0.429167f,-0.47037f);
    glVertex2f(-0.491667f,-0.47037f);
    glEnd();

    glBegin(GL_QUADS); ///pillar ground
    glColor3ub(117,80,62);
    glVertex2f(-0.384375,-0.453704f);
    glVertex2f(-0.322917,-0.453704f);
    glVertex2f(-0.322917,-0.47037f);
    glVertex2f(-0.384375,-0.47037f);

    glEnd();

    glBegin(GL_QUADS); ///mosque window lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.530208f,-0.451852f);
    glVertex2f(-0.51875f,-0.451852f);
    glVertex2f(-0.51875f,-0.388889f);
    glVertex2f(-0.530208f,-0.388889f);

    glEnd();
    glBegin(GL_QUADS); ///mosque window lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.509375f,-0.451852f);
    glVertex2f(-0.498958f,-0.451852f);
    glVertex2f(-0.498958f,-0.392593f);
    glVertex2f(-0.509375f,-0.392593f);
    glEnd();

    glBegin(GL_QUADS); ///mosque window
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.313542f,-0.451852f);
    glVertex2f(-0.303125f,-0.451852f);
    glVertex2f(-0.303125f,-0.396296f);
    glVertex2f(-0.313542f,-0.396296f);
    glEnd();
    glBegin(GL_QUADS); ///mosque window lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.530208f+0.235416f,-0.451852f);
    glVertex2f(-0.51875f+0.235416f,-0.451852f);
    glVertex2f(-0.51875f+0.235416f,-0.388889f);
    glVertex2f(-0.530208f+0.235416f,-0.388889f);
    glEnd();


    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.470833f,-0.451852f);
    glVertex2f(-0.460417f,-0.451852f);
    glVertex2f(-0.460417f,-0.388889f);
    glVertex2f(-0.470833f,-0.388889f);

    glEnd();

    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.470833f+0.013541,-0.451852f);
    glVertex2f(-0.460417f+0.013541,-0.451852f);
    glVertex2f(-0.460417f+0.013541,-0.388889f);
    glVertex2f(-0.470833f+0.013541,-0.388889f);

    glEnd();

    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.470833f+(0.103125),-0.451852f);
    glVertex2f(-0.460417f+0.103125,-0.451852f);
    glVertex2f(-0.460417f+0.103125,-0.388889f);
    glVertex2f(-0.470833f+0.103125,-0.388889f);

    glEnd();

    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.470833f+(0.103125+0.013541),-0.451852f);
    glVertex2f(-0.460417f+0.103125+0.013541,-0.451852f);
    glVertex2f(-0.460417f+0.103125+0.013541,-0.388889f);
    glVertex2f(-0.470833f+0.103125+0.013541,-0.388889f);

    glEnd();
    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.428125f,-0.451852f);
    glVertex2f(-0.385417f,-0.451852f);
    glVertex2f(-0.385417f,-0.409259f);
    glVertex2f(-0.428125f,-0.409259f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.428125f,-0.409259f);
    glVertex2f(-0.41875f,-0.387037f);
    glVertex2f(-0.409375f,-0.409259f);
    glEnd();
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3ub(205,193,169);
    glVertex2f(-0.40625f,-0.381481f);
    glVertex2f(-0.40625f,-0.451852f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light)
    {
        glColor3ub(255, 255, 153);
    }
    glVertex2f(-0.428125f+0.026042,-0.409259f);
    glVertex2f(-0.41875f+0.026042,-0.387037f);
    glVertex2f(-0.409375f+0.026042,-0.409259f);
    glEnd();


    x = 0.019792;
    for(int i=0; i<=5; i++)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(70,59,65);
        if(light)
        {
            glColor3ub(255, 255, 153);
        }
        glVertex2f(-0.50625f+x*i,-0.340741f);
        glVertex2f(-0.497917f+x*i,-0.294444f);
        glVertex2f(-0.490625f+x*i,-0.340741f);
        glEnd();

    }
    x=0.010416;
    for(int i=0; i<=15; i++)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(70,59,65);
        if(light)
        {
            glColor3ub(255, 255, 153);
        }
        glVertex2f(-0.486458f+x*i,-0.366667f);
        glVertex2f(-0.484375f+x*i,-0.348148f);
        glVertex2f(-0.480208f+x*i,-0.366667f);
        glEnd();

    }
    for(int i=0; i<=5; i++)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(70,59,65);
        if(light)
        {
            glColor3ub(255, 255, 153);
        }
        glVertex2f(-0.359375f+x*i,-0.338889f);
        glVertex2f(-0.35625f+x*i,-0.322222f);
        glVertex2f(-0.351042f+x*i,-0.338889f);
        glEnd();

    }
    glPopMatrix();
}



void house3()//e
{
    glPushMatrix();
    glTranslatef(-0.26f, -0.670f, 0.0f);
    glScalef(0.3f, 0.7f, 0.30f);


// left house start
    glBegin(GL_POLYGON); // body
    glColor3ub(224, 228, 231);
    glVertex2f(-1.4f, 0.5f);
    glVertex2f(-1.4f, 1.0f);
    glVertex2f(-0.9f, 1.0f);
    glVertex2f(-0.9f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // bottom-window 1
    glColor3ub(179, 230, 255);
    glVertex2f(-1.35f, 0.55f);
    glVertex2f(-1.35f, 0.65f);
    glColor3ub(0, 230, 230);
    glVertex2f(-1.25f, 0.65f);
    glVertex2f(-1.25f, 0.55f);
    glEnd();
    glBegin(GL_POLYGON); // bottom-window 2
    glColor3ub(179, 230, 255);
    glVertex2f(-1.05f, 0.55f);
    glVertex2f(-1.05f, 0.65f);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.95f, 0.65f);
    glVertex2f(-0.95f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON); // top-window 1
    glColor3ub(179, 230, 255);
    glVertex2f(-1.35f, 0.85f);
    glVertex2f(-1.35f, 0.95f);
    glColor3ub(0, 230, 230);
    glVertex2f(-1.25f, 0.95f);
    glVertex2f(-1.25f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 2
    glColor3ub(179, 230, 255);
    glVertex2f(-1.2f, 0.85f);
    glVertex2f(-1.2f, 0.95f);
    glColor3ub(0, 230, 230);
    glVertex2f(-1.1f, 0.95f);
    glVertex2f(-1.1f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 3
    glColor3ub(179, 230, 255);
    glVertex2f(-1.05f, 0.85f);
    glVertex2f(-1.05f, 0.95f);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.95f, 0.95f);
    glVertex2f(-0.95f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
    glColor3ub(153, 153, 153);
    glVertex2f(-1.2f, 0.5f);
    glVertex2f(-1.2f, 0.65f);
    glVertex2f(-1.1f, 0.65f);
    glVertex2f(-1.1f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.17f, 0.58f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(77, 195, 255);
    glVertex2f(-1.35f, 0.55f); // bottom-window 1
    glVertex2f(-1.35f, 0.65f);

    glVertex2f(-1.35f, 0.65f);
    glVertex2f(-1.25f, 0.65f);

    glVertex2f(-1.25f, 0.65f);
    glVertex2f(-1.25f, 0.55f);

    glVertex2f(-1.25f, 0.55f);
    glVertex2f(-1.35f, 0.55f);

    glVertex2f(-1.25f, 0.6f);
    glVertex2f(-1.35f, 0.6f);

    glVertex2f(-1.05f, 0.55f); // bottom-window 2
    glVertex2f(-1.05f, 0.65f);

    glVertex2f(-1.05f, 0.65f);
    glVertex2f(-0.95f, 0.65f);

    glVertex2f(-0.95f, 0.65f);
    glVertex2f(-0.95f, 0.55f);

    glVertex2f(-0.95f, 0.55f);
    glVertex2f(-1.05f, 0.55f);

    glVertex2f(-0.95f, 0.6f);
    glVertex2f(-1.05f, 0.6f);

    glVertex2f(-1.35f, 0.85f); // top-window 1
    glVertex2f(-1.35f, 0.95f);

    glVertex2f(-1.35f, 0.95f);
    glVertex2f(-1.25f, 0.95f);

    glVertex2f(-1.25f, 0.95f);
    glVertex2f(-1.25f, 0.85f);

    glVertex2f(-1.25f, 0.85f);
    glVertex2f(-1.35f, 0.85f);

    glVertex2f(-1.25f, 0.9f);
    glVertex2f(-1.35f, 0.9f);

    glVertex2f(-1.2f, 0.85f); // top-window 2
    glVertex2f(-1.2f, 0.95f);

    glVertex2f(-1.2f, 0.95f);
    glVertex2f(-1.1f, 0.95f);

    glVertex2f(-1.1f, 0.95f);
    glVertex2f(-1.1f, 0.85f);

    glVertex2f(-1.1f, 0.85f);
    glVertex2f(-1.2f, 0.85f);

    glVertex2f(-1.1f, 0.9f);
    glVertex2f(-1.2f, 0.9f);

    glVertex2f(-1.05f, 0.85f); // top-window 3
    glVertex2f(-1.05f, 0.95f);

    glVertex2f(-1.05f, 0.95f);
    glVertex2f(-0.95f, 0.95f);

    glVertex2f(-0.95f, 0.95f);
    glVertex2f(-0.95f, 0.85f);

    glVertex2f(-0.95f, 0.85f);
    glVertex2f(-1.05f, 0.85f);

    glVertex2f(-0.95f, 0.9f);
    glVertex2f(-1.05f, 0.9f);

    glVertex2f(-1.2f, 0.5f); // door
    glVertex2f(-1.2f, 0.65f);

    glVertex2f(-1.2f, 0.65f);
    glVertex2f(-1.1f, 0.65f);

    glVertex2f(-1.1f, 0.65f);
    glVertex2f(-1.1f, 0.5f);

    glVertex2f(-1.1f, 0.5f);
    glVertex2f(-1.2f, 0.5f);

    // body
    glColor3ub(128, 128, 128);

    glVertex2f(-1.4f, 0.5f);
    glVertex2f(-1.4f, 1.0f);

    glVertex2f(-1.4f, 1.0f);
    glVertex2f(-0.9f, 1.0f);

    glVertex2f(-0.9f, 1.0f);
    glVertex2f(-0.9f, 0.5f);

    glColor3ub(128, 0, 0);
    glVertex2f(-0.87f, 0.5f);
    glVertex2f(-1.43f, 0.5f);

    glVertex2f(-0.87f, 0.504f);
    glVertex2f(-1.43f, 0.504f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
    glColor3ub(76, 174, 218);
    glVertex2f(-1.4f, 0.8f);
    glVertex2f(-1.45f, 0.75f);
    glVertex2f(-1.45f, 0.7f);
    glVertex2f(-0.85f, 0.7f);
    glVertex2f(-0.85f, 0.75f);
    glVertex2f(-0.9f, 0.8f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.4f, 0.8f);
    glVertex2f(-1.45f, 0.75f);

    glVertex2f(-1.45f, 0.75f);
    glVertex2f(-1.45f, 0.7f);

    glVertex2f(-1.45f, 0.7f);
    glVertex2f(-0.85f, 0.7f);

    glVertex2f(-0.85f, 0.7f);
    glVertex2f(-0.85f, 0.75f);

    glVertex2f(-0.85f, 0.75f);
    glVertex2f(-0.9f, 0.8f);

    glVertex2f(-0.9f, 0.8f);
    glVertex2f(-1.4f, 0.8f);
    glEnd();
    // left house end
    glPopMatrix();
}

void house2()//e
{
    glPushMatrix();
    glTranslatef(-0.690f, -0.720f, 0.0f);
    glScalef(0.3f, 0.8f, 0.50f);

    // right house start
    glBegin(GL_POLYGON); // body
    glColor3ub(153, 51, 0);
    glVertex2f(-0.15f, 0.5f);
    glVertex2f(-0.15f, 0.8f);
    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.35f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); // store room
    glColor3ub(153, 51, 0);
    glVertex2f(0.05f, 0.8f);
    glVertex2f(0.05f, 0.99f);
    glVertex2f(0.35f, 0.99f);
    glVertex2f(0.35f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON); // window 1
    glColor3ub(77, 184, 255);
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.05f, 0.7f);
    glColor3ub(26, 140, 255);
    glVertex2f(0.15f, 0.7f);
    glVertex2f(0.15f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(77, 184, 255);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, 0.7f);
    glColor3ub(26, 140, 255);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.3f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // store room window
    glColor3ub(77, 184, 255);
    glVertex2f(0.15f, 0.85f);
    glVertex2f(0.15f, 0.95f);
    glColor3ub(26, 140, 255);
    glVertex2f(0.25f, 0.95f);
    glVertex2f(0.25f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
    glColor3ub(77, 77, 77);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(-0.1f, 0.65f);
    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.03f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // door shelter
    glColor3ub(230, 115, 0);
    glVertex2f(0.02f, 0.65f);
    glVertex2f(-0.05f, 0.7f);
    glVertex2f(-0.12f, 0.65f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.15f, 0.85f); // store room window
    glVertex2f(0.15f, 0.95f);

    glVertex2f(0.15f, 0.95f);
    glVertex2f(0.25f, 0.95f);

    glVertex2f(0.25f, 0.95f);
    glVertex2f(0.25f, 0.85f);

    glVertex2f(0.25f, 0.85f);
    glVertex2f(0.15f, 0.85f);

    glVertex2f(0.05f, 0.6f); // window 1
    glVertex2f(0.05f, 0.7f);

    glVertex2f(0.05f, 0.7f);
    glVertex2f(0.15f, 0.7f);

    glVertex2f(0.15f, 0.7f);
    glVertex2f(0.15f, 0.6f);

    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.05f, 0.6f);

    glVertex2f(0.2f, 0.6f); // window 2
    glVertex2f(0.2f, 0.7f);

    glVertex2f(0.2f, 0.7f);
    glVertex2f(0.3f, 0.7f);

    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.3f, 0.6f);

    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.2f, 0.6f);

    glColor3ub(255, 153, 51);
    glVertex2f(-0.1f, 0.5f); // door
    glVertex2f(-0.1f, 0.65f);

    glVertex2f(-0.1f, 0.65f);
    glVertex2f(0.0f, 0.65f);

    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.0f, 0.5f);

    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.1f, 0.5f);

    glVertex2f(0.02f, 0.65f); // door shelter
    glVertex2f(-0.05f, 0.7f);

    glVertex2f(-0.05f, 0.7f);
    glVertex2f(-0.12f, 0.65f);

    glVertex2f(-0.12f, 0.65f);
    glVertex2f(0.02f, 0.65f);

    glVertex2f(0.36f, 0.8f); // roof railing
    glVertex2f(-0.16f, 0.8f);

    glVertex2f(0.36f, 0.84f);
    glVertex2f(-0.16f, 0.84f);

    glVertex2f(-0.14f, 0.8f);
    glVertex2f(-0.14f, 0.84f);

    glVertex2f(-0.1f, 0.8f);
    glVertex2f(-0.1f, 0.84f);

    glVertex2f(-0.05f, 0.8f);
    glVertex2f(-0.05f, 0.84f);

    glVertex2f(-0.0f, 0.8f);
    glVertex2f(-0.0f, 0.84f);

    glVertex2f(0.05f, 0.8f);
    glVertex2f(0.05f, 0.84f);

    glVertex2f(0.1f, 0.8f);
    glVertex2f(0.1f, 0.84f);

    glVertex2f(0.15f, 0.8f);
    glVertex2f(0.15f, 0.84f);

    glVertex2f(0.2f, 0.8f);
    glVertex2f(0.2f, 0.84f);

    glVertex2f(0.25f, 0.8f);
    glVertex2f(0.25f, 0.84f);

    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.3f, 0.84f);

    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.35f, 0.84f);

    glVertex2f(-0.16f, 0.504f); // ground
    glVertex2f(0.36f, 0.504f);

    glVertex2f(-0.16f, 0.5f);
    glVertex2f(0.36f, 0.5f);

    glVertex2f(0.04f, 0.99f); // top roof
    glVertex2f(0.36f, 0.99f);

    glVertex2f(0.04f, 0.985f);
    glVertex2f(0.36f, 0.985f);
    glEnd();
    glPopMatrix();

    // right house end
}


void house1()//e
{
    glPushMatrix();
    glTranslatef(-1.310f, -0.450f, 0.0f);
    glScalef(1.2f, 1.2f, 1.0f);
    ///5th Building Food Court///
/// Food court big Right part///
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74); ///Food Court main part 2
    glVertex2f(0.373, 0.090);
    glVertex2f(0.466, 0.090);
    glVertex2f(0.466, 0.442);
    glVertex2f(0.373, 0.442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(91, 102, 108);
    glVertex2f(0.3775, 0.090); ///Food Court main part 2
    glVertex2f(0.461, 0.090);
    glVertex2f(0.461, 0.440);
    glVertex2f(0.3775, 0.440);
    glEnd();

//floor divided
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(0.2825, 0.270); ///Middle divided left right
    glVertex2f(0.466, 0.270);
    glVertex2f(0.466, 0.281);
    glVertex2f(0.2825, 0.281);
    glEnd();

///stairs//Top
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(0.371, 0.442); ///3//
    glVertex2f(0.4675, 0.442);
    glVertex2f(0.4675, 0.451);
    glVertex2f(0.371, 0.451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(20, 25, 33);
    glVertex2f(0.371, 0.454); ///2//
    glVertex2f(0.4675, 0.454);
    glVertex2f(0.4675, 0.451);
    glVertex2f(0.371, 0.451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(0.367, 0.454); ///1//
    glVertex2f(0.4715, 0.454);
    glVertex2f(0.4715, 0.463);
    glVertex2f(0.367, 0.463);
    glEnd();

///stairs Top End//

    glBegin(GL_QUADS);
    glColor3ub(72, 85, 93);
    glVertex2f(0.3775, 0.433);
    glVertex2f(0.461, 0.433);
    glVertex2f(0.461, 0.440);
    glVertex2f(0.3775, 0.440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.382, 0.290); ///black Food Court Right part
    glVertex2f(0.457, 0.290);
    glVertex2f(0.457, 0.429);
    glVertex2f(0.382, 0.429);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(0.3835, 0.2936); /// white color Food Court Right part
    glVertex2f(0.4554, 0.2936);
    glVertex2f(0.4554, 0.4254);
    glVertex2f(0.3835, 0.4254);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.382, 0.3142); ///middle line 2
    glVertex2f(0.457, 0.3142);
    glVertex2f(0.457, 0.3102);
    glVertex2f(0.382, 0.3102);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.368, 0.4091); ///middle line 1
    glVertex2f(0.457, 0.4091);
    glVertex2f(0.457, 0.4051);
    glVertex2f(0.368, 0.4051);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.368, 0.4291); ///middle line for sign board
    glVertex2f(0.382, 0.4291);
    glVertex2f(0.382, 0.426);
    glVertex2f(0.368, 0.426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.402, 0.290); ///partation of Blue line
    glVertex2f(0.4006, 0.290);
    glVertex2f(0.4006, 0.426);
    glVertex2f(0.402, 0.426);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.420, 0.290); ///partation of Blue line
    glVertex2f(0.4186, 0.290);
    glVertex2f(0.4186, 0.426);
    glVertex2f(0.420, 0.426);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.438, 0.290); ///partation of Blue line
    glVertex2f(0.4365, 0.290);
    glVertex2f(0.4365, 0.426);
    glVertex2f(0.438, 0.426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(0.3885, 0.2556); /// Food Court board Black
    glVertex2f(0.4502, 0.2556);
    glVertex2f(0.4502, 0.2834);
    glVertex2f(0.3885, 0.2834);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(182, 138, 94);
    glVertex2f(0.3865, 0.2583); /// Food Court board
    glVertex2f(0.4483, 0.2583);
    glVertex2f(0.4483, 0.287);
    glVertex2f(0.3865, 0.287);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(0.3865, 0.2812); ///middle line 1
    glVertex2f(0.4483, 0.2812);
    glVertex2f(0.4483, 0.279);
    glVertex2f(0.3865, 0.279);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(0.3865, 0.2732); ///middle line 1
    glVertex2f(0.4483, 0.2732);
    glVertex2f(0.4483, 0.271);
    glVertex2f(0.3865, 0.271);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(0.3865, 0.2652); ///middle line 1
    glVertex2f(0.4483, 0.2652);
    glVertex2f(0.4483, 0.263);
    glVertex2f(0.3865, 0.263);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(0.3776, 0.2414); ///middle line
    glVertex2f(0.4609, 0.2414);
    glVertex2f(0.4609, 0.2392);
    glVertex2f(0.3776, 0.2392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(0.3776, 0.2304); ///middle line
    glVertex2f(0.4609, 0.2304);
    glVertex2f(0.4609, 0.2282);
    glVertex2f(0.3776, 0.2282);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(0.3776, 0.2204); ///middle line
    glVertex2f(0.4609, 0.2204);
    glVertex2f(0.4609, 0.2182);
    glVertex2f(0.3776, 0.2182);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(0.3776, 0.2105); ///middle line
    glVertex2f(0.4609, 0.2105);
    glVertex2f(0.4609, 0.2084);
    glVertex2f(0.3776, 0.2084);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(0.3776, 0.2005); ///middle line
    glVertex2f(0.4609, 0.2005);
    glVertex2f(0.4609, 0.1984);
    glVertex2f(0.3776, 0.1984);
    glEnd();
/// Door ///
    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(0.397, 0.110);   /// black color Food court door
    glVertex2f(0.442, 0.110);
    glVertex2f(0.442, 0.230);
    glVertex2f(0.397, 0.230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(0.3985, 0.110);   /// Food Court black color
    glVertex2f(0.440, 0.110);
    glVertex2f(0.440, 0.2265);
    glVertex2f(0.3985, 0.2265);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 242, 205);
    glVertex2f(0.4015, 0.110);   /// Food Court Right part
    glVertex2f(0.437, 0.110);
    glVertex2f(0.437, 0.2205);
    glVertex2f(0.4015, 0.2205);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.399, 0.1187);  ///
    glVertex2f(0.440, 0.1187);
    glVertex2f(0.440, 0.1246);
    glVertex2f(0.399, 0.1246);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(0.420, 0.110);   /// partation of Blue line
    glVertex2f(0.4166, 0.110);
    glVertex2f(0.4166, 0.226);
    glVertex2f(0.420, 0.226);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(0.421, 0.110);   /// partation
    glVertex2f(0.4196, 0.110);
    glVertex2f(0.4196, 0.226);
    glVertex2f(0.421, 0.226);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(0.424, 0.110);   /// partation of Blue line
    glVertex2f(0.4206, 0.110);
    glVertex2f(0.4206, 0.226);
    glVertex2f(0.424, 0.226);
    glEnd();

/// End Right part ///

/// Food Court left part ///
    glBegin(GL_QUADS);
    glColor3ub(91, 102, 108);  /// Food Court small left part
    glVertex2f(0.288, 0.110);
    glVertex2f(0.373, 0.110);
    glVertex2f(0.373, 0.270);
    glVertex2f(0.288, 0.270);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.293, 0.120);  /// black Food Court small left part
    glVertex2f(0.368, 0.120);
    glVertex2f(0.368, 0.259);
    glVertex2f(0.293, 0.259);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(0.295, 0.124);  /// white color Food Court small left part
    glVertex2f(0.366, 0.124);
    glVertex2f(0.366, 0.256);
    glVertex2f(0.295, 0.256);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.2945, 0.190);  /// middle line
    glVertex2f(0.368, 0.190);
    glVertex2f(0.368, 0.187);
    glVertex2f(0.2945, 0.187);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.350, 0.120);   /// partation of Blue line
    glVertex2f(0.3486, 0.120);
    glVertex2f(0.3486, 0.256);
    glVertex2f(0.350, 0.256);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.332, 0.120);   /// partation of Blue line
    glVertex2f(0.3306, 0.120);
    glVertex2f(0.3306, 0.256);
    glVertex2f(0.332, 0.256);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.314, 0.120);   /// partation of Blue line
    glVertex2f(0.3126, 0.120);
    glVertex2f(0.3126, 0.256);
    glVertex2f(0.314, 0.256);
    glEnd();

/// Top Boundary ///
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.2843, 0.280);   /// partation of Blue line
    glVertex2f(0.2825, 0.280);
    glVertex2f(0.2825, 0.321);
    glVertex2f(0.2843, 0.321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.302, 0.280);   /// partation of Blue line
    glVertex2f(0.3002, 0.280);
    glVertex2f(0.3002, 0.321);
    glVertex2f(0.302, 0.321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.320, 0.280);   /// partation of Blue line
    glVertex2f(0.3182, 0.280);
    glVertex2f(0.3182, 0.321);
    glVertex2f(0.320, 0.321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.338, 0.280);   /// partation of Blue line
    glVertex2f(0.3361, 0.280);
    glVertex2f(0.3361, 0.321);
    glVertex2f(0.338, 0.321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.356, 0.280);   /// partation of Blue line
    glVertex2f(0.3542, 0.280);
    glVertex2f(0.3542, 0.321);
    glVertex2f(0.356, 0.321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.373, 0.280);   /// partation of Blue line
    glVertex2f(0.3712, 0.280);
    glVertex2f(0.3712, 0.321);
    glVertex2f(0.373, 0.321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.2825, 0.314);  /// middle line
    glVertex2f(0.372, 0.314);
    glVertex2f(0.372, 0.3096);
    glVertex2f(0.2825, 0.3096);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.2825, 0.304);  /// middle line
    glVertex2f(0.372, 0.304);
    glVertex2f(0.372, 0.300);
    glVertex2f(0.2825, 0.300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(0.2825, 0.294);  /// middle line
    glVertex2f(0.372, 0.294);
    glVertex2f(0.372, 0.290);
    glVertex2f(0.2825, 0.290);
    glEnd();
/// End top Boundary ///
/// End left part ///



    glPopMatrix();

}
//zafir sesh

//emon suru
void house()//e
{
    glPushMatrix();
    glTranslatef(0.25f, 0.0, 0.0);


    house2();


    glPopMatrix();
}

void house4()//e
{
    glPushMatrix();
    glTranslatef(-0.1f, 0.1250, 0.0);


    house2();


    glPopMatrix();
}

void nightSky()//e
{
    glBegin(GL_POLYGON);
    glColor3ub(5,10,16);
    glVertex2f(-1.00f,1.00f);
    glVertex2f(1.00f,1.00f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(-1.00f,0.765f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(19,23,35);
    glVertex2f(-1.00f,0.765f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(-1.00f,0.635185f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34,43,60);
    glVertex2f(-1.00f,0.635185f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(-1.00f,0.468518f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(61,78,98);
    glVertex2f(-1.00f,0.468518f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(0.996875f,0.157407f);
    glVertex2f(-0.996875f,0.157407f);
    glEnd();

}

void cloud()//e
{
    glPushMatrix();
    glTranslatef(cloudposition,0.0f, 0.0f);
    GLfloat p2=0.75f;
    GLfloat q2= 0.81f;
    GLfloat r2 = 0.05f;
    int tringle3=40;
    GLfloat tp3 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p2,q2);
    for(int j= 0; j<=tringle3; j++)
    {
        glVertex2f (
            p2+(r2*cos(j*tp3/tringle3)),
            q2+(r2*sin(j*tp3/tringle3))
        );

    }
    glEnd ();
    GLfloat p3=0.80f;
    GLfloat q3= 0.78f;
    GLfloat r3 = 0.05f;
    int tringle4=40;
    GLfloat tp4 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p3,q3);
    for(int k= 0; k<=tringle4; k++)
    {
        glVertex2f (
            p3+(r3*cos(k*tp4/tringle4)),
            q3+(r3*sin(k*tp4/tringle4))
        );

    }
    glEnd ();

    GLfloat p4=0.85f;
    GLfloat q4= 0.75f;
    GLfloat r4 = 0.05f;
    int tringle5=40;
    GLfloat tp5 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p4,q4);
    for(int m= 0; m<=tringle5; m++)
    {
        glVertex2f (
            p4+(r4*cos(m*tp5/tringle5)),
            q4+(r4*sin(m*tp5/tringle5))
        );

    }
    GLfloat p5=0.79f;
    GLfloat q5= 0.77f;
    GLfloat r5 = 0.05f;
    int tringle6=40;
    GLfloat tp6 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p5,q5);
    for(int m= 0; m<=tringle6; m++)
    {
        glVertex2f (
            p5+(r5*cos(m*tp6/tringle6)),
            q4+(r5*sin(m*tp6/tringle6))
        );

    }
    glEnd ();


    GLfloat p7=0.2f;
    GLfloat q7= 0.83f;
    GLfloat r7 = 0.05f;
    int tringle7=40;
    GLfloat tp7 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p7,q7);
    for(int b= 0; b<=tringle7; b++)
    {
        glVertex2f (
            p7+(r7*cos(b*tp7/tringle7)),
            q7+(r7*sin(b*tp7/tringle7))
        );

    }
    glEnd ();

    GLfloat p8=0.27f;
    GLfloat q8= 0.85f;
    GLfloat r8 = 0.05f;
    int tringle8=40;
    GLfloat tp8 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p8,q8);
    for(int c= 0; c<=tringle8; c++)
    {
        glVertex2f (
            p8+(r8*cos(c*tp8/tringle8)),
            q8+(r8*sin(c*tp8/tringle8))
        );

    }
    glEnd ();
    GLfloat p9=0.15f;
    GLfloat q9= 0.85f;
    GLfloat r9 = 0.05f;
    int tringle9=40;
    GLfloat tp9 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p9,q9);
    for(int c= 0; c<=tringle9; c++)
    {
        glVertex2f (
            p9+(r9*cos(c*tp9/tringle9)),
            q9+(r9*sin(c*tp9/tringle9))
        );

    }
    glEnd ();
    GLfloat p10=0.22f;
    GLfloat q10= 0.87f;
    GLfloat r10 = 0.05f;
    int tringle10=40;
    GLfloat tp10 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    glVertex2f (p10,q10);
    for(int c= 0; c<=tringle10; c++)
    {
        glVertex2f (
            p10+(r10*cos(c*tp10/tringle10)),
            q10+(r10*sin(c*tp10/tringle10))
        );

    }
    glEnd ();

    glPopMatrix();
}

void stars(float x, float y)//m
{
    glBegin(GL_POINTS);
    glColor3ub(245,245,245);
    glVertex2f(x, y);
    glEnd();
}

void nightRiver() //e
{
    glBegin(GL_POLYGON);
    glColor3ub(37, 51, 77);
    glVertex2f(-1.0f, 0.20f);
    glVertex2f(1.0f, 0.52f);
    glVertex2f(1.0f, 0.16f);
    glVertex2f(-1.0f, -0.65f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96, 121, 151);
    glVertex2f(-0.75f,0.25f);
    glVertex2f(-0.1f,0.39f);
    glVertex2f(-0.45f,0.1f);
    glVertex2f(-0.15f,0.15f);
    glEnd();
}

void earth()//m
{
    // glClearColor(0.30, 0.50, 0.20, 1.0);
    glClearColor(0.40, 0.40, 0.40, 1.0);
}
void earthnight()//m
{
    glClearColor(0.20, 0.2, 0.2, 1.0);
}

void day()
{

    sky();
    cloud();
    sun1();
    sun2();
    river();

    earth();

}


void night()
{


    nightSky();
    cloud();
    //stars
    stars(0.5f, 0.8f);
    stars(-0.1f, 0.7f);
    stars(-0.3f, 0.8f);
    stars(-0.1f, 0.95f);
    stars(-0.5f, 0.8f);
    stars(-0.6f, 0.91f);
    stars(0.6f, 0.95f);
    moon();
    redLights();
    earthnight();
}


void footBallGround()//z
{
    glBegin(GL_QUADS);
    glColor3ub(126, 175, 52);

    glVertex2f(-0.44f, -0.707f);
    glVertex2f(-0.44f,-0.99f);
    glVertex2f(0.24f, -0.995f);
    glVertex2f(0.24f, -0.71f);
    glEnd();

    GLfloat p1, q1, r1, tp2 =2.0f * PI;
    int tringle2;
    int i;
    p1=-0.09f;
    q1= -0.84f;
    r1 = 0.040f; //// ground circle
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (2,255,255);
    glVertex2f (p1,q1);
    for(i= 0; i<=tringle2; i++)
    {
        glVertex2f (
            p1+(r1*cos(i*tp2/tringle2)),
            q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd ();

    glLineWidth(3.5);//////////////////// left side er gorund black
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,-0.995f);
    glVertex2f(-0.44f, -0.707f);
    glEnd();

    glLineWidth(3.5);///////////////// right side er gorund black
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.24f,-0.995f);
    glVertex2f(0.24f, -0.707f);
    glEnd();


    glLineWidth(3.5);///////////////// uporer black line
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,-0.71f);
    glVertex2f(0.24f, -0.71f);
    glEnd();


    glLineWidth(3.5);///////////////// nicher black line
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,-0.99f);
    glVertex2f(0.24f, -0.99f);
    glEnd();

    glLineWidth(3.5);///////////////// majher black line
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.09f,-1.0f);
    glVertex2f(-0.09f, -0.7f);
    glEnd();
}
void goalpost()//z
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,0); ////////GOAL POST
    glVertex2f(-0.44f, -0.94f);
    glVertex2f(-0.44f, -0.78f);
    glVertex2f(-0.39f,-0.75f);
    glVertex2f(-0.39f, -0.91f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.80f);
    glVertex2f(-0.39f, -0.78f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.83f);
    glVertex2f(-0.39f, -0.81f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.86f);
    glVertex2f(-0.39f, -0.84f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.89f);
    glVertex2f(-0.39f, -0.87f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.92f);
    glVertex2f(-0.39f, -0.90f);
    glEnd();


    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.43f,-0.936f);
    glVertex2f(-0.425f, -0.77f);
    glEnd();


    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.42f,-0.932f);
    glVertex2f(-0.415f, -0.765f);
    glEnd();


    glLineWidth(3.0);////////////////////PARALLEL LINES FOR JAL
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.41f,-0.930f);
    glVertex2f(-0.405f, -0.760f);
    glEnd();
}



void goalposts()//z
{
    goalpost();
    glPushMatrix();
    glScalef(-1.0,1.0, 1.0);
    glTranslatef(0.2,0.0,0.0);
    goalpost();
    glPopMatrix();
}

void football()//z
{
    glPushMatrix();
    glTranslatef(footballx,-0.09,0.0f);
    GLfloat x=-0.30;
    GLfloat y=-0.75f;
    GLfloat radius =0.022f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub (255,201,55);
    glVertex2f(x, y); // center of circle
    for(int q= 0; q<= triangleAmount; q++)
    {
        glVertex2f( x + (radius * cos(q *  twicePi / triangleAmount)),
                    y + (radius * sin(q * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
}
void player()//z
{
    glBegin(GL_QUADS);
    glColor3ub(255,0,0); ////////GROUND PLAYER 1
    glVertex2f(-0.345f, -0.82f);
    glVertex2f(-0.345f, -0.77f);
    glVertex2f(-0.32f,-0.77f);
    glVertex2f(-0.32f, -0.82f);
    glEnd();

    GLfloat p1=-0.332f;
    GLfloat q1= -0.755f;
    GLfloat r1 = 0.015f; ////PLAYER 1 HEAD
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,255);
    glVertex2f (p1,q1);
    for(int i= 0; i<=tringle2; i++)
    {
        glVertex2f (
            p1+(r1*cos(i*tp2/tringle2)),
            q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd ();

    glLineWidth(3.5);////////////////////FIRST PLAYER RIGHT LEG
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.325f,-0.84f);
    glVertex2f(-0.325f, -0.82f);
    glEnd();

    glLineWidth(3.5);////////////////////FIRST PLAYER FIRST HAND
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.337f,-0.84f);
    glVertex2f(-0.337f, -0.82f);
    glEnd();

    glLineWidth(3.5);////////////////////FIRST PLAYER FIRST HAND
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.32f,-0.78f);
    glVertex2f(-0.305f, -0.79f);
    glEnd();

    glLineWidth(3.5);////////////////////FIRST PLAYER 2ND HAND
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.32f,-0.80f);
    glVertex2f(-0.310f, -0.81f);
    glEnd();
}

void players()//z
{
    glPushMatrix();
    glTranslatef(0.0f, playerpos -0.04, 0.0f);
    player();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, -playerpos -0.04, 0.0f);
    glPushMatrix();
    glScalef(-1.0,1.0, 1.0);
    glTranslatef(0.2,0.0,0.0);
    player();
    glPopMatrix();
    glPopMatrix();
}


void Ground()//z
{

    glPushMatrix();
    glTranslatef(-0.55,0.105,0.0);
    glScalef(0.8f, 0.8f, 1.0f);

    footBallGround();
    football();
    goalposts();
    players();
    glPopMatrix();
}
//emon sesh

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    sky();

    switch (time)
    {
    case 2:
        day();
        break;
    // case 3:
    //    rainyday();
    //    break;
    case 4:
        night();
    }



    cloud();
    plane();
    river();
    ship();
    Boat1();
    mosque();
    house4();
    house1();
    house3();
    house();
    Ground();

    station();







    glFlush();

}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'i':
        time = 1;
        light = false;
        break;
    case 'd':
        time = 2;
        light = !light;
        rive = !rive;
        break;
    case 'r':
        time = 3;
        light = false;
        break;
    case 'n':
        time = 4;
        light = true;
        rive = true;
        break;
    case '0':
        exit(0);
        break;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Metro Rail Station");

    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
    // glutMouseFunc(handleMouse);
    // sound();
    glutMainLoop();
    return 0;
}

