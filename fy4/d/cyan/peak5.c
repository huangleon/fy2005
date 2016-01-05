// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "���㺣");
    set("long", "��������Ϊ�����ѵõĹȵأ�������ǻ�ʢ�ţ�����������ϰϰ�����ɷ�
������䣬����ڤڤ����ľ�������뿪�˿��ﵥ���Ļ����ֲ��������ǰ��
�̵Ļ�ľ��������������������÷�Ȼ�ɾ���ֱ����ƽ�����׻���֮�䣬����
Ƭ�̵�������
"        );
	set("objects", ([
		__DIR__"obj/pine":1,
		__DIR__"obj/hole":1,
		__DIR__"npc/you":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : __DIR__"path7",
  		"eastup" : __DIR__"path8",
  		"southup" : __DIR__"forest5",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}


void init()
{
 	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
   	object me, obj, girl;
   	int gin, kee, sen, duration;

   	me = this_player();
   	obj = this_object();

   	if (me->is_fighting()) return 1;
   	
   	if (me->is_busy()) {
   		tell_object(me,"��������æ��\n");
   		return 1;
   	}
   
   	if (this_object()->query_temp("marks/taken"))
   	{
      		tell_object(me, "�ݵ�������Ү��������\n");
      		return 1;
   	}
    
    if (F_LEVEL->get_level(me->query("combat_exp"))<20){
    	tell_object(me,"�㹦����ô���������ȥ��������������ȼ�20��\n");
    	return 1;
    }
    
    duration = me->query("timer/cyan_dreamland") + 1200 - time();
    if (duration>0){
    	tell_object(me,"��������������ٵ�" + (duration/60) + "���Ӱɡ�\n");
    	return 1;
    }
    
    me->set_leader(0);
    
	message_vision("$N�����ۡ������Ƿ���ɵ��˲ݵ��ϣ�", me);
	tell_object(me, "�ܿ���;���˯�����ʡ�\n");
	message("vision", me->name()+"���˼������ҵ������ʵ����ƣ��ܿ�ͽ��������硣\n", environment(me), me);
	obj->set_temp("marks/taken", 1);

	switch (random(3))
	  {
	  case 0:
		  gin = (int) me->query("eff_gin");
		  me->set("gin", gin);
		  break;
	  case 1:
		  kee = (int) me->query("eff_kee");
		  me->set("kee", kee);
		  break;
	  case 2:
		  sen = (int) me->query("eff_sen");
		  me->set("sen", sen);
	  }
      	me->set("timer/cyan_dreamland", time());
      	me->set_temp("disable_inputs",1);
      	me->add_temp("block_msg/all",1);
      	me->set_temp("is_unconcious",1);
      	me->set("disable_type",HIG "<˯����>"NOR);


		if (!REWARD_D->riddle_check(me,"�쳾��") 
			&& !REWARD_D->check_m_success(me,"�쳾��") 
			&& me->query("score") > 4)
		{
			obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan/peak5");
			if (!obj)
				obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan/peak5");

			call_out("wake", 10, me,obj);
			return 1;
		}

		if (REWARD_D->riddle_check(me,"�쳾��") == 1 && me->query("score") > 4)
		{
			obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan3/forest4");
			if (!obj)
				obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan3/forest4");

			call_out("waked2", 10, me,obj);
			return 1;
		}

		call_out("wakexx", 10, me,obj);

      	return 1;
}

void wakexx(object me,object obj)
{
   		object oe,oc;

		if (!me || me->is_ghost()){
			obj->set_temp("marks/taken", 0); 
			return;
		}
			
		message_vision("$N�ڲݵ��Ϸ��˸����ӣ��������۾�����������˯ȥ��\n", me); 
		if (random(4))
			call_out("wakexx", 10, me);
		else
		{
			message_vision("һֻС����������̽ͷ̽�ԣ��ƺ���͵͵������$N��\n", me); 
			call_out("wake2", 10, me);
		}
		return;		
	
	return;
}

void wake(object me,object obj)
{
   	object oe,oc;
   	
   	set_temp("marks/taken", 0); 

	if (!me)	return;
	
	me->set("NO_KILL","�����ڲ��ܹ������ˡ�\n");
		
	oe=new("/d/phoenix/npc/cyan_player");
	oe->move(obj);
		
	oe->set_temp("block_msg/all",1);
	LOGIN_D->enter_world(me, oe, 1);

	if (present("cloth",oe))
		destruct(present("cloth",oe));

	
	"/feature/nada.c"->reset_player_status(oe);
	oe->full_me();
//	"/cmds/imm/full"->main(oe);

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
	oc=new("/d/phoenix/cyan/npc/ruo");
	oc->move(obj);

	oe->move(obj);

	obj->trigger(oe);
	
//	me->move(obj);



	return;
}



void waked2(object me,object obj)
{
   	object oe,oc;

	set_temp("marks/taken", 0); 

	oe=new("/d/phoenix/npc/cyan3_player");
	oe->move(obj);
		
	oe->set_temp("block_msg/all",1);
	LOGIN_D->enter_world(me, oe, 1);

	if (present("cloth",oe))
		destruct(present("cloth",oe));

	
	"/feature/nada.c"->reset_player_status(oe);
//	"/cmds/imm/full"->main(oe);
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

	oc=new("/d/phoenix/cyan3/npc/feng");
	oc->move(obj);

	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","��ɽ���µ�ʬ��");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","��ɽ���µ�ʬ��");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","ؤ����ӵ�ʬ��");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","�������˵�ʬ��");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","������ʬ��");
	oc->set("long","����ʦ�ݹ��ϴ�ʦ���£���������Ӱ�ֵ�������ʦ�����򲢳Ʒ���˫�㡣
�����������¶��ԣ������ĵ�����Ϊ�ѽ��������������������ߴ�����֮ϯ��
Ȼ�������Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������
������ò��... ���Ѿ����ˣ�����ʲô�ÿ��ģ�\n\n");
	oc->move(obj);

	oe->move(obj);

	oe->get_riddle_stat(me,oe);


	obj->trigger(oe);
	
//	me->move(obj);



	return;
}
void wake2(object me)
{
   	object obj;
   	obj = this_object();
   	
   	obj->set_temp("marks/taken", 0);
   	
   	if (!me || me->is_ghost()) {
   		return;
   	}
   		
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    me->add_temp("block_msg/all", -1);
   	me->delete_temp("is_unconcious");
	
	message_vision("һö�ɹ������Ϸ��Ҷ��£�׼׼��������$N�����ţ�����$N����������\n", me); 
   	tell_object(me, "�����ͷ���ƺ���ʲô����һ�£���������������ʹ��ͷ�������۾���\n");
   	tell_object(me, "ֻ���ü�����һ����β����������һת����ʧ�޼���\n");
   	if (me->query("kee") > 77)
		me->receive_damage("kee",77);
   	else
		me->receive_damage("kee", me->query("kee")-1);
   	me->set_temp("annie/cyan_lucky",1);
	return;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


