// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
�����ˮ����Ȼƽ�ȣ�ֻ�ǹ���������࣬�������ɵ�������һ�������߿�
����ǻ������һƬ����Ӱ���ƺ���ʲô���ƶ�������������Ϣ�ļž���û�в��Σ�
û�����㣬���Ȼ�����������������
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"midsea",
        	"down":	__DIR__"botsea",
    	]) );
    	set("objects",([
        	__DIR__"npc/octopus":	1,
    	]) );
    	set("no_fly", 1);
		set("coor/x",-10);
		set("coor/y",-30);
		set("coor/z",-80);
		set("no_fly",1);
		set("underwater",100);
		set("water_damage",20);
	   	setup();
}

void init()
{
	object octopus;
	if(userp(this_player())){
		this_player()->apply_condition("underwater",10);
		add_action("do_dive", "dive");
		remove_call_out("attack");
		octopus=present("octopus",this_object());
		if (objectp(octopus))
		{
			message_vision(BLU"�谵��ˮ����������һ���޴����Ӱ��������$N�ƽ�����\n\n"NOR,this_player());		
			call_out("attack",1+random(2),this_player(),0);
		}
	}
}


int attack(object me, int count)
{
	object octopus;
	
	if (environment(me)!= this_object())	return 1;
	
	octopus=present("octopus",this_object());
	
//	tell_object(me,"here i am"+ octopus->name()+ " hit you " + count +"\n");
	
	if (!objectp(octopus))	return 1;
	
	if (octopus->is_fighting())	return	1;
		
	
	COMBAT_D->do_attack(octopus,me);

	count++;
	if (count<40)		
		call_out("attack",1+random(2),me,count );
	else
	{
		message_vision(WHT"\n\n�������Ȼ��ʧ������������Ϥ���Ǹ���������Ӱ��
		
��Ů�����������Ц��Ц������Ǳȥ����ʧ��ε���ĺ�ˮ���\n\n"NOR, me);
		destruct(octopus);
	}
	return 1;	
}


int do_dive(){
	object me, obj, room,octopus;
	me = this_player();
	obj = me->query_temp("armor/mask");
	
	if (octopus=present("octopus",this_object()))
		return notify_fail("�������צ���ɣ���ס�����ȥ·��\n");
	
	room = find_object(__DIR__"botsea");
	        if(!objectp(room)){
	            room = load_object(__DIR__"botsea");
	        }
	
	if (room->query("underwater") <= me->query_skill("swimming",1)) {
		message_vision("$N��������Ǳȥ��\n", me);
		if (room->usr_in()) {
			tell_object(me,"����������ˣ�Ǳ����ȥҮ��\n");
			return 1;
		}  else 
			room->reset();
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
