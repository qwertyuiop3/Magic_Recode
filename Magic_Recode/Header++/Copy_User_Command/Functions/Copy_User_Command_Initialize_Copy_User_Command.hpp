#pragma once

void Initialize_Copy_User_Command()
{
	Recorded_User_Commands.clear();

	Recorder_User_Comamand_Number = 0;

	Route_Recorder_Record = 0;

	Recorded_Route.clear();

	Strafe_Optimizer_Optimize = 0;

	Strafe_Optimizer_Desired_Gain = 0;

	Strafe_Optimizer_Optimize_When_Horizontal_Mouse_Difference_Greater_Than_X = 0;

	Strafe_Optimizer_Greatest_Possible_Strafe_Angle = 0;
}
