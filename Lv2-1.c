#include <stdio.h>	// Part 1 : Include the library
#include <stdbool.h>

struct PassengerClass;	// Part 2 : Declare the structer
struct ElevatorClass {
	int CurrentFl;
	int PassengerNum;
	int WorkingTime;
	int toDownload[10];
};

void Process(struct ElevatorClass *Obj);	// Part 3 : Declare the functions
void InitElevator(struct ElevatorClass *Obj, int DefaultFl);
void InsertPassenger(int FromFl, int ToFl, int CallingTime);

int main(void) {	// Part 4 : Define the main() function
	struct ElevatorClass Elevator;
	FILE* fp = fopen("Input.txt", "r");
	{	// Init the Elevator Class/Structer
		int CurrentFl_Input;
		fscanf(fp, "%d", &CurrentFl_Input);
		InitElevator(&Elevator, CurrentFl_Input);
	}
	while (!feof(fp)) {	// Init the PassengerAtFl[] Array
		int FromFl_In, ToFl_In, CallingTime_In;
		fscanf(fp, "%d %d %d", &FromFl_In, &ToFl_In, &CallingTime_In);
		InsertPassenger(FromFl_In, ToFl_In, CallingTime_In);
	}
	Process(&Elevator);
	return 0;
}

struct PassengerClass {	// Part 5 : Define the structers
	int CallingTime;
	int TargetFl;
	bool isEmpty;
} PassengerAtFl[10];

int Process_Up(struct ElevatorClass* Obj);	// Part 6 : Define the Functions
int Process_Dn(struct ElevatorClass* Obj);
enum { Moving, Blank, Finish };

void InitElevator(struct ElevatorClass* Obj, int DefaultFl) {
	Obj->CurrentFl = DefaultFl-1;
	Obj->PassengerNum = 0;
	Obj->WorkingTime = 0;
	for (int i = 0; i < 10; i++) {
		Obj->toDownload[i] = 0;
		PassengerAtFl->isEmpty = true;
	}
}

void InsertPassenger(int FromFl, int ToFl, int CallingTime) {
	PassengerAtFl[FromFl-1].isEmpty = false;
	PassengerAtFl[FromFl-1].TargetFl = ToFl-1;
	PassengerAtFl[FromFl-1].CallingTime = CallingTime;
}

void Process(struct ElevatorClass *Obj) {
	printf("电梯位置\t电梯运行时间\t电梯乘客人数\n");
	while (true) {
		int status_Up = Process_Dn(Obj);
		int status_Dn = Process_Up(Obj);
		if (status_Up == Moving || status_Dn == Moving) continue;
		else if (status_Up == Blank || status_Dn == Blank) Obj->WorkingTime++;
		else break;
	}
}

int Process_Up(struct ElevatorClass* Obj) {
	int isMoving = 0;
	int FindBlank = 0;
	int FlPtr = Obj->CurrentFl;
	while (FlPtr <= 9) {
		bool needToPrint = false;
		if (!PassengerAtFl[FlPtr].isEmpty) {	// Not Empty => The Upload Process
			if (
				Obj->WorkingTime >= PassengerAtFl[FlPtr].CallingTime &&
				Obj->PassengerNum < 4
				) {	// Can Upload
				needToPrint = true;
				isMoving++;
				Obj->toDownload[PassengerAtFl[FlPtr].TargetFl] += 1;
				Obj->PassengerNum += 1;
				Obj->WorkingTime += FlPtr - Obj->CurrentFl;
				Obj->CurrentFl = FlPtr;
				PassengerAtFl[FlPtr].isEmpty = true;
			}
			else if (Obj->WorkingTime < PassengerAtFl[FlPtr].CallingTime) {
				FindBlank++;
			}
		}
		if (Obj->toDownload[FlPtr]) {
			needToPrint = true;
			isMoving++;
			Obj->PassengerNum -= Obj->toDownload[FlPtr];
			Obj->toDownload[FlPtr] = 0;
			Obj->WorkingTime += FlPtr - Obj->CurrentFl;
			Obj->CurrentFl = FlPtr;
		}
		if (needToPrint) {
			printf("%d\t\t%d\t\t%d\n", Obj->CurrentFl+1, Obj->WorkingTime, Obj->PassengerNum);
		}
		FlPtr++;
	}
	if (isMoving) return Moving;
	else if (!isMoving && FindBlank) return Blank;
	else return Finish;
}

int Process_Dn(struct ElevatorClass* Obj) {
	int isMoving = 0;
	int FindBlank = 0;
	int FlPtr = Obj->CurrentFl;
	while (FlPtr >= 0) {
		bool needToPrint = false;
		if (!PassengerAtFl[FlPtr].isEmpty) {	// Not Empty => The Upload Process
			if (
				Obj->WorkingTime >= PassengerAtFl[FlPtr].CallingTime &&
				Obj->PassengerNum < 4
				) {	// Can Upload
				needToPrint = true;
				isMoving++;
				Obj->toDownload[PassengerAtFl[FlPtr].TargetFl] += 1;
				Obj->PassengerNum += 1;
				Obj->WorkingTime += Obj->CurrentFl - FlPtr;
				Obj->CurrentFl = FlPtr;
				PassengerAtFl[FlPtr].isEmpty = true;
			}
			else if (Obj->WorkingTime < PassengerAtFl[FlPtr].CallingTime) {
				FindBlank++;
			}
		}
		if (Obj->toDownload[FlPtr]) {
			needToPrint = true;
			isMoving++;
			Obj->PassengerNum -= Obj->toDownload[FlPtr];
			Obj->toDownload[FlPtr] = 0;
			Obj->WorkingTime += Obj->CurrentFl - FlPtr;
			Obj->CurrentFl = FlPtr;
		}
		if (needToPrint) {
			printf("%d\t\t%d\t\t%d\n", Obj->CurrentFl+1, Obj->WorkingTime, Obj->PassengerNum);
		}
		FlPtr--;
	}
	if (isMoving) return Moving;
	else if (!isMoving && FindBlank) return Blank;
	else return Finish;
}
