#include "TargetMessage.h"

unsigned int Hex_parse(unsigned char* buf, size_t& index, size_t shift) {
	unsigned int result = 0;
	for (size_t it = 0; it < shift; ++it) {
		result = (result << 8) | buf[index + it];
	}
	index += shift;
	return result;
}

void TargetMessage(unsigned char* buf, Target_Message& tm, size_t& index) {
	//shift index of size data bytes
	tm.the_Nth_goal_numbering = Hex_parse(buf, index, 1);//1

	tm.vertical_distance = Hex_parse(buf, index, 2);//2

	tm.lateral_distance = Hex_parse(buf, index, 2);//2

	tm.speed_y_direction = Hex_parse(buf, index, 2);//2

	tm.target_type = Hex_parse(buf, index, 1);//1

	tm.lane_number = Hex_parse(buf, index, 1);//1

	tm.front_spacing = Hex_parse(buf, index, 2);//2

	tm.front_time_interval = Hex_parse(buf, index, 2);//2

	tm.speed_x_direction = Hex_parse(buf, index, 2);//2

	tm.heading_angle = Hex_parse(buf, index, 2);//2

	tm.incidents = Hex_parse(buf, index, 1);//1

	tm.radar_network_X = Hex_parse(buf, index, 4);//4

	tm.radar_network_Y = Hex_parse(buf, index, 4);//4

	tm.fill_the_blind_mark = Hex_parse(buf, index, 1);//1

	tm.car_length = Hex_parse(buf, index, 1);//1

	tm.car_width = Hex_parse(buf, index, 1);//1
};
