inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ƫ��");
        set("long", @LONG
��ƫ����¥�Ͼ������Ⱥ�����ң��������һ��������ʮ���죬һ���ʮ��С
ʱ���˵�ֵ��������������ģ��������Ⱥ�ĵմ����ӣ����Ǹ�����������������
�������������ܹܹ���ϣ�����������������ҲҪͨ���˲�����¥��
LONG
        );
        set("exits", ([ 
		"up": __DIR__"corridor3",
		"east": __DIR__"hall4",
	]));
        set("objects", ([
        	__DIR__"npc/vguard2":	1,
        	__DIR__"npc/vguard3":	1,
	]) );
        set("coor/x",-15);
        set("coor/y",130);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
