# mpi-openmp

Demo MPI process running multiple threads

## Source Files
- `mpi-openmp-demo-job.sh`
- `run_mpi_openmp.py`
- `mpi_openmp_threads.cpp`

## Steps
1. Slurm runs Bash script, allocating threads per process.
2. Bash script sets OpenMP environment variable, runs Python script.
3. Python script runs executable in parallel as separate processes. They inherit environment. They don't share memory.
4. Each instance (rank) of executable spawns OpenMP threads. Threads share memory.

## Expected output
NOTE: Output text may be intermixed (jumbled) due to parallel writes!
```
MPI Rank: 0/2, OpenMP Thread: 0/2, Running on Core: 105
MPI Rank: 0/2, OpenMP Thread: 1/2, Running on Core: 105
MPI Rank: 1/2, OpenMP Thread: 0/2, Running on Core: 106
MPI Rank: 1/2, OpenMP Thread: 1/2, Running on Core: 106
```

## To compile the executable
### Using cluster default
```
mpicxx -fopenmp -o mpi_openmp_threads mpi_openmp_threads.cpp
```
### Using Intel
```
module load intel-oneapi-compilers
module load intel-oneapi-mpi
mpiicpc -qopenmp -o mpi_openmp_threads mpi_openmp_threads.cpp
```

## To submit the Slurm job
```
sbatch mpi-omp-demo-job.sh
```

