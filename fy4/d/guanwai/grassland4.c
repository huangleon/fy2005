
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
		"west" : __DIR__"citygate",
		"east" : __DIR__"deadneck",
	]));
        set("outdoors", "guanwai");

	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}