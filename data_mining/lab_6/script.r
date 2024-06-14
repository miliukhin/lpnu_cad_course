library(arulesViz)

receipts <- read.csv("receipts.csv")
summary(receipts)
trans <- transactions(receipts)
# summary(trans)
# str(trans)
# colnames(trans)
rules = apriori(trans)

cat("---\n")
cat("Ось, які правила утворились:\n")
cat("---\n")

inspect(rules)
plot(rules)

cat("---\n")
cat("Асоціативний аналіз зі значенням support=0.005, confidence=0.5\n")
cat("---\n")

rules2 <- apriori(receipts, parameter = list(support = 0.005, confidence = 0.5))

cat("---\n")
cat("Ось правила:\n")
cat("---\n")

inspect(rules2)
plot(rules2)

plot(rules2, method = "graph")
