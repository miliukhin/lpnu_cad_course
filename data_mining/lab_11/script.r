library(e1071)
library(caret)

data <- iris

set.seed(123)
train_index <- sample(1:nrow(data), 0.8*nrow(data)) # 70% train data
train_data <- data[train_index, ]
test_data <- data[-train_index, ]

svm_model <- svm(Species ~ ., data = train_data, type = "C-classification", kernel = "radial", decision.values = TRUE)

predictions <- predict(svm_model, test_data)
accuracy <- mean(predictions == test_data$Species)

svm_model
predictions
accuracy

cm <- confusionMatrix(predictions, test_data$Species)
cm
