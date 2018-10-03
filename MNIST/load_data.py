from keras.datasets import mnist
(train_features, train_labels), (test_features, test_labels) = mnist.load_data()

print(train_features.shape)
print(train_labels.shape)
print(test_features.shape)
print(test_labels.shape)
