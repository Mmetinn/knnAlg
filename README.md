# knnAlg
## Açıklama
##### Sınıflandırmada (classification) kullanılan bu algoritmaya göre sınıflandırma sırasında çıkarılan özelliklerden (feature extraction), sınıflandırılmak istenen yeni bireyin daha önceki bireylerden k tanesine yakınlığına bakılmasıdır.

##### Örneğin k = 3 için yeni bir eleman sınıflandırılmak istensin. bu durumda eski sınıflandırılmış elemanlardan en yakın 3 tanesi alınır. Bu elamanlar hangi sınıfa dahilse, yeni eleman da o sınıfa dahil edilir. Mesafe hesabından genelde öklit mesafesi (euclid distance) kullanılabilir.

##### Bu algoritma [İris Dataset](http://archive.ics.uci.edu/ml/datasets/Iris?ref=datanews.io/) işlemektedir bu dataya verilen linkten ulaşabilirsiniz. Öncelikle iris datasını eğitim ve test datası olacak şekilde ayırın ardından bu dataları birer txt dosyasına atıp dosya pathini kod içrisinde uygun yere yazıp verileri kodun okumasını sağlaynızsepal length in cm ve sepal width in cm değerlerine göre de kodun içerisinde görselleştirme ve tablolama işlemleri yapılmıştır.Uygulamayı çalıştırabilmek için öncelikle qt creator indirip kurmanız gerekmektedir.
