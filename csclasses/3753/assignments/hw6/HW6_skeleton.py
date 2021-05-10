import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import pdb

def k_means_clustering(data, centroids, k):
    centroid_current = centroids
    centroid_last = pd.DataFrame()
    clusters = pd.DataFrame()
    
    # iterate until convergence
    while not centroid_current.equals(centroid_last):
        
        cluster_count = 0 #it counts the number of clusters. Cluster IDs start from 0.
        # calculate the distance of each point to the K centroids
        for idx, position in centroid_current.iterrows():# the idx will not be used. We just separate the index with the actual data "position" in the dataset. You will use "cluster_count" as the column index in "clusters".
            # your code is here. Save the Euclidean distances into 'clusters'
            distanceList = []
            for i in data.index:
                distanceList.append(((position['x'] - data['x'][i]) ** 2 + (position['y'] - data['y'][i]) ** 2) ** (1/2))
            
            clusters.insert(cluster_count, cluster_count, distanceList)
            
            # your code ends
            cluster_count += 1
        
        print(clusters)
        return
        # update cluster, assign the points to clusters
        clusterIDs = []
        for row_idx in range(len(clusters)):
            # your code is here. Check the distances at every row in 'clusters'. Save the assigned cluster IDs to points. The IDs start from 0
            pass
 
 
           # your code ends
        # assign points to clusters. The information is saved in the list and assigned to the dataset.
        data['Cluster'] = clusterIDs
        
        # store previous cluster
        centroid_last = centroid_current
        
        # Update the centroid of each cluster. All information are in 'data'. You have to calculate the new centroids based on the points in the same cluster.
        # The centroid is the center of a list of points. For example, (x1, y1), (x2, y2), ..., (xn, yn). The centroid is (x, y), where x = the mean of (x1, x2, ..., xn) and y = the mean of (y1, y2, ..., yn).
        centroids =[]
        points= [] # save k lists of points in the list. The points in the same list are in the same cluster. 
        # your code is here. The K centroids will be saved in 'centroids', e.g. [[1, 2], [3, 4], [5, 6]]
        
        
        
        # your code ends
        centroid_current = pd.DataFrame(data=centroids, columns = ['x', 'y'])
         
        print("No updates on clusters: ", centroid_current.equals(centroid_last))

    print("Convergence! Final centroids:", centroid_current)
    # plotting
    print('Plotting...')
    colors= ['b', 'g', 'r', 'c', 'm', 'y', 'k']
    
    # scatter plot all points. All points are colored circles
    for i in range(k):
        p = np.array(points[i])
        x, y = p[:,0], p[:, 1]
        
        plt.scatter(x, y, color = colors[i])
        plt.scatter(centroid_current['x'], centroid_current['y'], marker='^', color = colors[i])
    
    # scatter plot all centroids. All points are colored triangles
    for j in range(k):
        plt.scatter(centroid_current.iloc[j][0], centroid_current.iloc[j][1], marker='^', color= colors[j])
        
    plt.show()

if __name__ == '__main__':
    # Question 1 K-means clustering
    data = pd.read_csv('k_means_clustering_data.csv')
    seeds = []
    # Seed selection 1: random selected 3 points as centroids (4, 4), (8, 0), (6, 3)
    seeds.append(pd.DataFrame([[4, 4], [8, 0], [6, 3]], index=[13, 32, 23], columns = ['x', 'y']))
    
    # Seed selection 2: random selected 3 points as centroids (3, 6), (5, 6), (7, 4)
    seeds.append(pd.DataFrame([[3, 6], [5, 6], [7, 4]], index=[11, 17, 28], columns = ['x', 'y']))
    
    # Seed selection 3: random selected 3 points as centroids (3, 4), (2, 9), (3, 8)
    seeds.append(pd.DataFrame([[3, 4], [2, 9], [3, 8]], index=[10, 7, 12], columns = ['x', 'y']))
    
    for i in range(3):
      centroids = seeds[i]
      print('Initial centroids:\n', centroids)
      k_means_clustering(data, centroids, 3)


    # Question 2 Hidden Markov Model
    # your code is here
    
    
    # your code ends
    
