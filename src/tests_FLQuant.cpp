/* 
 * Copyright 2013 FLR Team. Distributed under the GPL 2 or later
 * Maintainer: Finlay Scott, JRC
 */

#include <FLasher.h>

// [[Rcpp::export]]
std::string FLPar_units(SEXP flp) {
	Rcpp::S4 flp_s4 = Rcpp::as<Rcpp::S4>(flp);
    std::string units = flp_s4.slot("units");
    return units;
}

// Constructors and copiers

// [[Rcpp::export]]
FLQuant test_FLQuant_as_wrap(FLQuant flq){
	return flq;
}

// [[Rcpp::export]]
void test_FLQuant_basic_constructor(){
    FLQuant flq;
    return;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_sexp_constructor(SEXP flq_sexp){
	FLQuant flq(flq_sexp);
	return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_dim_constructor(int nquant, int nyear, int nunit, int nseason, int narea, int niter){
    FLQuant flq(nquant, nyear, nunit, nseason, narea, niter);
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_dim_value_constructor(int nquant, int nyear, int nunit, int nseason, int narea, int niter, double value){
    FLQuant flq(nquant, nyear, nunit, nseason, narea, niter, value);
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_intvec_dim_constructor(std::vector<unsigned int> dims){
    FLQuant flq(dims);
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_intvec_dim_value_constructor(std::vector<unsigned int> dims, double value){
    FLQuant flq(dims, value);
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_copy_constructor(FLQuant flq){
    FLQuant out(flq);
    return out;
}

// Checking that a deep copy has been made
// [[Rcpp::export]]
Rcpp::List test_FLQuant_copy_constructor2(FLQuant flq1, int quant, int year, int unit, int season, int area, int iter, double value){
	FLQuant flq2(flq1); 
	flq2(quant,year,unit,season,area,iter) = value;
	return Rcpp::List::create(Rcpp::Named("flq1", flq1),
                            Rcpp::Named("flq2",flq2));
}

// [[Rcpp::export]]
FLQuant test_FLQuant_assignment_operator(FLQuant flq){
    FLQuant out;
    out = flq;
    return out;
}

// Checking that a deep copy has been made
// [[Rcpp::export]]
Rcpp::List test_FLQuant_assignment_operator2(FLQuant flq1, int quant, int year, int unit, int season, int area, int iter, double value){
	FLQuant flq2;
    flq2 = flq1; 
	flq2(quant,year,unit,season,area,iter) = value;
	return Rcpp::List::create(Rcpp::Named("flq1", flq1),
				Rcpp::Named("flq2",flq2));
}

// [[Rcpp::export]]
FLQuant test_FLQuant_from_FLQuantAD_constructor(FLQuantAD flqad){
    FLQuant flq(flqad);
    return flq;
}

//------------------ Accessors ----------------------
// [[Rcpp::export]]
std::vector<double> test_FLQuant_get_data(FLQuant flq){
	return flq.get_data();
}

// [[Rcpp::export]]
std::string test_FLQuant_get_units(FLQuant flq){
	return flq.get_units();
}

// [[Rcpp::export]]
std::vector<unsigned int> test_FLQuant_get_dim(FLQuant flq){
	return flq.get_dim();
}

// [[Rcpp::export]]
Rcpp::List test_FLQuant_get_dimnames(FLQuant flq){
	return flq.get_dimnames();
}

// [[Rcpp::export]]
Rcpp::List test_FLQuant_get_dimnames2(FLQuant flq){
    Rcpp::List dimnames = flq.get_dimnames();
    dimnames[0] = Rcpp::CharacterVector::create("all");
    return Rcpp::List::create(Rcpp::Named("flq", flq),
            Rcpp::Named("dimnames", dimnames));
}

// [[Rcpp::export]]
int test_FLQuant_get_size(FLQuant flq){
	return flq.get_size();
}

// [[Rcpp::export]]
int test_FLQuant_get_nquant(FLQuant flq){
	return flq.get_nquant();
}

// [[Rcpp::export]]
int test_FLQuant_get_nyear(FLQuant flq){
	return flq.get_nyear();
}

// [[Rcpp::export]]
int test_FLQuant_get_nunit(FLQuant flq){
	return flq.get_nunit();
}

// [[Rcpp::export]]
int test_FLQuant_get_nseason(FLQuant flq){
	return flq.get_nseason();
}

// [[Rcpp::export]]
int test_FLQuant_get_narea(FLQuant flq){
	return flq.get_narea();
}

// [[Rcpp::export]]
int test_FLQuant_get_niter(FLQuant flq){
	return flq.get_niter();
}

// [[Rcpp::export]]
int test_FLQuant_get_first_age(const FLQuant flq){
    int out = flq.get_first_age();
    return out;
}

//---------- () accessors -----------------

// [[Rcpp::export]]
int test_FLQuant_get_data_element(const FLQuant flq, int quant, int year, int unit, int season, int area, int iter){
	int out = 0;
	out = flq.get_data_element(quant,year,unit,season,area,iter);
	return out;
}

// [[Rcpp::export]]
double test_FLQuant_get_const_single_index_accessor(const FLQuant flq, const int element){
	double output = 0.0;
	output = flq(element);
	return output;
}

// [[Rcpp::export]]
double test_FLQuant_get_single_index_accessor(FLQuant flq, int element){
	double output = 0.0;
	output = flq(element);
	return output;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_set_single_index_accessor(FLQuant flq, int element, double value){
    flq(element) = value;
    return flq;
}

// [[Rcpp::export]]
double test_FLQuant_const_get_accessor(const FLQuant flq, int quant, int year, int unit, int season, int area, int iter){
	double output = 0.0;
	output = flq(quant,year,unit,season,area,iter);
	return output;
}

// [[Rcpp::export]]
double test_FLQuant_get_accessor(FLQuant flq, int quant, int year, int unit, int season, int area, int iter){
	double output = 0.0;
	output = flq(quant,year,unit,season,area,iter);
	return output;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_set_accessor(FLQuant flq, int quant, int year, int unit, int season, int area, int iter, double value){
	flq(quant,year,unit,season,area,iter) = value;
	return flq;
}

// [[Rcpp::export]]
double test_FLQuant_get_const_indices_accessor(const FLQuant flq, std::vector<unsigned int> indices){
    return flq(indices);
}

// [[Rcpp::export]]
double test_FLQuant_get_indices_accessor(FLQuant flq, std::vector<unsigned int> indices){
    return flq(indices);
}

// [[Rcpp::export]]
FLQuant test_FLQuant_set_indices_accessor(FLQuant flq, std::vector<unsigned int> indices, double value){
    flq(indices) = value;
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_get_all_iters(FLQuant flq, int quant, int year, int unit, int season, int area){
    return flq(quant,year,unit,season,area);
}

//------------ Set methods -------------------------

// [[Rcpp::export]]
FLQuant test_FLQuant_set_data(FLQuant flq, std::vector<double> data_in){
	flq.set_data(data_in);
	return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_set_dimnames(FLQuant flq, Rcpp::List new_dimnames){
    flq.set_dimnames(new_dimnames);
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_set_units(FLQuant flq, std::string new_units){
    flq.set_units(new_units);
    return flq;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_subset(FLQuant flq, const int quant_min, const int quant_max, const int year_min, const int year_max, const int unit_min, const int unit_max, const int season_min, const int season_max, const int area_min, const int area_max, const int iter_min, const int iter_max){
    return flq(quant_min, quant_max, year_min, year_max, unit_min, unit_max, season_min, season_max, area_min, area_max, iter_min, iter_max);
}

// [[Rcpp::export]]
FLQuant test_FLQuant_neat_subset(FLQuant flq, const std::vector<unsigned int> indices_min, const std::vector<unsigned int> indices_max){
    FLQuant out = flq(indices_min, indices_max);
    return out;
}

// [[Rcpp::export]]
Rcpp::List test_FLQuant_propagate_iters(FLQuant flq, const int iters){
    FLQuant flq2 = flq.propagate_iters(iters);
    return Rcpp::List::create(Rcpp::Named("flq", flq),
            Rcpp::Named("flq2", flq2));
}

// [[Rcpp::export]]
FLQuant test_FLQuant_fill(FLQuant flq, const double value) {
    flq.fill(value);
    return flq;
}

//------------------ Others --------------------------------------
// [[Rcpp::export]]
int test_FLQuant_FLQuant_match_dims(FLQuant flq1, FLQuant flq2){
    return flq1.match_dims(flq2);
}


// [[Rcpp::export]]
FLQuant test_FLPar_to_FLQuant(SEXP flp){
    FLQuant flq = FLPar_to_FLQuant(flp);
    return flq;
}

//--------- begin and end ----------------------

// [[Rcpp::export]]
FLQuant test_for_range(FLQuant flq, double rn){
    for (auto& it : flq){
        it *= rn;
    }
    return flq;
}

// [[Rcpp::export]]
double test_for_range_const(FLQuant flq, double rn){
    auto value = 0.0;
    for (const auto& it : flq){
        value = value + it * rn;
    }
    return value;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_for_iterator(FLQuant flq, double rn){
    FLQuant::iterator it;
    for(it = flq.begin(); it != flq.end(); it++) {
        *it *= rn;
    }
    return flq;
}

// [[Rcpp::export]]
double test_FLQuant_for_iterator_const(FLQuant flq, double rn){
    FLQuant::const_iterator it;
    auto value = 0.0;
    for(it = flq.begin(); it != flq.end(); it++) {
        value = value + *it * rn;
    }
    return value;
}

// [[Rcpp::export]]
FLQuant test_FLQuant_lambda(FLQuant flq1, FLQuant flq2){
    FLQuant flq3(flq1);
    std::transform(flq1.begin(), flq1.end(), flq2.begin(), flq3.begin(),
        [](double x, double y) { return sqrt(x*x + y*y); } );
    return flq3;
}

// [[Rcpp::export]]
FLQuant test_DD_pow(const FLQuant flq, const double power){
    FLQuant out = pow(flq, power);
    return out;
}

// [[Rcpp::export]]
FLQuantAD test_DAD_pow(const FLQuant flq, const double power){
    adouble adpower = power;
    return pow(flq, adpower);
}

// [[Rcpp::export]]
FLQuantAD test_ADD_pow(const FLQuantAD flq, const double power){
    return pow(flq, power);
}

// [[Rcpp::export]]
FLQuantAD test_ADAD_pow(const FLQuantAD flq, const double power){
    adouble adpower = power;
    return pow(flq, adpower);
}

// [[Rcpp::export]]
FLQuantAD test_input_subsetter_ADAD(FLQuantAD flq1, FLQuantAD flq2, std::vector<unsigned int> indices_min, std::vector<unsigned int> indices_max){
    flq1.insert(flq2, indices_min, indices_max);
    return flq1;
}

// [[Rcpp::export]]
FLQuant test_input_subsetter_DD(FLQuant flq1, FLQuant flq2, std::vector<unsigned int> indices_min, std::vector<unsigned int> indices_max){
    flq1.insert(flq2, indices_min, indices_max);
    return flq1;
}

// [[Rcpp::export]]
FLQuantAD test_input_subsetter_ADD(FLQuantAD flq1, FLQuant flq2, std::vector<unsigned int> indices_min, std::vector<unsigned int> indices_max){
    flq1.insert(flq2, indices_min, indices_max);
    return flq1;
}

// [[Rcpp::export]]
FLQuant test_input_subsetter_DAD(FLQuant flq1, FLQuantAD flq2, std::vector<unsigned int> indices_min, std::vector<unsigned int> indices_max){
    flq1.insert(flq2, indices_min, indices_max);
    return flq1;
}


/* timestep convertors */

// [[Rcpp::export]]
unsigned int test_year_season_to_timestep_FLQuant_double(FLQuant flq, const unsigned int year, const unsigned int season){
    unsigned int timestep = 0;
    year_season_to_timestep(year, season, flq, timestep);
    return timestep;
}

// [[Rcpp::export]]
unsigned int test_year_season_to_timestep_FLQuant_adouble(FLQuantAD flqad, const unsigned int year, const unsigned int season){
    unsigned int timestep = 0;
    year_season_to_timestep(year, season, flqad, timestep);
    return timestep;
}

// [[Rcpp::export]]
unsigned int test_year_season_to_timestep(FLQuant flq, const int unsigned year, const int unsigned season){
    unsigned int timestep = 0;
    year_season_to_timestep(year, season, flq.get_nseason(), timestep);
    return timestep;
}

// [[Rcpp::export]]
Rcpp::IntegerVector test_timestep_to_year_season_FLQuant_double(FLQuant flq, const unsigned int timestep){
    unsigned int year = 0;
    unsigned int season = 0;
    timestep_to_year_season(timestep, flq, year, season);
    Rcpp::IntegerVector out(2);
    out[0] = year;
    out[1] = season;
    return out;
}

// [[Rcpp::export]]
Rcpp::IntegerVector test_timestep_to_year_season_FLQuant_adouble(FLQuantAD flqad, const unsigned int timestep){
    unsigned int year = 0;
    unsigned int season = 0;
    timestep_to_year_season(timestep, flqad, year, season);
    Rcpp::IntegerVector out(2);
    out[0] = year;
    out[1] = season;
    return out;
}

// [[Rcpp::export]]
Rcpp::IntegerVector test_timestep_to_year_season(FLQuant flq, const unsigned int timestep){
    unsigned int year = 0;
    unsigned int season = 0;
    timestep_to_year_season(timestep, flq.get_nseason(), year, season);
    Rcpp::IntegerVector out(2);
    out[0] = year;
    out[1] = season;
    return out;
}

