#define VIDEO_WIDTH 	80 //???
#define VIDEO_HEIGHT 	60 //???

#define VIDEO_MEMORY	0xb8000

enum VGA_COLOR
{
	//non me li ricordo
};

int main()
{
	char* video_memory = (char *) VIDEO_MEMORY;
	
	//*video_memory = 'G';
	
	return 0;
}
