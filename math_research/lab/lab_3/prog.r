s1 <- c(63,55,90,58,30,04,71,61,33,85,89,73,04,51,05,50,68,03,85,06)
s2 <- c(95,39,49,20,67,26,63,77,96,81,65,60,36,55,70,18,11,42,32,96)
s3 <- c(79,21,70,84,72,27,34,40,83,72,98,30,63,47,50,30,73,14,59,22)
s4 <- c(s1,s2,s3)

nfa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0
	for (element in elements) {
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			# cat("   вага:", element, '\t', "залишилось місця:", containers[index], '\n')
		}
		else {
			index <- index + 1
			containers[index] = 100
			containers[index] <- containers[index] - element
			# cat("🥡 вага:", element, '\t', "залишилось місця:", containers[index], '\n')
		}
		comparisons = comparisons + 1
	}
	cat("NFA\nскладність:", comparisons, "\n")
	containers
}

ffa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0
	for (element in elements) {
		added = FALSE
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			# cat("   вага:", element, '\t', "залишилось місця:", containers[index], '\n')
			added = TRUE
		}
		else {
			# print(containers)
			for(container in containers) {
				# cat("?", "контейнер", container, "елемент", element, '\n')
				comparisons = comparisons + 1
				# cat("складність:", comparisons, "\n")
				if (element <= container) {
					container <- container - element
					# cat("   вага:", element, '\t', "залишилось місця:", container, '\n')
					added = TRUE
				}
			}
			if (!added) {
				index <- index + 1
				containers[index] = 100
				containers[index] <- containers[index] - element
				# cat("🥡 вага:", element, '\t', "залишилось місця:", containers[index], '\n')
			}
		}
		comparisons = comparisons + 1
	}
	cat("FFA\nскладність:", comparisons, "\n")
	containers
}

wfa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0
	for (element in elements) {
		added = FALSE
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			# cat("   вага:", element, '\t', "залишилось місця:", containers[index], '\n')
			added = TRUE
		}
		else {
			mindex = length(containers)
			free_space = 0

			for(i in length(containers):1) {
				# cat("🤔", "контейнер", containers[i], "елемент", element, free_space)
				comparisons = comparisons + 2
				if (free_space < containers[i] && containers[i] >= element) {
					# cat('😎')
					mindex = i
					free_space = containers[i]
				}
				# cat('\n')
			}
			# cat("контейнер", mindex, "місця", free_space, "\n")
			comparisons = comparisons + 1
			if(free_space >= element && free_space != 0) {
				# print(mindex)
				# cat("😎  вага:", element, '\t', "залишилось місця:", containers[mindex], '\n')
				# print(containers[mindex])
				containers[mindex] <- containers[mindex] - element
				added = TRUE
			}
			if (!added) {
				index <- index + 1
				containers[index] = 100
				containers[index] <- containers[index] - element
				# cat("🥡 вага:", element, '\t', "залишилось місця:", containers[index], '\n')
			}
		}
		comparisons = comparisons + 1
	}
	cat("WFA\nскладність:", comparisons, "\n")
	containers
}

bfa <- function (elements) {
	containers = c(100)
	index <- 1
	comparisons = 0
	for (element in elements) {
		added = FALSE
		if (element <= containers[index]) {
			containers[index] <- containers[index] - element
			# cat("   вага:", element, '\t', "залишилось місця:", containers[index], '\n')
			added = TRUE
		}
		else {
			# free_space = tail(containers, 1)
			mindex = length(containers)
			free_space = 100

			for(i in length(containers):1) {
				# cat("🤔", "контейнер", containers[i], "елемент", element, free_space)
				comparisons = comparisons + 2
				if (free_space > containers[i] && containers[i] >= element) {
					# cat('😎')
					mindex = i
					free_space = containers[i]
				}
				# cat('\n')
			}
			# cat("контейнер", mindex, "місця", free_space, "\n")
			comparisons = comparisons + 1
			if(free_space >= element && free_space != 100) {
				# print(mindex)
				# cat("😎  вага:", element, '\t', "залишилось місця:", containers[mindex], '\n')
				# print(containers[mindex])
				containers[mindex] <- containers[mindex] - element
				added = TRUE
			}
			if (!added) {
				index <- index + 1
				containers[index] = 100
				containers[index] <- containers[index] - element
				# cat("🥡 вага:", element, '\t', "залишилось місця:", containers[index], '\n')
			}
		}
		comparisons = comparisons + 1
	}
	cat("BFA\nскладність:", comparisons, "\n")
	containers
}

cat("Аналітичний розрахунок кількості контейнерів\n")
ceiling( sum(s1)/100 )
ceiling( sum(s2)/100 )
ceiling( sum(s3)/100 )
ceiling( sum(s4)/100 )

cat("1 рядок:\n")
length(nfa(s1))
length(ffa(s1))
length(wfa(s1))
length(bfa(s1))

cat("2 рядок:\n")
length(nfa(s2))
length(ffa(s2))
length(wfa(s2))
length(bfa(s2))

cat("3 рядок:\n")
length(nfa(s3))
length(ffa(s3))
length(wfa(s3))
length(bfa(s3))

cat("3 рядки разом:\n")
length(nfa(s4))
length(ffa(s4))
length(wfa(s4))
length(bfa(s4))

s1_sorted <- rev(sort(s1))
s2_sorted <- rev(sort(s2))
s3_sorted <- rev(sort(s3))
s4_sorted <- rev(sort(s4))

print("Посортовані")

cat("1 рядок:\n")
length(nfa(s1_sorted))
length(ffa(s1_sorted))
length(wfa(s1_sorted))
length(bfa(s1_sorted))

cat("2 рядок:\n")
length(nfa(s2_sorted))
length(ffa(s2_sorted))
length(wfa(s2_sorted))
length(bfa(s2_sorted))

cat("3 рядок:\n")
length(nfa(s3_sorted))
length(ffa(s3_sorted))
length(wfa(s3_sorted))
length(bfa(s3_sorted))

cat("3 рядки разом:\n")
length(nfa(s4_sorted))
length(ffa(s4_sorted))
length(wfa(s4_sorted))
length(bfa(s4_sorted))
