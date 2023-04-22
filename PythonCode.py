import serial
import time
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

#Modify the Path According to where you save the Given Dataset
data=pd.read_csv('--PATH--/vitals_data.csv')
# Split the data into features and target label
X = data.iloc[:, :-1]  # Features are all but the last column
y = data.iloc[:, -1]   # Target label is the last column

# Convert the string labels to numerical values using a dictionary
#Positive - Vitals are Unstable
#Negative - Vitals are Stable
label_map = {'Positive': 1, 'Negative': 0}
y = y.map(label_map)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Define and train the decision tree classifier
clf = DecisionTreeClassifier(random_state=42, max_depth=5)  # Limit the depth of the tree to 2
clf.fit(X_train, y_train)

# Predict the labels of the test set
y_pred = clf.predict(X_test)

# Calculate the accuracy of the model
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy*100)


#Serial Connection with Arduino UNO on Port COM5
#NOTE:It may vary
ser = serial.Serial('COM5', 9600)

while True:
    data = ser.readline().decode().strip() 
    #Parse the temperature, oxygen level and heart rate values
    if data.startswith('T:'):
        temperature = float(data.split(',')[0].split(':')[1]) 
        Oxygen = int(data.split(',')[1].split(':')[1])
        heart_rate = int(data.split(',')[2].split(':')[1])
        temperature_f = (temperature * 9/5) + 32
        Test=pd.DataFrame({'Temperature': [temperature_f], 'PulseRate': [heart_rate], 'Oxygen': [Oxygen]})
        print(Test)
        #Predict the Output using the ML Model
        label=clf.predict(Test)
        # Send commands to Arduino based on temperature readings
        if label[0]==1:
            print("Condition: Hypothermia")
            ser.write(b'1')  # turn on LED on Arduino
            time.sleep(0.5)  # wait for half a second
            ser.write(b'0')  # turn off LED on Arduino
        else:
            print("Vitals are Stable")
    time.sleep(2) # wait for 1 second before taking another reading
