import os
import subprocess


data_dir = 'data/'

already_computed_distance_matricies = os.listdir(os.path.join(data_dir, 'distance_matricies'))


models = os.listdir(os.path.join(data_dir, "models"))
for model in models:
    model = model.split('.')[0]
    if (model + ".csv") not in already_computed_distance_matricies:
        input_model = os.path.join(data_dir, 'distance_matricies', model + ".off")
        output_matrix = os.path.join(data_dir, 'distance_matricies', model + ".csv")
        result = subprocess.Popen(
            ['./estimate_geodesic_distance_matrix_from_off_model_file',
            input_model,
            output_matrix]
        , stdout=subprocess.PIPE)
        print(result)
    else:
        print("Already computed {}".format(model))