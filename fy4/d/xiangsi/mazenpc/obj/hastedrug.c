#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("����˳��ɢ",({"haste drug"}));
  	set("long", "һ������ɫ�ķ�ĩ����˵���ú���Խ�����ɣ��������ࡣ\n");
  	set("base_value",1000);
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",500);
  	set("desc_ext","���ã�eat haste drug��");
  	set("volumn",1);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({"eat" }));
}

int do_cure(string arg)
{
	object me;
	mapping buff;
	me = this_player();
	
	if (arg != "haste drug")
		return 0;
		
	if (me->is_busy())
		return notify_fail("��������æ��\n");
  	
  	message_vision(CYN"$N����һ��"+name()+"��\n"NOR,me);
	if( ANNIE_D->check_buff(me,"haste")) 
	{
		add_amount(-1);
		return 1;
	}

	buff =
	([
		"caster":me,
		"who":me,
		"type":"haste",
		"att":"bless",
		"name":"ҩ�����˳��ɢ",
		"buff1":"apply/haste",
		"buff1_c":15,
		"time":30+random(90),
		"buff_msg":CYN"$N��ɫ������ף������ٶȶ����ӿ졣\n"NOR,
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
