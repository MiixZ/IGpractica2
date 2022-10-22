//**************************************************************************
// Práctica 2 
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
    int i;
    glPointSize(grosor);
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    for (i=0;i<vertices.size();i++){
        glVertex3fv((GLfloat *) &vertices[i]);
        }
    glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
    int i;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLES);
    for (i=0; i<caras.size(); i++){
        glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
        glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
        glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
        }
    glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores()
{
    int i;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    
    for (i=0;i<caras.size();i++){
        glColor3f(colores_caras[i].r, colores_caras[i].g ,colores_caras[i].b);
        glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
        glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
        glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
        }
    glEnd();
}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(r, g, b, grosor);break;
	case SOLID:draw_solido(r, g, b);break;
	case SOLID_COLORS:draw_solido_colores();break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vértices
    vertices.resize(8); 
    vertices[0].x=-tam; vertices[0].y=0; vertices[0].z=tam;
    vertices[1].x=tam; vertices[1].y=0; vertices[1].z=tam;
    vertices[2].x=tam; vertices[2].y=0; vertices[2].z=-tam;
    vertices[3].x=-tam; vertices[3].y=0; vertices[3].z=-tam;
    vertices[4].x=-tam; vertices[4].y=tam*2; vertices[4].z=tam;
    vertices[5].x=tam; vertices[5].y=tam*2; vertices[5].z=tam;
    vertices[6].x=tam; vertices[6].y=tam*2; vertices[6].z=-tam;
    vertices[7].x=-tam; vertices[7].y=tam*2; vertices[7].z=-tam;
    
//colores vértices.
    /*colores_vertices.resize(8);    // valores entre 0 y 1.
    colores_vertices[0].r=0; colores_vertices[0].g=0.5; colores_vertices[0].b=0.5;
    colores_vertices[1].r=0.35; colores_vertices[1].g=0.15; colores_vertices[1].b=0.45;
    colores_vertices[2].r=0.6; colores_vertices[2].g=0.8; colores_vertices[2].b=0.11;
    colores_vertices[3].r=0,99; colores_vertices[3].g=0.99; colores_vertices[3].b=0.99;
    colores_vertices[4].r=0.1; colores_vertices[4].g=0.65; colores_vertices[4].b=0.29;
    colores_vertices[5].r=0.35; colores_vertices[5].g=0.84; colores_vertices[5].b=0.99;
    colores_vertices[6].r=0,99; colores_vertices[6].g=0.19; colores_vertices[6].b=0.79;
    colores_vertices[7].r=0.44; colores_vertices[7].g=0.41; colores_vertices[7].b=0.24;*/
    
// caras
    caras.resize(12);
    caras[0]._0=0; caras[0]._1=1; caras[0]._2=4;
    caras[1]._0=1; caras[1]._1=4; caras[1]._2=5;
    caras[2]._0=1; caras[2]._1=5; caras[2]._2=6;
    caras[3]._0=1; caras[3]._1=2; caras[3]._2=6;
    caras[4]._0=2; caras[4]._1=3; caras[4]._2=6;
    caras[5]._0=3; caras[5]._1=7; caras[5]._2=6;
    caras[6]._0=0; caras[6]._1=3; caras[6]._2=4;
    caras[7]._0=3; caras[7]._1=4; caras[7]._2=7;
    caras[8]._0=0; caras[8]._1=1; caras[8]._2=3;
    caras[9]._0=1; caras[9]._1=2; caras[9]._2=3;
    caras[10]._0=4; caras[10]._1=5; caras[10]._2=7;
    caras[11]._0=5; caras[11]._1=6; caras[11]._2=7;
    
//colores caras.
    colores_caras.resize(12);    // valores entre 0 y 1.
    colores_caras[0].r=0; colores_caras[0].g=0.5; colores_caras[0].b=0.5;
    colores_caras[1].r=0.2; colores_caras[1].g=1; colores_caras[1].b=0.4;
    colores_caras[2].r=0.6; colores_caras[2].g=0.8; colores_caras[2].b=0.8;
    colores_caras[3].r=0.8; colores_caras[3].g=0.6; colores_caras[3].b=0.6;
    colores_caras[4].r=1; colores_caras[4].g=0.4; colores_caras[4].b=0.2;
    colores_caras[5].r=0.1; colores_caras[5].g=0.2; colores_caras[5].b=1;
    colores_caras[6].r=0.2; colores_caras[6].g=1; colores_caras[6].b=0.4;
    colores_caras[7].r=0.6; colores_caras[7].g=0.8; colores_caras[7].b=0.8;
    colores_caras[8].r=0.8; colores_caras[8].g=0.6; colores_caras[8].b=0.6;
    colores_caras[9].r=0.11; colores_caras[9].g=0.23; colores_caras[9].b=0.2;
    colores_caras[10].r=0.1; colores_caras[10].g=0.2; colores_caras[10].b=1;
    colores_caras[11].r=0.19; colores_caras[11].g=0.85; colores_caras[11].b=0.33;

}



_cilindro::_cilindro(float radio, float altura, int num){           // Añadir el enum, la tecla y en el main.
    vector<_vertex3f> perfil;
    _vertex3f vert_aux;
    
    vert_aux.x = radio;
    vert_aux.y = -altura/2.0;
    vert_aux.z = 0.0;
    
    perfil.push_back(vert_aux);
    
    vert_aux.x = radio;
    vert_aux.y = altura/2.0;
    vert_aux.z = 0.0;
    
    perfil.push_back(vert_aux);
    
    parametros(perfil, num, 0, 1, 1);
}

_cono::_cono(float radio, float altura, int num)
{
    vector <_vertex3f> perfil;
    _vertex3f vert_aux;
    vert_aux.x = radio;
    vert_aux.y = 0.0;
    vert_aux.z = 0.0;
    perfil.push_back(vert_aux);
    vert_aux.x = 0.0;
    vert_aux.y = altura;
    vert_aux.z = 0.0;
    perfil.push_back(vert_aux);
    
    parametros(perfil, num, 1, 1, 1);
}


_esfera::_esfera(float radio, int num1, int num2)
{
    vector <_vertex3f> perfil;
    _vertex3f vert_aux;
    
    for(int i = 1 ; i < num1 ; i++){
        vert_aux.x = radio*cos(M_PI*i/num1-M_PI/2.0);
        vert_aux.y = radio*sin(M_PI*i/num1-M_PI/2.0);
        vert_aux.z = 0.0;
        perfil.push_back(vert_aux);
    }
    
    parametros(perfil, num2, 2, 1, 1);
}



//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
    vertices.resize(5); 
    vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
    vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
    vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
    vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
    vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

    caras.resize(6);
    caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
    caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
    caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
    caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
    caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
    caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
    
    colores_caras.resize(6);
    srand(10);
    for(int i = 0; i < 6; i++){
        colores_caras[i].r = rand()%1000/1000.0;
        colores_caras[i].g = rand()%1000/1000.0;
        colores_caras[i].b = rand()%1000/1000.0;
        
    }
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



void _objeto_ply::parametros(char *archivo)
{                                           // OBJETO TECLA "o"     
    int n_ver,n_car;

    vector<float> ver_ply ;
    vector<int>   car_ply ;
    
    _file_ply::read(archivo, ver_ply, car_ply );

    n_ver=ver_ply.size()/3;
    n_car=car_ply.size()/3;

    printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

    vertices.resize(n_ver);
    caras.resize(n_car);

// vértices                                 EN EL FICHERO .ply ESTÁN TODOS LOS DATOS NECESARIOS PARA CONSTRUIR EL OBJETO.
    for(int i = 0; i < n_ver; i++){
        vertices[i].x = ver_ply[i*3];
        vertices[i].y = ver_ply[i*3 + 1];
        vertices[i].z = ver_ply[i*3 + 2];
    }

// caras
    for(int i = 0; i < n_car; i++){
        caras[i].x = car_ply[i*3];
        caras[i].y = car_ply[i*3 + 1];
        caras[i].z = car_ply[i*3 + 2];
    }

//colores caras
    colores_caras.resize(n_car);
    srand(10);
    for(int i = 0; i < n_car; i++){
        colores_caras[i].r = rand()%1000/1000.0;
        colores_caras[i].g = rand()%1000/1000.0;
        colores_caras[i].b = rand()%1000/1000.0;
        
        if(vertices[caras[i]._0].y >= 0){
            colores_caras[i].r = rand()%1000/1000.0;
            colores_caras[i].b = 0;
            colores_caras[i].g = 0;
        }
        else{
            int n = rand() % 10;
            int sum = rand() % 100 / 500.0;
            if(n < 5){ 
                colores_caras[i].r = 0.255;
                colores_caras[i].b = 0.5 + sum;
                colores_caras[i].g = 0.5 - sum;
            }
            else{
                colores_caras[i].r = 0.6;
                colores_caras[i].b = rand()%1000/1000.0;
                colores_caras[i].g = rand()%1000/1000.0;
            }
        }
    }
}


//************************************************************************
// objeto por revolución
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_sup)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;        // TAMAÑO DEL PERFIL.

// tratamiento de los vértices

    float radio;
    if (tipo == 2) radio = sqrt((perfil[0].x*perfil[0].x) + (perfil[0].y*perfil[0].y));

    num_aux=perfil.size();
    vertices.resize(num_aux*num + 2); // +1  para añadir el centro.

    for (j=0;j<num;j++){
        for (i=0;i<num_aux;i++){          // SE GIRAN UN CIERTO ÁNGULO.
            vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+          // ESTA TRANSFORMACIÓN VIENE EN LAS DIAPOSITIVAS DE TEORÍA.
                            perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
            vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                            perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
            vertice_aux.y=perfil[i].y;
            vertices[i+j*num_aux]=vertice_aux;
        }
    }

// tratamiento de las caras 

    int num_caras = 2*(num_aux - 1) * num + 2*num;
    caras.resize(num_caras);
    int c = 0;
    
    for(int j = 0; j < num ; j++){
        for(int i = 0; i < num_aux - 1; i++){    // -1 porque es el número de segmentos que se pueden crear entre los puntos del perfil.
            caras[c]._0 = i + j*num_aux;
            caras[c]._1 = ((j + 1) % num)*num_aux + i;
            caras[c]._2 = 1 + i + j*num_aux;        // Todos los + 1 significan que quiero ir al siguiente punto del triángulo.
            
            c++;
            
            caras[c]._0 = ((j + 1) % num)*num_aux + i;
            caras[c]._1 = ((j + 1) % num)*num_aux + i + 1;
            caras[c]._2 = 1 + i + j*num_aux;
            c++;
        }
    }
    
// Colores caras.

    colores_caras.resize(num_caras);
    srand(10);
    for(int i = 0; i < num_caras; i++){
        colores_caras[i].r = rand()%1000/1000.0;
        colores_caras[i].g = rand()%1000/1000.0;
        colores_caras[i].b = rand()%1000/1000.0;
        
    }
    
// tapa inferior
    int total_matriz = num_aux * num;
    
    vertices[total_matriz].x = 0.0;          // Centro de la tapa de abajo.
    if(tipo == 2) vertices[total_matriz].y = -radio;
    else vertices[total_matriz].y = perfil[0].y;
    
    vertices[total_matriz].z = 0.0;
    
    for(int j = 0; j < num ; j++){    
        caras[c]._0 = j*num_aux;
        caras[c]._1 = ((j + 1) % num)*num_aux;
        caras[c]._2 = total_matriz;       
        
        c++;
    }

// tapa superior
    vertices[total_matriz + 1].x = 0.0;          // Centro de la tapa de arriba.
    
    if(tipo == 1) vertices[total_matriz+1].y = perfil[1].y;
    else if(tipo == 2) vertices[total_matriz+1].y = radio; 
        else vertices[total_matriz + 1].y = perfil[num_aux - 1].y;
               
    vertices[total_matriz + 1].z = 0.0;
    
    for(int j = 0; j < num ; j++){   
        caras[c]._0 = total_matriz + 1;
        caras[c]._1 = ((j + 1) % num)*num_aux + num_aux - 1;
        caras[c]._2 = j*num_aux + num_aux - 1; 
        
        c++;
    }
}


//************************************************************************
// objeto por extrusión
//************************************************************************


_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
    int i;
    _vertex3f vertice_aux;
    _vertex3i cara_aux;
    int num_aux;

// tratamiento de los vértices.

    num_aux=poligono.size();
    vertices.resize(num_aux*2);
    for (i=0;i<num_aux;i++)
        {
        vertices[2*i]=poligono[i];
        vertices[2*i+1].x=poligono[i].x+x;
        vertices[2*i+1].y=poligono[i].y+y;
        vertices[2*i+1].z=poligono[i].z+z;
        }
    
// tratamiento de las caras 

    int num_Caras = num_aux * 2;
    caras.resize(num_Caras);
    int c=0;
    for (i=0;i<num_aux;i++){
        caras[c]._0=i*2;
        caras[c]._1=(i*2+2)%(num_Caras);
        caras[c]._2=i*2+1;    
        c=c+1;
        caras[c]._0=(i*2+2)%(num_Caras);
        caras[c]._1=(i*2+2)%(num_Caras)+1;
        caras[c]._2=i*2+1;    
        c=c+1;    
    }   
    
    colores_caras.resize(num_Caras);
    srand(10);
    for(int i = 0; i < num_Caras; i++){
        colores_caras[i].r = rand()%1000/1000.0;
        colores_caras[i].g = rand()%1000/1000.0;
        colores_caras[i].b = rand()%1000/1000.0;
    }
}


//************************************************************************
// Clase rotación PLY
//************************************************************************

_rotacion_PLY::_rotacion_PLY(){}

void _rotacion_PLY::parametros_PLY(char *archivo, int num){
	int n_ver,n_car;
	vector<_vertex3f> perfil;
	vector<float> ver_ply ;
	vector<int>   car_ply ;
	
	_file_ply::read(archivo, ver_ply, car_ply );

	n_ver=ver_ply.size()/3;

	printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

	vertices.resize(n_ver);

	//vertices
	for(int i=0; i < n_ver; i++){
		vertices[i].x=ver_ply[3*i];
		vertices[i].y=ver_ply[3*i+1];
		vertices[i].z=ver_ply[3*i+2];
		perfil.push_back(vertices[i]);
	}

	//Colores para los vertices
	/*colores_vertices.resize(n_ver); //color entre 0 y 1
	for(int i=0; i < 5; i++){
		colores_vertices[i].r= rand()%1000/1000.0;
		colores_vertices[i].g= rand()%1000/1000.0;
		colores_vertices[i].b= rand()%1000/1000.0;
	}*/

    parametros(perfil, num, 0, 1, 1);
}

