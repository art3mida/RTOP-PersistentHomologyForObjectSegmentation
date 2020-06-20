

#include "CGAL/Heat_method_3/Surface_mesh_geodesic_distances_3.h"
#include "CGAL/Simple_cartesian.h"
#include "CGAL/Surface_mesh.h"
#include <fstream>
#include <iostream>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Surface_mesh<Point_3> Triangle_mesh;
typedef boost::graph_traits<Triangle_mesh>::vertex_descriptor vertex_descriptor;
typedef Triangle_mesh::Property_map<vertex_descriptor, double> Vertex_distance_map;
typedef CGAL::Heat_method_3::Surface_mesh_geodesic_distances_3<Triangle_mesh> Heat_method;

#include "matrix.hpp"

int
main(int argc, char* argv[])
{
    Triangle_mesh tm;
    const char* filename = argv[1];
    std::cerr << "\n\nComputing distance matrix for: \n";
    std::cerr << "input: " << argv[1] << '\n';
    std::cerr << "output: " << argv[2] << '\n';

    // TODO(Marko): Replace streams with something sane
    std::ifstream input(filename);
    if (!input || !(input >> tm) || tm.is_empty()) {
        std::cerr << "Not a valid off file." << std::endl;
        
        return 1;
    }

    Vertex_distance_map vertex_distance = tm.add_property_map<vertex_descriptor, double>("v:distance", 0).first;
    Heat_method hm(tm);

    me::Matrix<double> distance_matrix(tm.number_of_vertices(), tm.number_of_vertices());

    // Totaly naive.
    // Could be improved x2 at least
    // TODO(Marko): Improve performance of this loop
    for (vertex_descriptor source : vertices(tm)) {
        hm.add_source(source);
        std::cout << "\r\r" << source.idx() / (double)tm.number_of_vertices();
        hm.estimate_geodesic_distances(vertex_distance);

        for (vertex_descriptor dest : vertices(tm)) {
            distance_matrix.at(source.idx(), dest.idx()) = get(vertex_distance, dest);
        }

        hm.remove_source(source);
    }

    // TODO(Marko): Why am I not just dumping the matrix to hd
    std::cout << "\r\r" << 1.0;
    std::ofstream out(argv[2]);
    for (int64_t i = 0; i < distance_matrix.num_of_rows(); ++i) {
        for (int64_t j = 0; j < distance_matrix.num_of_cols(); ++j) {
            out << distance_matrix.at(i, j);
            if (j != distance_matrix.num_of_cols() - 1) {
                out << ',';
            }
        }
        out << '\n';
    }

    return 0;
}
