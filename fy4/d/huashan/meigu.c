#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ĺ�");
        set("long", @LONG
�˴�ֱ�����ƣ��������̣�����������ţ���������΢�ĳ���֮����������
������Ŀ�ɼ���÷�౾�����ư���֮��֦���������ô������ҡҷ����׺��
���Եø�����̣���ɫ���ס�
LONG
        );
    set("exits", ([ 
		"southwest" : __DIR__"yinxing",
	]));
	set("meishan", 1);
    set("outdoors", "huashan");
	set("coor/x",-1);
	set("coor/y",-48);
	set("coor/z",30);
    	set("objects", ([
		__DIR__"npc/lie" : 1,
	]));   
    
    
	setup();

}

/*
void init(){
	int i;
	object me;
	me = this_player();
	i = NATURE_D->get_season();
	if (i == 4) {
		call_out("do_winter", 1, me);
	}
}

int do_winter(object me) {
	object mei;
	string weather;
	if(interactive(me) && environment(me) != this_object()){
		return 1;
	}
	if (present("li e", this_object()))	return 1;
	if (present("wen shi", this_object()))	return 1;
	if (query("mei_out")) return 1;
			
	message_vision(HIY"\nһ��÷��Ʈ�����������ģ�������Ƣ��ǽ��塣\n"NOR, me);
//	weather = NATURE_D->get_weather();
//	if((weather == "ѩ" || weather == "��ѩ")&& NATURE_D->is_day_time() 
//			&& !present("wen shi", this_object())) {
		tell_object(me, "÷����ƺ���һ��Ӱ��\n");
		mei = new(__DIR__"npc/meishan");
		mei->move(this_object());
		set("mei_out",1);
//	}
}


void reset()
{

::reset();
if(query("mei_out") && random(4)) set("mei_out",1);
        else set("mei_out",0);
        
} 
*/