// seaside.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ת��һ���䣬����ǰ��Ȼһ���ޱ��޼ʵĴ󺣾�����ǰ�ˡ�������棬һϴ
�����ÿ͵�һ·�Ͷ١��������������е���ζ�������ĺ�ˮ�Ͻ�׵��˻���������
������ı������ƴ�����һ�����˵���ɴ��
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"searoad1",
		"north" : __DIR__"village",
	]));
        set("outdoors", "tieflag");

	set("coor/x",1000);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}


