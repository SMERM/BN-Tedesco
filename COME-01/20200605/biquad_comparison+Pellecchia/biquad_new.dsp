declare filename "biquad_new.dsp"; declare name "biquad_new"; declare compilation_options    "-single -scal -I libraries/ -I project/ -lang wasm";
declare library_path "FaustDSP";
declare library_path "/libraries/stdfaust.lib";
declare library_path "/libraries/maths.lib";
declare filename "FaustDSP";
declare maths_lib_author "GRAME";
declare maths_lib_copyright "GRAME";
declare maths_lib_license "LGPL with exception";
declare maths_lib_name "Faust Math Library";
declare maths_lib_version "2.1";
declare name "FaustDSP";
process = \(x1).(\(x2).(\(x3).(\(x4).(\(x5).(\(x6).(x1 : _<:(_,x2 : *),(_,1 : @ : _,x3 : *),(_,2 : @ : _,x4 : *):>_ : \(x7).(\(x8).(x8,x7 : -))~(_<:(_,x5 : *),(_,1 : @ : _,x6 : *):>_)))))));
