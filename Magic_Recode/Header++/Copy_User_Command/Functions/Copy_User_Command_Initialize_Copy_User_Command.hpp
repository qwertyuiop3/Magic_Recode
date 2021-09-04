#pragma once

void Initialize_Copy_User_Command()
{
	Strafe_Optimizer_Optimize = 0;

	Strafe_Optimizer_Required_Speed = 0;

	Strafe_Optimizer_Least_Allowed_Distance_To_Wall = 0;

	Strafe_Optimizer_Ray_Angle_Step_Offset = 1;

	Strafe_Optimizer_Desired_Gain = 0;

	Strafe_Optimizer_Greatest_Possible_Strafe_Angle = 0;

	Recorded_User_Commands.Initialize();

	Recorder_User_Comamand_Number = 0;

	Route_Recorder_Record = 0;

	Recorded_Route.Initialize();
}