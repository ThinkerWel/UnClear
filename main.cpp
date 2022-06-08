enum class  Mch {
    CREATE,
    GUES,
    RAND
    
};

class Disegn {

public:
    Mch RetUp() {
        return cuser;
    }
    void UpSet(Mch setant) {
        this->cuser = setant;
    }


private:
    Mch cuser;
};

int main() {

    

    Disegn pc;
    int choice = 0;
    std::cin >> choice;



    if (choice == 0) {
        pc.UpSet(Mch::CREATE);
    }
    else if  (choice == 1) {
        pc.UpSet(Mch::GUES);
    }
    else if(choice==2) {
        pc.UpSet(Mch::RAND);
    }
    else {
        cout << "#1";
    }

    const int size = 8;
    int count = 0;
    int min = 0, max = 0;

        switch (pc.RetUp())
        {
            srand(time(NULL));
        case Mch::CREATE:
          std::cout << "Output non-even numbers " << endl<<endl;

            int arr[size];
            for (int i = 0; i < size;) {
                arr[i] = rand() % + - 20;
                if (arr[i] % 2 != 0) {
                    i++;
                }
            }

            for (int j = 0; j < size; j++)
              std::cout << arr[j] << " ";
               break;

         case Mch::GUES:
           std::cout << "Counting negative numbers "<<endl;
            int sArr[size];
            for (int i = 0; i < size; i++) {
                sArr[i] = rand() % 100 +- 100;
                if (sArr[i] < 0) {
                    count += sArr[i];
                }
            }

            for (int k = 0; k < size; k++) {
                std::cout << sArr[k] << " ";
            }
            std::cout << endl<<endl;
            std::cout << "All Sum = " << count <<  endl;
            break;

        case Mch::RAND:
            int arrT[size];
            for (int i = 0; i < size; i++) {
                arrT[i] = rand() % 99 + 1;
            
          
                if (arrT[i] > max) {
                    max = arrT[i];
                }

                if (arrT[i] < min) {
                    min = arrT[i];
                }
            }
              
                for (int i = 0; i < size; i++) {
                    std::cout << arrT[i]<<" ";
                }
            std::cout << endl << endl;
            std::cout << "Max = " << max <<" " << "Min = " << min;
              break;

         default:
             break;
        }

       return 0;
}
