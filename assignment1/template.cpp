string support = input7Str;
    long long int data[4] = {0, 0, 0, 0};
    for(int i = 0 ; i < 4 ; i++){
        data[i] = stoi(support);
        int found = support.find(" ");
        if(found != string :: npos) support.erase(0, found + 1);
    }
    long long int N7 = data[0];
    long long int V = data[1];
    long long int ROW = data[2];
    long long int COL = data[3];

    long long int Array_of_input7Matrix[N7][N7];
    long long int Result_Matrix[N7][N7];
    long long int the_unit_matrix[N7][N7];
    string newinput7Matrix[k];

    for(int i = 0 ; i < N7 ; i++){
        for(int j = 0 ; j < N7 ; j++){
            if(i == j) the_unit_matrix[i][j] = 1;
            else the_unit_matrix[i][j] = 0;
        }
    }

    for(int index = 0 ; index < k ; index++){
        newinput7Matrix[index] = input7Matrix[index];
        for(int i = 0 ; i < N7 ; i++){
            for(int j = 0 ; j < N7 ; j++){
                Array_of_input7Matrix[i][j] = stoi(newinput7Matrix[index]);
                int found = newinput7Matrix[index].find(" ");
                if (found != string :: npos) newinput7Matrix[index].erase(0 , found + 1);
            }
        }

        for(int i = 0 ; i < N7 ; i++){
            for(int k = 0 ; k < N7 ; k++){
                Result_Matrix[i][k] = 0;
                for(int j = 0 ; j < N7 ; j++){
                    Result_Matrix[i][k] = Result_Matrix[i][k] + the_unit_matrix[i][j] * Array_of_input7Matrix[j][k];
                }
            }
        }

        for(int i = 0 ; i < N7 ; i++){
            for(int j = 0 ; j < N7 ; j++){
                the_unit_matrix[i][j] = Result_Matrix[i][j];
            }
        }
    }

    long long int R = the_unit_matrix[ROW][COL];
    cout << the_unit_matrix[ROW][COL] << endl;
    while(true){
        R = R + V;
        if(R > 0) break;
    }
    cout << R % V << endl;
    return R % V;
    return -1;