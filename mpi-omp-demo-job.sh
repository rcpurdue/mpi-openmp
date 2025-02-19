#!/bin/bash
#SBATCH --job-name=mpi_openmp_test
#SBATCH --output=mpi_openmp_output.txt
#SBATCH --error=mpi_openmp_error.txt
#SBATCH --nodes=1              # Number of nodes
#SBATCH --ntasks=2             # Total number of MPI processes (ranks)
#SBATCH --cpus-per-task=2      # Number of OpenMP threads per MPI rank
#SBATCH --time=00:05:00        # Time limit (hh:mm:ss)
#SBATCH --account=standby      # Adjust partition as needed

# Load any necessary modules (modify as needed)
module load anaconda
# Use Intel MPI instead of cluster's default
module load intel-oneapi-compilers
module load intel-oneapi-mpi

# Set OpenMP environment variable
export OMP_NUM_THREADS=2

# Run the Python script
python run_mpi_openmp.py
