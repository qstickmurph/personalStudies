def main():
    #%% import necessary modules
    import numpy as np
    import matplotlib.pyplot as plt
    from sklearn.linear_model import LinearRegression
    import pdb

    ##Q1, 20pts
    #%% Q1a, 15pts
    # the plot is not required
    #Your code is here
    X = np.array([[2005], [2006], [2007], [2008], [2009]])
    y = np.array([12, 19, 29, 37, 45])

    linReg = LinearRegression().fit(X, y)
    print("Q1a:")

    print("beta =", linReg.coef_)
    print("alpha =", linReg.intercept_)

    #%%Q1b, 5pts
    #Your code is here
    print("")
    print("Q1b:")

    print('Estimated sales in 2012 is', linReg.predict(np.array([[2012]])))
    #Output the result by print('Estimated sales in 2012 is ', XXX)


    #%% Q2, 20 pts 
    #Q2a, 15pts, just output the formula directly
    print("")
    print("Q2a:")

    print("2*bimom.pmf(12, 15, .5) + 2*bimon(13, 15, .5) + 2*bimon(14, 15, .5) + 2*bimon(15, 15, .5)")

    #Q2b, 5pts, just output either 'accept' or 'reject'
    print("")
    print("Q2b:")


    print("Reject")
    #%% Q3 setup, 70pts
    import scipy.stats as stats
    import numpy.random as rn
    #%% Q3a, 15pts
    rn.seed(0)
    N = 16;
    m = 10**5;
    # 10**5 by 16 = 16 + 16 + ... + 16
    # use the uniform or binomial functions to generate the data
    nHeads = (rn.uniform(size=(m, N))>0.5).sum(1)

    #%%plot the histgram
    # Your code is here
    print("")
    print("Q3a: Histogram")
    
    plt.hist(nHeads, bins=range(18))
    plt.title("Q3a: Histogram")
    plt.xlabel("nHeads")
    plt.ylabel("Number of trials")
    plt.show()

    #%% Q3b, 15pts
    # using plt.hist with parameter and density
    #Your code is here
    print("")
    print("Q3b: Probability Mass Function")
    
    plt.hist(nHeads,bins=range(18), density=True)
    plt.title("Q3b: Probability Mass Function")
    plt.xlabel("k")
    plt.ylabel("P(nHeads = k)")
    plt.show()

    #%% Q3c, 15pts

    #You can calculate the probabilities/counts with your own code or using values returned from 2a/2b.
    # Your code is here
    print("")
    print("Q3c: Cumulative Distribution Function")
    
    pmf = np.zeros(17)
    nHeadsSum = len(nHeads)
    for i in range(17):
        pmf[i] = np.count_nonzero(nHeads == i) / nHeadsSum
    
    cdf = np.zeros(17)
    cdf[0] = pmf[0]
    for i in range(1,17):
        cdf[i] = cdf[i-1] + pmf[i]
    print("SUM:", pmf)

    plt.plot( range(16+1), cdf )
    plt.title("Q3c: Cumulative Distribution Function")
    plt.xlabel("k")
    plt.ylabel("P(nHeads <= k)")
    plt.show()


    #%% Q3d, 25pts
    # Use the binomial distribution CDF (use scipy.stats.binom.cdf)

    # Your code is here
    print("")
    print("Q3d: Q3d Scatter Plot")

    # scatter plot
    # Your code is here
    
    plt.scatter( cdf, [stats.binom.cdf(i, 16, 0.5) for i in range(17)] )
    plt.title("Q3d: Scatter Plot")
    plt.xlabel("Empirical CDF")
    plt.ylabel("Theoretical CDF")
    plt.show()

    # line plot
    #Your code is here
    print("")
    print("Q1b:")

    plt.plot( cdf, [stats.binom.cdf(i, 16, 0.5) for i in range(17)], "-")
    plt.title("Q3d: Line Plot")
    plt.xlabel("Empirical CDF")
    plt.ylabel("Theoretical CDF")
    plt.show()

    # Loglog scale plot
    #your code is here
    print("")
    print("Q1b:")

    plt.scatter( cdf, [stats.binom.cdf(i, 16, 0.5) for i in range(17)])
    plt.xscale('log')
    plt.yscale('log')
    plt.xlim([10**-5, 1])
    plt.ylim([10**-5, 1])
    plt.title("Q3d: Log Log Scatter Plot")
    plt.xlabel("Empirical CDF")
    plt.ylabel("Theoretical CDF")
    plt.show()

if __name__ == "__main__":
    main()
