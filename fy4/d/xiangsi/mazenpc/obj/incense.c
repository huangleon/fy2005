#include <ansi.h>
inherit ITEM;
string description();

void create()
{
        set_name("������", ({ "incense" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50000);
                set("material", "herb");
				set("no_drop",1);
				set("no_clean_up",1);

        }
}

int do_sleep(object me)
{
	int gin,kee,sen;
	mapping buff;
      	message_vision(CYN"\n$Nȼ�������㣬ɢ�������ĵ�������Ѭ�������һ����Ƿ,", me);
      	tell_object(me, "�ܿ���;���˯�����ʡ�\n\n");
      	message("vision", me->name()+"�ڵ��Ϻ���һ�ɣ��ܿ�ͽ��������硣\n\n", environment(me), me);
		  gin = me->query("max_gin");
		  me->set("eff_gin", gin);
		  me->set("gin", gin);
		  kee = me->query("max_kee");
		  me->set("eff_kee", kee);
		  me->set("kee", kee);
		  sen = me->query("max_sen");
		  me->set("eff_sen", sen);
		  me->set("sen", sen);
			me->status_msg("all");
	  		buff =
			([
				"caster":me,
				"who":me,
				"type":"freeze",
				"att":"curse",
				"name":"����칬��������",
				"buff1":"disable_inputs",
				"buff1_c":1,
				"buff2":"is_unconcious",
				"buff2_c":1,
				"buff3":"block_msg/all",
				"buff3_c":1,
				"disable_type":HIG " <˯����>"NOR,
				"time":20+random(20),
				"buff_msg":"\n$N�ڵ��Ϻ���һ�ɣ��ܿ�ͽ��������硣\n\n"NOR,
				"disa_msg":CYN"\n\n$N�������۾���һ�������ͦ����������\n"NOR,
				"disa_type":1,
			]);
			ANNIE_D->buffup(buff);
      	move(load_object("/obj/void"));
		destruct(this_object());
      	return 1;
}


void init()
{
	object me;
	me = this_player();
	if (me && userp(me))
	{
		me->start_busy(1);
		call_out("do_sleep",1,me);		
	}
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
