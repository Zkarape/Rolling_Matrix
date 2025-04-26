# Coursework Project: Rolling Matrix Animation with Win32
# The Dance of the Matrix

In this project, I use Win32 to create a rolling matrix animation in the console.

To animate the movement of each matrix element based on its indices, I derived two key formulas:

For moving right: m + n - i - j - 2

For moving up/down: m - n - i + j

The work_right function, which rolls the matrix to the right, works correctly for matrices where n == 2.
I also started implementing work_left, which scrolls the matrix back to the left, but it is not yet complete.

Matrix Rotation Logic
To correctly rotate the matrix, I needed to retain the original values of the matrix elements after the first rotation.
Since I erase and reprint elements during the animation, simply moving them would cause the original data to be lost.
To solve this, I designed a structure that stores:

The indices of each element

The value of the element

I then created a 2D array of these structures (n * m), ensuring that each element has its own independent copy of its value and indices.

Rotation Stages
The rotation is divided into four stages.
At each stage:

The indices and values inside each structure are updated according to the current matrix shape.

The value for each structure is fetched from the original matrix based on a consistent rule:

In the first stage, the element at indices (0, n-1) is moved first.

Next, the element at (1, n-1) is moved, and so on.

However, the indices inside the structures are updated differently:

After each stage, the matrix dimensions may swap (e.g., from n * m to m * n).

Additionally, the logical position of elements changes (e.g., the (0,0) element may move to (0, m-1)).

This updating continues across all four stages.

Movement Formulas
The core of the animation relies on formulas I derived, based on the indices of the elements:

Horizontal movement (right):
The number of "steps" (or empty slots) an element moves is calculated as:

text
Copy
Edit
m + n - i - j - 2
Vertical movement (down or up):
The number of vertical steps is calculated as:

text
Copy
Edit
m - n - i + j
When moving up, the value becomes negative, indicating a decrease in the element's y coordinate.

I printed and captured the maximum coordinates that numbers could reach, and the animation cycles through the stages until all elements reach their final positions.

Summary
In short, the animation uses:

Careful tracking of original element values and positions

Stage-by-stage updates of matrix dimensions and indices

Custom movement formulas based on matrix dimensions and element indices

This approach ensures a smooth, mathematically correct rolling animation of the matrix inside a Windows console using Win32.


Խնդրի լուծման համար ինձ անհրաժեշտ էր ունենալ առաջին պտույտից հետո ստացված մատրիցի տարրերի տվյալները, քանի որ ես ջնջում ապա տպում եմ տվյալ տարրը, կկորցնեմ սկզբում գեներացված մատրիցի տվյալները։ Այդ նպատակով կազմել եմ ստրուկտուրա, որի մեջ պահել եմ պտույտից առաջ ներկա պահին մատրիցի տարրերի ինդեքսները և արժեքը։ Ապա ստեղծել եմ n * m  չափանի վերոնշյալ ստրուկտուրա տիպի զանգված, որպեսզի ամեն տարրն ունենա իր ստրուկտուրան։ Ինչպես հասկանում ենք ունենալու ենք պտտման 4 էտապ, որոնցից յուրաքանչյուրի ժամանակ վերոնշյալ զանգվածի k-երորդ ստրուկտուրայի անդամ ինդեքսները և արժեքը փոխվում են ըստ էտապի, ընդ որում՝ արժեքը վերցվում է սկզբնական մատրիցից հետևյալ սկզբունքով․ առաջին էտապում առաջինը պետք է շարժվի 0 և n – 1, ինդեքսներն ունեցող տարրը, հետևաբար 0-երորդ ստրուկտուրայի անդամ num  փոփոխականին վերագրում եմ սկզբնական զանգվածի այդ տարրը,  երկրորդը պետք է շարժվի 1 և n – 1 ինդեքսներով տարրը, հետևաբար 1-երորդ ստրուկտուրայի համապատասխան փոփոխականը կընդունի սկզբնական զանգվածի այդ տարրի արժեքը։ Սակայն ստրուկտուրաների անդամ ինդեքսներն արժեքավորում եմ այլ կերպ։ Յուրաքանչյուր էտապի համար ինդեքսներին վերագրում եմ այն ինդեքսները, որոնք, որ կունանան տարրերը, եթե լինեն նոր ստացված մատրիցի անդամ, այսինքն առաջին էտապին հաջորդող երկրորդ էտապում մատրիցն ունի n * m չափեր m * n-ի փոխարեն, իսկ 00 տարրը արդեն 00 ինդեքսներ չունի, այլ ունի 0, m – 1 ինդեքսներ։ Այսպես շարունակ բոլոր էտապների համար։ Ամենակարևորը բանաձևերն են, ըստ որի տարրերը որոշում են, թե որքան պետք է գնան աջ, ներքև կամ վերև։ Այդ բանաձևերն ինքս եմ դուրս բերել հետևյալ սկզբունքով․ կախված ինդեքսներից ամեն տարր պետք է շարժվի աջ ապա ներքև կամ վերև հետո աջ։ Տեղաշարժի համար հաշվում եմ այն «փոսիկների» քանակը, որ տարրը պետք է «հաղթահարի»։ Աջ տեղաշարժի համար տարրը պետք է հաղթահարի m – 1 – i + n – 1 – j = m + n – I – j – 2 հատ «փոսիկ», իսկ ներքև կամ վերև m – 1 – i – (n – 1 - j) = m – n – i + j հատ, ընդ որում՝ վեր տեղաշարժի դեպքում թիվը կստացվի բացասական և տարրի y  կոորդինատը կնվազի:
	Տպել և վերցրել եմ վերջին կոորդինատը, որ թվերը կարող են ընդունել, և ցիկլով էտապները կրկնում եմ մինչև այդ կոորդինատ։


