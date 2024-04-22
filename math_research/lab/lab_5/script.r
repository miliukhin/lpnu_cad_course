ctar <- read.csv("c.csv", row.names = 1)
ftar <- read.csv("f.csv", row.names = 1)
ttar <- read.csv("t.csv", row.names = 1)
htar <- read.csv("h.csv", row.names = 1)

subsetter <- function (x) {
	head(x[,which(x["Парето",] == "-")], 3)
}

twho <- subsetter(ttar)
hwho <- subsetter(htar)

numerize <- function(x) {
	for (i in 1:length(x)) {
		x[,i] <- as.numeric(x[,i])
	}
	x
}

twho <- numerize(twho)
hwho <- numerize(hwho)

ideal_point <- function(x) {
	ideal_point <- c(0,0,0)
	mindist <- Inf
	distlist <- c()
	for (i in 1:length(x)) {
		dist <- sqrt(sum(x[,i] - ideal_point[i])^2)
		distlist[i] <- dist
	}
	x <- rbind(x,dist=distlist)
}

maxmin <- function (x, quotients=c(1/3,1/3,1/3)) {
	maxlist <- c()
	cat("Коефіцієнти:", quotients, "\n")
	for (i in 1:ncol(x)) {
		maxlist[i] <- max(quotients * x[,i])
	}
	x <- rbind(x, max=maxlist)
}

cat("Розпізнавання символа T (ідеальна точка)\n")
write.csv(ideal_point(twho), "t_ideal_point.csv")
cat("Розпізнавання символа H (ідеальна точка)\n")
write.csv(ideal_point(hwho), "h_ideal_point.csv")

cat("Розпізнавання символа T (максмінна згортка)\n")
write.csv(maxmin(twho), "t_maxmin_1.csv")
write.csv(maxmin(twho, c(0.25,0.25,0.5)), "t_maxmin_2.csv")
cat("Розпізнавання символа H (максмінна згортка)\n")
write.csv(maxmin(hwho), "h_maxmin_1.csv")
write.csv(maxmin(hwho, c(0.25,0.25,0.5)), "h_maxmin_2.csv")
