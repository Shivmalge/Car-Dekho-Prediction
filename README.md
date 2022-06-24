# Car-Dekho-Prediction

## The project is bascially is created to predict the prices of Car using Machine Learning and Python. I have created this project using various python libraries, Machine learning algorithm. In this project I have visualized the required data to get better uderstanding of model.

### The dataset contains the independent features and dependent feature(Car Price) are as follows:
- Car Name
- Year
- Present price
- Kilometers Driven
- Fuel Type
- Seller Type
- Transmission
- Owner
- Selling Price(Car Price to predict)


### The libraries used in this project are as follows:
- Numpy
- Pandas
- Matplotlib
- Seaborn
- Sklearn

### I have performed number of steps to build the model.
- Import the required python libreries.
- Read the dataset using Pandas library.
- Feature Engineering - It contains handling data.
- Feature Selection - Selecting required features.
- Split the data into Training and Testing - Some data is selected to train the model and some data is selected for testing the model.
- Select the Best algorithm - To get better accuracy of model or to get similar predicted price with actual price.
- Fit the data 
- Test the data and predict the output i.e. Selling Price
### 1. Imported the libraries and Read the dataset.
![image](https://user-images.githubusercontent.com/104545490/175607385-8149fd9d-f768-4072-a408-5c99ecfd294c.png) 

### 2. Feature Engineering : 
  The main task in the feature engineering is to deal with the null values in the dataset.
    I have checked the whether there are any null values or not. If my dataset there is no null values so no need to drop values. 
    If in case there are null values then for continous variable we will replace that null values by taking mean of features and 
    fill in null cells. If there are categorical fetures then I will replace that null cell by Mode of that feature.
    This how I will handle the missing values in the dataset.
    
    
 ![image](https://user-images.githubusercontent.com/104545490/175608634-7c1f6482-29cc-4b74-a410-993280a1349d.png)
 
 After doing all feature engineering my final dataste will be like this:
 
 ![image](https://user-images.githubusercontent.com/104545490/175609990-a704b96f-052a-4fbe-97b6-b9f2bbf673df.png)


 ### 3. Feature selection : 
 
 After that I have dropped the Car Name and selected all other feature which will be of no use for price prediction 
 
 
 ### 4. Visulaization for finding relation between features:
![image](https://user-images.githubusercontent.com/104545490/175610442-826a787f-ad13-4651-b9e8-4a7a1dc940b6.png)
![image](https://user-images.githubusercontent.com/104545490/175610988-cd49f978-050f-41a7-9616-7f13e1cf432e.png)

![image](https://user-images.githubusercontent.com/104545490/175611278-1e5a4846-ebe0-4300-85ee-7f5485e97d1b.png)
![image](https://user-images.githubusercontent.com/104545490/175611340-9a61868d-728b-43fe-8056-9870e0f60e2e.png)

### 4. Dividing the data into Independent and Dependent features

![image](https://user-images.githubusercontent.com/104545490/175611568-082fd94c-47f6-49a1-ae58-c721443c2696.png)

### 5. Dividing the datat into training and testing purpose 

![image](https://user-images.githubusercontent.com/104545490/175612082-0e9d2ed1-5981-47fd-b79c-a9e11b9dcafd.png)

### 6. Applying the algorithm

![image](https://user-images.githubusercontent.com/104545490/175612183-d3d430e8-c875-41b1-a9a7-ec140f8e11e1.png)

### 7. Predicted values after testing datat

![image](https://user-images.githubusercontent.com/104545490/175612386-80b850cd-a4a9-46db-b977-4bcc0fe9d64e.png)





 

    

 
                          
