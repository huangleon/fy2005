// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ѿ���");
        set("long", @LONG
�����ƺ��Ͱ�Ƥ����࣬��������ķ�����Ƥ��͹�ͷ���룬�ѻ��˱�Ϊ��
�ã�Ȼ���ٰ�Ƥ������ȥ��ѭ�����������ʹ��ʵ�����Եֵ�����������������
�Ժ���а�������Ӵ˳�Ϊ����֮ͽ���㿴���˲���������ʶ����ס������»���
ʲô�أ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"hanbing",
		"down" : __DIR__"chouchang",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-110);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
