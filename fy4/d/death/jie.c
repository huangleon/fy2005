// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ����˾");
        set("long", @LONG
�Թ���������Ů������������أ�����Ů�ӣ��������ջ�������ѣ����ǵ�
����ʬ֮�ࡣ��˾���Ծ������Ů�ӵĻ��񣬻����д�ӵ��һλŮ�Ӷ������ϣ���
�ǽ�˾���ƹ�--���飬��������Ϊʯ����檣��������������ˣ�����¥����������
֮��������ǧ�š������â֮�У����ܷ�ʬ֮�̵�����ŮŮ����Ϊ��ª��
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/greengirl":1,
        ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
 
