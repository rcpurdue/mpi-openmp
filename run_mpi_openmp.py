# run_mpi_openmp.py

import subprocess

NUM_MPI_PROCESSES = 2  # Adjust as needed
NUM_OPENMP_THREADS = 2  # Adjust as needed

# Construct MPI command to run that executable
mpi_command = ["mpirun", "-np", str(NUM_MPI_PROCESSES), "./mpi_openmp_threads"]

# Run subprocess, showing output
try:
    result = subprocess.run(mpi_command, capture_output=True, text=True, check=True)
    print(result.stdout)

except subprocess.CalledProcessError as e:
    print("Error executing MPI program:", e)
    print("STDERR:", e.stderr)
