
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�ȹ�����������С�ţ���һ��С�ò�����С�ĳ��������濿ǽ����һ��
��ˮ�׺ͼ�ֻ��̳����������һ����¯�ӣ����յ�������һ���ϸ��˼����м�����
������ 
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xzhouse1",
	]));
        set("objects", ([
                __DIR__"npc/oldwoman" : 1,
        ]) );
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}
