

// *******************
// VERTEX BUFFER DATA:
// *******************

#ifdef DEFINITION
struct vertex
{
	glm::vec3	position;
	glm::vec3	normal;
	glm::vec3	color;
	glm::vec2	texCoord;
};
#endif

struct vertex VertexData[] =
{
	// triangle 1:
	// vertex #0:
	{
		{ 2., 0., -2. },
		{ 0.,  0., 0. },
		{ 1.,  0.,  0. },
		{ 1., 0. }
	},

	// vertex #2:
	{
		{ 0.,  0., 0. },
		{ 0.,  0., -1. },
		{ 1.,  1.,  1. },
		{ 1., 1. }
	},

	// vertex #3:
	{
		{ 2.,  0., 2. },
		{ 0.,  0., -1. },
		{ 0.,  1.,  0. },
		{ 0., 1. }
	},


};
