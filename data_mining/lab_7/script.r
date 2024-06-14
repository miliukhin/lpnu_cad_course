regvar <- read.csv("data.csv")
# scatter.smooth(x=regvar$x1, y=regvar$y)

model <- lm(y ~ x1, data = regvar)
# abline(model)

plot(regvar$x1, regvar$y); abline(model)

reg <- lm(y ~ x1, data = regvar)
summary(reg)

fit <- aov(y ~ x1, data = regvar)
summary(fit)

regdouble <- lm(y ~ x1+x2, data = regvar)
summary(regdouble)
