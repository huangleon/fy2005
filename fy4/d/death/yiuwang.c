// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ﲻ��Ѫ�ȣ�Ҳ���ź���������ķ���ȫ����������Ѻ������������������
֮���޷���̸��һ�ؾ�����ʮ�꣬������������������ˣ��಻�������һƬ��
����Ϊ���£���֮�����������˿־塣��һ��Ļ������������
LONG
        );
        set("exits", ([
		"up" : __DIR__"diaojin",
		"down" : __DIR__"huokeng",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-20);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
