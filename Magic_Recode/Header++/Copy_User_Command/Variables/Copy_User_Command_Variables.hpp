#pragma once

__int8 Strafe_Optimizer_Optimize;

float Strafe_Optimizer_Required_Speed;

float Strafe_Optimizer_Least_Allowed_Distance_To_Wall;

float Strafe_Optimizer_Ray_Angle_Step_Length;

float Strafe_Optimizer_Desired_Gain;

float Strafe_Optimizer_Greatest_Possible_Strafe_Angle;

std::vector<Compressed_User_Command_Structure> Recorded_User_Commands;

unsigned __int32 Recorder_User_Comamand_Number;

__int8 Route_Recorder_Record;

std::vector<Route_Structure> Recorded_Route;

void* Original_Copy_User_Command_Caller_Location;
