#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("�̱���Ԫ��",({"antibuff drug"}));
  	set("long", "һ������ɫ�ķ�ĩ����˵���ú�ɲ���������Ӱ�졣
���ֿ�stat�п���ʾ״̬��Ӱ�죩\n");
  	set("base_value",500);
  	set("desc_ext", "���ã�eat antibuff drug��");
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",500);
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
	
	if (arg != "antibuff drug")
		return 0;
		
	if (me->is_busy())
		return notify_fail("��������æ��\n");
  	message_vision(CYN"$N����һ��"+name()+"��\n"NOR,me);
	if( ANNIE_D->check_buff(me,"blocked")) 
	{
		add_amount(-1);
		return 1;
	}
	buff =
		([
			"caster":me,
			"who":me,
			"type":"blocked",
			"att":"bless",
			"name":"ҩ��̱���Ԫ��",
			"time": 10+random(10),
			"buff_msg":CYN"$N�پ��������ѣ�������ӯ��\n"NOR,
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
