#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
��һ��·����ƽ��������ɽ�Ͱεض���С·��ɽ��ȵ��̻����У�С·����
��ľï�ܣ��㲻ʱ�������ϻ�ȸ�ö��Ľ�����һ��СϪ������С·��һ�໺����
��ȥ��Ϫˮ�峺���ס�������һƬï�ܵ����֡�
LONG
        );
    	set("exits", ([ 
  		"westup" : __DIR__"canglong",
	    "eastup" : __DIR__"xiaodao1",
		"north" : __DIR__"milin",
	]));
    	set("objects", ([
		__DIR__"npc/woodcutter2" : 1,
    		__DIR__"npc/yellowbird" : 1,
    	]));
    	set("outdoors", "huashan");

	set("coor/x",-8);
	set("coor/y",-50);
	set("coor/z",27);
	setup();
}

void init(){
	if (REWARD_D->riddle_check( this_player(),"��ȸ����") == 1
		 && NATURE_D->is_day_time() 
		 && NATURE_D->get_weather() == "��") {
		tell_object(this_player(),YEL"���к�Ȼ����������֮����������\n\n"NOR);
		call_out("bird_come", 2, this_player());
	}
}


void bird_come(object me){
	object obj;
	int i;
	
	if(!interactive(me) || environment(me) != this_object()){
		return;
	}
	obj = new("/obj/medicine/pill_zhuguo");
	i = NATURE_D->get_season();
	if(objectp(obj) && (i == 3 || i == 4)){
		message_vision("\nһֻС��ȸ������$N����������һ�����ɫ�Ĺ��ӡ�\n", me);
		message_vision("���ɫ�Ĺ������£��պ�����$N���С�С��ȸչ��߷ɳ���������\n", me);
		if (!obj->move(me))
			obj->move(environment(me));
	} else {
		obj = new("obj/medicine/pill_yihua");
		message_vision("\nһֻС��ȸΧ����$Nͷ�����˼�Ȧ������䵽$N���\n", me);
		message_vision("һ��С����С��ȸ�������£�����$N���С�С��ȸ��������չ���ȥ��\n", me);
		if (!obj->move(me))
			obj->move(environment(me));
	}
	REWARD_D->riddle_done( me, "��ȸ����", 10, 1);
}
