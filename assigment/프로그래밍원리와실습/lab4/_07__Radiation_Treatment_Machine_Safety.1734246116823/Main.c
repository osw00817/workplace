#include <stdio.h>
#include <stdbool.h>

bool isCalibrationMode = false;

void beginCalibration() {
    isCalibrationMode = true;
}

void endCalibration() {
    isCalibrationMode = false;
}

void performRadiation(int dose) {
    printf("Radiation performed with dose: %d\n", dose);
}

void safeRadiation(int i) {
	if(isCalibrationMode == false && i > 0 && i <= 10) {
		performRadiation(i);
	} else {
		printf("Error: Unsafe radiation parameters.\n");
	}
}

int main() {
    // A technician calibrated the machine but forgot to switch back to treatment mode.
    beginCalibration();
		int calibrationDose = 30;
		performRadiation(calibrationDose);
	
    // The safe range for treatment is (0, 10)
    int patientDose = 15;
		// This should trigger the error message, protecting the patient
    safeRadiation(patientDose);  

    // Switching back to treatment mode and testing again
    endCalibration();
	
		// This should successfully administer radiation
    patientDose = 5;
    safeRadiation(patientDose);

    return 0;
}