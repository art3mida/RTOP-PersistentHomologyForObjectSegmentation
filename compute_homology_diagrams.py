import os
import ripser
import numpy as np

distance_matricies_dir = 'data/distance_matricies'
distance_matricies = os.listdir(distance_matricies_dir)
already_computed = os.listdir('data/homology_diagrams/')
if __name__ == '__main__':
    for distance_matrix_filename in distance_matricies:
        try:
            distance_matrix_filename = distance_matrix_filename.split('.')[0]
            output_numpy_dgms = os.path.join('data/homology_diagrams/', distance_matrix_filename + ".npy")
            if os.path.basename(output_numpy_dgms) in already_computed:
                print('already computed: ' + distance_matrix_filename)
                continue
            print('computing ' + distance_matrix_filename)
            rips = ripser.Rips()
            input_distance_matrix = os.path.join(distance_matricies_dir, distance_matrix + ".csv")
            geodesic_distance_matrix = np.genfromtxt(fname=input_distance_matrix,
                                    delimiter=',',
                                    dtype=np.double)
            print(geodesic_distance_matrix.shape)
            if geodesic_distance_matrix.shape[0] > 4000:
                print('to_large')
                continue
            dgms = rips.fit_transform(geodesic_distance_matrix, distance_matrix=True)
            np.save(output_numpy_dgms, arr=dgms, allow_pickle=True)
            
        except:
            with open('failed.txt', 'wa') as f:
                f.write(distance_matrix_filename + "\n")
        del rips
