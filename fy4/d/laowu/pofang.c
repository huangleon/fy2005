
inherit ROOM;

void create()
{
        set("short", "�Ʒ���");
        set("long", @LONG
һ�䶫�������С�ݣ��������������õ��ư�ʣ����ϵ�ϲ��д���������ſ���
���ſ�����˳�ۣ�ǽ�����ŵĲ���ү���õ�����һ����������
LONG
        );
	set("exits", ([ 
		"west" : __DIR__"inn",
	]));
	set("objects", ([
		"/obj/npc/xiaotong" : 2,
		 __DIR__"npc/kiddo" : 1,

	]) );
	set("coor/x",25);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

