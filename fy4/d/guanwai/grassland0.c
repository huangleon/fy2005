inherit ROOM;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��������
������Ⱥ����������Ʈ���Ķ����ơ�Զ���Ĳ��������ڽ����¿������紿������
��Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ���û�뵽��������ı���֮�ؾ��������
��ĵط������ûԻͶ����أ����������Ի��������˶����ˡ�
LONG);

        set("exits", ([ 
		"east" : "/d/quicksand/mroad2",
		"west" : __DIR__"grassland1",
	]));
        set("objects", ([
                __DIR__"npc/skylark" : 1,
        ]) );
        set("outdoors", "guanwai");
	set("coor/x",90);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
