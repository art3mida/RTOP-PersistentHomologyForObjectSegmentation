data/models
	modeli u formatu .off tacaka i grana
data/distance_matricies
	matrice geodezijskog rastojanja izmedju svaka dva cvora u modelu
	procenjna pokrentanjem compute_matricies.sh
	koji za svaki fajl u data/models poziva
	./estimate_geodesic_distance_matrix_from_off_model_file {$input}.off {$output}.csv
	kako bi generisao matricu rastojanja
data/homology_diagrams
	dijagrami H0 i H1 homologije izracunati koriscenjenjm python ripser biblioteke
	pokretanjem compute_homology_diagrams.py

data/models_superset
	svi interesantni modeli koji rade sa koriscenjim bibliotekama.
	Podskup ovih se nalazi u data/models jer su neki preveliki, a neki nisu topoloski interesantni

Vazni linkovi:
http://people.eecs.berkeley.edu/~sequin/CS39/LECT/ProjectPresentations/Pranav_Bhasin_3D-Segmentation.pdf
http://gudhi.gforge.inria.fr/python/latest/rips_complex_user.html
https://geometrica.saclay.inria.fr/team/Fred.Chazal/slides/MVA2019_TP1.html?fbclid=IwAR3V8JYb9WIELHti8Wz0FY4HMYYyH3pQ4wc64u8BJDiNVMlrVK_jZCPTLJY


Paketi:
sve potrebne pakete instalirati preko konde ako je moguce
pre pokretanja juptyer-notebook uraditi
conda activate
