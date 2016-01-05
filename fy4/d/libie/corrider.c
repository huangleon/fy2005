// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
����������һ�����ȡ���������������С���ϣ���ջҲûʲôǮ��������
����ҡҡ�λΣ���֨��֨�����ľͷ���ȣ�����Ϊ��Ϯһ�Ⱥ������ĵ�����һ��
��ʡ�Լ��õ��ϰ�ݺ���Ӳ�Ǽ������������еļҵ��������������˺��̺������
����Ҳ�߸߹����˴�������
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"down":__DIR__"yuelai",
	"enter":__DIR__"qilin",
	]) );
	//}}


	set("objects", ([
        __DIR__"npc/xiaoyezi": 1,
        ]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
		setup();	
}

int valid_leave(object me,string dir)
{
	object xiaoyezi;
	object room,cloth;
	
	room=this_object();
	if(dir!="enter") return 1;
	if(me->query_temp("libie/���_׼����������")) {
		return 1;
	}
	if(!objectp(xiaoyezi=present("xiao yezi",room))) return 1;
 	if(!living(xiaoyezi)) return 1;
 	if(me->query_temp("libie/���_����ֿ�ʼ")){
 		message_vision(HIR"СҶ��΢Ц�Ķ�$N˵��������λ"+RANK_D->query_respect(me)+"һ������"+me->query("name")+"�����ɣ������Ѿ��Ⱥ���¶�ʱ�ˡ���\n"NOR,me);
 		me->delete_temp("libie/���_��ֹ���������");
 		me->set_temp("libie/���_׼����������",1);
 		return notify_fail("");
 	}
 	if(me->query_temp("libie/���_��ֹ���������"))
 		return notify_fail(HIR"СҶ������һ������������ǰ��\n"NOR);
 	
 	cloth=present("waiter cloth",me);
   	if(objectp(cloth))
   	if(cloth->query("equipped")){
   		message_vision(HIY"СҶ�ӵ�ס��$N��ȥ·������û������ˣ���ȥæ��ɡ���\n"NOR,me);	
   		return notify_fail("");
   	}
   	add_action("do_answer","answer");
   	message_vision(HIY"СҶ����$N�ʵ�����������λ"+RANK_D->query_respect(me)+"�ǲ���Ҫ�ҵ�С��ү����\n"NOR,me);
   	return notify_fail(HIY"answer(yes/no)\n"NOR);
}

int do_answer(string arg)
{
	object ob, me;
	object room;
	
	room=this_object();
	ob=present("xiao yezi",room);
	me=this_player();
	if(!objectp(ob)) return 0;
	if(!living(ob)) return 0;
	if (arg=="no")
	{
		message_vision(HIW"СҶ��΢Ц�Ķ�$N˵��������Ȼ�������ҵ�С��ү�ģ����벻Ҫ��������ŵ�С��ү����Ϣ�ˡ���\n"NOR,me);
		remove_action("do_answer","answer");
		return 1;
	}
	if (arg=="yes")
	{
		message_vision(HIY"СҶ��΢Ц�Ķ�$N˵������ԭ���������������������\n"NOR,me);
		if(me->query_temp("libie/СҶ��ɱ"))
		{
			call_out("killing",1,ob,me);
			me->set_temp("libie/���_��ֹ���������",1);
			return 1;
		}
		message_vision(HIY"СҶ����$Nʾ����Խ��������\n"NOR,me);
		me->set_temp("libie/���_׼����������",1);
		remove_action("do_answer","answer");
		return 1;
	}
	return 0;
}


/*
һ���Ŀ���ߣ���ϥ����һ�������ϣ�ϥͷ�Ϻ�ڸ���
���ȣ��·�����ɮ�붨��������������һ�����ŵ����ߣ�ǹһ��վ��
���������ˡ�
*/

void killing(object ob, object me)
{
	message_vision(HIR"СҶ�Ӻ�Ȼ��$N��Ц������ȥ���ɡ�������\n",me);
	ob->ccommand("wield dagger");
	ob->kill_ob(me);
	ob->ccommand("perform sharenruma");
}
