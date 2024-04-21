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
	# шукаєм координати ідеальної точки
	# або 0,0,0 --- ідеальна точка, зручно ж
	ideal_point <- c(0,0,0)
	# for (i in 1:nrow(x)) {
	# 	ideal_point[i] <- min(x[i,])
	# }
	# обчислюємо відстані
	mindist <- Inf
	distlist <- c()
	for (i in 1:length(x)) {
		dist <- sqrt(sum(x[,i] - ideal_point[i])^2)
		distlist[i] <- dist
	}
	x <- rbind(x,dist=distlist)
	print(x)
	print(which.min(x["dist",]))
}

cat("Розпізнавання символа T (ідеальна точка)\n")
ideal_point(twho)
cat("Розпізнавання символа H (ідеальна точка)\n")
ideal_point(hwho)

# точно зручно?
maxmin <- function (x, quotients=c(1/3,1/3,1/3)) {
	maxlist <- c()
	cat("Коефіцієнти:", quotients, "\n")
	# print(x[,1])
	# print(quotients*x[,1])
	for (i in 1:ncol(x)) {
		# print(max(x[,i]))
		maxlist[i] <- max(quotients * x[,i])
		# maxlist[i] <- max(x[,i])
	}
	x <- rbind(x, max=maxlist)
	print(x)
	which.min(x["max",])
}

cat("Розпізнавання символа T (максмінна згортка)\n")
maxmin(twho)
maxmin(twho, c(0.25,0.25,0.5))
cat("Розпізнавання символа H (максмінна згортка)\n")
maxmin(hwho)
maxmin(hwho, c(0.25,0.25,0.5))
