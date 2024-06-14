# Load required library
library(tree)

# Load iris dataset
data(iris)

# Train decision tree model
tree_model <- tree(Species ~ ., data = iris)

# Plot the decision tree
plot(tree_model)
text(tree_model, pretty = 0)
