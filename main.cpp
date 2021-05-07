#include <iostream>
#include <Fitness.h>
#include <F6.h>
#include <random>
#include <limits>
#include <cstdlib>
#include <Fitness.h>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function
#include <fstream>

using namespace std;

//copy un des valeurs d'un tableau dans un autre
void copy(double* src, double* target)
{
    double *k, *m;
    for(k = src, m = target; *k != '\0', *m != '\0'; k++, m++){
        *m = *k;
    }
}

void GWO(Fitness* F, int* ub, int* lb, int dim, int searchAgents, int max_iter)
{
    unsigned seed ;
    std::ofstream myfile;
    myfile.open ("GWO.csv");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);//uniform distribution between 0 and 1

     /*initialization alpha, beta, and delta */
     double alpha_pos[dim + 1];
     alpha_pos[dim] = '\0';
     double alpha_score = std::numeric_limits<double>::infinity();

     double beta_pos[dim + 1];
     beta_pos[dim] = '\0';
     double beta_score = std::numeric_limits<double>::infinity();

     double delta_pos[dim + 1];
     delta_pos[dim] = '\0';
     double delta_score = std::numeric_limits<double>::infinity();

     /*inisialization des positions pour chaque loup*/
     double positions[searchAgents + 1][dim + 1];
     for(int i = 0; i < searchAgents; i++){
        positions[i][dim] = '\0';

        for(int j = 0; j < dim; j++){
            seed = time(0);
            srand(seed);
            positions[i][j] = (double)(dis(gen)) * (ub[j] - lb[j]) + lb[j];
            cout << "positions[" << i <<"][" << j << "] = " << positions[i][j]<<"\n";
        }
     }
     positions[searchAgents][0] = '\0';
     //les fitness de la recherche
     double convergence_courbe[max_iter];
     //initialisation du fitness
     double fitness, a, r1, r2, A1, A2, A3, C1, C2, C3, X1, X2, X3, D_alpha, D_beta, D_delta;
     //adaptation des position hores limites
    for(int i = 0; i < searchAgents; i++){
       for(int j = 0; j < dim; j++){
                if(positions[i][j] < lb[j]){
                    positions[i][j] = lb[j];
                } else if(positions[i][j] > ub[j]){
                    positions[i][j] = ub[j];
                }
                cout << "nvs: positions[" << i <<"][" << j << "] = " << positions[i][j] <<"\n";
            }
    }
    for(int l = 0; l < max_iter; l++){

        for(int i = 0; i < searchAgents; i++){

            // Calcule des fitness pour chaque agent (loup)
            fitness = F->objcF(&positions[i][0]);
            // update Alpha, Beta, et Delta

            if(fitness < alpha_score){
                delta_score = beta_score;
                copy(beta_pos, delta_pos);

                beta_score = alpha_score;
                copy(alpha_pos, beta_pos);

                alpha_score = fitness;
                copy(&positions[i][0], alpha_pos);
            }
            if(fitness > alpha_score && fitness < beta_score){
                delta_score = beta_score;
                copy(beta_pos, delta_pos);

                beta_score = alpha_score;
                copy(alpha_pos, beta_pos);
            }
            if(fitness > alpha_score && fitness > beta_score && fitness < delta_score){
                delta_score = fitness;
                copy(&positions[i][0], delta_pos);
            }
        }
        a = 2 - l * (((double) 2) / max_iter);
        for(int i = 0; i < searchAgents; i++){
            for(int j = 0; j < dim; j++){
                r1 = (double)(dis(gen));
                r2 = (double)(dis(gen));
                A1 = 2 * a * r1 - a;
                C1 = 2 * r2;
                D_alpha = abs(C1 * alpha_pos[j] - positions[i][j]);
                X1 = alpha_pos[j] - A1 * D_alpha;

                r1 = (double)(dis(gen));
                r2 = (double)(dis(gen));
                A2 = 2 * a * r1 - a;
                C2 = 2 * r2;
                D_beta = abs(C2 * beta_pos[j] - positions[i][j]);
                X2 = beta_pos[j] - A2 * D_beta;

                r1 = (double)(dis(gen));
                r2 = (double)(dis(gen));
                A3 = 2 * a * r1 - a;
                C3 = 2 * r2;
                D_delta = abs(C3 * delta_pos[j] - positions[i][j]);
                X3 = delta_pos[j] - A3 * D_delta;

                positions[i][j] = (X1 + X2 + X3)/3 ;
            }
        }
        convergence_courbe[l] = alpha_score;
        myfile << l<<","<<convergence_courbe[l]<<"\n";
        cout << "l = "<< l<< " alpha_score = "<<alpha_score << endl;
    }//iteration
    myfile.close();

}

int main()
{
    Fitness *f = new F6();
    int ub[3] = {100, 100,'\0'};
    int lb[3] = {-100, -100,'\0'};
    GWO(f, ub, lb, 2, 6, 20);

    return 0;
}
