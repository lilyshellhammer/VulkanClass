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
	//Center for the 0, 0, 1 triangle for circle
	{
		{ 0. 0. 0. },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ 0.5 0. 0.5 }
	},

		{ 1 0. 0 },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ 0.5 0 }
	},

		{ 0 0. 0.866026 },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ -0.249999 0.433013 }
	},

	//Center for the 0, 1, 2 triangle for circle
	{
		{ 0. 0. 0. },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ 0.5 0. 0.5 }
	},

		{ 0 0. 0.866026 },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ -0.249999 0.433013 }
	},

		{ 0 0. 0 },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ -0.250002 -0.433012 }
	},

	//Center for the 0, 2, 3 triangle for circle
	{
		{ 0. 0. 0. },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ 0.5 0. 0.5 }
	},

		{ 0 0. 0 },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ -0.250002 -0.433012 }
	},

		{ 1 0. 0 },
		{ 1. 0. 1. },
		{ 1. 1. 1. },
		{ 0.5 -2.7336e-06 }
	},

};
