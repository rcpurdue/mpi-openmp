// Copyright GPL v3
// mpi_openmp_threads.cpp

#include <omp.h>
#include <mpi.h>
#include <thread>

#include <iostream>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int core_id = sched_getcpu();

        #pragma omp critical
        {
            std::cout << "MPI Rank: " << world_rank << "/" << world_size
                      << ", OpenMP Thread: " << thread_id << "/" << num_threads
                      << ", Running on Core: " << core_id << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
