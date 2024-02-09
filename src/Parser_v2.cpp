﻿#include <fstream>
#include <sstream>
//#include <iostream>

#include"TargetMessage.h"
using namespace std;


unsigned char buf[] =
{ 0xAB, 0xCD, 0x00, 0xFB, 0x4A, 0x42, 0x00, 0x1B, 0x01, 0x00, 0x02,
	0x0C, 0x0E, 0x16, 0x08, 0x08, 0x06, 0x1D, 0x08, 0x05, 0x00, 0x1B,
	0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x01, 0x08, 0x4A, 0x4D, 0x42,
	0x00, 0xB3, 0xD4, 0x03, 0x67, 0xFF, 0xA0, 0xFF, 0x41, 0x00, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x50, 0x00, 0xFF, 0xFF,
	0xFF, 0xA0, 0x00, 0x00, 0x03, 0x67, 0x00, 0x2D, 0x12, 0xD6, 0x03,
	0xA0, 0x00, 0x82, 0x00, 0xD7, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x82, 0x00, 0x00,
	0x03, 0xA0, 0x00, 0x31, 0x12, 0xD0, 0x03, 0xD2, 0xFF, 0x91, 0xFE,
	0xE1, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFD, 0x46, 0x95,
	0x00, 0xFF, 0xFF, 0xFF, 0x91, 0x00, 0x00, 0x03, 0xD2, 0x00, 0x2D,
	0x12, 0xD5, 0x04, 0x34, 0x00, 0x67, 0x00, 0xFE, 0x00, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0xA9, 0x00, 0x00, 0x00, 0x00,
	0x67, 0x00, 0x00, 0x04, 0x34, 0x00, 0x2D, 0x12, 0xD2, 0x07, 0x4E,
	0x00, 0x82, 0x00, 0xF2, 0x00, 0x08, 0x15, 0x9D, 0x00, 0xEB, 0x00,
	0x02, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x82, 0x00, 0x00, 0x07,
	0x4E, 0x00, 0x2D, 0x12, 0xD3, 0x08, 0x58, 0xFF, 0xB3, 0xFE, 0xCE,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x46, 0x22, 0x00,
	0xFF, 0xFF, 0xFF, 0xB3, 0x00, 0x00, 0x08, 0x58, 0x00, 0x2D, 0x12,
	0x1C, 0x44, 0x4C, 0x00, 0x2D, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
	0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
	0x00, 0xE1, 0x8E };






int main()
{
	ofstream of("output.txt");
	size_t buf_size = sizeof(buf) / sizeof(buf[0]);
	Target_Message tm;

	for (size_t it = 0; it < buf_size; ++it) {
		if (buf[it] == 0x4D && buf[it + 1] == 0x42) {
			//next data after type information bytes
			it += 2;
			tm.module_data_length = buf[it] + buf[it + 1];
			int count_frames = ((tm.module_data_length - 2 - 2 - 1) / 29);// 2-type length, 2-module data length,1- verification length, 29- frame size

			of << "Target message module." << '\n';
			of << "Module data length: " << tm.module_data_length << '\n';
			it += 2;//next modul data length size

			//loop parsing n information frames 
			for (size_t frame = 1; frame != count_frames + 1; ++frame) {
				TargetMessage(buf, tm, it);

				of << "The " << frame << "th goal numbering: " << tm.the_Nth_goal_numbering << '\n';
				of << "Vertical distance: " << (tm.vertical_distance * 0.1) << "m" << '\n';
				of << "Lateral distance: " << (tm.lateral_distance * 0.1) << "m" << '\n';
				of << "Speed (y direction): " << (tm.speed_y_direction * 0.1) << "m" << '\n';
				of << "Target Type: " << tm.target_type << '\n';
				of << "Lane Number: " << tm.lane_number << '\n';
				of << "Front spacing: " << (tm.front_spacing * 0.1) << "m" << '\n';
				of << "Front time interval: " << (tm.front_time_interval * 0.1) << "m" << '\n';
				of << "Speed (x direction): " << (tm.speed_x_direction * 0.1) << "m" << '\n';
				of << "Heading angle: " << tm.heading_angle % 360 << '\n';
				of << "Incidents: ";
				switch (tm.incidents)
				{
				case(0):
					of << "No event occurred" << '\n';
					break;
				case(1):
					of << "Unblocked parking" << '\n';
					break;
				case(2):
					of << "Congested Parking" << '\n';
					break;
				case(3):
					of << "Vehicle Overspeed" << '\n';
					break;
				case(4):
					of << "Harbour Parking" << '\n';
					break;
				case(5):
					of << "Slow Moving vehicles" << '\n';
					break;
				case(6):
					of << "Pedestrian" << '\n';
					break;
				case(7):
					of << "Retrograde Vehicle" << '\n';
					break;
				case(8):
					of << "Change of direction" << '\n';
					break;
				default:
					break;
				}

				of << "Radar Network X-sit Standard: " << (tm.radar_network_X * 0.1) << "m" << '\n';
				of << "Radar Network Y-sit: " << (tm.radar_network_Y * 0.1) << "m" << '\n';
				of << "Fill the blind mark: " << tm.fill_the_blind_mark << '\n';
				of << "Car length: " << (tm.car_length * 0.1) << "m" << '\n';
				of << "Car width: " << (tm.car_width * 0.1) << "m" << '\n';
				of << "===" << '\n';

			}
			tm.module_verification = buf[it];
			of << "Module verification: " << tm.module_verification << '\n';
			of << "===================================================" << '\n';
		}
	}
	return 0;
}




