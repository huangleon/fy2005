#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("ʯ��",({"drug"}));
  	set("long", "һ�鿴�����ʵصĻ�ɫ��Ʒ��\n");
  	set("base_value",3000);
  	set("unit","Щ");
  	set("base_unit","��");
  	set("base_weight",50);
  	set("volumn",1);
  	set_amount(8);
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
  	message_vision(CYN"$N��һ��"+name()+"�������\n"NOR,me);
	if(!ANNIE_D->check_buff(me,"lockup")) 
	{
		add_amount(-1);
		return 1;
	}
	ANNIE_D->debuff(me,"lockup");
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
