// 1 vai ham dung khi di thi

//1. dem so lan xuat hien trong mang 1 chieu

void dem(){
	for(int i=0;i<n;i++){
		int count=1;
		if(b[i]){
			b[i]=0;
		
		for(int j=1+i;j<n;j++){
			if(a[i]==a[j]){
				count++;
				b[j]=0;
			}
		}
		printf("%5d\t\t%5d", a[i],count);
	}
}
}

//2. dem so tu  va chuan hoa chuoi

int WordCount(char str[], int length)
{
    int word = (str[0] != ' ');
    for (int i = 0; i < length - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            word++;
        }
    }
    return word;
}
 
void Correct(char str[], int length)
{
    int first = 0, last = length - 1;
    // Xóa d?u tr?ng d?u chu?i
    while (first < last && str[first] == ' ')
        first++;
    // Xóa d?u tr?ng cu?i chu?i
    while (last > first && str[last] == ' ')
        last--;
 
    // Vi?t hoa ch? cái d?u tiên
    if (str[first] >= 'a' && str[first] <= 'z')
        str[first] -= 32;
    for (int i = first + 1; i <= last; i++)
    {
        // Ðua h?t v? ch? thu?ng
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
        if (i + 1 <= last)
        {
            // B? d?u tr?ng th?a ? gi?a
            if (str[i] == str[i + 1] && str[i] == ' ')
            {
                continue;
            }
            // N?u là ch? cái d?u m?i t? thì vi?t hoa
            if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            {
                str[i + 1] -= 32;
            }
        }
        printf("%c", str[i]);
    }
}
 
int main()
{
    char str[100];
    // Nh?p chu?i
    printf("\nNhap chuoi: ");
    fgets(str, sizeof str, stdin);
    // Do s? d?ng fgets nên chu?i c?a chúng ta s? d?c c? ký t? '\n'.
    // Xóa b? nó di.
    int length = strlen(str) - 1; 
    str[length] = '\0';
    printf("So tu cua \"%s\" la %d", str, WordCount(str, length));
    printf("\nXau chuan hoa la: ");
    Correct(str, length);
}

//3. Dem so tu khac nhau  trong chuoi
int cmp(const void*a, const void*b){
	char* x =(char*)a;
	char* y=(char*)b;
	return strcmp(x,y);
}
int main(){
	char c[100001];
	gets(c);
	char a[10000][20];
	char b[10000][20];
	int n=0;m=0;
	char *token= strtok(c, " ");
	while(token != NULL){
		int check=1;
		for(int j=0;j<n;j++){
			if(strcmp(token,a[j])==0){
				check=0;
				break;
			}
		}
		if(check){
			strcpy(a[n], token);
			strcpy(b[n],token);
			
			}
		}
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i++){
		printf("&s", a[i]);
	}
}
//4.
