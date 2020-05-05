#pragma once

std::vector<User_Command_Structure> Recorded_User_Commands;

unsigned __int32 Recorder_User_Comamand_Number;

__int8 Visuals_Recorder_Route_Record;

struct Floating_Point_3
{
	float Floating_Point_3[3];
};

std::vector<Floating_Point_3> Recorded_Route;

void* Original_Copy_User_Command_Caller_Location;