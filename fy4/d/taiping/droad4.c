inherit ROOM;
#include <ansi.h>
int blinding(object me);
int bbqthem(object me, object obj);

void create()
{
        set("short", "С�ﾡͷ");
        set("long", @LONG
С��û��Զ�͵��˾�ͷ��һյ�Ұ�����ƹ���ǽ�ϣ��紵�����۵��죬�ƺ�ʱ
�̶���Ϩ��������Ȼ�ǰ���ɫ�ĸ�ǽ����Ȼû�д��ӣ�Ҳû��������������һ̲
��ˮ��������Ҷ������������Ա߻���һ��ƽ�峵��
LONG
        );
        set("exits", ([ 
		"southwest": __DIR__"droad3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
 
	]));
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init()
{
        add_action("do_look","look");

}

int do_look(string arg)
{
        object oldworm;
    	oldworm=present("oldworm",this_object());
    	
    	if (arg == "���" || arg=="ƽ�峵" || arg =="cart" || arg=="bag"){
  		if (oldworm && !userp(oldworm)) {
  			tell_object(this_player(),"�Ĺ����ҵ�ʪ�����װ���˷�ù�����ӣ��Ա�ͣ��������ŤŤ��ƽ�峵��\n");
  			tell_object(this_player(),HIR"����ϸһ����ƽ�峵�Ͼ�Ȼ������ʬ�壡�����µ�ʬ�壡\n"NOR);
  			message_vision(CYN"\n\n$N��Цһ������������·�㲻�ߣ�����������ƫҪ������Ҳ���°ɡ���\n\n"NOR,oldworm);
  			oldworm->kill_ob(this_player());
  			this_player()->kill_ob(oldworm);
  		} else 
  			tell_object(this_player(),"�Ĺ����ҵ�ʪ�����װ���˷�ù�����ӣ��Ա�ͣ��������ŤŤ��ƽ�峵��\n");  	
		return 1;
	}
    	return 0;
}


	
int blinding(object ob) {
	object *enemy;
	enemy=ob->query_enemy();
	if (!enemy || sizeof(enemy)<1)	return 1;
	message_vision(HIW"\n$N��Ȼһ���ֶ���һ��ʯ�ң��׷۷�ɢ������һ����ʱ������������������֮�С�\n"NOR,ob);
	foreach (object x in enemy) {
		if (x->query_temp("block_msg/all")) continue;
		bbqthem(ob,x);
	}
	return 1;
}

int bbqthem(object me, object enemy) 
{
	if(enemy->query("combat_exp")>random(me->query("combat_exp")*5))
        {
        	message_vision(HIB"$N��æת��ͷȥ���ܿ��׷ۡ�\n"NOR,enemy);
        	return 1;
        }
	tell_object(enemy,HIW"��ֻ������ǰ��ãã��һƬ��ʲô���������ˡ�����\n"NOR);
	enemy->add_temp("block_msg/all",1);
	message_vision(CYN"$Nʹ�����ס�۾���ֱ�ڵ��ϴ����\n"NOR,enemy);
	call_out ("recover",10, enemy);
	return 1;
}


int recover (object obj){
	if (!obj)	return 1;
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"���������ģ�����۾���ʼ���Էֱ���Χ�������ˡ�\n" NOR);
	return 1;
}	
