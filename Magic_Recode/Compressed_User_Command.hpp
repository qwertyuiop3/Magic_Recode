#pragma once

struct Compressed_User_Command_Structure
{
	float View_Angles[3];

	float Forward_Move;

	float Side_Move;

	float Up_Move;

	__int32 Buttons_State;

	unsigned __int8 Impulse;

	__int16 Mouse_Difference_X;

	__int16 Mouse_Difference_Y;
};