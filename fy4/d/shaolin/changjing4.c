#include <ansi.h>
inherit ROOM;
void create()
{
	object ob1,ob2,con;
        set("short", "�ؾ���");
        set("long", @LONG
�ؾ�¥���������ÿ����Ʒ����ϡ��֮�����������㻹ֻ���Լӻ�����������
�����ֵ��ӣ����ѽ��룬һ������Ѫ�����˵�����ʦ��ʱ��ʮ��������Ѫд�ɣ���
�м������ı�Ҷ�������Ե��̱�Ҷ���ɣ�ǧ�겻�䣬��ϧ��ʶ���ģ��ѽ����⡣
LONG
        );
        set("exits", ([ 
  		"down" : __DIR__"changjing3",
	]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",30);
	set("no_fly",1);
	set("no_lu_letter",1);
	
	set("item_desc", ([
	"����":"�ؾ���¥��һ��С����ֻҪ�������ξͿ���Ծ(jumpout)��Ծ����\n",
	"window":"�ؾ���¥��һ��С����ֻҪ�������ξͿ���Ծ(jumpout)��Ծ����\n",
	]) );
	

	setup();
	con = new(__DIR__"obj/he");
	ob1 = new(BOOKS"chant_75");
	ob2 = new(BOOKS"skill/yoga_0");
	if(con && ob1 && ob2)
	{
		ob1->move(con); 
		ob2->move(con); 
		con->move(this_object());
	}
}


void init()
{
	add_action("do_get","get");
	add_action("do_jumpout","jumpout");
	if(userp(this_player()))
		call_out("stealing",5+random(10),this_player());
}

int do_jumpout(string arg)
{
	object me;
	int i;
	object room;
   	me = this_player();
	i = me->query_skill("move",1);

	message_vision("$N����һ�㣬����һ�Ӷ����Դ��ڵ��������\n",me);
	room = find_object(__DIR__"changjing");
	if (!objectp(room)) room = load_object(__DIR__"changjing");
	if (REWARD_D->riddle_check(me,"����֮��") != 3 || REWARD_D->riddle_check(me,"�ؾ�¥") != 2)
	{
		tell_object(me,HIR"\n��ͻȻ���ִ���ʲôҲû�У�һ������ɢȥ��������ֱֱ�������׹�£���\n"NOR);
		tell_object(me,HIW"��������������������������\n"NOR);

		me->add_temp("block_msg/all",1);
		me->move(room);
		message_vision(HIY"\n����ǰһ����һ����Ӱ�Ӳؾ�¥�Ϸ�׹���£�"NOR,me);

		if (i < 50)
		{
			message_vision(HIR"ˤ�˸��Դ�������\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->set_temp("last_damage_from","�벻���Ӳؾ�������¥�Ծ��ˡ�");
			// �ţ�ͨ��һ��....
			me->die();
			return 1;
		}
		else
		{
			message_vision(HIW"ˤ�˸��߻���أ��赹������ǰ��\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->unconcious();
			return 1;
		}
	}
	if (i<80)
	{
		tell_object(me,HIR"\n�������ͻȻ��ɢ������һ�𣬲������Ϊʲô����û�кú���ϰ�Ṧ������\n��������˵ʲô���Ѿ����ˣ���������ֱֱ�������׹�£���\n"NOR);
		tell_object(me,HIW"��������������������������\n"NOR);
		i=random(i);

		me->add_temp("block_msg/all",1);
		me->move(room);
		message_vision(HIY"\n����ǰһ����һ����Ӱ�Ӳؾ�¥�Ϸ�׹���£�"NOR,me);
		if (i < 30)
		{
			message_vision(HIR"ˤ�˸��Դ�������\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->set_temp("last_damage_from","�벻���Ӳؾ�������¥�Ծ��ˡ�");
			// �ţ�ͨ��һ��....
			me->die();
			return 1;
		}
		else
		{
			message_vision(HIW"ˤ�˸��߻���أ��赹������ǰ��\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->unconcious();
			return 1;
		}
	}
	tell_object(me,HIG"\n�������������ڿ���һ�����ӵ������ɾ�����ش����˲ؾ��󶥡�\n\n"NOR);

	room = find_object(__DIR__"changjing5");
	if (!objectp(room)) room = load_object(__DIR__"changjing5");
	me->move(room);
	REWARD_D->riddle_set(me,"�ؾ�¥",3);
	return 1;
}

int do_get(string arg)
{
	string what;
	object me;
	me = this_player();
	if(!userp(me)) return 0;
	if(!arg) return 0;
	if(sscanf(arg,"%s",what) !=1) return 0;
	if(what== "all" || what  == "jingshuhe" || what == "jingshuhe 1" || what == "jingshuhe 0")
	{
		message_vision("$N���˿����������ˣ�����Ѿ��鴧�뻳�У�����һ�뵽
�ᱻ����׷ɱ���ľ���������������\n",me);
		return 1;
	}
}

int stealing(object me)
{
	object ob;
	if(environment(me) == this_object() && !present("mysterious figure",this_object()))
	{
		if (REWARD_D->riddle_check(me,"����֮��") == 3 && REWARD_D->riddle_check(me,"�ؾ�¥") == 1)
		{
			ob = new(__DIR__"npc/master_17_7");
			if (me->query("combat_exp")> ob->query("combat_exp"))
				ob->set("combat_exp", me->query("combat_exp"));
			"/feature/nada"->reset_npc(ob);
			ob->full_me();
			message_vision("һ��΢��Ӵ��ⴵ����$N���۾�����գ��һ�¡�����\n",me);
			if(ob)
				ob->move(this_object());
//			REWARD_D->riddle_set(me,"�ؾ�¥",2);
	// ��ʱ����ʧ��
		}
	}
	return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


