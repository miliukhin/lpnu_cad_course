read.csv("data.csv") -> table -> risk_table -> hurwitz_table

table$min <- apply(table, 1, FUN = min)
cat("Найоптимальніша стратегія за Вальдом:", which.max(table$min), '\n')

risk_table$p_1 = max(risk_table$p_1) - risk_table$p_1
risk_table$p_2 = max(risk_table$p_2) - risk_table$p_2
risk_table$p_3 = max(risk_table$p_3) - risk_table$p_3
risk_table$p_4 = max(risk_table$p_4) - risk_table$p_4
risk_table$p_5 = max(risk_table$p_5) - risk_table$p_5
risk_table$p_6 = max(risk_table$p_6) - risk_table$p_6
risk_table$max_risk <- apply(risk_table, 1, FUN = max)
cat("Найоптимальніша стратегія за Севіджем:", which.min(risk_table$max_risk), '\n')

hurwitz_table$min <- apply(table, 1, FUN = min)
hurwitz_table$max <- apply(table, 1, FUN = max)
khi <- 0.1
hurwitz_table$h <- floor(khi*hurwitz_table$min + (1-khi)*hurwitz_table$max)
cat("Найоптимальніша стратегія за Гурвіцом:", which.max(hurwitz_table$h), '\n')
