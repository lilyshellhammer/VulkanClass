#version 400
#extension GL_ARB_separate_shader_objects  : enable
#extension GL_ARB_shading_language_420pack : enable

// non-opaque must be in a uniform block:
layout( std140, set = 0, binding = 0 ) uniform matBuf
{
        mat4 uModelMatrix;
        mat4 uViewMatrix;
        mat4 uProjectionMatrix;
		mat4 uNormalMatrix;
} Matrices;

layout( std140, set = 1, binding = 0 ) uniform lightBuf
{
	float uKa;
	float uKd;
	float uKs;
	vec4  uLightPos;
	vec3  uLightSpecularColor;
	float uShininess;
	vec4  uEyePos;
} Light;

layout( std140, set = 2, binding = 0) uniform miscBuf
{
	float uTime;
	int   uMode;
	int   uLightingFlag;
	float uDelta;
	int uNumInstances;
	int  uSTFlag;
} Misc;

layout( location = 0 ) in vec3 aVertex;
layout( location = 1 ) in vec3 aNormal;
layout( location = 2 ) in vec3 aColor;
layout( location = 3 ) in vec2 aTexCoord;

layout ( location = 0 ) out vec3 vColor;
layout ( location = 1 ) out vec2 vTexCoord;
layout ( location = 2 ) out vec3 vN;
layout ( location = 3 ) out vec3 vL;
layout ( location = 4 ) out vec3 vE;

void
main( ) 
{
	int numInst = 16;
	float delta = 3.0;

	mat4  P = Matrices.uProjectionMatrix;
	mat4  M = Matrices.uModelMatrix;
	mat4  V = Matrices.uViewMatrix;
	mat4 VM = V * M;
	mat4 PVM = P * VM;

	//vColor    = aInstanceColor;
	vColor = aColor;
	vTexCoord = aTexCoord;

	vN = normalize( vec3( Matrices.uNormalMatrix * vec4(aNormal, 1.) ) );
								// surface normal vector

	vec4 ECposition = M * vec4( aVertex, 1. );
	vec4 lightPos = vec4( Light.uLightPos.xyz, 1. );	// light source in fixed location
								// because not transformed

	vL = normalize( lightPos.xyz  -  ECposition.xyz );	// vector from the point
								// to the light

	vec4 eyePos = Light.uEyePos;
	vE = normalize( eyePos.xyz -  ECposition.xyz );		 // vector from the point
								 // to the eye

    float xdelta =  3.0 * float( gl_InstanceIndex % 4 );
    float ydelta = 3.0 * float( gl_InstanceIndex / 4 );
    vColor = vec3( 1., float( (1.+gl_InstanceIndex) ) / float( Misc.uNumInstances ), 0. );

    xdelta -= 3.0 * sqrt( float(16.0) ) / 2.;
    ydelta -= 3.0 * sqrt( float(16.0) ) / 2.;
    vec4 vertex = vec4( aVertex.xyz + vec3( xdelta, ydelta, 0. ), 1. );
    gl_Position = PVM * vertex;

}