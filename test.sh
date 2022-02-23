set -exu

./term3d testfiles/extension_error1.tr
./term3d testfiles/extension_error2.tir
./term3d testfiles/extension_error3.itr
./term3d testfiles/extension_error4.t
./term3d testfiles/extension_error5.
./term3d testfiles/empty.tri
./term3d testfiles/empty_newline.tri
./term3d testfiles/empty_space.tri
./term3d testfiles/too_long_space.tri # 1025
./term3d testfiles/too_long_line.tri # 1025
./term3d testfiles/too_long_decimal_point.tri
./term3d testfiles/inf.tri
./term3d testfiles/nan.tri
./term3d testfiles/char.tri
./term3d testfiles/plus_sign_double.tri
./term3d testfiles/minus_sign_double.tri
./term3d testfiles/plus_sign.tri
./term3d testfiles/too_many_decimal_point.tri
./term3d testfiles/too_many_separate_space.tri
./term3d testfiles/greater_dobule_max.tri
./term3d testfiles/less_double_min.tri
./term3d testfiles/vector_wrong_separate_char.tri
./term3d testfiles/vector_no_separate.tri
./term3d testfiles/vector_one.tri
./term3d testfiles/vector_two.tri
./term3d testfiles/vector_four.tri
./term3d testfiles/vector_elem_one.tri
./term3d testfiles/vector_elem_two.tri
./term3d testfiles/vector_elem_four.tri
./term3d testfiles/vector_elem_only_dot.tri
./term3d testfiles/vector_elem_only_sign.tri
./term3d testfiles/permission_error.tri
./term3d testfiles/directory_error.tri