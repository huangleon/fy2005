#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
С�ֶ�����һ�����ӣ����ֱߵ�����ס�˴�룬���ԭ���и���ľ��Χ���դ
������֪ʲôʱ���Ѿ������Ƶ�����ʯ���·����ʯ����Ұ�ݾ�������ߣ���Ȼ��
�ط�ƽʱ������������������ˣ�ĺ��Ӷ�����ԶԶ�ģ�ż���м��������õĻ�����
��ЪЪ�ţ������ֿ����߿���
LONG
        );
        set("exits", ([ 
		"west": __DIR__"mroad2",
		"east": __DIR__"droad1",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	 set("objects",([
        	__DIR__"npc/scavenger": 2,
         ])  );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init(){
	if (random(2)) {
		remove_call_out("event_msg");
		call_out("event_msg",random(5)+1);
	}
}

int event_msg() {
	message("vision",HIG"�����һ�������εĴ���ɹ���������������������\n\n"NOR,this_object());
	return 1;
}