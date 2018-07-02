#include "node_options.h"
#include<string>
#include<iostream>

using namespace std;
main(){
	string configuration_directory = 
	"/home/user/Ring-Demo-arm-addlua/configuration_file";
	string configuration_basename  = "config_arm.lua";
	NodeOptions node_options;
	node_options = 
	LoadOptions(configuration_directory, configuration_basename);
	cout<<"baseStation_Name:     "<<node_options.baseStation_Name<<endl;
	cout<<"baseStation_ID  :    "<<node_options.baseStation_ID<<endl;
	cout<<"baseStation_Ip  :    "<<node_options.baseStation_Ip<<endl;
}
