inherit ROOM;

void create()
{
        set("short", "���ŷ�");
        set("long", @LONG
���������������ϲ���Դ�����ę́������������Ҷ�����֮�Ҿƣ����Կ���
����֮��ţ��ĵ�壬��������ʳ����ϲ���⣬�Ӳ����ڣ�ż������������Ҳ�Ը���
����ĳ�����ŪЩ�ɽ������㣬��κ��Ļ�з�������Ķ�Ϻ�����ϵĴ����ȵȣ���
���ſڵ�һ�ڴ�ˮ�������Щ���Ӷ������ϵر���һ������������Ц�Դ˴���
������Ψһ���������ŷ���
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"northstrt",
	]));
        set("resource/water", 1);
	set("liquid/container", "ˮ��");  
        set("objects", ([
               __DIR__"npc/cooker" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
