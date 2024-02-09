#pragma once

#ifndef TARGET_MESSAGE_H
#define TARGET_MESSAGE_H

#include <cstdint>  // For uint16_t and unsigned int
#include <cstddef>  // For size_t



struct Target_Message {
	uint16_t module_data_length = 0;
	uint16_t the_Nth_goal_numbering = 0;
	unsigned int vertical_distance = 0;
	unsigned int lateral_distance = 0;
	unsigned int speed_y_direction = 0;
	uint16_t target_type = 0;
	uint16_t lane_number = 0;
	unsigned int front_spacing = 0;
	unsigned int front_time_interval = 0;
	unsigned int speed_x_direction = 0;
	uint16_t heading_angle = 0;
	uint16_t incidents = 0;
	unsigned int radar_network_X = 0;
	unsigned int radar_network_Y = 0;
	uint16_t fill_the_blind_mark = 0;
	unsigned int car_length = 0;
	unsigned int car_width = 0;
	uint16_t module_verification = 0;
	uint16_t unknown_data = 0;
};

void TargetMessage(unsigned char* buf, Target_Message& tm, size_t& index);




#endif // TARGET_MESSAGE_H

