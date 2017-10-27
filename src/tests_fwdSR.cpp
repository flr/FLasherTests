/* 
 * Copyright 2014 FLR Team. Distributed under the GPL 2 or later
 * Maintainer: Finlay Scott, JRC
 */

#include <FLasher.h>

// [[Rcpp::export]]
void test_fwdSR_empty_constructor(){
	fwdSR flsr;
	return;
}

// [[Rcpp::export]]
fwdSR test_fwdSR_constructor_wrap(const std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult){
    fwdSR fwdsr(model_name, params, residuals, residuals_mult);
    return fwdsr;
}

// [[Rcpp::export]]
int test_fwdSR_get_nparams(std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult){
    fwdSR fwdsr(model_name, params, residuals, residuals_mult);
    return fwdsr.get_nparams();
}

// [[Rcpp::export]]
double test_fwdSR_eval(std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult, const double srp, const std::vector<unsigned int> param_indices){
    fwdSR fwdsr(model_name, params, residuals, residuals_mult);
    double rec = fwdsr.eval_model(srp, param_indices);
    return rec;
}

// [[Rcpp::export]]
std::vector<double> test_fwdSR_get_params(std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult, const std::vector<unsigned int> param_indices){
    fwdSR fwdsr(model_name, params, residuals, residuals_mult);
    std::vector<double> params_out = fwdsr.get_params(param_indices[0], param_indices[1], param_indices[2], param_indices[3], param_indices[4]);
    return params_out;
}

// [[Rcpp::export]]
Rcpp::List test_fwdSR_copy_constructor(std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult, const double srp){
    fwdSR fwdsr1(model_name, params, residuals, residuals_mult);
	fwdSR fwdsr2(fwdsr1); // uses copy constructor
    double rec1 = fwdsr1.eval_model(srp,1,1,1,1,1);
    double rec2 = fwdsr2.eval_model(srp,1,1,1,1,1);
	return Rcpp::List::create(Rcpp::Named("fwdsr1", fwdsr1),
				Rcpp::Named("fwdsr2",fwdsr2),
				Rcpp::Named("rec1",rec1),
				Rcpp::Named("rec2",rec2));
}

// [[Rcpp::export]]
Rcpp::List test_fwdSR_assignment_operator(std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult, const double srp){
    fwdSR fwdsr1(model_name, params, residuals, residuals_mult);
	fwdSR fwdsr2;
    fwdsr2 = fwdsr1; // Assignment happens
    double rec1 = fwdsr1.eval_model(srp,1,1,1,1,1);
    double rec2 = fwdsr2.eval_model(srp,1,1,1,1,1);
	return Rcpp::List::create(Rcpp::Named("fwdsr1", fwdsr1),
				Rcpp::Named("fwdsr2",fwdsr2),
				Rcpp::Named("rec1",rec1),
				Rcpp::Named("rec2",rec2));
}

// [[Rcpp::export]]
FLQuant test_fwdSR_predict_recruitment(std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult, const FLQuant srp, const std::vector<unsigned int> initial_params_indices){
    fwdSR fwdsr(model_name, params, residuals, residuals_mult);
    FLQuant rec = fwdsr.predict_recruitment(srp, initial_params_indices);
    return rec;
}

// [[Rcpp::export]]
bool test_fwdSR_does_recruitment_happen(const std::string model_name, const FLQuant params, const FLQuant residuals, const bool residuals_mult, unsigned int unit, unsigned int year, unsigned int season){
    fwdSR fwsr(model_name, params, residuals, residuals_mult);
    return fwsr.does_recruitment_happen(unit, year, season);
}



