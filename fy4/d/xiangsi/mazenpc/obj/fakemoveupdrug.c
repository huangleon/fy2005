#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("��Ȫ����",({"frozen elixir", "elixir"}));
  	set("long", "һ�����ɫ��֭Һ����С��ɢ���ű��˵ĺ�����\n");
  	set("base_value",5000);
  	set("unit","Щ");
  	set("base_unit","��");
  	set("base_weight",50);
  	set("desc_ext","���ã�drink frozen elixir��");
  	set("volumn",1);
	set("lore",1);
  	set_amount(1);
}


void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({ "drink" }));
}

int do_cure(string arg)
{
	object me;
	mapping buff;
	me = this_player();
	
	if (arg != "frozen elixir")
		return 0;
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
  	
  	message_vision(CYN"$N����һ��"+name()+"��\n"NOR,me);
	if( ANNIE_D->check_buff(me,"freeze")) 
	{
		add_amount(-1);
		return 1;
	}
		buff =
		([
			"caster":me,
			"who":me,
			"type":"freeze",
			"att":"curse",
			"name":"ҩ���Ȫ����",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <������>"NOR,
			"time":20+random(20),
			"buff_msg":HIW"$N����һ���������ʱ�������ã�\n"NOR,
			"disa_msg":HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
  	add_amount(-1);
  	return 1;
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
