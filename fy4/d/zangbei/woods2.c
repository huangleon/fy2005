inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
���ֲ���Ũ�ܣ�����������Ҷ��ƬƬ���ϣ������]��б���ģ��������f����
�ˡ���Ƥ�⻬�����yɫ����Ȧ��΢΢��������ɫ���ּ䱾û��·���ߵ��˶��ˣ���
̤��һ���ϱ����С����վ�����������������Զ��������ľ�˵�ߺ�ȡ�������
���ߣ��������𽥱���֪���Ĵ��������棬�˼�����ϡ�١�
LONG
        );
        set("exits", ([ 
		"south": __DIR__"woods3",
		"west" : __DIR__"linchang2",
		"east":	__DIR__"forest1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1620);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
