#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("��Ȫ����",({"drug"}));
  	set("long", "һ�����ɫ��֭Һ��\n");
  	set("base_value",5000);
  	set("unit","Щ");
  	set("base_unit","��");
  	set("base_weight",50);
  	set("volumn",1);
	set("lore",1);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({ "use","eat" }));
}

int do_cure()
{
	object me;
	mapping buff;
	me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ��\n");
  	message_vision(CYN"$N����һ��"+name()+"��\n"NOR,me);
	if( ANNIE_D->check_buff(me,"moveup")) 
	{
		add_amount(-1);
		return 1;
	}

	buff =
	([
		"caster":me,
		"who":me,
		"type":"moveup",
		"att":"bless",
		"name":"ҩ���Ȫ����",
		"buff1":"apply/agility",
		"buff1_c":3,
		"time":600,
		"buff_msg":CYN"$N�����ĵ���һ˿ů����������\n"NOR,
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
