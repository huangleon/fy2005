
inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��������
������Ⱥ����������Ʈ���Ķ����ơ�Զ���Ĳ��������ڽ����¿������紿������
��Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ���û�뵽��������ı���֮�ؾ��������
��ĵط������ûԻͶ����أ����������Ի��������˶����ˡ�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"deadneck",
        "north" : __DIR__"drugshop",
        "south" : __DIR__"weaponshop",
		  "east" : __DIR__"grassland2",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/sheepgirl" : 3,
                __DIR__"npc/sheepdog" : 1,
		__DIR__"npc/sheep3" : 5,
        ]) );
	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
