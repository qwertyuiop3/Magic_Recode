#pragma once

struct User_Command_Structure
{
	__int8 Additional_Bytes_1[12];

	float View_Angles[3];

	float Forward_Move;

	float Side_Move;

	float Up_Move;

	__int32 Pressed_Buttons;

	unsigned __int8 Impulse;

	__int8 Additional_Bytes_2[14];

	__int16 Mouse_Difference_X;

	__int16 Mouse_Difference_Y;
};