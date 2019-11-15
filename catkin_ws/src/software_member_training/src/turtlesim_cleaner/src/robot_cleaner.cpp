#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;

const double x_min = 0.0;
const double y_min = 0.0;
const double x_max = 11.0;
const double y_max = 11.0;

const double PI = 3.14159265359;

void move (double speed, double distance, bool isForward);
// method to move the robot straight
void move (double speed, double distance, bool isForward){
	geometry_msgs::Twist vel_msg;
	if(isForward)
		vel_msg.linear.x = abs(speed);
	else
		vel_msg.linear.x = -abs(speed);
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;
	
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = 0;
	
	double t0 = ros::Time::now().toSec();
	double curretn_distance = 0.0;
	ros::Rate loop_rate(100);
	do{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_angle = speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
	}while(current_distance < distance);
	vel_msg.linear.x = 0;
	velocity_publisher.publish(vel_msg);
}
void rotate (double angular_speed, double angle, bool clockwise){
	geometry_msgs::Twist vel_msg;
	vel_msg.linear.x = 0;
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;
	
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;

	if(clockwise)
		vel_msg.angular.z = -abs(angular_speed);
	else
		vel_msg.angular.z = abs(angular_speed);
	double current_angle = 0.0;
	double t0 = ros::Time::now().toSec();
	ros::Rate loop_rate(10);
	do{	
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_angle = angular_speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
	}while(current_angle < relative_angle);
	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);
}

double degrees2radians(double angle_in_degrees

int main(int argc, char ** argv){
	ros::init(argc,argv, "robot_cleaner");
	ros::NodeHandle n;
	double speed, angular_speed;
	double distance,angle;
	bool isForward, clockwise;

	velocity_publisher = n.advertise<geometry_msgs::Twist> ("/turtlel/cmd_vel" , 10);
	ros::Rate loop_rate(10);

	ROS_INFO(\n\n\n******************START TESTING************\n");
	cout << "enter speed: ";
	cin >> speed;
	cout << "enter distance: ";
	cin >> distance;
	cout << "forward?: ";
	cn >> isForward;
	move(speed,distance, isForward);
	
	cout << "enter angular velocity (degree/sec): ";
	cin >> angular_speed;
	cout << "enter desired angle (degrees): ";
	cin >> angle;
	cout "clockwise? "
	cin >> clockwise;

	rotate(degrees2radians(angular_speed), degrees2radians(angle) , clockwise);

	ros::spin();
	
	return 0;

}
