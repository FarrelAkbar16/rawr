import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score

# Load dataset
data = pd.read_csv('tabel_keputusan.csv')

# Pisahkan fitur dan label
X = data.drop('Keputusan', axis=1)
y = data['Keputusan']

# Bagi dataset menjadi data latih dan data uji
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Inisialisasi dan latih model Decision Tree
model = DecisionTreeClassifier()
model.fit(X_train, y_train)

# Lakukan prediksi
y_pred = model.predict(X_test)

# Evaluasi kinerja model
accuracy = accuracy_score(y_test, y_pred)
print("Akurasi model:", accuracy)

# Gunakan model untuk membuat prediksi
new_instance = pd.DataFrame([[5,2,3,1,3]], columns=['kolom 1','kolom 2', 'kolom 3','kolom 4','kolom 5'])  # Contoh instance baru
prediction = model.predict(new_instance)
print("Prediksi:", prediction)
