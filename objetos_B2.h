//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
    _puntos3D();
    void 	draw_puntos(float r, float g, float b, int grosor);

    vector<_vertex3f> vertices;
//vector<_vertex3f> colores_vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

        _triangulos3D();
    void 	draw_aristas(float r, float g, float b, int grosor);
    void    draw_solido(float r, float g, float b);
    void 	draw_solido_colores();
    void 	draw(_modo modo, float r, float g, float b, float grosor);
    /* asignación de colores */
    void 	colors_random();
    void 	colors_chess(float r1, float g1, float b1, float r2, float g2, float b2);

    vector<_vertex3i> caras;
    vector<_vertex3f> colores_caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

    void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
       
// tipo 0 --> Normal, tipo 1 --> cono, tipo 2 --> esfera.  tapa_in 0/1 --> Sin tapa / Con tapa,  tapa_sup 0/1 --> Sin tapa / Con tapa.
       
    void  parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_sup);
};

// CILINDRO.

class _cilindro: public _rotacion
{
public:
       _cilindro(float radio=1.0, float altura=0.5, int num=12);
};

//CONO.

class _cono: public _rotacion{
public:
    _cono(float radio, float altura, int num);
    
};

//ESFERA.

class _esfera: public _rotacion{
public:
    _esfera(float radio, int num1, int num2);
    
};

//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};

class _rotacion_PLY : public _rotacion{
public: 
    _rotacion_PLY();
    void parametros_PLY(char *archivo, int num);
};

//************************************************************************
// práctica 3, objeto jerárquico articulado excavadora
//************************************************************************

//************************************************************************
// piezas
//************************************************************************

//************************************************************************
// pala
//************************************************************************

class _pala: public _triangulos3D
{
public:
      _pala(float radio=1.0, float ancho=2.0, int num=8);
};

//************************************************************************
// brazo
//************************************************************************

class _brazo: public _triangulos3D
{
public:
    _brazo();
    void  draw(_modo modo, float r, float g, float b, float grosor);

    float ancho;
    float alto;
    float fondo;

    protected:
    _cubo cubo;
};

//************************************************************************
// cabina
//************************************************************************

class _cabina: public _triangulos3D
{
public:
    _cabina();
    void  draw(_modo modo, float r, float g, float b, float grosor);

    float ancho;
    float alto;
    float fondo;

protected:
    _cubo cubo;
};

//************************************************************************
// sustentación
//************************************************************************

class _sustentacion: public _triangulos3D
{
public:
    _sustentacion();
    void  draw(_modo modo, float r, float g, float b, float grosor);
        
    float ancho;
    float alto;
    float fondo;

    float radio;

protected:
    _cilindro rueda;
    _cubo base;
};

//************************************************************************
// excavadora (montaje del objeto final)
//************************************************************************

class _excavadora: public _triangulos3D
{
public:
    _excavadora();
       
    void  draw(_modo modo, float r, float g, float b, float grosor);

    float giro_cabina;
    float giro_primer_brazo;
    float giro_segundo_brazo;
    float giro_pala;

    float giro_primer_brazo_max;
    float giro_primer_brazo_min;
    float giro_segundo_brazo_max;
    float giro_segundo_brazo_min;
    float giro_pala_max;
    float giro_pala_min;

    float tamanio_pala;

protected:
    _pala pala;
    _brazo brazo;
    _cabina cabina;
    _sustentacion sustentacion;
};


class _capo: public _triangulos3D {
public:
    _capo();
    void  draw(_modo modo, float r, float g, float b, float grosor);

    float ancho;
    float alto;
    float fondo;

protected:
    _cubo cubo;
};

class _cabinacoche: public _triangulos3D
{
public:
    _cabinacoche();
    void  draw(_modo modo, float r, float g, float b, float grosor);

    float ancho;
    float alto;
    float fondo;

protected:
    _cubo cubo;
};

class _puerta: public _triangulos3D{
public:
    _puerta();
    void  draw(_modo modo, float r, float g, float b, float grosor);

    float ancho;
    float alto;
    float fondo;

protected:
    _cubo cubo;
};

class _ruedas: public _triangulos3D{
public:
    _ruedas();

    float ancho;
    float alto;
    float fondo;

    float radio;

    void draw(_modo modo, float r, float g, float b, float grosor);

protected:
    _cilindro rueda1, rueda2, rueda3, rueda4;
};

class _sustentacioncoche: public _triangulos3D {
public:
    _sustentacioncoche();
    void  draw(_modo modo, float r, float g, float b, float grosor);
    
    float ancho;
    float alto;
    float fondo;

    float radio;
    
    float getAncho();
    float getAlto();
    float getfondo();
    float getRadio();

protected:
    _cubo base;
    // _cilindro techo1, techo2;
};

class _coche: public _triangulos3D {
public:
    _coche();
    
    void  draw(_modo modo, float r, float g, float b, float grosor);
    
    float giro_puerta1;
    float giro_puerta2;
    float giro_puerta3;
    float giro_puerta4;
    
    float GIRO_MAXIMO_PUERTAS = 90;
    
protected:
    _sustentacioncoche sustentacion;
    _ruedas ruedas;
    //_puerta puerta1, puerta2, puerta3, puerta4;
};
