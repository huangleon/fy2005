// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;

int room_check(object room);

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
ˮ��ƽ������࣬�����ˮ�ʰ�͸����ε��ɫ�����˺�������ˮ���϶�������
���龰��ˮ��������������������ʱ�ι���С���������Բ���������ƺ������
�����޶����ԡ�
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"yadi",
        	"down":	__DIR__"botsea",
    	]) );
    	set("objects",([
        	__DIR__"npc/jiaonv":	1,
    	]) );
    	set("no_fly", 1);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-70);
	set("underwater",100);
	set("water_damage",20);
    	setup();
}


void init(){
    	
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
    	add_action("do_dive", "dive");
    	add_action("do_smile","smile");
}


int do_dive(){
	object me, obj, room, octopus, jiaonv;
	
	me = this_player();
	obj = me->query_temp("armor/mask");
	
	if (jiaonv = present("jiao nu",this_object()))
		return notify_fail("��Ů��ˮ�г��Σ���ס�����ȥ·��\n");
	
	room = find_object(__DIR__"midsea2");
	        if(!objectp(room)){
	            room = load_object(__DIR__"midsea2");
	        }
	
	if (room->query("underwater") <= me->query_skill("swimming",1)) {
		message_vision("$N��������Ǳȥ��\n", me);
		if (room->usr_in()) {
			tell_object(me,"����������ˣ�Ǳ����ȥҮ��\n");
			return 1;
		}  else 
			{
				if (objectp(octopus=present("octopus", room)))
					destruct(octopus);
				room->reset();
			}
		me->move(room);
	        this_object()->reset();
	        message("vision", me->name() + "Ǳ������ߵ�ˮ�С�\n", environment(me), me);
	} else {
	    	return notify_fail("�����Ӿ����̫�û��Ǳ��ȥѽ��\n");
    	}
    	return 1;
}

int valid_leave(object me,string dir){
    	
    	if (dir=="down"){
    		tell_object(me,"ˮ���ļ������ʹ��Ǳ�������壩��ȥ���С�\n");
    		return notify_fail("");
    	}
    	return 1;
}

int do_smile()
{
	object jiaonv;
		
	add("num",1);
	if(!((int) query("num") % 5))
	if(objectp(jiaonv= present("jiao nu", this_object())))
	{
		message_vision(WHT"\n$n�ع�ͷ����$NЦЦ���������֣�һת��Ǳ�뺣ˮ�в����ˡ�\n\n"NOR,
			this_player(), jiaonv);
		this_player()->set_temp("riddle/�̺�����/����һЦ",1);
		destruct(jiaonv);
		return 1;
	}
		return 0;
		
}