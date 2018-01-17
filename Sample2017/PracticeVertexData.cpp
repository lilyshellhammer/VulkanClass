

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
	// triangle 0-2-3:
	// vertex #0:
	{
		{ -1., -1., -1. },
		{ 0.,  0., -1. },
		{ 0.,  0.,  0. },
		{ 1., 0. }
	},

	// vertex #2:
	{
		{ -1.,  1., -1. },
		{ 0.,  0., -1. },
		{ 0.,  1.,  0. },
		{ 1., 1. }
	},

	// vertex #3:
	{
		{ 1.,  1., -1. },
		{ 0.,  0., -1. },
		{ 1.,  1.,  0. },
		{ 0., 1. }
	},


	// triangle 0-3-1:
	// vertex #0:
	{
		{ -1., -1., -1. },
		{ 0.,  0., -1. },
		{ 0.,  0.,  0. },
		{ 1., 0. }
	},

	// vertex #3:
	{
		{ 1.,  1., -1. },
		{ 0.,  0., -1. },
		{ 1.,  1.,  0. },
		{ 0., 1. }
	},

	// vertex #1:
	{
		{ 1., -1., -1. },
		{ 0.,  0., -1. },
		{ 1.,  0.,  0. },
		{ 0., 0. }
	},

};
