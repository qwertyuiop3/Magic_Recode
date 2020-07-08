#pragma once

struct Source_User_Command_Structure
{
	__int8 Additional_Bytes_1[12];

	float View_Angles[3];

	float Move[3];

	__int32 Buttons_State;

	unsigned __int8 Impulse;

	__int8 Additional_Bytes_2[14];

	__int16 Mouse_Difference_X;

	__int16 Mouse_Difference_Y;
};