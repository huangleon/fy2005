inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ش���");
        set("long", @LONG
���Ǽ伫��ķ��ӣ����������ʽ������ҩ�ݣ�ռ��������ʮ֮��������
��������ʮ���߻�¯��¯��㶼�յ�������¯�������ŵ��е���ͭ�����е���������
���е������ι�״��˵�������Ե���ͭ����ÿһ��ͭ���У�����һ����Ũ�ҵ�ҩ��
������
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"groad4",
	"north" : __DIR__"chunliuju2",
	]));
        set("objects", ([
        	__DIR__"npc/chunliu":1,
	]) );
        set("valid_startroom", 1);
		set("chunliu",1);
        set("coor/x",90);
        set("coor/y",100);
        set("coor/z",0);
	set("map","eren");
	setup();
}



int do_recover(object me, int count){
	
	if (!me || !objectp(me) || me->is_ghost())
		return 0;
	
	if (!environment(me)->query("chunliu")) {
		tell_object(me,RED"��������Ѫ��ӿ����ʱ���˹�ȥ��\n"NOR);
		me->delete("marks/eren/in_cure");
		me->unconcious();
		return 1;
	}
	
	count++;
	
	if (count >= 5)  {
		me->delete("marks/eren/in_cure");
		tell_object(me,YEL"����������ں��ˡ�\n"NOR);
		me->full_me();
		return 1;
	}
	
	if (count)
		tell_object(me,MAG"������˿�����������������Լ���\n"NOR);
	call_out("do_recover",10+random(5), me, count);
	return 1;
}