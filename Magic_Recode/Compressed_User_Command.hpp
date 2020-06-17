#pragma once

struct Compressed_User_Command_Structure
{
	float View_Angles[3];

	float Move[3];

	__int32 Buttons_State;

	unsigned __int8 Impulse;

	__int16 Mouse_Difference_X;

	__int16 Mouse_Difference_Y;
};