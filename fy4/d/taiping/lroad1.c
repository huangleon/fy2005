inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
������ɽ��������ʯ���ɵ�·��С���ݺᣬ����ҹɫ�У���ֱ����ͼҲ�ơ�
ɽ��Ặ��ʯ��������Է���⡣ˮ��ңͨ���룬ֻ�����ڵ������ƺ��Ӳ����ϣ���
���ǿ�֦��Ҷ����ɪ�����ң�����ıܽ��ڰ��
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"lroad2",
		"east": __DIR__"yuanzi",
		"west": __DIR__"pond",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([
		    
	]));
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();
	replace_program(ROOM);
}
