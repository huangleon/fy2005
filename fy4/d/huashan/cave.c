#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ëŮ��");
        set("long", @LONG
ëŮ����˵��ëŮ����������ëŮΪ��ʼ�ʹ�Ů�������ɽѳ��֮�֣���
�����ع��۷���Я���뻪ɽ����ҵ����ʿָ�㣬��ʳ�ɰ��ѣ�������Ȫˮ����ʹ
������ë���в���ɡ���˵ɽ����ʦ���������˿�������������ҹ���˾�ʱ����
Ȼ��������ëŮ���������ߵ�������
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"shaluo",
	]));
	set("listen", 0);
	set("music", 0);
    set("indoors", "huashan");
	set("coor/x",-10);
	set("coor/y",-5);
	set("coor/z",10);
	setup();
}

void init(){
    mixed *local;
    int dayTime;

/*  if(!NATURE_D->is_day_time()){
		local = NATURE_D->get_current_time();
		dayTime = local[5];
    	 if(dayTime > 1200 && NATURE_D->get_weather() == "��") {
    		call_out("make_sound", 20, this_player());
    	}
    }*/
    
	add_action("do_listen", "listen");
}


void init_scenery()
{
        call_out("make_sound",1);
}


int make_sound(){
		tell_room(this_object(),CYN"һ�����Ƶ�������֪�Ӻδ�������������������������������ҳ���������Դ��\n"NOR); 	
		call_out("music_gone", 30);
		set("listen", 1);
}

void music_gone(){
	set("listen", 0);
}

int do_listen(){
	object me;
	me = this_player();
	if(query("listen")){
		message_vision("\n��Զ��������ҹɫ���������ߣ���ѭ��������ϸѰ�ң����������ƺ��Ӷ���������\n",
				me); 
		me->apply_condition("music", random(10));
		return 1;
	}	
	tell_object(me,"����������������������ֻ����Ľ�����������\n");
	return 1;
}
