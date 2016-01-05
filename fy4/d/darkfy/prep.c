#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ڷ������");
        set("long", @LONG
׼������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"up" : __DIR__"fysquare",
  			"down":	"/d/wiz/demoroom",
		]));
        set("objects", ([
        ]) );

        set("coor/x",-40);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
}

void init()
{
 	add_action("do_mutate", "mutate");
 	add_action("do_setname", "setname");
}

/*
dark_assassin = ([
		"name":			"����"
		"exp":			1000000,
		"class":		({"assassin"}),
		"killed":			0,
		"total_killed":		0
		"PK":				0,
	])
*/


		
string add_class(string arg){
	object me = this_player();
	me->set("dark_assassin/class", me->query("dark_assassin/class")+ ({arg}));
	return me->query("dark_assassin/class");
}
	
int do_mutate(string arg){

	mapping ass_data;
	string myclass, *e_class = ({	"assassin","lama","shenshui"});
	mapping c_class = ([
			 "assassin":"��Ǯ",
			 "lama":	"����",
			 "shenshui":"��ˮ",
	]);
	int n, num, i;
   	object me, obj, girl, oe;
   	int gin, kee, sen, duration;
   				
	me = this_player();

   	if (me->is_busy()) {
   		tell_object(me,"��������æ��\n");
   		return 1;
   	}
   	
	if (F_LEVEL->get_level(me->query("combat_exp"))<20){
    	tell_object(me,"�㹦����ô���������ȥ��������������ȼ�20��\n");
    	return 1;
    }
       
/*  duration = me->query("timer/cyan_dreamland") + 1200 - time();
    if (duration>0){
    	tell_object(me,"��������������ٵ�" + (duration/60) + "���Ӱɡ�\n");
    	return 1;
    }*/
 
	ass_data = me->query("dark_assassin");

	if (!ass_data || ass_data["name"] == "����")	{
		tell_object(me,"������setnameָ����Ϊ���Լ�ȡ�������������ֽ���Ϊ�������ڵĴ��ţ�һ��ȷ���������ܸ��ġ�\n");
		return 1;
	}
		
	num = sizeof(ass_data["class"]);
	if (!num)
		ass_data["class"] = ({"assassin"});
	
	tell_object(me, ass_data["name"]+"�����Ѿ����յ���������Ϊ��\n");
	for (i=0;i<num;i++){
		tell_object(me, sprintf("%-10d��%10s\n",i+1,c_class[ass_data["class"][i]]));
	}
	
	if (!arg || sscanf(arg,"%d",n)!=1){
		tell_object(me,"\n��ʽΪ	mutate n	����nΪ���ӵ�е����ɴ��š�\n");
		return 1;
	}
	
	if (n<1 || n>num+1)	{
		tell_object(me,"��ʽΪ	mutate n	����nΪ���ӵ�е����ɴ��š�\n");
		return 1;
	}
	
	myclass = ass_data["class"][n-1];
	
	obj = this_object();
    message_vision("$N�����ۡ������Ƿ���ɵ��˲ݵ��ϣ�", me);
	tell_object(me, "�ܿ���;���˯�����ʡ�\n");
	message("vision", me->name()+"���˼������ҵ������ʵ����ƣ��ܿ�ͽ��������硣\n", environment(me), me);

	myclass = __DIR__"player/"+myclass+"_player";

	tell_object(me,"your class is "+ myclass + "\n");
//	return 1;
	
 	oe=new(myclass);
 	if (!oe)	{
 		tell_object(me,"ERROR darkfy 79832, please inform wizard.\n");
 		return 1;
 	}
 	
	oe->move(obj);
		
	oe->set_temp("block_msg/all",1);
	LOGIN_D->enter_world(me, oe, 1);

	if (present("cloth",oe))
		destruct(present("cloth",oe));
	
	"/feature/nada.c"->reset_player_status(oe);
	oe->full_me();

	oe->set_temp("block_msg/all",0);
	oe->set_temp("no_disconnect_during_idle",1);
	me->set_temp("no_disconnect_during_idle",1);

   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
   	me->delete_temp("is_unconcious");
	me->move(this_object());
   	tell_object(oe, CYN"���Ժ��������ƾ����������ھ��ߴ��������������۾�������\n"NOR);

	return 1;
}
