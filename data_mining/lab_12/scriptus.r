library(mlbench)
library(rpart)
library(rpart.plot)

pm <- iris

diabetes_mod_1 <- rpart(Species ~ .,pm,
                        method="class",cp=0.017)
rpart.plot(x = diabetes_mod_1)
