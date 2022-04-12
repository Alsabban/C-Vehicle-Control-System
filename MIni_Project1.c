#include <stdio.h>
#include <stdlib.h>

//enum defining status
enum status{
	ON=1,OFF=0
};

//Vehicle defined as structure
struct vehicle{
	float Engine_Temperature;
	float Room_Temperature;
	char Speed;
	enum status Engine_Status;
	char Traffic_Light;
	enum status AC_Status;
	enum status Engine_Temp_Ctrl_Status;
};

//Vehicle Status Print function, the status enum was handled to print strings "ON"/"OFF" using an inline condition.
void Print_Status(struct vehicle *veh){
	printf("Engine Status:%s\nEngine Temperature:%f\nEngine Temperature Control:%s\nVehicle Speed:%d\nRoom Temperature:%f\nAC status:%s\n\n",
			veh->Engine_Status==1? "ON":"OFF",
					veh->Engine_Temperature,
					veh->Engine_Temp_Ctrl_Status==1? "ON":"OFF",
							veh->Speed,
							veh->Room_Temperature,
							veh->AC_Status==1? "ON":"OFF");
}

//What happens when engine is off.
//By quitting, the character 'c' is returned to the main function to terminate.
char Engine_off(struct vehicle* veh){
	char input;
	while(1){
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		scanf(" %c", &input);
		if(input=='b'||input=='B'){
			printf("Engine is OFF\n");
			continue;
		}

		else if(input=='a'||input=='A'){
			veh->Engine_Status=ON;
			printf("Engine is ON\n\n");
			return 'a';
		}

		else if(input=='c'||input=='C')
		{
			printf("Quitting...\n");
			return 'c';
		}
		else{
			printf("!!!Enter a valid character!!!\n\n");
		}
	}
}

//Check any change in the vehicle
void Check_Change(struct vehicle *veh){
	//Check Traffic Light change
	if(veh->Traffic_Light=='G'){
		veh->Speed=100;
	}
	else if(veh->Traffic_Light=='Y'){
		veh->Speed=30;
	}
	else{
		veh->Speed=0;
	}


	//Check Room temperature
	if(veh->Room_Temperature<10||veh->Room_Temperature>30){
		veh->AC_Status=ON;
		veh->Room_Temperature=20;
	}
	else{
		veh->AC_Status=OFF;
	}


	//Check Engine temperature
	if(veh->Engine_Temperature<100||veh->Engine_Temperature>150){
		veh->Engine_Temp_Ctrl_Status=ON;
		veh->Engine_Temperature=125;
	}
	else{
		veh->Engine_Temp_Ctrl_Status=OFF;
	}


	//Check Vehicle speed
	if(veh->Speed==30){
		if(veh->AC_Status==OFF){
			veh->AC_Status=ON;
			veh->Room_Temperature*=(5.00/4.00);
			veh->Room_Temperature++;
			veh->Engine_Temp_Ctrl_Status=ON;
			veh->Engine_Temperature*=(5.00/4.00);
			veh->Engine_Temperature++;
		}
	}
}

//Change Traffic Light value. A character (c) was used to check that no false character was entered directly to the struct data
void Change_TL(struct vehicle *veh){
	char c;
	while(1){
		printf("Enter the new value for the Traffic light:\nG-green\nR-red\nY-yellow\n\n");
		scanf(" %c",&c);
		if (c=='G'||c=='R'||c=='Y'){
			veh->Traffic_Light=c;
			return;
		}
		else{
			printf("!!!Enter a valid character!!!\n\n");
		}
	}
}

//Change Room Temperature value
void Change_Room_Temp(struct vehicle *veh){
	printf("Enter the new value for the Room Temperature:\n\n");
	scanf(" %f",&(veh->Room_Temperature));
}

//Change Engine Temperature value
void Change_Engine_Temp(struct vehicle *veh){
	printf("Enter the new value for the Engine Temperature:\n\n");
	scanf(" %f",&(veh->Engine_Temperature));
}

//What happens when the engine is on.
//Each option calls a previously defined function to change a the value requested
void Engine_On(struct vehicle *veh){
	char input;
	while(1){
		Check_Change(veh);
		Print_Status(veh);
		printf("a. Turn off the engine\n");
		printf("b. Set the traffic light color\n");
		printf("c. Set the room temperature\n");
		printf("d. Set the engine temperature\n\n");
		scanf(" %c",&input);

		if(input=='a'||input=='A'){
			veh->Engine_Status=OFF;
			return;
		}

		if(input=='b'||input=='B'){
			Change_TL(veh);
			continue;
		}

		if(input=='c'||input=='C'){
			Change_Room_Temp(veh);
			continue;
		}

		if (input=='d'||input=='D'){
			Change_Engine_Temp(veh);
			continue;
		}

	}
}


int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	struct vehicle veh={125.0,20.0,100,OFF,'G',OFF,OFF};
	struct vehicle *veh_ptr=&veh;
	//infinite loop checking the engine status to enter the corresponding function.
	while(1){
		if(veh.Engine_Status==OFF){
			//function is called, if the return value is'c', program terminates.
			if(Engine_off(veh_ptr)=='c'){
				return 0;
			}
		}
		else if(veh.Engine_Status==ON){
			Engine_On(veh_ptr);
		}
	}
}
