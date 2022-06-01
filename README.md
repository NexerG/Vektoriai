# Vektoriai

### Funkcijos:<br>
- operator= vektoriui priskiria kito vektoriaus vertes
- PushBack į vektoriaus galą idėda naują elementą
- operatorius[] prieeiga pagal indeksą
- Size grąžina kiek vektorius yra užpildytas
- Capacity grąžina kiek vektorius gali būti užpildytas
- assign priskiria elementam vertę
- front grąžina pirmą elementą
- back grąžina paskutinį elementą
- data rodyklė į konteinerį
- reserve padidina vektoriaus talpa
- empty patikrina ar vektorius tuščias
- popback išima paskutinį elementą
- clear ištuština konteinerį
- begin grąžina iteratorių pirmam elementui
- end grąžina iteratorių paskutiniam elementui

| custom vector| std vector | kiekis(int) |
|--------|--------|-------|
| 0ms | 3ms | 10 000|
| 2ms | 29ms | 100 000|
| 17ms | 216ms | 1 000 000|
| 184ms | 2203ms | 10 000 000|
