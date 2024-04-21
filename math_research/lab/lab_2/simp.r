iden <- function(n)
    if (n > 0) diag(rep(1,n)) else NULL

simplex <- function (func, mat, b) {
	obfun <- -func
	tableau <- rbind(mat, obfun)
	tableau <- cbind(tableau, iden(nrow(tableau)))
	tableau <- cbind(tableau, c(b,0))
	m <- nrow(tableau)
	n <- ncol(tableau)
	print(tableau)

	while (!all(tableau["obfun",] >= 0)) {
		pc <- which.min(tableau["obfun",])
		ind <- which(tableau[1:m-1] > 0)
		if (all(tableau[ind,n]/tableau[ind,pc] != Inf)) {
			pr <- which.min(tableau[ind,n]/tableau[ind,pc])
			tableau[pr,] <- tableau[pr,]/tableau[pr,pc]
		} else break
		np = (1L:m)[-pr]
		for (i in np) {
			tableau[i,] <- tableau[i,] - tableau[i,pc]*tableau[pr,]
		}
		print(tableau)
	}
	cat("\nМаксимальне значення функції:", tableau[m,n], "\nза значень змінних: ")
	x <- vector()
	for (i in 1:length(func)) {
			x[i] <- head(which(tableau[,i] == 1),1)
		cat(paste("x",i,": ",tableau[x[i],n],sep="")," ")
	}
	cat("\n")
}

b <- c(168,180,144)
func <- c(14,18)
dat <- c(10,5,6,8,10,12)
mat <- matrix(dat,3)
simplex(func, mat, b)
