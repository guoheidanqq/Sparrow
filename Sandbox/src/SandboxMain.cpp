namespace Sparrow {
	__declspec(dllimport) void sayhello();

}


int main() {
	Sparrow::sayhello();
	return 0;
}