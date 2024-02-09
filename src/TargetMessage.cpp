#include "TargetMessage.h"

void TargetMessage(unsigned char* buf, Target_Message& tm, size_t& index) {
	//shift index of size data bytes
	tm.the_Nth_goal_numbering = buf[index + 1];//1
	++index;
	tm.vertical_distance = buf[index] + buf[index + 2];//2
	index += 2;
	tm.lateral_distance = buf[index] + buf[index + 2];//2
	index += 2;
	tm.speed_y_direction = buf[index] + buf[index + 2];//2
	index += 2;
	tm.target_type = buf[index];//1
	++index;
	tm.lane_number = buf[index];//1
	++index;
	tm.front_spacing = buf[index] + buf[index + 2];//2
	index += 2;
	tm.front_time_interval = buf[index] + buf[index + 2];//2
	index += 2;
	tm.speed_x_direction = buf[index] + buf[index + 2];//2
	index += 2;
	tm.heading_angle = buf[index] + buf[index + 2];//2
	index += 2;
	tm.incidents = buf[index];//1
	++index;
	tm.radar_network_X = buf[index] + buf[index + 2] + buf[index + 3] + buf[index + 4];//4
	index += 4;
	tm.radar_network_Y = buf[index] + buf[index + 2] + buf[index + 3] + buf[index + 4];//4
	index += 4;
	tm.fill_the_blind_mark = buf[index];;//1
	++index;
	tm.car_length = buf[index];;//1
	++index;
	tm.car_width = buf[index];//1
	++index;
};
