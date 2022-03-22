# Traceroutes
### Traceroute 1 (8:37pm) 
traceroute to www.nyse.com (104.16.103.50), 30 hops max, 60 byte packets
 1  \_gateway (10.0.1.1)  2.579 ms  2.533 ms  2.512 ms
 2  cpe-67-11-96-1.satx.res.rr.com (67.11.96.1)  15.293 ms  15.275 ms  21.393 ms
 3  tge0-0-12.snaxtxfp02h.texas.rr.com (24.28.133.77)  37.608 ms  37.590 ms  25.955 ms
 4  agg24.snaptx1902r.texas.rr.com (24.175.33.100)  15.787 ms  21.927 ms  21.908 ms
 5  agg22.snantxvy01r.texas.rr.com (24.175.32.168)  23.327 ms  23.310 ms  23.292 ms
 6  agg23.dllatxl301r.texas.rr.com (24.175.32.146)  105.965 ms  27.540 ms  27.492 ms
 7  bu-ether24.dllstx976iw-bcr00.tbone.rr.com (66.109.6.52)  27.472 ms  39.730 ms bu-ether14.dllstx976iw-bcr00.tbone.rr.com (66.109.6.88)  39.681 ms
 8  209-18-43-77.dfw10.tbone.rr.com (209.18.43.77)  39.662 ms 66.109.5.121 (66.109.5.121)  40.922 ms 209-18-43-77.dfw10.tbone.rr.com (209.18.43.77)  39.627 ms
 9  24.30.200.61 (24.30.200.61)  39.611 ms  45.025 ms  39.572 ms
10  104.16.103.50 (104.16.103.50)  39.561 ms  39.543 ms  39.524 ms

### Traceroute 2 (9:17pm) 
traceroute to www.nyse.com (104.16.103.50), 30 hops max, 60 byte packets
 1  \_gateway (10.0.1.1)  3.629 ms  3.586 ms  3.565 ms
 2  cpe-67-11-96-1.satx.res.rr.com (67.11.96.1)  17.124 ms  17.108 ms  13.973 ms
 3  tge0-0-12.snaxtxfp02h.texas.rr.com (24.28.133.77)  38.771 ms  26.173 ms  38.736 ms
 4  agg24.snaptx1902r.texas.rr.com (24.175.33.100)  13.649 ms  18.370 ms  13.617 ms
 5  agg22.snantxvy01r.texas.rr.com (24.175.32.168)  13.599 ms  18.307 ms  13.552 ms
 6  agg23.dllatxl301r.texas.rr.com (24.175.32.146)  25.974 ms  21.472 ms  21.427 ms
 7  bu-ether14.dllstx976iw-bcr00.tbone.rr.com (66.109.6.88)  21.419 ms 66.109.1.216 (66.109.1.216)  22.060 ms bu-ether14.dllstx976iw-bcr00.tbone.rr.com (66.109.6.88)  22.023 ms
 8  66.109.5.121 (66.109.5.121)  18.774 ms 209-18-43-77.dfw10.tbone.rr.com (209.18.43.77)  18.808 ms  27.432 ms
 9  24.30.200.61 (24.30.200.61)  27.361 ms  27.344 ms  27.327 ms
10  104.16.103.50 (104.16.103.50)  27.315 ms  27.299 ms  27.282 ms

### Traceroute 3 (11:00pm) 
traceroute to www.nyse.com (104.16.103.50), 30 hops max, 60 byte packets
 1  \_gateway (10.0.1.1)  4.849 ms  4.805 ms  4.783 ms
 2  cpe-67-11-96-1.satx.res.rr.com (67.11.96.1)  16.655 ms  17.052 ms  17.378 ms
 3  tge0-0-12.snaxtxfp02h.texas.rr.com (24.28.133.77)  111.923 ms  111.902 ms  111.880 ms
 4  agg24.snaptx1902r.texas.rr.com (24.175.33.100)  17.748 ms  17.728 ms  17.707 ms
 5  agg22.snantxvy01r.texas.rr.com (24.175.32.168)  17.650 ms  17.629 ms  17.608 ms
 6  agg23.dllatxl301r.texas.rr.com (24.175.32.146)  38.180 ms  36.865 ms  78.205 ms
 7  bu-ether24.dllstx976iw-bcr00.tbone.rr.com (66.109.6.52)  78.184 ms 66.109.1.216 (66.109.1.216)  29.109 ms bu-ether24.dllstx976iw-bcr00.tbone.rr.com (66.109.6.52)  29.076 ms
 8  209-18-43-77.dfw10.tbone.rr.com (209.18.43.77)  29.014 ms 66.109.5.121 (66.109.5.121)  29.028 ms 209-18-43-77.dfw10.tbone.rr.com (209.18.43.77)  32.596 ms
 9  24.30.200.61 (24.30.200.61)  32.568 ms  29.496 ms  29.470 ms
10  104.16.103.50 (104.16.103.50)  28.896 ms  28.866 ms  29.370 ms


# Problems

## a) Find the average and standard deviation of the round-trip delays at each of the three hours
Hour 1: Mean = 39.5427; Stdev = 0.0185023 \
Hour 2: Mean = 27.2987; Stdev = 0.0165025 \
Hour 3: Mean = 29.044; Stdev = 0.282722 \

## b) Find the number of routers in the path at each of the three hours. Did the paths change during any of the hours?
10 for each of the traceroutes, but the path was one hop different in the 2nd traceroute vs the 1st and 3rd

## c) Try to identify the number of ISP networks that the Traceroute packets pass through from source to destination. Routers with similar names and/ or similar IP addresses should be considered as part of the same ISP. In your experiments, do the largest delays occur at the peering interfaces between adjacent ISPs?
I believe we had 5 different ISP networks:
- satx.res.rr.com
- texas.rr.com
- tbone.rr.com
- 24.30.200.61
- 104.16.103.50

The largest delays always occur when jumping from one ISP to another

## d) Repeat the above for a source and destination on different continents. Compare the intra-continent and inter-continent results.

### Traceroute 1 (9:19pm)
traceroute to www.londonstockexchange.com (18.66.180.5), 30 hops max, 60 byte packets
 1  \_gateway (10.0.1.1)  2.305 ms  2.260 ms  2.242 ms
 2  cpe-67-11-96-1.satx.res.rr.com (67.11.96.1)  20.591 ms  20.573 ms  20.556 ms
 3  tge0-0-12.snaxtxfp02h.texas.rr.com (24.28.133.77)  33.258 ms  32.860 ms  33.224 ms
 4  agg24.snaptx1902r.texas.rr.com (24.175.33.100)  19.304 ms  19.288 ms  19.272 ms
 5  agg22.snantxvy01r.texas.rr.com (24.175.32.168)  19.255 ms  19.237 ms  19.221 ms
 6  agg23.dllatxl301r.texas.rr.com (24.175.32.146)  25.367 ms  28.753 ms  28.705 ms
 7  bu-ether24.dllstx976iw-bcr00.tbone.rr.com (66.109.6.52)  28.654 ms 66.109.1.216 (66.109.1.216)  26.098 ms bu-ether14.dllstx976iw-bcr00.tbone.rr.com (66.109.6.88)  26.829 ms
 8  66.109.5.121 (66.109.5.121)  33.552 ms  28.150 ms  26.007 ms
 9  dls-b23-link.ip.twelve99.net (62.115.156.208)  26.021 ms  29.213 ms  29.197 ms
10  * * dls-bb1-link.ip.twelve99.net (62.115.136.118)  147.209 ms
11  nash-bb1-link.ip.twelve99.net (62.115.137.44)  152.497 ms  152.482 ms  158.094 ms
12  * * atl-bb1-link.ip.twelve99.net (62.115.137.54)  51.473 ms
13  rest-bb1-link.ip.twelve99.net (62.115.138.70)  68.864 ms  68.846 ms  50.859 ms
14  prs-bb2-link.ip.twelve99.net (62.115.122.158)  139.704 ms  139.685 ms  139.666 ms
15  ffm-bb2-link.ip.twelve99.net (62.115.114.99)  142.739 ms ffm-bb2-link.ip.twelve99.net (62.115.122.139)  139.560 ms ffm-bb2-link.ip.twelve99.net (62.115.114.99)  139.536 ms
16  ffm-b1-link.ip.twelve99.net (62.115.121.7)  145.109 ms ffm-b10-link.ip.twelve99.net (62.115.137.211)  139.524 ms ffm-b1-link.ip.twelve99.net (62.115.121.7)  145.075 ms
17  a100row-svc076898-lag003772.ip.twelve99-cust.net (62.115.58.115)  143.734 ms  142.553 ms amazon-ic331702-ffm-b11.ip.twelve99-cust.net (62.115.48.55)  134.142 ms
18  * * *
19  * * *
20  * * *
21  * * *
22  * * *
23  * * *
24  * * *
25  * * *
26  * * *
27  * * *
28  * * *
29  * * *
30  * * *

### Traceroute 2 (11:00pm)
traceroute to www.londonstockexchange.com (13.226.31.75), 30 hops max, 60 byte packets
 1  \_gateway (10.0.1.1)  2.753 ms  2.708 ms  2.689 ms
 2  cpe-67-11-96-1.satx.res.rr.com (67.11.96.1)  14.412 ms  14.394 ms  14.376 ms
 3  * * *
 4  agg24.snaptx1902r.texas.rr.com (24.175.33.100)  14.882 ms  14.864 ms  14.846 ms
 5  agg22.snantxvy01r.texas.rr.com (24.175.32.168)  16.203 ms  15.245 ms  16.169 ms
 6  agg23.dllatxl301r.texas.rr.com (24.175.32.146)  21.912 ms  36.757 ms  36.709 ms
 7  bu-ether14.dllstx976iw-bcr00.tbone.rr.com (66.109.6.88)  39.090 ms 66.109.1.216 (66.109.1.216)  26.198 ms bu-ether24.dllstx976iw-bcr00.tbone.rr.com (66.109.6.52)  26.144 ms
 8  107.14.19.192 (107.14.19.192)  38.222 ms  39.318 ms  39.300 ms
 9  107.14.19.197 (107.14.19.197)  65.748 ms  66.755 ms  66.737 ms
10  bu-ether11.nycmny837aw-bcr00.tbone.rr.com (66.109.6.24)  65.706 ms  65.689 ms bu-ether17.atlngamq47w-bcr01.tbone.rr.com (66.109.6.94)  66.694 ms
11  ae-15-210.pr0.lax10.tbone.rr.com (66.109.9.5)  65.500 ms  77.933 ms  87.311 ms
12  99.82.176.74 (99.82.176.74)  87.257 ms 99.82.183.84 (99.82.183.84)  97.521 ms 99.82.176.72 (99.82.176.72)  70.628 ms
13  * * *
14  * * *
15  * * *
16  * * *
17  * * *
18  * * *
19  * * *
20  server-13-226-31-75.ewr53.r.cloudfront.net (13.226.31.75)  79.607 ms  79.590 ms  79.574 ms

### Traceroute 3 (11:30pm)
traceroute to www.londonstockexchange.com (13.226.31.75), 30 hops max, 60 byte packets
 1  \_gateway (10.0.1.1)  2.149 ms  2.101 ms  2.079 ms
 2  cpe-67-11-96-1.satx.res.rr.com (67.11.96.1)  16.645 ms  16.625 ms  16.607 ms
 3  tge0-0-12.snaxtxfp02h.texas.rr.com (24.28.133.77)  40.361 ms  40.343 ms  40.321 ms
 4  agg24.snaptx1902r.texas.rr.com (24.175.33.100)  21.500 ms  21.479 ms  21.461 ms
 5  agg22.snantxvy01r.texas.rr.com (24.175.32.168)  21.440 ms  21.421 ms  21.402 ms
 6  agg23.dllatxl301r.texas.rr.com (24.175.32.146)  27.749 ms  21.720 ms  24.616 ms
 7  bu-ether24.dllstx976iw-bcr00.tbone.rr.com (66.109.6.52)  25.898 ms 66.109.1.216 (66.109.1.216)  23.070 ms bu-ether14.dllstx976iw-bcr00.tbone.rr.com (66.109.6.88)  23.056 ms
 8  107.14.19.192 (107.14.19.192)  36.222 ms  35.166 ms  36.211 ms
 9  107.14.19.197 (107.14.19.197)  62.308 ms  62.302 ms  73.818 ms
10  bu-ether11.nycmny837aw-bcr00.tbone.rr.com (66.109.6.24)  67.935 ms bu-ether17.atlngamq47w-bcr01.tbone.rr.com (66.109.6.94)  62.274 ms bu-ether11.nycmny837aw-bcr00.tbone.rr.com (66.109.6.24)  66.812 ms
11  ae-15-210.pr0.lax10.tbone.rr.com (66.109.9.5)  66.804 ms  68.272 ms  64.613 ms
12  99.82.176.74 (99.82.176.74)  64.599 ms 99.82.183.84 (99.82.183.84)  64.594 ms 99.82.176.74 (99.82.176.74)  55.568 ms
13  * * *
14  * * *
15  * * *
16  * * *
17  * * *
18  * * *
19  * * *
20  server-13-226-31-75.ewr53.r.cloudfront.net (13.226.31.75)  64.193 ms  64.175 ms  64.950 ms

## a) Find the average and standard deviation of the round-trip delays at each of the three hours
Hour 1: Mean = N/A; Stdev = N/A \
Hour 2: Mean = 79.5903; Stdev = 0.0165025 \
Hour 3: Mean = 64.4393; Stdev = 0.442342 \

## b) Find the number of routers in the path at each of the three hours. Did the paths change during any of the hours?
Each of the successful traceroutes later in the night had 20 hops to their destination. The unsuccessful traceroute had 30 hops before giving up.

For the two successful traceroutes, they were exactly the same except for the 3rd hop which was unresponsive in our 2nd traceroute.

## c) Try to identify the number of ISP networks that the Traceroute packets pass through from source to destination. Routers with similar names and/ or similar IP addresses should be considered as part of the same ISP. In your experiments, do the largest delays occur at the peering interfaces between adjacent ISPs?
satx.res.rr.com
texas.rr.com
tbone.rr.com
107.14.19.xxx
tbone.rr.com
99.82.176.74
\*\*\*

We are unable to know how many ISPs are involved directly due to the unresponsiveness of so many of the routers. However, we do know that the largest delays occur between ISPs rather than within.

