# Medical Diagnosis Expert System
def main():
    print("==========================================")
    print("    MEDICAL DIAGNOSIS EXPERT SYSTEM       ")
    print("==========================================\n")

    print("Answer the following questions with yes or no !\n")

    fever = input("Do you have a fever ? ").strip().lower();
    cough = input("Do you have a cough ? ").strip().lower();
    fatigue = input("Are you experiencing fatigue ? ").strip().lower();
    headache = input("Do you have a headache ? ").strip().lower();
    sore_throat = input("Do you have a sore throat ? ").strip().lower();
    runny_nose = input("Do you have a runny nose ? ").strip().lower();
    nausea =  input("Are you felling nauseous ? ").strip().lower();
    vomiting = input("Have you been vomiting ? ").strip().lower(); 
    diarrhea = input("Are you experiencing dairrhea ? ").strip().lower();
    body_ache = input("Are you experiencing body ache ? ").strip().lower();
    short_breath = input("Do you feel shortness of breadth ? ").strip().lower();
    chest_pain = input("Do you have chest pain ? ").strip().lower();
    
    print("\n Diagnosis Result \n")

    if fever == "yes" and cough == "yes" and fatigue == "yes" and short_breath == "yes":
        print("Possible Diagnosis : COVID-19")
        print("Recommendation : Test immediately,isolate and take medications.")

    elif fever == "yes" and cough == "yes" and sore_throat == "yes" and runny_nose == "yes":
        print("Possible Daignosis : Common Cold")
        print("Recommendation : Stay hydrated.Drink warm water and take anti cold medicines.")
    
    elif fever == "yes" and cough == "yes" and fatigue == "yes" and body_ache == "yes":
        print("Possible Daignosis : Influenza(Flu)")
        print("Recommendation : Stay hydrated.Drink fluids and consult doctor for further medications.")

    elif nausea == "yes" and vomiting == "yes" and diarrhea == "yes":
        print("Possible Daignosis : Food Poisioning")
        print("Recommendation : Stay hydrated.Drink fluids and avoid solids and consult doctor for further medications.")     

    elif nausea == "yes" and vomiting == "yes" and headache == "yes":
        print("Possible Daignosis : Migrane")
        print("Recommendation : Stay in a dark room, avoid direct sunlight,stay hydrated and consult doctor")

    elif fever == "yes" and cough == "yes" and chest_pain == "yes" and short_breath == "yes":
        print("Possible Daignosis : Pneumonia")
        print("Recommendation : Consult doctor for further medications immediately")

    elif nausea == "yes" and vomiting == "yes" and fever == "yes":
        print("Possible Daignosis : Gastroenteritis")
        print("Recommendation : Stay hydrated.Drink fluids and consult doctor for further medications.")
    
    else:
        print("Diagnosis inconclusive")
        print("Recommendation : Consult to a doctor for accurate analysis.")

    print("\n Diagnosis End \n")        

if __name__ == "__main__":
    main()