sub <- read.csv2("서울교통공사_월별 승하차인원_20191231.csv", sep =",")
subsum <- apply(sub[4:15], 1, sum)
gg <- ggplot(sub, aes(x=역명, y=합계))+theme(x = element_text((size=5))) + geom_point(aes(color = 호선))

print(gg)