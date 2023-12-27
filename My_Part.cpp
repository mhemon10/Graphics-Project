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

//    GLfloat radius = 0.8f; //radius
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
void day()
{

    sky();
    cloud();
    sun1();
    sun2();


}


void night()
{


    nightSky();
    cloud();
    //stars
//    stars(0.5f, 0.8f);
//    stars(-0.1f, 0.7f);
//    stars(-0.3f, 0.8f);
//    stars(-0.1f, 0.95f);
//    stars(-0.5f, 0.8f);
//    stars(-0.6f, 0.91f);
//    stars(0.6f, 0.95f);
    moon();
//    redLights();
//    earthnight();
}




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


    river();
    cloud();
    plane();
//    river();
    ship();
    Boat1();
//    mosque();
    house4();
    house1();
    house3();
    house();

//    Ground();

//    station();







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
