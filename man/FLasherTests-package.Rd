\name{FLasherTests-package}
\alias{FLasherTests-package}
\alias{FLasherTests}
\docType{package}
\title{
    Tests internal C++ code of FLasher.
}
\description{
    Probably the best way to use this package is with the devtools and testthat packages and running test("FLasherTests").
    This will run all the tests in the package and tell where things break. Alternatively you can run R CMD check but this takes longer and gives fewer details.
}
\details{
    Ghost Reveries is excellent but I prefer Blackwater Park.
}
\author{
Finlay Scott

Maintainer: Finlay Scott<finlay.scott@ec.europa.eu>
}
\keyword{ package }
\examples{
  \dontrun{
      library(devtools)
      library(testthat)
      load_all("FLasherTests")
      test("FLasherTests")
  }
}
