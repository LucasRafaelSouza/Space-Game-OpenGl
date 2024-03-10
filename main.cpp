
#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//M_PI
//componentes iomportantes
static int f = 16;
static int p = 16;


GLuint texsol,tex1,tex2,tex3,tex4,tex5,tex6,tex7,tex8,tex9;
GLUquadricObj *pSphere = NULL;

int op = 1;
int op2 = 1;
int op3 = 1;
double razao;
//luzes e material
const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 0.0f, -50.0f, 1.0f };

const GLfloat mat_ambient[]    = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };





//visualizacao
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
    razao = (double)width / (double)height;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

}
//carrega texturas
GLuint loadTex(const char* filename)
{
    GLuint tex_ID = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,(SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT));
        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, tex_ID );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        return tex_ID;
    }
//funcao de desenho
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;




    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    //luLookAt(0, 0, 0, 0, 0,-1, 0, 1, 0);
    if(op == 1){
        gluLookAt(0, 0, -100, 0, 0,0, 0, 1, 0);
    }
    else if(op == 2){
        gluLookAt(0, 100, -150, 0, 0,0, 0, 1,0);
        //0, 20, -50, 0, 0,-1, 0, 1, 0  // 0, -50, 20, 0, 0,-1, 0, 1, 0
    }

//0, 100, -150, 0, 0,0, 0, 1,0

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




//sol
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texsol);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();

        glTranslated(0,0,-50);
        glRotated(a,0,1,0);
        //glutSolidSphere(2.3,f,p);

        gluSphere(pSphere, 2.3, 32, 32);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();




//planeta 1


    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(a,0,1,0);
        glTranslated(0,0,5);
        //glutSolidSphere(0.7,f,p);

        if(op3 == 1){
            glBindTexture(GL_TEXTURE_2D,tex1);
            glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 0.7, 32, 32);

    //teste
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

//planeta 2
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(a,0,1,0);
        glTranslated(25,0,10);
        //glutSolidSphere(1.2,f,p);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex2);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 0.7, 32, 32);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

//planeta 3
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(a,1,1,0);
        glTranslated(2,1,10);
        //glutSolidSphere(1.4,f,p);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex3);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 1.4, 32, 32);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
//planeta 4
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(-a,0,1,1);
        glTranslated(6,1,10);//1
        //glutSolidSphere(1.3,f,p);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex4);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 1.3, 32, 32);
     glDisable(GL_TEXTURE_2D);
    glPopMatrix();
//planeta 5
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(a/4,0,1,0);
        glTranslated(0,0,15);
        glutSolidSphere(1.5,f,p);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex5);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 1.5, 32, 32);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
//planeta 6
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(a,1,0,0);
        //glRotated(a,0,1,0);
        glTranslated(0,0,20);
        //glutSolidSphere(0.7,f,p);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex6);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 0.7, 32, 32);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
//planeta 8
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(a,0,1,0);
        //glRotated(a,0,1,0);
        glTranslated(0,4,6);
        //glutSolidSphere(1,f,p);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex7);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 1.1, 32, 32);
        glDisable(GL_TEXTURE_2D);
        glRotated(90,1,0,0);
        //teste, apagar
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex9);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glutSolidTorus(0.01,2,32,32);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
//planeta 9

    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(-a,0,1,0);
        //glRotated(a,0,1,0);
        glTranslated(0,0,8);
        //glutSolidSphere(1,f,p);
        //gluSphere(pSphere, 1, 32, 32);
        if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex8);
        glEnable(GL_TEXTURE_2D);
        }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(pSphere, 1, 32, 32);
        glDisable(GL_TEXTURE_2D);
        glRotated(120,1,1,0);
        //teste
         if(op3 == 1){
        glBindTexture(GL_TEXTURE_2D,tex8);
        glEnable(GL_TEXTURE_2D);
         }
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glutSolidTorus(0.1,2,32,32);
        glutSolidTorus(0.1,2.1,32,32);
        glutSolidTorus(0.1,2.2,32,32);
        glDisable(GL_TEXTURE_2D);

        //teste

   glPopMatrix();

   //luzes

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);



    glutSwapBuffers();
}

//callback de botoes
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a' :
            break;
        case 'e':
            exit(0);
            break;

        case 'c':
            if (op == 1){

            op = 2;
            //printf("camera de cima\n");
            }
            else if (op == 2){

              op = 1;
              //printf("camera lateral\n");
            }
            break;
        case 'l':
            if(op2 == 1){
            glDisable(GL_LIGHTING);
            op2 = 2;
            }
            else if(op2 == 2){
            glEnable(GL_LIGHTING);
            op2 = 1;
            }
            break;
        case 't':
            if(op3 == 1){

            op3 = 2;

            }
            else if (op3 == 2){

              op3 = 1;

            }
            break;
    }
    glutPostRedisplay();
}
//inicializa esferas e texturas
void inicializa() {


    //esferas
    pSphere = gluNewQuadric();
    gluQuadricDrawStyle(pSphere, GLU_FILL);
    gluQuadricNormals(pSphere, GLU_SMOOTH);
    gluQuadricTexture(pSphere, GLU_TRUE);
    //text
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    texsol = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/sun.jpg");
    tex1 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta1.jpg");
    tex2 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta2.jpg");
    tex3 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta3.jpg");
    tex4 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta4.jpg");
    tex5 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta5.jpg");
    tex6 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta6.jpg");
    tex7 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta7.jpg");
    tex8 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta8.jpg");
    tex9 = loadTex("C:/Users/WazPC/OneDrive/Documentos/TP2/bin/Debug/planeta9.jpg");



}

static void idle(void)
{
    glutPostRedisplay();

}
//luz





int main(int argc, char *argv[])
{
    //inicializacao
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glDepthFunc(GL_LEQUAL);                    //Deep test type
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutCreateWindow("TP02");
    inicializa();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);




    glClearColor(0,0,0,0);//(1,1,1,1)
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);



    glutMainLoop();

    return EXIT_SUCCESS;
}
