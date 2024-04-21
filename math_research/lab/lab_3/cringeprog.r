s1 <- c(63,55,90,58,30,04,71,61,33,85,89,73,04,51,05,50,68,03,85,06)
s2 <- c(95,39,49,20,67,26,63,77,96,81,65,60,36,55,70,18,11,42,32,96)
s3 <- c(79,21,70,84,72,27,34,40,83,72,98,30,63,47,50,30,73,14,59,22)
s4 <- c(s1,s2,s3)

nfa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0

	eli <- 1
	zero_matrix <- matrix(NA, nrow = 1, ncol = length(elements))
	table <- as.data.frame(zero_matrix)
	for (element in elements) {
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element

			table[index, eli] <- element
			eli <- eli + 1
		}
		else {
			index <- index + 1
			containers[index] = 100
			containers[index] <- containers[index] - element

			table[index, eli] = element
			eli <- eli + 1
		}
		comparisons = comparisons + 1
	}
	print(table)
	cat("NFA\nскладність:", comparisons, "\n")
	containers
}

ffa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0

	eli <- 1
	zero_matrix <- matrix(NA, nrow = 1, ncol = length(elements))
	table <- as.data.frame(zero_matrix)
	for (element in elements) {
		added = FALSE
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			added = TRUE
			table[index, eli] = element
			eli <- eli + 1
		}
		else {
			for(container in containers) {
				comparisons = comparisons + 1
				if (element <= container) {
					container <- container - element
					added = TRUE
					table[index, eli] = element
					eli <- eli + 1
					break
				}
			}
			if (!added) {
				index <- index + 1
				containers[index] = 100
				containers[index] <- containers[index] - element
				table[index, eli] = element
				eli <- eli + 1
			}
		}
		comparisons = comparisons + 1
	}
	print(table)
	cat("FFA\nскладність:", comparisons, "\n")
	containers
}

wfa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0

	eli <- 1
	zero_matrix <- matrix(NA, nrow = 1, ncol = length(elements))
	table <- as.data.frame(zero_matrix)
	for (element in elements) {
		added = FALSE
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			added = TRUE
			table[index, eli] = element
			eli <- eli + 1
		}
		else {
			mindex = length(containers)
			free_space = 0

			for(i in length(containers):1) {
				comparisons = comparisons + 2
				if (free_space < containers[i] && containers[i] >= element) {
					mindex = i
					free_space = containers[i]
				}
			}
			comparisons = comparisons + 1
			if(free_space >= element && free_space != 0) {
				containers[mindex] <- containers[mindex] - element
				added = TRUE
				table[index, eli] = element
				eli <- eli + 1
			}
			if (!added) {
				index <- index + 1
				containers[index] = 100
				containers[index] <- containers[index] - element
				table[index, eli] = element
				eli <- eli + 1
			}
		}
		comparisons = comparisons + 1
	}
	print(table)
	cat("WFA\nскладність:", comparisons, "\n")
	containers
}

bfa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0

	eli <- 1
	zero_matrix <- matrix(NA, nrow = 1, ncol = length(elements))
	table <- as.data.frame(zero_matrix)
	for (element in elements) {
		added = FALSE
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			added = TRUE
			table[index, eli] = element
			eli <- eli + 1
		}
		else {
			mindex = length(containers)
			free_space = 100

			for(i in length(containers):1) {
				comparisons = comparisons + 2
				if (free_space > containers[i] && containers[i] >= element) {
					mindex = i
					free_space = containers[i]
				}
			}
			comparisons = comparisons + 1
			if(free_space >= element && free_space != 100) {
				containers[mindex] <- containers[mindex] - element
				added = TRUE
				table[index, eli] = element
				eli <- eli + 1
			}
			if (!added) {
				index <- index + 1
				containers[index] = 100
				containers[index] <- containers[index] - element
				table[index, eli] = element
				eli <- eli + 1
			}
		}
		comparisons = comparisons + 1
	}
	print(table)
	cat("BFA\nскладність:", comparisons, "\n")
	containers
}

cat("1 рядок:\n")
nfa(s1)
ffa(s1)
wfa(s1)
bfa(s1)

cat("2 рядок:\n")
nfa(s2)
ffa(s2)
wfa(s2)
bfa(s2)

cat("3 рядок:\n")
nfa(s3)
ffa(s3)
wfa(s3)
bfa(s3)

cat("3 рядки разом:\n")
nfa(s4)
ffa(s4)
wfa(s4)
bfa(s4)

s1_sorted <- rev(sort(s1))
s2_sorted <- rev(sort(s2))
s3_sorted <- rev(sort(s3))
s4_sorted <- rev(sort(s4))

print("Посортовані")

cat("1 рядок:\n")
nfa(s1_sorted)
ffa(s1_sorted)
wfa(s1_sorted)
bfa(s1_sorted)

cat("2 рядок:\n")
nfa(s2_sorted)
ffa(s2_sorted)
wfa(s2_sorted)
bfa(s2_sorted)

cat("3 рядок:\n")
nfa(s3_sorted)
ffa(s3_sorted)
wfa(s3_sorted)
bfa(s3_sorted)

cat("3 рядки разом:\n")
nfa(s4_sorted)
ffa(s4_sorted)
wfa(s4_sorted)
bfa(s4_sorted)
