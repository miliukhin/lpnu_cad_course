Блейзер = c(0.5,6)
Пуховик = c(4,48)
Ватні_штани = c(2,24)
Вєтнамки = c(0.5,6)
Джинси = c(1,12)
Кепка = c(0.5,6)
Кросівки = c(1,12)
Куртка = c(2,24)
Пальто = c(3,36)
Рукавички = c(0.5,6)
Светр = c(1,12)
Сорочка = c(0.5,6)
Футболка = c(0.5,6)
Черевики = c(1.5,18)
Чоботи = c(2,24)
Шапка = c(1,12)
Шорти = c(0.5,6)

h1 <- list(Шапка, Пуховик, Рукавички, Ватні_штани, Чоботи)
h2 <- list(Шапка, Пальто, Рукавички, Джинси, Чоботи)
h3 <- list(Кепка, Куртка, c(0,0), Джинси, Черевики)
h4 <- list(c(0,0), Светр, c(0,0), Джинси, Кросівки)
h5 <- list(Блейзер, Сорочка, c(0,0), Джинси, Кросівки)
h6 <- list(Блейзер, Футболка, c(0,0), Шорти, Вєтнамки)

sets <- list(h1,h2,h3,h4,h5,h6)

chooser <- function(temp) {
	if (temp < -10)
		return(h1)
	else if (temp < 0)
		return(h2)
	else if (temp < 10)
		return(h3)
	else if (temp < 20)
		return(h4)
	else if (temp < 30)
		return(h5)
	else
		return(h6)
}

mem <- function (m, h, probs) {
	i=1
	sum = 0
	init_weight <- sum(sapply(h, function(pair) pair[1]))
	# print(init_weight)
	while (i <= length(m)) {
		res <- chooser(m[i])
		# print(h[[1]])
		# print(res)
		differing_pairs <- res[sapply(seq_along(h), function(i) {
			any(h[[i]] != res[[i]])
		})]

		j <- 1
		while (j <= length(differing_pairs)) {
			# print(differing_pairs[[j]][2] + 2 )
			sum = sum + (differing_pairs[[j]][2] + 2) * probs[i]
			j <- j + 1
		}
		optimality <- -sum - init_weight*10
		i <- i + 1
	}
	optimality
}

m1 <- -4
m2 <- -4
m3 <- -0
m4 <- +6
m5 <- +12
m6 <- +15
m7 <- +17
m8 <- +16
m9 <- +12
m10 <- +7
m11 <- +1
m12 <- -2

temp <- c(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12)

wrap_to_wrap_them_all <- function (temp, probs) {
	# print(deparse(substitute(h)))
	index = 1
	for (h in sets) {
		cat("h:", index, "")
		print(mem(temp, h, probs))
		index <- index + 1
	}
}

# завдання 2
print.noquote("2. Рівноймовірні повернення!")
wrap_to_wrap_them_all(temp, rep(1/12, 12))
# завдання 3
print.noquote("3. 1/3!")
print.noquote("Зима")
wrap_to_wrap_them_all(temp[c(1, 2, 12)], rep(1/3, 3))
print.noquote("Весна")
wrap_to_wrap_them_all(temp[3:5], rep(1/3, 3))
print.noquote("Літо")
wrap_to_wrap_them_all(temp[6:8], rep(1/3, 3))
print.noquote("Осінь")
wrap_to_wrap_them_all(temp[9:11], rep(1/3, 3))
# завдання 4
print.noquote("4. Зима втричі вірогідніша за решту!")
probs <- c(rep(1/6, 2), rep(1/18, 9), 1/6)
wrap_to_wrap_them_all(temp, probs)
# 4.5 Визначити найкращу стратегію при поверненні протягом одного з 12-
# ти місяців за умови, що ймовірність повернення залежить від кількості
# днів у місяці (рік вважати не високосним).
print.noquote("5. Рахуємо дні!")
probs <- c(0.08493, 0.07671, 0.08493, 0.08219, 0.08493, 0.08219, 0.08493, 0.08493, 0.08219, 0.08493, 0.08219, 0.08493)
wrap_to_wrap_them_all(temp, probs)
# 4.6 Визначити найкращу стратегію при поверненні протягом одного з 12-
# ти  місяців  за  умови,  що  ймовірність  повернення  в  кожен  з  місяців
# однакова, а початкова вартість речей з номерами № 2, 4, 9, 15, 16 (табл.
# 1.1) зменшилася втричі.
print.noquote("6. Однакові ймовірності, дешевші речі!")
Пуховик[2] = Пуховик[2] / 3
Вєтнамки[2] = Вєтнамки[2] / 3
Пальто [2] = Пальто[2] / 3
Чоботи[2] = Чоботи[2] / 3
Шапка[2] = Шапка[2] / 3

h1 <- list(Шапка, Пуховик, Рукавички, Ватні_штани, Чоботи)
h2 <- list(Шапка, Пальто, Рукавички, Джинси, Чоботи)
h3 <- list(Кепка, Куртка, c(0,0), Джинси, Черевики)
h4 <- list(c(0,0), Светр, c(0,0), Джинси, Кросівки)
h5 <- list(Блейзер, Сорочка, c(0,0), Джинси, Кросівки)
h6 <- list(Блейзер, Футболка, c(0,0), Шорти, Вєтнамки)

sets <- list(h1,h2,h3,h4,h5,h6)

# sets <- list(h1,h2,h3,h4,h5,h6)
# sets

wrap_to_wrap_them_all(temp, rep(1/12, 12))
