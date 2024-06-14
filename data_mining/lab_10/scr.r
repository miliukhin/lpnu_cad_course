library(tidyverse)
df_knn <- iris %>% mutate_if(is.numeric, scale)

library(caret)

knnModel <- train(
             Species ~ .,
             data = iris,
                method = "knn",
             trControl = trainControl(method = "cv"),
             tuneGrid = data.frame(k = c(1:30))
            )

best_model<- knn3(
                  Species ~ .,
                  data = iris,
                  k = knnModel$bestTune$k
                 )

knnModel
best_model

predictions <- predict(best_model, iris,type = "class")
predictions

cm <- confusionMatrix(predictions, iris$Species)
cm
