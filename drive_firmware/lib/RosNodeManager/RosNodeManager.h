#ifndef _ELYIR_NODE_MGR_
#define _ELYIR_NODE_MGR_

#include <ros.h>


void ros_node_mgr_setup(int logLevel);
void ros_node_mgr_run();
void ros_node_mgr_advertise(ros::Publisher publisher);

ros::NodeHandle ros_node_mgr_get_handle();

bool ros_node_mgr_connected();
// template <typename T>
// void ros_node_mgr_publish(ros::Publisher *publisher, T msg);
#endif